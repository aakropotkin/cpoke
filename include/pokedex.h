/* -*- mode: c; -*- */

#ifndef _POKEDEX_H
#define _POKEDEX_H

/* ========================================================================= */

#include "ext/uthash.h"
#include "moves.h"
#include "ptypes.h"
#include "util/bits.h"
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */

static const uint16_t MAX_STAT = 999;

struct stats_s { uint16_t attack, stamina, defense; } packed;
typedef struct stats_s  stats_t;


/* ------------------------------------------------------------------------- */

DEFINE_ENUM_WITH_FLAGS( pdex_tag, TAG_NONE, TAG_LEGENDARY, TAG_MYTHIC, TAG_MEGA,
                        TAG_SHADOW_ELIGABLE, TAG_SHADOW, TAG_PURE,
                        TAG_ALOLAN, TAG_GALARIAN,
                        TAG_STARTER, TAG_REGIONAL
                      );


/* ------------------------------------------------------------------------- */

struct region_s {
  char     * name;
  uint16_t   dex_start;
  uint16_t   dex_end;
};
typedef struct region_s  region_t;

#ifndef REGIONS
static const region_t REGIONS[] = {
  { "Kanto",     1, 151 },
  { "Johto",   152, 251 },
  { "Hoenn",   252, 386 },
  { "Sinnoh",  387, 493 },
  { "Unova",   494, 649 },
  { "Unknown", 808, 809 }
};
#endif

static const uint8_t NUM_REGIONS = array_size( REGIONS );


/* ------------------------------------------------------------------------- */

struct pdex_mon_s {
  uint16_t            dex_number;
  char              * name;
  /* Usually normal/shadow, but sometimes legacy */
  char              * form_name;
  /* Dex # of "base" monster ( lowest non-baby ) */
  uint16_t            family;
  ptype_mask_t        types;
  stats_t             base_stats;
  pdex_tag_mask_t     tags;
  uint16_t          * fast_move_ids;
  uint8_t             fast_moves_cnt;
  uint16_t          * charged_move_ids;
  uint8_t             charged_moves_cnt;
  uint8_t             form_idx;
  struct pdex_mon_s * next_form;
  /* For hash table */
  uint16_t            hkey;
  UT_hash_handle      hh_name;
  UT_hash_handle      hh_dex_num;
};

typedef struct pdex_mon_s  pdex_mon_t;

static const uint16_t MAX_DEX = 809;  /* Melmetal */

void pdex_mon_init( pdex_mon_t * mon );
void pdex_mon_free( pdex_mon_t * mon );

/**
 * This is the "store" key, it may change in different contexts.
 * For example the parser uses `UT_hash_handle' keys directly.
 */
  static inline uint16_t
pdex_mon_hkey( pdex_mon_t * mon )
{
  return ( mon->dex_number << ( 8 * sizeof( uint8_t ) ) ) | mon->form_idx;
}


/* ------------------------------------------------------------------------- */

int fprint_pdex_mon( FILE * stream, const pdex_mon_t * mon );

  static inline int
print_pdex_mon( const pdex_mon_t * mon )
{
  return fprint_pdex_mon( stdout, mon );
}


/* ------------------------------------------------------------------------- */

int  cmp_pdex_mon( pdex_mon_t * a, pdex_mon_t * b );


/* ------------------------------------------------------------------------- */

  static inline bool
is_starter( uint16_t dex_number )
{
  /* Skip "Unknown" region */
  for ( uint8_t r = 0; r < NUM_REGIONS - 1; r++ )
    {
      if ( in_eq( REGIONS[r].dex_start, dex_number, REGIONS[r].dex_start + 9 ) )
        {
          return true;
        }
    }
  return false;
}


/* ------------------------------------------------------------------------- */

#ifndef REGIONAL_DEX_NUMBERS
#define REGIONAL_DEX_NUMBERS                                                  \
  83, 115, 122, 128, 214, 222, 313, 314, 324, 335, 336, 337, 338, 357, 369,   \
  417, 441, 511, 512, 513, 514, 515, 516, 550, 556, 561, 626, 631, 632
#endif

static const uint16_t REGIONALS[] = { REGIONAL_DEX_NUMBERS };
static const uint8_t  NUM_REGIONALS = array_size( REGIONALS );

  static inline bool
is_regional( uint16_t dex_number )
{
  for ( uint8_t i = 0; i < NUM_REGIONALS; i++ )
    {
      if ( REGIONALS[i] == dex_number ) return true;
    }
  return false;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pokedex.h */

/* vim: set filetype=c : */
