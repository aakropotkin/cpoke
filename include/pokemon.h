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
  pdex_mon_t * pdex_mon;
  float        level;
  stats_t      ivs;
} packed;

typedef struct base_pokemon_s  base_pokemon_t;


/* ------------------------------------------------------------------------- */

struct roster_pokemon_s {
  base_pokemon_t * base;
  uint16_t         fast_move_id;
  uint16_t         charged_moves_ids[2];
} packed;

typedef struct roster_pokemon_s  roster_pokemon_t;

typedef enum { M_CHARGED1, M_CHARGED2, M_FAST } pmove_idx_t;


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

/**
 * Okay, in a lot of cases we just store pointers to "inherited" structures,
 * however here we actually store those values to avoid dereferencing
 * chains of pointers.
 * <p>
 * Additionally we drop a lot of data that is not necessary for the
 * simulator. Notably we don't even store a Dex # or IVs, so it is up to the
 * simulation runner to manage logging that info.
 */
struct pvp_pokemon_s {
  stats_t            stats;        /* From LV, IVs, and Base stats */
  ptype_mask_t       types;
  uint16_t           hp;
  uint8_t            cooldown;     /* # Turns until next action */
  buff_state_t       buffs;
  pvp_fast_move_t    fast_move;
  pvp_charged_move_t charged_moves[2];
} packed;

typedef struct pvp_pokemon_s  pvp_pokemon_t;

void pvp_pokemon_init( roster_pokemon_t *, pvp_pokemon_t * )


/* ------------------------------------------------------------------------- */

/**
 * A "team" is explicitly 3 pokemon which are being used in PvP battle.
 */
typedef pvp_pokemon_t  pvp_team_t[3];


/* ------------------------------------------------------------------------- */

  const_fn uint16_t
get_cp_from_stats( stats_t base, stats_t ivs, float level )
{
  return max( floor( 0.1                                  *
                     pow( get_cpm_for_level( level ), 2 ) *
                     ( base.attack + ivs.attack )         *
                     sqrt( ( base.defense + ivs.defense ) *
                           ( base.stamina + ivs.stamina )
                         )
                   ),
              10
            );
}


/* ------------------------------------------------------------------------- */

  const_fn stats_t
get_effective_stats( stats_t base, stats_t ivs, float level )
{
  const float cpm = get_cpm_for_level( level );
  return { .attack = (uint16_t) cpm * ( base.attack + ivs.attack ),
           .defense = (uint16_6) cpm * ( base.defense + ivs.defense ),
           .stamina = max( cpm * ( base.defense + ivs.defense ), 10 )
         };
}


/* ------------------------------------------------------------------------- */

 const_fn uint16_t
get_pvp_damage( pmove_idx_t     attack_idx,
                pvp_pokemon_t * attacker,
                pvp_pokemon_t * defender
              )
{
  reutrn 0;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pokemon.h */

/* vim: set filetype=c : */
