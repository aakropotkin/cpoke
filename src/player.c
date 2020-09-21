/* -*- mode: c; -*- */

/* ========================================================================= */

#include <assert.h>
#include "player.h"
#include "pokemon.h"

/* ------------------------------------------------------------------------- */

  uint8_t
get_remaining_pokemon( pvp_player_t * player )
{
  assert( player != NULL );
  return ( !! player->team.mon0.hp ) + ( !! player->team.mon1.hp ) +
         ( !! player->team.mon2.hp );
}


/* ------------------------------------------------------------------------- */

  bool
use_shield( pvp_player_t * player )
{
  assert( player != NULL );
  if ( 0 < player->shields )
    {
      player->shields--;
      return true;
    }
  return false;
}


/* ------------------------------------------------------------------------- */

  void
start_switch_timer( pvp_player_t * player )
{
  assert( player != NULL );
  player->switch_turns = SWITCH_TURNS;
}


/* ------------------------------------------------------------------------- */

  void
decr_switch_timer( pvp_player_t * player, uint8_t delta_turns )
{
  assert( player != NULL );
  uint_minus( player->switch_turns, delta_turns );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
