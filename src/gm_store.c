/* -*- mode: c; -*- */

/* ========================================================================= */

#include "gm_parser.h"
#include "moves.h"
#include "pokedex.h"
#include "store.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------- */

  int
gm_store_init( gm_store_t * gm_store, void * vgm_parser )
{
  assert( gm_store != NULL );
  assert( vgm_parser != NULL );

  gm_parser_t    * gm_parser = (gm_parser_t *) vgm_parser;

  gm_store->aux = (gm_store_aux_t) malloc( sizeof( gm_store_aux_t ) );
  assert( gm_store->aux != NULL );

  gm_store->name     = "Game Master";
  gm_store->writable = false;

  gm_store->aux->mons_by_name = vgm_parser->mons_by_name;
  gm_store->aux->mons_by_dex  = vgm_parser->mons_by_dex;
  gm_store->aux->mons_cnt     = HASH_COUNT( gm_store->aux->mons_by_name );
  assert( HASH_COUNT( gm_store->aux->mons_by_dex ) == gm_store->aux->mons_cnt );

  gm_store->aux->moves_by_name = vgm_parser->moves_by_name;
  gm_store->aux->moves_by_id   = vgm_parser->moves_by_id;
  gm_store->aux->moves_cnt     = HASH_COUNT( gm_store->aux->moves_by_name );
  assert( HASH_COUNT( gm_store->aux->moves_by_id ) ==
          gm_store->aux->moves_cnt
        );

  return STORE_SUCCESS;
}


/* ------------------------------------------------------------------------- */

  void
gm_store_free( gm_store_t * gm_store )
{
  /* Free the moves table */
  store_move_t * curr_move = NULL;
  store_move_t * tmp_move  = NULL;
  HASH_ITER( hh_name, gm_parser->moves_by_name, curr_move, tmp_move )
    {
      HASH_DELETE( hh_name, gm_parser->moves_by_name, curr_move );
      HASH_DELETE( hh_move_id, gm_parser->moves_by_id, curr_move );
      free( curr_move->name );
      free( curr_move );
    }
  /* Free Pokedex */
  pdex_mon_t * curr_mon = NULL;
  pdex_mon_t * tmp_mon  = NULL;
  HASH_ITER( hh_name, gm_parser->mons_by_name, curr_mon, tmp_mon )
    {
      HASH_DELETE( hh_name, gm_parser->mons_by_name, curr_mon );
      HASH_DELETE( hh_dex_num, gm_parser->mons_by_dex, curr_mon );
      pdex_mon_free( curr_mon );
    }
}


/* ------------------------------------------------------------------------- */

  bool
gm_store_has( gm_store_t * gm_store, store_key_t key )
{
  return STORE_NOTE_FOUND != gm_store_get( gm_store, key, NULL );
}


/* ------------------------------------------------------------------------- */

  int
gm_store_get( gm_store_t * gm_store, store_key_t key, void ** val )
{
  assert( gm_store != NULL );

  if ( as_gmsk( key ).is_move ) /* Move */
    {
      store_move_t * move = NULL;
      HASH_FIND( hh_move_id,
                 gm_store->aux->moves_by_id,
                 as_gmsk( key ).id,
                 sizeof( uint16_t ),
                 move
               );
      if ( val != NULL ) *val = (void *) move;
      if ( move != NULL ) return STORE_SUCCESS;
    }
  else /* Pokemon */
    {
      pdex_mon_t * mon = NULL;
      HASH_FIND( hh_move_id,
                 gm_store->aux->mons_by_id,
                 as_gmsk( key ).id,
                 sizeof( uint16_t ),
                 mon
               );
      if ( mon == NULL )
        {
          *val = NULL;
          return STORE_NOT_FOUND;
        }
      for ( uint8_t f = 0; f < as_gmsk( key ).form_idx; f++ )
        {
          if ( mon->next_form == NULL )
            {
              *val = NULL;
              return STORE_NOT_FOUND;
            }
          mon = mon->next_form;
        }
      *val = mon;
      return STORE_SUCCESS;
    }
}


/* ------------------------------------------------------------------------- */

  int
gm_store_add( gm_store_t * gm_store, store_key_t key, void * val )
{
  return STORE_ERROR_NOT_WRITABLE;
}

  int
gm_store_set( gm_store_t * gm_store, store_key_t key, void * val )
{
  return STORE_ERROR_NOT_WRITABLE;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
