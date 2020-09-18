/* -*- mode: c; -*- */
/* ========================================================================= */

#include "util/curl_util.h"

/* ------------------------------------------------------------------------- */

const char GM_URL[] =
  "https://raw.githubusercontent.com/pokemongo-dev-contrib/"
  "pokemongo-game-master/master/versions/latest/V2_GAME_MASTER.json";

int
fetch_gm( const char * out_path ) {
  return (int) curltofile( GM_URL, out_path );
}


int
main( int argc, char * argv[], char ** envp ) {
  return fetch_gm( "data/GAME_MASTER.json" );
}


/* ========================================================================= */
/* vim: set filetype=c : */
