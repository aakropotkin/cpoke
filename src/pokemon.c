/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"
#include "moves.h"
#include "pokemon.h"
#include "ptypes.h"
#include "util/macros.h"
#include <stdint.h>

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
  return (stats_t) {
    .attack  = (uint16_t) ( cpm * ( base.attack + ivs.attack ) ),
    .stamina = max( (uint16_t) ( cpm * ( base.stamina + ivs.stamina ) ), 10 ),
    .defense = ( (uint16_t) ( cpm * ( base.defense + ivs.defense ) ) )
  };
}


/* ------------------------------------------------------------------------- */

  const_fn uint16_t
get_pvp_damage( pmove_idx_t     attack_idx,
                pvp_pokemon_t * attacker,
                pvp_pokemon_t * defender
              )
  {
    const uint8_t power = get_pvp_mon_move_power( * attacker, attack_idx );
    const ptype_t mtype = get_pvp_mon_move_type( * attacker, attack_idx );
    const float   stab  = ( get_ptype_mask( mtype ) & attacker->types
                          ) ? STAB_BONUS : 1.0;
    const float   bonus = ( attack_idx == M_FAST ) ? PVP_FAST_BONUS_MOD
                                                   : PVP_CHARGE_BONUS_MOD *
                                                     CHARGE_DEFAULT_MOD;
    const double  atk   = attacker->stats.attack *
                          get_buff_mod( attacker->buffs.atk_buff_lv );
    const double  def   = defender->stats.defense *
                          get_buff_mod( defender->buffs.def_buff_lv );
    const float   teff  = get_damage_modifier( defender->types, mtype );

    return floor( 0.5 * power * atk / def * stab * teff * bonus ) + 1;
  }


/* ------------------------------------------------------------------------- */

  roster_t *
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

  int
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



/* ========================================================================= */

/* vim: set filetype=c : */
