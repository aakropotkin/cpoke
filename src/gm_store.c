/* -*- mode: c; -*- */

/* ========================================================================== */

#include "ext/uthash.h"
#include "defs/cstore_template.h"
#include "gm_store.h"
#include "moves.h"
#include "parse_gm.h"
#include "pokedex.h"
#include "store.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------- */

  int
gm_store_init( store_t * gm_store, void * vgm_parser )
{
  assert( gm_store != NULL );
  assert( vgm_parser != NULL );

  gm_parser_t * gm_parser = (gm_parser_t *) vgm_parser;

  gm_store->aux = (gm_store_aux_t *) malloc( sizeof( gm_store_aux_t ) );
  assert( gm_store->aux != NULL );

  as_gmsa( gm_store )->mons_by_name = gm_parser->mons_by_name;
  as_gmsa( gm_store )->mons_by_dex  = gm_parser->mons_by_dex;
  as_gmsa( gm_store )->mons_cnt =
    HASH_CNT( hh_name, as_gmsa( gm_store )->mons_by_name );
  assert( HASH_CNT( hh_dex_num, as_gmsa( gm_store )->mons_by_dex ) ==
                                as_gmsa( gm_store )->mons_cnt
        );

  as_gmsa( gm_store )->moves_by_name = gm_parser->moves_by_name;
  as_gmsa( gm_store )->moves_by_id   = gm_parser->moves_by_id;
  as_gmsa( gm_store )->moves_cnt =
    HASH_CNT( hh_name, as_gmsa( gm_store )->moves_by_name );
  assert( HASH_CNT( hh_move_id, as_gmsa( gm_store )->moves_by_id ) ==
                                as_gmsa( gm_store )->moves_cnt
        );

  return STORE_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  void
gm_store_free( store_t * gm_store )
{
  /* Free the moves table */
  store_move_t * curr_move = NULL;
  store_move_t * tmp_move  = NULL;
  HASH_ITER( hh_name, as_gmsa( gm_store )->moves_by_name, curr_move, tmp_move )
    {
      HASH_DELETE( hh_name, as_gmsa( gm_store )->moves_by_name, curr_move );
      HASH_DELETE( hh_move_id, as_gmsa( gm_store )->moves_by_id, curr_move );
      free( curr_move->name );
      free( curr_move );
    }
  HASH_CLEAR( hh_move_id, as_gmsa( gm_store )->moves_by_id );
  /* Free Pokedex */
  pdex_mon_t * curr_mon = NULL;
  pdex_mon_t * tmp_mon  = NULL;
  HASH_ITER( hh_name, as_gmsa( gm_store )->mons_by_name, curr_mon, tmp_mon )
    {
      HASH_DELETE( hh_name, as_gmsa( gm_store )->mons_by_name, curr_mon );
      HASH_DELETE( hh_dex_num, as_gmsa( gm_store )->mons_by_dex, curr_mon );
      pdex_mon_free( curr_mon );
    }
  HASH_CLEAR( hh_dex_num, as_gmsa( gm_store )->mons_by_dex );
  free( gm_store->aux );
}


/* -------------------------------------------------------------------------- */

  bool
gm_store_has( store_t * gm_store, store_key_t key )
{
  return STORE_ERROR_NOT_FOUND != gm_store_get( gm_store, key, NULL );
}


/* -------------------------------------------------------------------------- */

  int
gm_store_get_pokemon( gm_store_t *  gm_store,
                      uint16_t      dex_num,
                      uint8_t       form_idx,
                      pdex_mon_t ** val
                      )
{
  pdex_mon_t * mon = NULL;
  HASH_FIND( hh_dex_num,
             as_gmsa( gm_store )->mons_by_dex,
             & dex_num,
             sizeof( uint16_t ),
             mon
           );

  if ( mon == NULL )
    {
      *val = NULL;
      return STORE_ERROR_NOT_FOUND;
    }

  for ( uint8_t f = 0; f < form_idx; f++ )
    {
      if ( mon->next_form == NULL )
        {
          *val = NULL;
          return STORE_ERROR_NOT_FOUND;
        }
      mon = mon->next_form;
    }

  *val = mon;
  return STORE_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_get_pokemon_by_name( gm_store_t *  gm_store,
                              const char *  name,
                              pdex_mon_t ** val
                            )
{
  pdex_mon_t * mon = NULL;
  HASH_FIND( hh_name,
             as_gmsa( gm_store )->mons_by_name,
             name,
             strlen( name ),
             mon
           );
  if ( val != NULL ) *val = mon;
  return ( mon != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
}


/* -------------------------------------------------------------------------- */

 int
gm_store_get_move( gm_store_t   *  gm_store,
                   uint16_t        move_id,
                   store_move_t ** val
                 )
{
  store_move_t * move = NULL;
  HASH_FIND( hh_move_id,
             as_gmsa( gm_store )->moves_by_id,
             & move_id,
             sizeof( uint16_t ),
             move
           );
  if ( val != NULL ) *val = move;
  return ( move != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_get_move_by_name( gm_store_t   *  gm_store,
                           const char   *  name,
                           store_move_t ** val
                         )
{
  store_move_t * move = NULL;
  HASH_FIND( hh_name,
             as_gmsa( gm_store )->moves_by_name,
             name,
             strlen( name ),
             move
           );
  if ( val != NULL ) *val = move;
  return ( move != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_get( store_t * gm_store, store_key_t key, void ** val )
{
  assert( gm_store != NULL );

  if ( ( as_gmsk( key ).key_type == STORE_NUM  ) &&
       ( as_gmsk( key ).val_type == STORE_MOVE )
     )
    {
      return gm_store_get_move( gm_store,
                                as_gmsk( key ).id,
                                (store_move_t **) val
                              );
    }
  else if ( ( as_gmsk( key ).key_type == STORE_NUM  )    &&
            ( as_gmsk( key ).val_type == STORE_POKEDEX )
          )
    {
      return gm_store_get_pokemon( gm_store,
                                   as_gmsk( key ).id,
                                   as_gmsk( key ).form_idx,
                                   (pdex_mon_t **) val
                                 );
    }
  return STORE_ERROR_BAD_VALUE;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_get_str( store_t * gm_store, const char * str, void ** val )
{
  assert( gm_store != NULL );

  pdex_mon_t   * mon;
  store_move_t * move;
  gm_store_get_move_by_name( gm_store, str, & move );
  if ( move != NULL )
    {
      if ( val != NULL ) *val = (void *) move;
      return STORE_SUCCESS;
    }
  gm_store_get_pokemon_by_name( gm_store, str, & mon );
  if ( mon != NULL )
    {
      if ( val != NULL ) *val = (void *) mon;
      return STORE_SUCCESS;
    }
  return STORE_ERROR_NOT_FOUND;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_get_str_t( store_t      *  gm_store,
                    store_type_t    val_type,
                    const char   *  str,
                    void         ** val
                  )
{
  assert( gm_store != NULL );

  pdex_mon_t   * mon;
  store_move_t * move;

  if ( val_type == STORE_MOVE )
    {
      gm_store_get_move_by_name( gm_store, str, & move );
      if ( val != NULL ) *val = (void *) move;
      return ( move != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
    }

  if ( val_type == STORE_POKEDEX )
    {
      gm_store_get_pokemon_by_name( gm_store, str, & mon );
      if ( val != NULL ) *val = (void *) mon;
      return ( mon != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
    }

  return STORE_ERROR_BAD_VALUE;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_export_json( gm_store_t * gm_store, FILE * ostream )
{
  pdex_mon_t   * curr_mon;
  pdex_mon_t   * tmp_mon;
  store_move_t * curr_move;
  store_move_t * tmp_move;

  fprintf( ostream, "{ \"pokedex\": [ " );
  HASH_ITER( hh_dex_num,
             as_gmsa( gm_store )->mons_by_dex,
             curr_mon,
             tmp_mon
           )
    {
      fprint_pdex_mon_json( ostream, curr_mon );
      if ( tmp_mon != NULL ) fprintf( ostream, ", " );
    }

  fprintf( ostream, "\n],\n  \"moves\": [ " );
  HASH_ITER( hh_move_id,
             as_gmsa( gm_store )->moves_by_id,
             curr_move,
             tmp_move
           )
    {
      fprint_store_move_json( ostream, curr_move );
      if ( tmp_move != NULL ) fprintf( ostream, ", " );
    }
  fprintf( ostream, " ]\n}" );

  return STORE_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_export_c( gm_store_t * gm_store, FILE * ostream )
{
  pdex_mon_t   * curr_mon  = NULL;
  pdex_mon_t   * tmp_mon   = NULL;
  store_move_t * curr_move = NULL;
  store_move_t * tmp_move  = NULL;

  fprintf( ostream, "/* -*- mode: c; -*- */\n\n%s\n", EQSEP );
  fprintf( ostream, "%s\n\n%s\n\n", INCLUDES, DASHSEP );
  fprintf( ostream,
           "const uint16_t NUM_POKEMON = %u;\n\n",
           as_gmsa( gm_store )->mons_cnt
         );
  fprintf( ostream,
           "const uint16_t NUM_MOVES = %u;\n\n",
           as_gmsa( gm_store )->moves_cnt
         );

  fprintf( ostream, "\n%s\n\n", DASHSEP );

  fprintf( ostream, "store_move_t MOVES[] = {\n" );
  /* Define Moves */
  HASH_ITER( hh_move_id, as_gmsa( gm_store )->moves_by_id, curr_move, tmp_move )
    {
      fprint_store_move_c( ostream, curr_move );
      if ( tmp_move != NULL ) fprintf( ostream, ", " );
    }
  fprintf( ostream, "};\n" );

  fprintf( ostream, "\n%s\n\n", DASHSEP );

  /* Define Pokemon */
  HASH_ITER( hh_dex_num, as_gmsa( gm_store )->mons_by_dex, curr_mon, tmp_mon )
    {
      fprint_pdex_mon_c( ostream, curr_mon );
      fprintf( ostream, ";\n" );
    }

  fprintf( ostream, "\n%s\n\n", DASHSEP );

  /* Create Pokedex from Pokemon */
  fprintf( ostream, "\npdex_mon_t * POKEDEX[] = {\n" );
  HASH_ITER( hh_dex_num, as_gmsa( gm_store )->mons_by_dex, curr_mon, tmp_mon )
    {
      fprintf( ostream, "  & DEXMON_%u_0", curr_mon->dex_number );
      if ( tmp_mon != NULL ) fprintf( ostream, ",\n" );
    }
  fprintf( ostream, "\n};\n\n\n%s\n\n/* vim: set filetype=c : */\n", EQSEP );

  return STORE_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_export_sql( gm_store_t * gm_store, const char * db_name )
{
  return STORE_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  int
gm_store_export( gm_store_t   * gm_store,
                 store_sink_t   sink_type,
                 void         * target
               )
{
  switch( sink_type )
    {
    case SS_JSON: return gm_store_export_json( gm_store, (FILE *) target );
    case SS_C:    return gm_store_export_c( gm_store, (FILE *) target );
    case SS_SQL:  return gm_store_export_sql( gm_store, (const char *) target );
    default:      return STORE_ERROR_NOT_DEFINED;
    }
}

/* -------------------------------------------------------------------------- */

  int
gm_store_add( store_t * gm_store, store_key_t key, void * val )
{
  return STORE_ERROR_NOT_WRITABLE;
}

  int
gm_store_set( store_t * gm_store, store_key_t key, void * val )
{
  return STORE_ERROR_NOT_WRITABLE;
}


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
