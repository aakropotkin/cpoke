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

/* FIXME make masked enum. 118 kinds... */
#if 0
typedef enum {
  NORMAL, SHADOW, PURIFIED,
  FALL_2019,    /* Seems to pop up on a lot of Kanto */
  COPY,         /* Clone form. "COPY_2019" */
  ALOLA,
  VS_2019,      /* Pikachu, I'm assuming Luchador */
  COSTUME_2020, /* Pikachu, 4th anniversary */
  GALARIAN,
  A, /* Armored Mewtwo I think. Also Unown */
  /* Unowns... */
  B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
  EXCLAMATION_POINT, QUESTION_MARK,
  /* Spinda */
  _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12, _13, _14,
  _15, _16, _17, _18, _19,
  /* Castform */
  SUNNY, RAINY, SNOWY,
  /* Deoxys */
  ATTACK, DEFENSE, SPEED,
  /* Burmy/Worm */
  PLANT, SANDY, TRASH,
  /* Cherrim */
  OVERCAST,
  /* Shellos/Gastrodon */
  EAST_SEA, WEST_SEA,
  /* Rotom */
  HEAT, WASH, FROST, FAN, MOW,
  /* Tina */
  ALTERED, ORIGIN,
  /* Shaymin */
  LAND, SKY,
  /* Arceus */
  FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, STEEL, FIRE, WATER, GRASS,
  ELECTRIC, PSYCHIC, ICE, DRAGON, DARK, FAIRY,
  /* Basculin */
  RED_STRIPED, BLUE_STRIPED,
  /* Darmanitan */
  STANDARD, ZEN, GALARIAN_STANDARD, GALARIAN_ZEN,
  /* Deerling/Sawsbuck */
  SPRING, SUMMER, AUTUMN, WINTER,
  /* Frillish/Jellicent */
  FEMALE,
  /* Tornadus/Thundurus/Landorus */
  INCARNATE, THERIAN,
  /* Kyurem */
  WHITE, BLACK,
  /* Keldeo */
  ORDINARY, RESOLUTE,
  /* Meloetta */
  ARIA, PIROUETTE,
  /* Genesect */
  DOUSE, SHOCK, BURN, CHILL
} form_t;
#endif

static const uint8_t MAX_FORM = UCHAR_MAX;


/* ------------------------------------------------------------------------- */

typedef enum {
  LEGENDARY,
  MYTHIC,
  HAS_SHADOW,
  ALOLAN,
  GALARIAN
} pdex_tag_t;


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
 * This is the "default" key, it may change in different contexts.
 * For example the GM Parser and Sim are most likely going to use different
 * keys.
 */
  static inline uint16_t
pdex_mon_hkey( pdex_mon_t * mon )
{
  return ( mon->dex_number << ( 8 * sizeof( char ) ) ) | mon->form_idx;
}


/* ------------------------------------------------------------------------- */

  static uint8_t
get_form_number_from_str( const char * str )
{
  return 0;
}

  static uint8_t
get_form_number_from_enum( int e )
{
  return 0;
}


#define get_form_number( FORM ) _Generic( ( FORM ),                           \
    char *:       get_form_number_from_str,                                   \
    const char *: get_form_number_from_str,                                   \
    int:          get_form_number_from_enum                                   \
  )( FORM )



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



/* ========================================================================= */

#endif /* pokedex.h */

/* vim: set filetype=c : */
