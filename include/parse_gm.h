/* -*- mode: c; -*- */

#ifndef _PARSE_GM_H
#define _PARSE_GM_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/uthash.h"
#include "moves.h"
#include "ptypes.h"
#include "util/jsmn_iterator_stack.h"
#include "util/json_util.h"
#include <pokedex.h>
#include <regex.h>
#include <stdint.h>
#include <string.h>


/* ------------------------------------------------------------------------- */

static const char tmpl_mon_pat[]      = "^V[[:digit:]]\\{4\\}_POKEMON_";
static const char tmpl_shadow_pat[]   = "^V[[:digit:]]\\{4\\}_POKEMON_"
                                        "[A-Z_0-9]\\+_SHADOW";
static const char tmpl_pure_pat[]     = "^V[[:digit:]]\\{4\\}_POKEMON_"
                                        "[A-Z_0-9]\\+_PURIFIED";
static const char tmpl_norm_pat[]     = "^V[[:digit:]]\\{4\\}_POKEMON_"
                                        "[A-Z_0-9]\\+_NORMAL";
static const char tmpl_pvp_move_pat[] = "^COMBAT_V[[:digit:]]\\{4\\}_MOVE_";
static const char tmpl_pvp_fast_pat[] = "^COMBAT_V[[:digit:]]\\{4\\}_MOVE_"
                                        "[A-Z_]\\+_FAST";

struct gm_regexes_s {
  regex_t tmpl_mon;
  regex_t tmpl_shadow;
  regex_t tmpl_pure;
  regex_t tmpl_norm;
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
  char               *  buffer;
  size_t                buffer_len;
  jsmntok_t          *  tokens;
  size_t                tokens_cnt;
  gm_regexes_t          regs;
  jsmn_file_parser_t *  fparser;
  jsmnis_t              iter_stack;
  store_move_t       *  moves_by_name;
  store_move_t       *  moves_by_id;
  pdex_mon_t         *  mons_by_name;
  pdex_mon_t         *  mons_by_dex;
  pdex_mon_t         ** incomplete_mon;
  jsmntok_t          ** incomplete_fam;
  uint8_t               incomplete_idx;
  uint8_t               incomplete_size;
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
buff_t   parse_gm_buff( const char * json, jsmni_t * iter );
stats_t  parse_gm_stats( const char * json, jsmnis_t * iter_stack );
uint16_t parse_pdex_mon( const char   *  json,
                         jsmnis_t     *  iter_stack,
                         store_move_t *  moves_by_name,
                         pdex_mon_t   *  mons_by_name,
                         jsmntok_t    ** incomplete_fam_tok,
                         pdex_mon_t   *  mon
                       );


/* ------------------------------------------------------------------------- */

void add_pvp_charged_move_data( gm_parser_t        * gm_parser,
                                char               * name,
                                pvp_charged_move_t * move
                              );
void add_pvp_fast_move_data( gm_parser_t     * gm_parser,
                             char            * name,
                             pvp_fast_move_t * move
                           );
uint16_t lookup_move_id( store_move_t * moves, const char * name );
uint16_t lookup_move_idn( store_move_t * moves,
                          const char   * name,
                          size_t         n
                        );


/* ------------------------------------------------------------------------- */

/**
 * Returns false when adding is "incomplete", indicating that the family
 * needs to be resolved.
 * This tells the parser to push this entry onto a stack, which will be
 * resolved later.
 */
bool add_mon_data( gm_parser_t * gm_parser, pdex_mon_t * mon );

uint16_t lookup_dex( pdex_mon_t * mons, const char * name );
uint16_t lookup_dexn( pdex_mon_t * mons, const char * name, size_t n );


/* ------------------------------------------------------------------------- */

void process_moves( gm_parser_t * gm_parser );
void process_pokemon( gm_parser_t * gm_parser );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* parse_gm.h */

/* vim: set filetype=c : */
