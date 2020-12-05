/* -*- mode: c; -*- */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include "iv_rank.h"
#include "ptypes.h"
#include "util/bits.h"


/* -------------------------------------------------------------------------- */

/* This is currently just used to check that headers conpile. */
  int
main( int argc, char * argv[], char ** envp )
{

  ishowbits( PT_NONE_M | FIRE_M | GRASS_M );

  //stats_t         ven_base = { .attack = 198, .stamina = 190, .defense = 189 };
  //stats_combo_t * rankings = rank_ivs_array( ven_base, 10, GREAT_LEAGUE );
  //fprint_iv_rankings_c( stdout, rankings, 10, GREAT_LEAGUE, 3, 0 );
  //free( rankings );

  return EXIT_SUCCESS;
}



/* ========================================================================== */
/* vim: set filetype=c : */
