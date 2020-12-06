/* -*- mode: c; -*- */

#ifndef _FUZZY_H
#define _FUZZY_H

/* ========================================================================= */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


/* ------------------------------------------------------------------------- */

/**
 * Find the Levenshtein Distance between two string.
 * Results are cached.
 */
  static int
levenshtein( const char * s, const char * t )
{
  assert( s != NULL );
  assert( t != NULL );

	size_t slen = strlen( s );
  size_t tlen = strlen( t );
	int dist[slen + 1][tlen + 1];

	for ( size_t i = 0; i <= slen; i++ )
    {
      for ( size_t j = 0; j <= tlen; j++ )
        {
          dist[i][j] = -1;
        }
    }

	int
 distance( size_t i, size_t j )
  {
		if ( 0 <= dist[i][j] ) return dist[i][j];

		int x = -1;
		if ( i == slen )
      {
        x = tlen - j;
      }
		else if ( j == tlen )
      {
        x = slen - i;
      }
		else if ( s[i] == t[j] )
      {
        x = distance( i + 1, j + 1 );
      }
		else
      {
        x = distance( i + 1, j + 1 );

        int y = -1;
        if ( ( y = distance( i, j + 1 ) ) < x ) x = y;
        if ( ( y = distance( i + 1, j ) ) < x ) x = y;
        x++;
      }
		return dist[i][j] = x;
	}

	return distance( 0, 0 );
}


/* ------------------------------------------------------------------------- */

struct lev_pair_s {
  const char * str;
        int    dst;
};

  static int
_cmp_lev_dists( const void * a, const void * b )
{
  return ( (const struct lev_pair_s *) a )->dst -
         ( (const struct lev_pair_s *) b )->dst;
}

/**
 * Find the Levenshtein Distance of a string against a collection of strings.
 * Fill the shortest `nranked' distances in the buffers `sranked' ( strings )
 * and `dranked' ( distances ).
 * Returns the shortest distance.
 * <p>
 * See `src/test/test_fuzzy.c: test_rank_lev_dist' for a usage example.
 */
  static int
rank_lev_dist( const char   *  s,
               const char   ** strings,
                     size_t    nstrings,
               const char   ** sranked,
                     int    *  dranked,
                     size_t    nranked
             )
{
  assert( s != NULL );
  assert( strings != NULL );
  assert( sranked != NULL );
  assert( dranked != NULL );
  assert( nstrings <= nranked );

         int          shortest  = INT_MAX;
  struct lev_pair_s * lev_dists =
    (struct lev_pair_s *) malloc( sizeof( struct lev_pair_s ) * nstrings );

  assert( lev_dists != NULL );

  for ( size_t i = 0; i < nstrings; i++ )
    {
      lev_dists[i].str = strings[i];
      lev_dists[i].dst = levenshtein( s, strings[i] );
      if ( lev_dists[i].dst < shortest ) shortest = lev_dists[i].dst;
    }

  qsort( (void *) lev_dists,
         nstrings,
         sizeof( struct lev_pair_s ),
         _cmp_lev_dists
       );

  for ( size_t i = 0; i < nranked; i++ )
    {
      sranked[i] = lev_dists[i].str;
      dranked[i] = lev_dists[i].dst;
    }

  free( lev_dists );
  lev_dists = NULL;

  return shortest;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* fuzzy.h */

/* vim: set filetype=c : */
