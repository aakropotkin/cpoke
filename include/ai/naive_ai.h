/* -*- mode: c; -*- */

#ifndef _NAIVE_AI_H
#define _NAIVE_AI_H

/* ========================================================================== */

#include <stdint.h>
#include <stdbool.h>
#include "pvp_action.h"
#include "ai/ai.h"
#include "store.h"
#include "pokemon.h"

struct pvp_battle_s;

/* -------------------------------------------------------------------------- */

ai_status_t naive_ai_select_team( roster_t      * our_roster,
                                  roster_t      * their_roser,
                                  pvp_pokemon_t * team,
                                  store_t       * store,
                                  void          * aux
                                );

ai_status_t naive_ai_decide_action(              bool           decide_p1,
                                    const struct pvp_battle_s * battle,
                                                 pvp_action_t * choice,
                                                 void         * aux
                                  );

ai_status_t naive_ai_decide_swap(              bool           decide_p1,
                                  const struct pvp_battle_s * battle,
                                               pvp_action_t * choice,
                                               void         * aux
                                );

ai_status_t naive_ai_decide_shield(              bool           decide_p1,
                                    const struct pvp_battle_s * battle,
                                                 pvp_action_t * choice,
                                                 void         * aux
                                  );

ai_status_t naive_ai_init( ai_t * ai, void * init_aux );
void        naive_ai_free( ai_t * ai );


/* -------------------------------------------------------------------------- */

#define def_naive_ai()  (ai_t)                                                \
  {                                                                           \
      .name          = "Naive AI",                                            \
      .select_team   = naive_ai_select_team,                                  \
      .decide_action = naive_ai_decide_action,                                \
      .decide_swap   = naive_ai_decide_swap,                                  \
      .decide_shield = naive_ai_decide_shield,                                \
      .init          = naive_ai_init,                                         \
      .free          = naive_ai_free,                                         \
      .aux           = NULL                                                   \
  }


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* naive_ai.h */

/* vim: set filetype=c : */
