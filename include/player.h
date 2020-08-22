/* -*- mode: c; -*- */

#ifndef _PLAYER_H
#define _PLAYER_H

/* ========================================================================= */

#include "ai/ai.h"
#include "pokemon.h"
#include <stdbool.h>
#include <stdint.h>


/* ------------------------------------------------------------------------ */

typedef struct packed {
  roster_t roster;
  uint16_t wins;
  uint16_t battles;
} player_t;


typedef struct packed pvp_player_s {
  pvp_team_t         team;
  uint8_t            active_pokemon : 2;   /* 0-2  */
  uint8_t            shields        : 2;   /* 0-2  */
  uint8_t            switch_turns   : 4;   /* 0-12 */
  #ifdef AI_AUX_TYPE
  ai_aux_t           ai_aux;
  #endif
  #ifndef NO_DECIDE_ACTION_FNS
  decide_action_fn_t decide_action_fn;
  #endif
} pvp_player_t;


uint8_t
get_remaining_pokemon( pvp_player_t * player ) {
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


bool
use_shield( pvp_player_t * player ) {
  assert( player != NULL );
  if ( player->shields > 0 ) {
    player->shields--;
    return true;
  }
  return false;
}


void
start_switch_timer( pvp_player_t * player ) {
  assert( player != NULL );
  player->switch_timer = SWITCH_TIME;
}


void
decr_switch_timer( pvp_player_t * player, uint16_t delta_time ) {
  assert( player != NULL );
  if ( player->switch_timer > 0 )
    player->switch_timer = max( 0, ( player->switch_timer - delta_time ) );
}


#define get_active_pokemon( PLAYER )                                          \
  ( ( PLAYER ).team[( PLAYER ).active_pokemon] )



/* ========================================================================= */

#endif /* player.h */

/* vim: set filetype=c : */
