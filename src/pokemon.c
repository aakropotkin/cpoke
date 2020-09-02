/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"
#include "moves.h"
#include "ptypes.h"
#include "pokemon.h"
#include "util/macros.h"
#include <stdint.h>

/* ------------------------------------------------------------------------- */

  const_fn uint16_t
get_pvp_damage( pmove_idx_t     attack_idx,
                pvp_pokemon_t * attacker,
                pvp_pokemon_t * defender
              )
  {
    const base_move_t move  = get_pvp_mon_move( * attacker, attack_idx );
    const float       stab  = ( get_ptype_mask( move.type ) & attacker->types
                              ) ? STAB_BONUS : 1.0;
    const float       bonus = ( attack_idx == M_FAST ) ? PVP_FAST_BONUS_MOD
                                                       : PVP_CHARGE_BONUS_MOD *
                                                         CHARGE_DEFAULT_MOD;
    return floor( 0.5                                               *
                  move.power                                        *
                  attacker->stats.attack                            /
                  defender->stats.defense                           *
                  stab                                              *
                  get_damage_modifier( defender->types, move.type ) *
                  bonus
               ) + 1;
  }


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
