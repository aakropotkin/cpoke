/* -*- mode: c; -*- */

#ifndef _FUZZY_H
#define _FUZZY_H

/* ========================================================================= */

#include <assert.h>
#include <stdlib.h>
#include <string.h>


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



/* ========================================================================= */

#endif /* fuzzy.h */

/* vim: set filetype=c : */
