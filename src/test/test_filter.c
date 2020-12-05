/* -*- mode: c; -*- */

/* ========================================================================== */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"
#include "filter.h"


/* -------------------------------------------------------------------------- */

  static bool
test_pdex_mon_region_p( void )
{
  expect( true );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_pdex_mon_region_pred( void )
{
  expect( true );
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
