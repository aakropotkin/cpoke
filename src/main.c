/* -*- mode: c; -*- */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include "iv_rank.h"
#include "ptypes.h"
#include "util/bits.h"
#include "ai/ai.h"


/* -------------------------------------------------------------------------- */

/* This is currently just used to check that headers conpile. */
  int
main( int argc, char * argv[], char ** envp )
{

  dl_ai_t * dlai = dlopen_ai( "naive_ai.so" );
  dlai->ai->init( dlai->ai, NULL );
  printf( "Name: %s\n", dlai->ai->name );
  dlclose_ai( dlai );
  dlai = NULL;

  return EXIT_SUCCESS;
}



/* ========================================================================== */
/* vim: set filetype=c : */
