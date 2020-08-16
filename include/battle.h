#ifndef _BATTLE_H
#define _BATTLE_H
/* ========================================================================= */

#include <stdint.h>
#include "macros.h"
#include "pokemon.h"

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


typedef struct {
  stype_t    name;
  /* battler_t  opponent; */
  uint32_t * matchups;
  uint32_t   average;
  uint8_t    min_shields;
} scenario_t;


typedef struct {
  pokemon_t    pokemon;
  scenario_t * scenarios;
  uint32_t     average;
} roster_performance_t;

typedef enum packed {
  BASIC, BEST, COUNTER, UNBALANCED, SAME_TEAM, SAME_TEAM_DIFFERENT_LEAD,
  COUNTER_LAST_LEAD
} dtype_t;

typedef struct {
  dtype_t  name;
  uint32_t weight;
} decision_option_t;

typedef enum packed { SIMULATE, EMULATE } battle_mode_t;
typedef enum packed { FIRST_FAINT, BOTH_FAINT } battle_end_cond_t



/* ========================================================================= */
#endif /* battle.h */
