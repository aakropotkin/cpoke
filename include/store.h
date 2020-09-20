/* -*- mode: c; -*- */

#ifndef _STORE_H
#define _STORE_H

/* ========================================================================= */

#include "util/bits.h"
#include "util/enumflags.h"
#include <stdbool.h>
#include <stdint.h>

/* ------------------------------------------------------------------------- */

/**
 * An abstract interface for storing and fetching data.
 * This will likely be implemented by some sort of Database, whether that be
 * SQL, Redis, a file reader/writer, hash table, or possibly even a Web API.
 * <p>
 * It's got all of your good ol' fashioned set/get functions.
 * <p>
 * The naive implementation will likely have hard coded objects/structures,
 * but down the line the store should be able to parse a schema to
 * dynamically acess unknown objects.
 * <p>
 * For those who haven't seen this kind of struct design pattern before, it
 * is essentially the same idea as an "abstract class" in Object Oriented
 * Programming. This pattern will look incredibly familiar to those who are
 * used to working with JavaScript objects.
 * <p>
 * The <code>aux</code> member should likely be filled with a pointer to
 * whatever extra metadata of extra structure members you need in an
 * implementation of a store.
 */

struct store_s;


/* ------------------------------------------------------------------------- */

typedef enum {
  STORE_NULL_STATUS,
  STORE_SUCCESS,
  STORE_ERROR_FAIL,
  STORE_ERROR_BAD_VALUE,
  STORE_ERROR_NOMEM,
  STORE_ERROR_NOT_FOUND,
  STORE_ERROR_NOT_WRITABLE,
  STORE_ERROR_NOT_DEFINED
} store_status_t;


/* ------------------------------------------------------------------------- */

DEFINE_ENUM_WITH_FLAGS( store_flag,
    SF_NONE, SF_WRITABLE, SF_THREAD_SAFE, SF_OFFICIAL_DATA, SF_CUSTOM_DATA,
    SF_EXPORTABLE, SF_STANDARD_KEY, SF_TYPED, SF_GET_STRING,
    SF_GET_TYPED_STRING
  );


/* ------------------------------------------------------------------------- */

typedef enum packed {
  STORE_UNKNOWN,
  STORE_STRING,
  STORE_NUM,
  STORE_FUNCTION,
  STORE_POKEDEX,
  STORE_MOVE,
  STORE_ROSTER,
  STORE_CUP,
  STORE_PVP_POKEMON,
  STORE_PVP_TEAM,
  STORE_PVP_BATTLE,
  STORE_PVP_BATTLE_LOG,
  STORE_PVP_POKEMON_RANKING,
  STORE_PVP_MOVE_RANKING,
  STORE_ANALYTICS,
  STORE_CUSTOM
} store_type_t;

_Static_assert( sizeof( store_type_t ) == 1, "store_type_t must be 1 byte" );


/* ------------------------------------------------------------------------- */

typedef enum {
  SS_UNKNOWN, SS_C, SS_JSON, SS_SQL
} store_sink_t;

static const char * STORE_SINK_NAMES[] = {
  "SS_UNKNOWN", "SS_C", "SS_JSON", "SS_SQL"
};


/* ------------------------------------------------------------------------- */

struct store_key_s {
  store_type_t key_type;
  store_type_t val_type;
  union {
    uint32_t   data_f;
    struct {
      union { uint16_t data_h0; struct { uint8_t data_q0, data_q1; }; };
      union { uint16_t data_h1; struct { uint8_t data_q2, data_q3; }; };
    };
  } transparent;
};
typedef struct store_key_s  store_key_t;


/* ------------------------------------------------------------------------- */

/**
 * Optional functions may be left as `NULL', but it is suggested to instead
 * provide an empty function which simply returns an appropriate error code.
 */

/* Mandatory */
typedef bool ( * store_has_fn )( struct store_s *, store_key_t );
typedef int  ( * store_get_fn )( struct store_s *, store_key_t, void ** );
typedef int  ( * store_init_fn )( struct store_s *, void * );
typedef void ( * store_free_fn )( struct store_s * );

/* For `SF_GET_STRING' */
typedef int  ( * store_get_str_fn )( struct store_s *, const char *, void ** );
/* For `SF_GET_STRING' */
typedef int  ( * store_get_str_t_fn )( struct store_s *,
                                       store_type_t,
                                       const char *,
                                       void **
                                     );
/* For `SF_WRITABLE' */
typedef int  ( * store_add_fn )( struct store_s *, store_key_t, void * );
typedef int  ( * store_set_fn )( struct store_s *, store_key_t, void * );
/* For `SF_EXPORTABLE' */
typedef int ( * store_export_fn )( struct store_s *, store_sink_t, void * );


/* ------------------------------------------------------------------------- */

struct store_s {
  char              * name;
  store_flag_mask_t   flags;
  store_has_fn        has;
  store_get_fn        get;
  store_get_str_fn    get_str;
  store_get_str_t_fn  get_str_t;
  store_add_fn        add;
  store_set_fn        set;
  store_export_fn     export;
  store_init_fn       init;
  store_free_fn       free;
  void              * aux;
};

typedef struct store_s  store_t;


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* store.h */

/* vim: set filetype=c : */
