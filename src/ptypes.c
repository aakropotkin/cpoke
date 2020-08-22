/* -*- mode: c; -*- */
/* ========================================================================= */

#include "ptypes.h"
#include "util/bits.h"
#include "util/macros.h"
#include <stdio.h>

/* ------------------------------------------------------------------------- */

const_fn float
get_damage_modifier_mono_MATRIX( ptype_t def_type, ptype_t atk_type ) {
  return DAMAGE_MODIFIERS[def_type - 1][PT_NONE][atk_type - 1];
}

const_fn float
get_damage_modifier_duo_MATRIX( ptype_t def_type1,
                         ptype_t def_type2,
                         ptype_t atk_type
                       ) {
  return DAMAGE_MODIFIERS[def_type1 - 1][def_type2][atk_type - 1];
}

const_fn float
get_damage_modifier_MATRIX( ptype_mask_t def_types, ptype_t atk_type ) {
  switch( popcount( def_types ) ) {
  case 2:
    return DAMAGE_MODIFIERS[highest_bit( def_types ) - 1]
                           [lowest_bit( def_types )]
                           [atk_type - 1];
    break;
  case 1:
    return DAMAGE_MODIFIERS[highest_bit( def_types ) - 1]
                           [PT_NONE]
                           [atk_type - 1];
    break;
  case 0:
    return 1.0;
    break;
  default:
    fprintf( stderr,
             "'get_damage_modifier' received a 'ptype_mask_t' with more than "
             "two types! Returning '1.0'."
             );
    return 1.0;
    break;
  }
}


/* ------------------------------------------------------------------------- */

const_fn float
get_damage_modifier_mono_TABLE( ptype_t def_type, ptype_t atk_type) {
  ptype_mask_t   atk_mask   = get_ptype_mask( atk_type );
  ptype_traits_t def_traits = get_ptype_traits( def_type );
  return ( def_traits.resistances & atk_mask ) ? RESIST_DMG_MOD :
         ( def_traits.weaknesses & atk_mask )  ? WEAK_DMG_MOD   :
         ( def_traits.immunities & atk_mask )  ? IMMUNE_DMG_MOD :
         1.0;
}


const_fn float
get_damage_modifier_duo_TABLE( ptype_t def_type1,
                               ptype_t def_type2,
                               ptype_t atk_type
                             ) {
  return get_damage_modifier_mono( def_type1, atk_type ) *
         get_damage_modifier_mono( def_type2, atk_type );
}

const_fn float
get_damage_modifier_TABLE( ptype_mask_t def_types, ptype_t atk_type ) {
  float m = 1.0;
  switch( popcount( def_types ) ) {
  case 2:
    m = get_damage_modifier_mono( highest_bit( def_types ), atk_type );
  case 1:
    m *= get_damage_modifier_mono( lowest_bit( def_types ), atk_type );
  case 0:
    break;
  default:
    fprintf( stderr,
             "'get_damage_modifier' received a 'ptype_mask_t' with more than "
             "two types! Returning '1.0'."
           );
  }
  return m;
}


/* ------------------------------------------------------------------------- */

/**
 * <code>PTYPES_USE_TABLE</code> attribute will cause damage modifier lookups
 * to reference the <code>ptype_traits</code> table rather than the
 * pre-calculated damage matrix.
 */
#ifdef PTYPES_USE_TABLE

const_fn float get_damage_modifier_mono( ptype_t def_type, ptype_t atk_type )
  __attribute__(( alias( "get_damage_modifier_mono_TABLE" ) ));

const_fn float get_damage_modifier_duo( ptype_t def_type1,
                                        ptype_t def_type2,
                                        ptype_t atk_type
                                      )
  __attribute__(( alias( "get_damage_modifier_duo_TABLE" ) ));

const_fn float get_damage_modifier( ptype_mask_t def_types, ptype_t atk_type)
  __attribute__(( alias( "get_damage_modifier_TABLE" ) ));

#else /* PTYPES_USE_TABLE */

const_fn float get_damage_modifier_mono( ptype_t def_type, ptype_t atk_type )
  __attribute__(( alias( "get_damage_modifier_mono_MATRIX" ) ));

const_fn float get_damage_modifier_duo( ptype_t def_type1,
                                        ptype_t def_type2,
                                        ptype_t atk_type
                                        )
  __attribute__(( alias( "get_damage_modifier_duo_MATRIX" ) ));

const_fn float get_damage_modifier( ptype_mask_t def_types, ptype_t atk_type)
  __attribute__(( alias( "get_damage_modifier_MATRIX" ) ));

#endif /* PTYPES_USE_TABLE */


const_fn float
get_damage_modifier_flags( ptype_flags_t def_types, ptype_t atk_type ) {
  return get_damage_modifier( def_types.mask, atk_type );
}


/* ------------------------------------------------------------------------- */

int
fprint_ptype_mask( FILE * fd, const char * sep, ptype_mask_t pm ) {

  bool fst           = true;
  int  printed_chars = 0;

  /* Masking aginst 0 will always fail, so `PT_NONE' is a special case. */
  if ( pm == PT_NONE ) return fprintf( fd, "%s", get_ptype_name( PT_NONE ) );

  for ( int i = 1; i < NUM_PTYPES; i++ ) {
    if ( pm & get_ptype_mask( i ) ) {
      /* Don't print a seperator for the first match. */
      if ( fst ) fst = false;
      else       printed_chars += fprintf( fd, "%s", sep );
      printed_chars += fprintf( fd, "%s", get_ptype_name( i ) );
    }
  }

  return printed_chars;
}


/* ========================================================================= */
/* vim: set filetype=c : */
