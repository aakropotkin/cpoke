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

/**
 * PvP settings were collected manually from `GAME_MASTER.json' entry with
 * `templateId' = "COMBAT_SETTINGS"
 *
 *    "blockedFlyoutDurationTurns": 5,
 *    "changePokemonDurationSeconds": 12.0,
 *
 *    "chargeAttackBonusMultiplier": 1.3,
 *    "chargeScoreBase": 0.25,
 *    "chargeScoreExcellent": 1.0,
 *    "chargeScoreGreat": 0.75,
 *    "chargeScoreNice": 0.5,
 *    "defenderMinigameMultiplier": 1.0,
 *    "defenseBonusMultiplier": 1.0,
 *    "fastAttackBonusMultiplier": 1.3,
 *    "maxEnergy": 100,
 *    "minigameBonusBaseMultiplier": 1.0E-4,
 *    "minigameBonusVariableMultiplier": 1.0,
 *
 *    "minigameDurationSeconds": 7.0,
 *    "minigameSubmitScoreDurationSeconds": 10.0,
 *
 *    "normalEffectiveFlyoutDurationTurns": 5,
 *    "notVeryEffectiveFlyoutDurationTurns": 5,
 *
 *    "purifiedPokemonAttackMultiplierVsShadow": 1.0,
 *
 *    "quickSwapCooldownDurationSeconds": 60.0,
 *    "roundDurationSeconds": 270.0,
 *
 *    "sameTypeAttackBonusMultiplier": 1.2,
 *    "shadowPokemonAttackBonusMultiplier": 1.2,
 *    "shadowPokemonDefenseBonusMultiplier": 0.8333333,
 *
 *    "superEffectiveFlyoutDurationTurns": 5,
 *    "turnDurationSeconds": 0.5,
 */

static const float   PVP_FAST_BONUS_MOD   = 1.3;
static const float   PVP_CHARGE_BONUS_MOD = 1.3;

/**
 * There is still argument about whether there is a sliding scale "between"
 * these levels, this isn't super relevant to the simulator though.
 */
static const float   CHARGE_BASE_MOD      = 0.25;
static const float   CHARGE_NICE_MOD      = 0.5;
static const float   CHARGE_GREAT_MOD     = 0.75;
static const float   CHARGE_EXCELLENT_MOD = 1.0;
#ifndef CHARGE_DEFAULT_MOD
/* Assumes that players hit "Excellent" in all Charged Move Minigames */
#define CHARGE_DEFAULT_MOD  CHARGE_EXCELLENT_MOD
#endif
static const float   STAB_BONUS = 1.25;
static const float   SHADOW_ATTACK_MOD = 1.2;
static const float   SHADOW_DEFENSE_MOD = 0.8333333;

/* Energy cap */
static const uint8_t MAX_CHARGE = 100;
/* I have no idea what these two are */
static const uint8_t CHARGE_RATE       = 20;
static const float   CHARGE_DECAY_RATE = 0.5;

/** Time in ms of various battle phases/actions */
static const uint32_t BATTLE_TIME = 270 * 1000;
static const uint16_t TURN_TIME   = 500;
/* Time for Charged Attack Animation */
static const uint16_t CHARGED_ANIM_TIME = 4000;
/* Time for Charged Attack Minigame */
static const uint16_t CHARGED_MG_TIME = 10000;
//static const uint16_t CHARGED_MG_RESULT_TIME =
/* Time for switch animation */
static const uint16_t SWITCH_TIME    = 13000;
/* Timeout to select next pokemon after a faint */
static const uint16_t SWITCH_TIMEOUT = 12 * 1000;

static const uint8_t CHARGED_TURNS        = 8;
static const uint8_t SWITCH_TURNS         = 26;


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
 * Some of these are only relevant for interactive battles.
 * Simulated battles only use `NEUTRAL', `SUSPEND_CHARGED' when determining
 * if the defender will shield, and `SUSPEND_SWITCH_TIE' when both pokemon
 * faint and AIs may want to play chicken for lead advantage.
 * <p>
 * During simulation the battle handler only requests actions from one player
 * in suspend states.
 */
typedef enum packed {
  COUNTDOWN,                  /* Waiting for a battle to start */
  NEUTRAL,                    /* Normal battle phase */
  SUSPEND_CHARGED,            /* Minigame in progress */
  SUSPEND_CHARGED_ATTACK,     /* Attack animation playing */
  SUSPEND_CHARGED_SHIELD,     /* Shield used, waiting for attack */
  SUSPEND_CHARGED_NO_SHIELD,  /* Skipped shield, waiting for attack */
  SUSPEND_SWITCH_P1,          /* P1 fainted, waiting to pick switch */
  SUSPEND_SWITCH_P2,          /* P2 fainted, waiting to pick switch */
  SUSPEND_SWITCH_TIE,         /* Both fainted, play chicken */
  GAME_OVER
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
  battle_phase_t        phase;
  cmp_rule_t            cmp_rule;
  uint8_t               cmp_alt_state : 1;
} packed;
typedef struct pvp_battle_s pvp_battle_t;

static const pvp_battle_t PVP_BATTLE_NULL = {
  .p1            = NULL,
  .p2            = NULL,
  .p1_action     = ACT_NULL,
  .p2_action     = ACT_NULL,
  .turn          = 0,
  .phase         = COUNTDOWN,
  .cmp_rule      = CMP_IDEAL,
  .cmp_alt_state = false
};


/* ------------------------------------------------------------------------- */

void pvp_battle_init( pvp_battle_t * battle );
void pvp_battle_free( pvp_battle_t * battle );


/* ------------------------------------------------------------------------- */

pvp_action_t decide_action( bool decide_p1, pvp_battle_t * battle );

uint32_t     simulate_battle( pvp_battle_t * battle );

/**
 * Returns <code>true</code> when the battle is over.
 */
bool eval_turn( pvp_battle_t * battle );

bool is_battle_over( pvp_battle_t * battle );

bool is_p1_winner( pvp_battle_t * battle );

struct pvp_player_s * get_battle_winner( pvp_battle_t * battle );

/**
 * A helper for AI functions/battle handler to restrict available actions
 * based on things like stored energy, hp, and battle phase.
 * For example it is not valid to use a charged move without the available
 * energy, or to switch when there are no available pokemon.
 */
pvp_action_mask_t valid_actions( bool decide_p1, pvp_battle_t * battle );
bool              is_valid_action( bool           decide_p1,
                                   pvp_action_t   action,
                                   pvp_battle_t * battle
                                 );


bool is_p1_cmp_winner( pvp_battle_t * battle );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* battle.h */

/* vim: set filetype=c : */
