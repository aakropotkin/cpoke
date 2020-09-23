/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include "battle.h"
#include "player.h"
#include "pvp_action.h"


/* ------------------------------------------------------------------------- */

  bool
is_battle_over( pvp_battle_t * battle )
{
  assert( battle != NULL );
  return ( battle->phase == GAME_OVER )               ||
         ( get_remaining_pokemon( battle->p1 ) <= 0 ) ||
         ( get_remaining_pokemon( battle->p2 ) <= 0 );
}


/* ------------------------------------------------------------------------- */

  bool
is_p1_winner( pvp_battle_t * battle )
{
  assert( battle != NULL );
  assert( is_battle_over( battle ) == true );
  return ( get_remaining_pokemon( battle->p2 ) <= 0 ) &&
         ( 0 < get_remaining_pokemon( battle->p1 ) );
}


/* ------------------------------------------------------------------------- */

  pvp_player_t *
get_battle_winner( pvp_battle_t * battle )
{
  assert( battle != NULL );
  /* Detect a tie */
  if ( ( get_remaining_pokemon( battle->p1 ) == 0 ) &&
       ( get_remaining_pokemon( battle->p2 ) == 0 )
     ) return NULL;
  return is_p1_winner( battle ) ? battle->p1 : battle->p2;
}


/* ------------------------------------------------------------------------- */

  bool
eval_turn( pvp_battle_t * battle )
{
  assert( battle != NULL );
  assert( battle->p1_action != ACT_NULL );
  assert( battle->p2_action != ACT_NULL );
}



/* ------------------------------------------------------------------------- */

  bool
is_valid_action( bool decide_p1, pvp_action_t action, pvp_battle_t * battle )
{
  assert( battle != NULL );

  pvp_player_t * self = decide_p1 ? battle->p1 : battle->p2;

  switch( action )
    {
    case FAST:
      return ( battle->phase == NEUTRAL ) &&
             ( 0 < get_active_pokemon( *self ).hp );

    case WAIT:
      return true;

    case CHARGED1:
      return ( battle->phase == NEUTRAL )                            &&
             ( 0 < get_active_pokemon( *self ).hp )                  &&
             ( get_pvp_mon_move_energy( get_active_pokemon( *self ),
                                        M_CHARGED1
                                      ) <=
               get_active_pokemon( *self ).stored_energy
             );

    case CHARGED2:
      return ( battle->phase == NEUTRAL )                                  &&
             ( 0 < get_active_pokemon( *self ).hp )                        &&
             ( get_active_pokemon( *self ).charged_moves[1].move_id != 0 ) &&
             ( get_pvp_mon_move_energy( get_active_pokemon( *self ),
                                        M_CHARGED2
                                      ) <=
               get_active_pokemon( *self ).stored_energy
             );

    case SWITCH1:
      return ( !!( 0 < get_active_pokemon( *self ).hp ) <
               get_remaining_pokemon( self )
             );

    case SWITCH2:
      return ( ( 1 + !!( 0 < get_active_pokemon( *self ).hp ) ) <
               get_remaining_pokemon( self )
             );

    case SHIELD:
      return ( battle->phase == SUSPEND_CHARGED ) &&
             ( 0 < self->shields );
    }

  return false;
}


/* ------------------------------------------------------------------------- */

  pvp_action_mask_t
valid_actions( bool decide_p1, pvp_battle_t * battle )
{
  pvp_action_mask_t valids = ACT_NULL_M;
  for ( uint8_t a = 1; a < NUM_PVP_ACTIONS; a++ )
     {
       if ( is_valid_action( decide_p1, a, battle ) )
         {
           valids |= get_pvp_act_mask( (pvp_action_t) a );
         }
     }
  return valids;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
