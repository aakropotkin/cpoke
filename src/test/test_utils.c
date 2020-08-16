/* ========================================================================= */

#include <jsmn.h>
#include <json_utils.h>
#include <macros.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <test.h>

/* ------------------------------------------------------------------------- */


static const char
json_str1[] = "{"
                 "\"name\":       \"Suzy\""
              ",  \"age\":        23"
              ",  \"occupation\": \"mechanic\""
              "}";
static const size_t json_str1_len = array_size( json_str1 );
static const size_t json_str1_nts = 7;

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


static bool
test_jsoneq( void ) {

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


static bool
test_jsoneq_typed( void ) {

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


int
main( int argc, char * argv[], char ** envp ) {

  do_test( jsoneq );
  do_test( jsoneq_typed );

  return EXIT_SUCCESS;
}


/* ========================================================================= */
