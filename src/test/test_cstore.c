/* -*- mode: c; -*- */

/* ========================================================================== */

#include "pokedex.h"
#include "pokemon.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"
#define CSTORE_GLOBAL_STORE
#include "cstore.h"


/* -------------------------------------------------------------------------- */

  static bool
test_cstore_get_pokemon( void )
{
  pdex_mon_t * mon = NULL;
  int          rsl = cstore_get_pokemon( & CSTORE, 1, 0, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 1 );
  expect( mon->form_idx   == 0 );

  rsl = cstore_get_pokemon( & CSTORE, 1, 1, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 1 );
  expect( mon->form_idx   == 1 );

  rsl = cstore_get_pokemon( & CSTORE, 2, 0, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 2 );
  expect( mon->form_idx   == 0 );

  rsl = cstore_get_pokemon( & CSTORE, 3, 1, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 3 );
  expect( mon->form_idx   == 1 );

  rsl = cstore_get_pokemon( & CSTORE, 809, 0, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 809 );
  expect( mon->form_idx   == 0 );

  rsl = cstore_get_pokemon( & CSTORE, 808, 0, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 808 );
  expect( mon->form_idx   == 0 );

  rsl = cstore_get_pokemon( & CSTORE, 649, 0, & mon );
  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 649 );
  expect( mon->form_idx   == 0 );

  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_cstore_get_pokemon_by_name( void )
{
  pdex_mon_t * mon = NULL;
  int          rsl = cstore_get_pokemon_by_name( & CSTORE, "BULBASAUR", & mon );

  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 1 );
  expect( mon->form_idx == 0 );

  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_cstore_get_move( void )
{
  store_move_t * move = NULL;
  int            rsl  = cstore_get_move( & CSTORE, 13, & move );

  expect( rsl == STORE_SUCCESS );
  expect( move != NULL );
  expect( move->move_id == 13 );

  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_cstore_get_move_by_name( void )
{
  store_move_t * move = NULL;
  int            rsl  = cstore_get_move_by_name( & CSTORE, "WRAP", & move );

  expect( rsl == STORE_SUCCESS );
  expect( move != NULL );
  expect( move->move_id == 13 );

  return true;
}


/* -------------------------------------------------------------------------- */

  static bool
test_cstore_get( void )
{
  pdex_mon_t   * mon  = NULL;
  store_move_t * move = NULL;
  int rsl             = cstore_get( & CSTORE,
                                    dex_form_store_key( 1, 0 ),
                                    (void **) & mon
                                  );

  expect( rsl == STORE_SUCCESS );
  expect( mon != NULL );
  expect( mon->dex_number == 1 );
  expect( mon->form_idx == 0 );

  rsl = cstore_get( & CSTORE, move_id_store_key( 13 ), (void **) & move );
  expect( rsl == STORE_SUCCESS );
  expect( move != NULL );
  expect( move->move_id == 13 );

  return true;
}


/* -------------------------------------------------------------------------- */

  bool
test_cstore( void )
{
  bool rsl = true;
  rsl &= CS_init() == STORE_SUCCESS;
  rsl &= do_test( cstore_get_pokemon );
  rsl &= do_test( cstore_get_pokemon_by_name );
  rsl &= do_test( cstore_get_move );
  rsl &= do_test( cstore_get_move_by_name );
  rsl &= do_test( cstore_get );
  CS_free();
  return rsl;
}


/* -------------------------------------------------------------------------- */

#ifdef MK_TEST_BINARY
int
main( int argc, char * argv[], char ** envp )
{
  return test_cstore() ? EXIT_SUCCESS : EXIT_FAILURE;
}
#endif


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
