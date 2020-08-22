/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include "ptypes.h"
#include "moves.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pvp_action.h"
#include "battle.h"

#include "ai/pvpoke_ai.h"
/* Must come after AI implementation */
#include "ai/ai.h"
/* Must come after AI */
#include "player.h"


/* ------------------------------------------------------------------------- */


const pdex_mon_t bulbasaur = {
  .dex_number = 1,
  .name       = "BULBASAUR",
  .family     = 1,
  .form       = 1,
  .types      = GRASS_M | POISON_M,
  .base_stats = { .attack = 118, .stamina = 128, .defense = 111 }
};


const base_move_t vine_whip = {
  .move_id   = 214,
  .type      = GRASS,
  .power     = 5,
  .energy    = 8,
};

const pvp_fast_move_t vine_whip_pvp = {
  vine_whip,
  .turns     = 1
};

const base_move_t power_whip = {
  .move_id   = 118,
  .type      = GRASS,
  .power     = 90,
  .energy    = 50,
};

const pvp_charged_move_t power_whip_pvp = {
  power_whip,
  .buff      = NO_BUFF
};



/* This is currently just used to check that headers conpile. */
int
main( int argc, char * argv[], char ** envp ) {

  roster_pokemon_t bulby_boi = {
    bulbasaur,
    .level         = 20,
    .ivs           = { 10, 10, 10 },
    .fast_move     = vine_whip,
    .charged_moves = { power_whip, power_whip }
  };

  const roster_t my_roster = {
    .roster_pokemon = & bulby_boi,
    .roster_length  = 1
  };


  return EXIT_SUCCESS;
}



/* ========================================================================= */

/* vim: set filetype=c : */
