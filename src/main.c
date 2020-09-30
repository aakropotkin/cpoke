/* -*- mode: c; -*- */
/* ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include "iv_rank.h"


/* ------------------------------------------------------------------------- */

/* This is currently just used to check that headers conpile. */
  int
main( int argc, char * argv[], char ** envp )
{
  stats_t         ven_base = { .attack = 198, .stamina = 190, .defense = 189 };
  stats_combo_t * rankings = rank_ivs( ven_base, 10, 1500 );
  for ( int i = 0; i < 10; i++ )
    {
      printf( "# %d\tCP: %u\n", i + 1, rankings[i].cp );
    }
  free( rankings );

  return EXIT_SUCCESS;
}



/* ========================================================================= */
/* vim: set filetype=c : */
