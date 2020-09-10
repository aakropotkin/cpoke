/* -*- mode: c; -*- */

/* ========================================================================= */

#include "parse_gm.h"
#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include "util/json_util.h"
#include "util/jsmn_iterator_stack.h"
#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>


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
  gm_parser->tokens     = NULL;
  gm_parser->tokens_cnt = 0;
  gm_parser->fparser    = NULL;
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
  char buffer[4] = { '\0', '\0', '\0', '\0' };
  strncpy( buffer, json + token->start + 1, 4 );
  return atoi( buffer );
}


/* ------------------------------------------------------------------------- */

  stats_t
parse_gm_stats( const char * json, jsmnis_t * iter_stack )
{
  stats_t     stats     = { 0, 0, 0 };
  char        buffer[5] = { '\0', '\0', '\0', '\0', '\0' };
  jsmntok_t * key       = NULL;
  jsmntok_t * val       = NULL;
  jsmnis_while( iter_stack, &key, &val )
    {
      memset( buffer, '\0', 5 );
      strncpy( buffer, json + val->start, toklen( val ) );
      if ( jsoneq_str( json, key, "baseStamina" ) )
        {
          stats.stamina = atoi( buffer );
        }
      else if ( jsoneq_str( json, key, "baseAttack" ) )
        {
          stats.attack = atoi( buffer );
        }
      else if ( jsoneq_str( json, key, "baseDefense" ) )
        {
          stats.defense = atoi( buffer );
        }
    }
  return stats;
}


/* ------------------------------------------------------------------------- */

  uint16_t
parse_pdex_mon( const char * json, jsmnis_t * iter_stack, pdex_mon_t * mon )
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

  /* Ininitialize `pdex_mon_t' struct */
  /* FIXME */
  mon->types = PT_NONE_M;

  /* Parse Dex # from `templateId' value */
  mon->dex_number = parse_gm_dex_num( json, iter_stack->tokens + idx );
  assert( mon->dex_number != 0 );

  /* Create iterator on `pokemon' value */
  rsl = jsmnis_open_key_seq( json, iter_stack, "pokemon", 0 );
  assert( 0 == rsl );

  jsmnis_while( iter_stack, &key, &val ) {
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
        /* FIXME */
      }
    else if ( jsoneq_str( json, key, "cinematicMoves" ) )
      {
        /* FIXME */
      }
    else if ( jsoneq_str( json, key, "form" ) )
      {
        /* FIXME */
      }
    else if ( jsoneq_str( json, key, "familyId" ) )
      {
        /* FIXME */
      }
  }
  jsmnis_pop( iter_stack );

  assert( rsl == 0 );
  assert( iter_stack->stack_index == stack_idx );
  assert( mon->name != NULL );
  assert( mon->types != PT_NONE_M );
  assert( mon->base_stats.stamina != 0 );
  assert( mon->base_stats.attack != 0 );
  assert( mon->base_stats.defense != 0 );

  return mon->dex_number;
}


/* ------------------------------------------------------------------------- */

  uint16_t
parse_pvp_move( const char * json, jsmnis_t * iter_stack )
{
  return 0;
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
