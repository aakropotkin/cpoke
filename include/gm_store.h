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
    uint32_t      : 0;      /* 22 bits padding */
  };
} transparent;
typedef union gm_store_key_u  gm_store_key_t;


/* ------------------------------------------------------------------------- */

  static inline gm_store_key_t
dex_form_to_gmskey( uint16_t dex_num, uint8_t form_idx )
{
  return (gm_store_key_t) {
    .key_type = STORE_NUM,
    .val_type = STORE_POKEDEX,
    .id       = dex_num,
    .form_idx = form_idx
  };
}

  static inline gm_store_key_t
move_id_to_gmskey( uint16_t move_id )
{
  return (gm_store_key_t) {
    .key_type = STORE_NUM,
    .val_type = STORE_MOVE,
    .id       = move_id,
    .form_idx = 0
  };
}

#define as_gmsk( STORE_KEY )                                                  \
  ( (gm_store_key_t) { .store_key = ( STORE_KEY ) } )


/* ------------------------------------------------------------------------- */

bool gm_store_has( store_t * gm_store, store_key_t key );
int  gm_store_get( store_t * gm_store, store_key_t key, void ** val );
int  gm_store_get_str( store_t * gm_store, const char *, void ** val );
int  gm_store_get_str_t( store_t      *  gm_store,
                         store_type_t    val_type,
                         const char   *  key,
                         void         ** val
                       );
int  gm_store_add( store_t * gm_store, store_key_t key, void * val );
int  gm_store_set( store_t * gm_store, store_key_t key, void * val );
int  gm_store_init( store_t * gm_store, void * vgm_parser );
void gm_store_free( store_t * gm_store );


/* ------------------------------------------------------------------------- */

int gm_store_get_pokemon( gm_store_t *  gm_store,
                          uint16_t      dex_num,
                          uint8_t       form_idx,
                          pdex_mon_t ** mon
                        );

int gm_store_get_pokemon_by_name( gm_store_t *  gm_store,
                                  const char *  name,
                                  pdex_mon_t ** mon
                                );


/* ------------------------------------------------------------------------- */

int gm_store_get_move( gm_store_t   *  gm_store,
                       uint16_t        move_id,
                       store_move_t ** move
                     );

int gm_store_get_move_by_name( gm_store_t   *  gm_store,
                               const char   *  name,
                               store_move_t ** move
                             );

/* ------------------------------------------------------------------------- */

#define def_gm_store()                                                        \
  {                                                                           \
    .name      = "Game Master",                                               \
    .flags     = SF_OFFICIAL_DATA | SF_STANDARD_KEY | SF_TYPED |              \
                 SF_GET_STRING | SF_GET_TYPED_STRING,                         \
    .has       = gm_store_has,                                                \
    .get       = gm_store_get,                                                \
    .get_str   = gm_store_get_str,                                            \
    .get_str_t = gm_store_get_str_t,                                          \
    .add       = gm_store_add,                                                \
    .set       = gm_store_set,                                                \
    .init      = gm_store_init,                                               \
    .free      = gm_store_free,                                               \
    .aux       = NULL                                                         \
  }


/* ------------------------------------------------------------------------- */

#ifdef GM_GLOBAL_STORE

static store_t GM_STORE = def_gm_store();

#define GM_has( KEY )       gm_store_has( & GM_STORE, ( KEY ) )
#define GM_get( KEY, VAL )                                                    \
  gm_store_get( & GM_STORE, ( KEY ), (void **) ( VAL ) )
#define GM_get_str( KEY, VAL )                                                \
  gm_store_get_str( & GM_STORE, ( KEY ), (void **) ( VAL ) )
#define GM_get_str_t( TYPE, KEY, VAL )                                        \
  gm_store_get_str_t( & GM_STORE, ( TYPE ), ( KEY ), (void **) ( VAL ) )
#define GM_add( KEY, VAL )                                                    \
  gm_store_add( & GM_STORE, ( KEY ), (void *) ( VAL ) )
#define GM_set( KEY, VAL )                                                    \
  gm_store_set( & GM_STORE, ( KEY ), (void *) ( VAL ) )
#define GM_init( PARSER )   gm_store_init( & GM_STORE, (void *) ( PARSER ) )
#define GM_free()           gm_store_free( & GM_STORE )

#define GM_get_pokemon( DEX, FORM, VAL )                                      \
  gm_store_get_pokemon( & GM_STORE, ( DEX ), ( FORM ), ( VAL ) )
#define GM_get_pokemon_by_name( NAME, VAL )                                   \
  gm_store_get_pokemon_by_name( & GM_STORE, ( NAME ), ( VAL ) )

#define GM_get_move( MOVE_IDX, VAL )                                          \
  gm_store_get_move( & GM_STORE, ( MOVE_IDX ), ( VAL ) )
#define GM_get_move_by_name( NAME, VAL )                                      \
  gm_store_get_move_by_name( & GM_STORE, ( NAME ), ( VAL ) )

#endif


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* gm_store.h */

/* vim: set filetype=c : */
