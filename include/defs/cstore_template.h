/* -*- mode: c; -*- */

#ifndef _CSTORE_TEMPLATE_H
#define _CSTORE_TEMPLATE_H

/* ========================================================================= */

static const char EQSEP[] = "/* ====================================="
                            "==================================== */";
static const char DASHSEP[] = "/* -------------------------------------"
                              "------------------------------------ */";

static const char INCLUDES[] = R"RAW_C(
#include "pokedex.h"
#include "moves.h"
#include "ptypes.h"
#include <stdlib.h>
#include <stdint.h>
)RAW_C";

/* ( FAST | CHARGED, dex_number, form_idx ) */
static const char MOVELIST_FMT[] = "uint16_t %s_MOVELIST_%u_%u[] = ";

/* ( dex_number, form_idx ) */
static const char POKEMON_FMT[] = "pdex_mon_t DEXMON_%u_%u = ";


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* cstore_template.h */

/* vim: set filetype=c : */
