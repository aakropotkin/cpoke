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
  if ( ( str == NULL ) || ( token == NULL ) ) return PTYPE_NONE;
  if ( token->size < 16 ) return PTYPE_NONE; /* Ice is shortest at 16 */
  if ( strncmp( json + token->start, "POKEMON_TYPE_", 13 ) != 0 )
    {
      return PTYPE_NONE;
    }

  for ( int i = 1; i < NUM_PTYPES; i++ )
    {
      if ( strncasecmp( json + token->start  + 13,
                        ptype_names[i],
                        token->size - 13
                      ) == 0
         ) return (ptype_t) i;
    }

  return PTYPE_NONE;
}


/* ------------------------------------------------------------------------- */

static const TARGET_KEYS[] = {
  "templateId",                    /* Holds Dex # */
  "pokemon . uniqueId",
  "pokemon . type1",
  "pokemon . type2",               /* Optional */
  "pokemon . stats .baseStamina",
  "pokemon . stats .baseAttack",
  "pokemon . stats .baseDefense",
  "pokemon . quickMoves",
  "pokemon . cinematicMoves",
  "pokemon . form"                 /* Optional */
  "pokemon . familyId"
};

  static uint16_t
parse_pdex_mon( const char * json,
                jsmntok_t  * all_tokens,
                int          tidx,
                pdex_mon_t * mon
              )
{
  assert( json != NULL );
  assert( tokens != NULL );
  assert( mon != NULL );

  const jsmntok_t * tokens = &( all_tokens[tidx] );
  pdex_mon_init( mon );

  /* Parse Dex Number */
  const char dex_str = {
    json[tokens[0].start + 1],
    json[tokens[0].start + 2],
    json[tokens[0].start + 3],
    json[tokens[0].start + 4],
    '\0'
  };
  mon->dex_number = atoi( dex_str );
  assert( mon->dex_number != 0 );

  mon->name = strndup( tokens[4], tokens[4].size );
  assert( mon->name != NULL );

  return mon->dex_number;
}



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* parse_gm.h */

/* vim: set filetype=c : */
