/* -*- mode: c; -*- */

#ifndef _PARSE_GM_H
#define _PARSE_GM_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include "ptypes.h"
#include "util/jsmn_iterator_stack.h"
#include "util/json_util.h"
#include <assert.h>
#include <pokedex.h>
#include <regex.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


/* ------------------------------------------------------------------------- */

static const char pokemon_template_pat[] = "^V[[:digit:]]\\{4\\}_POKEMON_";


/* ------------------------------------------------------------------------- */

typedef jsmn_file_parser_t gm_parser_t;

struct gm_parser_s {
  jsmn_file_parser_t;
  uint32_t            first_mon_idx;
  uint32_t            first_move_idx;
};


/* ------------------------------------------------------------------------- */

  static void
free_gm_parser( gm_parser_t * gm_parser )
{
  free_jsmn_file_parser( gm_parser );
}


/* ------------------------------------------------------------------------- */

  static size_t
init_gm_parser( const char * gm_fpath, gm_parser_t * gm_parser )
{
  assert( gm_fpath != NULL );
  assert( gm_parser != NULL );

  size_t read_chars  = jsmn_file_parser_init( gm_fpath, gm_parser );
  long   read_tokens = 0;

  if ( read_chars == 0 ) return 0;  /* Don't worry, it doesn't leak. */

  /* `jsmn_parse_realloc' handles allocation. */
  read_tokens = jsmn_parse_realloc( &( gm_parser->jparser ),
                                    gm_parser->buffer,
                                    gm_parser->buffer_len,
                                    &( gm_parser->tokens ),
                                    &( gm_parser->tokens_cnt )
                                  );
  if ( read_tokens == JSMN_ERROR_NOMEM )
    {
      fprintf( stderr,
              "%s: JSMN failed to allocate space for tokens for file '%s'.\n",
              __func__,
              gm_fpath
            );
      free_gm_parser( gm_parser );
      return 0;
    }

  gm_parser->tokens_cnt = read_tokens;

  return read_tokens;
}


/* ------------------------------------------------------------------------- */

  static ptype_t
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

static const char pvp_move_template_pat[] = "^COMBAT_V[[:digit:]]\\{4\\}_MOVE_";
static const char pvp_fast_move_template_pat[] =
  "^COMBAT_V[[:digit:]]\\{4\\}_MOVE_[A-Z_]\\+_FAST$";
/*
 * {
 *   "templateId": "COMBAT_V0013_MOVE_WRAP",
 *   "combatMove": {
 *     "uniqueId": "WRAP",
 *     "type": "POKEMON_TYPE_NORMAL",
 *     "power": 60.0,
 *     "vfxName": "wrap",
 *     "energyDelta": -45
 *   }
 * }, {
 *   "templateId": "COMBAT_V0062_MOVE_ANCIENT_POWER",
 *   "combatMove": {
 *     "uniqueId": "ANCIENT_POWER",
 *     "type": "POKEMON_TYPE_ROCK",
 *     "power": 45.0,
 *     "vfxName": "ancient_power",
 *     "energyDelta": -45,
 *     "buffs": {
 *       "attackerAttackStatStageChange": 2,
 *       "attackerDefenseStatStageChange": 2,
 *       "buffActivationChance": 0.1
 *     }
 *   }
 * }, {
 *   "templateId": "COMBAT_V0200_MOVE_FURY_CUTTER_FAST",
 *   "combatMove": {
 *     "uniqueId": "FURY_CUTTER_FAST",
 *     "type": "POKEMON_TYPE_BUG",
 *     "power": 2.0,
 *     "vfxName": "fury_cutter_fast",
 *     "energyDelta": 4
 *   }
 * }
 *
 */

  static uint16_t
parse_pvp_move( const char * json, jsmnis_t * iter_stack )
{
  return 0;
}



/* ------------------------------------------------------------------------- */

/**
 * 0 Return indicates failure
 */
  static uint16_t
parse_gm_dex_num( const char * json, jsmntok_t * token )
{
  if ( ( json == NULL ) || ( token == NULL ) ) return 0;
  if ( json[token->start] != 'V' ) return 0;
  char buffer[4] = { '\0', '\0', '\0', '\0' };
  strncpy( buffer, json + token->start + 1, 4 );
  return atoi( buffer );
}


/* ------------------------------------------------------------------------- */

  static stats_t
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

  static uint16_t
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



/* ========================================================================= */

#endif /* parse_gm.h */

/* vim: set filetype=c : */
