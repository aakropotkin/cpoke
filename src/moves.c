/* -*- mode: c; -*- */
/* ========================================================================= */

#include "moves.h"

/* ------------------------------------------------------------------------- */

const buff_t NO_BUFF = { .chance = bc0000,
  .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
  .def_buff = { .target = 0, .debuffp = 0, .amount = 0 }
};


/* ------------------------------------------------------------------------- */

const double BUFF_MOD[] = {
  0.5000000, 0.5714286, 0.6666667, 0.8000000,  /* Debuff */
  1.0000000,
  1.2500000, 1.5000000, 1.7500000, 2.0000000   /*  Buff  */
};


/* ------------------------------------------------------------------------- */

  void
apply_buff( buff_state_t * buff_state, buff_t buff )
{
  /* Attack */
  if ( buff.atk_buff.debuffp )
    {
      buff_state->atk_buff_lv =
        max( B_4_8, buff_state->atk_buff_lv - buff.atk_buff.amount );
    } else {
    buff_state->atk_buff_lv =
      min( B_8_4, buff_state->atk_buff_lv + buff.atk_buff.amount );
  }
  /* Defense */
  if ( buff.def_buff.debuffp )
    {
      buff_state->def_buff_lv =
        max( B_4_8, buff_state->def_buff_lv - buff.def_buff.amount );
    } else {
    buff_state->def_buff_lv =
      min( B_8_4, buff_state->def_buff_lv + buff.def_buff.amount );
  }
}


/* ------------------------------------------------------------------------- */


/* ========================================================================= */

/* vim: set filetype=c : */
