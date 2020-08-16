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

#if 0
/**
 * PvPoke's CPMs calculate half levels from scratch every time.
 * We use their calculator to cache the half level results for speed.
 * This snippet has been left so that it can be referenced in the future.
 */
const double CPMS_full[] = {
  0.093999997, 0.16639787, 0.21573247, 0.25572005, 0.29024988,  /*  1-5  */
  0.321087600, 0.34921268, 0.37523559, 0.39956728, 0.42250001,  /*  6-10 */
  0.443107550, 0.46279839, 0.48168495, 0.49985844, 0.51739395,  /* 11-15 */
  0.534354330, 0.55079269, 0.56675452, 0.58227891, 0.59740001,  /* 16-20 */
  0.612157290, 0.62656713, 0.64065295, 0.65443563, 0.66793400,  /* 21-25 */
  0.681164920, 0.69414365, 0.70688421, 0.71939909, 0.73170000,  /* 26-30 */
  0.737769480, 0.74378943, 0.74976104, 0.75568551, 0.76156384,  /* 31-35 */
  0.767397170, 0.77318650, 0.77893275, 0.78463697, 0.79030001,  /* 36-40 */
  0.795300010, 0.80030000, 0.80530000, 0.81029999, 0.81529999   /* 41-45 */
};

const_fn double
calculate_cpm_from_full_levels( float level ) {
  return ( ( fmod( level, 1 ) == 0 )
           ? CPMS_full[( (int) level - 1 )]
           : sqrt( ( pow( CPMS_full[( (int) floor( level ) - 1 )], 2 )
                     + pow( CPMS_full[( (int) ceil( level ) - 1 )], 2 )
                   ) / 2.0
                 )
         );
}
#endif

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


typedef struct {
  pdex_mon_t;
  char *      custom_name;
  float       level;
  stats_t     ivs;
} base_pokemon_t;


typedef struct {
  base_pokemon_t;
  base_move_t fast_move;
  base_move_t charged_moves[2];
} roster_pokemon_t;


typedef struct {
  base_pokemon_t;
  uint8_t              hp;
  uint16_t             cooldown;
  buff_state_t         buffs;
  pvp_fast_move_t    * fast_move;
  pvp_charged_move_t * charged_moves[2];
} pvp_pokemon_t;


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
