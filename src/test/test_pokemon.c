/* -*- mode: c; -*- */

/* ========================================================================= */

#include "pokedex.h"
#include "pokemon.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"

/* ------------------------------------------------------------------------- */

const base_move_t vine_whip = {
  .move_id = 214,
  .type    = GRASS,
  .is_fast = true,
  .power   = 5,
  .energy  = 8,
};

const pvp_fast_move_t vine_whip_pvp = {
  vine_whip,
  .turns     = 1
};

const base_move_t power_whip = {
  .move_id = 118,
  .type    = GRASS,
  .is_fast = false,
  .power   = 90,
  .energy  = 50,
};

const pvp_charged_move_t power_whip_pvp = {
  power_whip,
  .buff      = NO_BUFF
};

uint16_t bulb_fast_move_ids[]    = { vine_whip.move_id };
uint16_t bulb_charged_move_ids[] = { power_whip.move_id };

const pdex_mon_t bulbasaur = {
  .dex_number        = 1,
  .name              = "BULBASAUR",
  .form_name         = "NORMAL",
  .family            = 1,
  .types             = GRASS_M | POISON_M,
  .base_stats        = { .attack = 118, .stamina = 128, .defense = 111 },
  .fast_move_ids     = bulb_fast_move_ids,
  .fast_moves_cnt    = 1,
  .charged_move_ids  = bulb_charged_move_ids,
  .charged_moves_cnt = 1,
  .form_idx          = 0,
  .next_form         = NULL,
  .hkey              = 0,
  .hh_name           = 0,
  .hh_dex_num        = 0
};


/* ------------------------------------------------------------------------- */

/**
 * This "test" is essentially done at compilation time.
 */
  static bool
test_construct_pokemon( void )
{
  base_pokemon_t base_bulby_boi = {
    .pdex_mon = & bulbasaur,
    .level    = 20,
    .ivs      = { 10, 10, 10 }
  };

  roster_pokemon_t bulby_boi = {
    .base             = & base_bulby_boi,
    .fast_move_id     = vine_whip.move_id,
    .charged_move_ids = { power_whip.move_id, 0 }
  };

  roster_t my_roster = {
    .roster_pokemon = & bulby_boi,
    .roster_length  = 1
  };

  return true;
}


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
  rsl &= do_test( construct_pokemon );
  rsl &= do_test( get_cpm_for_level );
  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
