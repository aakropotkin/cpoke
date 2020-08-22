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
#include "damage_modifiers.def"


/* ------------------------------------------------------------------------- */

DEFINE_ENUM_WITH_FLAGS( ptype, PT_NONE, BUG, DARK, DRAGON, ELECTRIC, FAIRY,
                        FIGHTING, FIRE, FLYING, GHOST, GRASS, GROUND, ICE,
                        NORMAL, POISON, PSYCHIC, ROCK, STEEL, WATER
                      );

int fprint_ptype_mask( FILE * fd, const char * sep, ptype_mask_t pm );
#define print_ptype_mask( sep, pm ) fprint_ptype_mask( stdout, ( sep ), ( pm ) )


/* ------------------------------------------------------------------------- */

const uint8_t NUM_PTYPES   = WATER + 1; /* 18 types, 19 including `PT_NONE' */

const float WEAK_DMG_MOD   = 1.6;
const float RESIST_DMG_MOD = 0.625;
const float IMMUNE_DMG_MOD = RESIST_DMG_MOD * RESIST_DMG_MOD;


/* ------------------------------------------------------------------------- */

/**
 * Creates a bitmask from a `ptype_t'.
 * `PT_NONE' has the `0' mask, while all others have a `1' bit in the bit
 * matching their integer value. Ex `BUG --> 0b1', `DARK --> 0b10', etc
 * <p>
 * This implementation is essentially <code>1 << ( pt - 1 )</code>, with some
 * extra bitwise magic to handle <code>get_ptype_mask( 0 )</code> which
 * returns 0.
 */
#define get_ptype_mask( pt )  ( (ptype_mask_t) to_mask( ( pt ) ) )


/* ------------------------------------------------------------------------- */

const char * ptype_names[] = {
  "null", "bug", "dark", "dragon", "electric", "fairy", "fighting", "fire",
  "flying", "ghost", "grass", "ground", "ice", "normal", "poison", "psychic",
  "rock", "steel", "water"
};


#define get_ptype_name( pt )  ptype_names[( pt )]


/* ------------------------------------------------------------------------- */

/**
 * While `ptypes_t' would be more convenient, this saves 32 bits.
 *
 * <code>ptype_traits_t</code> isn't super useful because in practice
 * <code>DAMAGE_MODIFIERS</code> should be read to find type interactions.
 */
typedef struct packed {
  ptype_mask_t resistances : 18;
  ptype_mask_t weaknesses  : 18;
  ptype_mask_t immunities  : 18;
} ptype_traits_t; /* 54 bits used, 64 total */

/* This must come after the definition of `ptype_traits_t` */
#include "ptype_traits.def"


/* ------------------------------------------------------------------------- */

#define get_ptype_traits( pt )  ptype_traits[( pt )]


#define pt_resistp( def, atk )                                                \
  ( !! ( ( get_ptype_traits( ( def ) ).resistances ) &                        \
         ( get_ptype_mask( ( atk ) ) ) ) )

#define pt_weakp( def, atk )                                                  \
  ( !! ( ( get_ptype_traits( ( def ) ).weaknesses ) &                         \
         ( get_ptype_mask( ( atk ) ) ) ) )

#define pt_immunep( def, atk )                                                \
  ( !! ( ( get_ptype_traits( ( def ) ).immunities ) &                         \
         ( get_ptype_mask( ( atk ) ) ) ) )


#if 0
/**
 * Used to build DAMAGE_MODIFIERS from scratch.
 */
void
generate_damage_modifier_mat( void ) {
  printf( "{ " );
  for ( ptype_t d1 = BUG; d1 <= WATER; d1++ ) {
    if ( d1 != BUG ) printf( ", " );
    printf( "{ " );
    for ( ptype_t d2 = PT_NONE; d2 <= WATER; d2++ ) {
      if ( d2 != PT_NONE ) printf( ", " );
      printf( "{ " );
      for ( ptype_t a = BUG; a <= WATER; a++ ) {
        if ( a != BUG ) printf( ", " );
        printf( "%f", get_damage_modifier_duo( d1, d2, a ) );
      }
      printf( " }\n  " );
    }
    printf( "}\n" );
  }
  printf( "}\n" );
}


const_fn float
get_damage_modifier_mono( ptype_t def_type, ptype_t atk_type) {
  ptype_mask_t   atk_mask   = get_ptype_mask( atk_type );
  ptype_traits_t def_traits = get_ptype_traits( def_type );
  return ( def_traits.resistances & atk_mask ) ? RESIST_DMG_MOD :
         ( def_traits.weaknesses & atk_mask )  ? WEAK_DMG_MOD   :
         ( def_traits.immunities & atk_mask )  ? IMMUNE_DMG_MOD :
         1.0;
}


const_fn float
get_damage_modifier_duo( ptype_t def_type1,
                         ptype_t def_type2,
                         ptype_t atk_type
                       ) {
  return get_damage_modifier_mono( def_type1, atk_type ) *
         get_damage_modifier_mono( def_type2, atk_type );
}

const_fn float
get_damage_modifier( ptype_mask_t def_types, ptype_t atk_type ) {
  float m = 1.0;
  switch( popcount( def_types ) ) {
  case 2:
    m = get_damage_modifier_mono( highest_bit( def_types ), atk_type );
  case 1:
    m *= get_damage_modifier_mono( lowest_bit( def_types ), atk_type );
  case 0:
    break;
  default:
    fprintf( stderr,
             "'get_damage_modifier' received a 'ptype_mask_t' with more than "
             "two types! Returning '1.0'."
           );
  }
  return m;
}
#endif /* 0 */


const_fn float
get_damage_modifier_mono( ptype_t def_type, ptype_t atk_type ) {
  return DAMAGE_MODIFIERS[def_type - 1][PT_NONE][atk_type - 1];
}

const_fn float
get_damage_modifier_duo( ptype_t def_type1,
                         ptype_t def_type2,
                         ptype_t atk_type
                       ) {
  return DAMAGE_MODIFIERS[def_type1 - 1][def_type2][atk_type - 1];
}

const_fn float
get_damage_modifier( ptype_mask_t def_types, ptype_t atk_type ) {
  switch( popcount( def_types ) ) {
  case 2:
    return DAMAGE_MODIFIERS[highest_bit( def_types ) - 1]
                           [lowest_bit( def_types )]
                           [atk_type - 1];
    break;
  case 1:
    return DAMAGE_MODIFIERS[highest_bit( def_types ) - 1]
                           [PT_NONE]
                           [atk_type - 1];
    break;
  case 0:
    return 1.0;
    break;
  default:
    fprintf( stderr,
             "'get_damage_modifier' received a 'ptype_mask_t' with more than "
             "two types! Returning '1.0'."
             );
    return 1.0;
    break;
  }
}

const_fn float
get_damage_modifier_flags( ptype_flags_t def_types, ptype_t atk_type ) {
  return get_damage_modifier( def_types.mask, atk_type );
}


const float STAB_DMG_MOD = 1.2;


int
fprint_ptype_mask( FILE * fd, const char * sep, ptype_mask_t pm ) {

  bool fst           = true;
  int  printed_chars = 0;

  /* Masking aginst 0 will always fail, so `PT_NONE' is a special case. */
  if ( pm == PT_NONE ) return fprintf( fd, "%s", get_ptype_name( PT_NONE ) );

  for ( int i = 1; i < NUM_PTYPES; i++ ) {
    if ( pm & get_ptype_mask( i ) ) {
      /* Don't print a seperator for the first match. */
      if ( fst ) fst = false;
      else       printed_chars += fprintf( fd, "%s", sep );
      printed_chars += fprintf( fd, "%s", get_ptype_name( i ) );
    }
  }

  return printed_chars;
}



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
