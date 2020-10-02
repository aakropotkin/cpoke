/* -*- mode: c; -*- */

#ifndef _POKEMON_H
#define _POKEMON_H

/* ========================================================================= */

#include "defs/cpms.h"
#include "moves.h"
#include "pokedex.h"
#include "ptypes.h"
#include "util/macros.h"
#include <math.h>
#include <stdint.h>
#include "store.h"
#include <string.h>
#include "pvp_action.h"


/* ------------------------------------------------------------------------- */

static const float MAX_LEVEL = 40.0;

#define get_cpm_for_level( lvl )  CPMS[( (int) ( ( ( lvl ) - 1 ) * 2 ) )]


/* ------------------------------------------------------------------------- */

struct base_pokemon_s {
  const pdex_mon_t * pdex_mon;
  float              level;
  stats_t            ivs;
};
typedef struct base_pokemon_s  base_pokemon_t;

static const base_pokemon_t BASE_MON_NULL = {
  .pdex_mon = NULL,
  .level    = 1.0,
  .ivs      = { .attack = 0, .stamina = 0, .defense = 0 }
};


/* ------------------------------------------------------------------------- */

/**
 * Fetch a pokemon from a store to create a `base_pokemon_t'
 */
int base_mon_from_store( store_t        * store,
                         uint16_t         dex_num,
                         uint8_t          form_idx,
                         float            level,
                         uint16_t         attack,
                         uint16_t         stamina,
                         uint16_t         defense,
                         base_pokemon_t * mon
                       );


/* ------------------------------------------------------------------------- */

/**
 * Represents an instance of a pokemon with IVs and moves.
 * Used to create PvP/PvE pokemon.
 * A user will likely store their pokemon collection as a roster to import into
 * the simulator.
 */
struct roster_pokemon_s {
  base_pokemon_t * base;
  uint16_t         fast_move_id;
  uint16_t         charged_move_ids[2];
} packed;
typedef struct roster_pokemon_s  roster_pokemon_t;

static const roster_pokemon_t ROSTER_MON_NULL = {
  .base             = NULL,
  .fast_move_id     = 0,
  .charged_move_ids = { 0, 0 }
};

typedef enum { M_CHARGED1, M_CHARGED2, M_FAST } pmove_idx_t;

#define acttomidx( ACT )                                                      \
  ( ( ACT ) == FAST )     ? M_FAST :                                          \
  ( ( ACT ) == CHARGED1 ) ? M_CHARGED1 : M_CHARGED2


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

roster_t * roster_append( roster_t * roster, roster_pokemon_t * mon );


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
  uint8_t            level;
  stats_t            stats;        /* Sum of IVs and Base stats */
  ptype_mask_t       types;
  uint16_t           hp;
  uint8_t            cooldown;     /* # Turns until next action */
  uint8_t            energy;
  buff_state_t       buffs;
  pvp_fast_move_t    fast_move;
  pvp_charged_move_t charged_moves[2];
} packed;
typedef struct pvp_pokemon_s  pvp_pokemon_t;

static const pvp_pokemon_t PVP_MON_NULL = {
  .level         = 0,
  .stats         = { .attack = 0, .stamina = 0, .defense = 0 },
  .types         = PT_NONE_M,
  .hp            = 0,
  .cooldown      = 0,
  .energy        = 0,
  .buffs         = NO_BUFF_STATE,
  .fast_move     = NO_MOVE_PVP_FAST,
  .charged_moves = { NO_MOVE_PVP_CHARGED, NO_MOVE_PVP_CHARGED }
};

void pvp_pokemon_init( pvp_pokemon_t    * mon,
                       roster_pokemon_t * rmon,
                       store_t          * store
                     );


/* ------------------------------------------------------------------------- */

#define _apply_to_pvp_mon_move( MON, IDX, FN )                                \
  ( ( ( IDX ) == M_FAST ) ? FN( ( MON ).fast_move )                           \
                          : FN( ( MON ).charged_moves[( IDX )] ) )

#define get_pvp_mon_move( MON, IDX )                                          \
  _apply_to_pvp_mon_move( ( MON ), ( IDX ), as_base_move )

#define _get_pvp_mon_move_id( MV )   ( MV ).move_id
#define get_pvp_mon_move_id( MON, IDX )                                       \
  _apply_to_pvp_mon_move( ( MON ), ( IDX ), _get_pvp_mon_move_id )

#define _get_pvp_mon_move_power( MV )   ( MV ).power
#define get_pvp_mon_move_power( MON, IDX )                                    \
  _apply_to_pvp_mon_move( ( MON ), ( IDX ), _get_pvp_mon_move_power )


#define _get_pvp_mon_move_type( MV )  ( MV ).type
#define get_pvp_mon_move_type( MON, IDX )                                     \
  _apply_to_pvp_mon_move( ( MON ), ( IDX ), _get_pvp_mon_move_type )

#define _get_pvp_mon_move_energy( MV )  ( MV ).energy
#define get_pvp_mon_move_energy( MON, IDX )                                   \
  _apply_to_pvp_mon_move( ( MON ), ( IDX ), _get_pvp_mon_move_energy )


/* ------------------------------------------------------------------------- */

const_fn uint16_t get_cp_from_stats( stats_t base, stats_t ivs, float level );
const_fn stats_t  get_effective_stats( stats_t base, stats_t ivs, float level );
const_fn uint16_t get_hp_from_stam_lv( uint16_t stam, float lv );

const_fn uint16_t get_pvp_damage( pmove_idx_t     attack_idx,
                                  pvp_pokemon_t * attacker,
                                  pvp_pokemon_t * defender
                                );


/* ------------------------------------------------------------------------- */

static inline bool _is_alive_ptr( pvp_pokemon_t * mon ) { return !! mon->hp; }
static inline bool _is_alive_raw( pvp_pokemon_t mon )   { return !! mon.hp;  }
#define is_alive( MON )  ( _Generic( ( MON ),                                 \
                                     pvp_pokemon_t *: _is_alive_ptr,          \
                                     pvp_pokemon_t:   _is_alive_raw           \
                                   )( MON ) )


/* ------------------------------------------------------------------------- */

/* Tries Sum, then prefers Attack, then Defense, then Stamina */
  static inline int
cmp_stats( stats_t a, stats_t b )
{
  uint32_t sa = a.attack + a.stamina + a.defense;
  uint32_t sb = b.attack + b.stamina + b.defense;
  if ( sa != sb )
    {
      return ( sa > sb ) - ( sa < sb );
    }
  if ( a.attack != b.attack )
    {
      return ( a.attack > b.attack ) - ( a.attack < b.attack );
    }
  if ( a.defense != b.defense )
    {
      return ( a.defense > b.defense ) - ( a.defense < b.defense );
    }
  return ( a.stamina > b.stamina ) - ( a.stamina < b.stamina );
}


/* ------------------------------------------------------------------------- */

bool brute_maximize_ivs( uint16_t  cp_cap,
                         stats_t   base,
                         stats_t * ivs,
                         float   * lv
                       );


/* ------------------------------------------------------------------------- */

/**
 * Aims to have the highest sum of "effective stats".
 * In the rare event of a perfect tie, priorities are:
 *   Attack, Defense, then Stamina
 */
  static inline bool
maximize_ivs( uint16_t cp_cap, stats_t base, stats_t * ivs, float * lv )
{
  return brute_maximize_ivs( cp_cap, base, ivs, lv );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pokemon.h */

/* vim: set filetype=c : */
