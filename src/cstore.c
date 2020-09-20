/* -*- mode: c; -*- */

/* ========================================================================= */

#include "cstore.h"
#include "ext/uthash.h"
#include "moves.h"
#include "pokedex.h"
#include "store.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */

extern pdex_mon_t * POKEDEX[];
extern store_move_t MOVES[];
extern uint16_t     NUM_POKEMON;
extern uint16_t     NUM_MOVES;


/* ------------------------------------------------------------------------- */

  int
cstore_init( store_t * cstore, void * _unused_ )
{
  assert( cstore != NULL );
  cstore->aux = (void *) malloc( sizeof( cstore_aux_t ) );
  assert( cstore->aux != NULL );

  as_csa( cstore )->mons_by_name  = NULL;
  as_csa( cstore )->mons_cnt      = NUM_POKEMON;

  as_csa( cstore )->moves_by_name = NULL;
  as_csa( cstore )->moves_by_id   = NULL;
  as_csa( cstore )->moves_cnt     = NUM_MOVES;

  for ( int i = 0; i < NUM_POKEMON; i++ )
    {
      HASH_ADD_KEYPTR( hh_name,
                       as_csa( cstore )->mons_by_name,
                       POKEDEX[i]->name,
                       strlen( POKEDEX[i]->name ),
                       POKEDEX[i]
                     );
    }

  for ( int i = 0; i < NUM_MOVES; i++ )
    {
      HASH_ADD_KEYPTR( hh_name,
                       as_csa( cstore )->moves_by_name,
                       MOVES[i].name,
                       strlen( MOVES[i].name ),
                       &( MOVES[i] )
                     );
      HASH_ADD( hh_move_id,
                as_csa( cstore )->moves_by_id,
                move_id,
                sizeof( uint16_t ),
                &( MOVES[i] )
              );
    }

  return STORE_SUCCESS;
}


/* ------------------------------------------------------------------------- */

  void
cstore_free( store_t * cstore )
{
  assert( cstore != NULL );
  HASH_CLEAR( hh_name, as_csa( cstore )->mons_by_name );
  HASH_CLEAR( hh_name, as_csa( cstore )->moves_by_name );
  HASH_CLEAR( hh_move_id, as_csa( cstore )->moves_by_id );
  free( cstore->aux );
  cstore->aux = NULL;
}


/* ------------------------------------------------------------------------- */

  bool
cstore_has( store_t * cstore, store_key_t key )
{
  return STORE_ERROR_NOT_FOUND != cstore_get( cstore, key, NULL );
}


/* ------------------------------------------------------------------------- */

  int
cstore_get_pokemon( cstore_t   *  cstore,
                    uint16_t      dex_num,
                    uint8_t       form_idx,
                    pdex_mon_t ** val
                  )
{
  pdex_mon_t * mon = NULL;
  /**
   * Everything except for Meltan and Melmetal are perfectly sequential, and
   * their indices are simply their dex # - 1
   */
  if ( ( REGIONS[0].dex_start <= dex_num ) &&
       ( dex_num <= REGIONS[NUM_REGIONS - 2].dex_end )
     )
    {
      mon = POKEDEX[dex_num - 1];
    }
  else
    {
      mon = POKEDEX[dex_num - REGIONS[NUM_REGIONS - 1].dex_start
                            + REGIONS[NUM_REGIONS - 2].dex_end
                   ];
    }
  assert( dex_num == mon->dex_number );

  for ( uint8_t f = 0; f < form_idx; f++ )
    {
      if ( mon->next_form == NULL )
        {
          *val = NULL;
          return STORE_ERROR_NOT_FOUND;
        }
      mon = mon->next_form;
    }
  assert( form_idx == mon->form_idx );

  *val = mon;
  return STORE_SUCCESS;
}


/* ------------------------------------------------------------------------- */

  int
cstore_get_pokemon_by_name( store_t    *  cstore,
                            const char *  name,
                            pdex_mon_t ** val
                          )
{
  pdex_mon_t * mon = NULL;
  HASH_FIND( hh_name,
             as_csa( cstore )->mons_by_name,
             name,
             strlen( name ),
             mon
           );
  if ( val != NULL ) *val = mon;
  return ( mon != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
}


/* ------------------------------------------------------------------------- */

 int
cstore_get_move( store_t * cstore, uint16_t move_id, store_move_t ** val)
{
  store_move_t * move = NULL;
  HASH_FIND( hh_move_id,
             as_csa( cstore )->moves_by_id,
             & move_id,
             sizeof( uint16_t ),
             move
           );
  if ( val != NULL ) *val = move;
  return ( move != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
}


/* ------------------------------------------------------------------------- */

  int
cstore_get_move_by_name( store_t      *  cstore,
                         const char   *  name,
                         store_move_t ** val
                       )
{
  store_move_t * move = NULL;
  HASH_FIND( hh_name,
             as_csa( cstore )->moves_by_name,
             name,
             strlen( name ),
             move
           );
  if ( val != NULL ) *val = move;
  return ( move != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
}


/* ------------------------------------------------------------------------- */

  int
cstore_get( store_t * cstore, store_key_t key, void ** val )
{
  assert( cstore != NULL );

  if ( ( key.key_type == STORE_NUM  ) &&
       ( key.val_type == STORE_MOVE )
     )
    {
      return cstore_get_move( cstore,
                              key.data_h0,
                              (store_move_t **) val
                            );
    }
  else if ( ( key.key_type == STORE_NUM  )    &&
            ( key.val_type == STORE_POKEDEX )
          )
    {
      return cstore_get_pokemon( cstore,
                                 key.data_h0,
                                 key.data_q2,
                                 (pdex_mon_t **) val
                               );
    }
  return STORE_ERROR_BAD_VALUE;
}


/* ------------------------------------------------------------------------- */

  int
cstore_get_str( store_t * cstore, const char * str, void ** val )
{
  assert( cstore != NULL );

  pdex_mon_t   * mon;
  store_move_t * move;
  cstore_get_move_by_name( cstore, str, & move );
  if ( move != NULL )
    {
      if ( val != NULL ) *val = (void *) move;
      return STORE_SUCCESS;
    }
  cstore_get_pokemon_by_name( cstore, str, & mon );
  if ( mon != NULL )
    {
      if ( val != NULL ) *val = (void *) mon;
      return STORE_SUCCESS;
    }
  return STORE_ERROR_NOT_FOUND;
}


/* ------------------------------------------------------------------------- */

  int
cstore_get_str_t( store_t      *  cstore,
                  store_type_t    val_type,
                  const char   *  str,
                  void         ** val
                )
{
  assert( cstore != NULL );

  pdex_mon_t   * mon;
  store_move_t * move;

  if ( val_type == STORE_MOVE )
    {
      cstore_get_move_by_name( cstore, str, & move );
      if ( val != NULL ) *val = (void *) move;
      return ( move != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
    }

  if ( val_type == STORE_POKEDEX )
    {
      cstore_get_pokemon_by_name( cstore, str, & mon );
      if ( val != NULL ) *val = (void *) mon;
      return ( mon != NULL ) ? STORE_SUCCESS : STORE_ERROR_NOT_FOUND;
    }

  return STORE_ERROR_BAD_VALUE;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
