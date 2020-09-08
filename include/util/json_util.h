/* -*- mode: c; -*- */

#ifndef _JSON_UTIL_H
#define _JSON_UTIL_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


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

typedef jsmn_iterator_t  jsmn_stacked_iterator_t;
#define jsmn_stacked_iterator_init  jsmn_iterator_init

struct jsmn_iterator_stack_s {
  jsmntok_t               * tokens;
  jsmn_stacked_iterator_t * stack;
  unsigned long           * is_object_flags;
  unsigned short            stack_size;
  unsigned short            stack_index;
  unsigned int              jsmn_len;
  unsigned int              hint;
};

typedef struct jsmn_iterator_stack_s  jsmn_iterator_stack_t;

static const size_t IS_OBJ_NUM_BITS = sizeof( unsigned long ) * 8;

  static bool
get_is_object( const jsmn_iterator_stack_t * iter_stack, unsigned int idx )
{
  assert( iter_stack != NULL );
  assert( idx <= iter_stack->stack_index );
  return ( iter_stack->is_object_flags[idx / IS_OBJ_NUM_BITS] >>
             ( idx % IS_OBJ_NUM_BITS )
         ) & 1;
}

  static jsmnitererr_t
set_is_object( jsmn_iterator_stack_t * iter_stack, unsigned int idx, bool val )
{
  if ( ( iter_stack == NULL ) || ( iter_stack->stack_index < idx )
     ) return JSMNITER_ERR_PARAMETER;
  iter_stack->is_object_flags[idx / IS_OBJ_NUM_BITS] &=
    ~( 1 << ( idx % IS_OBJ_NUM_BITS ) );
  iter_stack->is_object_flags[idx / IS_OBJ_NUM_BITS] |=
    ( 1 << ( idx % IS_OBJ_NUM_BITS ) );
}

  static jsmnitererr_t
jsmn_iterator_stack_init( jsmn_iterator_stack_t * iter_stack,
                          jsmntok_t             * tokens,
                          unsigned int            jsmn_len,
                          unsigned short          stack_size
                        )
{
  if ( ( iter_stack == NULL ) || ( tokens == NULL )
     ) return JSMNITER_ERR_PARAMETER;

  if ( 0 < stack_size )
    {
      /* This explicitly indicates that the stack is empty when pushing */
      iter_stack->stack[0].jsmn_tokens = NULL;

      /* Allocate stack space */
      iter_stack->stack =
        (jsmn_stacked_iterator_t *) malloc( sizeof( jsmn_stacked_iterator_t ) *
                                              stack_size
                                          );
      if ( iter_stack->stack == NULL ) return JSMN_ERROR_NOMEM;

      /* Allocate flag space */
      size_t want_num_flags_bytes = ( ( stack_size / IS_OBJ_NUM_BITS ) +
                                      ( !!( stack_size % IS_OBJ_NUM_BITS ) )
                                    ) * sizeof( unsigned long );
      iter_stack->is_object_flags =
        (unsigned long *) malloc( want_num_flags_bytes );
      if ( iter_stack->is_object_flags == NULL )
        {
          free( iter_stack->stack );
          return JSMN_ERROR_NOMEM;
        }
    }
  else
    {
      iter_stack->stack           = NULL;
      iter_stack->is_object_flags = NULL;
    }
  iter_stack->tokens     = tokens;
  iter_stack->jsmn_len   = jsmn_len;
  iter_stack->stack_size = stack_size;
  iter_stack->hint       = 0;
}

  static void
jsmn_iterator_stack_free( jsmn_iterator_stack_t * iter_stack )
{
  if ( iter_stack != NULL )
    {
      free( iter_stack->stack );
      free( iter_stack->is_object_flags );
    }
}

  static jsmnitererr_t
jsmn_iterator_stack_push( jsmn_iterator_stack_t * iter_stack,
                          unsigned int            parser_pos
                        )
{
  if ( ( iter_stack == NULL ) || ( iter_stack->jsmn_len <= parser_pos )
     ) return JSMNITER_ERR_PARAMETER;

  if ( !( ( iter_stack->tokens[parser_pos].type == JSMN_ARRAY ) ||
          ( iter_stack->tokens[parser_pos].type == JSMN_OBJECT ) )
     ) return JSMNITER_ERR_TYPE;

  /* Check if allocation is required */
  if ( iter_stack->stack_size <= iter_stack->stack_index )
    {
      /* Catches cases where a 0 size or very small stack was
       * originally allocated */
      unsigned int want_num_iters = 2 * ( iter_stack->stack_size );
      if ( want_num_iters < 4 ) want_num_iters = 4;

      size_t want_num_flags_bytes = ( ( want_num_iters/ IS_OBJ_NUM_BITS ) +
                                      ( !!( want_num_iters % IS_OBJ_NUM_BITS ) )
                                    ) * sizeof( unsigned long );

      jsmn_stacked_iterator_t * new_stack = NULL;
      unsigned long           * new_flags = NULL;

      /* Reallocate if we had an existing stack, otherwise malloc */
      if ( iter_stack->stack == NULL )
        {
          new_stack = malloc( want_num_iters *
                                sizeof( jsmn_stacked_iterator_t )
                            );
        }
      else
        {
          new_stack = realloc( iter_stack->stack,
                               want_num_iters *
                                 sizeof( jsmn_stacked_iterator_t )
                             );
        }
      if ( new_stack == NULL ) return JSMN_ERROR_NOMEM;

      /* (Re)Allocate Flags */
      if ( iter_stack->is_object_flags == NULL )
        {
          new_flags = malloc( want_num_flags_bytes );
        }
      else
        {
          new_flags = realloc( iter_stack->is_object_flags,
                               want_num_flags_bytes
                             );
        }
      if ( new_flags == NULL )
        {
          free( new_stack );
          return JSMN_ERROR_NOMEM;
        }

      iter_stack->stack_size      = want_num_iters;
      iter_stack->stack           = new_stack;
      iter_stack->is_object_flags = new_flags;
    }

  /* First push is a special case */
  if ( !( ( iter_stack->stack_index == 0 ) &&
          ( iter_stack->stack[0].jsmn_tokens == NULL )
        )
     ) iter_stack->stack_index++;

  set_is_object( iter_stack,
                 iter_stack->stack_index,
                 ( iter_stack->tokens[parser_pos].type == JSMN_OBJECT )
               );

  return jsmn_stacked_iterator_init( iter_stack->stack +
                                       iter_stack->stack_index,
                                     iter_stack->tokens,
                                     iter_stack->jsmn_len,
                                     parser_pos
                                   );
}


  static int
jsmn_iterator_stack_pop( jsmn_iterator_stack_t * iter_stack )
{
  if ( iter_stack == NULL ) return JSMNITER_ERR_PARAMETER;

  /* Check for empty stack */
  if ( ( iter_stack->stack_index == 0 ) &&
       ( iter_stack->stack[0].jsmn_tokens == NULL )
     ) return JSMNITER_ERR_PARAMETER;

  iter_stack->hint =
    jsmn_iterator_position( &iter_stack->stack[iter_stack->stack_index] );

  /* Clear stacked iterator's contents.
   * The `jsmn_tokens' member MUST be set to null for pushing to work properly,
   * other members don't necessarily need to be reset if you want to save time.
   */
  iter_stack->stack[iter_stack->stack_index].jsmn_len    = 0;
  iter_stack->stack[iter_stack->stack_index].parent_pos  = 0;
  iter_stack->stack[iter_stack->stack_index].parser_pos  = 0;
  iter_stack->stack[iter_stack->stack_index].index       = 0;
  /* Mandatory to clear this `jsmn_tokens' */
  iter_stack->stack[iter_stack->stack_index].jsmn_tokens = NULL;

  if ( 0 < iter_stack->stack_index ) iter_stack->stack_index--;

  return iter_stack->hint;
}



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
