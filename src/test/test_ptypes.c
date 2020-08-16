/* -*- mode: c; -*- */

/* ========================================================================= */

#include "ptypes.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test.h"


/* ------------------------------------------------------------------------- */


static bool
test_get_ptype_mask( void ) {

  expect( get_ptype_mask( PT_NONE )  == 0b0 );
  expect( get_ptype_mask( BUG )      == 0b1 );
  expect( get_ptype_mask( DARK )     == 0b10 );
  expect( get_ptype_mask( DRAGON )   == 0b100 );
  expect( get_ptype_mask( ELECTRIC ) == 0b1000 );
  expect( get_ptype_mask( FAIRY )    == 0b10000 );
  expect( get_ptype_mask( FIGHTING ) == 0b100000 );
  expect( get_ptype_mask( FIRE )     == 0b1000000 );
  expect( get_ptype_mask( FLYING )   == 0b10000000 );
  expect( get_ptype_mask( GHOST )    == 0b100000000 );
  expect( get_ptype_mask( GRASS )    == 0b1000000000 );
  expect( get_ptype_mask( GROUND )   == 0b10000000000 );
  expect( get_ptype_mask( ICE )      == 0b100000000000 );
  expect( get_ptype_mask( NORMAL )   == 0b1000000000000 );
  expect( get_ptype_mask( POISON )   == 0b10000000000000 );
  expect( get_ptype_mask( PSYCHIC )  == 0b100000000000000 );
  expect( get_ptype_mask( ROCK )     == 0b1000000000000000 );
  expect( get_ptype_mask( STEEL )    == 0b10000000000000000 );
  expect( get_ptype_mask( WATER )    == 0b100000000000000000 );

  return true;
}


static bool
test_pt_traitsp( void ) {

  expect( pt_resistp( WATER, FIRE )   == true  );
  expect( pt_immunep( WATER, POISON ) == false );
  expect( pt_immunep( STEEL, POISON ) == true  );
  expect( pt_weakp( FIRE, WATER )     == true  );

  return true;
}


static bool
test_get_damage_modifier_mono( void ) {

  expect( get_damage_modifier_mono( WATER, FIRE ) == RESIST_DMG_MOD );
  expect( get_damage_modifier_mono( WATER, POISON ) == 1.0 );
  expect( get_damage_modifier_mono( STEEL, POISON ) == IMMUNE_DMG_MOD );
  expect( get_damage_modifier_mono( FIRE, WATER ) == WEAK_DMG_MOD );

  return true;
}


static bool
test_get_damage_modifier_duo( void ) {

  expect( get_damage_modifier_duo( WATER, PT_NONE, FIRE ) == RESIST_DMG_MOD );
  expect( get_damage_modifier_duo( WATER, PT_NONE, POISON ) == 1.0 );
  expect( get_damage_modifier_duo( STEEL, PT_NONE, POISON ) == IMMUNE_DMG_MOD );
  expect( get_damage_modifier_duo( FIRE, PT_NONE, WATER ) == WEAK_DMG_MOD );
  expect( get_damage_modifier_duo( WATER, ICE, WATER ) == RESIST_DMG_MOD );
  expect( get_damage_modifier_duo( WATER, ICE, ICE ) ==
          ( RESIST_DMG_MOD * RESIST_DMG_MOD )
        );

  return true;
}


static bool
test_get_damage_modifier( void ) {

  expect( get_damage_modifier( WATER_M | PT_NONE_M, FIRE ) == RESIST_DMG_MOD );
  expect( get_damage_modifier( WATER_M | PT_NONE_M, POISON ) == 1.0 );
  expect( get_damage_modifier( STEEL_M | PT_NONE_M, POISON ) ==
          IMMUNE_DMG_MOD
        );
  expect( get_damage_modifier( FIRE_M | PT_NONE_M, WATER ) == WEAK_DMG_MOD );
  expect( get_damage_modifier( WATER_M | ICE_M, WATER ) == RESIST_DMG_MOD );
  expect( get_damage_modifier( WATER_M | ICE_M, ICE ) ==
          ( RESIST_DMG_MOD * RESIST_DMG_MOD )
        );

  return true;
}

/* ------------------------------------------------------------------------- */


int
main( int argc, char * argv[], char ** envp ) {

  do_test( get_ptype_mask );
  do_test( pt_traitsp );
  do_test( get_damage_modifier_mono );
  do_test( get_damage_modifier_duo );
  do_test( get_damage_modifier );

  return EXIT_SUCCESS;
}


/* ========================================================================= */

/* vim: set filetype=c : */
