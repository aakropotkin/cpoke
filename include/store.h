/* -*- mode: c; -*- */

#ifndef _STORE_H
#define _STORE_H

/* ========================================================================= */

#include <stdint.h>
#include <stdbool.h>

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

typedef enum {
  STORE_NULL_STATUS,
  STORE_SUCCESS,
  STORE_ERROR_FAIL,
  STORE_ERROR_BAD_VALUE,
  STORE_ERROR_NOMEM,
  STORE_ERROR_NOT_FOUND
} store_status_t;

typedef uint64_t  store_key_t;

typedef bool ( * store_has_fn )( struct store_s *, store_key_t );
typedef int  ( * store_get_fn )( struct store_s *, store_key_t, void ** );
typedef int  ( * store_add_fn )( struct store_s *, store_key_t, void * );
typedef int  ( * store_set_fn )( struct store_s *, store_key_t, void * );
typedef void ( * store_free_fn )( struct store_s * );

struct store_s {
  char *         name;
  bool           writable;
  store_has_fn   has;
  store_get_fn   get;
  store_add_fn   add;
  store_set_fn   set;
  store_free_fn  free;
  void *         aux;
};

typedef struct store_s  store_t;


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* store.h */

/* vim: set filetype=c : */
