/* -*- mode: c; -*- */

#ifndef _PTYPE_TRAITS_H
#define _PTYPE_TRAITS_H

/* ========================================================================== */


/* -------------------------------------------------------------------------- */

static const ptype_traits_t ptype_traits[19] = {
  /* PT_NONE */ {
    .resistances = PT_NONE_M,
    .weaknesses  = PT_NONE_M,
    .immunities  = PT_NONE_M
  }, /* Bug */ {
    .resistances = FIGHTING_M | GROUND_M | GRASS_M,
    .weaknesses  = FLYING_M | ROCK_M | FIRE_M,
    .immunities  = PT_NONE_M
  }, /* Dark */ {
    .resistances = GHOST_M | DARK_M,
    .weaknesses  = FIGHTING_M | FAIRY_M | BUG_M,
    .immunities  = PSYCHIC_M
  }, /* Dragon */ {
    .resistances = FIRE_M | WATER_M | GRASS_M | ELECTRIC_M,
    .weaknesses  = DRAGON_M | ICE_M | FAIRY_M,
    .immunities  = PT_NONE_M
  }, /* Electric */ {
    .resistances = FLYING_M | STEEL_M | ELECTRIC_M,
    .weaknesses  = GROUND_M,
    .immunities  = PT_NONE_M
  }, /* Fairy */ {
    .resistances = FIGHTING_M | BUG_M | DARK_M,
    .weaknesses  = POISON_M | STEEL_M,
    .immunities  = DRAGON_M
  }, /* Fighting */ {
    .resistances = ROCK_M | BUG_M | DARK_M,
    .weaknesses  = FLYING_M | PSYCHIC_M | FAIRY_M,
    .immunities  = PT_NONE_M
  }, /* Fire */ {
    .resistances = BUG_M | STEEL_M | FIRE_M | GRASS_M | ICE_M | FAIRY_M,
    .weaknesses  = GROUND_M | ROCK_M | WATER_M,
    .immunities  = PT_NONE_M
  }, /* Flying */ {
    .resistances = FIGHTING_M | BUG_M | GRASS_M,
    .weaknesses  = ROCK_M | ELECTRIC_M | ICE_M,
    .immunities  = GROUND_M
  }, /* Ghost */ {
    .resistances = POISON_M | BUG_M,
    .weaknesses  = GHOST_M | DARK_M,
    .immunities  = NORMAL_M | FIGHTING_M
  }, /* Grass */ {
    .resistances = GROUND_M | WATER_M | GRASS_M | ELECTRIC_M,
    .weaknesses  = FLYING_M | POISON_M | BUG_M | FIRE_M | ICE_M,
    .immunities  = PT_NONE_M
  }, /* Ground */ {
    .resistances = POISON_M | ROCK_M,
    .weaknesses  = WATER_M | GRASS_M | ICE_M,
    .immunities  = ELECTRIC_M
  }, /* Ice */ {
    .resistances = ICE_M,
    .weaknesses  = FIGHTING_M | FIRE_M | STEEL_M | ROCK_M,
    .immunities  = PT_NONE_M
  }, /* Normal */ {
    .resistances = PT_NONE_M,
    .weaknesses  = FIGHTING_M,
    .immunities  = GHOST_M
  }, /* Poison */ {
    .resistances = FIGHTING_M | POISON_M | BUG_M | FAIRY_M | GRASS_M,
    .weaknesses  = GROUND_M | PSYCHIC_M,
    .immunities  = PT_NONE
  }, /* Psychic */ {
    .resistances = FIGHTING_M | PSYCHIC_M,
    .weaknesses  = BUG_M | GHOST_M | DARK_M,
    .immunities  = PT_NONE_M
  }, /* Rock */ {
    .resistances = NORMAL_M | FLYING_M | POISON_M | FIRE_M,
    .weaknesses  = FIGHTING_M | GROUND_M | STEEL_M | WATER_M | GRASS_M,
    .immunities  = PT_NONE_M
  }, /* Steel */ {
    .resistances = NORMAL_M | FLYING_M | ROCK_M | BUG_M | STEEL_M | GRASS_M |
                   PSYCHIC_M | ICE_M | DRAGON_M | FAIRY_M,
    .weaknesses  = FIGHTING_M | GROUND_M | FIRE_M,
    .immunities  = POISON_M
  }, /* Water */ {
    .resistances = STEEL_M | FIRE_M | WATER_M | ICE_M,
    .weaknesses  = GRASS_M | ELECTRIC_M,
    .immunities  = PT_NONE_M
  }
};


/* -------------------------------------------------------------------------- */

static const ptype_traits_t * PT_NONE_TRAITS  = & ptype_traits[PT_NONE];
static const ptype_traits_t * BUG_TRAITS      = & ptype_traits[BUG];
static const ptype_traits_t * DARK_TRAITS     = & ptype_traits[DARK];
static const ptype_traits_t * DRAGON_TRAITS   = & ptype_traits[DRAGON];
static const ptype_traits_t * ELECTRIC_TRAITS = & ptype_traits[ELECTRIC];
static const ptype_traits_t * FAIRY_TRAITS    = & ptype_traits[FAIRY];
static const ptype_traits_t * FIGHTING_TRAITS = & ptype_traits[FIGHTING];
static const ptype_traits_t * FIRE_TRAITS     = & ptype_traits[FIRE];
static const ptype_traits_t * FLYING_TRAITS   = & ptype_traits[FLYING];
static const ptype_traits_t * GHOST_TRAITS    = & ptype_traits[GHOST];
static const ptype_traits_t * GRASS_TRAITS    = & ptype_traits[GRASS];
static const ptype_traits_t * GROUND_TRAITS   = & ptype_traits[GROUND];
static const ptype_traits_t * ICE_TRAITS      = & ptype_traits[ICE];
static const ptype_traits_t * NORMAL_TRAITS   = & ptype_traits[NORMAL];
static const ptype_traits_t * POISON_TRAITS   = & ptype_traits[POISON];
static const ptype_traits_t * PSYCHIC_TRAITS  = & ptype_traits[PSYCHIC];
static const ptype_traits_t * ROCK_TRAITS     = & ptype_traits[ROCK];
static const ptype_traits_t * STEEL_TRAITS    = & ptype_traits[STEEL];
static const ptype_traits_t * WATER_TRAITS    = & ptype_traits[WATER];


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* ptype_traitss.h */

/* vim: set filetype=c : */
