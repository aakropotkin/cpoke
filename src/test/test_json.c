/* -*- mode: c; -*- */

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include "util/json_util.h"
#include "util/macros.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/test_util.h"
#include <regex.h>

/* ------------------------------------------------------------------------- */

static const char
json_str1[] = "{"
                 "\"name\":       \"Suzy\""
              ",  \"age\":        23"
              ",  \"occupation\": \"mechanic\""
              "}";
static const size_t json_str1_len = array_size( json_str1 );
static const size_t json_str1_nts = 7;


/* ------------------------------------------------------------------------- */

static const char
json_str2[] = "["
  "\"name\",       \"Suzy\""
  ",  \"age\",        23"
  ",  \"occupation\", \"mechanic\""
  "]";
static const size_t json_str2_len = array_size( json_str2 );
static const size_t json_str2_nts = 7;


/* ------------------------------------------------------------------------- */

static const char
json_str3[] = "[ \"name\", \"Suzy\", \"age\", 23" ", \"occupation\", "
                 "\"mechanic\", [ 1, 2, 3 ]"
              "]";
static const size_t json_str3_len = array_size( json_str3 );
static const size_t json_str3_nts = 11;


/* ------------------------------------------------------------------------- */

#define parse_json_str( STR_NAME, TOKEN_LIST_NAME, COUNT_NAME )               \
  jsmntok_t TOKEN_LIST_NAME[STR_NAME ## _nts];                                \
  jsmn_parser STR_NAME ## _PARSER;                                            \
  jsmn_init( & STR_NAME ## _PARSER );                                         \
  int COUNT_NAME = jsmn_parse( & STR_NAME ## _PARSER,                         \
                               ( STR_NAME ),                                  \
                               ( STR_NAME ## _len ),                          \
                               ( TOKEN_LIST_NAME ),                           \
                               ( STR_NAME ## _nts )                           \
                             )


/* ------------------------------------------------------------------------- */

  static bool
test_jsoneq( void )
{
  parse_json_str( json_str1, tokens, r );
  assert( r == 7 );

  expect( jsoneq( json_str1, &tokens[1], "name" ) );
  expect( jsoneq( json_str1, &tokens[2], "Suzy" ) );
  expect( jsoneq( json_str1, &tokens[3], "age" ) );
  expect( jsoneq( json_str1, &tokens[4], "23" ) );
  expect( jsoneq( json_str1, &tokens[5], "occupation" ) );
  expect( jsoneq( json_str1, &tokens[6], "mechanic" ) );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_jsoneq_typed( void )
{

  parse_json_str( json_str1, tokens, r );
  assert( r == 7 ); /* Use `assert' because we are not testing the parser */

  expect( jsoneq_str( json_str1, &tokens[1], "name" ) );
  expect( jsoneq_str( json_str1, &tokens[2], "Suzy" ) );
  expect( jsoneq_str( json_str1, &tokens[3], "age" ) );
  expect( jsoneq_int( json_str1, &tokens[4], 23 ) );
  expect( jsoneq_str( json_str1, &tokens[5], "occupation" ) );
  expect( jsoneq_str( json_str1, &tokens[6], "mechanic" ) );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_jsmn_iterator_object( void )
{
  jsmn_iterator_t iterator;
  jsmntok_t *     id = NULL;
  jsmntok_t *     value = NULL;
  int             rsl  = 0;

  parse_json_str( json_str1, tokens, r );
  assert( r == 7 ); /* Use `assert' because we are not testing the parser */

  if ( jsmn_iterator_init( &iterator, tokens, r, 0 ) < 0 )
      expect( false && "Iterator initialization failed" );

  rsl = jsmn_iterator_next( &iterator, &id, &value, 0 );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str1, id, "name" ) );
  expect( jsoneq_str( json_str1, value, "Suzy" ) );

  rsl = jsmn_iterator_next( &iterator, &id, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str1, id, "age" ) );
  expect( jsoneq_int( json_str1, value, 23 ) );

  rsl = jsmn_iterator_next( &iterator, &id, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str1, id, "occupation" ) );
  expect( jsoneq_str( json_str1, value, "mechanic" ) );

  rsl = jsmn_iterator_next( &iterator, &id, &value, value->start );
  expect( 0 == rsl );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_jsmn_iterator_array( void )
{
  jsmn_iterator_t iterator;
  jsmntok_t *     value = NULL;
  int             rsl  = 0;

  parse_json_str( json_str2, tokens, r );
  assert( r == 7 ); /* Use `assert' because we are not testing the parser */

  if ( jsmn_iterator_init( &iterator, tokens, r, 0 ) < 0 )
      expect( false && "Iterator initialization failed" );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, 0 );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str2, value, "name" ) );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str2, value, "Suzy" ) );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str2, value, "age" ) );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_int( json_str2, value, 23 ) );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str2, value, "occupation" ) );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq_str( json_str2, value, "mechanic" ) );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 == rsl );

  return true;
}


/* ------------------------------------------------------------------------- */

/**
 * Shows that <code>jsmn_iterator_t</code> does not dive recursively into
 * child structures.
 */
  static bool
test_jsmn_iterator_array_nested( void )
{
  jsmn_iterator_t iterator;
  jsmntok_t *     value = NULL;
  int             rsl  = 0;

  parse_json_str( json_str3, tokens, r );
  assert( r == 11 ); /* Use `assert' because we are not testing the parser */

  if ( jsmn_iterator_init( &iterator, tokens, r, 0 ) < 0 )
      expect( false && "Iterator initialization failed" );

  rsl = jsmn_iterator_next( &iterator, NULL, &value, 0 );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( jsoneq_str( json_str3, value, "mechanic" ) );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  expect( 0 < rsl );
  expect( jsoneq( json_str3, value, "[ 1, 2, 3 ]" ) );
  rsl = jsmn_iterator_next( &iterator, NULL, &value, value->start );
  /* Nothing left. The iterator DOES NOT dive recursively into the child list */
  expect( rsl == 0 );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_json_find( void )
{

  parse_json_str( json_str1, tokens, r );
  assert( r == 7 ); /* Use `assert' because we are not testing the parser */

  expect( json_find( json_str1, tokens, jsoneq_int_p, (void *) 23, 7, 0 )
          == 4
        );

  expect( json_find( json_str1, tokens, jsoneq_str_p, (void *) "Suzy", 7, 0 )
          == 2
        );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_jsmn_iterator_find_next( void )
{
  jsmn_iterator_t iterator;
  jsmntok_t *     id = NULL;
  jsmntok_t *     value = NULL;
  int             rsl  = 0;

  parse_json_str( json_str1, tokens, r );
  assert( r == 7 ); /* Use `assert' because we are not testing the parser */

  if ( jsmn_iterator_init( &iterator, tokens, r, 0 ) < 0 )
    expect( false && "Iterator initialization failed" );

  rsl = jsmn_iterator_find_next( json_str1,
                                 &iterator,
                                 &id,
                                 jsoneq_str_p,
                                 (void *) "name",
                                 &value,
                                 jsoneq_str_p,
                                 (void *) "Suzy",
                                 0
                               );
  expect( rsl == 1 );
  expect( jsoneq_str( json_str1, id, "name" ) );
  expect( jsoneq_str( json_str1, value, "Suzy" ) );

  rsl = jsmn_iterator_find_next( json_str1,
                                 &iterator,
                                 &id,
                                 jsoneq_str_p,
                                 (void *) "name",
                                 &value,
                                 jsoneq_str_p,
                                 (void *) "Suzy",
                                 value->start
                               );
  expect( rsl == 0 );

  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_json( void )
{
  bool rsl = true;
  rsl &= do_test( jsoneq );
  rsl &= do_test( jsoneq_typed );
  rsl &= do_test( jsmn_iterator_object );
  rsl &= do_test( jsmn_iterator_array );
  rsl &= do_test( jsmn_iterator_array_nested );
  rsl &= do_test( json_find );
  rsl &= do_test( jsmn_iterator_find_next );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
