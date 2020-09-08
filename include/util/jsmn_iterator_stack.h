/* -*- mode: c; -*- */

#ifndef _JSMN_ITERATOR_STACK_H
#define _JSMN_ITERATOR_STACK_H

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>


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


/* ------------------------------------------------------------------------- */

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


/* ------------------------------------------------------------------------- */

  static jsmn_iterator_t *
current_iterator( const jsmn_iterator_stack_t * iter_stack )
{
  //if ( ( iter_stack == NULL ) || ( iter_stack->stack == NULL ) ) return NULL;
  assert( iter_stack != NULL );
  assert( iter_stack->stack != NULL );
  return iter_stack->stack + iter_stack->stack_index;
}


/* ------------------------------------------------------------------------- */

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

      /* This explicitly indicates that the stack is empty when pushing */
      iter_stack->stack[0].jsmn_tokens = NULL;
      iter_stack->stack[0].jsmn_len    = 0;
      iter_stack->stack[0].parser_pos  = 0;
      iter_stack->stack[0].parent_pos  = 0;
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

  return 0;
}


/* ------------------------------------------------------------------------- */

  static void
jsmn_iterator_stack_free( jsmn_iterator_stack_t * iter_stack )
{
  if ( iter_stack != NULL )
    {
      free( iter_stack->stack );
      iter_stack->stack = NULL;
      free( iter_stack->is_object_flags );
      iter_stack->is_object_flags = false;
    }
}


/* ------------------------------------------------------------------------- */

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


/* ------------------------------------------------------------------------- */

#define jsmn_iterator_stack_position( _iterator_stack_ )        \
  jsmn_iterator_position( current_iterator( _iterator_stack_ ) )

//  static unsigned int
//jsmn_iterator_stack_position( jsmn_iterator_stack_t * iter_stack )
//{
//  return jsmn_iterator_position( current_iterator( iter_stack ) );
//}


/* ------------------------------------------------------------------------- */

  static jsmnitererr_t
jsmn_iterator_stack_push_curr( jsmn_iterator_stack_t * iter_stack )
{
  return jsmn_iterator_stack_push( iter_stack,
                                   jsmn_iterator_stack_position( iter_stack )
                                 );
}


/* ------------------------------------------------------------------------- */

  static int
jsmn_iterator_stack_pop( jsmn_iterator_stack_t * iter_stack )
{
  //if ( iter_stack == NULL ) return JSMNITER_ERR_PARAMETER;
  assert( iter_stack != NULL );

  /* Check for empty stack */
  //if ( ( iter_stack->stack_index == 0 ) &&
  //     ( iter_stack->stack[0].jsmn_tokens == NULL )
  //   ) return JSMNITER_ERR_PARAMETER;
  assert( ( iter_stack->stack_index != 0 ) ||
          ( iter_stack->stack[0].jsmn_tokens != NULL )
        );

  iter_stack->hint = jsmn_iterator_stack_position( iter_stack );

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
 * Pops until index <code>i</code> is reached.
 */
  static int
jsmn_iterator_stack_jump( jsmn_iterator_stack_t * iter_stack, unsigned short i )
{
  if ( ( iter_stack == NULL ) || ( iter_stack->stack_index <= i )
     ) return JSMNITER_ERR_PARAMETER;
  int rsl = 0;
  while ( i < iter_stack->stack_index )
    {
      rsl = jsmn_iterator_stack_pop( iter_stack );
      if ( rsl < 0 ) break;
    }
  return rsl;
}


/* ------------------------------------------------------------------------- */

#ifndef JSMN_ITERATOR_NO_SHORTNAMES

#define jsmnis_get_objp   get_is_object
#define jsmnis_set_objp   set_is_object
#define jsmnis_curr       current_iterator
#define jsmnis_init       jsmn_iterator_stack_init
#define jsmnis_free       jsmn_iterator_stack_free
#define jsmnis_pos        jsmn_iterator_stack_position
#define jsmnis_push       jsmn_iterator_stack_push
#define jsmnis_push_curr  jsmn_iterator_stack_push_curr
#define jsmnis_pop        jsmn_iterator_stack_pop
#define jsmnis_jump       jsmn_iterator_stack_jump

#endif

/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* jsmn_iterator_stack.h */

/* vim: set filetype=c : */
