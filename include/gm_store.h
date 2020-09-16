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
  struct {
    store_type_t key_type;
    store_type_t val_type;
    uint16_t     id;
    uint8_t      form_idx;
    uint8_t      : 0;
  } fields;
};
typedef union gm_store_key_u  gm_store_key_t;

  static inline gm_store_key_t
hkey_to_gmskey( uint32_t hkey )
{
  return (gm_store_key_t) {
    .fields = {
      .key_type = STORE_NUM,
      .val_type = STORE_MOVE,
      .id       = hkey >> ( 8 * sizeof( uint8_t ) ),
      .form_idx = hkey & 0b11111111
    }
  };
}

  static inline uint32_t
gmskey_to_hkey( gm_store_key_t key )
{
  assert( key.fields.key_type == STORE_NUM );
  assert( key.fields.val_type == STORE_POKEDEX );
  return ( key.fields.id << ( 8 * sizeof( uint8_t ) ) ) | key.fields.form_idx;
}

  static inline gm_store_key_t
dex_form_to_gmskey( uint16_t dex_num, uint8_t form_idx )
{
  return (gm_store_key_t) {
    .fields = {
      .key_type = STORE_NUM,
      .val_type = STORE_POKEDEX,
      .id       = dex_num,
      .form_idx = form_idx
    }
  };
}

  static inline store_key_t
dex_form_to_skey( uint16_t dex_num, uint8_t form_idx )
{
  return dex_form_to_gmskey( dex_num, form_idx ).store_key;
}


  static inline gm_store_key_t
move_id_to_gmskey( uint16_t move_id )
{
  return (gm_store_key_t) {
    .fields = {
      .key_type = STORE_NUM,
      .val_type = STORE_MOVE,
      .id       = move_id,
      .form_idx = 0
    }
  };
}

  static inline uint16_t
gmskey_to_move_id( gm_store_key_t key )
{
  assert( key.fields.key_type == STORE_NUM );
  assert( key.fields.val_type == STORE_MOVE );
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

  static inline int
gm_store_get_pokemon( gm_store_t *  gm_store,
                      uint16_t      dex_num,
                      uint8_t       form_idx,
                      pdex_mon_t ** mon
                   )
{
  return gm_store_get( gm_store,
                       dex_form_to_skey( dex_num, form_idx ),
                       (void **) mon
                     );
}

  static inline int
gm_store_get_move( gm_store_t   *  gm_store,
                   uint16_t        move_id,
                   store_move_t ** move
                 )
{
  return gm_store_get( gm_store,
                       move_id_to_gmskey( move_id ).store_key,
                       (void **) move
                     );
}


/* ------------------------------------------------------------------------- */

#define def_gm_store()                                                        \
  {                                                                           \
    .name     = "Game Master",                                                \
    .flags    = SF_OFFICIAL_DATA | SF_STANDARD_KEY | SF_TYPED,                \
    .has      = gm_store_has,                                                 \
    .get      = gm_store_get,                                                 \
    .add      = gm_store_add,                                                 \
    .set      = gm_store_set,                                                 \
    .init     = gm_store_init,                                                \
    .free     = gm_store_free,                                                \
    .aux      = NULL                                                          \
  }

#ifdef GM_GLOBAL_STORE

static store_t GM_STORE = def_gm_store();
#define GM_has( KEY )       gm_store_has( & GM_STORE, ( KEY ) )
#define GM_get( KEY, VAL )                                                    \
  gm_store_get( & GM_STORE, ( KEY ), (void **) ( VAL ) )
#define GM_add( KEY, VAL )                                                    \
  gm_store_add( & GM_STORE, ( KEY ), (void *) ( VAL ) )
#define GM_set( KEY, VAL )                                                    \
  gm_store_set( & GM_STORE, ( KEY ), (void *) ( VAL ) )
#define GM_init( PARSER )   gm_store_init( & GM_STORE, (void *) ( PARSER ) )
#define GM_free()           gm_store_free( & GM_STORE )

#define GM_get_pokemon( DEX, FORM, VAL )                                      \
  gm_store_get_pokemon( & GM_STORE, ( DEX ), ( FORM ), ( VAL ) )
#define GM_get_move( MOVE_IDX, VAL )                                          \
  gm_store_get_move( & GM_STORE, ( MOVE_IDX ), ( VAL ) )

#endif


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* gm_store.h */

/* vim: set filetype=c : */
