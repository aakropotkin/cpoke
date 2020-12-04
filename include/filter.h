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
typedef bool (*pdex_mon_pred_fn)( pdex_mon_t *, void * );
typedef bool (*roster_mon_pred_fn)( roster_pokemon_t *, void * );

#define DEF_BASE_MON_FILTER( FNAME, MNAME, ARGT, ARGN, BODY )                 \
    static inline bool                                                        \
  base_mon_ ## FNAME ## _p( base_pokemon_t * MNAME, ARGT ARGN ) BODY          \
    static bool                                                               \
  base_mon_ ## FNAME ## _pred( base_pokemon_t * MNAME, void * argptr )        \
  {                                                                           \
    return base_mon_ ## FNAME ## _p( MNAME, *( (ARGT *) argptr ) );           \
  }                                                                           \
  enum {}
/* `enum {}' swallows the semicolon. */

#define DEF_PDEX_FILTER( FNAME, MNAME, ARGT, ARGN, BODY )                     \
    static inline bool                                                        \
  pdex_mon_ ## FNAME ## _p( const pdex_mon_t * MNAME, ARGT ARGN ) BODY        \
    static bool                                                               \
  pdex_mon_ ## FNAME ## _pred( const pdex_mon_t * MNAME, void * argptr )      \
  {                                                                           \
    return pdex_mon_ ## FNAME ## _p( MNAME, *( (ARGT *) argptr ) );           \
  }                                                                           \
  DEF_BASE_MON_FILTER( FNAME, MNAME, ARGT, ARGN, {                            \
      return pdex_mon_ ## FNAME ## _p( MNAME->pdex_mon, ARGN );               \
    } )


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_region_p( const pdex_mon_t * mon, region_t * reg );
static bool pdex_mon_region_pred( const pdex_mon_t * mon, void * reg_ptr );
static inline bool base_mon_region_p( base_pokemon_t * mon, region_t * reg );
static bool base_mon_region_pred( base_pokemon_t * mon, void * reg_ptr );

DEF_PDEX_FILTER( region, mon, region_t *, reg, {
    return get_region( mon->pdex_number ) == reg;
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_family_p( const pdex_mon_t * mon, uint16_t family );
static inline bool base_mon_family_p( base_pokemon_t * mon, uint16_t family );
static bool pdex_mon_family_pred( const pdex_mon_t * mon, void * family_ptr );
static bool base_mon_family_pred( base_pokemon_t * mon, void * family_ptr );

DEF_PDEX_FILTER( family, mon, uint16_t, family, {
    return mon->family == family;
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_tags_p( const pdex_mon_t      * mon,
                                          pdex_tag_mask_t   tags
                                  );
static inline bool base_mon_tags_p( base_pokemon_t  * mon,
                                    pdex_tag_mask_t   tags
                                  );
static bool pdex_mon_tags_pred( const pdex_mon_t * mon, void * tags_ptr );
static bool base_mon_tags_pred( base_pokemon_t * mon, void * tags_ptr );

DEF_PDEX_FILTER( tags, mon, pdex_tag_mask_t, tags, {
    return !! ( mon->tags & tags );
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_types_any_p( const pdex_mon_t   * mon,
                                               ptype_mask_t   types
                                       );
static inline bool base_mon_types_any_p( base_pokemon_t * mon,
                                         ptype_mask_t     types
                                       );
static bool pdex_mon_types_any_pred( const pdex_mon_t * mon, void * types_ptr );
static bool base_mon_types_any_pred( base_pokemon_t * mon, void * types_ptr );

DEF_PDEX_FILTER( types_any, mon, ptype_mask_t, types, {
    return !! ( mon->types & types );
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_types_all_p( const pdex_mon_t   * mon,
                                               ptype_mask_t   types
                                       );
static inline bool base_mon_types_all_p( base_pokemon_t * mon,
                                         ptype_mask_t     types
                                       );
static bool pdex_mon_types_all_pred( const pdex_mon_t * mon, void * types_ptr );
static bool base_mon_types_all_pred( base_pokemon_t * mon, void * types_ptr );

DEF_PDEX_FILTER( types_all, mon, ptype_mask_t, types, {
    return types <= ( mon->types & types );
  } );


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* filter.h */

/* vim: set filetype=c : */
