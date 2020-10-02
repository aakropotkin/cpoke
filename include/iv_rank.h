/* -*- mode: c; -*- */

#ifndef _IV_RANK_H
#define _IV_RANK_H

/* ========================================================================= */

#include "battle.h"
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


/* Minimal information to dump in ranking list */
struct iv_lv_s {
  uint8_t lvi;
  stats_t ivs;
} packed;
typedef struct iv_lv_s  iv_lv_t;


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

#define stats_combo_for_each( CURR, HEAD )                                    \
  list_for_each_entry( ( CURR ), & ( HEAD )->elem, elem )


/* ------------------------------------------------------------------------- */

/* For internal use */
  static inline int
cmp_stats_combo( const stats_combo_t * a, const stats_combo_t * b )
{
  return - cmp_stats( a->eff, b->eff );
}

/* For `qsort' */
  static inline int
_cmp_stats_combo( const void * a, const void * b )
{
  return cmp_stats_combo( (const stats_combo_t *) a,
                          (const stats_combo_t *) b
                        );
}

/* For `list_sort' */
  static inline int
_cmp_stats_combo_priv( void * _unused_,  list_t * a, list_t * b )
{
  return cmp_stats_combo( (const stats_combo_t *)
                            list_entry( a, stats_combo_t, elem ),
                          (const stats_combo_t *)
                            list_entry( b, stats_combo_t, elem )
                        );
}


/* ------------------------------------------------------------------------- */

/**
 * This is naive and just uses `stdlib' `qsort'.
 * This should be improved to use insertion sort drafted above.
 * `0' for `max_rsl' returns ALL.
 */
  static inline stats_combo_t *
rank_ivs_all( stats_t base, uint16_t cp_cap )
{
  uint16_t        num_elems = floor( MAX_LEVEL - 1.0 ) * 2 * 16 * 16 * 16;
  stats_combo_t * rankings  =
    (stats_combo_t *) malloc( sizeof( stats_combo_t ) * num_elems );
  stats_combo_t * ranking    = NULL;
  stats_t         ivs        = { 0, 0, 0 };
  float           lv         = 1.0;
  uint16_t        cp         = 0;
  bool            keep_going = true;

  if ( rankings == NULL ) return NULL;

  for ( lv = 1.0; ( lv <= MAX_LEVEL ) && keep_going; lv += 0.5 )
    {
      //keep_going = false;
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
                    }
                }
            }
        }
    }

  return rankings;
}


  static inline stats_combo_t *
rank_ivs_array( stats_t base, uint16_t max_rsl, uint16_t cp_cap )
{
  stats_combo_t * rankings  = rank_ivs_all( base, cp_cap );
  uint16_t        max_elems = floor( MAX_LEVEL - 1.0 ) * 2 * 16 * 16 * 16;
  if ( rankings == NULL ) return NULL;

  qsort( (void *) rankings,
         max_elems,
         sizeof( stats_combo_t ),
         _cmp_stats_combo
       );

  if ( max_rsl < max_elems )
    {
      rankings =
        (stats_combo_t *) realloc( rankings,
                                   sizeof( stats_combo_t ) * max_rsl
                                 );
    }
  return rankings;
}


/**
 * This should be rewritten later.
 * The issue is memory allocation.
 * `rank_ivs_all' pulls a contiguous block, so there's no good way to free the
 * linked list.
 * <p>
 * Realistically this should allocate individual elems.
 * An insertion sort alongside `list_replace' would also be an improvement.
 */
  static inline stats_combo_t *
rank_ivs_ll( stats_t base, uint16_t max_rsl, uint16_t cp_cap )
{
  stats_combo_t * rankings  = rank_ivs_array( base, cp_cap, cp_cap );
  uint16_t        max_elems = floor( MAX_LEVEL - 1.0 ) * 2 * 16 * 16 * 16;
  if ( rankings == NULL ) return NULL;
  if ( max_rsl == 0 ) max_rsl = max_elems;
  else                max_rsl = min( max_elems, max_rsl );
  for ( uint16_t i = 0; i < max_rsl; i++ )
    {
      INIT_LIST_HEAD( & rankings[i].elem );
      list_add_tail( & rankings[i].elem, & rankings[0].elem );
    }
  return rankings;
}


/* ------------------------------------------------------------------------- */

  static inline void
fprint_iv_rankings_c( FILE          * fd,
                stats_combo_t * rankings,
                uint16_t        num_elems,
                league_t        league,
                uint16_t        dex_num,
                uint8_t         form_idx
              )
{
  assert( rankings != NULL );
  assert( league != MASTER_LEAGUE );
  bool first = true;
  fprintf( fd,
           "static const iv_lv_t IVS_%s_%u_%u[] = {",
           get_league_name( league ),
           dex_num,
           form_idx
         );
  for ( uint16_t i = 0; i < num_elems; i++ )
    {
      if ( first ) first = false;
      else         putc( ',', fd );
      fprintf( fd,
               "\n  { .lvi = %u, "
               ".ivs = { .attack = %u, .stamina = %u, .defense = %u } }",
               (int) ( rankings[i].lv * 2 ),
               rankings[i].ivs.attack,
               rankings[i].ivs.stamina,
               rankings[i].ivs.defense
             );
    }
  fprintf( fd, "\n};\n" );
}

/**
 * This would be nicer if it accepted a `store_t', but I honestly don't think
 * it's going to be rerun frequently enough to justify using the abstraction.
 */
void iv_store_export_c( FILE * fd, uint16_t max_rsl );



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* iv_rank.h */

/* vim: set filetype=c : */
