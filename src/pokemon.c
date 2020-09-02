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
    const uint8_t power = get_pvp_mon_move_power( * attacker, attack_idx );
    const ptype_t mtype = get_pvp_mon_move_type( * attacker, attack_idx );
    const float   stab  = ( get_ptype_mask( mtype ) & attacker->types
                          ) ? STAB_BONUS : 1.0;
    const float   bonus = ( attack_idx == M_FAST ) ? PVP_FAST_BONUS_MOD
                                                   : PVP_CHARGE_BONUS_MOD *
                                                     CHARGE_DEFAULT_MOD;
    const double  atk   = attacker->stats.attack *
                          get_buff_mod( attacker->buffs.atk_buff_lv );
    const double  def   = defender->stats.defense *
                          get_buff_mod( defender->buffs.def_buff_lv );
    const float   teff  = get_damage_modifier( defender->types, mtype );

    return floor( 0.5 * power * atk / def * stab * teff * bonus ) + 1;
  }


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
