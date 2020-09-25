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



/* ========================================================================= */

/* vim: set filetype=c : */
