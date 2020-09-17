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

#ifdef CSTORE_EXTERN_POKEDEX
extern pdex_mon_t * POKEDEX[];
#endif


/* ------------------------------------------------------------------------- */

  int
cstore_init( store_t * cstore, void * pokedex )
{
  assert( cstore != NULL );
  cstore->aux = (void *) malloc( sizeof( cstore_aux_t ) );
  assert( cstore->aux != NULL );

#ifdef CSTORE_EXTERN_POKEDEX
  if ( pokedex == NULL ) as_csa( cstore )->pokedex = (void *) POKEDEX;
  else                   as_csa( cstore )->pokedex = pokedex;
#else
  assert( pokedex != NULL );
  cstore->aux = pokedex;
#endif

  as_csa( cstore )->mons_by_name  = NULL;
  as_csa( cstore )->mons_cnt      = 0;

  as_csa( cstore )->moves_by_name = NULL;
  as_csa( cstore )->moves_by_id   = NULL;
  as_csa( cstore )->moves_cnt     = 0;

  for ( uint8_t r = 0; r < NUM_REGIONS; r++ )
    {
      for ( int i = REGIONS[r].dex_start; i <= REGIONS[r].dex_end; i++ )
        {
          HASH_ADD_KEYPTR( hh_name,
                           as_csa( cstore )->mons_by_name,
                           as_csa( cstore )->pokedex[i]->name,
                           strlen( as_csa( cstore )->pokedex[i]->name ),
                           as_csa( cstore )->pokedex[i]
                         );
        }
      as_csa( cstore )->mons_cnt += REGIONS[r].dex_end - REGIONS[r].dex_start
                                    + 1;
    }


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
  if ( in_eq( REGIONS[0].dex_start, dex_num, REGIONS[NUM_REGIONS - 2].dex_end )
     )
    {
      mon = cstore->pokedex[dex_num - 1];
    }
  else
    {
      mon = cstore->pokedex[dex_num - REGIONS[NUM_REGIONS - 1].dex_start +
                            REGIONS[NUM_REGIONS - 2].dex_end
                           ];
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


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
