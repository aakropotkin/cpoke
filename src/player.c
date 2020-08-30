/* -*- mode: c; -*- */

/* ========================================================================= */

#include <assert.h>
#include "player.h"

/* ------------------------------------------------------------------------- */

  uint8_t
get_remaining_pokemon( pvp_player_t * player )
{
  assert( player != NULL );
  uint8_t rem = 0;
  /* If you wanted to be REAL cool you would unroll this into a one liner... */
  for ( pvp_pokemon_t * p = player->team;
        p < player->team + 3;
        rem += ( ( p != NULL ) && ( p->hp > 0 ) ), p++
      );
  assert( rem <= 3 );
  return rem;
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
