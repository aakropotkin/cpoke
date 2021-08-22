/* -*- mode: c; -*- */

/* ========================================================================== */

#include <assert.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include "ai/ai.h"

/* -------------------------------------------------------------------------- */

#define DLAI_LOAD_SYM( _DLAI, _SYM )  \
  *(void **) (& _DLAI->ai->_SYM) = dlsym( _DLAI->handle, "ai_" # _SYM ); \
  assert( _DLAI->ai->_SYM != NULL )

  dl_ai_t *
dlopen_ai( const char * filename )
{
  dl_ai_t * dlai = (dl_ai_t *) malloc( sizeof( dl_ai_t ) );
  assert( dlai != NULL );
  dlai->ai = (ai_t *) malloc( sizeof( ai_t ) );
  assert( dlai->ai != NULL );

  dlai->handle = dlopen( filename, RTLD_NOW|RTLD_LOCAL );
  assert( dlai->handle != NULL );  /* FIXME: Do real error handling */

  char ** dlai_name = (char **) dlsym( dlai->handle, "ai_name" );
  assert( dlai_name != NULL );
  assert( ( * dlai_name ) != NULL );

  dlai->ai->name = strndup( ( * dlai_name ), 1024 );
  assert( dlai->ai->name != NULL );

  *(void **) (& dlai->ai->select_team) = dlsym( dlai->handle,
                                                "ai_select_team"
                                              );
  assert( dlai->ai->select_team != NULL );

  DLAI_LOAD_SYM( dlai, decide_action );
  DLAI_LOAD_SYM( dlai, decide_swap );
  DLAI_LOAD_SYM( dlai, decide_shield );
  DLAI_LOAD_SYM( dlai, init );
  DLAI_LOAD_SYM( dlai, free );

  dlai->ai->aux = NULL;

  return dlai;
}

#undef DLAI_LOAD_SYM

/* -------------------------------------------------------------------------- */

  int
dlclose_ai( dl_ai_t * dlai )
{
  int rsl = -1;

  assert( dlai != NULL );

  free( dlai->ai->name );
  dlai->ai->name = NULL;

  /* Likely frees `ai.aux' */
  dlai->ai->free( dlai->ai );

  free( dlai->ai );
  dlai->ai = NULL;

  rsl = dlclose( dlai->handle );

  free( dlai );
  dlai = NULL;

  return rsl;
}


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
