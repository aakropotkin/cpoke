/* -*- mode: c; -*- */

#ifndef _PTYPES_H
#define _PTYPES_H

/* ========================================================================= */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "util/bits.h"
#include "util/macros.h"
#include "util/enumflags.h"
#include "defs/damage_modifiers.h"


/* ------------------------------------------------------------------------- */

static const float WEAK_DMG_MOD   = 1.6;
static const float RESIST_DMG_MOD = 0.625;
static const float IMMUNE_DMG_MOD = RESIST_DMG_MOD * RESIST_DMG_MOD;
static const float STAB_DMG_MOD   = 1.2;


/* ------------------------------------------------------------------------- */

DEFINE_ENUM_WITH_FLAGS( ptype, PT_NONE, BUG, DARK, DRAGON, ELECTRIC, FAIRY,
                        FIGHTING, FIRE, FLYING, GHOST, GRASS, GROUND, ICE,
                        NORMAL, POISON, PSYCHIC, ROCK, STEEL, WATER
                      );

/* 18 types, 19 including `PT_NONE' */
static const uint8_t NUM_PTYPES = WATER + 1;

int fprint_ptype_mask( FILE * fd, const char * sep, ptype_mask_t pm );

#define print_ptype_mask( sep, pm ) fprint_ptype_mask( stdout, ( sep ), ( pm ) )

#define get_ptype_mask( pt )  ( (ptype_mask_t) to_mask( ( pt ) ) )


/* ------------------------------------------------------------------------- */

/**
 * While `ptypes_t' would be more convenient, this saves 32 bits.
 *
 * <code>ptype_traits_t</code> isn't super useful because in practice
 * <code>DAMAGE_MODIFIERS</code> should be read to find type interactions.
 */
struct ptype_traits_s {
  ptype_mask_t resistances : 18;
  ptype_mask_t weaknesses  : 18;
  ptype_mask_t immunities  : 18;
} packed; /* 54 bits used, 64 total */

typedef struct ptype_traits_s  ptype_traits_t;

/* This must come after the definition of `ptype_traits_t' */
#include "defs/ptype_traits.h"


#define get_ptype_traits( pt )  ptype_traits[( pt )]


/* ------------------------------------------------------------------------- */

const_fn float get_damage_modifier_mono( ptype_t def_type, ptype_t atk_type );
const_fn float get_damage_modifier_duo( ptype_t def_type1,
                                        ptype_t def_type2,
                                        ptype_t atk_type
                                      );

const_fn float get_damage_modifier( ptype_mask_t def_types, ptype_t atk_type );

const_fn float
get_damage_modifier_flags( ptype_flags_t def_types, ptype_t atk_type );


/* ------------------------------------------------------------------------- */

  static inline const_fn bool
pt_resistp( ptype_t def, ptype_t atk )
{
  return ( !! ( ( get_ptype_traits( ( def ) ).resistances ) &
                ( get_ptype_mask( ( atk ) ) ) ) );
}

  static inline const_fn bool
pt_weakp( ptype_t def, ptype_t atk )
{
  return ( !! ( ( get_ptype_traits( ( def ) ).weaknesses ) &
                ( get_ptype_mask( ( atk ) ) ) ) );
}

  static inline const_fn bool
pt_immunep( ptype_t def, ptype_t atk )
{
  return ( !! ( ( get_ptype_traits( ( def ) ).immunities ) &
                ( get_ptype_mask( ( atk ) ) ) ) );
}


/* ------------------------------------------------------------------------- */

static const char * PTYPE_NAMES[] = {
  "NONE", "BUG", "DARK", "DRAGON", "ELECTRIC", "FAIRY", "FIGHTING", "FIRE",
  "FLYING", "GHOST", "GRASS", "GROUND", "ICE", "NORMAL", "POISON", "PSYCHIC",
  "ROCK", "STEEL", "WATER"
};

#define get_ptype_name( pt )  PTYPE_NAMES[( pt )]


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* ptypes.h */


/* {
 *   "templateId": "BATTLE_SETTINGS",
 *   "battleSettings": {
 *     "retargetSeconds": 0.5,
 *     "enemyAttackInterval": 1.5,
 *     "attackServerInterval": 5.0,
 *     "roundDurationSeconds": 99.0,
 *     "bonusTimePerAllySeconds": 10.0,
 *     "maximumAttackersPerBattle": 20,
 *     "sameTypeAttackBonusMultiplier": 1.2,
 *     "maximumEnergy": 100,
 *     "energyDeltaPerHealthLost": 0.5,
 *     "dodgeDurationMs": 500,
 *     "minimumPlayerLevel": 5,
 *     "swapDurationMs": 1000,
 *     "dodgeDamageReductionPercent": 0.75,
 *     "minimumRaidPlayerLevel": 5,
 *     "shadowPokemonAttackBonusMultiplier": 1.2,
 *     "shadowPokemonDefenseBonusMultiplier": 0.8333333,
 *     "purifiedPokemonAttackMultiplierVsShadow": 1.0
 *   }
 * }, {
 *   "templateId": "COMBAT_SETTINGS",
 *   "combatSettings": {
 *     "roundDurationSeconds": 270.0,
 *     "turnDurationSeconds": 0.5,
 *     "minigameDurationSeconds": 7.0,
 *     "sameTypeAttackBonusMultiplier": 1.2,
 *     "fastAttackBonusMultiplier": 1.3,
 *     "chargeAttackBonusMultiplier": 1.3,
 *     "defenseBonusMultiplier": 1.0,
 *     "minigameBonusBaseMultiplier": 1.0E-4,
 *     "minigameBonusVariableMultiplier": 1.0,
 *     "maxEnergy": 100,
 *     "defenderMinigameMultiplier": 1.0,
 *     "changePokemonDurationSeconds": 12.0,
 *     "minigameSubmitScoreDurationSeconds": 10.0,
 *     "quickSwapCooldownDurationSeconds": 60.0,
 *     "chargeScoreBase": 0.25,
 *     "chargeScoreNice": 0.5,
 *     "chargeScoreGreat": 0.75,
 *     "chargeScoreExcellent": 1.0,
 *     "shadowPokemonAttackBonusMultiplier": 1.2,
 *     "shadowPokemonDefenseBonusMultiplier": 0.8333333,
 *     "purifiedPokemonAttackMultiplierVsShadow": 1.0
 *   }
 * }, {
 *   "templateId": "COMBAT_STAT_STAGE_SETTINGS",
 *   "combatStatStageSettings": {
 *     "minimumStatStage": -4,
 *     "maximumStatStage": 4,
 *     "attackBuffMultiplier": [0.5, 0.5714286, 0.6666667, 0.8, 1.0, 1.25, 1.5, 1.75, 2.0],
 *     "defenseBuffMultiplier": [0.5, 0.5714286, 0.6666667, 0.8, 1.0, 1.25, 1.5, 1.75, 2.0]
 *   }
 * }
 */

/* vim: set filetype=c : */
