/* -*- mode: c; -*- */

#ifndef _POKEMON_H
#define _POKEMON_H

/* ========================================================================= */

#include "cpms.def"
#include "moves.h"
#include "pokedex.h"
#include "ptypes.h"
#include "util/macros.h"
#include <math.h>
#include <stdint.h>


/* ------------------------------------------------------------------------- */

#define get_cpm_for_level( lvl )  CPMS[( (int) ( ( ( lvl ) - 1 ) * 2 ) )]


/* ------------------------------------------------------------------------- */

struct base_pokemon_s {
  pdex_mon_t;
  float       level;
  stats_t     ivs;
} packed;

typedef struct base_pokemon_s  base_pokemon_t;


/* ------------------------------------------------------------------------- */

struct roster_pokemon_s {
  base_pokemon_t;
  base_move_t fast_move;
  base_move_t charged_moves[2];
} packed;

typedef struct roster_pokemon_s  roster_pokemon_t;


/* ------------------------------------------------------------------------- */

/**
 * A roster is essentially a players full collection of pokemon.
 * In a Silph Cup format this might only have 6 members; but for GBL it could
 * include all possible pokemon that they have in their bag.
 */
struct roster_s {
  roster_pokemon_t * roster_pokemon;
  size_t             roster_length;
};

typedef struct roster_s  roster_t;


/* ------------------------------------------------------------------------- */

typedef struct packed {
  base_pokemon_t;
  uint8_t              hp;
  uint8_t              cooldown;          /* # Turns until next action */
  buff_state_t         buffs;
  pvp_fast_move_t    * fast_move;
  pvp_charged_move_t * charged_moves[2];
} pvp_pokemon_t;


/* ------------------------------------------------------------------------- */

/**
 * A "team" is explicitly 3 pokemon which are being used in PvP battle.
 */
typedef pvp_pokemon_t  pvp_team_t[3];


/* ------------------------------------------------------------------------- */

  const_fn uint16_t
get_cp_from_stats( stats_t base, stats_t ivs, float level )
{
  return max( floor( 0.1 * pow( get_cpm_for_level( level ), 2 ) *
                     ( base.attack + ivs.attack ) *
                     sqrt( ( base.defense + ivs.defense ) *
                           ( base.stamina + ivs.stamina )
                         )
                   ),
              10
            );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pokemon.h */

/* vim: set filetype=c : */
