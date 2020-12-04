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

/**
 * Filters come in collections to operate on various types of pokemon, and to
 * meet the type interface of `pred_fn'.
 * Explicitly writing each is tedious, since basically all we do is cast from
 * `(void *)' to make `pred_fn' out of a typed predicate, and unpack extended
 * structs to convert from `base_pokemon_t' to `pdex_mon_t'.
 * Instead we have these convenient macros, which will generate the full
 * collection of functions from a few pieces.
 * <p>
 * `FNAME' will be wrapped to create the names of the filter functions,
 * Ex: foo -> pdex_mon_foo_p, pdex_mon_foo_pred,
 *            base_mon_foo_p, base_mon_foo_pred
 * `MNAME' is the name of the `{pdex_mon,base_pokemon}_t *' argument, which will
 * likely be referred to in the filter's body.
 * `ARGT' is the typeof the filter's second argument.
 * `ARGN' is the name of the second argument, which will likely be referenced in
 * the filter's body.
 * <p>
 * The macro is not complex, but if you want to see how it unrolls you can do:
 * `gcc -I. -E ./filter.h' to dump the preprocessed form of the file.
 */
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
