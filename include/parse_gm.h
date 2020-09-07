/* -*- mode: c; -*- */

#ifndef _PARSE_GM_H
#define _PARSE_GM_H

/* ========================================================================= */

#include <assert.h>
#include "util/json_util.h"
#include <regex.h>
#include <stdio.h>
#include <stdint.h>
#include <pokedex.h>
#include <string.h>
#include "ptypes.h"


/* ------------------------------------------------------------------------- */

static const char pokemon_template_pat[] = "^V[[:digit:]]\\{4\\}_POKEMON_";


/* ------------------------------------------------------------------------- */

typedef jsmn_file_parser_t gm_parser_t;


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

/* FIXME */
  static stats_t
parse_gm_stats( const char * json, jsmntok_t * token )
{
  stats_t stats = { 0, 0, 0 };
  char buffer[5] = { '\0', '\0', '\0', '\0', '\0' };
  for ( int i = 1; i <= token->size; i += 2 )
    {
      memset( buffer, '\0', 5 );
      strncpy( buffer,
               json + ( token + i + 1 )->start,
               toklen( token + i + 1 )
             );
      if ( jsoneq_str( json, token + i, "baseStamina" ) )
        {
          stats.stamina = atoi( buffer );
        }
      else if ( jsoneq_str( json, token + i, "baseAttack" ) )
        {
          stats.attack = atoi( buffer );
        }
      else if ( jsoneq_str( json, token + i, "baseDefense" ) )
        {
          stats.defense = atoi( buffer );
        }
    }
  return stats;
}


/* ------------------------------------------------------------------------- */

  static uint16_t
parse_pdex_mon( const char * json,
                jsmntok_t  * tokens,
                int          tidx,
                size_t       tokens_cnt,
                pdex_mon_t * mon
              )
{
  assert( json != NULL );
  assert( tokens != NULL );
  assert( mon != NULL );

  jsmn_iterator_t   iter;
  jsmntok_t       * key    = NULL;
  jsmntok_t       * val    = NULL;
  int               idx    = 0;
  int               rsl    = 0;
  size_t            hint   = 0;

  /* Find `templateId' key */
  idx = json_find( json,
                   tokens,
                   jsoneq_str_p,
                   (void *) "templateId",
                   tokens_cnt,
                   tidx
                   //tokens[tidx].start
                 );
  assert( 0 < idx );


  /* Ininitialize `pdex_mon_t' struct */
  /* FIXME */
  mon->types = PT_NONE_M;

  /* Parse Dex # from `templateId' value */
  mon->dex_number = parse_gm_dex_num( json, tokens + idx + 1 );
  assert( mon->dex_number != 0 );

  /* Create iterator on `pokemon' value */
  idx = json_find( json,
                   tokens,
                   jsoneq_str_p,
                   (void *) "pokemon",
                   tokens_cnt,
                   tidx
                   //tokens[tidx].start
                 );
  assert( 0 < idx );
  idx++;

  rsl = jsmn_iterator_init( &iter, tokens, tokens_cnt, idx );

  hint = tokens[idx].start;
  do {
    rsl = jsmn_iterator_next( &iter, &key, &val, hint );
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
        mon->base_stats = parse_gm_stats( json, val );
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

    hint = val->start;
  } while( 0 < rsl );

  assert( mon->name != NULL );

  return mon->dex_number;
}



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* parse_gm.h */

/* vim: set filetype=c : */
