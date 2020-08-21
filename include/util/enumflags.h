
#ifndef _ENUM_FLAGS_H
#define _ENUM_FLAGS_H

/* ========================================================================= */

#include "util/macros.h"
#include "util/bits.h"
#include "util/fnmacros.h"


/* ------------------------------------------------------------------------- */

#define MASK_DEF( BASENAME )  BASENAME ## _M = to_mask( BASENAME )
#define FLAG_DEF( FLAGNAME )  unsigned int FLAGNAME : 1


#define DEFINE_ENUM( TNAME, ... )                                             \
  typedef enum packed {                                                       \
    MAP( ID, COMMA, __VA_ARGS__ )                                             \
  } TNAME


#define DEFINE_MASKS( TNAME, ... )                                            \
  typedef enum packed {                                                       \
    MAP( MASK_DEF, COMMA, __VA_ARGS__ )                                       \
  } TNAME


/**
 * There are oddball cases where this union cannot be declared transparent,
 * however, GCC will implicitly make it transparent because packing the inner
 * struct does not match the alignment of the mask.
 * Don't sweat this too much, you can sneakily add the transparent attribute
 * after the closing parenthesis and before the semicolon to properly place the
 * `transparent' attribute.
 */
#define DEFINE_FLAG_UNION( TNAME, MTNAME, MNAME, FST, ... )                   \
  typedef union {                                                             \
    MTNAME MNAME;                                                             \
    struct packed {                                                           \
      MAP( FLAG_DEF, SEMICOLON, __VA_ARGS__ );                                \
    };                                                                        \
  } TNAME


/**
 * DEFINE_ENUM_WITH_FLAGS( foo, F0, F1, F2, F3, F4, F5 );
 *
 * Gives us:
 *  - Enum type <code>foo_t</code> with values <code>F0 ... F5</code>
 *  - Enum type <code>foo_mask_t</code> with mask values <code>F0_M ... F5_M</code>
 *  - Union type <code>foo_flags_t</code> with flags as struct members
 */
#define DEFINE_ENUM_WITH_FLAGS( BASETYPENAME, ... )                           \
  DEFINE_ENUM( BASETYPENAME ## _t , __VA_ARGS__ );                            \
  DEFINE_MASKS( BASETYPENAME ## _mask_t, __VA_ARGS__ );                       \
  DEFINE_FLAG_UNION( BASETYPENAME ## _flags_t,                                \
                     BASETYPENAME ## _mask_t,                                 \
                     mask,                                                    \
                     __VA_ARGS__                                              \
                   )


/* ========================================================================= */

#endif /* enumflags.h */
