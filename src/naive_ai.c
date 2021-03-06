/* -*- mode: c; -*- */

/* ========================================================================== */

#include "ai/ai.h"
#include "battle.h"
#include "player.h"
#include "pokemon.h"
#include "pvp_action.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* -------------------------------------------------------------------------- */

/**
 * Picks the first three roster pokemon without any regard for the opponent's
 * roster.
 */
  ai_status_t
naive_ai_select_team( roster_t      * our_roster,
                      roster_t      * their_roser,
                      pvp_pokemon_t * team, /* EXACTLY 3 ELEMENTS */
                      store_t       * store,
                      void          * aux
                    )
{
  if ( our_roster == NULL ) return AI_ERROR_BAD_VALUE;
  if ( team == NULL ) return AI_ERROR_BAD_VALUE;
  memset( team, 0, sizeof( pvp_pokemon_t ) * 3 );
  /* Take the first 3, or as many as possible */
  for ( size_t i = 0; i < min( 3, our_roster->roster_length ); i++ )
    {
      pvp_pokemon_init( team + i, our_roster->roster_pokemon + i, store );
    }
  return AI_SUCCESS;
}


/* -------------------------------------------------------------------------- */

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
  if ( battle == NULL ) return AI_ERROR_BAD_VALUE;
  if ( choice == NULL ) return AI_ERROR_BAD_VALUE;

  pvp_player_t * self = decide_p1 ? battle->p1 : battle->p2;
  if ( self == NULL ) return AI_ERROR_BAD_VALUE;

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


/* -------------------------------------------------------------------------- */

  ai_status_t
naive_ai_decide_swap( bool           decide_p1,
                      pvp_battle_t * battle,
                      pvp_action_t * choice,
                      void         * aux
                    )
{
  return AI_ERROR_FAIL;
}


/* -------------------------------------------------------------------------- */

  ai_status_t
naive_ai_decide_shield( bool           decide_p1,
                        pvp_battle_t * battle,
                        pvp_action_t * choice,
                        void         * aux
                      )
{
  return AI_ERROR_FAIL;
}


/* -------------------------------------------------------------------------- */

  ai_status_t
naive_ai_init( ai_t * ai, void * init_aux )
{
  if ( ai == NULL ) return AI_ERROR_BAD_VALUE;
  return AI_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  void
naive_ai_free( ai_t * ai )
{
  if ( ai == NULL ) return;
}


/* -------------------------------------------------------------------------- */

#ifdef MK_AI_SO

#ifdef USE_DLLEXPORT
#define DLLEXPORT  __declspec( dllexport )
#else /* defined( USE_DLLEXPORT ) */
#define DLLEXPORT
#endif /* defined( USE_DLLEXPORT ) */

DLLEXPORT char * ai_name = "Naive AI";

ai_status_t ai_select_team( roster_t      * our_roster,
                            roster_t      * their_roser,
                            pvp_pokemon_t * team,
                            store_t       * store,
                            void          * aux
                          )
  __attribute__(( alias( "naive_ai_select_team" ) )) DLLEXPORT;

ai_status_t ai_decide_action( bool           decide_p1,
                              pvp_battle_t * battle,
                              pvp_action_t * choice,
                              void         * aux
                            )
  __attribute__(( alias( "naive_ai_decide_action" ) )) DLLEXPORT;

ai_status_t ai_decide_swap( bool           decide_p1,
                            pvp_battle_t * battle,
                            pvp_action_t * choice,
                            void         * aux
                          )
  __attribute__(( alias( "naive_ai_decide_swap" ) )) DLLEXPORT;

ai_status_t ai_decide_shield( bool           decide_p1,
                              pvp_battle_t * battle,
                              pvp_action_t * choice,
                              void         * aux
                            )
  __attribute__(( alias( "naive_ai_decide_shield" ) )) DLLEXPORT;

ai_status_t ai_init( ai_t * ai, void * init_aux )
  __attribute__(( alias( "naive_ai_init" ) )) DLLEXPORT;

void ai_free( ai_t * ai )
  __attribute__(( alias( "naive_ai_free" ) )) DLLEXPORT;

#endif /* defined( MK_AI_SO ) */



/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
