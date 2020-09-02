/* -*- mode: c; -*- */

#ifndef _TEST_UTIL_H
#define _TEST_UTIL_H

/* ========================================================================= */

#include "util/macros.h"
#include <stdbool.h>
#include <stdio.h>


#define expect( BOOL_EXPR )                                                   \
  do {                                                                        \
    if ( ! ( BOOL_EXPR ) ) {                                                  \
      fprintf( stderr, "Expectation failed: %s\n", TOSTRING( BOOL_EXPR ) );   \
      return false;                                                           \
    }                                                                         \
  } while( false )


/* ------------------------------------------------------------------------- */

#define do_test( TEST_NAME )                                                  \
  __extension__(                                                              \
  {                                                                           \
    bool rsl = test_ ## TEST_NAME ();                                         \
    printf( "%s : %s\n",                                                      \
            STRINGIFY( TEST_NAME ),                                           \
            rsl ? "PASS" : "FAIL"                                             \
          );                                                                  \
    rsl;                                                                      \
  }                                                                           \
               )


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* test_util.h */

/* vim: set filetype=c : */
