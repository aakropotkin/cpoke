/* -*- mode: c; -*- */

#ifndef _POKEDEX_H
#define _POKEDEX_H

/* ========================================================================= */

#include "ext/uthash.h"
#include "moves.h"
#include "ptypes.h"
#include "store.h"
#include "util/bits.h"
#include "util/enumflags.h"
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

static const uint8_t NUM_PDEX_TAGS = TAG_REGIONAL + 1;

static const char * PDEX_TAG_NAMES[] = {
  "NONE", "LEGENDARY", "MYTHIC", "MEGA", "SHADOW_ELIGABLE", "SHADOW", "PURE",
  "ALOLAN", "GALARIAN", "STARTER", "REGIONAL"
};

#define get_pdex_tag_name( TAG )  PDEX_TAG_NAMES[( TAG )]

#define get_pdex_tag_mask( pt )  ( (pdex_tag_mask_t) to_mask( ( pt ) ) )

int fprint_pdex_tag_mask( FILE * fd, const char * sep, pdex_tag_mask_t tm );

#define print_pdex_tag_mask( SEP, TM )                                        \
  fprintf_pdex_tag_mask( stdout, ( SEP ), ( TM ) )


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
  UT_hash_handle      hh_name;
  UT_hash_handle      hh_dex_num;
};

typedef struct pdex_mon_s  pdex_mon_t;

static const uint16_t MAX_DEX = 809;  /* Melmetal */

void pdex_mon_init( pdex_mon_t      * mon,
                    uint16_t          dex_num,
                    const char      * name,
                    size_t            name_len,
                    uint16_t          family,
                    uint8_t           form_num,
                    ptype_t           type1,
                    ptype_t           type2,
                    uint16_t          stamina,
                    uint16_t          attack,
                    uint16_t          defense,
                    pdex_tag_mask_t   tags,
                    uint16_t        * fast_move_ids,
                    uint8_t           fast_moves_cnt,
                    uint16_t        * charged_move_ids,
                    uint8_t           charged_moves_cnt
                  );
void pdex_mon_free( pdex_mon_t * mon );

/**
 * This is the "store" key, it may change in different contexts.
 * For example the parser uses `UT_hash_handle' keys directly.
 */
  static inline store_key_t
pdex_store_key( pdex_mon_t * mon )
{
  return (store_key_t) {
    .key_type = STORE_NUM,
    .val_type = STORE_POKEDEX,
    .data_h0  = mon->dex_number,
    .data_q2  = mon->form_idx,
    .data_q3  = 0
  };
}

  static inline store_key_t
dex_form_store_key( uint16_t dex_num, uint8_t form_idx )
{
  return (store_key_t) {
    .key_type = STORE_NUM,
    .val_type = STORE_POKEDEX,
    .data_h0  = dex_num,
    .data_q2  = form_idx,
    .data_q3  = 0
  };
}


/* ------------------------------------------------------------------------- */

int fprint_pdex_mon( FILE * stream, const pdex_mon_t * mon );

#define print_pdex_mon( MON )  fprint_pdex_mon( stdout, ( MON ) );


/* ------------------------------------------------------------------------- */

int  cmp_pdex_mon( pdex_mon_t * a, pdex_mon_t * b );


/* ------------------------------------------------------------------------- */

  static inline const region_t *
get_region( uint16_t dex_number )
{
  for ( uint8_t r = 0; r < NUM_REGIONS; r++ )
    {
      if ( in_eq( REGIONS[r].dex_start, dex_number, REGIONS[r].dex_end ) )
        {
          return REGIONS + r;
        }
    }
  return REGIONS + NUM_REGIONS - 1;
}


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
