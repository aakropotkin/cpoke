/* -*- mode: c; -*- */

#ifndef _MOVES_H
#define _MOVES_H

/* ========================================================================= */

#include "ext/uthash.h"
#include "ptypes.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>


/* ------------------------------------------------------------------------- */

typedef enum packed {
  bc_1000, bc_0500, bc_0300, bc_0125, bc_0100, bc_0000
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


static const buff_t NO_BUFF = { .chance = bc_0000,
  .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
  .def_buff = { .target = 0, .debuffp = 0, .amount = 0 }
};



/* ------------------------------------------------------------------------- */

static const double BUFF_MOD[] = {
  0.5000000, 0.5714286, 0.6666667, 0.8000000,  /* Debuff */
  1.0000000,
  1.2500000, 1.5000000, 1.7500000, 2.0000000   /*  Buff  */
};

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

  static inline void
apply_buff( buff_state_t * buff_state, buff_t buff )
{
  /* Attack */
  if ( buff.atk_buff.debuffp )
    {
      buff_state->atk_buff_lv =
        max( B_4_8, buff_state->atk_buff_lv - buff.atk_buff.amount );
    } else {
    buff_state->atk_buff_lv =
      min( B_8_4, buff_state->atk_buff_lv + buff.atk_buff.amount );
  }
  /* Defense */
  if ( buff.def_buff.debuffp )
    {
      buff_state->def_buff_lv =
        max( B_4_8, buff_state->def_buff_lv - buff.def_buff.amount );
    } else {
    buff_state->def_buff_lv =
      min( B_8_4, buff_state->def_buff_lv + buff.def_buff.amount );
  }
}


/* ------------------------------------------------------------------------- */

/**
 * As of [2020-08-22] there are 342 moves
 */
struct base_move_s {
  uint16_t move_id;
  ptype_t  type;
  bool     is_fast : 1;
  uint8_t  power;   /* NOTE: These values are not always the same for PvP/PvE */
  uint8_t  energy;  /* NOTE: These values are not always the same for PvP/PvE */
} packed;
typedef struct base_move_s  base_move_t;

static const base_move_t NO_MOVE = {
  .move_id = 0,
  .type    = PT_NONE,
  .is_fast = false,
  .power   = 0,
  .energy  = 0
};

#define as_base_move( child_move )                                            \
  ( (base_move_t) { .move_id = ( child_move ).move_id,                        \
                    .type    = ( child_move ).type,                           \
                    .is_fast = ( child_move ).is_fast,                        \
                    .power   = ( child_move ).power,                          \
                    .energy  = ( child_move ).energy,                         \
                  } )


/* ------------------------------------------------------------------------- */

struct pve_move_s {
  base_move_t;           /* Inherit */
  uint16_t    cooldown;  /* ms */
} packed;
typedef struct pve_move_s  pve_move_t;

static const pve_move_t NO_MOVE_PVE = {
  NO_MOVE,
  .cooldown = 0
};


/* ------------------------------------------------------------------------- */

struct pvp_charged_move_s {
  base_move_t;       /* Inherit */
  buff_t      buff;  /* A pointer could be used, but it costs more */
} packed;
typedef struct pvp_charged_move_s  pvp_charged_move_t;

static const pvp_charged_move_t NO_MOVE_PVP_CHARGED = {
  NO_MOVE,
  .buff    = NO_BUFF
};


/* ------------------------------------------------------------------------- */

struct pvp_fast_move_s {
  base_move_t;            /* Inherit */
  uint8_t     turns : 2;  /* 1-4 */
} packed;
typedef struct pvp_fast_move_s  pvp_fast_move_t;

static const pvp_fast_move_t NO_MOVE_PVP_FAST = { NO_MOVE, .turns = 0 };


/* ------------------------------------------------------------------------- */

/**
 * Meant to be held in data storage for reference.
 * Should be able to construct both pvp/pve moves from this data.
 */
struct store_move_s {
  char *         name;
  ptype_t        type;
  bool           is_fast : 1;
  uint16_t       move_id;
  uint16_t       cooldown;     /* PvE seconds, PvP turns ( Fast Move ) */
  uint8_t        pve_power;
  uint8_t        pvp_power;
  uint8_t        pve_energy;
  uint8_t        pvp_energy;
  buff_t         buff;
  UT_hash_handle hh_name;
  UT_hash_handle hh_move_id;
};
typedef struct store_move_s  store_move_t;

  static inline store_key_t
move_store_key( store_move_t * move )
{
  return (store_key_t) {
    .key_type = STORE_NUM,
    .val_type = STORE_MOVE,
    .data_h0  = move->move_id,
    .data_h1  = 0
  };
}

  static inline store_key_t
move_id_store_key( uint16_t move_id )
{
  return (store_key_t) {
    .key_type = STORE_NUM,
    .val_type = STORE_MOVE,
    .data_h0  = move_id,
    .data_h1  = 0
  };
}


/* ------------------------------------------------------------------------- */

  static inline pve_move_t
pve_move_from_store( store_move_t * stored )
{
  assert( stored != NULL );
  pve_move_t move = {
    .move_id  = stored->move_id,
    .type     = stored->type,
    .is_fast  = stored->is_fast,
    .power    = stored->pve_power,
    .energy   = stored->pve_energy,
    .cooldown = stored->cooldown
  };
  return move;
}

  static inline pvp_charged_move_t
pvp_charged_move_from_store( store_move_t * stored )
{
  assert( stored != NULL );
  pvp_charged_move_t move = {
    .move_id = stored->move_id,
    .type    = stored->type,
    .is_fast = stored->is_fast,
    .power   = stored->pvp_power,
    .energy  = stored->pvp_energy,
    .buff    = stored->buff
  };
  return move;
}

  static inline pvp_fast_move_t
pvp_fast_move_from_store( store_move_t * stored )
{
  assert( stored != NULL );
  pvp_fast_move_t move = {
    .move_id = stored->move_id,
    .type    = stored->type,
    .is_fast = stored->is_fast,
    .power   = stored->pvp_power,
    .energy  = stored->pvp_energy,
    .turns   = stored->cooldown
  };
  return move;
}


/* ------------------------------------------------------------------------- */

  static int
fprint_buff( FILE * stream, const buff_t * buff )
{
  int pc = 0;
  pc += fprintf( stream, "{ attack:  { target: " );
  if ( buff->atk_buff.target == 1 ) pc += fprintf( stream, "OPPONENT" );
  else                              pc += fprintf( stream, "SELF" );
  pc += fprintf( stream, ", amount: %d", decode_stat_buff( buff->atk_buff ) );

  pc += fprintf( stream, " },\n          defense: { target: " );
  if ( buff->def_buff.target == 1 ) pc += fprintf( stream, "OPPONENT" );
  else                              pc += fprintf( stream, "SELF" );
  pc += fprintf( stream, ", amount: %d", decode_stat_buff( buff->def_buff ) );
  pc += fprintf( stream, " },\n          chance: " );
  switch ( buff->chance )
    {
    case bc_1000: pc += fprintf( stream, "1.0" ); break;
    case bc_0500: pc += fprintf( stream, "0.5" ); break;
    case bc_0300: pc += fprintf( stream, "0.3" ); break;
    case bc_0125: pc += fprintf( stream, "0.125" ); break;
    case bc_0100: pc += fprintf( stream, "0.1" ); break;
    case bc_0000: pc += fprintf( stream, "0.0" ); break;
    }
  pc += fprintf( stream, "\n        }" );
  return pc;
}
#define print_buff( BUFF )  fprint_buff( stdout, ( BUFF ) )


/* ------------------------------------------------------------------------- */

  static int
fprint_buff_json( FILE * stream, const buff_t * buff )
{
  int pc = 0;
  pc += fprintf( stream, "{ \"attack\":  { \"target\": " );
  if ( buff->atk_buff.target == 1 ) pc += fprintf( stream, "\"OPPONENT\"" );
  else                              pc += fprintf( stream, "\"SELF\"" );
  pc += fprintf( stream, ", \"amount\": %d", decode_stat_buff( buff->atk_buff ) );

  pc += fprintf( stream, " },\n            \"defense\": { \"target\": " );
  if ( buff->def_buff.target == 1 ) pc += fprintf( stream, "\"OPPONENT\"" );
  else                              pc += fprintf( stream, "\"SELF\"" );
  pc += fprintf( stream, ", \"amount\": %d", decode_stat_buff( buff->def_buff ) );
  pc += fprintf( stream, " },\n            \"chance\": " );
  switch ( buff->chance )
    {
    case bc_1000: pc += fprintf( stream, "1.0" ); break;
    case bc_0500: pc += fprintf( stream, "0.5" ); break;
    case bc_0300: pc += fprintf( stream, "0.3" ); break;
    case bc_0125: pc += fprintf( stream, "0.125" ); break;
    case bc_0100: pc += fprintf( stream, "0.1" ); break;
    case bc_0000: pc += fprintf( stream, "0.0" ); break;
    }
  pc += fprintf( stream, "\n          }" );
  return pc;
}
#define print_buff_json( BUFF )  fprint_buff_json( stdout, ( BUFF ) )


/* ------------------------------------------------------------------------- */

  static int
fprint_store_move( FILE * stream, const store_move_t * move )
{
  int pc = 0;
  pc += fprintf( stream, "(store_move_t) {\n" );
  pc += fprintf( stream, "  name: %s,\n", move->name );
  pc += fprintf( stream, "  type: %s,\n", get_ptype_name( move->type ) );
  pc += fprintf( stream, "  is_fast: %d,\n", move->is_fast );
  pc += fprintf( stream, "  move_id: %d,\n", move->move_id );
  pc += fprintf( stream, "  cooldown: %d,\n", move->cooldown );
  pc += fprintf( stream, "  pve_power: %d,\n", move->pve_power );
  pc += fprintf( stream, "  pvp_power: %d,\n", move->pvp_power );
  pc += fprintf( stream, "  pve_energy: %d,\n", move->pve_energy );
  pc += fprintf( stream, "  pvp_energy: %d,\n", move->pvp_energy );
  pc += fprintf( stream, "  buff: " );
  if ( ( move->buff.atk_buff.amount == 0 ) &&
       ( move->buff.def_buff.amount == 0 )
     ) pc += fprintf( stream, "NO_BUFF" );
  else pc += fprint_buff( stream, & move->buff );
  pc += fprintf( stream, "\n}");
  return pc;
}
#define print_store_move( MOVE )  fprint_store_move( stdout, ( MOVE ) )


/* ------------------------------------------------------------------------- */

  static int
fprint_store_move_json( FILE * stream, const store_move_t * move )
{
  int pc = 0;
  pc += fprintf( stream, "{\n" );
  pc += fprintf( stream, "  \"name\": \"%s\",\n", move->name );
  pc += fprintf( stream,
                 "  \"type\": \"%s\",\n",
                 get_ptype_name( move->type )
               );
  pc += fprintf( stream, "  \"is_fast\": %d,\n", move->is_fast );
  pc += fprintf( stream, "  \"move_id\": %d,\n", move->move_id );
  pc += fprintf( stream, "  \"cooldown\": %d,\n", move->cooldown );
  pc += fprintf( stream, "  \"pve_power\": %d,\n", move->pve_power );
  pc += fprintf( stream, "  \"pvp_power\": %d,\n", move->pvp_power );
  pc += fprintf( stream, "  \"pve_energy\": %d,\n", move->pve_energy );
  pc += fprintf( stream, "  \"pvp_energy\": %d,\n", move->pvp_energy );
  pc += fprintf( stream, "  \"buff\": " );
  if ( ( move->buff.atk_buff.amount == 0 ) &&
       ( move->buff.def_buff.amount == 0 )
     ) pc += fprint_buff_json( stream, & NO_BUFF );
  else pc += fprint_buff_json( stream, & move->buff );
  pc += fprintf( stream, "\n}");
  return pc;
}
#define print_store_move_json( MOVE )  fprint_store_move_json( stdout, ( MOVE ) )


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* moves.h */

/* vim: set filetype=c : */
