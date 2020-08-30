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

#define get_active_pokemon( PLAYER )              \
  ( ( PLAYER ).team[( PLAYER ).active_pokemon] )


/* ------------------------------------------------------------------------- */

uint8_t get_remaining_pokemon( pvp_player_t * player );
bool    use_shield( pvp_player_t * player );
void    start_switch_timer( pvp_player_t * player );
void    decr_switch_timer( pvp_player_t * player, uint8_t delta_turns );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* player.h */

/* vim: set filetype=c : */
