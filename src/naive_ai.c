/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "ai/ai.h"
#include "pvp_action.h"
#include "pokemon.h"
#include "battle.h"


/* ------------------------------------------------------------------------- */

/**
 * Picks the first three roster pokemon without any regard for the opponent's
 * roster.
 */
  ai_status_t
naive_ai_select_team( roster_t   * our_roster,
                      roster_t   * their_roser,
                      pvp_team_t * team,
                      void       * aux
                    )
{
  if ( our_roster == NULL ) return AI_BAD_VALUE;
  if ( team == NULL ) return AI_BAD_VALUE;
  team[0] = NULL;
  team[1] = NULL;
  team[2] = NULL;
  /* Take the first 3, or as many as possible */
  for ( size_t i = 0; i < min( 3, our_roster->roster_length ); i++ )
    {
      pvp_pokemon_init( our_roster->roster_pokemon + i, team + i );
    }
  return AI_SUCCESS;
}


/* ------------------------------------------------------------------------- */

/**
 * This is as naive as it gets, it is essentially the behaviour of a
 * Rocket Grunt.
 * It chooses the first valid action in the following order:
 *   Charged Attack, Shield, Fast Attack, Swap, or falls back to `WAIT'.
 */
  ai_status_t
naive_ai_decide_action( bool           decide_p1,
                        pvp_battle_t * battle,
                        pvp_action_t * choice,
                        void         * aux
                      )
{
  if ( battle == NULL ) return AI_BAD_VALUE;
  if ( choice == NULL ) return AI_BAD_VALUE;

  pvp_player_t * self = decide_p1 ? battle->p1 : battle->p2;
  if ( self == NULL ) return AI_BAD_VALUE;

  if ( is_valid_action( decide_p1, CHARGED1, battle ) )
    {
      *choice = CHARGED1;
    }
  else if ( is_valid_action( decide_p1, CHARGED2, battle ) )
    {
      *choice = CHARGED2;
    }
  else if ( is_valid_action( decide_p1, SHIELD, battle ) )
    {
      *choice = SHIELD;
    }
  else if ( is_valid_action( decide_p1, FAST, battle ) )
    {
      *choice = FAST;
    }
  else if ( is_valid_action( decide_p1, SWITCH1, battle ) )
    {
      *choice = SWITCH1;
    }
  else if ( is_valid_action( decide_p1, WAIT, battle ) )
    {
      *choice = WAIT;
    }
  else /* If you get to this point the battle is over, or you have a bug. */
    {
      *choice = ACT_NULL;
    }

  return ( *choice != ACT_NULL ) ? AI_SUCCESS : AI_ERROR_FAIL;
}


/* ------------------------------------------------------------------------- */

  ai_status_t
naive_ai_init( ai_t * ai, void * init_aux )
{
  if ( ai == NULL ) return AI_BAD_VALUE;
  return AI_SUCCESS;
}


/* ------------------------------------------------------------------------- */

  void
naive_ai_free( ai_t * ai )
{
  if ( ai == NULL ) return;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
