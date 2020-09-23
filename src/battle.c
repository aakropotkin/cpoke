/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include "battle.h"
#include "player.h"
#include "pvp_action.h"


/* ------------------------------------------------------------------------- */


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
