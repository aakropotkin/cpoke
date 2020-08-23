/* -*- mode: c; -*- */

#ifndef _CURL_UTIL_H
#define _CURL_UTIL_H

/* ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

/* ------------------------------------------------------------------------- */

static size_t
write_to_file( void * src, size_t size, size_t nmemb, void * dest ) {
  return fwrite( src, size, nmemb, (FILE *) dest );
}


CURLcode
curltofile( const char * url, const char * out_path ) {
  CURLcode rsl;
  CURL *   curl_handle;
  FILE *   out_file;

  curl_global_init( CURL_GLOBAL_ALL );
  curl_handle = curl_easy_init();

  curl_easy_setopt( curl_handle, CURLOPT_URL, url );
  curl_easy_setopt( curl_handle, CURLOPT_NOPROGRESS, 1L );
  //curl_easy_setopt( curl_handle, CURLOPT_USERAGENT, "curl/7.71.1" );
  curl_easy_setopt( curl_handle, CURLOPT_MAXREDIRS, 50L );
  curl_easy_setopt( curl_handle, CURLOPT_TCP_KEEPALIVE, 1L );
  curl_easy_setopt( curl_handle, CURLOPT_WRITEFUNCTION, write_to_file );

  out_file = fopen( out_path, "wb" );
  if ( out_file != NULL ) {
    curl_easy_setopt( curl_handle, CURLOPT_WRITEDATA, out_file );
    rsl = curl_easy_perform( curl_handle );
    fclose( out_file );
  } else {
    rsl = -1;
  }

  curl_easy_cleanup( curl_handle );
  curl_global_cleanup();
  curl_handle = NULL;

  return rsl;
}


/* ========================================================================= */

#endif /* curl_util.h */

/* vim: set filetype=c : */
