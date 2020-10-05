/* -*- mode: c; -*- */

/* ========================================================================= */

#include "iv_rank.h"
#include "pokedex.h"
#include "pokemon.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* ------------------------------------------------------------------------- */

extern pdex_mon_t * POKEDEX[];
extern uint16_t     NUM_POKEMON;


/* ------------------------------------------------------------------------- */

/* Don't bother exporting a pokemon if it's under the league cap at max level */
  static inline bool
should_export( stats_t base_stats, league_t league )
{
  return league < get_cp_from_stats( base_stats,
                                     (stats_t) { 15, 15, 15 },
                                     MAX_LEVEL
                                   );
}


/* ------------------------------------------------------------------------- */

  void
fprint_iv_rankings_c( FILE          * fd,
                      stats_combo_t * rankings,
                      uint32_t        num_elems,
                      league_t        league,
                      uint16_t        dex_num,
                      uint8_t         form_idx,
                      bool            minimal
                    )
{
  assert( rankings != NULL );
  assert( league != MASTER_LEAGUE );
  bool first = true;
  fprintf( fd,
           "static const iv_lv_t IVS_%s_%u_%u[] = {",
           get_league_name( league ),
           dex_num,
           form_idx
         );
  for ( uint32_t i = 0; i < num_elems; i++ )
    {
      if ( first ) first = false;
      else         putc( ',', fd );
      if ( minimal )
        {
          fprintf( fd,
                   "\n  { .lvi = %u, "
                   ".ivs = { .attack = %u, .stamina = %u, .defense = %u } }",
                   (int) ( rankings[i].lv * 2 ),
                   rankings[i].ivs.attack,
                   rankings[i].ivs.stamina,
                   rankings[i].ivs.defense
                 );
        }
      else
        {
          fprintf( fd,
                   "\n  { .cp = %u, .lvi = %u,\n\n"
                   "    .ivs = { .attack = %u, .stamina = %u, .defense = %u },"
                   "\n    .eff = { .attack = %u, .stamina = %u, .defense = %u }"
                   "\n  }",
                   rankings[i].cp,
                   (int) ( rankings[i].lv * 2 ),
                   rankings[i].ivs.attack,
                   rankings[i].ivs.stamina,
                   rankings[i].ivs.defense,
                   rankings[i].eff.attack,
                   rankings[i].eff.stamina,
                   rankings[i].eff.defense
                 );
        }
    }
  fprintf( fd, "\n};\n" );
}


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
iv_store_export_c( FILE * fd, uint32_t max_rsl, bool minimal )
{
  stats_combo_t * rankings = NULL;
  pdex_mon_t    * curr     = NULL;
  bool            first    = true;
  uint16_t        gl_cnt   = 0;
  uint16_t        ul_cnt   = 0;

  if ( ( max_rsl == 0 ) || ( 1000 < max_rsl ) )
    {
      fprintf( stderr,
               "This is a shit idea, you don't want to generate this many "
               "rankings.\nDo something reasonable: < 1000.\n"
             );
      exit( EXIT_FAILURE );
    }

  fprintf( fd, "#include \"iv_rank.h\"\n#include <stdint.h>\n\n" );

  for ( uint16_t i = 0; i < NUM_POKEMON; i++ )
    {
      if ( ! should_export( POKEDEX[i]->base_stats, GREAT_LEAGUE ) ) continue;
      gl_cnt++;

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
                            0,
                            minimal
                          );
      free( rankings );

      if ( ! should_export( POKEDEX[i]->base_stats, ULTRA_LEAGUE ) ) continue;
      ul_cnt++;
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
                            0,
                            minimal
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
                                curr->form_idx,
                                minimal
                              );
          free( rankings );
          rankings = rank_ivs_array( curr->base_stats, max_rsl, ULTRA_LEAGUE );
          assert( rankings != NULL );
          fprint_iv_rankings_c( fd,
                                rankings,
                                max_rsl,
                                ULTRA_LEAGUE,
                                curr->dex_number,
                                curr->form_idx,
                                minimal
                              );
          free( rankings );
        }
      #endif
    }

  fprintf( fd, "\n\niv_stats_t ** IV_RANKINGS_GREAT_LEAGUE[] = {\n");

  for ( uint8_t i = 0; i < NUM_POKEMON; i++ )
    {
      if ( ! should_export( POKEDEX[i]->base_stats, GREAT_LEAGUE ) ) continue;
      if ( first ) first = false;
      else         putc( ',', fd );
      fprintf( fd, "\n  & IVS_GREAT_LEAGUE_%u_0", POKEDEX[i]->dex_number );
    }

  fprintf( fd, "\n};\n\niv_stats_t ** IV_RANKINGS_ULTRA_LEAGUE[] = {\n" );

  for ( uint8_t i = 0; i < NUM_POKEMON; i++ )
    {
      if ( ! should_export( POKEDEX[i]->base_stats, ULTRA_LEAGUE  ) ) continue;
      if ( first ) first = false;
      else         putc( ',', fd );
      fprintf( fd, "\n  & IVS_ULTRA_LEAGUE_%u_0", POKEDEX[i]->dex_number );
    }
  fprintf( fd, "\n};\n\n" );

  fprintf( fd, "const uint16_t IVS_GL_COUNT= %u;\n", gl_cnt );
  fprintf( fd, "const uint16_t IVS_UL_COUNT= %u;\n", ul_cnt );
  fprintf( fd, "const uint16_t IVS_NUM_RANKS = %u;\n\n", max_rsl );
}


/* ------------------------------------------------------------------------- */

#ifdef MK_IV_STORE_BUILD_BINARY

  int
main( int argc, char * argv[], char ** envp )
{
  iv_store_export_c( stdout, 100, true );
  return EXIT_SUCCESS;
}


#endif /* MK_IV_STORE_BUILD_BINARY */



/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
