/* -*- mode: c; -*- */

#ifndef _PARSE_GM_H
#define _PARSE_GM_H

/* ========================================================================= */

#include <assert.h>
#include <json_utils.h>
#include <regex.h>
#include <stdio.h>


/* ------------------------------------------------------------------------- */

static const char pokemon_template_pat[] = "^V[[:digit:]]\\{4\\}_POKEMON_";


/* ------------------------------------------------------------------------- */

typedef jsmn_file_parser_t gm_parser_t;


/* ------------------------------------------------------------------------- */

void
free_gm_parser( gm_parser_t * gm_parser ) {
  free_jsmn_file_parser( gm_parser );
}


/* ------------------------------------------------------------------------- */

size_t
init_gm_parser( const char * gm_fpath, gm_parser_t * gm_parser ) {
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
  if ( read_tokens == JSMN_ERROR_NOMEM ) {
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



/* ========================================================================= */

#endif /* parse_gm.h */

/* vim: set filetype=c : */
