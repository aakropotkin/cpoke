/* -*- mode: c; -*- */

#ifndef _JSON_UTIL_H
#define _JSON_UTIL_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include <regex.h>
#include <stdio.h>
#include <stdbool.h>


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

void free_jsmn_file_parser( jsmn_file_parser_t * parser );

/**
 * Initialize file parser, and read the target file into malloced memory; but
 * does not perform any parsing or allocation of tokens.
 *
 * @return Size of `buffer' allocated by malloc.
 */
size_t jsmn_file_parser_init( const char         * fpath,
                              jsmn_file_parser_t * f_parser
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
/**
 * <code>jsmntok_predicate_fn</code> form of <code>jsoneq</code>.
 */
  static bool
jsoneq_p( const char      * json,
          const jsmntok_t * token,
          void            * str
        )
{
  return jsoneq( json, token, (const char *) str );
}

/**
 * <code>jsmntok_predicate_fn</code> form of <code>jsoneq_str</code>.
 */
  static bool
jsoneq_str_p( const char      * json,
              const jsmntok_t * token,
              void            * str
            )
{
  return jsoneq_str( json, token, (const char *) str );
}

/**
 * <code>jsmntok_predicate_fn</code> form of <code>jsoneq_int</code>.
 */
  static bool
jsoneq_int_p( const char * json, const jsmntok_t * token, void * i )
{
  return jsoneq_int( json, token, (int) ( (long) i ) );
}

/**
 * <code>jsmntok_predicate_fn</code> form of <code>jsoneq_int</code>.
 */
  static bool
jsonmatch_str_p( const char * json, const jsmntok_t * token, void * r )
{
  return jsonmatch_str( json, token, (regex_t *) r );
}

/**
 * <code>jsmntok_predicate_fn</code> that unconditionally returns true.
 * Useful as value predicate when finding keys in objects.
 */
  static bool
json_true_p( const char * json, const jsmntok_t * token, void * p )
{
  return true;
}


/* ------------------------------------------------------------------------- */

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
  return jsmn_iterator_find_next( json,
                                  iterator,
                                  jsmn_identifier,
                                  identifier_pred,
                                  identifier_aux,
                                  jsmn_value,
                                  json_true_p,
                                  NULL,
                                  next_value_index
                                );
}


/* ------------------------------------------------------------------------- */

  static bool
json_iterator_has_key( const char      *  json,
                       jsmn_iterator_t *  iterator,
                       jsmntok_pred_fn    identifier_pred,
                       void            *  identifier_aux,
                       size_t             next_value_index
                     )
{
  jsmntok_t * jsmn_identifier;
  jsmntok_t * jsmn_value;
  return 0 != jsmn_iterator_find_key( json,
                                      iterator,
                                      &jsmn_identifier,
                                      identifier_pred,
                                      identifier_aux,
                                      &jsmn_value,
                                      next_value_index
                                    );
}



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* json_util.h */

/* vim: set filetype=c : */
