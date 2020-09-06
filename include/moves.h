/* -*- mode: c; -*- */

#ifndef _MOVES_H
#define _MOVES_H

/* ========================================================================= */

#include <stdint.h>
#include <stdbool.h>
#include "ptypes.h"


/* ------------------------------------------------------------------------- */

typedef enum packed {
  bc_1000, bc_0500, bc_0300, bc_0125, bc0100, bc0000
} buff_chance_t; /* 3 bits used, 4 total */


/* ------------------------------------------------------------------------- */

struct stat_buff_s {
  uint8_t target  : 1; /* 0 --> self; 1 --> opponent */
  uint8_t debuffp : 1; /* 1 --> Debuff --> ( - amount ) */
  uint8_t amount  : 2;
} packed;

typedef struct stat_buff_s  stat_buff_t;


  static inline const_fn int8_t
decode_stat_buff( stat_buff_t buff )
{
  return buff.debuffp ? buff.amount : ( - buff.amount );
}


/* ------------------------------------------------------------------------- */

struct buff_s {
  buff_chance_t chance;   /* I think 3 bits */
  stat_buff_t   atk_buff;
  stat_buff_t   def_buff;
} packed; /* 11 bits used, 16 total */

typedef struct buff_s  buff_t;


extern const buff_t NO_BUFF;


/* ------------------------------------------------------------------------- */

extern const double BUFF_MOD[];

typedef enum packed {
  B_4_8, B_4_7, B_4_6, B_4_5,
  B_4_4,
  B_5_4, B_6_4, B_7_4, B_8_4
} buff_level_t;


/* ------------------------------------------------------------------------- */

struct buff_state_s {
  buff_level_t atk_buff_lv;
  buff_level_t def_buff_lv;
} packed;

typedef struct buff_state_s  buff_state_t;

#define get_buff_mod( buff_level )  ( BUFF_MOD[( buff_level )] )

void apply_buff( buff_state_t * buff_state, buff_t buff );


/* ------------------------------------------------------------------------- */

/**
 * As of [2020-08-22] there are 342 moves
 */
struct base_move_s {
  uint16_t move_id;
  ptype_t  type;
  uint8_t  power;   /* NOTE: These values are not always the same for PvP/PvE */
  uint8_t  energy;  /* NOTE: These values are not always the same for PvP/PvE */
} packed;

typedef struct base_move_s  base_move_t;

#define as_base_move( child_move )                                            \
  ( (base_move_t) { .move_id = ( child_move ).move_id,                        \
                    .type    = ( child_move ).type,                           \
                    .power   = ( child_move ).power,                          \
                    .energy  = ( child_move ).energy,                         \
                  } )


/* ------------------------------------------------------------------------- */

struct pve_move_s {
  base_move_t;           /* Inherit */
  uint16_t    cooldown;  /* ms */
} packed;

typedef struct pve_move_s  pve_move_t;


/* ------------------------------------------------------------------------- */

struct pvp_charged_move_s {
  base_move_t;       /* Inherit */
  buff_t      buff;  /* A pointer could be used, but it costs more */
} packed;

typedef struct pvp_charged_move_s  pvp_charged_move_t;


/* ------------------------------------------------------------------------- */

struct pvp_fast_move_s {
  base_move_t;            /* Inherit */
  uint8_t     turns : 2;  /* 1-4 */
} packed;

typedef struct pvp_fast_move_s  pvp_fast_move_t;


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* moves.h */

/* vim: set filetype=c : */
