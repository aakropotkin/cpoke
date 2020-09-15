/* -*- mode: c; -*- */

#ifndef _GM_STORE_H
#define _GM_STORE_H

/* ========================================================================= */

#include "gm_parser.h"
#include "moves.h"
#include "pokedex.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------- */

struct gm_store_aux_s {
  uint16_t       mons_cnt;
  uint16_t       moves_cnt;
  pdex_mon_t   * mons_by_name;
  pdex_mon_t   * mons_by_dex;
  store_move_t * moves_by_name;
  store_move_t * moves_by_dex;
};
typedef struct gm_store_aux_s  gm_store_aux_t;

typedef store_t  gm_store_t;


/* ------------------------------------------------------------------------- */

struct gm_store_key_s {
  uint8_t  is_move; /* : 1; ( Actually a 1 bit boolean but we need to pad. ) */
  uint16_t id;
  uint8_t  form_idx;
};
typedef struct gm_store_key_s  gm_store_key_t;

  static inline gm_store_key_t
hkey_to_gmskey( uint32_t hkey )
{
  return (gm_store_key_t) {
    false,
    hkey >> ( 8 * sizeof( uint8_t ) ),
    hkey & 0b11111111
  };
}

  static inline uint32_t
gmskey_to_hkey( gm_store_key_t key )
{
  assert( key.is_move == false );
  return ( key.id << ( 8 * sizeof( uint8_t ) ) ) | key.form_idx;
}


  static inline gm_store_key_t
move_id_to_gmskey( uint16_t move_id )
{
  return (gm_store_key_t) { true, move_id, 0 };
}

  static inline uint16_t
gmskey_to_move_id( gm_store_key_t key )
{
  assert( key.is_move == true );
  return key.move_id;
}

#define as_gmsk( STORE_KEY )  ( (gm_store_key_t) ( STORE_KEY ) )


/* ------------------------------------------------------------------------- */

bool gm_store_has( gm_store_t * gm_store, store_key_t key );
int  gm_store_get( gm_store_t * gm_store, store_key_t key, void ** val );
int  gm_store_add( gm_store_t * gm_store, store_key_t key, void * val );
int  gm_store_set( gm_store_t * gm_store, store_key_t key, void * val );
int  gm_store_init( gm_store_t * gm_store, void * vgm_parser );
void gm_store_free( gm_store_t * gm_store );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* gm_store.h */

/* vim: set filetype=c : */
