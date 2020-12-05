/* -*- mode: c; -*- */

/* ========================================================================== */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"
#include "util/fuzzy.h"


/* -------------------------------------------------------------------------- */


  static bool
test_levenshtein( void )
{
  expect( levenshtein( "kitten", "sitting" ) == 3 );
  return true;
}


/* -------------------------------------------------------------------------- */

  bool
test_fuzzy( void )
{
  bool rsl = true;
  rsl &= do_test( levenshtein );
  return rsl;
}


/* -------------------------------------------------------------------------- */

#ifdef MK_TEST_BINARY
  int
main( int argc, char * argv[], char ** envp )
{
  return test_fuzzy() ? EXIT_SUCCESS : EXIT_FAILURE;
}
#endif


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
