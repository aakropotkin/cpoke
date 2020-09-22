/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"
#include "player.h"
#include "ptypes.h"
#include "pvp_action.h"
#include "util/test_util.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */


  static bool
test_is_valid_action( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;

  p1.team.mon0.hp = 10;

  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_battle( void )
{
  bool rsl = true;
  rsl &= do_test( is_valid_action );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
