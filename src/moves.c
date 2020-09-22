/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include "ptypes.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>
#include "moves.h"

/* ------------------------------------------------------------------------- */

  void
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

  static inline int
_move_from_store( store_t * store, uint16_t move_id, store_move_t * move )
{
  assert( move != NULL );
  if ( store == NULL )                         return STORE_ERROR_BAD_VALUE;
  if ( !( store->flags & SF_STANDARD_KEY_M ) ) return STORE_ERROR_BAD_VALUE;

  const store_key_t key = move_id_store_key( move_id );
  assert( key.key_type == STORE_NUM );
  assert( key.val_type == STORE_MOVE );
  assert( key.data_h0 == move_id );

  move = NULL;

  int rsl = store->get( store, key, (void **) & move );
  if ( rsl != STORE_SUCCESS ) return rsl;
  assert( move->move_id == move_id );
  return rsl;
}



/* ------------------------------------------------------------------------- */

  int
pvp_charged_move_from_store( store_t            * store,
                             uint16_t             move_id,
                             pvp_charged_move_t * move
                           )
{
  store_move_t * smove = NULL;
  int rsl = _move_from_store( store, move_id, smove );
  if ( rsl != STORE_SUCCESS ) return rsl;
  *move = pvp_charged_move_from_store_move( smove );
  return rsl;
}


/* ------------------------------------------------------------------------- */

  int
pvp_fast_move_from_store( store_t         * store,
                          uint16_t          move_id,
                          pvp_fast_move_t * move
                        )
{
  store_move_t * smove = NULL;
  int rsl = _move_from_store( store, move_id, smove );
  if ( rsl != STORE_SUCCESS ) return rsl;
  *move = pvp_fast_move_from_store_move( smove );
  return rsl;
}


/* ------------------------------------------------------------------------- */

  int
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


/* ------------------------------------------------------------------------- */

  int
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


/* ------------------------------------------------------------------------- */

  int
fprint_buff_c( FILE * stream, const buff_t * buff )
{
  int pc = 0;
  pc += fprintf( stream,
                 "{ .atk_buff =  { .target = %d, .debuffp = %d, .amount = %d }"
                 ",\n              .atk_buff = { .target = %d, .debuffp = %d, "
                 ".amount = %d },\n              .chance = ",
                 buff->atk_buff.target,
                 buff->atk_buff.debuffp,
                 buff->atk_buff.amount,
                 buff->def_buff.target,
                 buff->def_buff.debuffp,
                 buff->def_buff.amount
               );
  switch ( buff->chance )
    {
    case bc_1000: pc += fprintf( stream, "bc_1000" ); break;
    case bc_0500: pc += fprintf( stream, "bc_0500" ); break;
    case bc_0300: pc += fprintf( stream, "bc_0300" ); break;
    case bc_0125: pc += fprintf( stream, "bc_0125" ); break;
    case bc_0100: pc += fprintf( stream, "bc_0100" ); break;
    case bc_0000: pc += fprintf( stream, "bc_0000" ); break;
    }
  pc += fprintf( stream, "\n            }" );
  return pc;
}


/* ------------------------------------------------------------------------- */

  int
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


/* ------------------------------------------------------------------------- */

  int
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


/* ------------------------------------------------------------------------- */

  int
fprint_store_move_c( FILE * stream, const store_move_t * move )
{
  int pc = 0;
  pc += fprintf( stream, "{\n" );
  pc += fprintf( stream, "  .name = \"%s\",\n", move->name );
  pc += fprintf( stream, "  .type = %s,\n", get_ptype_name( move->type ) );
  pc += fprintf( stream, "  .is_fast = %d,\n", move->is_fast );
  pc += fprintf( stream, "  .move_id = %d,\n", move->move_id );
  pc += fprintf( stream, "  .cooldown = %d,\n", move->cooldown );
  pc += fprintf( stream, "  .pve_power = %d,\n", move->pve_power );
  pc += fprintf( stream, "  .pvp_power = %d,\n", move->pvp_power );
  pc += fprintf( stream, "  .pve_energy = %d,\n", move->pve_energy );
  pc += fprintf( stream, "  .pvp_energy = %d,\n", move->pvp_energy );
  pc += fprintf( stream, "  .buff = " );
  if ( ( move->buff.atk_buff.amount == 0 ) &&
       ( move->buff.def_buff.amount == 0 )
     ) pc += fprintf( stream, "NO_BUFF" );
  else pc += fprint_buff_c( stream, & move->buff );
  pc += fprintf( stream, "\n}");
  return pc;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
