/* -*- mode: c; -*- */

#ifndef _FILTER_H
#define _FILTER_H

/* ========================================================================== */

#include "pokemon.h"


/* -------------------------------------------------------------------------- */

/**
 * Filters/predicates to narrow rosters and gm_stores.
 */
typedef bool (*base_mon_pred_fn)( base_pokemon_t *, void * );
typedef bool (*roster_mon_pred_fn)( roster_pokemon_t *, void * );
typedef bool (*pdex_mon_pred_fn)( pdex_mon_t *, void * );


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_region_p( pdex_mon_t * mon, region_t * reg )
{
  return ( reg->dex_start  <= mon->dex_number ) &&
         ( mon->dex_number <= reg->dex_end    );
}

  static bool
pdex_mon_region_pred( pdex_mon_t * mon, void * reg )
{
  return pdex_mon_region_p( mon, (region_t *) reg );
}

  static inline bool
base_mon_region_p( base_pokemon_t * mon, region_t * reg )
{
  return ( reg->dex_start            <= mon->pdex_mon->dex_number ) &&
         ( mon->pdex_mon->dex_number <= reg->dex_end              );
}

  static bool
base_mon_region_pred( base_pokemon_t * mon, void * reg )
{
  return base_mon_region_p( mon, (region_t *) reg );
}


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_family_p( pdex_mon_t * mon, uint16_t family )
{
  return mon->family == family;
}

static bool
pdex_mon_family_pred( pdex_mon_t * mon, void * familyp )
{
  return pdex_mon_family_p( mon, *( (uint16_t *) familyp ) );
}

  static inline bool
base_mon_family_p( pdex_mon_t * mon, uint16_t family )
{
  return mon->pdex_mon->family == family;
}

  static bool
base_mon_family_pred( pdex_mon_t * mon, void * familyp )
{
  return base_mon_family_p( mon, *( (uint16_t *) familyp ) );
}


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* filter.h */

/* vim: set filetype=c : */
