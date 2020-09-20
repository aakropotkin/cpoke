/* -*- mode: c; -*- */

/* ========================================================================= */

#include "pokedex.h"
#include "pokemon.h"
#include <stdlib.h>
#define CSTORE_GLOBAL_STORE
#include "cstore.h"

extern pdex_mon_t POKEDEX[];

/* ------------------------------------------------------------------------- */

static base_pokemon_t USER1_BASE_MONS[] = {
  { .pdex_mon = & POKEDEX[0], .level = 15.0, .ivs = { 10, 10, 10 } },
  { .pdex_mon = & POKEDEX[3], .level = 15.0, .ivs = { 10, 10, 10 } },
  { .pdex_mon = & POKEDEX[6], .level = 15.0, .ivs = { 10, 10, 10 } }
};


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
