/* -*- mode: c; -*- */
/* ========================================================================= */
/* THIS FILE IS FOR REFERENCE ONLY. DO NOT INCLUDE IT IN ANY OTHER FILES. */
/* THIS FILE IS FOR REFERENCE ONLY. DO NOT INCLUDE IT IN ANY OTHER FILES. */
/* THIS FILE IS FOR REFERENCE ONLY. DO NOT INCLUDE IT IN ANY OTHER FILES. */
#if 0
/* ------------------------------------------------------------------------- */

/**
 * Used to build DAMAGE_MODIFIERS from scratch.
 */
void
generate_damage_modifier_mat( void ) {
  printf( "{ " );
  for ( ptype_t d1 = BUG; d1 <= WATER; d1++ ) {
    if ( d1 != BUG ) printf( ", " );
    printf( "{ " );
    for ( ptype_t d2 = PT_NONE; d2 <= WATER; d2++ ) {
      if ( d2 != PT_NONE ) printf( ", " );
      printf( "{ " );
      for ( ptype_t a = BUG; a <= WATER; a++ ) {
        if ( a != BUG ) printf( ", " );
        printf( "%f", get_damage_modifier_duo( d1, d2, a ) );
      }
      printf( " }\n  " );
    }
    printf( "}\n" );
  }
  printf( "}\n" );
}


/* ------------------------------------------------------------------------- */
#endif
/* ========================================================================= */
/* vim: set filetype=c : */
