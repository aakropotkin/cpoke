/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"
#include "moves.h"
#include "pokemon.h"
#include "ptypes.h"
#include "util/macros.h"
#include <stdint.h>
#include "store.h"
#include <math.h>


/* ------------------------------------------------------------------------- */

  void
pvp_pokemon_init( pvp_pokemon_t    * mon,
                  roster_pokemon_t * rmon,
                  store_t          * store
                )
{
  assert( mon != NULL );
  assert( rmon != NULL );
  assert( store != NULL );

  int rsl = 0;

  mon->level = rmon->base->level;

  mon->stats.attack  = rmon->base->pdex_mon->base_stats.attack +
                       rmon->base->ivs.attack;
  mon->stats.stamina = rmon->base->pdex_mon->base_stats.stamina +
                       rmon->base->ivs.stamina;
  mon->stats.defense = rmon->base->pdex_mon->base_stats.defense +
                       rmon->base->ivs.defense;

  /* Apply Shadow stat modifier */
  if ( !!( rmon->base->pdex_mon->tags & TAG_SHADOW_M ) )
    {
      mon->stats.attack  *= SHADOW_ATTACK_MOD;
      mon->stats.defense *= SHADOW_DEFENSE_MOD;
    }

  mon->types     = rmon->base->pdex_mon->types;
  mon->hp        = get_hp_from_stam_lv( mon->stats.stamina, mon->level );
  mon->cooldown  = 0;
  mon->energy    = 0;
  mon->buffs     = NO_BUFF_STATE;

  rsl = pvp_fast_move_from_store( store, rmon->fast_move_id, & mon->fast_move );
  assert( rsl == STORE_SUCCESS );

  rsl = pvp_charged_move_from_store( store,
                                     rmon->charged_move_ids[0],
                                     & mon->charged_moves[0]
                                   );
  assert( rsl == STORE_SUCCESS );

  if ( rmon->charged_move_ids[1] != 0 )
    {
      rsl = pvp_charged_move_from_store( store,
                                         rmon->charged_move_ids[1],
                                         & mon->charged_moves[1]
                                       );
      assert( rsl == STORE_SUCCESS );
    }
}


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

  const_fn uint16_t
get_hp_from_stam_lv( uint16_t stam, float lv )
{
  return max( (uint16_t) ( get_cpm_for_level( lv ) * stam ), 10 );
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

  uint16_t
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
    const float atk  = attacker->stats.attack               *
                       get_cpm_for_level( attacker->level ) *
                       get_buff_mod( attacker->buffs.atk_buff_lv );
    const float def  = defender->stats.defense              *
                       get_cpm_for_level( defender->level ) *
                       get_buff_mod( defender->buffs.def_buff_lv );
    const float teff = get_damage_modifier( defender->types, mtype );

    return floor(  power * stab * ( atk / def ) * teff * 0.5 * bonus ) + 1;
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

  bool
brute_maximize_ivs( uint16_t cp_cap, stats_t base, stats_t * ivs, float * lv )
{
  stats_t  eff_best   = { 0, 0, 0 };
  stats_t  peff       = { 0, 0, 0 };
  stats_t  pivs       = { 0, 0, 0 };
  float    plv        = 1.0;
  bool     keep_going = true;
  uint16_t cp         = 0;

  /* Pointers store current "best" */
  ivs->attack  = 0;
  ivs->stamina = 0;
  ivs->defense = 0;
  *lv          = 0.0;

  for ( plv = 1.0; ( plv <= MAX_LEVEL ) && keep_going; plv += 0.5 )
    {
      keep_going = false;
      for ( pivs.attack = 0; pivs.attack <= 15; pivs.attack++ )
        {
          for ( pivs.stamina = 0; pivs.stamina <= 15; pivs.stamina++ )
            {
              for ( pivs.defense = 0; pivs.defense <= 15; pivs.defense++ )
                {
                  cp = get_cp_from_stats( base, pivs, plv );
                  if ( cp <= cp_cap )
                    {
                      keep_going = true;
                      peff = get_effective_stats( base, pivs, plv );
                      if ( 0 < cmp_stats( peff, eff_best ) )
                        {
                          eff_best = peff;
                          *lv      = plv;
                          *ivs     = pivs;
                        }
                    }
                }
            }
        }
    }
  return 0 < ( *lv );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
