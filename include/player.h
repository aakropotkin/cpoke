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
  ai_t *        ai;
  pvp_pokemon_t team[3];
  uint16_t      active_pokemon : 2;   /* 0-2  */
  uint16_t      shields        : 2;   /* 0-2  */
  uint16_t      switch_turns   : 5;   /* 0-26 */
} packed;
typedef struct pvp_player_s  pvp_player_t;

static const pvp_player_t PVP_PLAYER_NULL = {
  .ai             = NULL,
  .team           = { PVP_MON_NULL, PVP_MON_NULL, PVP_MON_NULL },
  .active_pokemon = 0,
  .shields        = 2,
  .switch_turns   = 0
};


/* ------------------------------------------------------------------------- */

#define get_active_pokemon( PLAYER )                                          \
  ( PLAYER )->team[( PLAYER )->active_pokemon]

#define _apply_active_mon( PLAYER, FN )  FN( get_active_pokemon( PLAYER ) )

#define is_active_alive( PLAYER )  _apply_active_mon( ( PLAYER ), is_alive )
#define get_active_energy( PLAYER )  get_active_pokemon( PLAYER ).energy
#define get_active_move_energy( PLAYER, MIDX )                                \
  get_pvp_mon_move_energy( get_active_pokemon( PLAYER ), MIDX )
#define get_active_move_power( PLAYER, MIDX )                                 \
  get_pvp_mon_move_power( get_active_pokemon( PLAYER ), MIDX )

#define start_switch_timer( PLAYER )  ( PLAYER )->switch_turns = SWITCH_TURNS

#define decr_switch_timer( PLAYER, DELTA_TURNS )                              \
  uint_minus( ( PLAYER )->switch_turns, ( DELTA_TURNS ) )

#define decr_cooldown( PLAYER, DELTA_TURNS )                                  \
  uint_minus( get_active_pokemon( PLAYER ).cooldown, ( DELTA_TURNS ) )

#define decr_energy( PLAYER, DELTA )                                          \
  uint_minus( get_active_pokemon( PLAYER ).energy, ( DELTA ) )


/* ------------------------------------------------------------------------- */

  static inline uint8_t
_get_rem_mons_ptr( pvp_player_t * player )
{
  return ( ( !! player->team[0].hp ) + ( !! player->team[1].hp ) +
           ( !! player->team[2].hp ) );
}

  static inline uint8_t
_get_rem_mons_raw( pvp_player_t player )
{
  return ( ( !! player.team[0].hp ) + ( !! player.team[1].hp ) +
           ( !! player.team[2].hp ) );
}

#define get_remaining_pokemon( PLAYER )                                       \
  ( _Generic( ( PLAYER ),                                                     \
              pvp_player_t *: _get_rem_mons_ptr,                              \
              pvp_player_t:   _get_rem_mons_raw                               \
            )( PLAYER ) )


/* ------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------- */

bool use_shield( pvp_player_t * player );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* player.h */

/* vim: set filetype=c : */
