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
    .stamina = max( (uint16_t) cpm * ( base.defense + ivs.defense ), 10 ),
    .defense = ( (uint16_t) cpm * ( base.defense + ivs.defense ) )
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

  void
pdex_mon_init( pdex_mon_t * mon )
{
  assert( mon != NULL );
  mon->name             = NULL;
  mon->dex_number       = 0;
  mon->form_name        = NULL;
  mon->fast_move_ids    = NULL;
  mon->charged_move_ids = NULL;
  mon->next_form        = NULL;
  mon->hkey             = 0;
}

  void
pdex_mon_free( pdex_mon_t * mon )
{
  if ( mon == NULL ) return;
  if ( mon->next_form != NULL ) pdex_mon_free( mon->next_form );
  free( mon->name );
  free( mon->form_name );
  free( mon->fast_move_ids );
  free( mon->charged_move_ids );
  free( mon );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
