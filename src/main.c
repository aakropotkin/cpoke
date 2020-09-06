/* -*- mode: c; -*- */
/* ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include "ptypes.h"
#include "moves.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pvp_action.h"
#include "battle.h"
#include <curl/curl.h>

#include "ai/pvpoke_ai.h"
/* Must come after AI implementation */
#include "ai/ai.h"
/* Must come after AI */
#include "player.h"

#include "util/json_util.h"


/* ------------------------------------------------------------------------- */

/* This is currently just used to check that headers conpile. */
  int
main( int argc, char * argv[], char ** envp )
{
  const char json_str3[] =
    "[ \"name\", \"Suzy\", \"age\", 23" ", \"occupation\", "
      "\"mechanic\", [ 1, 2, 3 ]"
    "]";
  const size_t json_str3_len = array_size( json_str3 );
  jsmntok_t tokens[11];
  jsmn_parser json_str3_parser;
  jsmn_init( & json_str3_parser );
  int r = jsmn_parse( & json_str3_parser,
                      json_str3,
                      json_str3_len,
                      tokens,
                      11
                    );


  return EXIT_SUCCESS;
}



/* ========================================================================= */
/* vim: set filetype=c : */
