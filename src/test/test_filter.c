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
  expect( pdex_mon_region_pred( & bulbasaur, (void *) R_KANTO ) == true );
  expect( pdex_mon_region_pred( & bulbasaur, (void *) R_JOHTO ) == false );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_base_mon_region_p( void )
{
  expect( base_mon_region_p( & base_bulbasaur, R_KANTO ) == true );
  expect( base_mon_region_p( & base_bulbasaur, R_JOHTO ) == false );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_base_mon_region_pred( void )
{
  expect( base_mon_region_pred( & base_bulbasaur, (void *) (intptr_t) R_KANTO
                              ) == true
        );
  expect( base_mon_region_pred( & base_bulbasaur, (void *) (intptr_t) R_JOHTO
                              ) == false
        );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_rost_mon_region_p( void )
{
  expect( rost_mon_region_p( & roster_bulbasaur, R_KANTO ) == true );
  expect( rost_mon_region_p( & roster_bulbasaur, R_JOHTO ) == false );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_rost_mon_region_pred( void )
{
  expect( rost_mon_region_pred( & roster_bulbasaur, (void *) (intptr_t) R_KANTO
                              ) == true
        );
  expect( rost_mon_region_pred( & roster_bulbasaur, (void *) (intptr_t) R_JOHTO
                              ) == false
        );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_explicit_regions( void )
{
  expect( pdex_mon_kanto_p( & bulbasaur ) == true );
  expect( pdex_mon_johto_p( & bulbasaur ) == false );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_regions( void )
{
  bool rsl = true;

  rsl &= do_test( pdex_mon_region_p );
  rsl &= do_test( pdex_mon_region_pred );
  rsl &= do_test( base_mon_region_p );
  rsl &= do_test( base_mon_region_pred );
  rsl &= do_test( rost_mon_region_p );
  rsl &= do_test( rost_mon_region_pred );
  rsl &= do_test( explicit_regions );

  return rsl;
}


/* -------------------------------------------------------------------------- */

  static bool
test_pdex_mon_family_p( void )
{
  expect( pdex_mon_family_p( & bulbasaur, bulbasaur.family ) == true );
  expect( pdex_mon_family_p( & bulbasaur, bulbasaur.family + 1 ) == false );
  return true;
}

/* -------------------------------------------------------------------------- */

  static bool
test_pdex_mon_family_pred( void )
{
  expect( pdex_mon_family_pred( & bulbasaur,
                                (void *) (intptr_t) bulbasaur.family
                              ) == true
        );
  expect( pdex_mon_family_pred( & bulbasaur,
                                (void *) (intptr_t) bulbasaur.family + 1
                              ) == false
        );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_base_mon_family_p( void )
{
  expect( base_mon_family_p( & base_bulbasaur, bulbasaur.family ) == true );
  expect( base_mon_family_p( & base_bulbasaur, bulbasaur.family + 1 ) == false
        );
  return true;
}

/* -------------------------------------------------------------------------- */

  static bool
test_base_mon_family_pred( void )
{
  expect( base_mon_family_pred( & base_bulbasaur,
                                (void *) (intptr_t) bulbasaur.family
                              ) == true
        );
  expect( base_mon_family_pred( & base_bulbasaur,
                                (void *) (intptr_t) bulbasaur.family + 1
                              ) == false
        );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_rost_mon_family_p( void )
{
  expect( rost_mon_family_p( & roster_bulbasaur, bulbasaur.family ) == true );
  expect( rost_mon_family_p( & roster_bulbasaur, bulbasaur.family + 1 ) == false
        );
  return true;
}

/* -------------------------------------------------------------------------- */

  static bool
test_rost_mon_family_pred( void )
{
  expect( rost_mon_family_pred( & roster_bulbasaur,
                                (void *) (intptr_t) bulbasaur.family
                              ) == true
        );
  expect( rost_mon_family_pred( & roster_bulbasaur,
                                (void *) (intptr_t) bulbasaur.family + 1
                              ) == false
        );
  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_families( void )
{
  bool rsl = true;

  rsl &= do_test( pdex_mon_family_p );
  rsl &= do_test( pdex_mon_family_pred );
  rsl &= do_test( base_mon_family_p );
  rsl &= do_test( base_mon_family_pred );
  rsl &= do_test( rost_mon_family_p );
  rsl &= do_test( rost_mon_family_pred );

  return rsl;
}


/* -------------------------------------------------------------------------- */

  bool
test_filter( void )
{
  bool rsl = true;

  rsl &= do_test( regions );
  rsl &= do_test( families );

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
