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

/* A fake pokemon to build teams */
pvp_pokemon_t MON1 = {
  .stats         = { .attack = 1, .stamina = 1, .defense = 1 },
  .types         = NORMAL_M,
  .hp            = 10,
  .cooldown      = 0,
  .stored_energy = 0,
  .buffs         = NO_BUFF_STATE,
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
};


/* ------------------------------------------------------------------------- */

  static bool
test_get_remaining_pokemon( void )
{
  pvp_player_t player = PVP_PLAYER_NULL;
  player.team[0] = MON1;
  player.team[1] = MON1;
  player.team[2] = MON1;

  expect( get_remaining_pokemon( & player ) == 3 );
  player.team[0].hp = 0;
  expect( get_remaining_pokemon( & player ) == 2 );
  player.team[1].hp = 0;
  expect( get_remaining_pokemon( & player ) == 1 );
  player.team[2].hp = 0;
  expect( get_remaining_pokemon( & player ) == 0 );
  player.team[1].hp = 10;
  expect( get_remaining_pokemon( & player ) == 1 );
  player.team[0].hp = 10;
  expect( get_remaining_pokemon( & player ) == 2 );
  player.team[2].hp = 10;
  expect( get_remaining_pokemon( & player ) == 3 );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_use_shield( void )
{
  pvp_player_t player = PVP_PLAYER_NULL;
  bool         used   = false;
  assert( player.shields == 2 );

  used = use_shield( & player );
  expect( used == true );
  expect( player.shields == 1 );

  used = use_shield( & player );
  expect( used == true );
  expect( player.shields == 0 );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_switch_timer( void )
{
  pvp_player_t player = PVP_PLAYER_NULL;
  assert( player.switch_turns == 0 );

  start_switch_timer( & player );
  expect( 0 < player.switch_turns );
  expect( player.switch_turns == SWITCH_TURNS );

  assert( 2 < player.switch_turns );
  decr_switch_timer( & player, 2 );
  expect( player.switch_turns == ( SWITCH_TURNS - 2 ) );

  assert( 0 < player.switch_turns );
  decr_switch_timer( & player, player.switch_turns + 1 );
  expect( player.switch_turns == 0 );

  start_switch_timer( & player );
  expect( 0 < player.switch_turns );
  expect( player.switch_turns == SWITCH_TURNS );

  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_player( void )
{
  bool rsl = true;

  rsl &= do_test( get_remaining_pokemon );
  rsl &= do_test( use_shield );
  rsl &= do_test( switch_timer );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
