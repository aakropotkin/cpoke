/* -*- mode: c; -*- */

#ifndef _PVP_ACTION_H
#define _PVP_ACTION_H

/* ========================================================================= */

#include "util/bits.h"
#include "util/enumflags.h"


/* ------------------------------------------------------------------------- */

/**
 * PvPoke has separate constructs for "Actions" and "Timeline Events".
 * From what I can tell these are nearly identical, and they spent a huge amount
 * of resources converting between the two during simulation and analysis.
 * I have combined them so that a list of actions can represent the full
 * decision tree of a battle.
 *
 * FIXME:
 * The effect of random chance buffs are unfortunately not going to appear in
 * this encoding. This should be fixed once the simulator is more fleshed out
 * and we understand how buffs are relevant to analysis.
 */
DEFINE_ENUM_WITH_FLAGS( pvp_action,
    ACT_NULL, FAST, WAIT, CHARGED1, CHARGED2, SWITCH1, SWITCH2, SHIELD
  );
static const uint8_t NUM_PVP_ACTIONS = SHIELD + 1;
#define get_pvp_act_mask( ACTION )  ( (pvp_action_mask_t) to_mask( ACTION ) )


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

#endif /* pvp_action.h */

/* vim: set filetype=c : */
