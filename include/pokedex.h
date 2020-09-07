/* -*- mode: c; -*- */

#ifndef _POKEDEX_H
#define _POKEDEX_H

/* ========================================================================= */

#include "moves.h"
#include "ptypes.h"
#include <stdint.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */

struct stats_s { uint16_t attack, stamina, defense; } packed;
typedef struct stats_s  stats_t;


/* ------------------------------------------------------------------------- */

struct pdex_mon_s {
  uint16_t     dex_number; /* Highest is Melmetal with 809 */
  char *       name;
  uint16_t     family;     /* Dex # of "base" monster ( lowest non-baby ) */
  uint8_t      form;       /* Usually normal/shadow, but sometimes legacy */
  ptype_mask_t types;
  stats_t      base_stats;

  /* FIXME add moves struct */

} packed;

typedef struct pdex_mon_s  pdex_mon_t;

void pdex_mon_init( pdex_mon_t * mon );
void pdex_mon_free( pdex_mon_t * mon );

  static int
fprint_pdex_mon( FILE * stream, const pdex_mon_t * mon )
{
  fprintf( stream, "(pdex_mon_t) {\n" );
  fprintf( stream, "  dex_number: %d,\n", mon->dex_number );
  fprintf( stream, "  name: \"%s\",\n", mon->name );
  fprintf( stream, "  types: " );
  fprint_ptype_mask( stream, " & ", mon->types );
  fprintf( stream, ",\n" );
  fprintf( stream,
           "  stats: { stamina: %d, attack: %d, defense: %d },\n",
           mon->base_stats.stamina,
           mon->base_stats.attack,
           mon->base_stats.defense
         );
  fprintf( stream, "}\n" );
}

  static int
print_pdex_mon( const pdex_mon_t * mon )
{
  return fprint_pdex_mon( stdout, mon );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pokedex.h */


/*  Example data from GAME_MASTER.json:
 * [{
 *    "templateId": "V0001_POKEMON_BULBASAUR_NORMAL",
 *    "pokemon": {
 *      "uniqueId": "BULBASAUR",
 *      "modelScale": 1.09,
 *      "type1": "POKEMON_TYPE_GRASS",
 *      "type2": "POKEMON_TYPE_POISON",
 *      "camera": {
 *        "diskRadiusM": 0.5723,
 *        "cylinderRadiusM": 0.5,
 *        "cylinderHeightM": 0.763,
 *        "shoulderModeScale": 0.5
 *      },
 *      "encounter": {
 *        "baseCaptureRate": 0.2,
 *        "baseFleeRate": 0.1,
 *        "collisionRadiusM": 0.3815,
 *        "collisionHeightM": 0.654,
 *        "collisionHeadRadiusM": 0.2725,
 *        "movementType": "MOVEMENT_JUMP",
 *        "movementTimerS": 10.0,
 *        "jumpTimeS": 1.15,
 *        "attackTimerS": 29.0,
 *        "attackProbability": 0.1,
 *        "dodgeProbability": 0.15,
 *        "dodgeDurationS": 1.0,
 *        "dodgeDistance": 1.0,
 *        "cameraDistance": 3.75,
 *        "minPokemonActionFrequencyS": 0.2,
 *        "maxPokemonActionFrequencyS": 1.6
 *      },
 *      "stats": {
 *        "baseStamina": 128,
 *        "baseAttack": 118,
 *        "baseDefense": 111
 *      },
 *      "quickMoves": ["VINE_WHIP_FAST", "TACKLE_FAST"],
 *      "cinematicMoves": ["SLUDGE_BOMB", "SEED_BOMB", "POWER_WHIP"],
 *      "animTime": [1.6667, 0.6667, 1.6667, 1.8333, 0.0, 2.1667, 1.4, 1.466667],
 *      "evolution": ["IVYSAUR"],
 *      "evolutionPips": 1,
 *      "pokedexHeightM": 0.7,
 *      "pokedexWeightKg": 6.9,
 *      "heightStdDev": 0.0875,
 *      "weightStdDev": 0.8625,
 *      "familyId": "FAMILY_BULBASAUR",
 *      "candyToEvolve": 25,
 *      "kmBuddyDistance": 3.0,
 *      "modelHeight": 0.7,
 *      "evolutionBranch": [{
 *        "evolution": "IVYSAUR",
 *        "candyCost": 25,
 *        "form": "IVYSAUR_NORMAL"
 *      }],
 *      "modelScaleV2": 0.89,
 *      "form": "BULBASAUR_NORMAL",
 *      "buddyOffsetMale": [0.0, 0.0, 0.0],
 *      "buddyOffsetFemale": [0.0, 0.0, 0.0],
 *      "buddyScale": 19.0,
 *      "thirdMove": {
 *        "stardustToUnlock": 10000,
 *        "candyToUnlock": 25
 *      },
 *      "isTransferable": true,
 *      "isDeployable": true,
 *      "buddyGroupNumber": 2
 *    }
 *},   {
 *    "templateId": "V0001_POKEMON_BULBASAUR_PURIFIED",
 *    "pokemon": {
 *      "uniqueId": "BULBASAUR",
 *      "modelScale": 1.09,
 *      "type1": "POKEMON_TYPE_GRASS",
 *      "type2": "POKEMON_TYPE_POISON",
 *      "camera": {
 *        "diskRadiusM": 0.5723,
 *        "cylinderRadiusM": 0.5,
 *        "cylinderHeightM": 0.763,
 *        "shoulderModeScale": 0.5
 *      },
 *      "encounter": {
 *        "baseCaptureRate": 0.2,
 *        "baseFleeRate": 0.1,
 *        "collisionRadiusM": 0.3815,
 *        "collisionHeightM": 0.654,
 *        "collisionHeadRadiusM": 0.2725,
 *        "movementType": "MOVEMENT_JUMP",
 *        "movementTimerS": 10.0,
 *        "jumpTimeS": 1.15,
 *        "attackTimerS": 29.0,
 *        "attackProbability": 0.1,
 *        "dodgeProbability": 0.15,
 *        "dodgeDurationS": 1.0,
 *        "dodgeDistance": 1.0,
 *        "cameraDistance": 3.75,
 *        "minPokemonActionFrequencyS": 0.2,
 *        "maxPokemonActionFrequencyS": 1.6
 *      },
 *      "stats": {
 *        "baseStamina": 128,
 *        "baseAttack": 118,
 *        "baseDefense": 111
 *      },
 *      "quickMoves": ["VINE_WHIP_FAST", "TACKLE_FAST"],
 *      "cinematicMoves": ["SLUDGE_BOMB", "SEED_BOMB", "POWER_WHIP"],
 *      "animTime": [1.6667, 0.6667, 1.6667, 1.8333, 0.0, 2.1667, 1.4, 1.466667],
 *      "evolution": ["IVYSAUR"],
 *      "evolutionPips": 1,
 *      "pokedexHeightM": 0.7,
 *      "pokedexWeightKg": 6.9,
 *      "heightStdDev": 0.0875,
 *      "weightStdDev": 0.8625,
 *      "familyId": "FAMILY_BULBASAUR",
 *      "candyToEvolve": 25,
 *      "kmBuddyDistance": 3.0,
 *      "modelHeight": 0.7,
 *      "evolutionBranch": [{
 *        "evolution": "IVYSAUR",
 *        "candyCost": 22,
 *        "form": "IVYSAUR_PURIFIED"
 *      }],
 *      "modelScaleV2": 0.89,
 *      "form": "BULBASAUR_PURIFIED",
 *      "buddyOffsetMale": [0.0, 0.0, 0.0],
 *      "buddyOffsetFemale": [0.0, 0.0, 0.0],
 *      "buddyScale": 19.0,
 *      "thirdMove": {
 *        "stardustToUnlock": 8000,
 *        "candyToUnlock": 20
 *      },
 *      "isTransferable": true,
 *      "isDeployable": true,
 *      "buddyGroupNumber": 2
 *    }
 *},   {
 *    "templateId": "V0001_POKEMON_BULBASAUR_SHADOW",
 *    "pokemon": {
 *      "uniqueId": "BULBASAUR",
 *      "modelScale": 1.09,
 *      "type1": "POKEMON_TYPE_GRASS",
 *      "type2": "POKEMON_TYPE_POISON",
 *      "camera": {
 *        "diskRadiusM": 0.5723,
 *        "cylinderRadiusM": 0.5,
 *        "cylinderHeightM": 0.763,
 *        "shoulderModeScale": 0.5
 *      },
 *      "encounter": {
 *        "baseCaptureRate": 0.05,
 *        "baseFleeRate": 0.1,
 *        "collisionRadiusM": 0.3815,
 *        "collisionHeightM": 0.654,
 *        "collisionHeadRadiusM": 0.2725,
 *        "movementType": "MOVEMENT_JUMP",
 *        "movementTimerS": 10.0,
 *        "jumpTimeS": 1.15,
 *        "attackTimerS": 29.0,
 *        "attackProbability": 0.7,
 *        "dodgeProbability": 0.2,
 *        "dodgeDurationS": 1.0,
 *        "dodgeDistance": 1.0,
 *        "cameraDistance": 3.75,
 *        "minPokemonActionFrequencyS": 0.2,
 *        "maxPokemonActionFrequencyS": 1.6
 *      },
 *      "stats": {
 *        "baseStamina": 128,
 *        "baseAttack": 118,
 *        "baseDefense": 111
 *      },
 *      "quickMoves": ["VINE_WHIP_FAST", "TACKLE_FAST"],
 *      "cinematicMoves": ["SLUDGE_BOMB", "SEED_BOMB", "POWER_WHIP"],
 *      "animTime": [1.6667, 0.6667, 1.6667, 1.8333, 0.0, 2.1667, 1.4, 1.466667],
 *      "evolution": ["IVYSAUR"],
 *      "evolutionPips": 1,
 *      "pokedexHeightM": 0.7,
 *      "pokedexWeightKg": 6.9,
 *      "heightStdDev": 0.0875,
 *      "weightStdDev": 0.8625,
 *      "familyId": "FAMILY_BULBASAUR",
 *      "candyToEvolve": 25,
 *      "kmBuddyDistance": 3.0,
 *      "modelHeight": 0.7,
 *      "evolutionBranch": [{
 *        "evolution": "IVYSAUR",
 *        "candyCost": 25,
 *        "form": "IVYSAUR_SHADOW"
 *      }],
 *      "modelScaleV2": 0.89,
 *      "form": "BULBASAUR_SHADOW",
 *      "buddyOffsetMale": [0.0, 0.0, 0.0],
 *      "buddyOffsetFemale": [0.0, 0.0, 0.0],
 *      "buddyScale": 19.0,
 *      "thirdMove": {
 *        "stardustToUnlock": 12000,
 *        "candyToUnlock": 30
 *      },
 *      "isTransferable": true,
 *      "isDeployable": true,
 *      "shadow": {
 *        "purificationStardustNeeded": 3000,
 *        "purificationCandyNeeded": 3,
 *        "purifiedChargeMove": "RETURN",
 *        "shadowChargeMove": "FRUSTRATION"
 *      },
 *      "buddyGroupNumber": 2
 *    }
 *  }]
 */


/* vim: set filetype=c : */
