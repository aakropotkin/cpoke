/* -*- mode: c; -*- */

/* ========================================================================= */

#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "files.h"

/* ------------------------------------------------------------------------- */

  bool
file_exists( const char * fpath )
{
  assert( fpath != NULL );
  struct stat st;
  int         status = stat( fpath, &st );
  return ( status == 0 );
}


/* ------------------------------------------------------------------------- */

  long
file_size( const char * fpath )
{
  assert( fpath != NULL );
  struct stat st;
  int         status = stat( fpath, &st );  /* 0 --> File Exists */
  if ( status != 0 )
    {
      perror( __func__ );
      return -1;
    }
  return (long) st.st_size;
}


/* ------------------------------------------------------------------------- */

  size_t
fread_malloc( const char * fpath, char ** buffer )
{
  assert( buffer != NULL );
  assert( fpath != NULL );

  long   fsize      = file_size( fpath );
  FILE * fd         = NULL;
  size_t read_chars = 0;

  if ( fsize == -1 ) return 0;
  (* buffer) = (char *) malloc( sizeof( char ) * fsize );
  if ( (* buffer) == NULL )
    { /* Check for malloc failure. */
      perror( __func__ );
      return 0;
    }
  fd = fopen( fpath, "r" );
  if ( fd == NULL )
    { /* Check for fopen failure. */
      perror( __func__ );
      free( * buffer );
      return 0;
    }
  read_chars = fread( (* buffer), sizeof( char ), (size_t) fsize, fd );
  fclose( fd );
  /* Confirm full file was read. */
  if ( ( (long) read_chars ) != fsize )
    {
      fprintf( stderr,
              "%s: Only read %zu/%ld characters of file '%s'.\n",
              __func__,
              read_chars,
              fsize,
              fpath
            );
      free( * buffer );
      return 0;
    }
  return read_chars;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
