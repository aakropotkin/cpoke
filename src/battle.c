/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include "battle.h"
#include "player.h"
#include "pvp_action.h"
#include <time.h>


/* ------------------------------------------------------------------------- */

  pvp_action_t
decide_action( bool decide_p1, const pvp_battle_t * battle )
{
  assert( battle != NULL );

  pvp_action_t action = ACT_NULL;
  ai_status_t  rsl    = AI_NULL_STATUS;

  /* If cooldown from previous fast move is still unsatisfied, player
   * must wait. */
  if ( decide_p1 && ( 0 < get_active_pokemon( battle->p1 ).cooldown ) )
    {
      return WAIT;
    }
  if ( ( ! decide_p1 ) && ( 0 < get_active_pokemon( battle->p2 ).cooldown ) )
    {
      return WAIT;
    }

  /* Use AI's Decide Action function */
  if ( decide_p1 )
    {
      rsl = battle->p1->ai->decide_action( decide_p1,
                                           battle,
                                           & action,
                                           battle->p1->ai->aux
                                         );
    }
  else
    {
      rsl = battle->p2->ai->decide_action( decide_p1,
                                           battle,
                                           & action,
                                           battle->p2->ai->aux
                                         );
    }
  assert( rsl == AI_SUCCESS );

  return action;
}



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

  void
do_switch( bool is_switch1, pvp_player_t * player )
{
  for ( uint8_t i = 0; i < 3; i++ )
    {
      if ( player->active_pokemon == i ) continue;
      if ( player->team[i].hp <= 0 )     continue;
      if ( is_switch1 )
        {
          player->active_pokemon = i;
          break;
        }
      else
        {
          is_switch1 = true;
        }
    }
}


/* ------------------------------------------------------------------------- */

/**
 * When a pokemon faints the battle manager can process turns much more
 * efficiently by skipping many of the usual checks that are performed during
 * a `NEUTRAL' phase.
 * This handler is optional, but takes advantage of those skipped checks,
 * returning once both players have pokemon back on the field.
 * <p>
 * This function does not check to see if a battle is over, because the aim here
 * is to cut down on unneccesary checks, we assume the caller has checked to
 * ensure that both players still have remaining pokemon.
 */
  void
handle_faints( bool p1_mon_alive, bool p2_mon_alive, pvp_battle_t * battle )
{
  uint8_t        swap_timeout = 0;
  pvp_player_t * target       = NULL;

  if ( !( p1_mon_alive || p2_mon_alive ) ) /* Both fainted. Wait for swap */
    {
      swap_timeout  = SWITCH_TIMEOUT;
      battle->phase = SUSPEND_SWITCH_TIE;
      battle->p1_action = decide_action( true, battle );
      battle->p2_action = decide_action( false, battle );
      /* Wait for both to pick */
      while ( ( 0 < swap_timeout-- )        &&
              ( battle->p1_action == WAIT ) ||
              ( battle->p2_action == WAIT )
            )
        {
          eval_turn( battle );
          battle->turn++;
          decr_switch_timer( battle->p1, 1 );
          decr_switch_timer( battle->p2, 1 );

          battle->p1_action = ACT_NULL;
          battle->p2_action = ACT_NULL;
          battle->p1_action = decide_action( true, battle );
          battle->p2_action = decide_action( false, battle );
        }
      /* Force swap if they ran out the clock playing chicken */
      if ( battle->p1_action == WAIT ) battle->p1_action = SWITCH1;
      if ( battle->p2_action == WAIT ) battle->p2_action = SWITCH1;
    }
  else if ( ! ( p1_mon_alive && p2_mon_alive ) )
    { /* Only 1 fainted. No playing chicken. But player can eat the clock */
      swap_timeout = SWITCH_TIMEOUT;
      while ( ( 0 < swap_timeout-- ) &&
              ( ( p1_mon_alive && ( battle->p2_action == WAIT ) ) ||
                ( p2_mon_alive && ( battle->p1_action == WAIT ) )
              )
            )
        {
          eval_turn( battle );
          battle->turn++;
          decr_switch_timer( battle->p1, 1 );
          decr_switch_timer( battle->p2, 1 );
          /* Decrement cooldown for living pokemon */
          if ( p1_mon_alive ) decr_cooldown( battle->p1, 1 );
          else                decr_cooldown( battle->p2, 1 );

          battle->p1_action = ACT_NULL;
          battle->p2_action = ACT_NULL;
          battle->p1_action = decide_action( true, battle );
          battle->p2_action = decide_action( false, battle );
        }
      /* Force a swap if they ran out the clock */
      if ( p1_mon_alive && ( battle->p2_action == WAIT ) )
        {
          battle->p2_action = SWITCH1;
        }
      else if ( p2_mon_alive && ( battle->p1_action == WAIT ) )
        {
          battle->p1_action = SWITCH1;
        }
    }

  assert( is_active_alive( battle->p1 ) );
  assert( is_active_alive( battle->p2 ) );
}


/* ------------------------------------------------------------------------- */

  void
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
      move_idx = acttomidx( battle->p1_action );
    }
  else
    {
      attacker = battle->p2;
      defender = battle->p1;
      move_idx = acttomidx( battle->p2_action );
    }

  energy = get_active_move_energy( attacker, move_idx );
  assert( energy <= get_active_energy( attacker ) );
  decr_energy( attacker, energy );

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

  damage = get_pvp_damage( move_idx,
                           & get_active_pokemon( attacker ),
                           & get_active_pokemon( defender )
                         );
  uint_minus( get_active_pokemon( defender ).hp, damage );

  /* FIXME: If CMP loser is alive, allow them to swap to
   *        cancel charged attack                        */
}


/* ------------------------------------------------------------------------- */

  void
do_fast( bool is_attacker1, pvp_battle_t * battle )
{
  assert( battle != NULL );

  pvp_pokemon_t * attacker = NULL;
  pvp_pokemon_t * defender = NULL;
  uint16_t        damage   = 0;

  if ( is_attacker1 )
    {
      attacker = & get_active_pokemon( battle->p1 );
      defender = & get_active_pokemon( battle->p2 );
    }
  else
    {
      attacker = & get_active_pokemon( battle->p2 );
      defender = & get_active_pokemon( battle->p1 );
    }

  damage = get_pvp_damage( M_FAST, attacker, defender );

  if ( damage <= defender->hp ) defender->hp -= damage;
  else                          defender->hp = 0;

  attacker->cooldown += attacker->fast_move.turns;
  attacker->energy   += attacker->fast_move.energy;
}


/* ------------------------------------------------------------------------- */

  bool
is_p1_cmp_winner( pvp_battle_t * battle )
{
  assert( battle != NULL );
  uint16_t a1 = 0;
  uint16_t a2 = 0;
  switch ( battle->cmp_rule )
    {
    case CMP_IDEAL:
      a1 = get_active_pokemon( battle->p2 ).stats.attack;
      a2 = get_active_pokemon( battle->p1 ).stats.attack;
      /* In a perfect tie randomize */
      if ( a1 == a2 )
        {
          srand( time( 0 ) );
          return ( rand() % 1 );
        }
      else
        {
          return a2 < a1;
        }

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
  bool
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

  /* Force pokemon with cooldowns to wait, regardless of their decided action.
   * An exception is for forced swaps */
  if ( ( a1 != WAIT ) && ( has_cooldown( battle->p1 ) )       &&
       ( ! ( is_switch( a1 ) && can_switch( battle->p1 ) ) )
     )
    {
      battle->p1_action = WAIT;
      a1 = WAIT;
    }
  if ( ( a2 != WAIT ) && ( has_cooldown( battle->p2 ) )       &&
       ( ! ( is_switch( a2 ) && can_switch( battle->p2 ) ) )
     )
    {
      battle->p2_action = WAIT;
      a2 = WAIT;
    }

  /* Shortcut to skip evaluation when both players waited */
  if ( ( a1 == WAIT ) && ( a2 == WAIT ) ) return false;

  switch ( battle->phase )
    {
    case NEUTRAL:
      /* Handle Switches first. These are not switches resulting from faints. */
      if ( is_switch( a1 ) )
        {
          assert( can_switch( battle->p1 ) );
          do_switch( ( battle->p1_action == SWITCH1 ), battle->p1 );
          start_switch_timer( battle->p1 );
        }
      if ( is_switch( a2 ) )
        {
          assert( can_switch( battle->p2 ) );
          do_switch( ( battle->p2_action == SWITCH1 ), battle->p2 );
          start_switch_timer( battle->p2 );
        }

      /* Do fast attacks. These always go before charged attacks. */
      if ( a1 == FAST ) do_fast( true, battle );
      if ( a2 == FAST ) do_fast( false, battle );

      /* Handle charged moves */
      if ( is_charged( a1 ) && is_charged( a2 ) )
        {
          /* Find CMP winner */
          if ( is_p1_cmp_winner( battle ) )
            {
              do_charged( true, battle );
              if ( is_active_alive( battle->p2 ) ) do_charged( false, battle );
            }
          else
            {
              do_charged( false, battle );
              if ( is_active_alive( battle->p1 ) ) do_charged( true, battle );
            }
        }
      else if ( is_charged( a1 ) )
        {
          do_charged( true, battle );
        }
      else if ( is_charged( a2 ) )
        {
          do_charged( false, battle );
        }
      break;

    case SUSPEND_SWITCH_TIE:
      /* AIs are free to wait during this period, so loop until it's done. */
      if ( is_switch( a1 ) )
        {
          do_switch( ( battle->p1_action == SWITCH1 ), battle->p1 );
        }
      if ( is_switch( a2 ) )
        {
          do_switch( ( battle->p2_action == SWITCH1 ), battle->p2 );
        }
      break;
    }

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

  assert( is_valid_action( true, battle->p1_action, battle ) );
  assert( is_valid_action( false, battle->p2_action, battle ) );

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

  bool           p1_mon_alive = true;
  bool           p2_mon_alive = true;

  while( eval_turn( battle ) == false )
    {
      /* Decrement turn counter, switch timer, and cooldowns */
      decr_switch_timer( battle->p1, 1 );
      decr_switch_timer( battle->p2, 1 );
      decr_cooldown( battle->p1, 1 );
      decr_cooldown( battle->p2, 1 );
      battle->turn++;

      battle->p1_action = ACT_NULL;
      battle->p2_action = ACT_NULL;

      /* Check for fainted pokemon */
      p1_mon_alive = is_active_alive( battle->p1 );
      p2_mon_alive = is_active_alive( battle->p2 );
      if ( !( p1_mon_alive && p2_mon_alive ) )
        {
          handle_faints( p1_mon_alive, p2_mon_alive, battle );
          p1_mon_alive = true;
          p2_mon_alive = true;
        }

    }

  return battle->turn;
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
      return ( battle->phase == NEUTRAL ) && is_active_alive( self );

    case WAIT:
      return true;

    case CHARGED1:
      return ( battle->phase == NEUTRAL ) && is_active_alive( self ) &&
             ( get_pvp_mon_move_energy( get_active_pokemon( self ),
                                        M_CHARGED1
                                      ) <=
               get_active_pokemon( self ).energy
             );

    case CHARGED2:
      return ( battle->phase == NEUTRAL ) && is_active_alive( self )      &&
             ( get_active_pokemon( self ).charged_moves[1].move_id != 0 ) &&
             ( get_pvp_mon_move_energy( get_active_pokemon( self ),
                                        M_CHARGED2
                                      ) <=
               get_active_pokemon( self ).energy
             );

    case SWITCH1:
      return !!( is_active_alive( self ) ) < get_remaining_pokemon( self );

    case SWITCH2:
      return ( 1 + !!( is_active_alive( self ) ) ) <
             get_remaining_pokemon( self );

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
