/* -*- mode: c; -*- */

#ifndef _MOVES_H
#define _MOVES_H

/* ========================================================================= */

#include <stdint.h>
#include <stdbool.h>
#include "ptypes.h"


/* ------------------------------------------------------------------------- */

typedef enum packed {
  bc_1000, bc_0500, bc_0300, bc_0125, bc0100, bc0000
} buff_chance_t; /* 3 bits used, 4 total */

typedef struct packed {
  uint8_t target  : 1; /* 0 --> self; 1 --> opponent */
  uint8_t debuffp : 1; /* 1 --> Debuff --> ( - amount ) */
  uint8_t amount  : 2;
} stat_buff_t; /* 4 bits */

const_fn int8_t
decode_stat_buff( stat_buff_t buff ) {
  return buff.debuffp ? buff.amount : ( - buff.amount );
}

typedef struct packed {
  buff_chance_t chance;   /* I think 3 bits */
  stat_buff_t   atk_buff;
  stat_buff_t   def_buff;
} buff_t; /* 11 bits used, 16 total */



const buff_t NO_BUFF = { .chance = bc0000,
                         .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
                         .def_buff = { .target = 0, .debuffp = 0, .amount = 0 }
                       };


const double BUFF_MOD[] = {
  0.5000000, 0.5714286, 0.6666667, 0.8000000,  /* Debuff */
  1.0000000,
  1.2500000, 1.5000000, 1.7500000, 2.0000000   /*  Buff  */
};

typedef enum packed {
  B_4_8, B_4_7, B_4_6, B_4_5,
  B_4_4,
  B_5_4, B_6_4, B_7_4, B_8_4
} buff_level_t;


typedef struct packed {
  buff_level_t atk_buff_lv;
  buff_level_t def_buff_lv;
} buff_state_t;


#define get_buff_mod( buff_level )  ( BUFF_MOD( ( buff_level ) ) )


void
apply_buff( buff_state_t * buff_state, buff_t buff ) {
  /* Attack */
  if ( buff.atk_buff.debuffp ) {
    buff_state->atk_buff_lv =
      max( B_4_8, buff_state->atk_buff_lv - buff.atk_buff.amount );
  } else {
    buff_state->atk_buff_lv =
      min( B_8_4, buff_state->atk_buff_lv + buff.atk_buff.amount );
  }
  /* Defense */
  if ( buff.def_buff.debuffp ) {
    buff_state->def_buff_lv =
      max( B_4_8, buff_state->def_buff_lv - buff.def_buff.amount );
  } else {
    buff_state->def_buff_lv =
      min( B_8_4, buff_state->def_buff_lv + buff.def_buff.amount );
  }
}


/**
 * Calculating Damage:
 *
 * https://www.reddit.com/r/TheSilphRoad/comments/a6pjb6/pvp_attack_bonus13_confirmed/
 *
 * move_power = floor( 0.5 * move_power * attacker.atk / defender.def * STAB * type_mod * 1.3 ) + 1
 *
 * the 1.3 is reflected in GAME_MASTER.json `COMBAT_SETTINGS.fastAttackBonusMultiplier'
 *
 * Ex: Vaporeon = { base_atk = 205, iv_atk = 14, lvl = 17 }
 *     Magikarp = { base_def = 85,  iv_def = 15, lvl = 40 }
 *
 *     attacker.atk = ( base_atk + iv_atk ) * CPM
 *     defender.def = ( base_def + iv_def ) * CPM
 *     Vaporeon.atk = ( 205 + 14 ) * 0.55079269 = 120.623599
 *     Magikarp.def = ( 85 + 15 ) * 0.7903 = 79.03
 *
 *     move = { name = water_gun, power = 3 }
 *
 *     move_power = floor( 0.5 * 3 * 120.623599 / 79.03 * 1.2 * 0.625 * 1.3 ) + 1
 *                = floor( 2.23 ) + 1
 *                = 3
 */


/**
 * As of [2020-08-22] there are 342 moves
 */
typedef struct packed {
  uint16_t move_id;
  ptype_t  type;
  uint8_t  power;   /* NOTE: These values are not always the same for PvP/PvE */
  uint8_t  energy;  /* NOTE: These values are not always the same for PvP/PvE */
} base_move_t;


typedef struct packed {
  base_move_t;           /* Inherit */
  uint16_t    cooldown;  /* ms */
} pve_move_t;


typedef struct packed {
  base_move_t;       /* Inherit */
  buff_t      buff;  /* A pointer could be used, but it costs more */
} pvp_charged_move_t;


typedef struct packed {
  base_move_t;            /* Inherit */
  uint8_t     turns : 2;  /* 1-4 */
} pvp_fast_move_t;


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* moves.h */

/* vim: set filetype=c : */
