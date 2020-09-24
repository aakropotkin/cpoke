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

  inline void
do_switch( bool is_switch1, pvp_player_t * player )
{
  for ( uint8_t i = 0; i < 3; i++ )
    {
      if ( player->active_pokemon == i ) continue;
      if ( player->team[i].hp <= 0 )     continue;
      if ( is_switch1 )
        {
          battle->p1.active_pokemon = i;
          break;
        }
      else
        {
          is_switch1 = true;
        }
    }
}


/* ------------------------------------------------------------------------- */

  inline void
do_charged( bool is_attacker1, pvp_battle_t * battle )
{
  assert( battle != NULL );
  pvp_player_t * attacker   = NULL;
  pvp_player_t * defender   = NULL;
  pmove_idx_t    move_idx   = M_CHARGED1;
  uint16_t       energy     = 0;
  uint16_t       damage     = 0;
  pvp_action_t   reaction   = ACT_NULL;

  if ( is_attacker1 )
    {
      attacker = battle->p1;
      defender = battle->p2;
      if ( battle->p1_action == CHARGED2 ) move_idx = M_CHARGED2;
    }
  else
    {
      attacker = battle->p2;
      defender = battle->p1;
      if ( battle->p2_action == CHARGED2 ) move_idx = M_CHARGED2;
    }

  energy = get_pvp_mon_move_energy( attacker, move_idx );
  assert( energy <= attacker->energy );
  attacker->energy -= energy;

  if ( 0 < defender->shields )
    {
      battle->phase = SUSPEND_CHARGED;
      reaction      = decide_action( ! is_attacker1, battle );
      battle->phase = NEUTRAL;
      if ( reaction == SHIELD )
        {
          /* FIXME Calculate that tiny bit of damage that leaks */
          use_shield( defender );
          return;
        }
    }

  damage = get_pvp_damage( move_idx, attacker, defender );
  if ( defender->hp <= damage ) defender->hp = 0;
  else                          defender->hp -= damage;

  /* FIXME: If CMP loser is alive, allow them to swap to
   *        cancel charged attack                        */
}


/* ------------------------------------------------------------------------- */

  bool
is_p1_cmp_winner( pvp_battle_t * battle )
{
  assert( battle != NULL );
  switch ( battle->cmp_rule )
    {
    case CMP_IDEAL:
      return get_active_pokemon( *battle->p2 ).stats.attack <=
             get_active_pokemon( *battle->p1 ).stats.attack;

    case CMP_ALTERNATE:
      battle->cmp_alt_state = ! battle->cmp_alt_state;
      return ! battle->cmp_alt_state;

    case CMP_FAVOR_P1:
      return true;

    case CMP_FAVOR_P2:
      return false;

    default:
      fprintf( stderr, "Encountered unknown CMP Rule!\n" );
      return false;
    }
}


/* ------------------------------------------------------------------------- */

/**
 * Simulated battles only support `NEUTRAL', `SUSPEND_CHARGED', and
 * `SUSPEND_SWITCH_TIE' phases.
 * However, you'll only encounter a `SUSPEND_CHARGED' phase from within the AI
 * when a reaction is being decided, it should never be used as an input here.
 */
  inline bool
eval_turn_simulated( pvp_battle_t * battle )
{
  assert( battle->phase != COUNTDOWN );
  assert( battle->phase != SUSPEND_CHARGED_ATTACK );
  assert( battle->phase != SUSPEND_CHARGED_SHIELD );
  assert( battle->phase != SUSPEND_CHARGED_NO_SHIELD );
  assert( battle->phase != SUSPEND_SWITCH_P1 );
  assert( battle->phase != SUSPEND_SWITCH_P2 );
  assert( battle->phase != GAME_OVER );
  assert( battle->phase != SUSPEND_CHARGED );

  pvp_action_t    a1       = battle->p1_action;
  pvp_action_t    a2       = battle->p2_action;
  pvp_pokemon_t * attacker = NULL;
  pvp_pokemon_t * defender = NULL;
  uint16_t        damage   = 0;
  uint16_t        energy   = 0;

  switch ( battle->phase )
    {
    case NEUTRAL:
      /* Handle Switches first. These are not switches resulting from faints. */
      if ( ( a1 == SWITCH1 ) || ( a1 == SWITCH2 ) )
        {
          assert( battle->p1->switch_turns <= 0 );
          do_switch( ( battle->p1_action == SWITCH1 ), battle->p1 );
          start_switch_timer( battle->p1 );
        }
      else
        {
          decr_switch_timer( battle->p1 );
        }
      if ( ( a2 == SWITCH1 ) || ( a2 == SWITCH2 ) )
        {
          assert( battle->p2->switch_turns <= 0 );
          do_switch( ( battle->p2_action == SWITCH1 ), battle->p2 );
          start_switch_timer( battle->p2 );
        }
      else
        {
          decr_switch_timer( battle->p2 );
        }

      /* Do fast attacks. These always go before charged attacks. */
      if ( a1 == FAST )
        {
          attacker = & get_active_pokemon( * battle->p1 );
          defender = & get_active_pokemon( * battle->p2 );
          damage   = get_pvp_damage( M_FAST, attacker, defender );
          /* I'm intentionally avoiding a macro here to avoid subexpression
           * overhead */
          if ( defender->hp <= damage ) defender->hp = 0;
          else                          defender->hp -= damage;
        }
      if ( a2 == FAST )
        {
          attacker = & get_active_pokemon( * battle->p2 );
          defender = & get_active_pokemon( * battle->p1 );
          damage   = get_pvp_damage( M_FAST, attacker, defender );
          /* I'm intentionally avoiding a macro here to avoid subexpression
           * overhead */
          if ( defender->hp <= damage ) defender->hp = 0;
          else                          defender->hp -= damage;
        }

      /* Handle charged moves */
      if ( ( ( a1 == CHARGED1 ) || ( a1 == CHARGED2 ) ) &&
           ( ( a2 == CHARGED1 ) || ( a2 == CHARGED2 ) )
         )
        {
          /* Find CMP winner */
          if ( is_p1_cmp_winner( battle ) )
            {
              do_charged( true, battle );
              if ( 0 < get_active_pokemon( * battle->p2 ).hp )
                {
                  do_charged( false, battle );
                }
            }
          else
            {
              do_charged( false, battle );
              if ( 0 < get_active_pokemon( * battle->p1 ).hp )
                {
                  do_charged( true, battle );
                }
            }
        }
      else if ( ( a1 == CHARGED1 ) || ( a1 == CHARGED2 ) )
        {
          do_charged( true, battle );
        }
      else if ( ( a2 == CHARGED1 ) || ( a2 == CHARGED2 ) )
        {
          do_charged( false, battle );
        }
      break;

    case SUSPEND_SWITCH_TIE:
      /* AIs are free to wait during this period, so loop until it's done. */
      if ( ( a1 == SWITCH1 ) || ( a1 == SWITCH2 ) )
        {
          do_switch( ( battle->p1_action == SWITCH1 ), battle->p1 );
        }
      if ( ( a2 == SWITCH1 ) || ( a2 == SWITCH2 ) )
        {
          do_switch( ( battle->p2_action == SWITCH1 ), battle->p2 );
        }
      break;
    }

  battle->turn++;

  return is_battle_over( battle );
}


/* ------------------------------------------------------------------------- */

  bool
eval_turn( pvp_battle_t * battle )
{
  assert( battle != NULL );
  /* It is the responsibility of `pvp_battle_init' to set first actions */
  assert( battle->p1_action != ACT_NULL );
  assert( battle->p2_action != ACT_NULL );

  assert( is_valid_action( true, battle.p1_action, & battle ) );
  assert( is_valid_action( false, battle.p2_action, & battle ) );

  /* Currently only `SIMULATE' battle mode is supported. */
  return eval_turn_simulated( battle );
}


/* ------------------------------------------------------------------------- */

  uint32_t
simulate_battle( pvp_battle_t * battle )
{
  assert( battle != NULL );
  assert( battle->phase == COUNTDOWN );

  /* Give opportunity to swap during countdown */
  battle->p1_action = decide_action( true, battle );
  battle->p2_action = decide_action( false, battle );

  bool    p1_mon_alive = true;
  bool    p2_mon_alive = true;
  uint8_t swap_timeout = 0;

  while( eval_turn( battle ) == false )
    {
      battle->p1_action = ACT_NULL;
      battle->p2_action = ACT_NULL;
      /* Check for fainted pokemon */
      p1_mon_alive = get_active_pokemon( * battle->p1 ).hp <= 0;
      p2_mon_alive = get_active_pokemon( * battle->p2 ).hp <= 0;
      if ( !( p1_mon_alive || p2_mon_alive ) )
        {
          swap_timeout  = SWITCH_TIMEOUT;
          battle->phase = SUSPEND_SWAP_TIE;
          battle->p1_action = decide_action( true, battle );
          battle->p2_action = decide_action( false, battle );
          /* Wait for both to pick */
          while ( ( 0 < swap_timeout-- )        &&
                  ( battle->p1_action == WAIT ) ||
                  ( battle->p2_action == WAIT )
                )
            {
              eval_turn( battle );
              battle->p1_action = decide_action( true, battle );
              battle->p2_action = decide_action( false, battle );
            }
          /* Force swap if they ran out the clock playing chicken */
          if ( battle->p1_action == WAIT ) battle->p1_action = SWITCH1;
          if ( battle->p2_action == WAIT ) battle->p2_action = SWITCH1;
        }
      else if ( ! p1_mon_alive )
        {
          swap_timeout = SWITCH_TIMEOUT;
        }
    }

  return battle->turns;
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
