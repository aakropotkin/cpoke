/* -*- mode: c; -*- */

#ifndef _PLAYER_H
#define _PLAYER_H

/* ========================================================================= */

#include "ai/ai.h"
#include "battle.h"
#include "pokemon.h"
#include <stdbool.h>
#include <stdint.h>


/* ------------------------------------------------------------------------- */

struct player_s {
  roster_t roster;
  uint16_t wins;
  uint16_t battles;
} packed;

typedef struct player_s  player_t;


/* ------------------------------------------------------------------------- */

struct pvp_player_s {
  ai_t *     ai;
  pvp_team_t team;
  uint8_t    active_pokemon : 2;   /* 0-2  */
  uint8_t    shields        : 2;   /* 0-2  */
  uint8_t    switch_turns   : 4;   /* 0-12 */
} packed;

typedef struct pvp_player_s  pvp_player_t;


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
  if ( player->shields > 0 )
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
  if ( player->switch_turns > 0 )
    player->switch_turns = max( 0, ( player->switch_turns - delta_turns ) );
}


/* ------------------------------------------------------------------------- */

#define get_active_pokemon( PLAYER )                                          \
  ( ( PLAYER ).team[( PLAYER ).active_pokemon] )


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* player.h */

/* vim: set filetype=c : */
