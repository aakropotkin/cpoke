/* -*- mode: c; -*- */

/* ========================================================================= */

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

/* ------------------------------------------------------------------------- */

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


/* ------------------------------------------------------------------------- */

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
  /* Free Pokedex */
  pdex_mon_t * curr_mon = NULL;
  pdex_mon_t * tmp_mon  = NULL;
  HASH_ITER( hh_name, as_gmsa( gm_store )->mons_by_name, curr_mon, tmp_mon )
    {
      HASH_DELETE( hh_name, as_gmsa( gm_store )->mons_by_name, curr_mon );
      HASH_DELETE( hh_dex_num, as_gmsa( gm_store )->mons_by_dex, curr_mon );
      pdex_mon_free( curr_mon );
    }
  free( gm_store->aux );
}


/* ------------------------------------------------------------------------- */

  bool
gm_store_has( store_t * gm_store, store_key_t key )
{
  return STORE_ERROR_NOT_FOUND != gm_store_get( gm_store, key, NULL );
}


/* ------------------------------------------------------------------------- */

  int
gm_store_get( store_t * gm_store, store_key_t key, void ** val )
{
  assert( gm_store != NULL );

  if ( as_gmsk( key ).is_move ) /* Move */
    {
      store_move_t * move = NULL;
      HASH_FIND( hh_move_id,
                 as_gmsa( gm_store )->moves_by_id,
                 & as_gmsk( key ).id,
                 sizeof( uint16_t ),
                 move
               );
      if ( val != NULL ) *val = (void *) move;
      if ( move != NULL ) return STORE_SUCCESS;
    }
  else /* Pokemon */
    {
      printf( "pokemon\n" );

      pdex_mon_t * mon = NULL;
      HASH_FIND( hh_dex_num,
                 as_gmsa( gm_store )->mons_by_dex,
                 & as_gmsk( key ).id,
                 sizeof( uint16_t ),
                 mon
               );
      if ( mon == NULL )
        {
          printf( "no hash\n" );
          *val = NULL;
          return STORE_ERROR_NOT_FOUND;
        }

      for ( uint8_t f = 0; f < as_gmsk( key ).form_idx; f++ )
        {
          if ( mon->next_form == NULL )
            {
              printf( "form %d/%d not found\n", f, as_gmsk( key ).form_idx );
              *val = NULL;
              return STORE_ERROR_NOT_FOUND;
            }
          mon = mon->next_form;
        }
      printf( "form %d found\n", as_gmsk( key ).form_idx );
      *val = mon;
      return STORE_SUCCESS;
    }
}


/* ------------------------------------------------------------------------- */

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


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
