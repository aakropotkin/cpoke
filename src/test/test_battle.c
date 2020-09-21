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
test_foo( void )
{

  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_battle( void )
{
  bool rsl = true;
  rsl &= do_test( foo );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
