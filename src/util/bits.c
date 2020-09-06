/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include "util/bits.h"

/* ------------------------------------------------------------------------- */

  void
lshowbits ( unsigned long ul ) {
  for ( int i = 8 * sizeof( unsigned long ) -1; i >= 0; i-- )
    printf( "%lu", ( ul >> i ) & 1 );
  putchar( '\n' );
}

void
ishowbits ( unsigned int ui ) {
  for ( int j = 8 * sizeof( unsigned int ) -1; j >= 0; j-- )
    printf( "%u", ( ui >> j ) & 1 );
  putchar( '\n' );
}


/* ========================================================================= */

/* vim: set filetype=c : */
