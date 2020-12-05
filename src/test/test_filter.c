/* -*- mode: c; -*- */

/* ========================================================================== */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"
#include "filter.h"

#include "../../data/test/pdex_0.h"


/* -------------------------------------------------------------------------- */

  static bool
test_pdex_mon_region_p( void )
{
  expect( pdex_mon_region_p( & bulbasaur, R_KANTO ) == true );
  expect( pdex_mon_region_p( & bulbasaur, R_JOHTO ) == false );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_pdex_mon_region_pred( void )
{
  region_e reg = R_KANTO;
  expect( pdex_mon_region_pred( & bulbasaur, (void *) & reg ) == true );
  reg = R_JOHTO;
  expect( pdex_mon_region_pred( & bulbasaur, (void *) & reg ) == false );
  return true;
}


/* -------------------------------------------------------------------------- */

bool
test_filter( void )
{
  bool rsl = true;
  rsl &= do_test( pdex_mon_region_p );
  rsl &= do_test( pdex_mon_region_pred );

  return rsl;
}


/* -------------------------------------------------------------------------- */

#ifdef MK_TEST_BINARY
  int
main( int argc, char * argv[], char ** envp )
{
  return test_filter() ? EXIT_SUCCESS : EXIT_FAILURE;
}
#endif



/* ========================================================================== */

/* vim: set filetype=c : */
