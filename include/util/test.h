/* -*- mode: c; -*- */

#ifndef _TEST_H
#define _TEST_H

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


#define do_test( TEST_NAME )                                                  \
  printf( "%s : %s\n",                                                        \
          STRINGIFY( TEST_NAME ),                                             \
          test_ ## TEST_NAME () ? "PASS" : "FAIL"                             \
        )



/* ========================================================================= */

#endif /* test.h */

/* vim: set filetype=c : */
