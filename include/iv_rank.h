
/* -*- mode: c; -*- */

#ifndef _IV_RANK_H
#define _IV_RANK_H

/* ========================================================================= */

#include "pokemon.h"
#include "util/list.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


/* ------------------------------------------------------------------------- */

struct stats_combo_s {
  uint16_t cp;
  float    lv;
  stats_t  base;
  stats_t  ivs;
  stats_t  eff;
  list_t   elem;
};
typedef struct stats_combo_s  stats_combo_t;

/* ------------------------------------------------------------------------- */

  static inline void
fprint_stats_combo( FILE * fd, stats_combo_t * stats )
{
  fprintf( fd,
           "CP: %u, LV: %.1f, IVs: %u/%u/%u\n",
           stats->cp, stats->lv,
           stats->ivs.attack,  stats->ivs.stamina,  stats->ivs.defense
         );
}
#define print_stats_combo( STATS )  fprint_stats_combo( stdout, ( STATS ) )


/* ------------------------------------------------------------------------- */

  static inline int
cmp_stats_combo( const stats_combo_t * a, const stats_combo_t * b )
{
  return - cmp_stats( a->eff, b->eff );
}

  static inline int
_cmp_stats_combo( const void * a, const void * b )
{
  return cmp_stats_combo( (const stats_combo_t *) a,
                          (const stats_combo_t *) b
                        );
}

  static inline int
_cmp_stats_combo_priv( void * _unused_,  list_t * a, list_t * b )
{
  return cmp_stats_combo( (const stats_combo_t *) list_entry( a, stats_combo_t, elem ),
                          (const stats_combo_t *) list_entry( b, stats_combo_t, elem )
                        );
}


/* ------------------------------------------------------------------------- */

  static inline void
stats_combo_sorted_insert( stats_combo_t ** head, stats_combo_t * new )
{
  stats_combo_t * curr = NULL;

  if ( ( * head ) == NULL )
    {
      *head = new;
      new->elem.next = NULL;
      new->elem.prev = & new->elem;
    }
  else if ( cmp_stats_combo( *head, new ) > 0 ) /* head < new */
    {
      new->elem.next = & ( * head )->elem;
      new->elem.prev = & new->elem;
      ( * head )->elem.prev = & new->elem;
    }
  else
    {
      curr = * head;
      while ( ( curr->elem.next != NULL ) &&
              ( 0 > cmp_stats_combo( *head, new ) )
            ) curr = list_entry( curr->elem.next, stats_combo_t, elem );
      /* Insert */
      new->elem.next = curr->elem.next;
      if ( curr->elem.next != NULL ) new->elem.next->prev = & new->elem;
      curr->elem.next = & new->elem;
      new->elem.prev  = & curr->elem;
    }
}


/* ------------------------------------------------------------------------- */

/**
 * This is naive and just uses `stdlib' `qsort'.
 * This should be improved to use insertion sort drafted above.
 */
  static inline stats_combo_t *
rank_ivs( stats_t base, uint16_t max_rsl, uint16_t cp_cap )
{
  size_t num_elems = floor( MAX_LEVEL - 1.0 ) * 2 * 16 * 16 * 16;
  stats_combo_t * rankings =
    (stats_combo_t *) malloc( sizeof( stats_combo_t ) * num_elems );
  stats_combo_t * ranking = NULL;
  stats_t  ivs        = { 0, 0, 0 };
  float    lv         = 1.0;
  uint16_t cp         = 0;
  bool     keep_going = true;

  if ( rankings == NULL ) return NULL;

  for ( lv = 1.0; ( lv <= MAX_LEVEL ) && keep_going; lv += 0.5 )
    {
      keep_going = false;
      for ( ivs.attack = 0; ivs.attack <= 15; ivs.attack++ )
        {
          for ( ivs.stamina = 0; ivs.stamina <= 15; ivs.stamina++ )
            {
              for ( ivs.defense = 0; ivs.defense <= 15; ivs.defense++ )
                {
                  cp = get_cp_from_stats( base, ivs, lv );
                  if ( cp <= cp_cap )
                    {
                      keep_going = true;

                      ranking = & rankings[(int) ( lv * 2 - 2 ) +
                                           ivs.attack           +
                                           ivs.stamina          +
                                           ivs.defense];
                      ranking->cp   = cp;
                      ranking->lv   = lv;
                      ranking->base = base;
                      ranking->ivs  = ivs;
                      ranking->eff  = get_effective_stats( base, ivs, lv );
                      INIT_LIST_HEAD( & ranking->elem );
                    }
                }
            }
        }
    }

  qsort( (void *) rankings,
         num_elems,
         sizeof( stats_combo_t ),
         _cmp_stats_combo
       );

  rankings =
    (stats_combo_t *) realloc( rankings, sizeof( stats_combo_t ) * max_rsl );

  return rankings;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* iv_rank.h */

/* vim: set filetype=c : */
