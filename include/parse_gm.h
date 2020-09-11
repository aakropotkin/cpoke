/* -*- mode: c; -*- */

#ifndef _PARSE_GM_H
#define _PARSE_GM_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ptypes.h"
#include "util/jsmn_iterator_stack.h"
#include "util/json_util.h"
#include <pokedex.h>
#include <regex.h>
#include <stdint.h>
#include <string.h>


/* ------------------------------------------------------------------------- */

static const char tmpl_mon_pat[]      = "^V[[:digit:]]\\{4\\}_POKEMON_";
static const char tmpl_pvp_move_pat[] = "^COMBAT_V[[:digit:]]\\{4\\}_MOVE_";

static const char tmpl_pvp_fast_pat[] =
  "^COMBAT_V[[:digit:]]\\{4\\}_MOVE_[A-Z_]\\+_FAST$";

struct gm_regexes_s {
  regex_t tmpl_mon;
  //regex_t tmpl_pve_move;
  regex_t tmpl_pvp_move;
  regex_t tmpl_pvp_fast;
  //regex_t tmpl_forms;
};
typedef struct gm_regexes_s  gm_regexes_t;

int  gm_regexes_init( gm_regexes_t * grs );
void gm_regexes_free( gm_regexes_t * grs );


/* ------------------------------------------------------------------------- */

struct gm_parser_s {
  char               * buffer;
  size_t               buffer_len;
  jsmntok_t          * tokens;
  size_t               tokens_cnt;
  gm_regexes_t         regs;
  jsmn_file_parser_t * fparser;
  jsmnis_t             iter_stack;
};
typedef struct gm_parser_s  gm_parser_t;

void   gm_parser_free( gm_parser_t * gm_parser );
size_t gm_parser_init( gm_parser_t * gm_parser, const char * gm_fpath  );


/* ------------------------------------------------------------------------- */

bool     stris_pvp_charged_move( const char * str, gm_regexes_t * regs );
ptype_t  parse_gm_type( const char * json, jsmntok_t * token );
uint16_t parse_pvp_fast_move( const char      *  json,
                              jsmnis_t        *  iter_stack,
                              char            ** name,
                              pvp_fast_move_t *  move
                            );
uint16_t parse_pvp_charged_move( const char         *  json,
                                 jsmnis_t           *  iter_stack,
                                 char               ** name,
                                 pvp_charged_move_t *  move
                               );
uint16_t parse_gm_dex_num( const char * json, jsmntok_t * token );
buff_t   parse_gm_buff( const char * json, jsmnis_t * iter_stack );
stats_t  parse_gm_stats( const char * json, jsmnis_t * iter_stack );
uint16_t parse_pdex_mon( const char * json,
                         jsmnis_t   * iter_stack,
                         pdex_mon_t * mon
                       );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* parse_gm.h */

/* vim: set filetype=c : */
