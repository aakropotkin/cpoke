/* -*- mode: c; -*- */

#ifndef _POKEMON_H
#define _POKEMON_H

/* ========================================================================= */

#include <stdint.h>
#include "ptypes.h"
#include "pokedex.h"
#include "moves.h"
#include <math.h>
#include "util/macros.h"


/* ------------------------------------------------------------------------- */

const double CPMS[] = {
  0.09399997, 0.13513743, 0.16639787, 0.19265091, 0.21573247, 0.23657266,
  0.25572005, 0.27353038, 0.29024988, 0.30605738, 0.32108760, 0.33544503,
  0.34921268, 0.36245775, 0.37523559, 0.38759241, 0.39956728, 0.41119355,
  0.42250001, 0.43292641, 0.44310755, 0.45305996, 0.46279839, 0.47233608,
  0.48168495, 0.49085581, 0.49985844, 0.50870176, 0.51739395, 0.52594251,
  0.53435433, 0.54263576, 0.55079269, 0.55883060, 0.56675452, 0.57456915,
  0.58227891, 0.58988791, 0.59740001, 0.60482366, 0.61215729, 0.61940412,
  0.62656713, 0.63364918, 0.64065295, 0.64758096, 0.65443563, 0.66121926,
  0.66793400, 0.67458190, 0.68116492, 0.68768490, 0.69414365, 0.70054289,
  0.70688421, 0.71316910, 0.71939909, 0.72557561, 0.73170000, 0.73474101,
  0.73776948, 0.74078557, 0.74378943, 0.74678120, 0.74976104, 0.75272910,
  0.75568551, 0.75863037, 0.76156384, 0.76448607, 0.76739717, 0.77029727,
  0.77318650, 0.77606494, 0.77893275, 0.78179006, 0.78463697, 0.78747358,
  0.79030001, 0.79280395, 0.79530001, 0.79780392, 0.80030000, 0.80280389,
  0.80530000, 0.80780386, 0.81029999, 0.81280383, 0.81529999
};

#define get_cpm_for_level( lvl )  CPMS[( (int) ( ( ( lvl ) - 1 ) * 2 ) )]


typedef struct packed {
  pdex_mon_t;
  float       level;
  stats_t     ivs;
} base_pokemon_t;


typedef struct packed {
  base_pokemon_t;
  base_move_t fast_move;
  base_move_t charged_moves[2];
} roster_pokemon_t;


/**
 * A roster is essentially a players full collection of pokemon.
 * In a Silph Cup format this might only have 6 members; but for GBL it could
 * include all possible pokemon that they have in their bag.
 */
typedef struct packed {
  roster_pokemon_t * roster_pokemon;
  size_t             roster_length;
} roster_t;


typedef struct packed {
  base_pokemon_t;
  uint8_t              hp;
  uint8_t              cooldown;          /* # Turns until next action */
  buff_state_t         buffs;
  pvp_fast_move_t    * fast_move;         /* TODO: Hold value for GPGPU */
  pvp_charged_move_t * charged_moves[2];  /* TODO: Hold value for GPGPU */
} pvp_pokemon_t;


/**
 * A "team" is explicitly 3 pokemon which are being used in PvP battle.
 */
//typedef struct { pvp_pokemon_t pokemon[3]; } pvp_team_t;
typedef pvp_pokemon_t pvp_team_t[3];


const_fn uint16_t
get_cp_from_stats( stats_t base, stats_t ivs, float level ) {
  return max( floor( 0.1 * pow( get_cpm_for_level( level ), 2 ) *
                     ( base.attack + ivs.attack ) *
                     sqrt( ( base.defense + ivs.defense ) *
                           ( base.stamina + ivs.stamina )
                         )
                   ),
              10
            );
}


/* ========================================================================= */

#endif /* pokemon.h */

/* vim: set filetype=c : */
