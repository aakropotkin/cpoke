/* -*- mode: c; -*- */

#ifndef _GM_STORE_H
#define _GM_STORE_H

/* ========================================================================= */

#include "parse_gm.h"
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
  store_move_t * moves_by_id;
};
typedef struct gm_store_aux_s  gm_store_aux_t;

#define as_gmsa( STORE_PTR )  ( (gm_store_aux_t *) ( STORE_PTR )->aux )

typedef store_t  gm_store_t;


/* ------------------------------------------------------------------------- */

union gm_store_key_u {
  store_key_t store_key;
  struct gm_store_key_fields_s {
    uint8_t  is_move;
    uint16_t id;
    uint8_t  form_idx;
  } fields;
};
typedef union gm_store_key_u  gm_store_key_t;

  static inline gm_store_key_t
hkey_to_gmskey( uint32_t hkey )
{
  return (gm_store_key_t) {
    .fields = {
      false,
      hkey >> ( 8 * sizeof( uint8_t ) ),
      hkey & 0b11111111
    }
  };
}

  static inline uint32_t
gmskey_to_hkey( gm_store_key_t key )
{
  assert( key.fields.is_move == false );
  return ( key.fields.id << ( 8 * sizeof( uint8_t ) ) ) | key.fields.form_idx;
}


  static inline gm_store_key_t
move_id_to_gmskey( uint16_t move_id )
{
  return (gm_store_key_t) { .fields = { true, move_id, 0 } };
}

  static inline uint16_t
gmskey_to_move_id( gm_store_key_t key )
{
  assert( key.fields.is_move == true );
  return key.fields.id;
}

#define as_gmsk( STORE_KEY )                                                  \
  ( (gm_store_key_t) { .store_key = ( STORE_KEY ) } ).fields


/* ------------------------------------------------------------------------- */

bool gm_store_has( store_t * gm_store, store_key_t key );
int  gm_store_get( store_t * gm_store, store_key_t key, void ** val );
int  gm_store_add( store_t * gm_store, store_key_t key, void * val );
int  gm_store_set( store_t * gm_store, store_key_t key, void * val );
int  gm_store_init( store_t * gm_store, void * vgm_parser );
void gm_store_free( store_t * gm_store );


/* ------------------------------------------------------------------------- */

static store_t gm_store = {
  .name     = "Game Master",
  .writable = false,
  .has      = gm_store_has,
  .get      = gm_store_get,
  .add      = gm_store_add,
  .set      = gm_store_set,
  .init     = gm_store_init,
  .free     = gm_store_free,
  .aux      = NULL
};


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* gm_store.h */

/* vim: set filetype=c : */
