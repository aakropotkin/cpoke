/* -*- mode: c; -*- */

#ifndef _PVPOKE_AI_H
#define _PVPOKE_AI_H

/* ========================================================================= */

#include <stdint.h>
#include <stdbool.h>
#include "pvp_action.h"
#include "ai/ai.h"

struct pvp_battle_s;


/* ------------------------------------------------------------------------- */

/**
 * NOTE: Okay so down the line we want the AI decision engine to be modular.
 * In <code>battle.h</code> the function <code>decide_action</code> should
 * allow completely different AI systems to run.
 * This implementation here is pulled almost directly from PvPoke essentially
 * serves as a proof of concept.
 * This type of AI design might be useful for GPGPU because it is simple and
 * it's rules can be encoded tightly; but something like an Expert System or
 * an AI Agent are probably more accurate.
 */
typedef enum packed {
  USER_CONTROLLED, NOVICE, RIVAL, ELITE, CHAMPION
} pvpoke_ai_level_t;

typedef pvpoke_ai_level_t  pvpoke_ai_aux_t;


/* ------------------------------------------------------------------------- */

/* transparent attribute is applied to `strat_flags_t' */
DEFINE_ENUM_WITH_FLAGS( strat, DEFAULT_STRAT, SHIELD_STRAT, SWITCH_BASIC,
                        SWITCH_FARM, SWITCH_ADVANCED, FARM_ENERGY, OVERFARM,
                        BAIT_SHIELDS, WAIT_CLOCK, PRESERVE_SWITCH_ADVANTAGE,
                        ADVANCED_SHIELDING, BAD_DECISION_PROTECTION,
                        SACRIFICIAL_SWAP
                      ) transparent;

const uint8_t NUM_STRATS = SACRIFICIAL_SWAP + 1;

#define get_strat_mask( strat )  ( (strat_mask_t) to_mask( ( strat ) ) )


/* ------------------------------------------------------------------------- */

struct pvpoke_ai_rules_s {
  bool          two_charged_moves     : 1;
  uint16_t      iv_combo_range        : 15;  /*   200-3000  */
  uint8_t       energy_guess_accuracy : 4;   /*    0-15     */
  uint8_t       reaction_time         : 4;   /* 0, 4, 8, 12 */
  uint8_t       move_guess_certainty  : 2;   /*    0-3      */
  strat_flags_t strategies;
} packed;

typedef struct pvpoke_ai_rules_s  pvpoke_ai_rules_t;


/* ------------------------------------------------------------------------- */

const pvpoke_ai_rules_t AI_ARCHETYPES[] = {
  /* User Controlled */ {
    .two_charged_moves     = true,
    .iv_combo_range        = 0,
    .energy_guess_accuracy = 0,
    .reaction_time         = 0,
    .move_guess_certainty  = 0,
    .strategies            = { DEFAULT_STRAT_M }
  }, /* Novice */ {
    .two_charged_moves     = false,
    .iv_combo_range        = 3000,
    .energy_guess_accuracy = 15,
    .reaction_time         = 12,
    .move_guess_certainty  = 0,
    .strategies            = { SHIELD_STRAT_M }
  }, /* Rival */ {
    .two_charged_moves     = true,
    .iv_combo_range        = 2000,
    .energy_guess_accuracy = 10,
    .reaction_time         = 8,
    .move_guess_certainty  = 1,
    .strategies            = { SHIELD_STRAT_M | SWITCH_BASIC_M }
  }, /* Elite */ {
    .two_charged_moves     = true,
    .iv_combo_range        = 1000,
    .energy_guess_accuracy = 5,
    .reaction_time         = 4,
    .move_guess_certainty  = 2,
    .strategies            = { SHIELD_STRAT_M | SWITCH_BASIC_M | FARM_ENERGY_M |
                               BAIT_SHIELDS_M }
  }, /* Champion */ {
    .two_charged_moves     = true,
    .iv_combo_range        = 200,
    .energy_guess_accuracy = 0,
    .reaction_time         = 0,
    .move_guess_certainty  = 3,
    .strategies            = { SHIELD_STRAT_M | SWITCH_BASIC_M | FARM_ENERGY_M |
                               OVERFARM_M | BAIT_SHIELDS_M | WAIT_CLOCK_M |
                               PRESERVE_SWITCH_ADVANTAGE_M |
                               ADVANCED_SHIELDING_M |
                               BAD_DECISION_PROTECTION_M | SACRIFICIAL_SWAP_M }
  }
};


/* ------------------------------------------------------------------------- */

typedef enum packed {
  BOTH_BAIT, NEITHER_BAIT, NO_BAIT, FARM
} stype_t;


struct scenario_s {
  stype_t    name;
  /* battler_t  opponent; */
  uint32_t * matchups;
  uint32_t   average;
  uint8_t    min_shields;
} packed;

typedef struct scenario_s  scenario_t;


/* ------------------------------------------------------------------------- */

struct roster_performance_s {
  roster_pokemon_t * pokemon;
  scenario_t       * scenarios;
  uint32_t           average;
} packed;

typedef struct roster_performance_s  roster_performance_t;

/* ------------------------------------------------------------------------- */

/**
 * These decisions help AI pick teams from a roster.
 */
typedef enum packed {
  BASIC, BEST, COUNTER, UNBALANCED, SAME_TEAM, SAME_TEAM_DIFFERENT_LEAD,
  COUNTER_LAST_LEAD
} dtype_t;

struct decision_option_s {
  dtype_t  name;
  uint32_t weight;
} packed;

typedef struct decision_option_s  decision_option_t;



/* ------------------------------------------------------------------------- */

ai_status_t pvpoke_ai_select_team( roster_t   * our_roster,
                                   roster_t   * their_roser,
                                   pvp_team_t * team,
                                   void       *
                                 );

ai_status_t pvpoke_ai_decide_action( bool                  decide_p1,
                                     struct pvp_battle_s * battle,
                                     pvp_action_t        * choice
                                   );

ai_status_t pvpoke_ai_init( ai_t * ai );
ai_status_t pvpoke_ai_free( ai_t * ai );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pvpoke_ai.h */

/* vim: set filetype=c : */
