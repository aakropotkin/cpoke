/* -*- mode: c; -*- */

/* ========================================================================= */

#include "pokedex.h"
#include "pokemon.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/test_util.h"
#include "../../data/test/roster.h"


/* ------------------------------------------------------------------------- */

const base_move_t vine_whip = {
  .move_id = 214,
  .type    = GRASS,
  .is_fast = true,
  .power   = 5,
  .energy  = 8,
};

const pvp_fast_move_t vine_whip_pvp = {
  vine_whip,
  .turns     = 1
};

const base_move_t power_whip = {
  .move_id = 118,
  .type    = GRASS,
  .is_fast = false,
  .power   = 90,
  .energy  = 50,
};

const pvp_charged_move_t power_whip_pvp = {
  power_whip,
  .buff      = NO_BUFF
};

uint16_t bulb_fast_move_ids[]    = { vine_whip.move_id };
uint16_t bulb_charged_move_ids[] = { power_whip.move_id };

const pdex_mon_t bulbasaur = {
  .dex_number        = 1,
  .name              = "BULBASAUR",
  .form_name         = "NORMAL",
  .family            = 1,
  .types             = GRASS_M | POISON_M,
  .base_stats        = { .attack = 118, .stamina = 128, .defense = 111 },
  .fast_move_ids     = bulb_fast_move_ids,
  .fast_moves_cnt    = 1,
  .charged_move_ids  = bulb_charged_move_ids,
  .charged_moves_cnt = 1,
  .form_idx          = 0,
  .next_form         = NULL,
  .hh_name           = 0,
  .hh_dex_num        = 0
};


/* ------------------------------------------------------------------------- */

/**
 * This "test" is essentially done at compilation time.
 */
  static bool
test_construct_pokemon( void )
{
  base_pokemon_t base_bulby_boi = {
    .pdex_mon = & bulbasaur,
    .level    = 20,
    .ivs      = { 10, 10, 10 }
  };

  roster_pokemon_t bulby_boi = {
    .base             = & base_bulby_boi,
    .fast_move_id     = vine_whip.move_id,
    .charged_move_ids = { power_whip.move_id, 0 }
  };

  roster_t my_roster = {
    .roster_pokemon = & bulby_boi,
    .roster_length  = 1
  };

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_get_cpm_for_level( void )
{
  expect( get_cpm_for_level( 1 ) == CPMS[0] );
  expect( get_cpm_for_level( 39.5 ) == CPMS[77] );
  expect( get_cpm_for_level( 40 ) == CPMS[78] );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_cstore_base_mon_from_store( void )
{
  store_t cstore = CSTORE;

  base_pokemon_t mon = BASE_MON_NULL;

  int rsl = base_mon_from_store( & cstore, 1, 0, 15.0, 10, 11, 12, & mon );
  expect( mon.pdex_mon != NULL );
  expect( mon.pdex_mon->dex_number == 1 );
  expect( mon.pdex_mon->form_idx == 0 );
  expect( mon.level == 15.0 );
  expect( mon.ivs.attack == 10 );
  expect( mon.ivs.stamina == 11 );
  expect( mon.ivs.defense == 12 );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_cstore_roster( void )
{
  store_t cstore = CSTORE;
  base_pokemon_t USER1_BASE_MONS[] = def_user1_base_mons();

  roster_pokemon_t bulbasaur = {
    .base = & USER1_BASE_MONS[0],
    .fast_move_id = (uint16_t) USER1_BASE_MONS[0].pdex_mon->fast_move_ids[0],
    .charged_move_ids = {
      (uint16_t) USER1_BASE_MONS[0].pdex_mon->charged_move_ids[0],
      (uint16_t) USER1_BASE_MONS[0].pdex_mon->charged_move_ids[1]
    }
  };

  roster_pokemon_t charmander = {
    .base = & USER1_BASE_MONS[1],
    .fast_move_id = (uint16_t) USER1_BASE_MONS[1].pdex_mon->fast_move_ids[0],
    .charged_move_ids = {
      (uint16_t) USER1_BASE_MONS[1].pdex_mon->charged_move_ids[0],
      (uint16_t) USER1_BASE_MONS[1].pdex_mon->charged_move_ids[1]
    }
  };

  roster_pokemon_t squirtle = {
    .base = & USER1_BASE_MONS[2],
    .fast_move_id = (uint16_t) USER1_BASE_MONS[2].pdex_mon->fast_move_ids[0],
    .charged_move_ids = {
      (uint16_t) USER1_BASE_MONS[2].pdex_mon->charged_move_ids[0],
      (uint16_t) USER1_BASE_MONS[2].pdex_mon->charged_move_ids[1]}
  };

  roster_pokemon_t user1_rmons[] = { bulbasaur, charmander, squirtle };
  roster_t user1_roster = { .roster_pokemon = user1_rmons, .roster_length = 3 };

  expect( strcmp( user1_roster.roster_pokemon[0].base->pdex_mon->name,
                  "BULBASAUR"
                ) == 0
        );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_roster_append( void )
{
  store_t cstore  = CSTORE;
  base_pokemon_t USER1_BASE_MONS[] = def_user1_base_mons();
  roster_t roster = { .roster_pokemon = NULL, .roster_length = 0 };

  roster_pokemon_t bulbasaur = {
    .base = & USER1_BASE_MONS[0],
    .fast_move_id = (uint16_t) USER1_BASE_MONS[0].pdex_mon->fast_move_ids[0],
    .charged_move_ids = {
      (uint16_t) USER1_BASE_MONS[0].pdex_mon->charged_move_ids[0],
      (uint16_t) USER1_BASE_MONS[0].pdex_mon->charged_move_ids[1]
    }
  };

  roster_pokemon_t charmander = {
    .base = & USER1_BASE_MONS[1],
    .fast_move_id = (uint16_t) USER1_BASE_MONS[1].pdex_mon->fast_move_ids[0],
    .charged_move_ids = {
      (uint16_t) USER1_BASE_MONS[1].pdex_mon->charged_move_ids[0],
      (uint16_t) USER1_BASE_MONS[1].pdex_mon->charged_move_ids[1]
    }
  };

  roster_pokemon_t squirtle = {
    .base = & USER1_BASE_MONS[2],
    .fast_move_id = (uint16_t) USER1_BASE_MONS[2].pdex_mon->fast_move_ids[0],
    .charged_move_ids = {
      (uint16_t) USER1_BASE_MONS[2].pdex_mon->charged_move_ids[0],
      (uint16_t) USER1_BASE_MONS[2].pdex_mon->charged_move_ids[1]
    }
  };

  roster_append( & roster, & bulbasaur );
  expect( roster.roster_pokemon != NULL );
  expect( roster.roster_length == 1 );

  roster_append( & roster, & charmander );
  expect( roster.roster_pokemon != NULL );
  expect( roster.roster_length == 2 );

  roster_append( & roster, & squirtle );
  expect( roster.roster_pokemon != NULL );
  expect( roster.roster_length == 3 );

  free( roster.roster_pokemon );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_get_pvp_mon_move( void )
{
  pvp_pokemon_t mon    = PVP_MON_NULL;
  mon.fast_move        = vine_whip_pvp;
  mon.charged_moves[0] = power_whip_pvp;

  expect( get_pvp_mon_move( mon, M_FAST ).move_id == vine_whip_pvp.move_id );
  expect( get_pvp_mon_move( mon, M_CHARGED1 ).move_id ==
          power_whip_pvp.move_id
        );

  expect( get_pvp_mon_move_id( mon, M_FAST ) == vine_whip_pvp.move_id );
  expect( get_pvp_mon_move_id( mon, M_CHARGED1 ) == power_whip_pvp.move_id );

  expect( get_pvp_mon_move_power( mon, M_FAST ) == vine_whip_pvp.power );
  expect( get_pvp_mon_move_power( mon, M_CHARGED1 ) == power_whip_pvp.power );

  expect( get_pvp_mon_move_energy( mon, M_FAST ) == vine_whip_pvp.energy );
  expect( get_pvp_mon_move_energy( mon, M_CHARGED1 ) == power_whip_pvp.energy
        );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_get_cp_from_stats( void )
{
  const stats_t ralts_base = { .attack = 79, .stamina = 99, .defense = 59 };
  expect( get_cp_from_stats( ralts_base,
                             (stats_t) { .attack  = 4,
                                         .stamina = 6,
                                         .defense = 12
                                       },
                             20
                           ) == 255
        );

  const stats_t mewtwo_base = { .attack = 300, .stamina = 214, .defense = 182 };
  expect( get_cp_from_stats( mewtwo_base,
                             (stats_t) { .attack  = 14,
                                         .stamina = 15,
                                         .defense = 15
                                       },
                             40
                           ) == 4165
        );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_get_effective_stats( void )
{
  const stats_t mewtwo_base = { .attack = 300, .stamina = 214, .defense = 182 };
  const stats_t mewtwo_ivs  = { .attack  = 14, .stamina = 15, .defense = 15};

  /* HP is the only real good indicator we have from the game */
  expect( get_effective_stats( mewtwo_base, mewtwo_ivs, 40 ).stamina == 180 );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_get_pvp_damage( void )
{
  /**
   * Originally Cribbed from `pokemongohub.net', notably their math is off by 1
   * because they rounded up rather than down for `floor'.
   * No it is not a precision issue, I've tried it a million ways.
   *
   * They also use the wrong defense for Vaporeon so I just redid it.
   */
  pvp_pokemon_t venusaur = PVP_MON_NULL;
  venusaur.stats = (stats_t) { .stamina = 190 + 15,
                               .attack  = 198 + 15,
                               .defense = 189 + 15
                             };
  venusaur.types = GRASS_M | POISON_M;
  venusaur.level = 30;
  venusaur.charged_moves[0] = (pvp_charged_move_t) {
    .move_id = 116,
    .type    = GRASS,
    .is_fast = false,
    .power   = 150,
    .energy  = 80,
    .buff    = NO_BUFF
  };

  pvp_pokemon_t vaporeon = PVP_MON_NULL;
  vaporeon.level = 30;
  vaporeon.stats = (stats_t) { .stamina = 277 + 15,
                               .attack  = 205 + 15,
                               .defense = 161 + 15
                              };
  vaporeon.types = WATER_M;

  expect( get_pvp_damage( M_CHARGED1, & venusaur, & vaporeon ) == 236 );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_brute_maximize_ivs( void )
{
  stats_t ven_base = { .stamina = 190, .attack = 198, .defense = 189 };
  stats_t ivs      = { 0, 0, 0 };
  float   lv       = 0.0;
  bool    rsl      = false;

  rsl = brute_maximize_ivs( 1500, ven_base, & ivs, & lv );

  expect( rsl == true );
  expect( lv == 21 );
  expect( ivs.attack  ==  0 );
  expect( ivs.defense == 14 );
  expect( ivs.stamina == 11 );
  expect( get_cp_from_stats( ven_base, ivs, lv ) == 1498 );

  return true;
}



/* ------------------------------------------------------------------------- */

  bool
test_pokemon( void )
{
  bool rsl = true;
  CS_init();

  rsl &= do_test( construct_pokemon );
  rsl &= do_test( get_cpm_for_level );
  rsl &= do_test( cstore_roster );
  rsl &= do_test( cstore_base_mon_from_store );
  rsl &= do_test( roster_append );
  rsl &= do_test( get_pvp_mon_move );
  rsl &= do_test( get_cp_from_stats );
  rsl &= do_test( get_effective_stats );
  rsl &= do_test( get_pvp_damage );
  rsl &= do_test( brute_maximize_ivs );

  CS_free();
  return rsl;
}


/* ------------------------------------------------------------------------- */

#ifdef MK_TEST_BINARY
int
main( int argc, char * argv[], char ** envp )
{
  return test_pokemon() ? EXIT_SUCCESS : EXIT_FAILURE;
}
#endif


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
