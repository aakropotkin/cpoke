/* -*- mode: c; -*- */

/* ========================================================================= */

#include "player.h"
#include "pokemon.h"
#include "moves.h"
#include "util/test_util.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */

/* All identical fake pokemon */
pvp_pokemon_t TEAM1[3] = {
  {
    .stats         = { .attack = 1, .stamina = 1, .defense = 1 },
    .types         = NORMAL_M,
    .hp            = 10,
    .cooldown      = 0,
    .stored_energy = 0,
    .buffs         = { .atk_buff_lv = B_4_4, .def_buff_lv = B_4_4 },
    .fast_move     = {
      .move_id = 1,
      .type    = NORMAL,
      .is_fast = true,
      .power   = 1,
      .energy  = 1,
      .turns   = 1
    },
    .charged_moves = {
      {
        .move_id = 2,
        .type    = NORMAL,
        .is_fast = true,
        .power   = 10,
        .energy  = 10,
        .buff    = NO_BUFF
      },
      NO_MOVE_PVP_CHARGED
    }
  }, {
    .stats         = { .attack = 1, .stamina = 1, .defense = 1 },
    .types         = NORMAL_M,
    .hp            = 10,
    .cooldown      = 0,
    .stored_energy = 0,
    .buffs         = { .atk_buff_lv = B_4_4, .def_buff_lv = B_4_4 },
    .fast_move     = {
      .move_id = 1,
      .type    = NORMAL,
      .is_fast = true,
      .power   = 1,
      .energy  = 1,
      .turns   = 1
    },
    .charged_moves = {
      {
        .move_id = 2,
        .type    = NORMAL,
        .is_fast = true,
        .power   = 10,
        .energy  = 10,
        .buff    = NO_BUFF
      },
      NO_MOVE_PVP_CHARGED
    }
  }, {
    .stats         = { .attack = 1, .stamina = 1, .defense = 1 },
    .types         = NORMAL_M,
    .hp            = 10,
    .cooldown      = 0,
    .stored_energy = 0,
    .buffs         = { .atk_buff_lv = B_4_4, .def_buff_lv = B_4_4 },
    .fast_move     = {
      .move_id = 1,
      .type    = NORMAL,
      .is_fast = true,
      .power   = 1,
      .energy  = 1,
      .turns   = 1
    },
    .charged_moves = {
      {
        .move_id = 2,
        .type    = NORMAL,
        .is_fast = true,
        .power   = 10,
        .energy  = 10,
        .buff    = NO_BUFF
      },
      NO_MOVE_PVP_CHARGED
    }
  }
};


/* ------------------------------------------------------------------------- */

static bool
test_get_remaining_pokemon( void )
{
  pvp_player_t player = {
    .ai             = NULL,
    .team           = { TEAM1[0], TEAM1[1], TEAM1[2] },
    .active_pokemon = 0,
    .shields        = 2,
    .switch_turns   = 0
  };

  expect( get_remaining_pokemon( & player ) == 3 );
  player.team.mon0.hp = 0;
  expect( get_remaining_pokemon( & player ) == 2 );
  player.team.mon1.hp = 0;
  expect( get_remaining_pokemon( & player ) == 1 );
  player.team.mon2.hp = 0;
  expect( get_remaining_pokemon( & player ) == 0 );
  player.team.mon1.hp = 10;
  expect( get_remaining_pokemon( & player ) == 1 );
  player.team.mon0.hp = 10;
  expect( get_remaining_pokemon( & player ) == 2 );
  player.team.mon2.hp = 10;
  expect( get_remaining_pokemon( & player ) == 3 );

  return true;
}


/* ------------------------------------------------------------------------- */

bool
test_player( void )
{
  bool rsl = true;
  rsl &= do_test( get_remaining_pokemon );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
