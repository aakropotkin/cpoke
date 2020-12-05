/* -*- mode: c; -*- */

/* ========================================================================== */

#include "pokedex.h"
#include "pokemon.h"
#include "ptypes.h"
#include "moves.h"

/* -------------------------------------------------------------------------- */

static const base_move_t vine_whip = {
  .move_id = 214,
  .type    = GRASS,
  .is_fast = true,
  .power   = 5,
  .energy  = 8,
};

static const pvp_fast_move_t vine_whip_pvp = {
  vine_whip,
  .turns     = 1
};

static const base_move_t power_whip = {
  .move_id = 118,
  .type    = GRASS,
  .is_fast = false,
  .power   = 90,
  .energy  = 50,
};

static const pvp_charged_move_t power_whip_pvp = {
  power_whip,
  .buff      = NO_BUFF
};

static uint16_t bulb_fast_move_ids[]    = { vine_whip.move_id };
static uint16_t bulb_charged_move_ids[] = { power_whip.move_id };

static const pdex_mon_t bulbasaur = {
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


/* -------------------------------------------------------------------------- */

#ifdef PDEX_0_NOBASE
#define PDEX_0_NOROST
#else /* defined( PDEX_0_NOBASE ) */

static base_pokemon_t base_bulbasaur = {
  .pdex_mon = & bulbasaur,
  .level    = 20,
  .ivs      = { 10, 10, 10 }
};


#endif /* defined( PDEX_0_NOBASE ) */


#ifndef PDEX_0_NOROST

static roster_pokemon_t roster_bulbasaur = {
  .base             = & base_bulbasaur,
  .fast_move_id     = vine_whip.move_id,
  .charged_move_ids = { power_whip.move_id, 0 }
};

#endif /* ! defined( PDEX_0_NOROST ) */


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
