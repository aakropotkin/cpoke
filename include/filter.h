/* -*- mode: c; -*- */

#ifndef _FILTER_H
#define _FILTER_H

/* ========================================================================== */

#include "pokemon.h"
#include "util/macros.h"


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
 * <p>
 * If you're the kind of person who hates "when people abuse C macros to
 * immitate C++ templates", I can only say "Sorry, not sorry".
 */
#define _DEF_ROST_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )             \
    static inline bool                                                        \
  rost_mon_ ## FNAME ## _p( roster_pokemon_t * MNAME, ARGT ARGN ) BODY        \
    static bool                                                               \
  rost_mon_ ## FNAME ## _pred( roster_pokemon_t * MNAME, void * argptr )      \
  {                                                                           \
    return rost_mon_ ## FNAME ## _p( MNAME, *( (ARGT *) argptr ) );           \
  }

#define _DEF_BASE_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )             \
    static inline bool                                                        \
  base_mon_ ## FNAME ## _p( base_pokemon_t * MNAME, ARGT ARGN ) BODY          \
    static bool                                                               \
  base_mon_ ## FNAME ## _pred( base_pokemon_t * MNAME, void * argptr )        \
  {                                                                           \
    return base_mon_ ## FNAME ## _p( MNAME, *( (ARGT *) argptr ) );           \
  }

#define _DEF_PDEX_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                 \
    static inline bool                                                        \
  pdex_mon_ ## FNAME ## _p( const pdex_mon_t * MNAME, ARGT ARGN ) BODY        \
    static bool                                                               \
  pdex_mon_ ## FNAME ## _pred( const pdex_mon_t * MNAME, void * argptr )      \
  {                                                                           \
    return pdex_mon_ ## FNAME ## _p( MNAME, *( (ARGT *) argptr ) );           \
  }

#define _DEF_PB_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                   \
  _DEF_PDEX_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                       \
  _DEF_BASE_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, {                        \
      return pdex_mon_ ## FNAME ## _p( MNAME->pdex_mon, ARGN );               \
    } )

#define _DEF_BR_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                   \
  _DEF_BASE_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                   \
  _DEF_ROST_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, {                        \
      return base_mon_ ## FNAME ## _p( MNAME->base, ARGN );                   \
    } )

#define _DEF_PBR_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                  \
  _DEF_PDEX_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                       \
  _DEF_BASE_FILTER_A1( FNAME, MNAME, ARGT, ARGN, {                            \
      return pdex_mon_ ## FNAME ## _p( MNAME->pdex_mon, ARGN );               \
    } )                                                                       \
  _DEF_ROST_FILTER_A1( FNAME, MNAME, ARGT, ARGN, {                            \
      return pdex_mon_ ## FNAME ## _p( MNAME->base->pdex_mon, ARGN );         \
    } )


/* `enum {}' swallows the semicolon. */
#define DEF_ROST_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )              \
  _DEF_ROST_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY ) enum {}

#define DEF_BASE_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )              \
  _DEF_BASE_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY ) enum {}

#define DEF_PDEX_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                  \
  _DEF_BASE_MON_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY ) enum {}

#define DEF_PB_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                    \
  _DEF_PB_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY ) enum {}

#define DEF_BR_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                    \
  _DEF_BR_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY ) enum {}

#define DEF_PBR_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY )                   \
  _DEF_PBR_FILTER_A1( FNAME, MNAME, ARGT, ARGN, BODY ) enum {}


/* -------------------------------------------------------------------------- */

/**
 * Requires no extra arguments ( "Is this a regional Pokemon?", etc )
 */
#define _DEF_ROSTER_MON_FILTER_A0( FNAME, MNAME, BODY )                       \
    static inline bool                                                        \
  rost_mon_ ## FNAME ## _p( roster_pokemon_t * MNAME ) BODY                   \
    static bool                                                               \
  rost_mon_ ## FNAME ## _pred( roster_pokemon_t * MNAME, void * __NOTUSED )   \
  {                                                                           \
    return rost_mon_ ## FNAME ## _p( MNAME );                                 \
  }

#define _DEF_BASE_MON_FILTER_A0( FNAME, MNAME, BODY )                         \
    static inline bool                                                        \
  base_mon_ ## FNAME ## _p( base_pokemon_t * MNAME ) BODY                     \
    static bool                                                               \
  base_mon_ ## FNAME ## _pred( base_pokemon_t * MNAME, void * __NOTUSED )     \
  {                                                                           \
    return base_mon_ ## FNAME ## _p( MNAME );                                 \
  }

#define _DEF_PDEX_FILTER_A0( FNAME, MNAME, BODY )                             \
    static inline bool                                                        \
  pdex_mon_ ## FNAME ## _p( const pdex_mon_t * MNAME ) BODY                   \
    static bool                                                               \
  pdex_mon_ ## FNAME ## _pred( const pdex_mon_t * MNAME, void * __NOTUSED )   \
  {                                                                           \
    return pdex_mon_ ## FNAME ## _p( MNAME );                                 \
  }

#define _DEF_PB_FILTER_A0( FNAME, MNAME, BODY )                               \
  _DEF_PDEX_FILTER_A0( FNAME, MNAME )                                         \
  _DEF_BASE_MON_FILTER_A0( FNAME, MNAME, {                                    \
      return pdex_mon_ ## FNAME ## _p( MNAME->pdex_mon );                     \
    } )

#define _DEF_BR_FILTER_A0( FNAME, MNAME, BODY )                               \
  _DEF_BASE_FILTER_A0( FNAME, MNAME )                                         \
  _DEF_ROST_MON_FILTER_A0( FNAME, MNAME, {                                    \
      return base_mon_ ## FNAME ## _p( MNAME->base );                         \
    } )

#define _DEF_PBR_FILTER_A0( FNAME, MNAME, BODY )                              \
  _DEF_PDEX_FILTER_A0( FNAME, MNAME )                                         \
  _DEF_BASE_MON_FILTER_A0( FNAME, MNAME, {                                    \
      return pdex_mon_ ## FNAME ## _p( MNAME->pdex_mon );                     \
    } )                                                                       \
  _DEF_ROST_MON_FILTER_A0( FNAME, MNAME, {                                    \
      return pdex_mon_ ## FNAME ## _p( MNAME->base->pdex_mon );               \
    } )


#define DEF_ROST_MON_FILTER_A0( FNAME, MNAME, BODY )                          \
  _DEF_ROST_MON_FILTER_A0( FNAME, MNAME, BODY ) enum {}

#define DEF_BASE_MON_FILTER_A0( FNAME, MNAME, BODY )                          \
  _DEF_BASE_MON_FILTER_A0( FNAME, MNAME, BODY ) enum {}

#define DEF_PDEX_FILTER_A0( FNAME, MNAME, BODY )                              \
  _DEF_PDEX_FILTER_A0( FNAME, MNAME, BODY )  enum {}

#define DEF_PB_FILTER_A0( FNAME, MNAME, BODY )                                \
  _DEF_PB_FILTER_A0( FNAME, MNAME, BODY ) enum {}

#define DEF_BR_FILTER_A0( FNAME, MNAME, BODY )                                \
  _DEF_BR_FILTER_A0( FNAME, MNAME, BODY ) enum {}

#define DEF_PBR_FILTER_A0( FNAME, MNAME, BODY )                               \
  _DEF_PBR_FILTER_A0( FNAME, MNAME, BODY ) enum {}


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_region_p( const pdex_mon_t * mon,
                                      enum  region_e     reg
                                    );
static inline bool base_mon_region_p( base_pokemon_t * mon, enum region_e reg );
static bool pdex_mon_region_pred( const pdex_mon_t * mon, void * reg_ptr );
static bool base_mon_region_pred( base_pokemon_t * mon, void * reg_ptr );

/**
 * Check if dex number is in the range of the region.
 */
DEF_PBR_FILTER_A1( region, mon, enum region_e, reg, {
    return in_eq( REGIONS[reg].dex_start,
                  mon->dex_number,
                  REGIONS[reg].dex_end
                );
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_family_p( const pdex_mon_t * mon, uint16_t family );
static inline bool base_mon_family_p( base_pokemon_t * mon, uint16_t family );
static bool pdex_mon_family_pred( const pdex_mon_t * mon, void * family_ptr );
static bool base_mon_family_pred( base_pokemon_t * mon, void * family_ptr );

DEF_PBR_FILTER_A1( family, mon, uint16_t, family, {
    return mon->family == family;
  } );


/* -------------------------------------------------------------------------- */

/**
 * Create a predicate collection foreach region
 */
#define DEF_REGION_FILTER( FNAME, RNAME )                                     \
  DEF_PBR_FILTER_A0( FNAME, mon, {                                            \
    return pdex_mon_region_p( mon, RNAME );                                   \
  } )

DEF_REGION_FILTER( kanto,          REGION_KANTO );
DEF_REGION_FILTER( johto,          REGION_JOHTO );
DEF_REGION_FILTER( hoenn,          REGION_HOENN );
DEF_REGION_FILTER( sinnoh,         REGION_SINNOH );
DEF_REGION_FILTER( unova,          REGION_UNOVA );
DEF_REGION_FILTER( kalos,          REGION_KALOS );
DEF_REGION_FILTER( region_unknown, REGION_UNKNOWN );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_tags_p( const pdex_mon_t      * mon,
                                          pdex_tag_mask_t   tags
                                  );
static inline bool base_mon_tags_p( base_pokemon_t  * mon,
                                    pdex_tag_mask_t   tags
                                  );
static bool pdex_mon_tags_pred( const pdex_mon_t * mon, void * tags_ptr );
static bool base_mon_tags_pred( base_pokemon_t * mon, void * tags_ptr );

DEF_PBR_FILTER_A1( tags, mon, pdex_tag_mask_t, tags, {
    return !! ( mon->tags & tags );
  } );


/* -------------------------------------------------------------------------- */

/**
 * Create a predicate collection foreach `PDEX_TAG'
 */
#define DEF_PDEX_TAG_FILTER( FNAME, TAG )                                     \
  DEF_PBR_FILTER_A0( FNAME, mon, {                                            \
    return pdex_mon_tags_p( mon, get_pdex_tag_mask( TAG ) );                  \
  } )

/* `pdex_mon_legendary_p( const pdex_mon_t * mon );', etc... */
DEF_PDEX_TAG_FILTER( legendary,       TAG_LEGENDARY );
DEF_PDEX_TAG_FILTER( mythic,          TAG_MYTHIC );
DEF_PDEX_TAG_FILTER( mythical,        TAG_MYTHIC );           /* Alias */
DEF_PDEX_TAG_FILTER( mega,            TAG_MEGA );
DEF_PDEX_TAG_FILTER( shadow_eligable, TAG_SHADOW_ELIGABLE );
DEF_PDEX_TAG_FILTER( shadow,          TAG_SHADOW );
DEF_PDEX_TAG_FILTER( pure,            TAG_PURE );
DEF_PDEX_TAG_FILTER( purified,        TAG_PURE );             /* Alias */
DEF_PDEX_TAG_FILTER( alolan,          TAG_ALOLAN );
DEF_PDEX_TAG_FILTER( galarian,        TAG_GALARIAN );
DEF_PDEX_TAG_FILTER( starter,         TAG_STARTER );
DEF_PDEX_TAG_FILTER( regional,        TAG_REGIONAL );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_types_any_p( const pdex_mon_t   * mon,
                                               ptype_mask_t   types
                                       );
static inline bool base_mon_types_any_p( base_pokemon_t * mon,
                                         ptype_mask_t     types
                                       );
static bool pdex_mon_types_any_pred( const pdex_mon_t * mon, void * types_ptr );
static bool base_mon_types_any_pred( base_pokemon_t * mon, void * types_ptr );

DEF_PBR_FILTER_A1( types_any, mon, ptype_mask_t, types, {
    return !! ( mon->types & types );
  } );


/* -------------------------------------------------------------------------- */

/**
 * Create a predicate collection foreach Pokemon type.
 */
#define DEF_PTYPE_FILTER( FNAME, TNAME )                                      \
  DEF_PBR_FILTER_A0( FNAME, mon, {                                        \
      return pdex_mon_types_any_p( mon, get_ptype_mask( TNAME ) );            \
    } )

DEF_PTYPE_FILTER( bug,      BUG );
DEF_PTYPE_FILTER( dark,     DARK );
DEF_PTYPE_FILTER( dragon,   DRAGON );
DEF_PTYPE_FILTER( electric, ELECTRIC );
DEF_PTYPE_FILTER( fairy,    FAIRY );
DEF_PTYPE_FILTER( fighting, FIGHTING );
DEF_PTYPE_FILTER( fire,     FIRE );
DEF_PTYPE_FILTER( flying,   FLYING );
DEF_PTYPE_FILTER( ghost,    GHOST );
DEF_PTYPE_FILTER( grass,    GRASS );
DEF_PTYPE_FILTER( ground,   GROUND );
DEF_PTYPE_FILTER( ice,      ICE );
DEF_PTYPE_FILTER( normal,   NORMAL );
DEF_PTYPE_FILTER( poison,   POISON );
DEF_PTYPE_FILTER( psychic,  PSYCHIC );
DEF_PTYPE_FILTER( rock,     ROCK );
DEF_PTYPE_FILTER( steel,    STEEL );
DEF_PTYPE_FILTER( water,    WATER );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_types_all_p( const pdex_mon_t   * mon,
                                               ptype_mask_t   types
                                       );
static inline bool base_mon_types_all_p( base_pokemon_t * mon,
                                         ptype_mask_t     types
                                       );
static bool pdex_mon_types_all_pred( const pdex_mon_t * mon, void * types_ptr );
static bool base_mon_types_all_pred( base_pokemon_t * mon, void * types_ptr );

DEF_PBR_FILTER_A1( types_all, mon, ptype_mask_t, types, {
    return types <= ( mon->types & types );
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_has_fast_p( const pdex_mon_t * mon,
                                              uint16_t     move_id
                                      );
static inline bool base_mon_has_fast_p( base_pokemon_t * mon,
                                        uint16_t         move_id
                                      );
static inline bool rost_mon_has_fast_p( roster_pokemon_t * mon,
                                        uint16_t           move_id
                                      );
static bool pdex_mon_has_fast_pred( const pdex_mon_t * mon,
                                          void       * move_id_ptr
                                  );
static bool base_mon_has_fast_pred( base_pokemon_t * mon,
                                    void           * move_id_ptr
                                  );
static inline bool rost_mon_has_fast_p( roster_pokemon_t * mon,
                                        void             * move_id_ptr
                                      );

DEF_PB_FILTER_A1( has_fast, mon, uint16_t, move_id, {
    for ( uint8_t i = 0; i < mon->fast_moves_cnt; i++ )
      {
        if ( abs( mon->fast_move_ids[i] ) == move_id ) return true;
      }
    return false;
  } );

DEF_ROST_MON_FILTER_A1( has_fast, mon, uint16_t, move_id, {
    return mon->fast_move_id == move_id;
  } );


/* -------------------------------------------------------------------------- */

static inline bool pdex_mon_has_charged_p( const pdex_mon_t * mon,
                                                 uint16_t     move_id
                                         );
static inline bool base_mon_has_charged_p( base_pokemon_t * mon,
                                           uint16_t         move_id
                                         );
static bool pdex_mon_has_charged_pred( const pdex_mon_t * mon,
                                             void       * move_id_ptr
                                     );
static bool base_mon_has_charged_pred( base_pokemon_t * mon,
                                       void           * move_id_ptr
                                     );
static bool base_mon_has_charged_pred( base_pokemon_t * mon,
                                       void           * move_id_ptr
                                     );
static inline bool rost_mon_has_charged_p( roster_pokemon_t * mon,
                                           void             * move_id_ptr
                                         );

DEF_PB_FILTER_A1( has_charged, mon, uint16_t, move_id, {
    for ( uint8_t i = 0; i < mon->charged_moves_cnt; i++ )
      {
        if ( abs( mon->charged_move_ids[i] ) == move_id ) return true;
      }
    return false;
  } );

DEF_ROST_MON_FILTER_A1( has_charged, mon, uint16_t, move_id, {
    return ( mon->charged_move_ids[0] == move_id ) ||
           ( mon->charged_move_ids[1] == move_id );
  } );


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* filter.h */

/* vim: set filetype=c : */
