/* -*- mode: c; -*- */
/* ========================================================================= */
/* THIS FILE IS FOR REFERENCE ONLY. DO NOT INCLUDE IT IN ANY OTHER FILES. */
/* THIS FILE IS FOR REFERENCE ONLY. DO NOT INCLUDE IT IN ANY OTHER FILES. */
/* THIS FILE IS FOR REFERENCE ONLY. DO NOT INCLUDE IT IN ANY OTHER FILES. */
#if 0
/* ------------------------------------------------------------------------- */

#include <math.h>

/**
 * PvPoke's CPMs calculate half levels from scratch every time.
 * We use their calculator to cache the half level results for speed.
 * This snippet has been left so that it can be referenced in the future.
 */
const double CPMS_full[] = {
  0.093999997, 0.16639787, 0.21573247, 0.25572005, 0.29024988,  /*  1-5  */
  0.321087600, 0.34921268, 0.37523559, 0.39956728, 0.42250001,  /*  6-10 */
  0.443107550, 0.46279839, 0.48168495, 0.49985844, 0.51739395,  /* 11-15 */
  0.534354330, 0.55079269, 0.56675452, 0.58227891, 0.59740001,  /* 16-20 */
  0.612157290, 0.62656713, 0.64065295, 0.65443563, 0.66793400,  /* 21-25 */
  0.681164920, 0.69414365, 0.70688421, 0.71939909, 0.73170000,  /* 26-30 */
  0.737769480, 0.74378943, 0.74976104, 0.75568551, 0.76156384,  /* 31-35 */
  0.767397170, 0.77318650, 0.77893275, 0.78463697, 0.79030001,  /* 36-40 */
  0.795300010, 0.80030000, 0.80530000, 0.81029999, 0.81529999   /* 41-45 */
};

double
calculate_cpm_from_full_levels( float level ) {
  return ( ( fmod( level, 1 ) == 0 )
           ? CPMS_full[( (int) level - 1 )]
           : sqrt( ( pow( CPMS_full[( (int) floor( level ) - 1 )], 2 )
                     + pow( CPMS_full[( (int) ceil( level ) - 1 )], 2 )
                   ) / 2.0
                 )
         );
}


/* ------------------------------------------------------------------------- */
#endif
/* ========================================================================= */
/* vim: set filetype=c : */
