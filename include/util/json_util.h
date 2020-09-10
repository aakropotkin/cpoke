/* -*- mode: c; -*- */

#ifndef _JSON_UTIL_H
#define _JSON_UTIL_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/* ------------------------------------------------------------------------- */

typedef struct jsmn_parser jsmn_parser_t;


/**
 * Reallocating jsmn_parse wrapper; like getline(3).  This currently
 * operates in a naive double-on-fail way, and so it calls
 * jsmn_init(parser) for you.
 *
 * If (*tokens) is NULL, jsmn_parse_realloc will malloc a buffer which
 * should be freed by the caller; unless it remains NULL due to
 * insufficient memory.  num_tokens is ignored.  Don't forget to reset
 * (*tokens)=NULL after freeing, before parsing again.
 *
 * Otherwise, (*tokens) must be a buffer from malloc and (*num_tokens)
 * shall be its size in sizeof(jsmntok_t).  If it is realloc(3)'d,
 * both (*tokens) and (*num_tokens) will be updated.
 *
 * Returns JSMN_ERROR_NOMEM only when malloc or realloc fail.
 */
jsmnerr_t jsmn_parse_realloc( jsmn_parser_t *  parser,
                              const char    *  js,
                              size_t           len,
                              jsmntok_t     ** tokens,
                              size_t        *  num_tokens
                            );


/* ------------------------------------------------------------------------- */

/**
 * Wrap a JSMN parser to read from a file.
 */
typedef struct {
  char          * fpath;
  char          * buffer;
  size_t          buffer_len;
  jsmn_parser_t   jparser;
  jsmntok_t     * tokens;
  size_t          tokens_cnt;
} jsmn_file_parser_t;

void jsmn_file_parser_free( jsmn_file_parser_t * parser );

/**
 * Initialize file parser, and read the target file into malloced memory; but
 * does not perform any parsing or allocation of tokens.
 *
 * @return Size of `buffer' allocated by malloc.
 */
size_t jsmn_file_parser_init( jsmn_file_parser_t * f_parser,
                              const char         * fpath
                            );


/* ------------------------------------------------------------------------- */

/**
 * Calculate the length of a token.
 *
 * @param token    Token to calculate the length of.
 * @return         The string length of a token.
 */
size_t toklen( const jsmntok_t * token );


/* ------------------------------------------------------------------------- */

/**
 * Print a token to file descriptor <code>stream</code>.
 *
 * @param stream    File descriptor to print to.
 * @param json      Beginning of JSON string used to produce <code>token</code>.
 * @param token     Token to be printed.
 * @return          The number of characters printed.
 */
int fprint_tok( FILE * stream, const char * json, const jsmntok_t * token );
int print_tok( const char * json, const jsmntok_t * token );


/* ------------------------------------------------------------------------- */

bool jsoneq( const char * json, const jsmntok_t * token, const char * str );
bool jsoneq_str( const char * json, const jsmntok_t * token, const char * str );
bool jsoneq_int( const char * json, const jsmntok_t * token, const int i );


/* ------------------------------------------------------------------------- */

bool jsonmatch_str( const char      * json,
                    const jsmntok_t * token,
                    regex_t         * regex
                  );


/* ------------------------------------------------------------------------- */

/**
 * Predicate function operating on JSMN tokens.
 * To be used for filters/finders.
 * Wrapped <code>jsoneq</code> functions that cast <code>void *</code> are
 * perfect examples.
 */
typedef bool ( * jsmntok_pred_fn )( const char      *,
                                    const jsmntok_t *,
                                    void            *
                                  );

static bool jsoneq_p( const char * json, const jsmntok_t * token, void * str )
{ return jsoneq( json, token, (const char *) str ); }

static bool jsoneq_str_p( const char * json, const jsmntok_t * token,
                          void * str )
{ return jsoneq_str( json, token, (const char *) str ); }

static bool jsoneq_int_p( const char * json, const jsmntok_t * token, void * i )
{ return jsoneq_int( json, token, (int) ( (long) i ) ); }

static bool jsonmatch_str_p( const char * json, const jsmntok_t * token,
                             void * r )
{ return jsonmatch_str( json, token, (regex_t *) r ); }

/**
 * <code>jsmntok_predicate_fn</code> that unconditionally returns true.
 * Useful as value predicate when finding keys in objects.
 */
  static bool
json_true_p( const char * json, const jsmntok_t * token, void * p )
{ return true; }


/* ------------------------------------------------------------------------- */

/**
 * Return the index of the first token which satisfies the provided predicate.
 * Searching will begin at <code>parser_pos</code>, allowing additional
 * satisfactory tokens to be found.
 */
int json_find( const char      * json,
               const jsmntok_t * tokens,
               jsmntok_pred_fn   pred,
               void            * aux,
               size_t            jsmn_len,
               size_t            parser_pos
             );


/* ------------------------------------------------------------------------- */

/**
 * Find the next <code>jsmn_iterator_t</code> element that matches the provided
 * predicate functions.
 */
int jsmn_iterator_find_next( const char      *  json,
                             jsmn_iterator_t *  iterator,
                             jsmntok_t       ** jsmn_identifier,
                             jsmntok_pred_fn    identifier_pred,
                             void            *  identifier_aux,
                             jsmntok_t       ** jsmn_value,
                             jsmntok_pred_fn    value_pred,
                             void            *  value_aux,
                             size_t             next_value_index
                           );


/* ------------------------------------------------------------------------- */

/**
 * Find the next matching key. Agnostic to values.
 */
  static int
jsmn_iterator_find_key( const char      *  json,
                        jsmn_iterator_t *  iterator,
                        jsmntok_t       ** jsmn_identifier,
                        jsmntok_pred_fn    identifier_pred,
                        void            *  identifier_aux,
                        jsmntok_t       ** jsmn_value,
                        size_t             next_value_index
                      )
{
  return jsmn_iterator_find_next( json, iterator, jsmn_identifier,
           identifier_pred, identifier_aux, jsmn_value, json_true_p, NULL,
           next_value_index );
}


/* ------------------------------------------------------------------------- */

/**
 * Find the next matching key which exactly matches the provided string.
 */
  static int
jsmn_iterator_find_key_seq( const char      *  json,
                            jsmn_iterator_t *  iterator,
                            jsmntok_t       ** jsmn_identifier,
                            const char      *  str,
                            jsmntok_t       ** jsmn_value,
                            size_t             next_value_index
                            )
{
  return jsmn_iterator_find_next( json, iterator, jsmn_identifier, jsoneq_str_p,
           (void *) str, jsmn_value, json_true_p, NULL, next_value_index );
}


/* ------------------------------------------------------------------------- */

/**
 * Returns true/false if an iterator's remaining tokens contain a
 * satisfactory key.
 * The iterator is NOT changed and remains in it's original position.
 */
  static bool
jsmn_iterator_has_key( const char      *  json,
                       jsmn_iterator_t *  iterator,
                       jsmntok_pred_fn    identifier_pred,
                       void            *  identifier_aux,
                       size_t             next_value_index
                     )
{
  jsmntok_t * jsmn_identifier, * jsmn_value;
  jsmn_iterator_t cpy;
  memcpy( &cpy, iterator, sizeof( jsmn_iterator_t ) );
  return 0 != jsmn_iterator_find_key( json, &cpy, &jsmn_identifier,
                identifier_pred, identifier_aux, &jsmn_value,
                next_value_index );
}


/* ------------------------------------------------------------------------- */

/**
 * For exact string matches.
 */
  static bool
jsmn_iterator_has_key_seq( const char      * json,
                           jsmn_iterator_t * iterator,
                           char            * str,
                           size_t            next_value_index
                         )
{
  jsmntok_t * jsmn_identifier, * jsmn_value;
  jsmn_iterator_t cpy;
  memcpy( &cpy, iterator, sizeof( jsmn_iterator_t ) );
  return 0 != jsmn_iterator_find_key( json, &cpy, &jsmn_identifier,
                jsoneq_str_p, (void *) str, &jsmn_value, next_value_index );
}


/* ------------------------------------------------------------------------- */

#define jsmn_iterator_while_using( _nxt_fn_, _iter_, _key_, _val_, _hint_ ) \
  while( 0 < _nxt_fn_( ( _iter_ ), ( _key_ ), ( _val_ ), ( _hint_ ) ) )

#define jsmn_iterator_while( _iter_, _key_, _val_, _hint_ )             \
  jsmn_iterator_while_using( jsmn_iterator_next, ( _iter_ ), ( _key_ ), \
                             ( _val_ ), ( _hint_ ) )

#define jsmn_iterator_array_while( _iter_, _val_, _hint_ )        \
  jsmn_iterator_while( ( _iter_ ), NULL, ( _val_ ), ( _hint_ ) )


/* ------------------------------------------------------------------------- */

/**
 * Count remaining matches in the iterator.
 * Iterator is unchanged by this function.
 */
  static size_t
jsmn_iterator_count( const char      *  json,
                     jsmn_iterator_t *  iterator,
                     jsmntok_pred_fn    identifier_pred,
                     void            *  identifier_aux,
                     jsmntok_pred_fn    value_pred,
                     void            *  value_aux,
                     size_t             next_value_index
                   )
  {
    jsmntok_t * jsmn_identifier, * jsmn_value;
    jsmn_iterator_t cpy;
    size_t matches = 0;
    memcpy( &cpy, iterator, sizeof( jsmn_iterator_t ) );
    while ( 0 < jsmn_iterator_find_next( json,  &cpy, &jsmn_identifier,
            identifier_pred, identifier_aux, &jsmn_value, value_pred, value_aux,
            next_value_index ) ) matches++;
    return matches;
  }


/* ------------------------------------------------------------------------- */

/**
 * Count remaining keys in the iterator matching a regex expression.
 * Iterator is unchanged by this function.
 */
  static size_t
jsmn_iterator_count_keys_pat( const char      *  json,
                              jsmn_iterator_t *  iterator,
                              regex_t         *  regexp,
                              size_t             next_value_index
                            )
{
  return jsmn_iterator_count( json, iterator, jsonmatch_str_p, (void *) regexp,
                              json_true_p, NULL, next_value_index );
}


/* ------------------------------------------------------------------------- */

#ifndef JSMN_ITERATOR_NO_SHORTNAMES

typedef jsmn_iterator_t      jsmni_t;
#define jsmni_find_last      jsmn_iterator_find_last
#define jsmni_init           jsmn_iterator_init
#define jsmni_next           jsmn_iterator_next
#define jsmni_pos            jsmn_iterator_position
#define jsmni_find_next      jsmn_iterator_find_next
#define jsmni_find_key       jsmn_iterator_find_key
#define jsmni_has_key        jsmn_iterator_has_key
#define jsmni_find_key_seq   jsmn_iterator_find_key_seq
#define jsmni_has_key_seq    jsmn_iterator_has_key_seq
#define jsmni_while_using    jsmn_iterator_while_using
#define jsmni_while          jsmn_iterator_while
#define jsmni_a_while        jsmn_iterator_array_while

#endif


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* json_util.h */

/* vim: set filetype=c : */
