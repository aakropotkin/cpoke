/* -*- mode: c; -*- */

#ifndef _BATTLE_H
#define _BATTLE_H

/* ========================================================================= */

#include "pokemon.h"
#include "pvp_action.h"
#include "util/macros.h"
#include <stdint.h>

struct pvp_player_s;


/* ------------------------------------------------------------------------- */

extern const float   PVP_FAST_BONUS_MOD;
extern const float   PVP_CHARGE_BONUS_MOD;

extern const float   CHARGE_BASE_MOD;
extern const float   CHARGE_NICE_MOD;
extern const float   CHARGE_GREAT_MOD;
extern const float   CHARGE_EXCELLENT_MOD;
#ifndef CHARGE_DEFAULT_MOD
#define CHARGE_DEFAULT_MOD  CHARGE_EXCELLENT_MOD
#endif

extern const float   STAB_BONUS;

extern const uint8_t MAX_CHARGE;
extern const uint8_t CHARGE_RATE;
extern const float   CHARGE_DECAY_RATE;

extern const uint16_t TURN_TIME;     /* ms */
extern const uint16_t CHARGED_TIME;  /* ms */
extern const uint16_t SWITCH_TIME;   /* ms */

extern const uint8_t CHARGED_TURNS;
extern const uint8_t SWITCH_TURNS;


/* ------------------------------------------------------------------------- */

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


/* ------------------------------------------------------------------------- */

/**
 * I'm pretty sure these are only used for UI animations during
 * interactive battles.
 */
typedef enum packed {
  NEUTRAL, COUNTDOWN, SUSPEND_CHARGED, SUSPED_CHARGED_ATTACK,
  SUSPEND_CHARGED_SHIELD, SUSPEND_CHARGED_NO_SHIELD, SUSPEND_SWITCH_P1,
  SUSPEND_SWITCH_P2, ANIMATING, GAME_OVER
} battle_phase_t;


/* ------------------------------------------------------------------------- */

/**
 * This can often be constructed from a battle timeline, and is not always
 * desired in a simulation, so it is not included in <code>battle_t</code>
 */
struct pvp_pokemon_log_s {
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
} packed;

typedef struct pvp_pokemon_log_s  pvp_pokemon_log_t;

typedef pvp_pokemon_log_t  pvp_team_log_t[3];

void pvp_pokemon_log_init( pvp_pokemon_log_t * pokemon_log );
void pvp_pokemon_log_free( pvp_pokemon_log_t * pokemon_log );


/* ------------------------------------------------------------------------- */

/**
 * There are a lot of ways to represent a battle; but while one is being
 * calculated we use this structure to track state.
 * <p>
 * You almost certainly would not want to log this entire structure for later
 * analysis. Instead log the players and their actions to construct
 * specific detailed data after the fact.
 */
struct pvp_battle_s {
  struct pvp_player_s * p1;
  struct pvp_player_s * p2;
  pvp_action_t          p1_action;  /* Queued/Current action */
  pvp_action_t          p2_action;
  uint32_t              turn;
  //battle_phase_t phase;      /* Not sure if we actually need this */
} packed;

typedef struct pvp_battle_s pvp_battle_t;

void pvp_battle_init( pvp_battle_t * battle );
void pvp_battle_free( pvp_battle_t * battle );


/* ------------------------------------------------------------------------- */

pvp_action_t decide_action( bool decide_p1, pvp_battle_t * battle );

/**
 * Returns <code>true</code> when the battle is over.
 */
bool eval_turn( pvp_battle_t * battle );

bool is_battle_over( pvp_battle_t * battle );

bool is_p1_winner( pvp_battle_t * battle );

struct pvp_player_s * get_battle_winner( pvp_battle_t * battle );



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* battle.h */

/* vim: set filetype=c : */
