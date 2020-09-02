/* -*- mode: c; -*- */

/* ========================================================================= */

#include "pokemon.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"

/* ------------------------------------------------------------------------- */


  static bool
test_get_cpm_for_level( void )
 {
  expect( get_cpm_for_level( 1 ) == CPMS[0] );
  expect( get_cpm_for_level( 39.5 ) == CPMS[77] );
  expect( get_cpm_for_level( 40 ) == CPMS[78] );

  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_pokemon( void )
{
  bool rsl = true;
  rsl &= do_test( get_cpm_for_level );
  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
