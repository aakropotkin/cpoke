/* -*- mode: c; -*- */

#ifndef _AI_H
#define _AI_H

/* ========================================================================= */

#include <stdint.h>
#include <stdbool.h>
#include "battle.h"
#include "pvp_action.h"


/* ------------------------------------------------------------------------- */



/**
 * Choose an action for an AI player to queue next.
 *
 * @param decide_p1    <code>true</code> when the decision will be for
 *                     Player 1; otherwise decide for Player 2
 * @param battle       The current battle state, which will be used to
 *                     inform decision making.
 * @return             An action to be queued for the chosen player.
 */
typedef pvp_action_t (* decide_action_fn_t ) ( bool, pvp_battle_t * );


/**
 * By default AI systems are treated modularly, and a
 * <code>pvp_player_t</code> will hold a pointer to an auxilary struct
 * where AI systems can store any data they need.
 * <p>
 * However, some AI systems are simple enough that this is not necessary,
 * and in the case of GPGPU processing we can't actually use a
 * <code>decide_action_fn</code> to choose actions.
 * In these cases a compile flag can be activated to substitute the modular
 * AI interface with alternative structures.
 * This also means that <code>decide_action</code> in <code>battle.h</code>
 * will need to be defined explicitly.
 */
#ifdef AI_AUX_TYPE
typedef AI_AUX_TYPE ai_aux_t;
#ifndef AI_AUX_BITS
#define AI_AUX_BITS
#endif
#endif


/* ========================================================================= */

#endif /* ai.h */

/* vim: set filetype=c : */
