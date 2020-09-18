/* -*- mode: c; -*- */

#ifndef _ENCODER_H
#define _ENCODER_H

/* ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


/* ------------------------------------------------------------------------- *
 *
 * Formatters/writers to encode abstract data to various formats.
 * Should support encoding structs and primitives to JSON, C, and SQL.
 * Data should be wrapped in an "Abstract Data Type" ( ADT ) wrapper, to
 * abstract conversion to other languages/encodings.
 *
 * ( SQL is currently unsupported. Starting with C/JSON )
 *
 * ------------------------------------------------------------------------- */

typedef enum {
  ADT_NULL, ADT_CHAR, ADT_SIGNED, ADT_UNSIGNED, ADT_FLOAT, ADT_STRING, ADT_BOOL,
  ADT_STRUCT, ADT_LIST, ADT_FIELD, ADT_SYMBOL, ADT_BITFIELD, ADT_POINTER
} adtype_t;


struct adt_val_s {
  adtype_t    val_type;
  size_t      val_size;  /* Bytes for primitives, length for strings */
  void     ** val_ptr;   /* Points to value */
};
typedef struct adt_val_s  adt_val_t;


/* Struct field/value pair */
struct adt_member_s {
  char      * field_name;
  uint8_t     field_len;
  adt_val_t * val;
};
typedef struct adt_member_s  adt_member_t;


/* A struct/object */
struct adt_object_s {
  char         * obj_name;     /* struct foo_s { ... }; ==> "foo_s" */
  uint8_t        name_len;
  adt_member_t * members;
  uint8_t        members_cnt;
};
typedef struct adt_object_s  adt_object_t;


/* A value list */
struct adt_list_s {
  adtype_t     vals_type;  /* Use `ADT_NULL' for mixed/`void *' lists */
  adt_val_t  * vals;
  size_t       len;
};
typedef struct adt_list_s  adt_list_t;


/* ------------------------------------------------------------------------- */

typedef enum {
  ENC_C, ENC_JSON, ENC_SQL
} enc_target_t;


/* ------------------------------------------------------------------------- */

/**
 * Almost all of these use `malloc', so you should aim to only use them if you
 * need to post process something before it is written.
 * Strings are NULL terminated.
 *
 * THE CALLER IS RESPONSIBLE FOR FREEING THESE STRINGS.
 */

char * enc_prim_str_c( adt_val_t * val, const char * fmt );
char * enc_prim_str_json( adt_val_t * val, const char * fmt );
char * enc_prim_str_sql( adt_val_t * val, const char * fmt );

/**
 * Format string ( optional, use NULL to skip ) may be used to include
 * post-processing. A SINGLE `%s' will be repaced with the primitive.
 * Do not include any other un-escaped `printf' style `%' symbols!
 *  Ex: enc_prim_str( { ADT_SYMBOL, 3, "FOO" }, "int bar = %s_M;", ENC_C )
 *      ==> "int bar = FOO_M;"
 */
  char *
enc_prim_str( adt_val_t * val, const char * fmt, enc_target_t to )
{
  assert( val != NULL );
  assert( val->val_type != ADT_STRUCT );
  assert( val->val_type != ADT_LIST );
  assert( val->val_type != ADT_FIELD );
  assert( val->val_type != ADT_POINTER );

  switch( to )
    {
    case ENC_C:    return enc_prim_str_c( val, fmt );
    case ENC_JSON: return enc_prim_str_json( val, fmt );
    case ENC_SQL:  return enc_prim_str_sql( val, fmt );
    }
  return NULL;
}

  char *
enc_prim_str_c( adt_val_t * val, const char * fmt )
{
  assert( val != NULL );

  char * out       = NULL;
  size_t fmt_extra = ( fmt == NULL ) ? 0 : ( strlen( fmt ) - 2 );
  int    rsl       = 0;

  switch( val->val_type )
    {
    case ADT_NULL:
      out = (char *) malloc( sizeof( char ) * ( 4 + fmt_extra + 1 ) );
      assert( out != NULL );
      if ( fmt != NULL ) rsl = sprintf( out, fmt, "NULL" );
      else               rsl = ( strncpy( out, "NULL", 4 ) != NULL );
      assert( 0 < rsl );
      return out;

    case ADT_CHAR:
      out = (char *) malloc( sizeof( char ) * ( 2 + fmt_extra + 1 ) );
      assert( out != NULL );
      if ( fmt != NULL )
        {
          /* Convert to string */
          char buff[4] = { '\'', *( (char *) val->val_ptr ), '\'', '\0' };
          rsl = sprintf( out, fmt, buff );
          assert( 0 < rsl );
          return out;
        }
      else
        {
          out[0] = '\'';
          out[1] = *( (char *) val->val_ptr );
          out[2] = '\'';
          out[3] = '\0';
          return out;
        }

    case ADT_SIGNED:   return NULL;
    case ADT_UNSIGNED: return NULL;
    case ADT_FLOAT:    return NULL;
    case ADT_STRING:   return NULL;
    case ADT_BOOL:     return NULL;
    case ADT_SYMBOL:   return NULL;
    case ADT_BITFIELD: return NULL;
    }

  return NULL;
}




/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* encoder.h */

/* vim: set filetype=c : */
