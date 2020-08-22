/* -*- mode: c; -*- */

#ifndef _BATTLE_H
#define _BATTLE_H

/* ========================================================================= */

#include <stdint.h>
#include "util/macros.h"
#include "pokemon.h"
#include "player.h"


/* ------------------------------------------------------------------------- */


const float PVP_FAST_BONUS_MOD   = 1.3;
const float PVP_CHARGE_BONUS_MOD = 1.3;
const float CHARGE_BASE_MOD      = 0.25;
const float CHARGE_NICE_MOD      = 0.5;
const float CHARGE_GREAT_MOD     = 0.75;
const float CHARGE_EXCELLENT_MOD = 1.0;


typedef enum packed {
  FAST, CHARGED, WAIT, SHIELD, SWAP
} action_t;


typedef enum packed {
  BOTH_BAIT, NEITHER_BAIT, NO_BAIT, FARM
} stype_t;


typedef struct packed {
  stype_t    name;
  /* battler_t  opponent; */
  uint32_t * matchups;
  uint32_t   average;
  uint8_t    min_shields;
} scenario_t;


typedef struct packed {
  pokemon_t    pokemon;
  scenario_t * scenarios;
  uint32_t     average;
} roster_performance_t;


/**
 * These decisions help AI pick teams from a roster.
 */
typedef enum packed {
  BASIC, BEST, COUNTER, UNBALANCED, SAME_TEAM, SAME_TEAM_DIFFERENT_LEAD,
  COUNTER_LAST_LEAD
} dtype_t;

typedef struct packed {
  dtype_t  name;
  uint32_t weight;
} decision_option_t;


typedef enum packed { SIMULATE, EMULATE } battle_mode_t;
typedef enum packed { FIRST_FAINT, BOTH_FAINT } battle_end_cond_t;
/**
 * Controls how CMP Ties should be handled.
 *  - "Ideal" is the way that Niantic claims it works ( as of 2020 it doesn't )
 *     where the Pokemon with the highest Attack stat wins.
 *  - "Alternate" is what PvPoke uses where winners alternate.
 *  - "Favor" rules essentially handicap one player, which often happens as a
 *    result of P2P hosts being advantaged. ( Don't ask why, blame Niantic )
 */
typedef enum packed {
  CMP_IDEAL, CMP_ALTERNATE, CMP_FAVOR_P1, CMP_FAVOR_P2
} cmp_rule_t;

/**
 * I'm pretty sure these are only used for UI animations during
 * interactive battles.
 */
typedef enum packed {
  NEUTRAL, COUNTDOWN, SUSPEND_CHARGED, SUSPED_CHARGED_ATTACK,
  SUSPEND_CHARGED_SHIELD, SUSPEND_CHARGED_NO_SHIELD, SUSPEND_SWITCH_P1,
  SUSPEND_SWITCH_P2, ANIMATING, GAME_OVER
} battle_phase_t;
typedef

/**
 * PvPoke has separate constructs for "Actions" and "Timeline Events".
 * From what I can tell these are nearly identical, and they spent a huge amount
 * of resources converting between the two during simulation and analysis.
 * I have combined them so that a list of actions can represent the full
 * decision tree of a battle.
 *
 * FIXME:
 * The effect of random chance buffs are unfortunately not going to appear in
 * this encoding. This should be fixed once the simulator is more fleshed out
 * and we understand how buffs are relevant to analysis.
 */
typedef enum packed {
  ACT_NULL, FAST, WAIT, CHARGED1, CHARGED2, SWITCH1, SWITCH2, SHIELD
} pvp_action_t;


const uint8_t MAX_CHARGE        = 100;
const uint8_t CHARGE_RATE       = 20;
const float   CHARGE_DECAY_RATE = 0.5;

const uint8_t TURN_TIME         = 500;    /* ms */
const uint8_t CHARGED_TIME      = 4000;   /* ms */
const uint8_t SWITCH_TIME       = 13000;  /* ms */

const uint8_t CHARGED_TURNS     = 8;
const uint8_t SWITCH_TURNS      = 26;


/**
 * This can often be constructed from a battle timeline, and is not always
 * desired in a simulation, so it is not included in <code>battle_t</code>
 */
typedef struct packed {
  uint32_t total_damage;
  uint32_t total_charged_damage;        /* Damage dealt with Charged Moves */
  uint32_t total_damage_blocked;        /* Damage prevent by shielding     */
  uint32_t total_energy_gained;
  uint32_t total_energy_used;
  uint32_t damage_against_shields;      /* Damage wasted on enemy shields  */
  uint8_t  damage_through_shields;      /* Damage taken while shielding    */
  uint8_t  shields_used           : 2;  /* 0-2 */
  uint8_t  shields_hit            : 2;  /* 0-2 */
  uint8_t  switch_advantages;
} pvp_pokemon_log_t;


typedef pvp_pokemon_log_t pvp_team_log_t[3];


/**
 * There are a lot of ways to represent a battle; but while one is being
 * calculated we use this structure to track state.
 * <p>
 * You almost certainly would not want to log this entire structure for later
 * analysis. Instead log the players and their actions to construct
 * specific detailed data after the fact.
 */
typedef struct packed {
  pvp_player_t   p1;
  pvp_player_t   p2;
  pvp_action_t   p1_action;  /* Queued/Current action */
  pvp_action_t   p2_action;
  uint32_t       turn;
  //battle_phase_t phase;      /* Not sure if we actually need this */
} pvp_battle_t;


pvp_action_t decide_action( bool decide_p1, pvp_battle_t * battle );

/**
 * Returns <code>true</code> when the battle is over.
 */
bool           eval_turn( pvp_battle_t * battle );
bool           is_battle_over( pvp_battle_t * battle );
bool           is_p1_winner( pvp_battle_t * battle );
pvp_player_t * get_battle_winner( pvp_battle_t * battle );


/* ========================================================================= */

#endif /* battle.h */

/* vim: set filetype=c : */
