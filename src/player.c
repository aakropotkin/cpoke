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
  return ( !! player->team[0].hp ) + ( !! player->team[1].hp ) +
         ( !! player->team[2].hp );
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

  void
decr_cooldown( pvp_player_t * player, uint8_t delta_turns )
{
  assert( player != NULL );
  uint_minus( get_active_pokemon( player ).cooldown, delta_turns );
}


/* ------------------------------------------------------------------------- */

  bool
is_active_alive( pvp_player_t * player )
{
  assert( player != NULL );
  return 0 < get_active_pokemon( player ).hp;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
