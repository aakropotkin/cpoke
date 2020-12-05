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

  static bool
test_rank_lev_dist( void )
{
  const char   * strings[]         = { "Hey", "there", "duderino" };
        size_t   nstrings          = 3;
  const char   * sranked[nstrings];
        int      dranked[nstrings];
        int      shortest          = -1;

  shortest = rank_lev_dist( "here",
                            strings,
                            nstrings,
                            sranked,
                            dranked,
                            nstrings
                          );

  expect( shortest == 1 );
  expect( strcmp( sranked[0], "there" ) == 0 );
  expect( dranked[0] == 1 );
  expect( strcmp( sranked[1], "Hey" ) == 0 );
  expect( dranked[1] == 3 );
  expect( strcmp( sranked[2], "duderino" ) == 0 );
  expect( dranked[2] == 6 );

  return true;
}


/* -------------------------------------------------------------------------- */

  bool
test_fuzzy( void )
{
  bool rsl = true;
  rsl &= do_test( levenshtein );
  rsl &= do_test( rank_lev_dist );
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
