/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"
#include "player.h"
#include "ptypes.h"
#include "pvp_action.h"
#include "util/test_util.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */


  static bool
test_is_valid_action( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;

  battle.p1 = & p1;
  battle.p2 = & p2;
  battle.phase = NEUTRAL;

  assert( p1.active_pokemon == 0 );
  p1.team[0].hp = 10;
  p1.team[0].charged_moves[0].energy = 10;
  p1.team[0].charged_moves[1].energy = 10;
  assert( p2.active_pokemon == 0 );
  p2.team[0].hp = 10;
  p2.team[0].charged_moves[0].energy = 10;
  p2.team[0].charged_moves[1].energy = 10;

  /* Waiting is always allowed */
  expect( is_valid_action( true, WAIT, & battle ) == true );
  expect( is_valid_action( false, WAIT, & battle ) == true );
  /* Fast attacking is permitted because of `NEUTRAL' phase */
  expect( is_valid_action( true, FAST, & battle ) == true );
  expect( is_valid_action( false, FAST, & battle ) == true );
  /* Not enough energy */
  expect( is_valid_action( true, CHARGED1, & battle ) == false );
  expect( is_valid_action( false, CHARGED1, & battle ) == false );
  expect( is_valid_action( true, CHARGED2, & battle ) == false );
  expect( is_valid_action( false, CHARGED2, & battle ) == false );
  /* Other pokemon have 0 hp, so switching is not allowed */
  expect( is_valid_action( true, SWITCH1, & battle ) == false );
  expect( is_valid_action( false, SWITCH1, & battle ) == false );
  expect( is_valid_action( true, SWITCH2, & battle ) == false );
  expect( is_valid_action( false, SWITCH2, & battle ) == false );
  /* Phase is not `SUSPEND_CHARGED' so shielding is not allowed */
  expect( is_valid_action( true, SHIELD, & battle ) == false );
  expect( is_valid_action( false, SHIELD, & battle ) == false );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_is_battle_over( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;

  battle.p1 = & p1;
  battle.p2 = & p2;
  battle.phase = NEUTRAL;

  assert( battle.p1->team[0].hp == 0 );
  assert( battle.p1->team[1].hp == 0 );
  assert( battle.p1->team[2].hp == 0 );
  assert( battle.p2->team[0].hp == 0 );
  assert( battle.p2->team[1].hp == 0 );
  assert( battle.p2->team[2].hp == 0 );

  expect( is_battle_over( & battle ) == true );

  battle.p1->team[0].hp = 1;
  expect( is_battle_over( & battle ) == true );

  battle.p2->team[0].hp = 1;
  expect( is_battle_over( & battle ) == false );

  battle.phase = GAME_OVER;
  expect( is_battle_over( & battle ) == true );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_is_p1_winner( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;

  battle.p1 = & p1;
  battle.p2 = & p2;
  battle.phase = NEUTRAL;

  assert( battle.p1->team[0].hp == 0 );
  assert( battle.p1->team[1].hp == 0 );
  assert( battle.p1->team[2].hp == 0 );
  assert( battle.p2->team[0].hp == 0 );
  assert( battle.p2->team[1].hp == 0 );
  assert( battle.p2->team[2].hp == 0 );

  /**
   * P2 is said to win ties, because GBL counts ties as losses for both
   * players, and we assume that the user is P1.
   */
  expect( is_p1_winner( & battle ) == false );

  battle.p1->team[0].hp = 1;
  expect( is_p1_winner( & battle ) == true );

  battle.p1->team[0].hp = 0;
  battle.p2->team[0].hp = 1;
  expect( is_p1_winner( & battle ) == false );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_get_battle_winner( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;

  battle.p1 = & p1;
  battle.p2 = & p2;
  battle.phase = NEUTRAL;

  assert( battle.p1->team[0].hp == 0 );
  assert( battle.p1->team[1].hp == 0 );
  assert( battle.p1->team[2].hp == 0 );
  assert( battle.p2->team[0].hp == 0 );
  assert( battle.p2->team[1].hp == 0 );
  assert( battle.p2->team[2].hp == 0 );

  /* Ties return `NULL' */
  expect( get_battle_winner( & battle ) == NULL );

  battle.p1->team[0].hp = 1;
  expect( get_battle_winner( & battle ) == ( & p1 ) );

  battle.p1->team[0].hp = 0;
  battle.p2->team[0].hp = 1;
  expect( get_battle_winner( & battle ) == ( & p2 ) );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_eval_turn( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;
  bool         over   = false;
  uint16_t     ohp1   = 0;
  uint16_t     ohp2   = 0;
  uint16_t     oen1   = 0;
  uint16_t     oen2   = 0;

  assert( p1.active_pokemon == 0 );
  assert( p2.active_pokemon == 0 );

  battle.p1    = & p1;
  battle.p2    = & p2;
  battle.phase = NEUTRAL;

  /* Make some fake pokemon */
  p1.team[0].hp            = 100;
  p1.team[0].level         = 20;
  p1.team[0].stats.attack  = 200;
  p1.team[0].stats.stamina = 100;
  p1.team[0].stats.defense = 100;
  p1.team[0].types         = NORMAL_M;
  p2.team[0]               = p1.team[0];
  p2.team[0].types         = FIRE_M;

  p1.team[0].fast_move.move_id  = 1; /* Fake */
  p1.team[0].fast_move.turns    = 1;
  p1.team[0].fast_move.type     = NORMAL;
  p1.team[0].fast_move.is_fast  = true;
  p1.team[0].fast_move.power    = 10;
  p1.team[0].fast_move.energy   = 3;
  p2.team[0].fast_move          = p1.team[0].fast_move;

  p1.team[0].charged_moves[0].move_id = 2;
  p1.team[0].charged_moves[0].type    = NORMAL;
  p1.team[0].charged_moves[0].is_fast = false;
  p1.team[0].charged_moves[0].power   = 100;
  p1.team[0].charged_moves[0].energy  = 50;
  p2.team[0].charged_moves[0]         = p1.team[0].charged_moves[0];

  /* Decisions must be set before `eval_turn' is called */
  battle.p1_action = FAST;
  battle.p2_action = FAST;
  /* Backup current hp and energy */
  ohp1 = p1.team[0].hp;
  ohp2 = p2.team[0].hp;
  oen1 = p1.team[0].energy;
  oen2 = p2.team[0].energy;
  /* Evaluate */
  over = eval_turn( & battle );
  expect( over == false );
  expect( oen1 < p1.team[0].energy );
  expect( oen2 < p2.team[0].energy );
  expect( p1.team[0].hp < ohp1 );
  expect( p2.team[0].hp < ohp2 );

  /* Make sure both players are unable to attack because of cooldown */
  assert( has_cooldown( & p1 ) );
  assert( has_cooldown( & p2 ) );
  assert( battle.p1_action == FAST );
  assert( battle.p2_action == FAST );
  /* Backup current hp and energy */
  ohp1 = p1.team[0].hp;
  ohp2 = p2.team[0].hp;
  oen1 = p1.team[0].energy;
  oen2 = p2.team[0].energy;
  over = eval_turn( & battle );
  expect( over == false );
  expect( oen1 == p1.team[0].energy );
  expect( oen2 == p2.team[0].energy );
  expect( ohp1 == p1.team[0].hp );
  expect( ohp2 == p2.team[0].hp );
  expect( battle.p1_action == WAIT );
  expect( battle.p2_action == WAIT );

  /* Decrement cooldowns to allow for actions to occur again */
  decr_cooldown( battle.p1, 1 );
  decr_cooldown( battle.p2, 1 );
  /* Clone pokemon to try switching, and confirm damage application */
  p1.team[1]       = p1.team[0];
  p1.team[1].hp    = 100;
  battle.p1_action = SWITCH1;
  battle.p2_action = FAST;
  over             = eval_turn( & battle );
  expect( over == false );
  expect( oen1 == p1.team[0].energy );
  expect( oen1 == p1.team[1].energy );
  expect( oen2 <  p2.team[0].energy );
  expect( ohp1 == p1.team[0].hp );
  /* Pokemon which was switched to should have taken the hit */
  expect( ohp1 == p1.team[1].hp );
  expect( p1.active_pokemon == 1 );
  expect( has_switch_timer( & p1 ) == true );
  expect( can_switch( & p1 ) == false );

  /* Test Charged move that kills opponent. */
  battle.p1_action = CHARGED1;
  p1.team[1].energy = p1.team[1].charged_moves[0].energy;
  over = eval_turn( & battle );
  assert( p1.active_pokemon == 1 );
  expect( over == true );
  expect( is_active_alive( & p2 ) == false );
  expect( p1.team[1].energy == 0 );
  expect( ohp1 == p1.team[1].hp );  /* Shouldn't have been hit */

  /* Try a CMP tie where one faints. */
  battle.p2_action        = CHARGED1;
  p1.team[1].energy       = p1.team[1].charged_moves[0].energy;
  p2.team[0].energy       = p2.team[0].charged_moves[0].energy;
  /* Make sure P1 wins tie */
  assert( battle.cmp_rule == CMP_IDEAL );
  p1.team[1].stats.attack = p2.team[0].stats.attack + 1;
  p2.team[0].hp           = ohp2;     /* Revive P2 */
  assert( is_active_alive( & p2 ) );
  over = eval_turn( & battle );
  expect( over == true );
  expect( is_active_alive( & p2 ) == false );
  expect( p1.team[1].energy == 0 );
  expect( ohp1 == p1.team[1].hp );  /* Shouldn't have been hit */

  /* Do a switch tie */
  battle.phase      = SUSPEND_SWITCH_TIE;
  p1.team[1].hp     = 0;                    /*  Kill P1's active pokemon */
  p2.team[1]        = p2.team[0];
  p2.team[1].hp     = 100;                  /* Revive P2 */
  battle.p1_action  = WAIT;
  battle.p2_action  = WAIT;
  assert( p1.active_pokemon == 1 );
  assert( p2.active_pokemon == 0 );
  over = eval_turn( & battle );
  expect( over == false );
  expect( can_switch( & p1 ) == true );
  expect( can_switch( & p2 ) == true );
  battle.p1_action = SWITCH1;
  over = eval_turn( & battle );
  expect( over == false );
  expect( p1.active_pokemon == 0 );
  expect( p2.active_pokemon == 0 );
  battle.p1_action = WAIT;
  battle.p2_action = SWITCH1;
  over = eval_turn( & battle );
  expect( over == false );
  expect( p1.active_pokemon == 0 );
  expect( p2.active_pokemon == 1 );

  return true;
}



/* ------------------------------------------------------------------------- */

  bool
test_battle( void )
{
  bool rsl = true;

  rsl &= do_test( is_valid_action );
  rsl &= do_test( is_battle_over );
  rsl &= do_test( is_p1_winner );
  rsl &= do_test( get_battle_winner );
  rsl &= do_test( eval_turn );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
