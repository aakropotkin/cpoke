/* -*- mode: c; -*- */

#ifndef _MACROS_H
#define _MACROS_H

/* Assert the use of GCC so we can use extension. */
#ifndef __GNUC__
#error "__GNUC__ not defined"
#else /* def __GNUC__ */

/* ========================================================================= */

#include <assert.h>

/* Note: -------------------------------------------------------------- {{{1 *
 * A Macro collection to be used across projects.
 *
 * Limitations:
 *  - You must use GCC, or a compiler which supports GCC's extensions.
 * End Note ----------------------------------------------------------- }}}1 */


/* Pragmas: ----------------------------------------------------------- {{{1 */

#define do_pragma( p )    _Pragma( # p )
#define TODO( msg )       do_pragma( message( "TODO: " # msg ))
#define pragma_pop()      do_pragma( GCC diagnostic pop )
#define pragma_push()     do_pragma( GCC diagnostic push )
/* Ex: pragma_ignore ("-Wunused"); */
#define pragma_ignore( w )    do_pragma( GCC diagnostic ignored w )

#define GCC_IGNORE_UNUSED                                                     \
  pragma_ignore ( "-Wunused" );                                               \
  pragma_ignore ( "-Wunused-but-set-variable" );                              \
  pragma_ignore ( "-Wunused-parameter" );                                     \
  pragma_ignore ( "-Wunused-variable" )


/* End Pragmas -------------------------------------------------------- }}}1 */


/* Attributes: -------------------------------------------------------- {{{1 */

/* Tell GCC to SHUT UP about unused variables. */
#define unused         __attribute__((__unused__))
#define transparent    __attribute__((__transparent_union__))
#define align8         __attribute__((aligned (8)))
#define packed         __attribute__((packed))
#define pure_fn        __attribute__((pure))
#define const_fn       __attribute__((const))


/* End Attributes ----------------------------------------------------- }}}1 */


/* Puns: -------------------------------------------------------------- {{{1 */

#define when( p, expr ) if ( p ) { ( expr ); }
#define not( b ) !( b )

#ifndef nop
  #define nop()    asm volatile ( "nop" )
#endif


/* End Puns ----------------------------------------------------------- }}}1 */


/* Build Bugs and Asserts: -------------------------------------------- {{{1 */

#define throw( s )    assert( 0, "Exception: " ( s ) )

/**
 * Compile time assertions, that can be used in macros, unlike `static_assert`.
 * Borrowed from the Linux Kernel.
 */
#define _compiletime_assert( condition, msg, prefix, suffix )                 \
  __compiletime_assert( condition, msg, prefix, suffix )

/* Shorter. */
#define compiletime_assert( condition, msg )                                  \
  _compiletime_assert( condition, msg, __compiletime_assert_, __LINE__ )

/* Create a compiler bug when the provided expression (predicate) returns 0 */
#define BUILD_BUG_ON_ZERO( e )    ( sizeof( struct { int : -!!( e ); } ) )

/**
 * BUILD_BUG_ON_INVALID - permits the compiler to check the validity of the
 * expression but avoids the generation of any code, even if that expression
 * has side-effects.
 */
#define BUILD_BUG_ON_INVALID( e )                                             \
  ( (void) ( sizeof( ( __force long ) ( e ) ) ) )

/* BUILD_BUG_ON_MSG - break compile if a condition is true & emit message. */
#define BUILD_BUG_ON_MSG( cond, msg )    compiletime_assert( !( cond ), msg )

/* BUILD_BUG_ON - break compile if a condition is true. */
#define BUILD_BUG_ON( condition )                                             \
  BUILD_BUG_ON_MSG( condition, "BUILD_BUG_ON failed: " # condition )

/* BUILD_BUG - break compile if used. */
#define BUILD_BUG()    BUILD_BUG_ON_MSG( 1, "BUILD_BUG failed" )


/* End Build Bugs and Asserts ----------------------------------------- }}}1 */


/* Stringize: --------------------------------------------------------- {{{1 */

/* Convert a token to a string. */
#define STRINGIFY( token )    # token
#define TOSTRING( token )     STRINGIFY( token )
/*
 * #define foo 4
 * STRINGIFY( foo ) // ==> "foo"
 * TOSTRING( foo ) // ==> 4
 */

/* Concatenate. */
#ifndef CAT
#  define CAT( a, ... )     _CAT( a, __VA_ARGS__ )
#endif /* ndef CAT */

/* Primitive Concatenate. */
#ifndef _CAT
#  define _CAT( a, ... )    a ## __VA_ARGS__
/*
 * int foo_bar = 1;
 * int foo_baz = 2;
 * _CAT( foo, _bar )            // ==> foo_bar
 * _CAT( foo, _baz )            // ==> foo_baz
 *
 * // Bad:
 * _CAT( _CAT( foo, _ ), bar )  // ==> foo__CAT( bar )
 * // Bad:
 * _CAT( CAT( foo, _ ), bar )   // ==> foo_CAT( bar )
 * // Good:
 * CAT( _CAT ( foo, _ ), bar )  // ==> foo_baz
 * // Just use cat by default to be safe.
 * CAT( CAT( foo, _ ), bar )    // ==> foo_bar
 *
 * CAT( "Foo", "Bar" )         // ==> "Foo" "Bar"
 */

#endif /* ndef _CAT */


/* End Stringize ------------------------------------------------------ }}}1 */


/* Token Duplication: ------------------------------------------------- {{{1 */

/* Limited to 10 repeats, use recursive definitions if you want more. */
#define  REPEAT( N, S, TERM )    _REPEAT ##            N( S, TERM )

#define _REPEAT0(   S, TERM )                                TERM
#define _REPEAT1(   S, TERM )             S     _REPEAT0( S, TERM )
#define _REPEAT2(   S, TERM )    _REPEAT1( S, ) _REPEAT1( S, TERM )
#define _REPEAT3(   S, TERM )             S     _REPEAT2( S, TERM )
#define _REPEAT4(   S, TERM )    _REPEAT2( S, ) _REPEAT2( S, TERM )
#define _REPEAT5(   S, TERM )             S     _REPEAT4( S, TERM )
#define _REPEAT6(   S, TERM )    _REPEAT3( S, ) _REPEAT3( S, TERM )
#define _REPEAT7(   S, TERM )             S     _REPEAT6( S, TERM )
#define _REPEAT8(   S, TERM )    _REPEAT4( S, ) _REPEAT4( S, TERM )
#define _REPEAT9(   S, TERM )             S     _REPEAT8( S, TERM )
#define _REPEAT10(  S, TERM )    _REPEAT5( S, ) _REPEAT5( S, TERM )
/*
 * This is a classic for String duplication, but this one adds a Terminal token
 * option that lets you get a bit more creative with the expansions.
 * A simple example first:
 * ```
 * REPEAT( 2, "foo", "bar" );                          // ==> "foo" "foo" "bar";
 *
 * REPEAT( 2, printf( "foo\n" );, printf( "bar\n" ) );
 * // ==> printf( "foo\n" ); printf( "foo\n" ); printf( "bar\n" );
 * ```
 * Note that in the second example we used a `;` in the `S` param, but not
 * `TERM` because the macro "eats" the outer semicolon of the call. It of
 * course doesn't hurt to add a semicolon, but it's not necessary to.
 */

#define REPSTR( N, S )    REPEAT( N, S, "" )
/*
 * A shortcut for the "classic" macro.
 * ```
 * REPSTR( 2, "foo" ); // ==> "foo" "foo";
 * ```
 */


/* End Token Duplication ---------------------------------------------- }}}1 */


/* Lambda: ------------------------------------------------------------ {{{1 */

/* ``If you're scared, go to Church.'' -Richie Rich */
#define lambda( return_type, ... )                                            \
  __extension__(                                                              \
  {                                                                           \
    return_type __fn__ __VA_ARGS__                                            \
    __fn__;                                                                   \
  }                                                                           \
               )

/*
 * Lambdas are predominantly useful for generating function definitions, but I
 * will just put two simple examples to illustrate the interface.
 * ```
 * typedef int (*binop_f) (int,int);
 * binop_f add = lambda (int, (int a, int b) { return a + b; });
 * int i = add (1, 2); // ==> 3
 * ```
 * the `typedef` is optional, but is included for clarity.
 * This (pretty contrived) example also works.
 * ```
 * int j = lambda (int, (int a, int b) { return a - b; })(1, 2); // ==> -1
 * ```
 */


/* End Lambda --------------------------------------------------------- }}}1 */


/* Arrays and Pointers: ----------------------------------------------- {{{1 */

#define pointer( T )     typeof( T * )
#define array( T, N )    typeof( T [N] )
/*
 * array (pointer (char), 4) y;
 * y[0] = 'a';
 */

/* &a[0] degrades to a pointer: a different type from an array */
#define __must_be_array( a )                                                  \
  BUILD_BUG_ON_ZERO( typesof_eq( ( a ), &( a )[0] ) )

#define array_size(arr)                                                       \
  ( sizeof( arr ) / sizeof( ( arr )[0] ) + __must_be_array( arr ) )

#define foreach( arr, fn )                                                    \
  for ( size_t i = 0; i < array_size( arr ); i++ )                            \
    fn( ( arr )[i] )

/* Struct Field Offset. */
#define offset_of( field_type, field_name )                                   \
  ( (size_t) &( (field_type *) 0 )->field_name )

/* An extension of `offset_of` */
#define container_of( ptr, type, member )                                     \
  (type *) ( (char *) ( ptr ) - (char *) &( (type *) 0 )->member )
/*
 * typedef struct { char * name; float weight; } fruit_t;
 * // ...
 * // Imagine I have a pointer which I know is a member of a struct, I can use
 * // `container_of` to get the whole struct from any of it's members.
 * char * target_name = ...;
 * fruit_t * target_fruit = container_of (target_name, fruit_t, name);
 */


/* End Arrays and Pointers -------------------------------------------- }}}1 */


/* Math: -------------------------------------------------------------- {{{1 */

#define max( a, b )                                                           \
  __extension__(                                                              \
  {                                                                           \
    __auto_type _a = ( a );                                                   \
    __auto_type _b = ( b );                                                   \
    _a > _b ? _a : _b;                                                        \
  }                                                                           \
               )

#define min( a, b )                                                           \
  __extension__(                                                              \
  {                                                                           \
    __auto_type _a = ( a );                                                   \
    __auto_type _b = ( b );                                                   \
    _a < _b ? _a : _b;                                                        \
  }                                                                           \
               )

#define is_power_of_two( A )                                                  \
  ( ( ( n ) & ( ( n ) - 1 ) ) != 0 )

#define in( lo, x, hi )                                                       \
  __extension__(                                                              \
  {                                                                           \
    __auto_type _lo = ( lo );                                                 \
    __auto_type _hi = ( lo );                                                 \
    __auto_type _x  = ( x );                                                  \
    _lo < _x && _x < _hi                                                      \
  }                                                                           \
               )

#define in_eq( lo, x, hi )                                                    \
  __extension__(                                                              \
  {                                                                           \
    __auto_type _lo = ( lo );                                                 \
    __auto_type _hi = ( lo );                                                 \
    __auto_type _x  = ( x );                                                  \
    _lo <= _x && _x <= _hi                                                    \
  }                                                                           \
               )

/* Less safe, but useful for static assertions. */
#define _in( lo, x, hi )       ( ( lo ) < ( x ) && ( x ) < ( hi ) )
#define _in_eq( lo, x, hi )    ( ( lo ) <= ( x ) && ( x ) <= ( hi ) )

/* Force `x' into range */
#define clamp( lo, x, hi )     ( min( ( hi ), max( ( lo ), ( x ) ) ) )

#define clamp_add( lo, x, i, hi )       clamp( ( lo ), ( x + i ), ( hi ) )
#define clamp_incr( lo, x, hi )         clamp( ( lo ), ( x + 1 ), ( hi ) )
#define clamp_minus( lo, x, i, hi )     clamp( ( lo ), ( x - i ), ( hi ) )
#define clamp_decr( lo, x, hi )         clamp( ( lo ), ( x - 1 ), ( hi ) )
#define clamp_multiply( lo, x, i, hi )  clamp( ( lo ), ( x * i ), ( hi ) )
#define clamp_divide( lo, x, i, hi )    clamp( ( lo ), ( x / i ), ( hi ) )

#define uint_decr( x )                  if ( 0 < ( x ) ) ( x )--

#define uint_minus( x, i )  ( {                                               \
    if ( 0 < ( x ) ) {                                                        \
      if ( ( i ) < ( x ) ) ( x ) -= ( i );                                    \
      else ( x ) = 0;                                                         \
    }                                                                         \
    x                                                                         \
  } )


/* End Math ----------------------------------------------------------- }}}1 */


/* Type Guards: ------------------------------------------------------- {{{1 */

/**
 * This method is stricter than `_Generic` and can properly differentiate
 * between arrays and pointers (unlike _Generic) eg, `char *` from `char []`
 */
#define types_compat_p( x, y )  __builtin_types_compatible_p( x, y )

#define has_type( x, t )  types_compat_p( typeof( x ), t )

#define assert_type( x, t )                                                   \
  assert(                                                                     \
      has_type( ( x ), t )                                                    \
      && "`typeof( " STRINGIFY( x ) " )` == `" STRINGIFY( t ) "`"             \
        )

#define static_assert_type( x, t )                                            \
  static_assert(                                                              \
    has_type( ( x ), t ),                                                     \
    "`typeof( " STRINGIFY( x ) " )` == `" STRINGIFY( t ) "`"                  \
               )

#define typesof_eq( x, y )  types_compat_p( typeof( x ), typeof( y ) )

#define static_assert_typesof_eq( x, y )                                      \
  static_assert(                                                              \
    typesof_eq( ( x ), ( y ) ),                                               \
    "`typeof( " STRINGIFY( x ) " )` == `typeof( " STRINGIFY( y ) " )`"        \
               )

/* NOTE: `void *` is NOT included here. Use `is_void_star`. */
#define primitive_star_TID( x )                                               \
  _Generic ( ( x ),                                                           \
    char *:                       1,                                          \
    signed char *:                2,                                          \
    unsigned char *:              3,                                          \
    short *:                      4,                                          \
    unsigned short *:             5,                                          \
    int *:                        6,                                          \
    unsigned int *:               7,                                          \
    long *:                       8,                                          \
    unsigned long *:              9,                                          \
    long long *:                 10,                                          \
    unsigned long long *:        11,                                          \
    float *:                     12,                                          \
    double *:                    13,                                          \
    long double *:               14,                                          \
    _Bool *:                     15,                                          \
                                                                              \
    const char *:                -1,                                          \
    const signed char *:         -2,                                          \
    const unsigned char *:       -3,                                          \
    const short *:               -4,                                          \
    const unsigned short *:      -5,                                          \
    const int *:                 -6,                                          \
    const unsigned int *:        -7,                                          \
    const long *:                -8,                                          \
    const unsigned long *:       -9,                                          \
    const long long *:          -10,                                          \
    const unsigned long long *: -11,                                          \
    const float *:              -12,                                          \
    const double *:             -13,                                          \
    const long double *:        -14,                                          \
    const _Bool *:              -15,                                          \
    default: 0                                                                \
           )


#define is_primitive_star( x )  ( primitive_star_TID ( x ) != 0 )

#define is_void_star( x )                                                     \
  _Generic ( ( x ),                                                           \
      void *: 1,                                                              \
      default: 0                                                              \
           )


#define is_void_star_star( x )                                                \
  _Generic ( ( x ),                                                           \
      void **: 1,                                                             \
      const void **: 1,                                                       \
      default: 0                                                              \
           )


#define primitive_TID( x )  primitive_star_TID( &( x ) )

#define is_primitive( x )  ( primitive_TID( x ) != 0 )

#define is_integer_star_family( x )                                           \
  ( _in( -16, primitive_star_TID( x ), 16 )                                   \
    && ( primitive_star_TID( x ) != 0 ) )

#define is_integer_family( x )  is_integer_star_family( &( x ) )

#define is_signed_family( x )                                                 \
  ( is_integer_family( x ) && ( ( primitive_TID( x ) % 3 ) != 0 ) )

#define is_unsigned_family( x )                                               \
  ( is_integer_family( x ) && ( ( primitive_TID( x ) % 3 ) == 0 ) )

#define is_signed_ftar_family( x )                                            \
  ( is_integer_star_family( x ) && ( ( primitive_TID( x ) % 3 ) != 0 ) )

#define is_unsigned_star_family( x )                                          \
  ( is_integer_star_family( x ) && ( ( primitive_TID( x ) % 3 ) == 0 ) )


/* End Type Guards --------------------------------------------------- }}}1 */


/* Generic Prints: --------------------------------------------------- {{{1 */

/* TODO */

/* End Generic Prints ------------------------------------------------ }}}1 */


/* ======================================================================== */

#endif /* macros.h */
#endif /* def __GNUC__ */

/* vim: set filetype=c foldmethod=marker foldlevel=0 : */
