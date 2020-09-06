/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"

/* ------------------------------------------------------------------------- */

const float   PVP_FAST_BONUS_MOD   = 1.3;
const float   PVP_CHARGE_BONUS_MOD = 1.3;

const float   CHARGE_BASE_MOD      = 0.25;
const float   CHARGE_NICE_MOD      = 0.5;
const float   CHARGE_GREAT_MOD     = 0.75;
const float   CHARGE_EXCELLENT_MOD = 1.0;

const float   STAB_BONUS           = 1.25;


const uint8_t MAX_CHARGE           = 100;
const uint8_t CHARGE_RATE          = 20;
const float   CHARGE_DECAY_RATE    = 0.5;

const uint16_t TURN_TIME           = 500;    /* ms */
const uint16_t CHARGED_TIME        = 4000;   /* ms */
const uint16_t SWITCH_TIME         = 13000;  /* ms */

const uint8_t CHARGED_TURNS        = 8;
const uint8_t SWITCH_TURNS         = 26;


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
