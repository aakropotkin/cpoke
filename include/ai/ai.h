/* -*- mode: c; -*- */

#ifndef _AI_H
#define _AI_H

/* ========================================================================== */

#include <stdint.h>
#include <stdbool.h>
#include "pvp_action.h"

struct pvp_battle_s;
struct roster_s;
struct pvp_pokemon_s;
struct store_s;


/* -------------------------------------------------------------------------- */

typedef enum {
  AI_NULL_STATUS,
  AI_SUCCESS,
  AI_ERROR_FAIL,
  AI_ERROR_BAD_VALUE,
  AI_ERROR_NOMEM
} ai_status_t;


/* -------------------------------------------------------------------------- */

struct ai_s;

/**
 * Choose an action for an AI player to queue next.
 *
 * @param decide_p1    <code>true</code> when the decision will be for
 *                     Player 1; otherwise decide for Player 2
 * @param battle       The current battle state, which will be used to
 *                     inform decision making.
 * @param action       An empty <code>pvp_action_t</code> to be filled by this
 *                     function for the chosen player.
 */
typedef ai_status_t ( * decide_action_fn ) ( bool,
                                             const struct pvp_battle_s *,
                                             pvp_action_t *,
                                             void *
                                           );

typedef ai_status_t ( * select_team_fn ) ( struct roster_s *,
                                           struct roster_s *,
                                           struct pvp_pokemon_s *, /* team  */
                                           struct store_s *, /* store */
                                           void *
                                         );

typedef ai_status_t ( * ai_init_fn ) ( struct ai_s *, void * );
typedef void ( * ai_free_fn ) ( struct ai_s * );


/* -------------------------------------------------------------------------- */

struct ai_s {
  char *           name;
  select_team_fn   select_team;
  decide_action_fn decide_action;
  decide_action_fn decide_swap;
  decide_action_fn decide_shield;
  ai_init_fn       init;
  ai_free_fn       free;
  void *           aux;
};
typedef struct ai_s  ai_t;


/* -------------------------------------------------------------------------- */

struct dl_ai_s {
  ai_t * ai;
  void * handle;
};
typedef struct dl_ai_s  dl_ai_t;

dl_ai_t * dlopen_ai( const char * filename );
int       dlclose_ai( dl_ai_t * dlai );


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* ai.h */

/* vim: set filetype=c : */
