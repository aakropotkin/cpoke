/* -*- mode: c; -*- */

/* ========================================================================= */

#include "ai/ai.h"
#include "battle.h"
#include "player.h"
#include "pokemon.h"
#include "pvp_action.h"
#include "util/test_util.h"
#define CSTORE_GLOBAL_STORE
#include "cstore.h"
#include "ai/naive_ai.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ------------------------------------------------------------------------- */

  static bool
test_decide_action( void )
{
  pvp_player_t     p1       = PVP_PLAYER_NULL;
  pvp_player_t     p2       = PVP_PLAYER_NULL;
  pvp_action_t     a1       = ACT_NULL;
  pvp_action_t     a2       = ACT_NULL;
  pvp_battle_t     battle   = PVP_BATTLE_NULL;
  int              rsl      = 0;
  base_pokemon_t   base_ven = BASE_MON_NULL;
  base_pokemon_t   base_vap = BASE_MON_NULL;
  roster_pokemon_t rost_ven = {
    .base             = & base_ven,
    .fast_move_id     = 214,         /* Vine Whip */
    .charged_move_ids = { 296, 90 }  /* Frenzy Plant, Sludge Bomb */
  };
  roster_pokemon_t rost_vap = {
    .base             = & base_vap,
    .fast_move_id     = 230,
    .charged_move_ids = { 58, 300 }  /* Aqua Tail , Last Resort */
  };
  /* There is no reason to initialize Naive AIs */
  ai_t p1_ai = def_naive_ai();
  ai_t p2_ai = def_naive_ai();

  /* Vaporeon vs Venusaur */
  rsl = base_mon_from_store( & CSTORE, 1, 0, 20.0, 15, 15, 15, & base_ven );
  assert( rsl == STORE_SUCCESS );
  rsl = base_mon_from_store( & CSTORE, 134, 0, 20.0, 15, 15, 15, & base_vap );
  assert( rsl == STORE_SUCCESS );
  pvp_pokemon_init( & p1.team[0], & rost_ven, & CSTORE );
  pvp_pokemon_init( & p2.team[0], & rost_vap, & CSTORE );
  assert( p1.team[0].fast_move.move_id == 214 );

  battle.p1    = & p1;
  p1.ai        = & p1_ai;
  battle.p2    = & p2;
  p2.ai        = & p2_ai;
  battle.phase = COUNTDOWN;

  /* Ensure AIs to not try to swap, given that they have only 1 pokemon */
  a1 = decide_action( true, & battle );
  expect( a1 == WAIT );
  a2 = decide_action( true, & battle );
  expect( a2 == WAIT );

  battle.phase = NEUTRAL;
  a1 = decide_action( true, & battle );
  expect( a1 == FAST );
  a2 = decide_action( true, & battle );
  expect( a2 == FAST );

  return true;
}



/* ------------------------------------------------------------------------- */

  bool
test_naive_ai( void )
{
  bool rsl = true;

  rsl &= CS_init() == STORE_SUCCESS;
  rsl &= do_test( decide_action );
  CS_free();

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
