/* -*- mode: c; -*- */

/* ========================================================================== */

#include <stdio.h>
#include "ai/pvpoke_ai.h"

/* -------------------------------------------------------------------------- */

  ai_status_t
pvpoke_ai_select_team( roster_t   * our_roster,
                       roster_t   * their_roster,
                       pvp_team_t * team,
                       void       * aux
                     )
{
  return AI_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  ai_status_t
pvpoke_ai_decide_action( bool                        decide_p1,
                         const struct pvp_battle_s * battle,
                         pvp_action_t              * choice
                       )
{
  return AI_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  ai_status_t
pvpoke_ai_init( ai_t * ai, void * init_aux )
{
  return AI_SUCCESS;
}


/* -------------------------------------------------------------------------- */

  void
pvpoke_ai_free( ai_t * ai )
{

}


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/* vim: set filetype=c : */
