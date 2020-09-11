/* -*- mode: c; -*- */

#ifndef BITS_H
#define BITS_H

/* ========================================================================= */

#include <stdlib.h>
#include <stdio.h>

/* ------------------------------------------------------------------------- */

  static inline void
lshowbits ( unsigned long ul ) {
  for ( int i = 8 * sizeof( unsigned long ) -1; i >= 0; i-- )
    printf( "%lu", ( ul >> i ) & 1 );
  putchar( '\n' );
}

  static inline void
ishowbits ( unsigned int ui ) {
  for ( int j = 8 * sizeof( unsigned int ) -1; j >= 0; j-- )
    printf( "%u", ( ui >> j ) & 1 );
  putchar( '\n' );
}

#define showbits( x ) _Generic( ( x ),                                        \
  long: lshowbits( (unsigned long) x ),                                       \
  const long: lshowbits( (unsigned long ) x ),                                \
  unsigned long: lshowbits( x ),                                              \
  const unsigned long: lshowbits( (unsigned long) x ),                        \
  int: ishowbits( (unsigned int) x ),                                         \
  const int: ishowbits( (unsigned int) x ),                                   \
  unsigned int: ishowbits( x ),                                               \
  const unsigned int: ishowbits( (unsigned int) x ),                          \
  default: ( {                                                                \
    fprintf( stderr, "Unrecognized type in `showbits`!" );                    \
    exit( EXIT_FAILURE );                                                     \
  } ) )


/* ------------------------------------------------------------------------- */

/**
 * Convert a positive integer to a bitmask.
 * Doesn't check that input is positive so just don't fuck it up.
 * Notably 0 and 1 consume the same bit.
 */
#define to_mask( NUM )  ( ( ( !! ( NUM ) ) << ( NUM ) ) >> 1 )


/* ------------------------------------------------------------------------- */

/**
 * Tests if the <code>NTH</code> bit in <code>MASK</code> a 1.
 */
#define has_nth_bit( MASK, NTH )  ( !! ( ( MASK ) & ( 1 << ( NTH ) ) ) )


/* ------------------------------------------------------------------------- */

/**
 * Count the number of 1 bits in a bitmask.
 */
#define popcount( _mask )  __builtin_popcount( ( _mask ) )


/* ------------------------------------------------------------------------- */

/**
 * Count the "trailing" ( rightmost/least-significant ) zeroes in a bitmask.
 */
#define ctz( _mask )  __builtin_ctz( ( _mask  ) )

/**
 * Return the index of the least-significant ( rightmost ) bit of a bitmask.
 */
#define lowest_bit( _mask )  ( ctz( ( _mask ) ) + 1 )


/* ------------------------------------------------------------------------- */

/**
 * Count the "leading" ( leftmost/most-significant ) zeroes in a bitmask.
 */
#define clz( _mask )  __builtin_clz( ( _mask  ) )

/**
 * Return the index of the most-significant ( leftmost ) bit of a bitmask.
 */
#define highest_bit( _mask )  ( ( sizeof( _mask ) * 8 ) - clz( ( _mask ) ) )


/* ------------------------------------------------------------------------- */

/**
 * Pop the least-significant ( rightmost ) bit off of a bitmask.
 * Argument must be a variable name, not a value.
 * Original mask is modified, and the removed bit is returned.
 */
#define mask_pop( ptm )                                                       \
  ( ( ! ( ptm ) ) ? 0 : __extension( {                                        \
    __auto_type _right_bit = 1 << __builtin_ctz( ( ptm ) );                   \
    ptm ^= _right_bit;                                                        \
    _right_bit;                                                               \
  } ) )


/* ------------------------------------------------------------------------- */

/**
 * Split a bitmask into an array of "single count" bitmasks.
 */
#define _mask_to_array( _ptm, _array_type, _array_name, count )               \
  _array_type _array_name[count];                                             \
  for ( int _i = 0; _i < count; i++, _array_name[_i] = mask_pop( ( _ptm ) ) )

#define mask_to_array( ptm, array_type, array_name )                          \
  _mask_to_array( ( ptm ), array_type, array_name, mask_count( ( ptm ) ) )


/* ------------------------------------------------------------------------- */

  static inline unsigned char
log10_u32( unsigned int x )
{
  return ( x >= 1000000000 ) ? 10 :
         ( x >= 100000000  ) ?  9 :
         ( x >= 10000000   ) ?  8 :
         ( x >= 1000000    ) ?  7 :
         ( x >= 100000     ) ?  6 :
         ( x >= 10000      ) ?  5 :
         ( x >= 1000       ) ?  4 :
         ( x >= 100        ) ?  3 :
         ( x >= 10         ) ?  2 :
                                1;
}


/* ------------------------------------------------------------------------- */

  static inline int
atoin( const char * str, unsigned char n )
{
  if ( n > 11 ) return 0;
  unsigned char i = 0;
  char buffer[12] = {
      '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'
    };
  while ( ( *str != '\0' ) && ( i < n ) ) buffer[i++] = *str++;
  return atoi( buffer );
}


/* ------------------------------------------------------------------------- */

  static inline char
atocn( const char * str, unsigned char n )
{
  if ( n > 4 ) return 0;
  char buffer[5] = { '\0', '\0', '\0', '\0', '\0' };
  unsigned char i = 0;
  while ( ( *str != '\0' ) && ( i < n ) ) buffer[i++] = *str++;
  return (char) atoi( buffer );
}


/* ------------------------------------------------------------------------- */

  static inline unsigned char
atoucn( const char * str, unsigned char n )
{
  if ( n > 3 ) return 0;
  char buffer[4] = { '\0', '\0', '\0', '\0' };
  unsigned char i = 0;
  while ( ( '0' <= *str ) && ( *str <= '9' ) && ( i < n ) )
    buffer[i++] = *str++;
  return (unsigned char) atoi( buffer );
}


/* ------------------------------------------------------------------------- */


/* ========================================================================= */

#endif /* def BITS_H */
