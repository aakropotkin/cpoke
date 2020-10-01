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
      printf( "# %d\t", i );
      print_stats_combo( rankings + i );
    }

  LIST_HEAD( head );
  for ( int i = 9; 0 <= i ; i-- ) list_add( & rankings[i].elem, & head );
  list_sort( NULL, & head, _cmp_stats_combo_priv );
  stats_combo_t * curr = NULL;
  list_for_each_entry( curr, & head, elem ) print_stats_combo( curr );

  free( rankings );

  return EXIT_SUCCESS;
}



/* ========================================================================= */
/* vim: set filetype=c : */
