/* -*- mode: c; -*- */

/* ========================================================================= */

#include "iv_rank.h"
#include "pokedex.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------- */

extern pdex_mon_t * POKEDEX[];
extern uint16_t     NUM_POKEMON;


/* ------------------------------------------------------------------------- */

/**
 * This thing already has to crunch a lot of data, we take a dirty shortcut
 * and work directly on the static data in `cstore_data.c'.
 * This saves us from wasting calls fetching data from the store.
 * This is only being done because I don't actually expect this to be used
 * frequently by users.
 * If I turn out to be wrong, it is trivial to substitute a `store_t' here.
 */
  void
iv_store_export_c( FILE * fd, uint16_t max_rsl )
{
  stats_combo_t * rankings = NULL;
  pdex_mon_t    * curr     = NULL;
  bool            first    = true;

  if ( ( max_rsl == 0 ) || ( 1000 < max_rsl ) )
    {
      fprintf( stderr,
               "This is a shit idea, you don't want to generate this many "
               "rankings.\nDo something reasonable: < 1000.\n"
             );
      exit( EXIT_FAILURE );
    }

  fprintf( fd, "#include \"iv_rank.h\"\n#include <stdint.h>\n\n" );
  fprintf( fd, "const uint16_t IVS_NUM_POKEMON = %u;\n", NUM_POKEMON );
  fprintf( fd, "const uint16_t IVS_NUM_RANKS = %u;\n", max_rsl );

  for ( uint16_t i = 0; i < NUM_POKEMON; i++ )
    {
      /* Write the base form */
      rankings = rank_ivs_array( POKEDEX[i]->base_stats,
                                 max_rsl,
                                 GREAT_LEAGUE
                               );
      assert( rankings != NULL );
      fprint_iv_rankings_c( fd,
                            rankings,
                            max_rsl,
                            GREAT_LEAGUE,
                            POKEDEX[i]->dex_number,
                            0
                          );
      free( rankings );
      rankings = rank_ivs_array( POKEDEX[i]->base_stats,
                                 max_rsl,
                                 ULTRA_LEAGUE
                               );
      assert( rankings != NULL );
      fprint_iv_rankings_c( fd,
                            rankings,
                            max_rsl,
                            ULTRA_LEAGUE,
                            POKEDEX[i]->dex_number,
                            0
                          );
      free( rankings );

      #if 0
      /* Do extra forms, but only if their stats differ */
      curr = POKEDEX[i]->next_form;
      while ( curr != NULL )
        {
          if ( ( POKEDEX[i]->base_stats.attack  == curr->base_stats.attack  ) &&
               ( POKEDEX[i]->base_stats.stamina == curr->base_stats.stamina ) &&
               ( POKEDEX[i]->base_stats.defense == curr->base_stats.defense )
             )
            {
              curr = curr->next_form;
              continue;
            }
          rankings = rank_ivs_array( curr->base_stats, max_rsl, GREAT_LEAGUE );
          assert( rankings != NULL );
          fprint_iv_rankings_c( fd,
                                rankings,
                                max_rsl,
                                GREAT_LEAGUE,
                                curr->dex_number,
                                curr->form_idx
                              );
          free( rankings );
          rankings = rank_ivs_array( curr->base_stats, max_rsl, ULTRA_LEAGUE );
          assert( rankings != NULL );
          fprint_iv_rankings_c( fd,
                                rankings,
                                max_rsl,
                                ULTRA_LEAGUE,
                                curr->dex_number,
                                curr->form_idx
                              );
          free( rankings );
        }
      #endif
    }

  fprintf( fd, "\n\niv_stats_t ** IV_RANKINGS_GREAT_LEAGUE[] = {\n");

  for ( uint8_t i = 0; i < NUM_POKEMON; i++ )
    {
      if ( first ) first = false;
      else         putc( ',', fd );
      fprintf( fd, "\n  & IVS_GREAT_LEAGUE_%u_0", POKEDEX[i]->dex_number );
    }

  fprintf( fd, "\n};\n\niv_stats_t ** IV_RANKINGS_ULTRA_LEAGUE[] = {\n" );

  for ( uint8_t i = 0; i < NUM_POKEMON; i++ )
    {
      if ( first ) first = false;
      else         putc( ',', fd );
      fprintf( fd, "\n  & IVS_GREAT_ULTRA_%u_0", POKEDEX[i]->dex_number );
    }
  fprintf( fd, "\n};\n\n" );
}


/* ------------------------------------------------------------------------- */

#ifdef MK_IV_STORE_BUILD_BINARY

  int
main( int argc, char * argv[], char ** envp )
{
  iv_store_export_c( stdout, 100 );
  return EXIT_SUCCESS;
}


#endif /* MK_IV_STORE_BUILD_BINARY */



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
