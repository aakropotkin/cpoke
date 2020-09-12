/* -*- mode: c; -*- */

/* ========================================================================= */

#include "parse_gm.h"
#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include "util/bits.h"
#include "util/json_util.h"
#include "util/jsmn_iterator_stack.h"
#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>
#include "ext/uthash.h"


/* ------------------------------------------------------------------------- */

  int
gm_regexes_init( gm_regexes_t * grs )
{
  assert( grs != NULL );
  int rsl = regcomp( &grs->tmpl_mon, tmpl_mon_pat, REG_NOSUB );
  if ( rsl != 0 ) return rsl;
  rsl = regcomp( &grs->tmpl_pvp_move, tmpl_pvp_move_pat, REG_NOSUB );
  if ( rsl != 0 ) return rsl;
  rsl = regcomp( &grs->tmpl_pvp_fast, tmpl_pvp_fast_pat, REG_NOSUB );
  return rsl;
}

  void
gm_regexes_free( gm_regexes_t * grs )
{
  assert( grs != NULL );
  regfree( &grs->tmpl_mon );
  regfree( &grs->tmpl_pvp_move );
  regfree( &grs->tmpl_pvp_fast );
}


/* ------------------------------------------------------------------------- */

  void
gm_parser_free( gm_parser_t * gm_parser )
{
  jsmn_file_parser_free( gm_parser->fparser );
  free( gm_parser->fparser ); /* The file parser itself was malloced */
  gm_regexes_free( &gm_parser->regs );
  jsmnis_free( &gm_parser->iter_stack );
  gm_parser->buffer     = NULL;
  gm_parser->buffer_len = 0;
  gm_parser->tokens     = NULL; /* Tokens were already freed by fparser */
  gm_parser->tokens_cnt = 0;
  gm_parser->fparser    = NULL;
  /* Free the moves table */
  store_move_t * curr_move = NULL;
  store_move_t * tmp_move  = NULL;
  HASH_ITER( hh_name, gm_parser->moves_by_name, curr_move, tmp_move )
    {
      HASH_DELETE( hh_name, gm_parser->moves_by_name, curr_move );
      HASH_DELETE( hh_move_id, gm_parser->moves_by_id, curr_move );
      free( curr_move->name );
      free( curr_move );
    }
  /* Free Pokedex */
  pdex_mon_t * curr_mon = NULL;
  pdex_mon_t * tmp_mon  = NULL;
  HASH_ITER( hh_name, gm_parser->mons_by_name, curr_mon, tmp_mon )
    {
      HASH_DELETE( hh_name, gm_parser->mons_by_name, curr_mon );
      HASH_DELETE( hh_dex_num, gm_parser->mons_by_dex, curr_mon );
      pdex_mon_free( curr_mon );
    }
}

  size_t
gm_parser_init( gm_parser_t * gm_parser, const char * gm_fpath )
{
  assert( gm_fpath != NULL );
  assert( gm_parser != NULL );

  size_t read_chars  = 0;
  long   read_tokens = 0;
  int    jsmn_rsl    = 0;

  gm_parser->fparser =
    (jsmn_file_parser_t *) malloc( sizeof( jsmn_file_parser_t ) );
  if ( gm_parser->fparser == NULL ) return 0;

  read_chars = jsmn_file_parser_init( gm_parser->fparser, gm_fpath );

  if ( read_chars == 0 )
    {
      jsmn_file_parser_free( gm_parser->fparser );
      free( gm_parser->fparser );
      return 0;
    }

  /* `jsmn_parse_realloc' handles allocation. */
  read_tokens = jsmn_parse_realloc( &( gm_parser->fparser->jparser ),
                                    gm_parser->fparser->buffer,
                                    gm_parser->fparser->buffer_len,
                                    &( gm_parser->fparser->tokens ),
                                    &( gm_parser->fparser->tokens_cnt )
                                  );
  if ( read_tokens == JSMN_ERROR_NOMEM )
    {
      fprintf( stderr,
              "%s: JSMN failed to allocate space for tokens for file '%s'.\n",
              __func__,
              gm_fpath
            );
      gm_parser_free( gm_parser );
      return 0;
    }

  /* Initialize tables */
  gm_parser->moves_by_name = NULL;
  gm_parser->moves_by_id   = NULL;
  gm_parser->mons_by_name  = NULL;
  gm_parser->mons_by_dex   = NULL;

  gm_parser->buffer     = gm_parser->fparser->buffer;
  gm_parser->buffer_len = read_chars;
  gm_parser->tokens     = gm_parser->fparser->tokens;
  gm_parser->tokens_cnt = read_tokens;
  jsmn_rsl = jsmnis_init( &( gm_parser->iter_stack ),
                          gm_parser->tokens,
                          read_tokens,
                          8
                        );
  assert( jsmn_rsl == 0 );

  /* Open the top level object */
  jsmn_rsl = jsmnis_push( &( gm_parser->iter_stack ), 0 );
  assert( jsmn_rsl == 0 );

  /* Open the item template list */
  jsmn_rsl = jsmnis_open_key_seq( gm_parser->buffer,
                                  &( gm_parser->iter_stack ),
                                  "itemTemplate",
                                  0
                                );
  assert( jsmn_rsl == 0 );

  return read_tokens;
}


/* ------------------------------------------------------------------------- */

  ptype_t
parse_gm_type( const char * json, jsmntok_t * token )
{
  if ( ( json == NULL ) || ( token == NULL ) ) return PT_NONE;
  if ( toklen( token ) < 16 ) return PT_NONE; /* Ice is shortest at 16 */
  if ( strncmp( json + token->start, "POKEMON_TYPE_", 13 ) != 0 )
    {
      return PT_NONE;
    }

  for ( int i = 1; i < NUM_PTYPES; i++ )
    {
      if ( strncasecmp( json + token->start  + 13,
                        ptype_names[i],
                        toklen( token ) - 13
                      ) == 0
         ) return (ptype_t) i;
    }

  return PT_NONE;
}


/* ------------------------------------------------------------------------- */

  bool
stris_pvp_charged_move( const char * str, gm_regexes_t * regs )
{
  assert( regs != NULL );
  if ( str == NULL ) return false;
  return ( ! regexec( &( regs->tmpl_pvp_move ), str, 0, NULL, 0 ) ) &&
         ( !! regexec( &( regs->tmpl_pvp_fast ), str, 0, NULL, 0 ) );
}


/* ------------------------------------------------------------------------- */

  uint16_t
parse_gm_dex_num( const char * json, jsmntok_t * token )
{
  if ( ( json == NULL ) || ( token == NULL ) ) return 0;
  if ( json[token->start] != 'V' ) return 0;
  return atouin( json + token->start + 1, 4 );
}


/* ------------------------------------------------------------------------- */

  stats_t
parse_gm_stats( const char * json, jsmnis_t * iter_stack )
{
  stats_t     stats     = { 0, 0, 0 };
  jsmntok_t * key       = NULL;
  jsmntok_t * val       = NULL;
  jsmnis_while( iter_stack, &key, &val )
    {
      if ( jsoneq_str( json, key, "baseStamina" ) )
        {
          stats.stamina = atouin( json + val->start, 4 );
        }
      else if ( jsoneq_str( json, key, "baseAttack" ) )
        {
          stats.attack = atouin( json + val->start, 4 );
        }
      else if ( jsoneq_str( json, key, "baseDefense" ) )
        {
          stats.defense = atouin( json + val->start, 4 );
        }
    }
  return stats;
}


/* ------------------------------------------------------------------------- */

  buff_t
parse_gm_buff( const char * json, jsmni_t * iter )
{
  buff_t      buff      = NO_BUFF;
  jsmntok_t * key       = NULL;
  jsmntok_t * val       = NULL;
  char        amount    = 0;
  jsmni_while( iter, &key, &val, 0 )
    {
      if ( jsoneq_str( json, key, "targetAttackStatStageChange" ) )
        {
          amount = atocn( json + val->start, toklen( val ) );
          buff.atk_buff.target  = 1;
          buff.atk_buff.amount  = ( 0 < amount ) ? amount : ( - amount );
          buff.atk_buff.debuffp = !!( amount < 0 );
        }
      else if ( jsoneq_str( json, key, "targetDefenseStatStageChange" ) )
        {
          amount = atocn( json + val->start, toklen( val ) );
          buff.def_buff.target  = 1;
          buff.def_buff.amount  = ( 0 < amount ) ? amount : ( - amount );
          buff.def_buff.debuffp = !!( amount < 0 );
        }
      else if ( jsoneq_str( json, key, "attackerAttackStatStageChange" ) )
        {
          amount = atocn( json + val->start, toklen( val ) );
          buff.atk_buff.target  = 0;
          buff.atk_buff.amount  = ( 0 < amount ) ? amount : ( - amount );
          buff.atk_buff.debuffp = !!( amount < 0 );
        }
      else if ( jsoneq_str( json, key, "attackerDefenseStatStageChange" ) )
        {
          amount = atocn( json + val->start, toklen( val ) );
          buff.def_buff.target  = 0;
          buff.def_buff.amount  = ( 0 < amount ) ? amount : ( - amount );
          buff.def_buff.debuffp = !!( amount < 0 );
        }
      else if ( jsoneq_str( json, key, "buffActivationChance" ) )
        {
          if      ( jsoneq( json, val, "1.0" ) )   buff.chance = bc_1000;
          else if ( jsoneq( json, val, "0.5" ) )   buff.chance = bc_0500;
          else if ( jsoneq( json, val, "0.3" ) )   buff.chance = bc_0300;
          else if ( jsoneq( json, val, "0.125" ) ) buff.chance = bc_0125;
          else if ( jsoneq( json, val, "0.1" ) )   buff.chance = bc_0100;
          else                                     buff.chance = bc_0000;
        }
    }

  return buff;
}


/* ------------------------------------------------------------------------- */

  uint16_t
parse_pdex_mon( const char   * json,
                jsmnis_t     * iter_stack,
                store_move_t * moves_by_name,
                pdex_mon_t   * mons_by_name,
                pdex_mon_t   * mon
              )
{
  assert( json != NULL );
  assert( iter_stack != NULL );
  assert( mon != NULL );

  const unsigned short stack_idx = iter_stack->stack_index;
  jsmntok_t *          key       = NULL;
  jsmntok_t *          val       = NULL;
  int                  idx       = jsmnis_pos( iter_stack );
  int                  rsl       = 0;

  /* `templateId' value should already be targeted by `iter_stack' */
  assert( 0 < idx );
  /* Clear struct */
  memset( mon, 0, sizeof( pdex_mon_t ) );
  mon->next_form = NULL;

  /* Parse Dex # from `templateId' value */
  mon->dex_number = parse_gm_dex_num( json, iter_stack->tokens + idx );
  assert( mon->dex_number != 0 );

  /* Create iterator on `pokemon' value */
  rsl = jsmnis_open_key_seq( json, iter_stack, "pokemon", 0 );
  assert( 0 == rsl );

  jsmnis_while( iter_stack, &key, &val )
    {
      if ( jsoneq_str( json, key, "uniqueId" ) )
        {
          mon->name = strndup( json + val->start, toklen( val ) );
          assert( mon->name != NULL );
        }
      else if ( jsoneq_str( json, key, "type1" ) ||
                jsoneq_str( json, key, "type2" )
              )
        {
          mon->types |= get_ptype_mask( parse_gm_type( json, val ) );
        }
      else if ( jsoneq_str( json, key, "stats" ) )
        {
          jsmnis_push_curr( iter_stack );
          mon->base_stats = parse_gm_stats( json, iter_stack );
          jsmnis_pop( iter_stack );
        }
      else if ( jsoneq_str( json, key, "quickMoves" ) )
        {
          mon->fast_move_ids  = malloc( sizeof( uint16_t ) * key->size );
          mon->fast_moves_cnt = key->size;
          assert( mon->fast_move_ids != NULL );
          jsmnis_push_curr( iter_stack );
          idx = 0;
          jsmnis_while( iter_stack, &key, &val )
            {
              mon->fast_move_ids[idx++] = lookup_move_idn( moves_by_name,
                                                           json + val->start,
                                                           toklen( val )
                                                         );
              assert( 0 < mon->fast_move_ids[idx - 1] );
            }
          jsmnis_pop( iter_stack );
          assert( idx == mon->fast_moves_cnt );
        }
      else if ( jsoneq_str( json, key, "cinematicMoves" ) )
        {
          mon->charged_move_ids  = malloc( sizeof( uint16_t ) * key->size );
          mon->charged_moves_cnt = key->size;
          assert( mon->charged_move_ids != NULL );
          jsmnis_push_curr( iter_stack );
          idx = 0;
          jsmnis_while( iter_stack, &key, &val )
            {
              mon->charged_move_ids[idx++] = lookup_move_idn( moves_by_name,
                                                              json + val->start,
                                                              toklen( val )
                                                            );
              assert( 0 < mon->charged_move_ids[idx - 1] );
            }
          jsmnis_pop( iter_stack );
          assert( idx == mon->charged_moves_cnt );
        }
      else if ( jsoneq_str( json, key, "form" ) )
        {
          mon->form_name = strndup( json + val->start, toklen( val ) );
          assert( mon->form_name != NULL );
        }
      else if ( jsoneq_str( json, key, "familyId" ) )
        {
          mon->family = lookup_dexn( mons_by_name,
                                     json + val->start + 7,
                                     toklen( val ) - 7
                                   );
        }
    }
  jsmnis_pop( iter_stack );

  mon->hkey = pdex_mon_hkey( mon );

  assert( mon->name != NULL );
  assert( iter_stack->stack_index == stack_idx );
  assert( mon->types != PT_NONE_M );
  assert( mon->base_stats.stamina != 0 );
  assert( mon->base_stats.attack != 0 );
  assert( mon->base_stats.defense != 0 );
  assert( mon->form_name != NULL );

  return mon->dex_number;
}


/* ------------------------------------------------------------------------- */

/**
 * Pokedex data is stored as a hash table indexed by Dex Numbers/Names,
 * holding a linked list of "forms".
 * <p>
 * Unlike the data store, the parser's simpler table cannot directly jump to a
 * specific form. This is fine, because the GM Parser is not meant to be used
 * to store data; it is a temporary construct to extract data for later
 * organization and reduction. Still we try to save space where we can by
 * using move ids and dex numbers for families when we can. For this reason
 * moves must be parsed before pokemon, and in a handful of cases families
 * will need to be filled in after the fact ( baby forms ).
 * <p>
 * A lot of these forms are completely redundant. For example, shadow/purified
 * are always identical to their normal forms, with the exception of the
 * extra charged moves "FRUSTRATION", and "RETURN"; these skipped by the parser.
 * Similarly Unown and Spinda have a ton of identical forms that are skipped.
 * Other pokemon likely have redundant forms, but for the sake of simplicity we
 * parse them anyways, and "merge" them later when building the data store.
 */
  bool
add_mon_data( gm_parser_t * gm_parser, pdex_mon_t * mon )
{
  assert( gm_parser != NULL );
  assert( mon != NULL );

  pdex_mon_t * stored = NULL;
  HASH_FIND( hh_dex_num,
             gm_parser->mons_by_dex,
             & mon->dex_number,
             sizeof( uint16_t ),
             stored
           );

  /* Add new pdex_mon_t if none exists yet */
  if ( stored == NULL )
    {
      mon->form_idx = 0;
      HASH_ADD( hh_name,
                gm_parser->mons_by_name,
                name,
                strlen( mon->name ),
                mon
              );
      HASH_ADD( hh_dex_num,
                gm_parser->mons_by_dex,
                dex_number,
                sizeof( uint16_t ),
                mon
              );
    }
  else
    {
      /* Check if this form already exists.
       * If it does, update the family name, but leave everything else alone. */
      if ( strcmp( stored->form_name, mon->form_name ) == 0 )
        {
          stored->family = mon->family;
          pdex_mon_free( mon );
          return true;
        }

      while ( stored->next_form != NULL )
        {
          stored = stored->next_form;
          /* Check for same form */
          if ( strcmp( stored->form_name, mon->form_name ) == 0 )
            {
              stored->family = mon->family;
              pdex_mon_free( mon );
              return true;
            }
        }
      stored->next_form = mon;
      mon->form_idx = stored->form_idx + 1;
    }

  return ( 0 < mon->family );
}


/* ------------------------------------------------------------------------- */

  uint16_t
parse_pvp_charged_move( const char         *  json,
                        jsmnis_t           *  iter_stack,
                        char               ** name,
                        pvp_charged_move_t *  move
                      )
{
  assert( json != NULL );
  assert( iter_stack != NULL );
  assert( name != NULL );
  assert( move != NULL );

  const unsigned short stack_idx = iter_stack->stack_index;
  jsmntok_t *          key       = NULL;
  jsmntok_t *          val       = NULL;
  int                  idx       = jsmnis_pos( iter_stack );
  int                  rsl       = 0;

  /* `templateId' value should already be targeted by `iter_stack' */

  /* Clear struct */
  memset( move, 0, sizeof( pvp_charged_move_t ) );

  move->is_fast = false;

  /* Parse Move ID */
  move->move_id = atouin( json + iter_stack->tokens[idx].start + 8, 4 );

  rsl = jsmnis_open_key_seq( json, iter_stack, "combatMove", 0 );
  jsmnis_while( iter_stack, &key, &val )
    {
      if ( jsoneq_str( json, key, "uniqueId" ) )
        {
          *name = strndup( json + val->start, toklen( val ) );
        }
      else if ( jsoneq_str( json, key, "type" ) )
        {
          move->type = parse_gm_type( json, val );
        }
      else if ( jsoneq_str( json, key, "power" ) )
        {
          move->power = atoi( json + val->start );
        }
      else if ( jsoneq_str( json, key, "energyDelta" ) )
        {
          rsl = atoi( json + val->start );
          move->energy = ( 0 < rsl ) ? rsl : -rsl;
        }
      else if ( jsoneq_str( json, key, "buffs" ) )
        {
          jsmnis_push_curr( iter_stack );
          move->buff = parse_gm_buff( json, current_iterator( iter_stack ) );
          jsmnis_pop( iter_stack );
        }
    }
  jsmnis_pop( iter_stack );

  assert( iter_stack->stack_index == stack_idx );
  assert( *name != NULL );
  assert( move->is_fast == false );
  assert( move->move_id != 0 );
  assert( move->type != PT_NONE );
  assert( 0 < move->power );
  assert( 0 < move->energy );

  return move->move_id;
}


/* ------------------------------------------------------------------------- */

  uint16_t
parse_pvp_fast_move( const char      *  json,
                     jsmnis_t        *  iter_stack,
                     char            ** name,
                     pvp_fast_move_t *  move
                   )
{
  assert( json != NULL );
  assert( iter_stack != NULL );
  assert( name != NULL );
  assert( move != NULL );

  const unsigned short stack_idx = iter_stack->stack_index;
  jsmntok_t *          key       = NULL;
  jsmntok_t *          val       = NULL;
  int                  idx       = jsmnis_pos( iter_stack );
  int                  rsl       = 0;

  /* `templateId' value should already be targeted by `iter_stack' */
  assert( 0 < idx );
  /* Clear struct */
  memset( move, 0, sizeof( pvp_fast_move_t ) );

  move->is_fast = true;

  /* Parse Move ID */
  move->move_id = atouin( json + iter_stack->tokens[idx].start + 8, 4 );

  rsl = jsmnis_open_key_seq( json, iter_stack, "combatMove", 0 );
  jsmnis_while( iter_stack, &key, &val )
    {
      if ( jsoneq_str( json, key, "uniqueId" ) )
        {
          *name = strndup( json + val->start, toklen( val ) - 5 );
        }
      else if ( jsoneq_str( json, key, "type" ) )
        {
          move->type = parse_gm_type( json, val );
        }
      else if ( jsoneq_str( json, key, "power" ) )
        {
          move->power = atoi( json + val->start );
        }
      else if ( jsoneq_str( json, key, "energyDelta" ) )
        {
          rsl = atoi( json + val->start );
          move->energy = ( 0 < rsl ) ? rsl : -rsl;
        }
      else if ( jsoneq_str( json, key, "durationTurns" ) )
        {
          move->turns = atoi( json + val->start );
        }
    }
  jsmnis_pop( iter_stack );

  assert( iter_stack->stack_index == stack_idx );
  assert( *name != NULL );
  assert( move->is_fast == true );
  assert( move->move_id != 0 );
  assert( move->type != PT_NONE );
  assert( 0 < move->power );
  assert( 0 < move->energy );
  assert( 0 < move->turns );

  return move->move_id;
}


/* ------------------------------------------------------------------------- */

  void
add_pvp_charged_move_data( gm_parser_t        *  gm_parser,
                           char               *  move_name,
                           pvp_charged_move_t *  move
                         )
{
  assert( gm_parser != NULL );
  assert( move != NULL );
  assert( move_name != NULL );

  store_move_t * stored = NULL;
  HASH_FIND( hh_move_id,
             gm_parser->moves_by_id,
             & move->move_id,
             sizeof( uint16_t ),
             stored
           );

  /* Add new store_move if none exists yet */
  if ( stored == NULL )
    {
      stored = (store_move_t *) malloc( sizeof( store_move_t ) );
      memset( stored, 0, sizeof( store_move_t ) );
      assert( stored != NULL );

      stored->name    = move_name;
      stored->move_id = move->move_id;
      stored->type    = move->type;
      stored->is_fast = false;

      HASH_ADD( hh_name,
                gm_parser->moves_by_name,
                name,
                strlen( move_name ),
                stored
              );
      HASH_ADD( hh_move_id,
                gm_parser->moves_by_id,
                move_id,
                sizeof( uint16_t ),
                stored
              );
    }

  stored->pvp_power  = move->power;
  stored->pvp_energy = move->energy;
  stored->buff       = move->buff;
}


/* ------------------------------------------------------------------------- */

  void
add_pvp_fast_move_data( gm_parser_t     *  gm_parser,
                        char            *  move_name,
                        pvp_fast_move_t *  move
                      )
{
  assert( gm_parser != NULL );
  assert( move != NULL );
  assert( move_name != NULL );

  store_move_t * stored = NULL;
  HASH_FIND( hh_move_id,
             gm_parser->moves_by_id,
             & move->move_id,
             sizeof( uint16_t ),
             stored
           );

  /* Add new store_move if none exists yet */
  if ( stored == NULL )
    {
      stored = (store_move_t *) malloc( sizeof( store_move_t ) );
      memset( stored, 0, sizeof( store_move_t ) );
      assert( stored != NULL );

      stored->name = move_name;
      stored->move_id = move->move_id;
      stored->type    = move->type;
      stored->is_fast = true;

      HASH_ADD( hh_name,
                gm_parser->moves_by_name,
                name,
                strlen( move_name ),
                stored
              );
      HASH_ADD( hh_move_id,
                gm_parser->moves_by_id,
                move_id,
                sizeof( uint16_t ),
                stored
              );
    }

  stored->pvp_power  = move->power;
  stored->pvp_energy = move->energy;
  stored->cooldown   = move->turns;
  stored->buff       = NO_BUFF;
}


/* ------------------------------------------------------------------------- */

  uint16_t
lookup_move_id( store_move_t * moves, const char * name )
{
  assert( moves != NULL );
  assert( name != NULL );
  store_move_t * move = NULL;
  HASH_FIND( hh_name, moves, name, strlen( name ), move );
  return ( move == NULL ) ? 0 : move->move_id;
}

  uint16_t
lookup_move_idn( store_move_t * moves, const char * name, size_t n )
{
  assert( moves != NULL );
  assert( name != NULL );
  assert( 0 < n );
  store_move_t * move = NULL;
  HASH_FIND( hh_name, moves, name, n, move );
  return ( move == NULL ) ? 0 : move->move_id;
}


/* ------------------------------------------------------------------------- */

  uint16_t
lookup_dex( pdex_mon_t * mons, const char * name )
{
  assert( mons != NULL );
  assert( name != NULL );
  pdex_mon_t * mon = NULL;
  HASH_FIND( hh_name, mons, name, strlen( name ), mon );
  return ( mon == NULL ) ? 0 : mon->dex_number;
}

  uint16_t
lookup_dexn( pdex_mon_t * mons, const char * name, size_t n )
{
  assert( mons != NULL );
  assert( name != NULL );
  assert( 0 < n );
  pdex_mon_t * mon = NULL;
  HASH_FIND( hh_name, mons, name, n, mon );
  return ( mon == NULL ) ? 0 : mon->dex_number;
}


/* ------------------------------------------------------------------------- */

#ifdef MK_PARSE_GM_BINARY
/* THIS IS CURRENTLY BROKEN.
 * This code should be moved to a gm_parser function */
  int
main( int argc, char * argv[], char ** envp )
{

  /* Parse file */
  gm_parser_t gparser;
  size_t rsl = gm_parser_init( "./data/GAME_MASTER.json", &gparser );
  assert( rsl != 0 );

  /* Iterate over items */
  jsmntok_t * key  = NULL;
  jsmntok_t * val  = NULL;
  int         idx  = 0;
  jsmntok_t * item = NULL;

  jsmnis_a_while( &iter_stack, &item )
    {
      /* Open the current item */
      jsmnis_push_curr( &iter_stack );

      /* See if this item's templateId matches that of a Pokemon */
      key = NULL;
      val = NULL;
      idx = jsmni_find_next( gparser.buffer,
                            jsmnis_curr( &iter_stack ),
                            &key,
                            jsoneq_str_p,
                            (void *) "templateId",
                            &val,
                             //jsonmatch_str_p,
                             //(void *) &gmparser.regs.tmpl_mon,
                            jsoneq_str_p,
                            (void *) "FORMS_V0002_POKEMON_IVYSAUR",
                            0
                          );
      if ( idx <= 0 )
        {
          jsmnis_pop( &iter_stack ); /* Close the item */
          continue;
        }

      /* Find number of forms for Ivysaur */
      jsmni_next( jsmnis_curr( &iter_stack ), &key, &val, 0 );
      jsmnis_push_curr( &iter_stack );
      jsmni_next( jsmnis_curr( &iter_stack ), &key, &val, 0 );
      jsmni_next( jsmnis_curr( &iter_stack ), &key, &val, 0 );
      printf( "SIZE: %d\n", val->size );
      return 0;

      /* You have to pop/close before parsing because `iter_stack' is currently
      * pointed inside the item template, not pointing at it's root. */
      pdex_mon_t mon;
      parse_pdex_mon( gparser.buffer,
                      &iter_stack,
                      gparser.moves_by_name,
                      gparser.mons_by_name,
                      &mon
                    );
      print_pdex_mon( &mon );

      jsmnis_pop( &iter_stack );
    }


  /* Cleanup */
  jsmnis_free( &iter_stack );
  gm_parser_free( &gparser );

  return EXIT_SUCCESS;
}
#endif /* MK_PARSE_GM_BINARY */


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
