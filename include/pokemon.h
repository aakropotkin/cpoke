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


/* ------------------------------------------------------------------------- */

#define get_cpm_for_level( lvl )  CPMS[( (int) ( ( ( lvl ) - 1 ) * 2 ) )]


/* ------------------------------------------------------------------------- */

struct base_pokemon_s {
  const pdex_mon_t * pdex_mon;
  float              level;
  stats_t            ivs;
};
typedef struct base_pokemon_s  base_pokemon_t;

  static inline int
base_mon_from_store( store_t        * store,
                     uint16_t         dex_num,
                     uint8_t          form_idx,
                     float            level,
                     uint16_t         attack,
                     uint16_t         stamina,
                     uint16_t         defense,
                     base_pokemon_t * mon
                     )
{
  assert( store != NULL );
  assert( mon != NULL );
  assert( !!( store->flags & SF_STANDARD_KEY_M ) );
  const store_key_t key = dex_form_store_key( dex_num, form_idx );
  assert( key.key_type == STORE_NUM );
  assert( key.val_type == STORE_POKEDEX );
  assert( key.data_h0 == dex_num );
  assert( key.data_q2 == form_idx );
  int rsl = 0;
  mon->pdex_mon = NULL;
  mon->level = level;
  mon->ivs.attack = attack;
  mon->ivs.stamina = stamina;
  mon->ivs.defense = defense;
  rsl = store->get( store, key, (void **) & mon->pdex_mon );
  assert( rsl == STORE_SUCCESS );
  assert( mon->pdex_mon != NULL );
  assert( mon->pdex_mon->dex_number == dex_num );
  assert( mon->pdex_mon->form_idx == form_idx );
  return rsl;
}


/* ------------------------------------------------------------------------- */

struct roster_pokemon_s {
  base_pokemon_t * base;
  uint16_t         fast_move_id;
  uint16_t         charged_move_ids[2];
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

  static roster_t *
roster_append( roster_t * roster, roster_pokemon_t * mon )
{
  assert( mon != NULL );
  assert( roster != NULL );
  assert( ( roster->roster_pokemon != NULL ) ||
          ( roster->roster_length == 0 )
        );
  if ( ( roster->roster_pokemon == NULL ) && ( roster->roster_length == 0 ) )
    {
      roster->roster_pokemon =
        (roster_pokemon_t *) malloc( sizeof( roster_pokemon_t ) );
      roster->roster_length = 0;
    }
  else
    {
      roster->roster_pokemon =
        (roster_pokemon_t *) realloc( roster->roster_pokemon,
                                      sizeof( roster_pokemon_t ) *
                                        ( roster->roster_length + 1)
                                    );
    }
  assert( roster->roster_pokemon != NULL );
  memcpy( roster->roster_pokemon + roster->roster_length,
          mon,
          sizeof( roster_pokemon_t )
        );
  roster->roster_length++;
  return roster;
}


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
  uint8_t            stored_energy;
  buff_state_t       buffs;
  pvp_fast_move_t    fast_move;
  pvp_charged_move_t charged_moves[2];
} packed;
typedef struct pvp_pokemon_s  pvp_pokemon_t;

void pvp_pokemon_init( roster_pokemon_t *, pvp_pokemon_t * );


/* ------------------------------------------------------------------------- */

#define _apply_to_pvp_mon_move( mon, idx, fn )                                \
  ( ( ( idx ) == M_FAST ) ? fn( ( mon ).fast_move )                           \
                          : fn( ( mon ).charged_moves[( idx )] ) )

#define get_pvp_mon_move( mon, idx )                                          \
  _apply_to_pvp_mon_move( ( mon ), ( idx ), as_base_move )

#define _get_pvp_mon_move_id( mv )   ( mv ).move_id
#define get_pvp_mon_move_id( mon, idx )                                       \
  _apply_to_pvp_mon_move( ( mon ), ( idx ), _get_pvp_mon_move_id )

#define _get_pvp_mon_move_power( mv )   ( mv ).power
#define get_pvp_mon_move_power( mon, idx )                                    \
  _apply_to_pvp_mon_move( ( mon ), ( idx ), _get_pvp_mon_move_power )


#define _get_pvp_mon_move_type( mv )    ( mv ).type
#define get_pvp_mon_move_type( mon, idx )                                     \
  _apply_to_pvp_mon_move( ( mon ), ( idx ), _get_pvp_mon_move_type )

#define _get_pvp_mon_move_energy( mv )  ( mv ).energy
#define get_pvp_mon_move_energy( mon, idx )                                   \
  _apply_to_pvp_mon_move( ( mon ), ( idx ), _get_pvp_mon_move_energy )


/* ------------------------------------------------------------------------- */

const_fn uint16_t get_cp_from_stats( stats_t base, stats_t ivs, float level );
const_fn stats_t  get_effective_stats( stats_t base, stats_t ivs, float level );

 const_fn uint16_t
get_pvp_damage( pmove_idx_t     attack_idx,
                pvp_pokemon_t * attacker,
                pvp_pokemon_t * defender
              );


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pokemon.h */

/* vim: set filetype=c : */
