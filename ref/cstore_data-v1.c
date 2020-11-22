/* -*- mode: c; -*- */

/* ========================================================================= */

#include "pokedex.h"
#include "moves.h"
#include "ptypes.h"
#include <stdlib.h>
#include <stdint.h>


/* ------------------------------------------------------------------------- */

const uint16_t NUM_POKEMON = 654;

const uint16_t NUM_MOVES = 223;


/* ------------------------------------------------------------------------- */

store_move_t MOVES[] = {
{
  .name = "WRAP",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 13,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "HYPER_BEAM",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 14,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 150,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "DARK_PULSE",
  .type = DARK,
  .is_fast = 0,
  .move_id = 16,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "SLUDGE",
  .type = POISON,
  .is_fast = 0,
  .move_id = 18,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "VICE_GRIP",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 20,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "FLAME_WHEEL",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 21,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "MEGAHORN",
  .type = BUG,
  .is_fast = 0,
  .move_id = 22,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "FLAMETHROWER",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 24,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "DIG",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 26,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "CROSS_CHOP",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 28,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "PSYBEAM",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 30,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "EARTHQUAKE",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 31,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 120,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = NO_BUFF
}, {
  .name = "STONE_EDGE",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 32,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "ICE_PUNCH",
  .type = ICE,
  .is_fast = 0,
  .move_id = 33,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "HEART_STAMP",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 34,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "DISCHARGE",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 35,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 65,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "FLASH_CANNON",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 36,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = NO_BUFF
}, {
  .name = "DRILL_PECK",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 38,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "ICE_BEAM",
  .type = ICE,
  .is_fast = 0,
  .move_id = 39,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "BLIZZARD",
  .type = ICE,
  .is_fast = 0,
  .move_id = 40,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 75,
  .buff = NO_BUFF
}, {
  .name = "HEAT_WAVE",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 42,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 95,
  .pve_energy = 0,
  .pvp_energy = 75,
  .buff = NO_BUFF
}, {
  .name = "AERIAL_ACE",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 45,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "DRILL_RUN",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 46,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "PETAL_BLIZZARD",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 47,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = NO_BUFF
}, {
  .name = "MEGA_DRAIN",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 48,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 25,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "BUG_BUZZ",
  .type = BUG,
  .is_fast = 0,
  .move_id = 49,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "POISON_FANG",
  .type = POISON,
  .is_fast = 0,
  .move_id = 50,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "NIGHT_SLASH",
  .type = DARK,
  .is_fast = 0,
  .move_id = 51,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0125
            }
}, {
  .name = "BUBBLE_BEAM",
  .type = WATER,
  .is_fast = 0,
  .move_id = 53,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 25,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "SUBMISSION",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 54,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "LOW_SWEEP",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 56,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "AQUA_JET",
  .type = WATER,
  .is_fast = 0,
  .move_id = 57,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "AQUA_TAIL",
  .type = WATER,
  .is_fast = 0,
  .move_id = 58,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "SEED_BOMB",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 59,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "PSYSHOCK",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 60,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "ANCIENT_POWER",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 62,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 2 },
              .chance = bc_0100
            }
}, {
  .name = "ROCK_TOMB",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 63,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "ROCK_SLIDE",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 64,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "POWER_GEM",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 65,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "SHADOW_SNEAK",
  .type = GHOST,
  .is_fast = 0,
  .move_id = 66,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "SHADOW_PUNCH",
  .type = GHOST,
  .is_fast = 0,
  .move_id = 67,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "OMINOUS_WIND",
  .type = GHOST,
  .is_fast = 0,
  .move_id = 69,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 2 },
              .chance = bc_0100
            }
}, {
  .name = "SHADOW_BALL",
  .type = GHOST,
  .is_fast = 0,
  .move_id = 70,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "MAGNET_BOMB",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 72,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "IRON_HEAD",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 74,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "PARABOLIC_CHARGE",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 75,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 25,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "THUNDER_PUNCH",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 77,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "THUNDER",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 78,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "THUNDERBOLT",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 79,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "TWISTER",
  .type = DRAGON,
  .is_fast = 0,
  .move_id = 80,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "DRAGON_PULSE",
  .type = DRAGON,
  .is_fast = 0,
  .move_id = 82,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "DRAGON_CLAW",
  .type = DRAGON,
  .is_fast = 0,
  .move_id = 83,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "DISARMING_VOICE",
  .type = FAIRY,
  .is_fast = 0,
  .move_id = 84,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "DRAINING_KISS",
  .type = FAIRY,
  .is_fast = 0,
  .move_id = 85,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "DAZZLING_GLEAM",
  .type = FAIRY,
  .is_fast = 0,
  .move_id = 86,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 70,
  .buff = NO_BUFF
}, {
  .name = "MOONBLAST",
  .type = FAIRY,
  .is_fast = 0,
  .move_id = 87,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0300
            }
}, {
  .name = "PLAY_ROUGH",
  .type = FAIRY,
  .is_fast = 0,
  .move_id = 88,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "CROSS_POISON",
  .type = POISON,
  .is_fast = 0,
  .move_id = 89,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "SLUDGE_BOMB",
  .type = POISON,
  .is_fast = 0,
  .move_id = 90,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "SLUDGE_WAVE",
  .type = POISON,
  .is_fast = 0,
  .move_id = 91,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = NO_BUFF
}, {
  .name = "GUNK_SHOT",
  .type = POISON,
  .is_fast = 0,
  .move_id = 92,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 75,
  .buff = NO_BUFF
}, {
  .name = "BONE_CLUB",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 94,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "BULLDOZE",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 95,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "MUD_BOMB",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 96,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "SIGNAL_BEAM",
  .type = BUG,
  .is_fast = 0,
  .move_id = 99,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 75,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "X_SCISSOR",
  .type = BUG,
  .is_fast = 0,
  .move_id = 100,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "FLAME_CHARGE",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 101,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "FLAME_BURST",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 102,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "FIRE_BLAST",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 103,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 140,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "BRINE",
  .type = WATER,
  .is_fast = 0,
  .move_id = 104,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "WATER_PULSE",
  .type = WATER,
  .is_fast = 0,
  .move_id = 105,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "SCALD",
  .type = WATER,
  .is_fast = 0,
  .move_id = 106,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "HYDRO_PUMP",
  .type = WATER,
  .is_fast = 0,
  .move_id = 107,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 75,
  .buff = NO_BUFF
}, {
  .name = "PSYCHIC",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 108,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 1, .debuffp = 1, .amount = 1 },
              .chance = bc_0100
            }
}, {
  .name = "PSYSTRIKE",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 109,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "ICY_WIND",
  .type = ICE,
  .is_fast = 0,
  .move_id = 111,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "GIGA_DRAIN",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 114,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "FIRE_PUNCH",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 115,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "SOLAR_BEAM",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 116,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 150,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "LEAF_BLADE",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 117,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "POWER_WHIP",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 118,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "AIR_CUTTER",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 121,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "HURRICANE",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 122,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = NO_BUFF
}, {
  .name = "BRICK_BREAK",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 123,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "SWIFT",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 125,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "HORN_ATTACK",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 126,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 40,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "STOMP",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 127,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "HYPER_FANG",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 129,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "BODY_SLAM",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 131,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "REST",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 132,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "STRUGGLE",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 133,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 35,
  .pve_energy = 0,
  .pvp_energy = 100,
  .buff = NO_BUFF
}, {
  .name = "SCALD_BLASTOISE",
  .type = WATER,
  .is_fast = 0,
  .move_id = 134,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "HYDRO_PUMP_BLASTOISE",
  .type = WATER,
  .is_fast = 0,
  .move_id = 135,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "WRAP_GREEN",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 136,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 25,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "WRAP_PINK",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 137,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 25,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "FURY_CUTTER",
  .type = BUG,
  .is_fast = 1,
  .move_id = 200,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 2,
  .pve_energy = 0,
  .pvp_energy = 4,
  .buff = NO_BUFF
}, {
  .name = "BUG_BITE",
  .type = BUG,
  .is_fast = 1,
  .move_id = 201,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 3,
  .buff = NO_BUFF
}, {
  .name = "BITE",
  .type = DARK,
  .is_fast = 1,
  .move_id = 202,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 4,
  .pve_energy = 0,
  .pvp_energy = 2,
  .buff = NO_BUFF
}, {
  .name = "SUCKER_PUNCH",
  .type = DARK,
  .is_fast = 1,
  .move_id = 203,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "DRAGON_BREATH",
  .type = DRAGON,
  .is_fast = 1,
  .move_id = 204,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 4,
  .pve_energy = 0,
  .pvp_energy = 3,
  .buff = NO_BUFF
}, {
  .name = "THUNDER_SHOCK",
  .type = ELECTRIC,
  .is_fast = 1,
  .move_id = 205,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 9,
  .buff = NO_BUFF
}, {
  .name = "SPARK",
  .type = ELECTRIC,
  .is_fast = 1,
  .move_id = 206,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 4,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "LOW_KICK",
  .type = FIGHTING,
  .is_fast = 1,
  .move_id = 207,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 4,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "KARATE_CHOP",
  .type = FIGHTING,
  .is_fast = 1,
  .move_id = 208,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "EMBER",
  .type = FIRE,
  .is_fast = 1,
  .move_id = 209,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "WING_ATTACK",
  .type = FLYING,
  .is_fast = 1,
  .move_id = 210,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "PECK",
  .type = FLYING,
  .is_fast = 1,
  .move_id = 211,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "LICK",
  .type = GHOST,
  .is_fast = 1,
  .move_id = 212,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 3,
  .buff = NO_BUFF
}, {
  .name = "SHADOW_CLAW",
  .type = GHOST,
  .is_fast = 1,
  .move_id = 213,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "VINE_WHIP",
  .type = GRASS,
  .is_fast = 1,
  .move_id = 214,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "RAZOR_LEAF",
  .type = GRASS,
  .is_fast = 1,
  .move_id = 215,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 11,
  .pve_energy = 0,
  .pvp_energy = 4,
  .buff = NO_BUFF
}, {
  .name = "MUD_SHOT",
  .type = GROUND,
  .is_fast = 1,
  .move_id = 216,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 9,
  .buff = NO_BUFF
}, {
  .name = "ICE_SHARD",
  .type = ICE,
  .is_fast = 1,
  .move_id = 217,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 10,
  .buff = NO_BUFF
}, {
  .name = "FROST_BREATH",
  .type = ICE,
  .is_fast = 1,
  .move_id = 218,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 7,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "QUICK_ATTACK",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 219,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "SCRATCH",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 220,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 4,
  .pve_energy = 0,
  .pvp_energy = 2,
  .buff = NO_BUFF
}, {
  .name = "TACKLE",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 221,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 2,
  .buff = NO_BUFF
}, {
  .name = "POUND",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 222,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 4,
  .buff = NO_BUFF
}, {
  .name = "CUT",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 223,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 2,
  .buff = NO_BUFF
}, {
  .name = "POISON_JAB",
  .type = POISON,
  .is_fast = 1,
  .move_id = 224,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "ACID",
  .type = POISON,
  .is_fast = 1,
  .move_id = 225,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "PSYCHO_CUT",
  .type = PSYCHIC,
  .is_fast = 1,
  .move_id = 226,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 9,
  .buff = NO_BUFF
}, {
  .name = "ROCK_THROW",
  .type = ROCK,
  .is_fast = 1,
  .move_id = 227,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "METAL_CLAW",
  .type = STEEL,
  .is_fast = 1,
  .move_id = 228,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "BULLET_PUNCH",
  .type = STEEL,
  .is_fast = 1,
  .move_id = 229,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "WATER_GUN",
  .type = WATER,
  .is_fast = 1,
  .move_id = 230,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 3,
  .buff = NO_BUFF
}, {
  .name = "SPLASH",
  .type = WATER,
  .is_fast = 1,
  .move_id = 231,
  .cooldown = 3,
  .pve_power = 0,
  .pvp_power = 0,
  .pve_energy = 0,
  .pvp_energy = 12,
  .buff = NO_BUFF
}, {
  .name = "WATER_GUN_FAST_BLAS",
  .type = WATER,
  .is_fast = 1,
  .move_id = 232,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 4,
  .buff = NO_BUFF
}, {
  .name = "MUD_SLAP",
  .type = GROUND,
  .is_fast = 1,
  .move_id = 233,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 11,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "ZEN_HEADBUTT",
  .type = PSYCHIC,
  .is_fast = 1,
  .move_id = 234,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "CONFUSION",
  .type = PSYCHIC,
  .is_fast = 1,
  .move_id = 235,
  .cooldown = 3,
  .pve_power = 0,
  .pvp_power = 16,
  .pve_energy = 0,
  .pvp_energy = 12,
  .buff = NO_BUFF
}, {
  .name = "POISON_STING",
  .type = POISON,
  .is_fast = 1,
  .move_id = 236,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "BUBBLE",
  .type = WATER,
  .is_fast = 1,
  .move_id = 237,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 11,
  .buff = NO_BUFF
}, {
  .name = "FEINT_ATTACK",
  .type = DARK,
  .is_fast = 1,
  .move_id = 238,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "STEEL_WING",
  .type = STEEL,
  .is_fast = 1,
  .move_id = 239,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 7,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "FIRE_FANG",
  .type = FIRE,
  .is_fast = 1,
  .move_id = 240,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "ROCK_SMASH",
  .type = FIGHTING,
  .is_fast = 1,
  .move_id = 241,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "TRANSFORM",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 242,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 0,
  .pve_energy = 0,
  .pvp_energy = 0,
  .buff = NO_BUFF
}, {
  .name = "COUNTER",
  .type = FIGHTING,
  .is_fast = 1,
  .move_id = 243,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 7,
  .buff = NO_BUFF
}, {
  .name = "POWDER_SNOW",
  .type = ICE,
  .is_fast = 1,
  .move_id = 244,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 4,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "CLOSE_COMBAT",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 245,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 0, .debuffp = 1, .amount = 2 },
              .chance = bc_1000
            }
}, {
  .name = "DYNAMIC_PUNCH",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 246,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "FOCUS_BLAST",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 247,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 150,
  .pve_energy = 0,
  .pvp_energy = 75,
  .buff = NO_BUFF
}, {
  .name = "AURORA_BEAM",
  .type = ICE,
  .is_fast = 0,
  .move_id = 248,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "CHARGE_BEAM",
  .type = ELECTRIC,
  .is_fast = 1,
  .move_id = 249,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 11,
  .buff = NO_BUFF
}, {
  .name = "VOLT_SWITCH",
  .type = ELECTRIC,
  .is_fast = 1,
  .move_id = 250,
  .cooldown = 3,
  .pve_power = 0,
  .pvp_power = 12,
  .pve_energy = 0,
  .pvp_energy = 16,
  .buff = NO_BUFF
}, {
  .name = "WILD_CHARGE",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 251,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 0, .debuffp = 1, .amount = 2 },
              .chance = bc_1000
            }
}, {
  .name = "ZAP_CANNON",
  .type = ELECTRIC,
  .is_fast = 0,
  .move_id = 252,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 150,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "DRAGON_TAIL",
  .type = DRAGON,
  .is_fast = 1,
  .move_id = 253,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 10,
  .buff = NO_BUFF
}, {
  .name = "AVALANCHE",
  .type = ICE,
  .is_fast = 0,
  .move_id = 254,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "AIR_SLASH",
  .type = FLYING,
  .is_fast = 1,
  .move_id = 255,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 9,
  .buff = NO_BUFF
}, {
  .name = "BRAVE_BIRD",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 256,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "SKY_ATTACK",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 257,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "SAND_TOMB",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 258,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 25,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 1, .debuffp = 1, .amount = 1 },
              .chance = bc_1000
            }
}, {
  .name = "ROCK_BLAST",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 259,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "INFESTATION",
  .type = BUG,
  .is_fast = 1,
  .move_id = 260,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 11,
  .buff = NO_BUFF
}, {
  .name = "STRUGGLE_BUG",
  .type = BUG,
  .is_fast = 1,
  .move_id = 261,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "SILVER_WIND",
  .type = BUG,
  .is_fast = 0,
  .move_id = 262,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 2 },
              .chance = bc_0100
            }
}, {
  .name = "ASTONISH",
  .type = GHOST,
  .is_fast = 1,
  .move_id = 263,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 9,
  .buff = NO_BUFF
}, {
  .name = "HEX",
  .type = GHOST,
  .is_fast = 1,
  .move_id = 264,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 6,
  .pve_energy = 0,
  .pvp_energy = 11,
  .buff = NO_BUFF
}, {
  .name = "NIGHT_SHADE",
  .type = GHOST,
  .is_fast = 0,
  .move_id = 265,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "IRON_TAIL",
  .type = STEEL,
  .is_fast = 1,
  .move_id = 266,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "GYRO_BALL",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 267,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "HEAVY_SLAM",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 268,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "FIRE_SPIN",
  .type = FIRE,
  .is_fast = 1,
  .move_id = 269,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 10,
  .buff = NO_BUFF
}, {
  .name = "OVERHEAT",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 270,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 1, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "BULLET_SEED",
  .type = GRASS,
  .is_fast = 1,
  .move_id = 271,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 13,
  .buff = NO_BUFF
}, {
  .name = "GRASS_KNOT",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 272,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "ENERGY_BALL",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 273,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 1, .debuffp = 1, .amount = 1 },
              .chance = bc_0100
            }
}, {
  .name = "EXTRASENSORY",
  .type = PSYCHIC,
  .is_fast = 1,
  .move_id = 274,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 10,
  .buff = NO_BUFF
}, {
  .name = "FUTURESIGHT",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 275,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 120,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = NO_BUFF
}, {
  .name = "MIRROR_COAT",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 276,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "OUTRAGE",
  .type = DRAGON,
  .is_fast = 0,
  .move_id = 277,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "SNARL",
  .type = DARK,
  .is_fast = 1,
  .move_id = 278,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 13,
  .buff = NO_BUFF
}, {
  .name = "CRUNCH",
  .type = DARK,
  .is_fast = 0,
  .move_id = 279,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "FOUL_PLAY",
  .type = DARK,
  .is_fast = 0,
  .move_id = 280,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "HIDDEN_POWER",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 281,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 9,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "TAKE_DOWN",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 282,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 5,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "WATERFALL",
  .type = WATER,
  .is_fast = 1,
  .move_id = 283,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 12,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "SURF",
  .type = WATER,
  .is_fast = 0,
  .move_id = 284,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 65,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "DRACO_METEOR",
  .type = DRAGON,
  .is_fast = 0,
  .move_id = 285,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 150,
  .pve_energy = 0,
  .pvp_energy = 65,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 1, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "DOOM_DESIRE",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 286,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 75,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "YAWN",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 287,
  .cooldown = 3,
  .pve_power = 0,
  .pvp_power = 0,
  .pve_energy = 0,
  .pvp_energy = 12,
  .buff = NO_BUFF
}, {
  .name = "PSYCHO_BOOST",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 288,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 70,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 1, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "ORIGIN_PULSE",
  .type = WATER,
  .is_fast = 0,
  .move_id = 289,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "PRECIPICE_BLADES",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 290,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 60,
  .buff = NO_BUFF
}, {
  .name = "PRESENT",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 291,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 3,
  .pve_energy = 0,
  .pvp_energy = 12,
  .buff = NO_BUFF
}, {
  .name = "WEATHER_BALL_FIRE",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 292,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "WEATHER_BALL_ICE",
  .type = ICE,
  .is_fast = 0,
  .move_id = 293,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "WEATHER_BALL_ROCK",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 294,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "WEATHER_BALL_WATER",
  .type = WATER,
  .is_fast = 0,
  .move_id = 295,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "FRENZY_PLANT",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 296,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "SMACK_DOWN",
  .type = ROCK,
  .is_fast = 1,
  .move_id = 297,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 12,
  .pve_energy = 0,
  .pvp_energy = 8,
  .buff = NO_BUFF
}, {
  .name = "BLAST_BURN",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 298,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "HYDRO_CANNON",
  .type = WATER,
  .is_fast = 0,
  .move_id = 299,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "LAST_RESORT",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 300,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "METEOR_MASH",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 301,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "SKULL_BASH",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 302,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 75,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 1 },
              .chance = bc_1000
            }
}, {
  .name = "ACID_SPRAY",
  .type = POISON,
  .is_fast = 0,
  .move_id = 303,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 20,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 1, .debuffp = 1, .amount = 2 },
              .chance = bc_1000
            }
}, {
  .name = "EARTH_POWER",
  .type = GROUND,
  .is_fast = 0,
  .move_id = 304,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 1, .debuffp = 1, .amount = 1 },
              .chance = bc_0100
            }
}, {
  .name = "CRABHAMMER",
  .type = WATER,
  .is_fast = 0,
  .move_id = 305,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 75,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0125
            }
}, {
  .name = "OCTAZOOKA",
  .type = WATER,
  .is_fast = 0,
  .move_id = 308,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 50,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0500
            }
}, {
  .name = "MIRROR_SHOT",
  .type = STEEL,
  .is_fast = 0,
  .move_id = 309,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 35,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0300
            }
}, {
  .name = "SUPER_POWER",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 310,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 85,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 1, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 1, .amount = 1 },
              .chance = bc_1000
            }
}, {
  .name = "FELL_STINGER",
  .type = BUG,
  .is_fast = 0,
  .move_id = 311,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 20,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "LEAF_TORNADO",
  .type = GRASS,
  .is_fast = 0,
  .move_id = 312,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 45,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 2 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0500
            }
}, {
  .name = "MUDDY_WATER",
  .type = WATER,
  .is_fast = 0,
  .move_id = 316,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 35,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = { .atk_buff =  { .target = 1, .debuffp = 1, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_0300
            }
}, {
  .name = "BLAZE_KICK",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 317,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 55,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "POWER_UP_PUNCH",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 319,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 20,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 1 },
              .atk_buff = { .target = 0, .debuffp = 0, .amount = 0 },
              .chance = bc_1000
            }
}, {
  .name = "CHARM",
  .type = FAIRY,
  .is_fast = 1,
  .move_id = 320,
  .cooldown = 2,
  .pve_power = 0,
  .pvp_power = 16,
  .pve_energy = 0,
  .pvp_energy = 6,
  .buff = NO_BUFF
}, {
  .name = "GIGA_IMPACT",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 321,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 150,
  .pve_energy = 0,
  .pvp_energy = 80,
  .buff = NO_BUFF
}, {
  .name = "FRUSTRATION",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 322,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 10,
  .pve_energy = 0,
  .pvp_energy = 70,
  .buff = NO_BUFF
}, {
  .name = "RETURN",
  .type = NORMAL,
  .is_fast = 0,
  .move_id = 323,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 130,
  .pve_energy = 0,
  .pvp_energy = 70,
  .buff = NO_BUFF
}, {
  .name = "SYNCHRONOISE",
  .type = PSYCHIC,
  .is_fast = 0,
  .move_id = 324,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "LOCK_ON",
  .type = NORMAL,
  .is_fast = 1,
  .move_id = 325,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 1,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "THUNDER_FANG",
  .type = ELECTRIC,
  .is_fast = 1,
  .move_id = 326,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "ICE_FANG",
  .type = ICE,
  .is_fast = 1,
  .move_id = 327,
  .cooldown = 1,
  .pve_power = 0,
  .pvp_power = 8,
  .pve_energy = 0,
  .pvp_energy = 5,
  .buff = NO_BUFF
}, {
  .name = "SACRED_SWORD",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 330,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 60,
  .pve_energy = 0,
  .pvp_energy = 35,
  .buff = NO_BUFF
}, {
  .name = "FLYING_PRESS",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 331,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 90,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = NO_BUFF
}, {
  .name = "AURA_SPHERE",
  .type = FIGHTING,
  .is_fast = 0,
  .move_id = 332,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 100,
  .pve_energy = 0,
  .pvp_energy = 55,
  .buff = NO_BUFF
}, {
  .name = "ROCK_WRECKER",
  .type = ROCK,
  .is_fast = 0,
  .move_id = 334,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 110,
  .pve_energy = 0,
  .pvp_energy = 50,
  .buff = NO_BUFF
}, {
  .name = "FLY",
  .type = FLYING,
  .is_fast = 0,
  .move_id = 341,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 80,
  .pve_energy = 0,
  .pvp_energy = 45,
  .buff = NO_BUFF
}, {
  .name = "V_CREATE",
  .type = FIRE,
  .is_fast = 0,
  .move_id = 342,
  .cooldown = 0,
  .pve_power = 0,
  .pvp_power = 95,
  .pve_energy = 0,
  .pvp_energy = 40,
  .buff = { .atk_buff =  { .target = 0, .debuffp = 0, .amount = 0 },
              .atk_buff = { .target = 0, .debuffp = 1, .amount = 3 },
              .chance = bc_1000
            }
}};

/* ------------------------------------------------------------------------- */

uint16_t FAST_MOVELIST_1_0[] = { 214, 221 };
uint16_t CHARGED_MOVELIST_1_0[] = { 90, 59, 118 };
uint16_t FAST_MOVELIST_1_1[] = { 214, 221 };
uint16_t CHARGED_MOVELIST_1_1[] = { 90, 59, 118 };
pdex_mon_t DEXMON_1_1 = {
  .dex_number = 1,
  .name = "BULBASAUR",
  .form_name = "FALL_2019",
  .family = 1,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 128, .attack = 118, .defense = 111 },
  .tags = TAG_STARTER_M,
  .fast_move_ids = FAST_MOVELIST_1_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_1_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_1_0 = {
  .dex_number = 1,
  .name = "BULBASAUR",
  .form_name = "BASE",
  .family = 1,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 128, .attack = 118, .defense = 111 },
  .tags = TAG_SHADOW_ELIGABLE_M | TAG_STARTER_M,
  .fast_move_ids = FAST_MOVELIST_1_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_1_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_1_1
};
uint16_t FAST_MOVELIST_2_0[] = { 215, 214 };
uint16_t CHARGED_MOVELIST_2_0[] = { 90, 116, 118 };
pdex_mon_t DEXMON_2_0 = {
  .dex_number = 2,
  .name = "IVYSAUR",
  .form_name = "BASE",
  .family = 1,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 151, .defense = 143 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_2_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_2_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_3_0[] = { 215, 214 };
uint16_t CHARGED_MOVELIST_3_0[] = { 90, 47, 116, -296 };
uint16_t FAST_MOVELIST_3_1[] = { 215, 214 };
uint16_t CHARGED_MOVELIST_3_1[] = { 90, 47, 116, -296 };
pdex_mon_t DEXMON_3_1 = {
  .dex_number = 3,
  .name = "VENUSAUR",
  .form_name = "COPY_2019",
  .family = 1,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 189 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_3_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_3_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_3_0 = {
  .dex_number = 3,
  .name = "VENUSAUR",
  .form_name = "BASE",
  .family = 1,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 189 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_3_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_3_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_3_1
};
uint16_t FAST_MOVELIST_4_0[] = { 209, 220 };
uint16_t CHARGED_MOVELIST_4_0[] = { 101, 102, 24 };
uint16_t FAST_MOVELIST_4_1[] = { 209, 220 };
uint16_t CHARGED_MOVELIST_4_1[] = { 101, 102, 24 };
pdex_mon_t DEXMON_4_1 = {
  .dex_number = 4,
  .name = "CHARMANDER",
  .form_name = "FALL_2019",
  .family = 4,
  .types = FIRE_M,
  .base_stats = { .stamina = 118, .attack = 116, .defense = 93 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_4_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_4_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_4_0 = {
  .dex_number = 4,
  .name = "CHARMANDER",
  .form_name = "BASE",
  .family = 4,
  .types = FIRE_M,
  .base_stats = { .stamina = 118, .attack = 116, .defense = 93 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_4_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_4_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_4_1
};
uint16_t FAST_MOVELIST_5_0[] = { 209, 240, -220 };
uint16_t CHARGED_MOVELIST_5_0[] = { 115, 102, 24 };
pdex_mon_t DEXMON_5_0 = {
  .dex_number = 5,
  .name = "CHARMELEON",
  .form_name = "BASE",
  .family = 4,
  .types = FIRE_M,
  .base_stats = { .stamina = 151, .attack = 158, .defense = 126 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_5_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_5_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_6_0[] = { 269, 255, -209, -210 };
uint16_t CHARGED_MOVELIST_6_0[] = { 103, 83, 270, -298, -24 };
uint16_t FAST_MOVELIST_6_1[] = { 269, 255, -209, -210 };
uint16_t CHARGED_MOVELIST_6_1[] = { 103, 83, 270, -298, -24 };
pdex_mon_t DEXMON_6_1 = {
  .dex_number = 6,
  .name = "CHARIZARD",
  .form_name = "COPY_2019",
  .family = 4,
  .types = FIRE_M | FLYING_M,
  .base_stats = { .stamina = 186, .attack = 223, .defense = 173 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_6_1,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_6_1,
  .charged_moves_cnt = 5,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_6_0 = {
  .dex_number = 6,
  .name = "CHARIZARD",
  .form_name = "BASE",
  .family = 4,
  .types = FIRE_M | FLYING_M,
  .base_stats = { .stamina = 186, .attack = 223, .defense = 173 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_6_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_6_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = & DEXMON_6_1
};
uint16_t FAST_MOVELIST_7_0[] = { 237, 221 };
uint16_t CHARGED_MOVELIST_7_0[] = { 57, 58, 105 };
uint16_t FAST_MOVELIST_7_1[] = { 237, 221 };
uint16_t CHARGED_MOVELIST_7_1[] = { 57, 58, 105 };
pdex_mon_t DEXMON_7_1 = {
  .dex_number = 7,
  .name = "SQUIRTLE",
  .form_name = "FALL_2019",
  .family = 7,
  .types = WATER_M,
  .base_stats = { .stamina = 127, .attack = 94, .defense = 121 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_7_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_7_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_7_0 = {
  .dex_number = 7,
  .name = "SQUIRTLE",
  .form_name = "BASE",
  .family = 7,
  .types = WATER_M,
  .base_stats = { .stamina = 127, .attack = 94, .defense = 121 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_7_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_7_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_7_1
};
uint16_t FAST_MOVELIST_8_0[] = { 230, 202 };
uint16_t CHARGED_MOVELIST_8_0[] = { 57, 39, 107 };
pdex_mon_t DEXMON_8_0 = {
  .dex_number = 8,
  .name = "WARTORTLE",
  .form_name = "BASE",
  .family = 7,
  .types = WATER_M,
  .base_stats = { .stamina = 153, .attack = 126, .defense = 155 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_8_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_8_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_9_0[] = { 230, 202 };
uint16_t CHARGED_MOVELIST_9_0[] = { 36, 39, 107, 302, -299 };
uint16_t FAST_MOVELIST_9_1[] = { 230, 202 };
uint16_t CHARGED_MOVELIST_9_1[] = { 36, 39, 107, 302, -299 };
pdex_mon_t DEXMON_9_1 = {
  .dex_number = 9,
  .name = "BLASTOISE",
  .form_name = "COPY_2019",
  .family = 7,
  .types = WATER_M,
  .base_stats = { .stamina = 188, .attack = 171, .defense = 207 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_9_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_9_1,
  .charged_moves_cnt = 5,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_9_0 = {
  .dex_number = 9,
  .name = "BLASTOISE",
  .form_name = "BASE",
  .family = 7,
  .types = WATER_M,
  .base_stats = { .stamina = 188, .attack = 171, .defense = 207 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_9_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_9_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = & DEXMON_9_1
};
uint16_t FAST_MOVELIST_10_0[] = { 201, 221 };
uint16_t CHARGED_MOVELIST_10_0[] = { 133 };
pdex_mon_t DEXMON_10_0 = {
  .dex_number = 10,
  .name = "CATERPIE",
  .form_name = "BASE",
  .family = 10,
  .types = BUG_M,
  .base_stats = { .stamina = 128, .attack = 55, .defense = 55 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_10_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_10_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_11_0[] = { 201, 221 };
uint16_t CHARGED_MOVELIST_11_0[] = { 133 };
pdex_mon_t DEXMON_11_0 = {
  .dex_number = 11,
  .name = "METAPOD",
  .form_name = "BASE",
  .family = 10,
  .types = BUG_M,
  .base_stats = { .stamina = 137, .attack = 45, .defense = 80 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_11_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_11_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_12_0[] = { 261, 235, -201 };
uint16_t CHARGED_MOVELIST_12_0[] = { 49, 108, 99 };
pdex_mon_t DEXMON_12_0 = {
  .dex_number = 12,
  .name = "BUTTERFREE",
  .form_name = "BASE",
  .family = 10,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 155, .attack = 167, .defense = 137 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_12_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_12_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_13_0[] = { 201, 236 };
uint16_t CHARGED_MOVELIST_13_0[] = { 133 };
pdex_mon_t DEXMON_13_0 = {
  .dex_number = 13,
  .name = "WEEDLE",
  .form_name = "BASE",
  .family = 13,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 120, .attack = 63, .defense = 50 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_13_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_13_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_14_0[] = { 201, 236 };
uint16_t CHARGED_MOVELIST_14_0[] = { 133 };
pdex_mon_t DEXMON_14_0 = {
  .dex_number = 14,
  .name = "KAKUNA",
  .form_name = "BASE",
  .family = 13,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 128, .attack = 46, .defense = 75 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_14_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_14_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_15_0[] = { 260, 224, -201 };
uint16_t CHARGED_MOVELIST_15_0[] = { 90, 45, 100, 311, -46 };
pdex_mon_t DEXMON_15_0 = {
  .dex_number = 15,
  .name = "BEEDRILL",
  .form_name = "BASE",
  .family = 13,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 163, .attack = 169, .defense = 130 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_15_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_15_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_16_0[] = { 219, 221 };
uint16_t CHARGED_MOVELIST_16_0[] = { 80, 45, 121 };
pdex_mon_t DEXMON_16_0 = {
  .dex_number = 16,
  .name = "PIDGEY",
  .form_name = "BASE",
  .family = 16,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 120, .attack = 85, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_16_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_16_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_17_0[] = { 210, 239 };
uint16_t CHARGED_MOVELIST_17_0[] = { 80, 45, 121 };
pdex_mon_t DEXMON_17_0 = {
  .dex_number = 17,
  .name = "PIDGEOTTO",
  .form_name = "BASE",
  .family = 16,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 160, .attack = 117, .defense = 105 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_17_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_17_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_18_0[] = { 255, 239, -210 };
uint16_t CHARGED_MOVELIST_18_0[] = { 122, 45, 256, -121 };
pdex_mon_t DEXMON_18_0 = {
  .dex_number = 18,
  .name = "PIDGEOT",
  .form_name = "BASE",
  .family = 16,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 195, .attack = 166, .defense = 154 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_18_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_18_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_19_0[] = { 221, 219 };
uint16_t CHARGED_MOVELIST_19_0[] = { 26, 129, 131 };
uint16_t FAST_MOVELIST_19_1[] = { 221, 219 };
uint16_t CHARGED_MOVELIST_19_1[] = { 279, 129, 70 };
pdex_mon_t DEXMON_19_1 = {
  .dex_number = 19,
  .name = "RATTATA",
  .form_name = "ALOLA",
  .family = 19,
  .types = DARK_M | NORMAL_M,
  .base_stats = { .stamina = 102, .attack = 103, .defense = 70 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_19_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_19_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_19_0 = {
  .dex_number = 19,
  .name = "RATTATA",
  .form_name = "BASE",
  .family = 19,
  .types = NORMAL_M,
  .base_stats = { .stamina = 102, .attack = 103, .defense = 70 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_19_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_19_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_19_1
};
uint16_t FAST_MOVELIST_20_0[] = { 202, 219 };
uint16_t CHARGED_MOVELIST_20_0[] = { 26, 129, 14 };
uint16_t FAST_MOVELIST_20_1[] = { 202, 219 };
uint16_t CHARGED_MOVELIST_20_1[] = { 279, 129, 14 };
pdex_mon_t DEXMON_20_1 = {
  .dex_number = 20,
  .name = "RATICATE",
  .form_name = "ALOLA",
  .family = 19,
  .types = DARK_M | NORMAL_M,
  .base_stats = { .stamina = 181, .attack = 135, .defense = 154 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_20_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_20_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_20_0 = {
  .dex_number = 20,
  .name = "RATICATE",
  .form_name = "BASE",
  .family = 19,
  .types = NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 161, .defense = 139 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_20_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_20_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_20_1
};
uint16_t FAST_MOVELIST_21_0[] = { 211, 219 };
uint16_t CHARGED_MOVELIST_21_0[] = { 45, 38, 257, -80 };
pdex_mon_t DEXMON_21_0 = {
  .dex_number = 21,
  .name = "SPEAROW",
  .form_name = "BASE",
  .family = 21,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 120, .attack = 112, .defense = 60 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_21_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_21_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_22_0[] = { 211, 239 };
uint16_t CHARGED_MOVELIST_22_0[] = { 45, 46, 257, -80 };
pdex_mon_t DEXMON_22_0 = {
  .dex_number = 22,
  .name = "FEAROW",
  .form_name = "BASE",
  .family = 21,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 163, .attack = 182, .defense = 133 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_22_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_22_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_23_0[] = { 236, 225 };
uint16_t CHARGED_MOVELIST_23_0[] = { 13, 50, 90, -92 };
pdex_mon_t DEXMON_23_0 = {
  .dex_number = 23,
  .name = "EKANS",
  .form_name = "BASE",
  .family = 23,
  .types = POISON_M,
  .base_stats = { .stamina = 111, .attack = 110, .defense = 97 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_23_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_23_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_24_0[] = { 202, 225, 253 };
uint16_t CHARGED_MOVELIST_24_0[] = { 16, 91, 92, 303 };
pdex_mon_t DEXMON_24_0 = {
  .dex_number = 24,
  .name = "ARBOK",
  .form_name = "BASE",
  .family = 23,
  .types = POISON_M,
  .base_stats = { .stamina = 155, .attack = 167, .defense = 153 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_24_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_24_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_25_0[] = { 205, 219, -291 };
uint16_t CHARGED_MOVELIST_25_0[] = { 35, 79, 251, -284, -78 };
uint16_t FAST_MOVELIST_25_1[] = { 205, 219, -291 };
uint16_t CHARGED_MOVELIST_25_1[] = { 35, 79, 251, -284, -78 };
uint16_t FAST_MOVELIST_25_2[] = { 205, 219 };
uint16_t CHARGED_MOVELIST_25_2[] = { 35, 79, 251, 341 };
uint16_t FAST_MOVELIST_25_3[] = { 205, 219, -291 };
uint16_t CHARGED_MOVELIST_25_3[] = { 35, 79, 251, -284, -78 };
uint16_t FAST_MOVELIST_25_4[] = { 205, 320 };
uint16_t CHARGED_MOVELIST_25_4[] = { 331, 77, 88 };
pdex_mon_t DEXMON_25_4 = {
  .dex_number = 25,
  .name = "PIKACHU",
  .form_name = "VS_2019",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 111, .attack = 112, .defense = 96 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_25_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_25_4,
  .charged_moves_cnt = 3,
 .form_idx = 4,
  .next_form = NULL
};
pdex_mon_t DEXMON_25_3 = {
  .dex_number = 25,
  .name = "PIKACHU",
  .form_name = "FALL_2019",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 111, .attack = 112, .defense = 96 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_25_3,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_25_3,
  .charged_moves_cnt = 5,
 .form_idx = 3,
  .next_form = & DEXMON_25_4
};
pdex_mon_t DEXMON_25_2 = {
  .dex_number = 25,
  .name = "PIKACHU",
  .form_name = "COSTUME_2020",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 111, .attack = 112, .defense = 96 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_25_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_25_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = & DEXMON_25_3
};
pdex_mon_t DEXMON_25_1 = {
  .dex_number = 25,
  .name = "PIKACHU",
  .form_name = "COPY_2019",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 111, .attack = 112, .defense = 96 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_25_1,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_25_1,
  .charged_moves_cnt = 5,
 .form_idx = 1,
  .next_form = & DEXMON_25_2
};
pdex_mon_t DEXMON_25_0 = {
  .dex_number = 25,
  .name = "PIKACHU",
  .form_name = "BASE",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 111, .attack = 112, .defense = 96 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_25_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_25_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = & DEXMON_25_1
};
uint16_t FAST_MOVELIST_26_0[] = { 250, 206, 320, 205 };
uint16_t CHARGED_MOVELIST_26_0[] = { 123, 77, 251, 302, -78 };
uint16_t FAST_MOVELIST_26_1[] = { 250, 206, 205 };
uint16_t CHARGED_MOVELIST_26_1[] = { 108, 77, 251, 272 };
pdex_mon_t DEXMON_26_1 = {
  .dex_number = 26,
  .name = "RAICHU",
  .form_name = "ALOLA",
  .family = 25,
  .types = ELECTRIC_M | PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 201, .defense = 154 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_26_1,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_26_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_26_0 = {
  .dex_number = 26,
  .name = "RAICHU",
  .form_name = "BASE",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 155, .attack = 193, .defense = 151 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_26_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_26_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = & DEXMON_26_1
};
uint16_t FAST_MOVELIST_27_0[] = { 220, 216 };
uint16_t CHARGED_MOVELIST_27_0[] = { 26, 64, 258, -63 };
uint16_t FAST_MOVELIST_27_1[] = { 228, 244 };
uint16_t CHARGED_MOVELIST_27_1[] = { 40, 267, 51 };
pdex_mon_t DEXMON_27_1 = {
  .dex_number = 27,
  .name = "SANDSHREW",
  .form_name = "ALOLA",
  .family = 27,
  .types = ICE_M | STEEL_M,
  .base_stats = { .stamina = 137, .attack = 125, .defense = 129 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_27_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_27_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_27_0 = {
  .dex_number = 27,
  .name = "SANDSHREW",
  .form_name = "BASE",
  .family = 27,
  .types = GROUND_M,
  .base_stats = { .stamina = 137, .attack = 126, .defense = 120 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_27_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_27_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_27_1
};
uint16_t FAST_MOVELIST_28_0[] = { 228, 216 };
uint16_t CHARGED_MOVELIST_28_0[] = { 31, 63, 95 };
uint16_t FAST_MOVELIST_28_1[] = { 228, 244 };
uint16_t CHARGED_MOVELIST_28_1[] = { 40, 267, 95, 33 };
pdex_mon_t DEXMON_28_1 = {
  .dex_number = 28,
  .name = "SANDSLASH",
  .form_name = "ALOLA",
  .family = 27,
  .types = ICE_M | STEEL_M,
  .base_stats = { .stamina = 181, .attack = 177, .defense = 195 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_28_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_28_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_28_0 = {
  .dex_number = 28,
  .name = "SANDSLASH",
  .form_name = "BASE",
  .family = 27,
  .types = GROUND_M,
  .base_stats = { .stamina = 181, .attack = 182, .defense = 175 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_28_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_28_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_28_1
};
uint16_t FAST_MOVELIST_29_0[] = { 202, 236 };
uint16_t CHARGED_MOVELIST_29_0[] = { 50, 131, 90 };
pdex_mon_t DEXMON_29_0 = {
  .dex_number = 29,
  .name = "NIDORAN_FEMALE",
  .form_name = "BASE",
  .family = 29,
  .types = POISON_M,
  .base_stats = { .stamina = 146, .attack = 86, .defense = 89 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_29_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_29_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_30_0[] = { 202, 236 };
uint16_t CHARGED_MOVELIST_30_0[] = { 50, 26, 90 };
pdex_mon_t DEXMON_30_0 = {
  .dex_number = 30,
  .name = "NIDORINA",
  .form_name = "BASE",
  .family = 29,
  .types = POISON_M,
  .base_stats = { .stamina = 172, .attack = 117, .defense = 120 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_30_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_30_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_31_0[] = { 224, 202 };
uint16_t CHARGED_MOVELIST_31_0[] = { 31, 91, 32, 304 };
pdex_mon_t DEXMON_31_0 = {
  .dex_number = 31,
  .name = "NIDOQUEEN",
  .form_name = "BASE",
  .family = 29,
  .types = GROUND_M | POISON_M,
  .base_stats = { .stamina = 207, .attack = 180, .defense = 173 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_31_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_31_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_32_0[] = { 211, 236 };
uint16_t CHARGED_MOVELIST_32_0[] = { 126, 131, 90 };
pdex_mon_t DEXMON_32_0 = {
  .dex_number = 32,
  .name = "NIDORAN_MALE",
  .form_name = "BASE",
  .family = 32,
  .types = POISON_M,
  .base_stats = { .stamina = 130, .attack = 105, .defense = 76 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_32_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_32_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_33_0[] = { 224, 236 };
uint16_t CHARGED_MOVELIST_33_0[] = { 126, 26, 90 };
pdex_mon_t DEXMON_33_0 = {
  .dex_number = 33,
  .name = "NIDORINO",
  .form_name = "BASE",
  .family = 32,
  .types = POISON_M,
  .base_stats = { .stamina = 156, .attack = 137, .defense = 111 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_33_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_33_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_34_0[] = { 224, 266, -200 };
uint16_t CHARGED_MOVELIST_34_0[] = { 31, 91, 22, 304 };
pdex_mon_t DEXMON_34_0 = {
  .dex_number = 34,
  .name = "NIDOKING",
  .form_name = "BASE",
  .family = 32,
  .types = GROUND_M | POISON_M,
  .base_stats = { .stamina = 191, .attack = 204, .defense = 156 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_34_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_34_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_35_0[] = { 222, 234 };
uint16_t CHARGED_MOVELIST_35_0[] = { 84, 131, 87 };
pdex_mon_t DEXMON_35_0 = {
  .dex_number = 35,
  .name = "CLEFAIRY",
  .form_name = "BASE",
  .family = 35,
  .types = FAIRY_M,
  .base_stats = { .stamina = 172, .attack = 107, .defense = 108 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_35_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_35_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_36_0[] = { 249, 234, 320, -222 };
uint16_t CHARGED_MOVELIST_36_0[] = { 86, 108, 87, 301 };
pdex_mon_t DEXMON_36_0 = {
  .dex_number = 36,
  .name = "CLEFABLE",
  .form_name = "BASE",
  .family = 35,
  .types = FAIRY_M,
  .base_stats = { .stamina = 216, .attack = 178, .defense = 162 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_36_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_36_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_37_0[] = { 219, 209 };
uint16_t CHARGED_MOVELIST_37_0[] = { 131, 24, 101 };
uint16_t FAST_MOVELIST_37_1[] = { 234, 244 };
uint16_t CHARGED_MOVELIST_37_1[] = { 16, 39, 40 };
pdex_mon_t DEXMON_37_1 = {
  .dex_number = 37,
  .name = "VULPIX",
  .form_name = "ALOLA",
  .family = 37,
  .types = ICE_M,
  .base_stats = { .stamina = 116, .attack = 96, .defense = 109 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_37_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_37_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_37_0 = {
  .dex_number = 37,
  .name = "VULPIX",
  .form_name = "BASE",
  .family = 37,
  .types = FIRE_M,
  .base_stats = { .stamina = 116, .attack = 96, .defense = 109 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_37_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_37_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_37_1
};
uint16_t FAST_MOVELIST_38_0[] = { 238, 269, -209 };
uint16_t CHARGED_MOVELIST_38_0[] = { 42, 270, 116, 60, -103, -24 };
uint16_t FAST_MOVELIST_38_1[] = { 238, 244, 320 };
uint16_t CHARGED_MOVELIST_38_1[] = { 86, 39, 40, 60 };
pdex_mon_t DEXMON_38_1 = {
  .dex_number = 38,
  .name = "NINETALES",
  .form_name = "ALOLA",
  .family = 37,
  .types = FAIRY_M | ICE_M,
  .base_stats = { .stamina = 177, .attack = 170, .defense = 193 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_38_1,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_38_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_38_0 = {
  .dex_number = 38,
  .name = "NINETALES",
  .form_name = "BASE",
  .family = 37,
  .types = FIRE_M,
  .base_stats = { .stamina = 177, .attack = 169, .defense = 190 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_38_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_38_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = & DEXMON_38_1
};
uint16_t FAST_MOVELIST_39_0[] = { 222, 238 };
uint16_t CHARGED_MOVELIST_39_0[] = { 84, 267, 86, -88, -131 };
pdex_mon_t DEXMON_39_0 = {
  .dex_number = 39,
  .name = "JIGGLYPUFF",
  .form_name = "BASE",
  .family = 39,
  .types = FAIRY_M | NORMAL_M,
  .base_stats = { .stamina = 251, .attack = 80, .defense = 41 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_39_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_39_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_40_0[] = { 222, 238, 320 };
uint16_t CHARGED_MOVELIST_40_0[] = { 86, 14, 88, 39 };
pdex_mon_t DEXMON_40_0 = {
  .dex_number = 40,
  .name = "WIGGLYTUFF",
  .form_name = "BASE",
  .family = 39,
  .types = FAIRY_M | NORMAL_M,
  .base_stats = { .stamina = 295, .attack = 156, .defense = 90 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_40_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_40_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_41_0[] = { 219, 202 };
uint16_t CHARGED_MOVELIST_41_0[] = { 50, 121, 125, -90 };
pdex_mon_t DEXMON_41_0 = {
  .dex_number = 41,
  .name = "ZUBAT",
  .form_name = "BASE",
  .family = 41,
  .types = FLYING_M | POISON_M,
  .base_stats = { .stamina = 120, .attack = 83, .defense = 73 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_41_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_41_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_42_0[] = { 210, 202 };
uint16_t CHARGED_MOVELIST_42_0[] = { 70, 121, 50, -69 };
pdex_mon_t DEXMON_42_0 = {
  .dex_number = 42,
  .name = "GOLBAT",
  .form_name = "BASE",
  .family = 41,
  .types = FLYING_M | POISON_M,
  .base_stats = { .stamina = 181, .attack = 161, .defense = 150 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_42_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_42_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_43_0[] = { 215, 225 };
uint16_t CHARGED_MOVELIST_43_0[] = { 59, 90, 87 };
pdex_mon_t DEXMON_43_0 = {
  .dex_number = 43,
  .name = "ODDISH",
  .form_name = "BASE",
  .family = 43,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 128, .attack = 131, .defense = 112 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_43_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_43_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_44_0[] = { 215, 225 };
uint16_t CHARGED_MOVELIST_44_0[] = { 47, 90, 87 };
pdex_mon_t DEXMON_44_0 = {
  .dex_number = 44,
  .name = "GLOOM",
  .form_name = "BASE",
  .family = 43,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 153, .defense = 136 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_44_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_44_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_45_0[] = { 215, 225 };
uint16_t CHARGED_MOVELIST_45_0[] = { 47, 116, 87, 90 };
pdex_mon_t DEXMON_45_0 = {
  .dex_number = 45,
  .name = "VILEPLUME",
  .form_name = "BASE",
  .family = 43,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 181, .attack = 202, .defense = 167 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_45_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_45_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_46_0[] = { 220, 201 };
uint16_t CHARGED_MOVELIST_46_0[] = { 89, 100, 59 };
pdex_mon_t DEXMON_46_0 = {
  .dex_number = 46,
  .name = "PARAS",
  .form_name = "BASE",
  .family = 46,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 111, .attack = 121, .defense = 99 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_46_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_46_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_47_0[] = { 261, 200, -201 };
uint16_t CHARGED_MOVELIST_47_0[] = { 89, 100, 116 };
pdex_mon_t DEXMON_47_0 = {
  .dex_number = 47,
  .name = "PARASECT",
  .form_name = "BASE",
  .family = 47,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 155, .attack = 165, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_47_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_47_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_48_0[] = { 201, 235 };
uint16_t CHARGED_MOVELIST_48_0[] = { 50, 30, 99 };
pdex_mon_t DEXMON_48_0 = {
  .dex_number = 48,
  .name = "VENONAT",
  .form_name = "BASE",
  .family = 48,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 100, .defense = 100 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_48_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_48_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_49_0[] = { 260, 235, -201 };
uint16_t CHARGED_MOVELIST_49_0[] = { 262, 108, 49, 50 };
pdex_mon_t DEXMON_49_0 = {
  .dex_number = 49,
  .name = "VENOMOTH",
  .form_name = "BASE",
  .family = 48,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 172, .attack = 179, .defense = 143 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_49_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_49_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_50_0[] = { 233, 220 };
uint16_t CHARGED_MOVELIST_50_0[] = { 26, 96, 63 };
uint16_t FAST_MOVELIST_50_1[] = { 233, 228 };
uint16_t CHARGED_MOVELIST_50_1[] = { 26, 96, 63 };
pdex_mon_t DEXMON_50_1 = {
  .dex_number = 50,
  .name = "DIGLETT",
  .form_name = "ALOLA",
  .family = 50,
  .types = GROUND_M | STEEL_M,
  .base_stats = { .stamina = 67, .attack = 108, .defense = 81 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_50_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_50_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_50_0 = {
  .dex_number = 50,
  .name = "DIGLETT",
  .form_name = "BASE",
  .family = 50,
  .types = GROUND_M,
  .base_stats = { .stamina = 67, .attack = 109, .defense = 78 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_50_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_50_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_50_1
};
uint16_t FAST_MOVELIST_51_0[] = { 203, 233 };
uint16_t CHARGED_MOVELIST_51_0[] = { 31, 96, 32 };
uint16_t FAST_MOVELIST_51_1[] = { 228, 233 };
uint16_t CHARGED_MOVELIST_51_1[] = { 31, 96, 74 };
pdex_mon_t DEXMON_51_1 = {
  .dex_number = 51,
  .name = "DUGTRIO",
  .form_name = "ALOLA",
  .family = 50,
  .types = GROUND_M | STEEL_M,
  .base_stats = { .stamina = 111, .attack = 201, .defense = 142 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_51_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_51_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_51_0 = {
  .dex_number = 51,
  .name = "DUGTRIO",
  .form_name = "BASE",
  .family = 50,
  .types = GROUND_M,
  .base_stats = { .stamina = 111, .attack = 167, .defense = 134 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_51_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_51_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_51_1
};
uint16_t FAST_MOVELIST_52_0[] = { 220, 202 };
uint16_t CHARGED_MOVELIST_52_0[] = { 51, 16, 280, -131 };
uint16_t FAST_MOVELIST_52_1[] = { 220, 202 };
uint16_t CHARGED_MOVELIST_52_1[] = { 51, 16, 280 };
uint16_t FAST_MOVELIST_52_2[] = { 220, 228 };
uint16_t CHARGED_MOVELIST_52_2[] = { 51, 267, 26 };
pdex_mon_t DEXMON_52_2 = {
  .dex_number = 52,
  .name = "MEOWTH",
  .form_name = "GALARIAN",
  .family = 52,
  .types = STEEL_M,
  .base_stats = { .stamina = 137, .attack = 115, .defense = 92 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_52_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_52_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_52_1 = {
  .dex_number = 52,
  .name = "MEOWTH",
  .form_name = "ALOLA",
  .family = 52,
  .types = DARK_M,
  .base_stats = { .stamina = 120, .attack = 99, .defense = 78 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_52_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_52_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_52_2
};
pdex_mon_t DEXMON_52_0 = {
  .dex_number = 52,
  .name = "MEOWTH",
  .form_name = "BASE",
  .family = 52,
  .types = NORMAL_M,
  .base_stats = { .stamina = 120, .attack = 92, .defense = 78 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_52_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_52_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_52_1
};
uint16_t FAST_MOVELIST_53_0[] = { 220, 238 };
uint16_t CHARGED_MOVELIST_53_0[] = { 280, 65, 88, -51 };
uint16_t FAST_MOVELIST_53_1[] = { 220, 238 };
uint16_t CHARGED_MOVELIST_53_1[] = { 280, 16, 88 };
pdex_mon_t DEXMON_53_1 = {
  .dex_number = 53,
  .name = "PERSIAN",
  .form_name = "ALOLA",
  .family = 52,
  .types = DARK_M,
  .base_stats = { .stamina = 163, .attack = 158, .defense = 136 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_53_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_53_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_53_0 = {
  .dex_number = 53,
  .name = "PERSIAN",
  .form_name = "BASE",
  .family = 52,
  .types = NORMAL_M,
  .base_stats = { .stamina = 163, .attack = 150, .defense = 136 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_53_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_53_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_53_1
};
uint16_t FAST_MOVELIST_54_0[] = { 230, 234 };
uint16_t CHARGED_MOVELIST_54_0[] = { 30, 58, 28 };
pdex_mon_t DEXMON_54_0 = {
  .dex_number = 54,
  .name = "PSYDUCK",
  .form_name = "BASE",
  .family = 54,
  .types = WATER_M,
  .base_stats = { .stamina = 137, .attack = 122, .defense = 95 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_54_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_54_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_55_0[] = { 230, 235 };
uint16_t CHARGED_MOVELIST_55_0[] = { 108, 107, 39, 53, 324, 28 };
pdex_mon_t DEXMON_55_0 = {
  .dex_number = 55,
  .name = "GOLDUCK",
  .form_name = "BASE",
  .family = 54,
  .types = WATER_M,
  .base_stats = { .stamina = 190, .attack = 191, .defense = 162 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_55_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_55_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_56_0[] = { 208, 220 };
uint16_t CHARGED_MOVELIST_56_0[] = { 28, 56, 123 };
pdex_mon_t DEXMON_56_0 = {
  .dex_number = 56,
  .name = "MANKEY",
  .form_name = "BASE",
  .family = 56,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 120, .attack = 148, .defense = 82 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_56_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_56_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_57_0[] = { 207, 243, -208 };
uint16_t CHARGED_MOVELIST_57_0[] = { 245, 56, 51, -28 };
pdex_mon_t DEXMON_57_0 = {
  .dex_number = 57,
  .name = "PRIMEAPE",
  .form_name = "BASE",
  .family = 56,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 163, .attack = 207, .defense = 138 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_57_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_57_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_58_0[] = { 209, 202 };
uint16_t CHARGED_MOVELIST_58_0[] = { 21, 131, 24 };
pdex_mon_t DEXMON_58_0 = {
  .dex_number = 58,
  .name = "GROWLITHE",
  .form_name = "BASE",
  .family = 58,
  .types = FIRE_M,
  .base_stats = { .stamina = 146, .attack = 136, .defense = 93 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_58_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_58_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_59_0[] = { 240, 278, 326, -202 };
uint16_t CHARGED_MOVELIST_59_0[] = { 103, 251, 279, 24, -95 };
pdex_mon_t DEXMON_59_0 = {
  .dex_number = 59,
  .name = "ARCANINE",
  .form_name = "BASE",
  .family = 58,
  .types = FIRE_M,
  .base_stats = { .stamina = 207, .attack = 227, .defense = 166 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_59_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_59_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_60_0[] = { 237, 216 };
uint16_t CHARGED_MOVELIST_60_0[] = { 53, 96, 131 };
pdex_mon_t DEXMON_60_0 = {
  .dex_number = 60,
  .name = "POLIWAG",
  .form_name = "BASE",
  .family = 60,
  .types = WATER_M,
  .base_stats = { .stamina = 120, .attack = 101, .defense = 82 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_60_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_60_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_61_0[] = { 237, 216 };
uint16_t CHARGED_MOVELIST_61_0[] = { 105, 96, 53, -106 };
pdex_mon_t DEXMON_61_0 = {
  .dex_number = 61,
  .name = "POLIWHIRL",
  .form_name = "BASE",
  .family = 60,
  .types = WATER_M,
  .base_stats = { .stamina = 163, .attack = 130, .defense = 123 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_61_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_61_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_62_0[] = { 237, 241, 216 };
uint16_t CHARGED_MOVELIST_62_0[] = { 107, 246, 33, 319, -54 };
pdex_mon_t DEXMON_62_0 = {
  .dex_number = 62,
  .name = "POLIWRATH",
  .form_name = "BASE",
  .family = 60,
  .types = FIGHTING_M | WATER_M,
  .base_stats = { .stamina = 207, .attack = 182, .defense = 184 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_62_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_62_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_63_0[] = { 234, 249 };
uint16_t CHARGED_MOVELIST_63_0[] = { 60, 99, 70 };
pdex_mon_t DEXMON_63_0 = {
  .dex_number = 63,
  .name = "ABRA",
  .form_name = "BASE",
  .family = 63,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 93, .attack = 195, .defense = 82 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_63_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_63_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_64_0[] = { 226, 235 };
uint16_t CHARGED_MOVELIST_64_0[] = { 30, 86, 70 };
pdex_mon_t DEXMON_64_0 = {
  .dex_number = 64,
  .name = "KADABRA",
  .form_name = "BASE",
  .family = 63,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 120, .attack = 232, .defense = 117 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_64_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_64_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_65_0[] = { 226, 235, -243 };
uint16_t CHARGED_MOVELIST_65_0[] = { 275, 247, 70, 115, -86, -108 };
pdex_mon_t DEXMON_65_0 = {
  .dex_number = 65,
  .name = "ALAKAZAM",
  .form_name = "BASE",
  .family = 63,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 146, .attack = 271, .defense = 167 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_65_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_65_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_66_0[] = { 241, 208, -207 };
uint16_t CHARGED_MOVELIST_66_0[] = { 56, 123, 28 };
pdex_mon_t DEXMON_66_0 = {
  .dex_number = 66,
  .name = "MACHOP",
  .form_name = "BASE",
  .family = 66,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 172, .attack = 137, .defense = 82 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_66_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_66_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_67_0[] = { 207, 208 };
uint16_t CHARGED_MOVELIST_67_0[] = { 54, 123, 246, -28 };
pdex_mon_t DEXMON_67_0 = {
  .dex_number = 67,
  .name = "MACHOKE",
  .form_name = "BASE",
  .family = 66,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 190, .attack = 177, .defense = 125 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_67_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_67_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_68_0[] = { 229, 243, -208 };
uint16_t CHARGED_MOVELIST_68_0[] = { 268, 246, 245, 64, 28, -32, -54 };
pdex_mon_t DEXMON_68_0 = {
  .dex_number = 68,
  .name = "MACHAMP",
  .form_name = "BASE",
  .family = 66,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 207, .attack = 234, .defense = 159 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_68_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_68_0,
  .charged_moves_cnt = 7,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_69_0[] = { 214, 225 };
uint16_t CHARGED_MOVELIST_69_0[] = { 118, 90, 13 };
pdex_mon_t DEXMON_69_0 = {
  .dex_number = 69,
  .name = "BELLSPROUT",
  .form_name = "BASE",
  .family = 69,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 137, .attack = 139, .defense = 61 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_69_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_69_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_70_0[] = { 271, 225, -215 };
uint16_t CHARGED_MOVELIST_70_0[] = { 118, 90, 59 };
pdex_mon_t DEXMON_70_0 = {
  .dex_number = 70,
  .name = "WEEPINBELL",
  .form_name = "BASE",
  .family = 69,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 163, .attack = 172, .defense = 92 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_70_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_70_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_71_0[] = { 215, 225 };
uint16_t CHARGED_MOVELIST_71_0[] = { 117, 90, 116, 312, 303 };
pdex_mon_t DEXMON_71_0 = {
  .dex_number = 71,
  .name = "VICTREEBEL",
  .form_name = "BASE",
  .family = 69,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 190, .attack = 207, .defense = 135 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_71_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_71_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_72_0[] = { 237, 236 };
uint16_t CHARGED_MOVELIST_72_0[] = { 53, 105, 13 };
pdex_mon_t DEXMON_72_0 = {
  .dex_number = 72,
  .name = "TENTACOOL",
  .form_name = "BASE",
  .family = 72,
  .types = POISON_M | WATER_M,
  .base_stats = { .stamina = 120, .attack = 97, .defense = 149 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_72_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_72_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_73_0[] = { 225, 224 };
uint16_t CHARGED_MOVELIST_73_0[] = { 107, 91, 40, 303 };
pdex_mon_t DEXMON_73_0 = {
  .dex_number = 73,
  .name = "TENTACRUEL",
  .form_name = "BASE",
  .family = 72,
  .types = POISON_M | WATER_M,
  .base_stats = { .stamina = 190, .attack = 166, .defense = 209 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_73_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_73_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_74_0[] = { 227, 221 };
uint16_t CHARGED_MOVELIST_74_0[] = { 64, 63, 26 };
uint16_t FAST_MOVELIST_74_1[] = { 227, 250 };
uint16_t CHARGED_MOVELIST_74_1[] = { 64, 63, 79 };
pdex_mon_t DEXMON_74_1 = {
  .dex_number = 74,
  .name = "GEODUDE",
  .form_name = "ALOLA",
  .family = 74,
  .types = ELECTRIC_M | ROCK_M,
  .base_stats = { .stamina = 120, .attack = 132, .defense = 132 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_74_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_74_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_74_0 = {
  .dex_number = 74,
  .name = "GEODUDE",
  .form_name = "BASE",
  .family = 74,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 120, .attack = 132, .defense = 132 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_74_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_74_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_74_1
};
uint16_t FAST_MOVELIST_75_0[] = { 227, 233 };
uint16_t CHARGED_MOVELIST_75_0[] = { 26, 32, 259, -64 };
uint16_t FAST_MOVELIST_75_1[] = { 227, 250 };
uint16_t CHARGED_MOVELIST_75_1[] = { 79, 32, 259 };
pdex_mon_t DEXMON_75_1 = {
  .dex_number = 75,
  .name = "GRAVELER",
  .form_name = "ALOLA",
  .family = 74,
  .types = ELECTRIC_M | ROCK_M,
  .base_stats = { .stamina = 146, .attack = 164, .defense = 164 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_75_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_75_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_75_0 = {
  .dex_number = 75,
  .name = "GRAVELER",
  .form_name = "BASE",
  .family = 74,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 146, .attack = 164, .defense = 164 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_75_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_75_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_75_1
};
uint16_t FAST_MOVELIST_76_0[] = { 227, 233 };
uint16_t CHARGED_MOVELIST_76_0[] = { 32, 259, 31, 62 };
uint16_t FAST_MOVELIST_76_1[] = { 227, 250 };
uint16_t CHARGED_MOVELIST_76_1[] = { 32, 259, 251 };
pdex_mon_t DEXMON_76_1 = {
  .dex_number = 76,
  .name = "GOLEM",
  .form_name = "ALOLA",
  .family = 74,
  .types = ELECTRIC_M | ROCK_M,
  .base_stats = { .stamina = 190, .attack = 211, .defense = 198 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_76_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_76_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_76_0 = {
  .dex_number = 76,
  .name = "GOLEM",
  .form_name = "BASE",
  .family = 74,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 190, .attack = 211, .defense = 198 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_76_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_76_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_76_1
};
uint16_t FAST_MOVELIST_77_0[] = { 221, 209 };
uint16_t CHARGED_MOVELIST_77_0[] = { 101, 21, 127, -103 };
pdex_mon_t DEXMON_77_0 = {
  .dex_number = 77,
  .name = "PONYTA",
  .form_name = "BASE",
  .family = 77,
  .types = FIRE_M,
  .base_stats = { .stamina = 137, .attack = 170, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_77_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_77_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_78_0[] = { 207, 269, -209 };
uint16_t CHARGED_MOVELIST_78_0[] = { 103, 46, 42 };
pdex_mon_t DEXMON_78_0 = {
  .dex_number = 78,
  .name = "RAPIDASH",
  .form_name = "BASE",
  .family = 77,
  .types = FIRE_M,
  .base_stats = { .stamina = 163, .attack = 207, .defense = 162 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_78_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_78_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_79_0[] = { 230, 235 };
uint16_t CHARGED_MOVELIST_79_0[] = { 105, 60, 108 };
pdex_mon_t DEXMON_79_0 = {
  .dex_number = 79,
  .name = "SLOWPOKE",
  .form_name = "BASE",
  .family = 79,
  .types = PSYCHIC_M | WATER_M,
  .base_stats = { .stamina = 207, .attack = 109, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_79_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_79_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_80_0[] = { 230, 235 };
uint16_t CHARGED_MOVELIST_80_0[] = { 105, 108, 39 };
pdex_mon_t DEXMON_80_0 = {
  .dex_number = 80,
  .name = "SLOWBRO",
  .form_name = "BASE",
  .family = 79,
  .types = PSYCHIC_M | WATER_M,
  .base_stats = { .stamina = 216, .attack = 177, .defense = 180 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_80_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_80_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_81_0[] = { 206, 205 };
uint16_t CHARGED_MOVELIST_81_0[] = { 35, 72, 79 };
pdex_mon_t DEXMON_81_0 = {
  .dex_number = 81,
  .name = "MAGNEMITE",
  .form_name = "BASE",
  .family = 81,
  .types = ELECTRIC_M | STEEL_M,
  .base_stats = { .stamina = 93, .attack = 165, .defense = 121 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_81_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_81_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_82_0[] = { 206, 249, 205 };
uint16_t CHARGED_MOVELIST_82_0[] = { 252, 72, 36, 35 };
pdex_mon_t DEXMON_82_0 = {
  .dex_number = 82,
  .name = "MAGNETON",
  .form_name = "BASE",
  .family = 81,
  .types = ELECTRIC_M | STEEL_M,
  .base_stats = { .stamina = 137, .attack = 223, .defense = 169 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_82_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_82_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_83_0[] = { 255, 200, -223 };
uint16_t CHARGED_MOVELIST_83_0[] = { 45, 121, 117 };
uint16_t FAST_MOVELIST_83_1[] = { 241, 200 };
uint16_t CHARGED_MOVELIST_83_1[] = { 123, 256, 117 };
pdex_mon_t DEXMON_83_1 = {
  .dex_number = 83,
  .name = "FARFETCHD",
  .form_name = "GALARIAN",
  .family = 83,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 141, .attack = 174, .defense = 114 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_83_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_83_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_83_0 = {
  .dex_number = 83,
  .name = "FARFETCHD",
  .form_name = "BASE",
  .family = 83,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 141, .attack = 124, .defense = 115 },
  .tags = TAG_SHADOW_ELIGABLE_M | TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_83_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_83_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_83_1
};
uint16_t FAST_MOVELIST_84_0[] = { 211, 219 };
uint16_t CHARGED_MOVELIST_84_0[] = { 38, 45, 256, -125 };
pdex_mon_t DEXMON_84_0 = {
  .dex_number = 84,
  .name = "DODUO",
  .form_name = "BASE",
  .family = 84,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 111, .attack = 158, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_84_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_84_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_85_0[] = { 238, 239 };
uint16_t CHARGED_MOVELIST_85_0[] = { 38, 45, 256, -121 };
pdex_mon_t DEXMON_85_0 = {
  .dex_number = 85,
  .name = "DODRIO",
  .form_name = "BASE",
  .family = 84,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 218, .defense = 140 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_85_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_85_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_86_0[] = { 217, 212, -230 };
uint16_t CHARGED_MOVELIST_86_0[] = { 248, 111, 58, -57 };
pdex_mon_t DEXMON_86_0 = {
  .dex_number = 86,
  .name = "SEEL",
  .form_name = "BASE",
  .family = 86,
  .types = WATER_M,
  .base_stats = { .stamina = 163, .attack = 85, .defense = 121 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_86_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_86_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_87_0[] = { 218, 266, -217 };
uint16_t CHARGED_MOVELIST_87_0[] = { 248, 105, 40, -57, -111 };
pdex_mon_t DEXMON_87_0 = {
  .dex_number = 87,
  .name = "DEWGONG",
  .form_name = "BASE",
  .family = 86,
  .types = ICE_M | WATER_M,
  .base_stats = { .stamina = 207, .attack = 139, .defense = 177 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_87_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_87_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_88_0[] = { 224, 233 };
uint16_t CHARGED_MOVELIST_88_0[] = { 18, 96, 90 };
uint16_t FAST_MOVELIST_88_1[] = { 224, 202 };
uint16_t CHARGED_MOVELIST_88_1[] = { 279, 92, 90 };
pdex_mon_t DEXMON_88_1 = {
  .dex_number = 88,
  .name = "GRIMER",
  .form_name = "ALOLA",
  .family = 88,
  .types = DARK_M | POISON_M,
  .base_stats = { .stamina = 190, .attack = 135, .defense = 90 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_88_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_88_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_88_0 = {
  .dex_number = 88,
  .name = "GRIMER",
  .form_name = "BASE",
  .family = 88,
  .types = POISON_M,
  .base_stats = { .stamina = 190, .attack = 135, .defense = 90 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_88_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_88_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_88_1
};
uint16_t FAST_MOVELIST_89_0[] = { 260, 224, -212 };
uint16_t CHARGED_MOVELIST_89_0[] = { 16, 92, 91, 77, 303 };
uint16_t FAST_MOVELIST_89_1[] = { 202, 224, 278 };
uint16_t CHARGED_MOVELIST_89_1[] = { 16, 92, 91, 303 };
pdex_mon_t DEXMON_89_1 = {
  .dex_number = 89,
  .name = "MUK",
  .form_name = "ALOLA",
  .family = 88,
  .types = DARK_M | POISON_M,
  .base_stats = { .stamina = 233, .attack = 190, .defense = 172 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_89_1,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_89_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_89_0 = {
  .dex_number = 89,
  .name = "MUK",
  .form_name = "BASE",
  .family = 88,
  .types = POISON_M,
  .base_stats = { .stamina = 233, .attack = 190, .defense = 172 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_89_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_89_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = & DEXMON_89_1
};
uint16_t FAST_MOVELIST_90_0[] = { 217, 221 };
uint16_t CHARGED_MOVELIST_90_0[] = { 53, 105, 111 };
pdex_mon_t DEXMON_90_0 = {
  .dex_number = 90,
  .name = "SHELLDER",
  .form_name = "BASE",
  .family = 90,
  .types = WATER_M,
  .base_stats = { .stamina = 102, .attack = 116, .defense = 134 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_90_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_90_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_91_0[] = { 218, 217 };
uint16_t CHARGED_MOVELIST_91_0[] = { 248, 107, 254, 111, -40 };
pdex_mon_t DEXMON_91_0 = {
  .dex_number = 91,
  .name = "CLOYSTER",
  .form_name = "BASE",
  .family = 90,
  .types = ICE_M | WATER_M,
  .base_stats = { .stamina = 137, .attack = 186, .defense = 256 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_91_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_91_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_92_0[] = { 212, 263, -203 };
uint16_t CHARGED_MOVELIST_92_0[] = { 265, 16, 90, -69 };
pdex_mon_t DEXMON_92_0 = {
  .dex_number = 92,
  .name = "GASTLY",
  .form_name = "BASE",
  .family = 92,
  .types = GHOST_M | POISON_M,
  .base_stats = { .stamina = 102, .attack = 186, .defense = 67 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_92_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_92_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_93_0[] = { 213, 263, -212 };
uint16_t CHARGED_MOVELIST_93_0[] = { 67, 16, 90, 70 };
pdex_mon_t DEXMON_93_0 = {
  .dex_number = 93,
  .name = "HAUNTER",
  .form_name = "BASE",
  .family = 92,
  .types = GHOST_M | POISON_M,
  .base_stats = { .stamina = 128, .attack = 223, .defense = 107 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_93_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_93_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_94_0[] = { 203, 264, 213, -212 };
uint16_t CHARGED_MOVELIST_94_0[] = { 70, 247, 90, -91, -16, -108, -67 };
pdex_mon_t DEXMON_94_0 = {
  .dex_number = 94,
  .name = "GENGAR",
  .form_name = "BASE",
  .family = 92,
  .types = GHOST_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 261, .defense = 149 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_94_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_94_0,
  .charged_moves_cnt = 7,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_95_0[] = { 227, 221 };
uint16_t CHARGED_MOVELIST_95_0[] = { 258, 32, 268, -74, -64 };
pdex_mon_t DEXMON_95_0 = {
  .dex_number = 95,
  .name = "ONIX",
  .form_name = "BASE",
  .family = 95,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 111, .attack = 85, .defense = 232 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_95_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_95_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_96_0[] = { 222, 235 };
uint16_t CHARGED_MOVELIST_96_0[] = { 30, 60, 108 };
pdex_mon_t DEXMON_96_0 = {
  .dex_number = 96,
  .name = "DROWZEE",
  .form_name = "BASE",
  .family = 96,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 89, .defense = 136 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_96_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_96_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_97_0[] = { 234, 235 };
uint16_t CHARGED_MOVELIST_97_0[] = { 275, 108, 247, 115, 33, 77, 70, -60 };
pdex_mon_t DEXMON_97_0 = {
  .dex_number = 97,
  .name = "HYPNO",
  .form_name = "BASE",
  .family = 96,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 198, .attack = 144, .defense = 193 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_97_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_97_0,
  .charged_moves_cnt = 8,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_98_0[] = { 237, 216 };
uint16_t CHARGED_MOVELIST_98_0[] = { 20, 53, 105 };
pdex_mon_t DEXMON_98_0 = {
  .dex_number = 98,
  .name = "KRABBY",
  .form_name = "BASE",
  .family = 98,
  .types = WATER_M,
  .base_stats = { .stamina = 102, .attack = 181, .defense = 124 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_98_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_98_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_99_0[] = { 237, 228, -216 };
uint16_t CHARGED_MOVELIST_99_0[] = { 20, 100, 105, 305 };
pdex_mon_t DEXMON_99_0 = {
  .dex_number = 99,
  .name = "KINGLER",
  .form_name = "BASE",
  .family = 98,
  .types = WATER_M,
  .base_stats = { .stamina = 146, .attack = 240, .defense = 181 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_99_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_99_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_100_0[] = { 206, 221 };
uint16_t CHARGED_MOVELIST_100_0[] = { 35, 79, 267, -99 };
pdex_mon_t DEXMON_100_0 = {
  .dex_number = 100,
  .name = "VOLTORB",
  .form_name = "BASE",
  .family = 100,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 120, .attack = 109, .defense = 111 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_100_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_100_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_101_0[] = { 206, 250, -221 };
uint16_t CHARGED_MOVELIST_101_0[] = { 35, 79, 14, 280 };
pdex_mon_t DEXMON_101_0 = {
  .dex_number = 101,
  .name = "ELECTRODE",
  .form_name = "BASE",
  .family = 100,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 155, .attack = 173, .defense = 173 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_101_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_101_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_102_0[] = { 235, 271 };
uint16_t CHARGED_MOVELIST_102_0[] = { 59, 108, 62 };
pdex_mon_t DEXMON_102_0 = {
  .dex_number = 102,
  .name = "EXEGGCUTE",
  .form_name = "BASE",
  .family = 102,
  .types = GRASS_M | PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 107, .defense = 125 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_102_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_102_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_103_0[] = { 271, 274, 235, -234 };
uint16_t CHARGED_MOVELIST_103_0[] = { 59, 108, 116 };
uint16_t FAST_MOVELIST_103_1[] = { 271, 253 };
uint16_t CHARGED_MOVELIST_103_1[] = { 59, 82, 116 };
pdex_mon_t DEXMON_103_1 = {
  .dex_number = 103,
  .name = "EXEGGUTOR",
  .form_name = "ALOLA",
  .family = 102,
  .types = DRAGON_M | GRASS_M,
  .base_stats = { .stamina = 216, .attack = 230, .defense = 153 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_103_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_103_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_103_0 = {
  .dex_number = 103,
  .name = "EXEGGUTOR",
  .form_name = "BASE",
  .family = 102,
  .types = GRASS_M | PSYCHIC_M,
  .base_stats = { .stamina = 216, .attack = 233, .defense = 149 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_103_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_103_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_103_1
};
uint16_t FAST_MOVELIST_104_0[] = { 233, 241 };
uint16_t CHARGED_MOVELIST_104_0[] = { 94, 26, 95 };
pdex_mon_t DEXMON_104_0 = {
  .dex_number = 104,
  .name = "CUBONE",
  .form_name = "BASE",
  .family = 104,
  .types = GROUND_M,
  .base_stats = { .stamina = 137, .attack = 90, .defense = 144 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_104_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_104_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_105_0[] = { 233, 241 };
uint16_t CHARGED_MOVELIST_105_0[] = { 94, 26, 31 };
uint16_t FAST_MOVELIST_105_1[] = { 264, 241, 269 };
uint16_t CHARGED_MOVELIST_105_1[] = { 94, 70, 103, 21 };
pdex_mon_t DEXMON_105_1 = {
  .dex_number = 105,
  .name = "MAROWAK",
  .form_name = "ALOLA",
  .family = 104,
  .types = FIRE_M | GHOST_M,
  .base_stats = { .stamina = 155, .attack = 144, .defense = 186 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_105_1,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_105_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_105_0 = {
  .dex_number = 105,
  .name = "MAROWAK",
  .form_name = "BASE",
  .family = 104,
  .types = GROUND_M,
  .base_stats = { .stamina = 155, .attack = 144, .defense = 186 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_105_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_105_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_105_1
};
uint16_t FAST_MOVELIST_106_0[] = { 207, 241 };
uint16_t CHARGED_MOVELIST_106_0[] = { 245, 56, 32, -127, -123 };
pdex_mon_t DEXMON_106_0 = {
  .dex_number = 106,
  .name = "HITMONLEE",
  .form_name = "BASE",
  .family = 236,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 137, .attack = 224, .defense = 181 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_106_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_106_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_107_0[] = { 229, 243, -241 };
uint16_t CHARGED_MOVELIST_107_0[] = { 115, 33, 77, 245, 319, -123 };
pdex_mon_t DEXMON_107_0 = {
  .dex_number = 107,
  .name = "HITMONCHAN",
  .form_name = "BASE",
  .family = 236,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 137, .attack = 193, .defense = 197 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_107_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_107_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_108_0[] = { 212, 234 };
uint16_t CHARGED_MOVELIST_108_0[] = { 14, 127, 118, -131 };
pdex_mon_t DEXMON_108_0 = {
  .dex_number = 108,
  .name = "LICKITUNG",
  .form_name = "BASE",
  .family = 108,
  .types = NORMAL_M,
  .base_stats = { .stamina = 207, .attack = 108, .defense = 137 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_108_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_108_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_109_0[] = { 221, 260 };
uint16_t CHARGED_MOVELIST_109_0[] = { 18, 90, 16 };
pdex_mon_t DEXMON_109_0 = {
  .dex_number = 109,
  .name = "KOFFING",
  .form_name = "BASE",
  .family = 109,
  .types = POISON_M,
  .base_stats = { .stamina = 120, .attack = 119, .defense = 141 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_109_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_109_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_110_0[] = { 221, 260 };
uint16_t CHARGED_MOVELIST_110_0[] = { 90, 70, 16, 79 };
uint16_t FAST_MOVELIST_110_1[] = { 221 };
uint16_t CHARGED_MOVELIST_110_1[] = { 18, 14, 88, 14, 270 };
pdex_mon_t DEXMON_110_1 = {
  .dex_number = 110,
  .name = "WEEZING",
  .form_name = "GALARIAN",
  .family = 109,
  .types = FAIRY_M | POISON_M,
  .base_stats = { .stamina = 163, .attack = 174, .defense = 197 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_110_1,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_110_1,
  .charged_moves_cnt = 5,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_110_0 = {
  .dex_number = 110,
  .name = "WEEZING",
  .form_name = "BASE",
  .family = 109,
  .types = POISON_M,
  .base_stats = { .stamina = 163, .attack = 174, .defense = 197 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_110_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_110_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_110_1
};
uint16_t FAST_MOVELIST_111_0[] = { 233, 241 };
uint16_t CHARGED_MOVELIST_111_0[] = { 95, 126, 127 };
pdex_mon_t DEXMON_111_0 = {
  .dex_number = 111,
  .name = "RHYHORN",
  .form_name = "BASE",
  .family = 111,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 190, .attack = 140, .defense = 127 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_111_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_111_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_112_0[] = { 233, 241 };
uint16_t CHARGED_MOVELIST_112_0[] = { 284, 31, 32, -22 };
pdex_mon_t DEXMON_112_0 = {
  .dex_number = 112,
  .name = "RHYDON",
  .form_name = "BASE",
  .family = 111,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 233, .attack = 222, .defense = 171 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_112_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_112_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_113_0[] = { 222, 234 };
uint16_t CHARGED_MOVELIST_113_0[] = { 108, 14, 86 };
pdex_mon_t DEXMON_113_0 = {
  .dex_number = 113,
  .name = "CHANSEY",
  .form_name = "BASE",
  .family = 113,
  .types = NORMAL_M,
  .base_stats = { .stamina = 487, .attack = 60, .defense = 128 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_113_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_113_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_114_0[] = { 214, 260 };
uint16_t CHARGED_MOVELIST_114_0[] = { 272, 90, 116, -118 };
pdex_mon_t DEXMON_114_0 = {
  .dex_number = 114,
  .name = "TANGELA",
  .form_name = "BASE",
  .family = 114,
  .types = GRASS_M,
  .base_stats = { .stamina = 163, .attack = 183, .defense = 169 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_114_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_114_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_115_0[] = { 233, 207 };
uint16_t CHARGED_MOVELIST_115_0[] = { 279, 31, 277, 319, -123, -127 };
pdex_mon_t DEXMON_115_0 = {
  .dex_number = 115,
  .name = "KANGASKHAN",
  .form_name = "BASE",
  .family = 115,
  .types = NORMAL_M,
  .base_stats = { .stamina = 233, .attack = 181, .defense = 165 },
  .tags = TAG_SHADOW_ELIGABLE_M | TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_115_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_115_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_116_0[] = { 230, 237 };
uint16_t CHARGED_MOVELIST_116_0[] = { 53, 82, 36 };
pdex_mon_t DEXMON_116_0 = {
  .dex_number = 116,
  .name = "HORSEA",
  .form_name = "BASE",
  .family = 116,
  .types = WATER_M,
  .base_stats = { .stamina = 102, .attack = 129, .defense = 103 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_116_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_116_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_117_0[] = { 230, 204 };
uint16_t CHARGED_MOVELIST_117_0[] = { 248, 82, 107, -40 };
pdex_mon_t DEXMON_117_0 = {
  .dex_number = 117,
  .name = "SEADRA",
  .form_name = "BASE",
  .family = 116,
  .types = WATER_M,
  .base_stats = { .stamina = 146, .attack = 187, .defense = 156 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_117_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_117_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_118_0[] = { 211, 216 };
uint16_t CHARGED_MOVELIST_118_0[] = { 105, 126, 58 };
pdex_mon_t DEXMON_118_0 = {
  .dex_number = 118,
  .name = "GOLDEEN",
  .form_name = "BASE",
  .family = 118,
  .types = WATER_M,
  .base_stats = { .stamina = 128, .attack = 123, .defense = 110 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_118_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_118_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_119_0[] = { 211, 283, -224 };
uint16_t CHARGED_MOVELIST_119_0[] = { 39, 105, 22, -111, -46 };
pdex_mon_t DEXMON_119_0 = {
  .dex_number = 119,
  .name = "SEAKING",
  .form_name = "BASE",
  .family = 118,
  .types = WATER_M,
  .base_stats = { .stamina = 190, .attack = 175, .defense = 147 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_119_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_119_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_120_0[] = { 221, 230 };
uint16_t CHARGED_MOVELIST_120_0[] = { 125, 53, 65 };
pdex_mon_t DEXMON_120_0 = {
  .dex_number = 120,
  .name = "STARYU",
  .form_name = "BASE",
  .family = 120,
  .types = WATER_M,
  .base_stats = { .stamina = 102, .attack = 137, .defense = 112 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_120_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_120_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_121_0[] = { 281, 230, -221 };
uint16_t CHARGED_MOVELIST_121_0[] = { 107, 65, 108, 78, 39 };
pdex_mon_t DEXMON_121_0 = {
  .dex_number = 121,
  .name = "STARMIE",
  .form_name = "BASE",
  .family = 120,
  .types = PSYCHIC_M | WATER_M,
  .base_stats = { .stamina = 155, .attack = 210, .defense = 184 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_121_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_121_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_122_0[] = { 235, 234 };
uint16_t CHARGED_MOVELIST_122_0[] = { 30, 108, 70 };
pdex_mon_t DEXMON_122_0 = {
  .dex_number = 122,
  .name = "MR_MIME",
  .form_name = "BASE",
  .family = 122,
  .types = FAIRY_M | PSYCHIC_M,
  .base_stats = { .stamina = 120, .attack = 192, .defense = 205 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_122_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_122_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_123_0[] = { 200, 255, -239 };
uint16_t CHARGED_MOVELIST_123_0[] = { 51, 100, 45, -49 };
pdex_mon_t DEXMON_123_0 = {
  .dex_number = 123,
  .name = "SCYTHER",
  .form_name = "BASE",
  .family = 123,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 172, .attack = 218, .defense = 170 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_123_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_123_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_124_0[] = { 218, 235, -222 };
uint16_t CHARGED_MOVELIST_124_0[] = { 85, 254, 60, 247, -33 };
pdex_mon_t DEXMON_124_0 = {
  .dex_number = 124,
  .name = "JYNX",
  .form_name = "BASE",
  .family = 124,
  .types = ICE_M | PSYCHIC_M,
  .base_stats = { .stamina = 163, .attack = 223, .defense = 151 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_124_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_124_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_125_0[] = { 205, 207 };
uint16_t CHARGED_MOVELIST_125_0[] = { 77, 79, 78 };
pdex_mon_t DEXMON_125_0 = {
  .dex_number = 125,
  .name = "ELECTABUZZ",
  .form_name = "BASE",
  .family = 125,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 163, .attack = 198, .defense = 158 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_125_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_125_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_126_0[] = { 209, 208 };
uint16_t CHARGED_MOVELIST_126_0[] = { 103, 115, 24 };
pdex_mon_t DEXMON_126_0 = {
  .dex_number = 126,
  .name = "MAGMAR",
  .form_name = "BASE",
  .family = 126,
  .types = FIRE_M,
  .base_stats = { .stamina = 163, .attack = 206, .defense = 154 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_126_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_126_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_127_0[] = { 241, 201, 200 };
uint16_t CHARGED_MOVELIST_127_0[] = { 20, 100, 245, 310, -54 };
pdex_mon_t DEXMON_127_0 = {
  .dex_number = 127,
  .name = "PINSIR",
  .form_name = "BASE",
  .family = 127,
  .types = BUG_M,
  .base_stats = { .stamina = 163, .attack = 238, .defense = 182 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_127_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_127_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_128_0[] = { 221, 234 };
uint16_t CHARGED_MOVELIST_128_0[] = { 126, 74, 31 };
pdex_mon_t DEXMON_128_0 = {
  .dex_number = 128,
  .name = "TAUROS",
  .form_name = "BASE",
  .family = 128,
  .types = NORMAL_M,
  .base_stats = { .stamina = 181, .attack = 198, .defense = 183 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_128_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_128_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_129_0[] = { 231 };
uint16_t CHARGED_MOVELIST_129_0[] = { 133 };
pdex_mon_t DEXMON_129_0 = {
  .dex_number = 129,
  .name = "MAGIKARP",
  .form_name = "BASE",
  .family = 129,
  .types = WATER_M,
  .base_stats = { .stamina = 85, .attack = 29, .defense = 85 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_129_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_129_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_130_0[] = { 202, 283, 204, -253 };
uint16_t CHARGED_MOVELIST_130_0[] = { 107, 279, 277, 80, -82 };
pdex_mon_t DEXMON_130_0 = {
  .dex_number = 130,
  .name = "GYARADOS",
  .form_name = "BASE",
  .family = 129,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 216, .attack = 237, .defense = 186 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_130_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_130_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_131_0[] = { 218, 230, -217 };
uint16_t CHARGED_MOVELIST_131_0[] = { 107, 284, 40, 302, -82, -39 };
pdex_mon_t DEXMON_131_0 = {
  .dex_number = 131,
  .name = "LAPRAS",
  .form_name = "BASE",
  .family = 131,
  .types = ICE_M | WATER_M,
  .base_stats = { .stamina = 277, .attack = 165, .defense = 174 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_131_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_131_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_132_0[] = { 242 };
uint16_t CHARGED_MOVELIST_132_0[] = { 133 };
pdex_mon_t DEXMON_132_0 = {
  .dex_number = 132,
  .name = "DITTO",
  .form_name = "BASE",
  .family = 132,
  .types = NORMAL_M,
  .base_stats = { .stamina = 134, .attack = 91, .defense = 91 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_132_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_132_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_133_0[] = { 219, 221 };
uint16_t CHARGED_MOVELIST_133_0[] = { 26, 125, -300, -131 };
pdex_mon_t DEXMON_133_0 = {
  .dex_number = 133,
  .name = "EEVEE",
  .form_name = "BASE",
  .family = 133,
  .types = NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 104, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_133_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_133_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_134_0[] = { 230 };
uint16_t CHARGED_MOVELIST_134_0[] = { 105, 107, 58, -300 };
pdex_mon_t DEXMON_134_0 = {
  .dex_number = 134,
  .name = "VAPOREON",
  .form_name = "BASE",
  .family = 133,
  .types = WATER_M,
  .base_stats = { .stamina = 277, .attack = 205, .defense = 161 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_134_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_134_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_135_0[] = { 205, 250 };
uint16_t CHARGED_MOVELIST_135_0[] = { 35, 79, 78, -300 };
pdex_mon_t DEXMON_135_0 = {
  .dex_number = 135,
  .name = "JOLTEON",
  .form_name = "BASE",
  .family = 133,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 163, .attack = 232, .defense = 182 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_135_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_135_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_136_0[] = { 209, 269 };
uint16_t CHARGED_MOVELIST_136_0[] = { 103, 24, 270, -300, -42 };
pdex_mon_t DEXMON_136_0 = {
  .dex_number = 136,
  .name = "FLAREON",
  .form_name = "BASE",
  .family = 133,
  .types = FIRE_M,
  .base_stats = { .stamina = 163, .attack = 246, .defense = 179 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_136_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_136_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_137_0[] = { 249, 281, -221, -234 };
uint16_t CHARGED_MOVELIST_137_0[] = { 116, 14, 252, -99, -30, -35 };
pdex_mon_t DEXMON_137_0 = {
  .dex_number = 137,
  .name = "PORYGON",
  .form_name = "BASE",
  .family = 137,
  .types = NORMAL_M,
  .base_stats = { .stamina = 163, .attack = 153, .defense = 136 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_137_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_137_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_138_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_138_0[] = { 62, 53, 259, -63, -104 };
pdex_mon_t DEXMON_138_0 = {
  .dex_number = 138,
  .name = "OMANYTE",
  .form_name = "BASE",
  .family = 138,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 111, .attack = 155, .defense = 153 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_138_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_138_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_139_0[] = { 216, 230, -227 };
uint16_t CHARGED_MOVELIST_139_0[] = { 62, 107, 259, -64 };
pdex_mon_t DEXMON_139_0 = {
  .dex_number = 139,
  .name = "OMASTAR",
  .form_name = "BASE",
  .family = 138,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 172, .attack = 207, .defense = 201 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_139_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_139_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_140_0[] = { 220, 216 };
uint16_t CHARGED_MOVELIST_140_0[] = { 62, 57, 63 };
pdex_mon_t DEXMON_140_0 = {
  .dex_number = 140,
  .name = "KABUTO",
  .form_name = "BASE",
  .family = 140,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 102, .attack = 148, .defense = 140 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_140_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_140_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_141_0[] = { 216, 241, 283, -200 };
uint16_t CHARGED_MOVELIST_141_0[] = { 62, 105, 32 };
pdex_mon_t DEXMON_141_0 = {
  .dex_number = 141,
  .name = "KABUTOPS",
  .form_name = "BASE",
  .family = 141,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 155, .attack = 220, .defense = 186 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_141_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_141_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_142_0[] = { 239, 202, 227 };
uint16_t CHARGED_MOVELIST_142_0[] = { 62, 74, 14, 64, 304 };
pdex_mon_t DEXMON_142_0 = {
  .dex_number = 142,
  .name = "AERODACTYL",
  .form_name = "BASE",
  .family = 142,
  .types = FLYING_M | ROCK_M,
  .base_stats = { .stamina = 190, .attack = 221, .defense = 159 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_142_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_142_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_143_0[] = { 234, 212, -287 };
uint16_t CHARGED_MOVELIST_143_0[] = { 268, 14, 31, 277, 302, 131, 310 };
pdex_mon_t DEXMON_143_0 = {
  .dex_number = 143,
  .name = "SNORLAX",
  .form_name = "BASE",
  .family = 143,
  .types = NORMAL_M,
  .base_stats = { .stamina = 330, .attack = 190, .defense = 169 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_143_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_143_0,
  .charged_moves_cnt = 7,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_144_0[] = { 218, 217 };
uint16_t CHARGED_MOVELIST_144_0[] = { 39, 111, 40, 62, -122 };
pdex_mon_t DEXMON_144_0 = {
  .dex_number = 144,
  .name = "ARTICUNO",
  .form_name = "BASE",
  .family = 144,
  .types = FLYING_M | ICE_M,
  .base_stats = { .stamina = 207, .attack = 192, .defense = 236 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_144_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_144_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_145_0[] = { 249, -205 };
uint16_t CHARGED_MOVELIST_145_0[] = { 252, 79, 78, 62, 38 };
pdex_mon_t DEXMON_145_0 = {
  .dex_number = 145,
  .name = "ZAPDOS",
  .form_name = "BASE",
  .family = 145,
  .types = ELECTRIC_M | FLYING_M,
  .base_stats = { .stamina = 207, .attack = 253, .defense = 185 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_145_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_145_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_146_0[] = { 269, 210 };
uint16_t CHARGED_MOVELIST_146_0[] = { 103, 42, 270, 62, -257 };
pdex_mon_t DEXMON_146_0 = {
  .dex_number = 146,
  .name = "MOLTRES",
  .form_name = "BASE",
  .family = 146,
  .types = FIRE_M | FLYING_M,
  .base_stats = { .stamina = 207, .attack = 251, .defense = 181 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_146_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_146_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_147_0[] = { 204, 266 };
uint16_t CHARGED_MOVELIST_147_0[] = { 13, 80, 58 };
pdex_mon_t DEXMON_147_0 = {
  .dex_number = 147,
  .name = "DRATINI",
  .form_name = "BASE",
  .family = 147,
  .types = DRAGON_M,
  .base_stats = { .stamina = 121, .attack = 119, .defense = 91 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_147_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_147_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_148_0[] = { 204, 266 };
uint16_t CHARGED_MOVELIST_148_0[] = { 13, 58, 82 };
pdex_mon_t DEXMON_148_0 = {
  .dex_number = 148,
  .name = "DRAGONAIR",
  .form_name = "BASE",
  .family = 147,
  .types = DRAGON_M,
  .base_stats = { .stamina = 156, .attack = 163, .defense = 135 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_148_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_148_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_149_0[] = { 253, 239, 204 };
uint16_t CHARGED_MOVELIST_149_0[] = { 122, 14, 277, 83, -285, -82 };
pdex_mon_t DEXMON_149_0 = {
  .dex_number = 149,
  .name = "DRAGONITE",
  .form_name = "BASE",
  .family = 147,
  .types = DRAGON_M | FLYING_M,
  .base_stats = { .stamina = 209, .attack = 263, .defense = 198 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_149_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_149_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_150_0[] = { 226, 235 };
uint16_t CHARGED_MOVELIST_150_0[] = { 108, 79, 39, 247, 24, -109, -70, -14 };
uint16_t FAST_MOVELIST_150_1[] = { 235, 266 };
uint16_t CHARGED_MOVELIST_150_1[] = { 64, 246, 31, 275, -109 };
pdex_mon_t DEXMON_150_1 = {
  .dex_number = 150,
  .name = "MEWTWO",
  .form_name = "A",
  .family = 150,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 214, .attack = 182, .defense = 278 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_150_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_150_1,
  .charged_moves_cnt = 5,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_150_0 = {
  .dex_number = 150,
  .name = "MEWTWO",
  .form_name = "BASE",
  .family = 150,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 214, .attack = 300, .defense = 182 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_150_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_150_0,
  .charged_moves_cnt = 8,
 .form_idx = 0,
  .next_form = & DEXMON_150_1
};
uint16_t FAST_MOVELIST_151_0[] = { 222, 239, 249, 213, 250, 261, 218, 253, 260, 224, 241, 278, 223, 283 };
uint16_t CHARGED_MOVELIST_151_0[] = { 108, 62, 83, 60, 39, 40, 14, 116, 79, 78, 101, 56, 270, 247, 273, 32, 267, 95, 64, 272, 36, 251, 16, 86, 284 };
pdex_mon_t DEXMON_151_0 = {
  .dex_number = 151,
  .name = "MEW",
  .form_name = "BASE",
  .family = 151,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_151_0,
  .fast_moves_cnt = 14,
  .charged_move_ids = CHARGED_MOVELIST_151_0,
  .charged_moves_cnt = 25,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_152_0[] = { 214, 221 };
uint16_t CHARGED_MOVELIST_152_0[] = { 273, 272, 131 };
pdex_mon_t DEXMON_152_0 = {
  .dex_number = 152,
  .name = "CHIKORITA",
  .form_name = "BASE",
  .family = 152,
  .types = GRASS_M,
  .base_stats = { .stamina = 128, .attack = 92, .defense = 122 },
  .tags = TAG_STARTER_M,
  .fast_move_ids = FAST_MOVELIST_152_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_152_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_153_0[] = { 215, 221 };
uint16_t CHARGED_MOVELIST_153_0[] = { 273, 272, 62 };
pdex_mon_t DEXMON_153_0 = {
  .dex_number = 153,
  .name = "BAYLEEF",
  .form_name = "BASE",
  .family = 152,
  .types = GRASS_M,
  .base_stats = { .stamina = 155, .attack = 122, .defense = 155 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_153_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_153_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_154_0[] = { 215, 214 };
uint16_t CHARGED_MOVELIST_154_0[] = { 47, 116, 31, -296 };
pdex_mon_t DEXMON_154_0 = {
  .dex_number = 154,
  .name = "MEGANIUM",
  .form_name = "BASE",
  .family = 152,
  .types = GRASS_M,
  .base_stats = { .stamina = 190, .attack = 168, .defense = 202 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_154_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_154_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_155_0[] = { 209, 221 };
uint16_t CHARGED_MOVELIST_155_0[] = { 101, 125, 24 };
pdex_mon_t DEXMON_155_0 = {
  .dex_number = 155,
  .name = "CYNDAQUIL",
  .form_name = "BASE",
  .family = 155,
  .types = FIRE_M,
  .base_stats = { .stamina = 118, .attack = 116, .defense = 93 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_155_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_155_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_156_0[] = { 209, 221 };
uint16_t CHARGED_MOVELIST_156_0[] = { 101, 26, 24 };
pdex_mon_t DEXMON_156_0 = {
  .dex_number = 156,
  .name = "QUILAVA",
  .form_name = "BASE",
  .family = 155,
  .types = FIRE_M,
  .base_stats = { .stamina = 151, .attack = 158, .defense = 126 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_156_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_156_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_157_0[] = { 209, 213 };
uint16_t CHARGED_MOVELIST_157_0[] = { 103, 270, 116, -298 };
pdex_mon_t DEXMON_157_0 = {
  .dex_number = 157,
  .name = "TYPHLOSION",
  .form_name = "BASE",
  .family = 155,
  .types = FIRE_M,
  .base_stats = { .stamina = 186, .attack = 223, .defense = 173 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_157_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_157_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_158_0[] = { 230, 220 };
uint16_t CHARGED_MOVELIST_158_0[] = { 279, 57, 105 };
pdex_mon_t DEXMON_158_0 = {
  .dex_number = 158,
  .name = "TOTODILE",
  .form_name = "BASE",
  .family = 158,
  .types = WATER_M,
  .base_stats = { .stamina = 137, .attack = 117, .defense = 109 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_158_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_158_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_159_0[] = { 230, 220 };
uint16_t CHARGED_MOVELIST_159_0[] = { 279, 33, 105 };
pdex_mon_t DEXMON_159_0 = {
  .dex_number = 159,
  .name = "CROCONAW",
  .form_name = "BASE",
  .family = 158,
  .types = WATER_M,
  .base_stats = { .stamina = 163, .attack = 150, .defense = 142 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_159_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_159_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_160_0[] = { 283, 202, 327, -230 };
uint16_t CHARGED_MOVELIST_160_0[] = { 279, 107, 39, -299 };
pdex_mon_t DEXMON_160_0 = {
  .dex_number = 160,
  .name = "FERALIGATR",
  .form_name = "BASE",
  .family = 158,
  .types = WATER_M,
  .base_stats = { .stamina = 198, .attack = 205, .defense = 188 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_160_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_160_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_161_0[] = { 220, 219 };
uint16_t CHARGED_MOVELIST_161_0[] = { 26, 123, 272 };
pdex_mon_t DEXMON_161_0 = {
  .dex_number = 161,
  .name = "SENTRET",
  .form_name = "BASE",
  .family = 161,
  .types = NORMAL_M,
  .base_stats = { .stamina = 111, .attack = 79, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_161_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_161_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_162_0[] = { 219, 203 };
uint16_t CHARGED_MOVELIST_162_0[] = { 26, 123, 14 };
pdex_mon_t DEXMON_162_0 = {
  .dex_number = 162,
  .name = "FURRET",
  .form_name = "BASE",
  .family = 161,
  .types = NORMAL_M,
  .base_stats = { .stamina = 198, .attack = 148, .defense = 125 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_162_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_162_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_163_0[] = { 238, 211 };
uint16_t CHARGED_MOVELIST_163_0[] = { 45, 257, 265 };
pdex_mon_t DEXMON_163_0 = {
  .dex_number = 163,
  .name = "HOOTHOOT",
  .form_name = "BASE",
  .family = 163,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 67, .defense = 88 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_163_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_163_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_164_0[] = { 210, 274 };
uint16_t CHARGED_MOVELIST_164_0[] = { 108, 257, 265 };
pdex_mon_t DEXMON_164_0 = {
  .dex_number = 164,
  .name = "NOCTOWL",
  .form_name = "BASE",
  .family = 163,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 225, .attack = 145, .defense = 156 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_164_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_164_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_165_0[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_165_0[] = { 262, 125, 45 };
pdex_mon_t DEXMON_165_0 = {
  .dex_number = 165,
  .name = "LEDYBA",
  .form_name = "BASE",
  .family = 165,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 120, .attack = 72, .defense = 118 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_165_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_165_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_166_0[] = { 261, 201 };
uint16_t CHARGED_MOVELIST_166_0[] = { 49, 262, 45 };
pdex_mon_t DEXMON_166_0 = {
  .dex_number = 166,
  .name = "LEDIAN",
  .form_name = "BASE",
  .family = 165,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 146, .attack = 107, .defense = 179 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_166_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_166_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_167_0[] = { 236, 201 };
uint16_t CHARGED_MOVELIST_167_0[] = { 51, 99, 89 };
pdex_mon_t DEXMON_167_0 = {
  .dex_number = 167,
  .name = "SPINARAK",
  .form_name = "BASE",
  .family = 167,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 120, .attack = 105, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_167_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_167_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_168_0[] = { 236, 260 };
uint16_t CHARGED_MOVELIST_168_0[] = { 66, 22, 89 };
pdex_mon_t DEXMON_168_0 = {
  .dex_number = 168,
  .name = "ARIADOS",
  .form_name = "BASE",
  .family = 167,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 172, .attack = 161, .defense = 124 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_168_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_168_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_169_0[] = { 255, 202 };
uint16_t CHARGED_MOVELIST_169_0[] = { 70, 121, 90 };
pdex_mon_t DEXMON_169_0 = {
  .dex_number = 169,
  .name = "CROBAT",
  .form_name = "BASE",
  .family = 41,
  .types = FLYING_M | POISON_M,
  .base_stats = { .stamina = 198, .attack = 194, .defense = 178 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_169_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_169_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_170_0[] = { 237, 206 };
uint16_t CHARGED_MOVELIST_170_0[] = { 105, 79, 53 };
pdex_mon_t DEXMON_170_0 = {
  .dex_number = 170,
  .name = "CHINCHOU",
  .form_name = "BASE",
  .family = 170,
  .types = ELECTRIC_M | WATER_M,
  .base_stats = { .stamina = 181, .attack = 106, .defense = 97 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_170_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_170_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_171_0[] = { 230, 249, 206 };
uint16_t CHARGED_MOVELIST_171_0[] = { 107, 79, 78 };
pdex_mon_t DEXMON_171_0 = {
  .dex_number = 171,
  .name = "LANTURN",
  .form_name = "BASE",
  .family = 170,
  .types = ELECTRIC_M | WATER_M,
  .base_stats = { .stamina = 268, .attack = 146, .defense = 137 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_171_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_171_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_172_0[] = { 205 };
uint16_t CHARGED_MOVELIST_172_0[] = { 79, 84, 77 };
pdex_mon_t DEXMON_172_0 = {
  .dex_number = 172,
  .name = "PICHU",
  .form_name = "BASE",
  .family = 25,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 85, .attack = 77, .defense = 53 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_172_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_172_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_173_0[] = { 222, 234 };
uint16_t CHARGED_MOVELIST_173_0[] = { 272, 60, 99, -108, -131 };
pdex_mon_t DEXMON_173_0 = {
  .dex_number = 173,
  .name = "CLEFFA",
  .form_name = "BASE",
  .family = 35,
  .types = FAIRY_M,
  .base_stats = { .stamina = 137, .attack = 75, .defense = 79 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_173_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_173_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_174_0[] = { 222, 238 };
uint16_t CHARGED_MOVELIST_174_0[] = { 251, 70, 108, -131 };
pdex_mon_t DEXMON_174_0 = {
  .dex_number = 174,
  .name = "IGGLYBUFF",
  .form_name = "BASE",
  .family = 39,
  .types = FAIRY_M | NORMAL_M,
  .base_stats = { .stamina = 207, .attack = 69, .defense = 32 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_174_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_174_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_175_0[] = { 281, 211, -234 };
uint16_t CHARGED_MOVELIST_175_0[] = { 62, 60, 86 };
pdex_mon_t DEXMON_175_0 = {
  .dex_number = 175,
  .name = "TOGEPI",
  .form_name = "BASE",
  .family = 175,
  .types = FAIRY_M,
  .base_stats = { .stamina = 111, .attack = 67, .defense = 116 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_175_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_175_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_176_0[] = { 274, 281, -239, -234 };
uint16_t CHARGED_MOVELIST_176_0[] = { 62, 86, 45 };
pdex_mon_t DEXMON_176_0 = {
  .dex_number = 176,
  .name = "TOGETIC",
  .form_name = "BASE",
  .family = 175,
  .types = FAIRY_M | FLYING_M,
  .base_stats = { .stamina = 146, .attack = 139, .defense = 181 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_176_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_176_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_177_0[] = { 211, 219 };
uint16_t CHARGED_MOVELIST_177_0[] = { 265, 60, 38 };
pdex_mon_t DEXMON_177_0 = {
  .dex_number = 177,
  .name = "NATU",
  .form_name = "BASE",
  .family = 177,
  .types = FLYING_M | PSYCHIC_M,
  .base_stats = { .stamina = 120, .attack = 134, .defense = 89 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_177_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_177_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_178_0[] = { 255, 238 };
uint16_t CHARGED_MOVELIST_178_0[] = { 69, 275, 45 };
pdex_mon_t DEXMON_178_0 = {
  .dex_number = 178,
  .name = "XATU",
  .form_name = "BASE",
  .family = 177,
  .types = FLYING_M | PSYCHIC_M,
  .base_stats = { .stamina = 163, .attack = 192, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_178_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_178_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_179_0[] = { 221, 205 };
uint16_t CHARGED_MOVELIST_179_0[] = { 131, 79, 35 };
pdex_mon_t DEXMON_179_0 = {
  .dex_number = 179,
  .name = "MAREEP",
  .form_name = "BASE",
  .family = 179,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 146, .attack = 114, .defense = 79 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_179_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_179_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_180_0[] = { 221, 249 };
uint16_t CHARGED_MOVELIST_180_0[] = { 65, 79, 35 };
pdex_mon_t DEXMON_180_0 = {
  .dex_number = 180,
  .name = "FLAAFFY",
  .form_name = "BASE",
  .family = 179,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 172, .attack = 145, .defense = 109 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_180_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_180_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_181_0[] = { 249, 250 };
uint16_t CHARGED_MOVELIST_181_0[] = { 252, 247, 78, 65, 77, -82 };
pdex_mon_t DEXMON_181_0 = {
  .dex_number = 181,
  .name = "AMPHAROS",
  .form_name = "BASE",
  .family = 179,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 207, .attack = 211, .defense = 169 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_181_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_181_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_182_0[] = { 215, 225, 271 };
uint16_t CHARGED_MOVELIST_182_0[] = { 117, 47, 86 };
pdex_mon_t DEXMON_182_0 = {
  .dex_number = 182,
  .name = "BELLOSSOM",
  .form_name = "BASE",
  .family = 43,
  .types = GRASS_M,
  .base_stats = { .stamina = 181, .attack = 169, .defense = 186 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_182_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_182_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_183_0[] = { 221, 237 };
uint16_t CHARGED_MOVELIST_183_0[] = { 53, 58, 131 };
pdex_mon_t DEXMON_183_0 = {
  .dex_number = 183,
  .name = "MARILL",
  .form_name = "BASE",
  .family = 183,
  .types = FAIRY_M | WATER_M,
  .base_stats = { .stamina = 172, .attack = 37, .defense = 93 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_183_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_183_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_184_0[] = { 241, 237 };
uint16_t CHARGED_MOVELIST_184_0[] = { 88, 107, 39 };
pdex_mon_t DEXMON_184_0 = {
  .dex_number = 184,
  .name = "AZUMARILL",
  .form_name = "BASE",
  .family = 183,
  .types = FAIRY_M | WATER_M,
  .base_stats = { .stamina = 225, .attack = 112, .defense = 152 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_184_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_184_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_185_0[] = { 227, 243 };
uint16_t CHARGED_MOVELIST_185_0[] = { 32, 31, 64 };
pdex_mon_t DEXMON_185_0 = {
  .dex_number = 185,
  .name = "SUDOWOODO",
  .form_name = "BASE",
  .family = 185,
  .types = ROCK_M,
  .base_stats = { .stamina = 172, .attack = 167, .defense = 176 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_185_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_185_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_186_0[] = { 216, 237 };
uint16_t CHARGED_MOVELIST_186_0[] = { 107, 40, 284, -31 };
pdex_mon_t DEXMON_186_0 = {
  .dex_number = 186,
  .name = "POLITOED",
  .form_name = "BASE",
  .family = 60,
  .types = WATER_M,
  .base_stats = { .stamina = 207, .attack = 174, .defense = 179 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_186_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_186_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_187_0[] = { 221, 271 };
uint16_t CHARGED_MOVELIST_187_0[] = { 272, 86, 59 };
pdex_mon_t DEXMON_187_0 = {
  .dex_number = 187,
  .name = "HOPPIP",
  .form_name = "BASE",
  .family = 187,
  .types = FLYING_M | GRASS_M,
  .base_stats = { .stamina = 111, .attack = 67, .defense = 94 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_187_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_187_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_188_0[] = { 221, 271 };
uint16_t CHARGED_MOVELIST_188_0[] = { 272, 86, 273 };
pdex_mon_t DEXMON_188_0 = {
  .dex_number = 188,
  .name = "SKIPLOOM",
  .form_name = "BASE",
  .family = 187,
  .types = FLYING_M | GRASS_M,
  .base_stats = { .stamina = 146, .attack = 91, .defense = 120 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_188_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_188_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_189_0[] = { 260, 271 };
uint16_t CHARGED_MOVELIST_189_0[] = { 273, 86, 116, 45 };
pdex_mon_t DEXMON_189_0 = {
  .dex_number = 189,
  .name = "JUMPLUFF",
  .form_name = "BASE",
  .family = 187,
  .types = FLYING_M | GRASS_M,
  .base_stats = { .stamina = 181, .attack = 118, .defense = 183 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_189_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_189_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_190_0[] = { 220, 263 };
uint16_t CHARGED_MOVELIST_190_0[] = { 56, 125, 45 };
pdex_mon_t DEXMON_190_0 = {
  .dex_number = 190,
  .name = "AIPOM",
  .form_name = "BASE",
  .family = 190,
  .types = NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 136, .defense = 112 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_190_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_190_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_191_0[] = { 215, 223 };
uint16_t CHARGED_MOVELIST_191_0[] = { 273, 272, 59 };
pdex_mon_t DEXMON_191_0 = {
  .dex_number = 191,
  .name = "SUNKERN",
  .form_name = "BASE",
  .family = 191,
  .types = GRASS_M,
  .base_stats = { .stamina = 102, .attack = 55, .defense = 55 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_191_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_191_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_192_0[] = { 215, 271 };
uint16_t CHARGED_MOVELIST_192_0[] = { 116, 47, 90 };
pdex_mon_t DEXMON_192_0 = {
  .dex_number = 192,
  .name = "SUNFLORA",
  .form_name = "BASE",
  .family = 191,
  .types = GRASS_M,
  .base_stats = { .stamina = 181, .attack = 185, .defense = 135 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_192_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_192_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_193_0[] = { 219, 210 };
uint16_t CHARGED_MOVELIST_193_0[] = { 62, 45, 262 };
pdex_mon_t DEXMON_193_0 = {
  .dex_number = 193,
  .name = "YANMA",
  .form_name = "BASE",
  .family = 193,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 163, .attack = 154, .defense = 94 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_193_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_193_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_194_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_194_0[] = { 96, 26, 131 };
pdex_mon_t DEXMON_194_0 = {
  .dex_number = 194,
  .name = "WOOPER",
  .form_name = "BASE",
  .family = 194,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 146, .attack = 75, .defense = 66 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_194_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_194_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_195_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_195_0[] = { 90, 31, 32, 303 };
pdex_mon_t DEXMON_195_0 = {
  .dex_number = 195,
  .name = "QUAGSIRE",
  .form_name = "BASE",
  .family = 194,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 216, .attack = 152, .defense = 143 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_195_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_195_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_196_0[] = { 235, 234 };
uint16_t CHARGED_MOVELIST_196_0[] = { 30, 108, 275, -300 };
pdex_mon_t DEXMON_196_0 = {
  .dex_number = 196,
  .name = "ESPEON",
  .form_name = "BASE",
  .family = 133,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 163, .attack = 261, .defense = 175 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_196_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_196_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_197_0[] = { 238, 278 };
uint16_t CHARGED_MOVELIST_197_0[] = { 16, 280, -300 };
pdex_mon_t DEXMON_197_0 = {
  .dex_number = 197,
  .name = "UMBREON",
  .form_name = "BASE",
  .family = 133,
  .types = DARK_M,
  .base_stats = { .stamina = 216, .attack = 126, .defense = 240 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_197_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_197_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_198_0[] = { 211, 238 };
uint16_t CHARGED_MOVELIST_198_0[] = { 38, 280, 16 };
pdex_mon_t DEXMON_198_0 = {
  .dex_number = 198,
  .name = "MURKROW",
  .form_name = "BASE",
  .family = 198,
  .types = DARK_M | FLYING_M,
  .base_stats = { .stamina = 155, .attack = 175, .defense = 87 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_198_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_198_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_199_0[] = { 230, 235 };
uint16_t CHARGED_MOVELIST_199_0[] = { 40, 108, 103 };
pdex_mon_t DEXMON_199_0 = {
  .dex_number = 199,
  .name = "SLOWKING",
  .form_name = "BASE",
  .family = 79,
  .types = PSYCHIC_M | WATER_M,
  .base_stats = { .stamina = 216, .attack = 177, .defense = 180 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_199_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_199_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_200_0[] = { 263, 264 };
uint16_t CHARGED_MOVELIST_200_0[] = { 66, 16, 69 };
pdex_mon_t DEXMON_200_0 = {
  .dex_number = 200,
  .name = "MISDREAVUS",
  .form_name = "BASE",
  .family = 200,
  .types = GHOST_M,
  .base_stats = { .stamina = 155, .attack = 167, .defense = 154 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_200_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_200_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_201_0[] = { 281 };
uint16_t CHARGED_MOVELIST_201_0[] = { 133 };
pdex_mon_t DEXMON_201_0 = {
  .dex_number = 201,
  .name = "UNOWN",
  .form_name = "BASE",
  .family = 201,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 134, .attack = 136, .defense = 91 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_201_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_201_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_202_0[] = { 243, 231, 320 };
uint16_t CHARGED_MOVELIST_202_0[] = { 276 };
pdex_mon_t DEXMON_202_0 = {
  .dex_number = 202,
  .name = "WOBBUFFET",
  .form_name = "BASE",
  .family = 202,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 382, .attack = 60, .defense = 106 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_202_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_202_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_203_0[] = { 221, 235 };
uint16_t CHARGED_MOVELIST_203_0[] = { 108, 79, 276 };
pdex_mon_t DEXMON_203_0 = {
  .dex_number = 203,
  .name = "GIRAFARIG",
  .form_name = "BASE",
  .family = 203,
  .types = NORMAL_M | PSYCHIC_M,
  .base_stats = { .stamina = 172, .attack = 182, .defense = 133 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_203_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_203_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_204_0[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_204_0[] = { 267, 63, 258 };
pdex_mon_t DEXMON_204_0 = {
  .dex_number = 204,
  .name = "PINECO",
  .form_name = "BASE",
  .family = 204,
  .types = BUG_M,
  .base_stats = { .stamina = 137, .attack = 108, .defense = 122 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_204_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_204_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_205_0[] = { 201, 261 };
uint16_t CHARGED_MOVELIST_205_0[] = { 268, 31, 63, 258, 309 };
pdex_mon_t DEXMON_205_0 = {
  .dex_number = 205,
  .name = "FORRETRESS",
  .form_name = "BASE",
  .family = 204,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 181, .attack = 161, .defense = 205 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_205_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_205_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_206_0[] = { 202, 263 };
uint16_t CHARGED_MOVELIST_206_0[] = { 26, 64, 46 };
pdex_mon_t DEXMON_206_0 = {
  .dex_number = 206,
  .name = "DUNSPARCE",
  .form_name = "BASE",
  .family = 206,
  .types = NORMAL_M,
  .base_stats = { .stamina = 225, .attack = 131, .defense = 128 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_206_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_206_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_207_0[] = { 200, 210 };
uint16_t CHARGED_MOVELIST_207_0[] = { 26, 45, 51 };
pdex_mon_t DEXMON_207_0 = {
  .dex_number = 207,
  .name = "GLIGAR",
  .form_name = "BASE",
  .family = 207,
  .types = FLYING_M | GROUND_M,
  .base_stats = { .stamina = 163, .attack = 143, .defense = 184 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_207_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_207_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_208_0[] = { 266, 253, 326 };
uint16_t CHARGED_MOVELIST_208_0[] = { 31, 268, 279 };
pdex_mon_t DEXMON_208_0 = {
  .dex_number = 208,
  .name = "STEELIX",
  .form_name = "BASE",
  .family = 95,
  .types = GROUND_M | STEEL_M,
  .base_stats = { .stamina = 181, .attack = 148, .defense = 272 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_208_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_208_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_209_0[] = { 221, 202 };
uint16_t CHARGED_MOVELIST_209_0[] = { 279, 86, 123 };
pdex_mon_t DEXMON_209_0 = {
  .dex_number = 209,
  .name = "SNUBBULL",
  .form_name = "BASE",
  .family = 209,
  .types = FAIRY_M,
  .base_stats = { .stamina = 155, .attack = 137, .defense = 85 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_209_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_209_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_210_0[] = { 202, 278, 320 };
uint16_t CHARGED_MOVELIST_210_0[] = { 279, 88, 245 };
pdex_mon_t DEXMON_210_0 = {
  .dex_number = 210,
  .name = "GRANBULL",
  .form_name = "BASE",
  .family = 209,
  .types = FAIRY_M,
  .base_stats = { .stamina = 207, .attack = 212, .defense = 131 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_210_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_210_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_211_0[] = { 236, 230 };
uint16_t CHARGED_MOVELIST_211_0[] = { 58, 39, 91, 303, 311 };
pdex_mon_t DEXMON_211_0 = {
  .dex_number = 211,
  .name = "QWILFISH",
  .form_name = "BASE",
  .family = 211,
  .types = POISON_M | WATER_M,
  .base_stats = { .stamina = 163, .attack = 184, .defense = 138 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_211_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_211_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_212_0[] = { 229, 200 };
uint16_t CHARGED_MOVELIST_212_0[] = { 100, 74, 51 };
pdex_mon_t DEXMON_212_0 = {
  .dex_number = 212,
  .name = "SCIZOR",
  .form_name = "BASE",
  .family = 123,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 172, .attack = 236, .defense = 181 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_212_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_212_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_213_0[] = { 261, 227 };
uint16_t CHARGED_MOVELIST_213_0[] = { 259, 32, 267 };
pdex_mon_t DEXMON_213_0 = {
  .dex_number = 213,
  .name = "SHUCKLE",
  .form_name = "BASE",
  .family = 213,
  .types = BUG_M | ROCK_M,
  .base_stats = { .stamina = 85, .attack = 17, .defense = 396 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_213_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_213_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_214_0[] = { 243, 261 };
uint16_t CHARGED_MOVELIST_214_0[] = { 22, 245, 31 };
pdex_mon_t DEXMON_214_0 = {
  .dex_number = 214,
  .name = "HERACROSS",
  .form_name = "BASE",
  .family = 214,
  .types = BUG_M | FIGHTING_M,
  .base_stats = { .stamina = 190, .attack = 234, .defense = 179 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_214_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_214_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_215_0[] = { 217, 238 };
uint16_t CHARGED_MOVELIST_215_0[] = { 254, 33, 280 };
pdex_mon_t DEXMON_215_0 = {
  .dex_number = 215,
  .name = "SNEASEL",
  .form_name = "BASE",
  .family = 215,
  .types = DARK_M | ICE_M,
  .base_stats = { .stamina = 146, .attack = 189, .defense = 146 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_215_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_215_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_216_0[] = { 220, 212 };
uint16_t CHARGED_MOVELIST_216_0[] = { 28, 279, 88 };
pdex_mon_t DEXMON_216_0 = {
  .dex_number = 216,
  .name = "TEDDIURSA",
  .form_name = "BASE",
  .family = 216,
  .types = NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 142, .defense = 93 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_216_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_216_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_217_0[] = { 228, 243, 213 };
uint16_t CHARGED_MOVELIST_217_0[] = { 245, 14, 88 };
pdex_mon_t DEXMON_217_0 = {
  .dex_number = 217,
  .name = "URSARING",
  .form_name = "BASE",
  .family = 216,
  .types = NORMAL_M,
  .base_stats = { .stamina = 207, .attack = 236, .defense = 144 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_217_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_217_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_218_0[] = { 209, 227 };
uint16_t CHARGED_MOVELIST_218_0[] = { 102, 101, 64 };
pdex_mon_t DEXMON_218_0 = {
  .dex_number = 218,
  .name = "SLUGMA",
  .form_name = "BASE",
  .family = 218,
  .types = FIRE_M,
  .base_stats = { .stamina = 120, .attack = 118, .defense = 71 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_218_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_218_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_219_0[] = { 209, 227 };
uint16_t CHARGED_MOVELIST_219_0[] = { 42, 270, 32 };
pdex_mon_t DEXMON_219_0 = {
  .dex_number = 219,
  .name = "MAGCARGO",
  .form_name = "BASE",
  .family = 218,
  .types = FIRE_M | ROCK_M,
  .base_stats = { .stamina = 137, .attack = 139, .defense = 191 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_219_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_219_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_220_0[] = { 221, 244 };
uint16_t CHARGED_MOVELIST_220_0[] = { 111, 131, 64 };
pdex_mon_t DEXMON_220_0 = {
  .dex_number = 220,
  .name = "SWINUB",
  .form_name = "BASE",
  .family = 220,
  .types = GROUND_M | ICE_M,
  .base_stats = { .stamina = 137, .attack = 90, .defense = 69 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_220_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_220_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_221_0[] = { 217, 244 };
uint16_t CHARGED_MOVELIST_221_0[] = { 254, 95, 32 };
pdex_mon_t DEXMON_221_0 = {
  .dex_number = 221,
  .name = "PILOSWINE",
  .form_name = "BASE",
  .family = 220,
  .types = GROUND_M | ICE_M,
  .base_stats = { .stamina = 225, .attack = 181, .defense = 138 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_221_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_221_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_222_0[] = { 221, 237 };
uint16_t CHARGED_MOVELIST_222_0[] = { 259, 65, 53 };
pdex_mon_t DEXMON_222_0 = {
  .dex_number = 222,
  .name = "CORSOLA",
  .form_name = "BASE",
  .family = 222,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 146, .attack = 118, .defense = 156 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_222_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_222_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_223_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_223_0[] = { 248, 105, 259 };
pdex_mon_t DEXMON_223_0 = {
  .dex_number = 223,
  .name = "REMORAID",
  .form_name = "BASE",
  .family = 223,
  .types = WATER_M,
  .base_stats = { .stamina = 111, .attack = 127, .defense = 69 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_223_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_223_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_224_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_224_0[] = { 92, 105, 248, 303, 308 };
pdex_mon_t DEXMON_224_0 = {
  .dex_number = 224,
  .name = "OCTILLERY",
  .form_name = "BASE",
  .family = 223,
  .types = WATER_M,
  .base_stats = { .stamina = 181, .attack = 197, .defense = 141 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_224_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_224_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_225_0[] = { 291 };
uint16_t CHARGED_MOVELIST_225_0[] = { 33, 111, 45 };
pdex_mon_t DEXMON_225_0 = {
  .dex_number = 225,
  .name = "DELIBIRD",
  .form_name = "BASE",
  .family = 225,
  .types = FLYING_M | ICE_M,
  .base_stats = { .stamina = 128, .attack = 128, .defense = 90 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_225_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_225_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_226_0[] = { 237, 210, 271 };
uint16_t CHARGED_MOVELIST_226_0[] = { 105, 39, 45, 53 };
pdex_mon_t DEXMON_226_0 = {
  .dex_number = 226,
  .name = "MANTINE",
  .form_name = "BASE",
  .family = 226,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 163, .attack = 148, .defense = 226 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_226_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_226_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_227_0[] = { 239, 255 };
uint16_t CHARGED_MOVELIST_227_0[] = { 256, 257, 36 };
pdex_mon_t DEXMON_227_0 = {
  .dex_number = 227,
  .name = "SKARMORY",
  .form_name = "BASE",
  .family = 227,
  .types = FLYING_M | STEEL_M,
  .base_stats = { .stamina = 163, .attack = 148, .defense = 226 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_227_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_227_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_228_0[] = { 238, 209 };
uint16_t CHARGED_MOVELIST_228_0[] = { 279, 24, 16 };
pdex_mon_t DEXMON_228_0 = {
  .dex_number = 228,
  .name = "HOUNDOUR",
  .form_name = "BASE",
  .family = 228,
  .types = DARK_M | FIRE_M,
  .base_stats = { .stamina = 128, .attack = 152, .defense = 83 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_228_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_228_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_229_0[] = { 278, 240 };
uint16_t CHARGED_MOVELIST_229_0[] = { 279, 103, 280, 24 };
pdex_mon_t DEXMON_229_0 = {
  .dex_number = 229,
  .name = "HOUNDOOM",
  .form_name = "BASE",
  .family = 228,
  .types = DARK_M | FIRE_M,
  .base_stats = { .stamina = 181, .attack = 224, .defense = 144 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_229_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_229_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_230_0[] = { 283, 204, -230 };
uint16_t CHARGED_MOVELIST_230_0[] = { 107, 40, 277, 308 };
pdex_mon_t DEXMON_230_0 = {
  .dex_number = 230,
  .name = "KINGDRA",
  .form_name = "BASE",
  .family = 116,
  .types = DRAGON_M | WATER_M,
  .base_stats = { .stamina = 181, .attack = 194, .defense = 194 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_230_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_230_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_231_0[] = { 221, 241 };
uint16_t CHARGED_MOVELIST_231_0[] = { 95, 64, 131 };
pdex_mon_t DEXMON_231_0 = {
  .dex_number = 231,
  .name = "PHANPY",
  .form_name = "BASE",
  .family = 231,
  .types = GROUND_M,
  .base_stats = { .stamina = 207, .attack = 107, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_231_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_231_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_232_0[] = { 221, 243, 233, 320 };
uint16_t CHARGED_MOVELIST_232_0[] = { 31, 268, 88 };
pdex_mon_t DEXMON_232_0 = {
  .dex_number = 232,
  .name = "DONPHAN",
  .form_name = "BASE",
  .family = 231,
  .types = GROUND_M,
  .base_stats = { .stamina = 207, .attack = 214, .defense = 185 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_232_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_232_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_233_0[] = { 281, 249, 325 };
uint16_t CHARGED_MOVELIST_233_0[] = { 116, 14, 252 };
pdex_mon_t DEXMON_233_0 = {
  .dex_number = 233,
  .name = "PORYGON2",
  .form_name = "BASE",
  .family = 233,
  .types = NORMAL_M,
  .base_stats = { .stamina = 198, .attack = 198, .defense = 180 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_233_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_233_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_234_0[] = { 221, 234 };
uint16_t CHARGED_MOVELIST_234_0[] = { 127, 251, 22 };
pdex_mon_t DEXMON_234_0 = {
  .dex_number = 234,
  .name = "STANTLER",
  .form_name = "BASE",
  .family = 234,
  .types = NORMAL_M,
  .base_stats = { .stamina = 177, .attack = 192, .defense = 131 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_234_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_234_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_235_0[] = {};
uint16_t CHARGED_MOVELIST_235_0[] = {};
pdex_mon_t DEXMON_235_0 = {
  .dex_number = 235,
  .name = "SMEARGLE",
  .form_name = "BASE",
  .family = 235,
  .types = NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 40, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_235_0,
  .fast_moves_cnt = 0,
  .charged_move_ids = CHARGED_MOVELIST_235_0,
  .charged_moves_cnt = 0,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_236_0[] = { 241, 221 };
uint16_t CHARGED_MOVELIST_236_0[] = { 123, 64, 56 };
pdex_mon_t DEXMON_236_0 = {
  .dex_number = 236,
  .name = "TYROGUE",
  .form_name = "BASE",
  .family = 236,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 111, .attack = 64, .defense = 64 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_236_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_236_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_237_0[] = { 241, 243 };
uint16_t CHARGED_MOVELIST_237_0[] = { 245, 267, 32 };
pdex_mon_t DEXMON_237_0 = {
  .dex_number = 237,
  .name = "HITMONTOP",
  .form_name = "BASE",
  .family = 236,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 137, .attack = 173, .defense = 207 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_237_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_237_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_238_0[] = { 244, 222, -218 };
uint16_t CHARGED_MOVELIST_238_0[] = { 39, 33, 60 };
pdex_mon_t DEXMON_238_0 = {
  .dex_number = 238,
  .name = "SMOOCHUM",
  .form_name = "BASE",
  .family = 124,
  .types = ICE_M | PSYCHIC_M,
  .base_stats = { .stamina = 128, .attack = 153, .defense = 91 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_238_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_238_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_239_0[] = { 205, 207 };
uint16_t CHARGED_MOVELIST_239_0[] = { 77, 123, 35, -79 };
pdex_mon_t DEXMON_239_0 = {
  .dex_number = 239,
  .name = "ELEKID",
  .form_name = "BASE",
  .family = 125,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 128, .attack = 135, .defense = 101 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_239_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_239_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_240_0[] = { 209, 208 };
uint16_t CHARGED_MOVELIST_240_0[] = { 123, 115, 102, -24 };
pdex_mon_t DEXMON_240_0 = {
  .dex_number = 240,
  .name = "MAGBY",
  .form_name = "BASE",
  .family = 126,
  .types = FIRE_M,
  .base_stats = { .stamina = 128, .attack = 151, .defense = 99 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_240_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_240_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_241_0[] = { 221, 234 };
uint16_t CHARGED_MOVELIST_241_0[] = { 127, 131, 267, 79, 39 };
pdex_mon_t DEXMON_241_0 = {
  .dex_number = 241,
  .name = "MILTANK",
  .form_name = "BASE",
  .family = 241,
  .types = NORMAL_M,
  .base_stats = { .stamina = 216, .attack = 157, .defense = 193 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_241_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_241_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_242_0[] = { 222, 234 };
uint16_t CHARGED_MOVELIST_242_0[] = { 108, 14, 86 };
pdex_mon_t DEXMON_242_0 = {
  .dex_number = 242,
  .name = "BLISSEY",
  .form_name = "BASE",
  .family = 113,
  .types = NORMAL_M,
  .base_stats = { .stamina = 496, .attack = 129, .defense = 169 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_242_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_242_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_243_0[] = { 205, 250 };
uint16_t CHARGED_MOVELIST_243_0[] = { 78, 79, 251, 70 };
pdex_mon_t DEXMON_243_0 = {
  .dex_number = 243,
  .name = "RAIKOU",
  .form_name = "BASE",
  .family = 243,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 207, .attack = 241, .defense = 195 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_243_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_243_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_244_0[] = { 269, 240 };
uint16_t CHARGED_MOVELIST_244_0[] = { 24, 103, 270, 74 };
pdex_mon_t DEXMON_244_0 = {
  .dex_number = 244,
  .name = "ENTEI",
  .form_name = "BASE",
  .family = 244,
  .types = FIRE_M,
  .base_stats = { .stamina = 251, .attack = 235, .defense = 171 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_244_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_244_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_245_0[] = { 274, 278, 327, -281 };
uint16_t CHARGED_MOVELIST_245_0[] = { 107, 53, 105, 39 };
pdex_mon_t DEXMON_245_0 = {
  .dex_number = 245,
  .name = "SUICUNE",
  .form_name = "BASE",
  .family = 245,
  .types = WATER_M,
  .base_stats = { .stamina = 225, .attack = 180, .defense = 235 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_245_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_245_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_246_0[] = { 202, 241 };
uint16_t CHARGED_MOVELIST_246_0[] = { 127, 279, 62 };
pdex_mon_t DEXMON_246_0 = {
  .dex_number = 246,
  .name = "LARVITAR",
  .form_name = "BASE",
  .family = 246,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 137, .attack = 115, .defense = 93 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_246_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_246_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_247_0[] = { 202, 241 };
uint16_t CHARGED_MOVELIST_247_0[] = { 26, 279, 62 };
pdex_mon_t DEXMON_247_0 = {
  .dex_number = 247,
  .name = "PUPITAR",
  .form_name = "BASE",
  .family = 246,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 172, .attack = 155, .defense = 133 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_247_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_247_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_248_0[] = { 202, 266, -297 };
uint16_t CHARGED_MOVELIST_248_0[] = { 103, 279, 32 };
pdex_mon_t DEXMON_248_0 = {
  .dex_number = 248,
  .name = "TYRANITAR",
  .form_name = "BASE",
  .family = 246,
  .types = DARK_M | ROCK_M,
  .base_stats = { .stamina = 225, .attack = 251, .defense = 207 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_248_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_248_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_249_0[] = { 274, 253 };
uint16_t CHARGED_MOVELIST_249_0[] = { 257, 107, 275 };
pdex_mon_t DEXMON_249_0 = {
  .dex_number = 249,
  .name = "LUGIA",
  .form_name = "BASE",
  .family = 249,
  .types = FLYING_M | PSYCHIC_M,
  .base_stats = { .stamina = 235, .attack = 193, .defense = 310 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_249_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_249_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_250_0[] = { 274, 239, 281 };
uint16_t CHARGED_MOVELIST_250_0[] = { 256, 103, 116, -31 };
pdex_mon_t DEXMON_250_0 = {
  .dex_number = 250,
  .name = "HO_OH",
  .form_name = "BASE",
  .family = 250,
  .types = FIRE_M | FLYING_M,
  .base_stats = { .stamina = 214, .attack = 239, .defense = 244 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_250_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_250_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_251_0[] = { 235, 249 };
uint16_t CHARGED_MOVELIST_251_0[] = { 14, 108, 86, 59 };
pdex_mon_t DEXMON_251_0 = {
  .dex_number = 251,
  .name = "CELEBI",
  .form_name = "BASE",
  .family = 251,
  .types = GRASS_M | PSYCHIC_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_251_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_251_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_252_0[] = { 222, 271 };
uint16_t CHARGED_MOVELIST_252_0[] = { 273, 45, 272 };
pdex_mon_t DEXMON_252_0 = {
  .dex_number = 252,
  .name = "TREECKO",
  .form_name = "BASE",
  .family = 252,
  .types = GRASS_M,
  .base_stats = { .stamina = 120, .attack = 124, .defense = 94 },
  .tags = TAG_STARTER_M,
  .fast_move_ids = FAST_MOVELIST_252_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_252_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_253_0[] = { 219, 271 };
uint16_t CHARGED_MOVELIST_253_0[] = { 117, 45, 272 };
pdex_mon_t DEXMON_253_0 = {
  .dex_number = 253,
  .name = "GROVYLE",
  .form_name = "BASE",
  .family = 252,
  .types = GRASS_M,
  .base_stats = { .stamina = 137, .attack = 172, .defense = 120 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_253_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_253_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_254_0[] = { 200, 271 };
uint16_t CHARGED_MOVELIST_254_0[] = { 117, 45, 31, 83, -296 };
pdex_mon_t DEXMON_254_0 = {
  .dex_number = 254,
  .name = "SCEPTILE",
  .form_name = "BASE",
  .family = 252,
  .types = GRASS_M,
  .base_stats = { .stamina = 172, .attack = 223, .defense = 169 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_254_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_254_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_255_0[] = { 220, 209 };
uint16_t CHARGED_MOVELIST_255_0[] = { 101, 24, 63 };
pdex_mon_t DEXMON_255_0 = {
  .dex_number = 255,
  .name = "TORCHIC",
  .form_name = "BASE",
  .family = 255,
  .types = FIRE_M,
  .base_stats = { .stamina = 128, .attack = 130, .defense = 87 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_255_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_255_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_256_0[] = { 211, 209 };
uint16_t CHARGED_MOVELIST_256_0[] = { 101, 24, 64 };
pdex_mon_t DEXMON_256_0 = {
  .dex_number = 256,
  .name = "COMBUSKEN",
  .form_name = "BASE",
  .family = 255,
  .types = FIGHTING_M | FIRE_M,
  .base_stats = { .stamina = 155, .attack = 163, .defense = 115 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_256_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_256_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_257_0[] = { 243, 269 };
uint16_t CHARGED_MOVELIST_257_0[] = { 247, 270, 256, 317, -298, -32 };
pdex_mon_t DEXMON_257_0 = {
  .dex_number = 257,
  .name = "BLAZIKEN",
  .form_name = "BASE",
  .family = 255,
  .types = FIGHTING_M | FIRE_M,
  .base_stats = { .stamina = 190, .attack = 240, .defense = 141 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_257_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_257_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_258_0[] = { 221, 230 };
uint16_t CHARGED_MOVELIST_258_0[] = { 26, 18, 127 };
pdex_mon_t DEXMON_258_0 = {
  .dex_number = 258,
  .name = "MUDKIP",
  .form_name = "BASE",
  .family = 258,
  .types = WATER_M,
  .base_stats = { .stamina = 137, .attack = 126, .defense = 93 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_258_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_258_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_259_0[] = { 216, 230 };
uint16_t CHARGED_MOVELIST_259_0[] = { 96, 18, 284 };
pdex_mon_t DEXMON_259_0 = {
  .dex_number = 259,
  .name = "MARSHTOMP",
  .form_name = "BASE",
  .family = 258,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 172, .attack = 156, .defense = 133 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_259_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_259_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_260_0[] = { 216, 230 };
uint16_t CHARGED_MOVELIST_260_0[] = { 31, 91, 284, 316, -299 };
pdex_mon_t DEXMON_260_0 = {
  .dex_number = 260,
  .name = "SWAMPERT",
  .form_name = "BASE",
  .family = 258,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 225, .attack = 208, .defense = 175 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_260_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_260_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_261_0[] = { 221, 278 };
uint16_t CHARGED_MOVELIST_261_0[] = { 279, 26, 50 };
pdex_mon_t DEXMON_261_0 = {
  .dex_number = 261,
  .name = "POOCHYENA",
  .form_name = "BASE",
  .family = 261,
  .types = DARK_M,
  .base_stats = { .stamina = 111, .attack = 96, .defense = 61 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_261_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_261_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_262_0[] = { 202, 240, 326, 327 };
uint16_t CHARGED_MOVELIST_262_0[] = { 279, 88, 50 };
pdex_mon_t DEXMON_262_0 = {
  .dex_number = 262,
  .name = "MIGHTYENA",
  .form_name = "BASE",
  .family = 261,
  .types = DARK_M,
  .base_stats = { .stamina = 172, .attack = 171, .defense = 132 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_262_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_262_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_263_0[] = { 221, 241 };
uint16_t CHARGED_MOVELIST_263_0[] = { 26, 272, 79 };
uint16_t FAST_MOVELIST_263_1[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_263_1[] = { 26, 131, 125 };
pdex_mon_t DEXMON_263_1 = {
  .dex_number = 263,
  .name = "ZIGZAGOON",
  .form_name = "GALARIAN",
  .family = 263,
  .types = DARK_M | NORMAL_M,
  .base_stats = { .stamina = 116, .attack = 58, .defense = 80 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_263_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_263_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_263_0 = {
  .dex_number = 263,
  .name = "ZIGZAGOON",
  .form_name = "BASE",
  .family = 263,
  .types = NORMAL_M,
  .base_stats = { .stamina = 116, .attack = 58, .defense = 80 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_263_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_263_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_263_1
};
uint16_t FAST_MOVELIST_264_0[] = { 213, 221 };
uint16_t CHARGED_MOVELIST_264_0[] = { 26, 272, 78 };
uint16_t FAST_MOVELIST_264_1[] = { 278, 212 };
uint16_t CHARGED_MOVELIST_264_1[] = { 26, 131, 92 };
pdex_mon_t DEXMON_264_1 = {
  .dex_number = 264,
  .name = "LINOONE",
  .form_name = "GALARIAN",
  .family = 263,
  .types = DARK_M | NORMAL_M,
  .base_stats = { .stamina = 186, .attack = 142, .defense = 128 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_264_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_264_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_264_0 = {
  .dex_number = 264,
  .name = "LINOONE",
  .form_name = "BASE",
  .family = 263,
  .types = NORMAL_M,
  .base_stats = { .stamina = 186, .attack = 142, .defense = 128 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_264_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_264_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_264_1
};
uint16_t FAST_MOVELIST_265_0[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_265_0[] = { 133 };
pdex_mon_t DEXMON_265_0 = {
  .dex_number = 265,
  .name = "WURMPLE",
  .form_name = "BASE",
  .family = 265,
  .types = BUG_M,
  .base_stats = { .stamina = 128, .attack = 75, .defense = 59 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_265_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_265_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_266_0[] = { 236, 201 };
uint16_t CHARGED_MOVELIST_266_0[] = { 133 };
pdex_mon_t DEXMON_266_0 = {
  .dex_number = 266,
  .name = "SILCOON",
  .form_name = "BASE",
  .family = 265,
  .types = BUG_M,
  .base_stats = { .stamina = 137, .attack = 60, .defense = 77 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_266_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_266_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_267_0[] = { 261, 260 };
uint16_t CHARGED_MOVELIST_267_0[] = { 262, 121, 49 };
pdex_mon_t DEXMON_267_0 = {
  .dex_number = 267,
  .name = "BEAUTIFLY",
  .form_name = "BASE",
  .family = 265,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 155, .attack = 189, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_267_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_267_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_268_0[] = { 236, 201 };
uint16_t CHARGED_MOVELIST_268_0[] = { 133 };
pdex_mon_t DEXMON_268_0 = {
  .dex_number = 268,
  .name = "CASCOON",
  .form_name = "BASE",
  .family = 265,
  .types = BUG_M,
  .base_stats = { .stamina = 137, .attack = 60, .defense = 77 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_268_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_268_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_269_0[] = { 261, 235 };
uint16_t CHARGED_MOVELIST_269_0[] = { 262, 90, 49 };
pdex_mon_t DEXMON_269_0 = {
  .dex_number = 269,
  .name = "DUSTOX",
  .form_name = "BASE",
  .family = 265,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 98, .defense = 162 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_269_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_269_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_270_0[] = { 230, 215 };
uint16_t CHARGED_MOVELIST_270_0[] = { 53, 273 };
pdex_mon_t DEXMON_270_0 = {
  .dex_number = 270,
  .name = "LOTAD",
  .form_name = "BASE",
  .family = 270,
  .types = GRASS_M | WATER_M,
  .base_stats = { .stamina = 120, .attack = 71, .defense = 77 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_270_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_270_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_271_0[] = { 237, 215 };
uint16_t CHARGED_MOVELIST_271_0[] = { 53, 39, 272 };
pdex_mon_t DEXMON_271_0 = {
  .dex_number = 271,
  .name = "LOMBRE",
  .form_name = "BASE",
  .family = 270,
  .types = GRASS_M | WATER_M,
  .base_stats = { .stamina = 155, .attack = 112, .defense = 119 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_271_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_271_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_272_0[] = { 237, 215 };
uint16_t CHARGED_MOVELIST_272_0[] = { 107, 40, 116, 39, 273 };
pdex_mon_t DEXMON_272_0 = {
  .dex_number = 272,
  .name = "LUDICOLO",
  .form_name = "BASE",
  .family = 270,
  .types = GRASS_M | WATER_M,
  .base_stats = { .stamina = 190, .attack = 173, .defense = 176 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_272_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_272_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_273_0[] = { 271, 219 };
uint16_t CHARGED_MOVELIST_273_0[] = { 273, 272, 280 };
pdex_mon_t DEXMON_273_0 = {
  .dex_number = 273,
  .name = "SEEDOT",
  .form_name = "BASE",
  .family = 273,
  .types = GRASS_M,
  .base_stats = { .stamina = 120, .attack = 71, .defense = 77 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_273_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_273_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_274_0[] = { 215, 238 };
uint16_t CHARGED_MOVELIST_274_0[] = { 117, 272, 280 };
pdex_mon_t DEXMON_274_0 = {
  .dex_number = 274,
  .name = "NUZLEAF",
  .form_name = "BASE",
  .family = 273,
  .types = DARK_M | GRASS_M,
  .base_stats = { .stamina = 172, .attack = 134, .defense = 78 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_274_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_274_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_275_0[] = { 215, 238, 278, -271 };
uint16_t CHARGED_MOVELIST_275_0[] = { 117, 122, 280, 312 };
pdex_mon_t DEXMON_275_0 = {
  .dex_number = 275,
  .name = "SHIFTRY",
  .form_name = "BASE",
  .family = 273,
  .types = DARK_M | GRASS_M,
  .base_stats = { .stamina = 207, .attack = 200, .defense = 121 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_275_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_275_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_276_0[] = { 211, 219 };
uint16_t CHARGED_MOVELIST_276_0[] = { 45 };
pdex_mon_t DEXMON_276_0 = {
  .dex_number = 276,
  .name = "TAILLOW",
  .form_name = "BASE",
  .family = 276,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 120, .attack = 106, .defense = 61 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_276_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_276_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_277_0[] = { 210, 239 };
uint16_t CHARGED_MOVELIST_277_0[] = { 45, 256, 257 };
pdex_mon_t DEXMON_277_0 = {
  .dex_number = 277,
  .name = "SWELLOW",
  .form_name = "BASE",
  .family = 276,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 185, .defense = 124 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_277_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_277_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_278_0[] = { 230, 219 };
uint16_t CHARGED_MOVELIST_278_0[] = { 105, 121, 39 };
pdex_mon_t DEXMON_278_0 = {
  .dex_number = 278,
  .name = "WINGULL",
  .form_name = "BASE",
  .family = 278,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 120, .attack = 106, .defense = 61 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_278_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_278_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_279_0[] = { 230, 210 };
uint16_t CHARGED_MOVELIST_279_0[] = { 107, 122, 40 };
pdex_mon_t DEXMON_279_0 = {
  .dex_number = 279,
  .name = "PELIPPER",
  .form_name = "BASE",
  .family = 278,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 155, .attack = 175, .defense = 174 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_279_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_279_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_280_0[] = { 235, 249 };
uint16_t CHARGED_MOVELIST_280_0[] = { 60, 84, 66 };
pdex_mon_t DEXMON_280_0 = {
  .dex_number = 280,
  .name = "RALTS",
  .form_name = "BASE",
  .family = 280,
  .types = FAIRY_M | PSYCHIC_M,
  .base_stats = { .stamina = 99, .attack = 79, .defense = 59 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_280_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_280_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_281_0[] = { 235, 249 };
uint16_t CHARGED_MOVELIST_281_0[] = { 108, 84, 66 };
pdex_mon_t DEXMON_281_0 = {
  .dex_number = 281,
  .name = "KIRLIA",
  .form_name = "BASE",
  .family = 280,
  .types = FAIRY_M | PSYCHIC_M,
  .base_stats = { .stamina = 116, .attack = 117, .defense = 90 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_281_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_281_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_282_0[] = { 235, 249, 320 };
uint16_t CHARGED_MOVELIST_282_0[] = { 108, 86, 70, -324 };
pdex_mon_t DEXMON_282_0 = {
  .dex_number = 282,
  .name = "GARDEVOIR",
  .form_name = "BASE",
  .family = 280,
  .types = FAIRY_M | PSYCHIC_M,
  .base_stats = { .stamina = 169, .attack = 237, .defense = 195 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_282_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_282_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_283_0[] = { 237, 201 };
uint16_t CHARGED_MOVELIST_283_0[] = { 57, 53, 99 };
pdex_mon_t DEXMON_283_0 = {
  .dex_number = 283,
  .name = "SURSKIT",
  .form_name = "BASE",
  .family = 283,
  .types = BUG_M | WATER_M,
  .base_stats = { .stamina = 120, .attack = 93, .defense = 87 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_283_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_283_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_284_0[] = { 260, 255 };
uint16_t CHARGED_MOVELIST_284_0[] = { 121, 69, 262, 53 };
pdex_mon_t DEXMON_284_0 = {
  .dex_number = 284,
  .name = "MASQUERAIN",
  .form_name = "BASE",
  .family = 283,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 172, .attack = 192, .defense = 150 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_284_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_284_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_285_0[] = { 221, 271 };
uint16_t CHARGED_MOVELIST_285_0[] = { 59, 272, 273 };
pdex_mon_t DEXMON_285_0 = {
  .dex_number = 285,
  .name = "SHROOMISH",
  .form_name = "BASE",
  .family = 285,
  .types = GRASS_M,
  .base_stats = { .stamina = 155, .attack = 74, .defense = 110 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_285_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_285_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_286_0[] = { 243, 271 };
uint16_t CHARGED_MOVELIST_286_0[] = { 246, 59, 90, -272 };
pdex_mon_t DEXMON_286_0 = {
  .dex_number = 286,
  .name = "BRELOOM",
  .form_name = "BASE",
  .family = 285,
  .types = FIGHTING_M | GRASS_M,
  .base_stats = { .stamina = 155, .attack = 241, .defense = 144 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_286_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_286_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_287_0[] = { 287 };
uint16_t CHARGED_MOVELIST_287_0[] = { 131, 51, 123 };
pdex_mon_t DEXMON_287_0 = {
  .dex_number = 287,
  .name = "SLAKOTH",
  .form_name = "BASE",
  .family = 287,
  .types = NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 104, .defense = 92 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_287_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_287_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_288_0[] = { 220, 243 };
uint16_t CHARGED_MOVELIST_288_0[] = { 131, 95, 123 };
pdex_mon_t DEXMON_288_0 = {
  .dex_number = 288,
  .name = "VIGOROTH",
  .form_name = "BASE",
  .family = 287,
  .types = NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 159, .defense = 145 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_288_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_288_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_289_0[] = { 287 };
uint16_t CHARGED_MOVELIST_289_0[] = { 14, 88, 31, -131 };
pdex_mon_t DEXMON_289_0 = {
  .dex_number = 289,
  .name = "SLAKING",
  .form_name = "BASE",
  .family = 287,
  .types = NORMAL_M,
  .base_stats = { .stamina = 284, .attack = 290, .defense = 166 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_289_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_289_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_290_0[] = { 220, 201 };
uint16_t CHARGED_MOVELIST_290_0[] = { 51, 49, 45 };
pdex_mon_t DEXMON_290_0 = {
  .dex_number = 290,
  .name = "NINCADA",
  .form_name = "BASE",
  .family = 290,
  .types = BUG_M | GROUND_M,
  .base_stats = { .stamina = 104, .attack = 80, .defense = 126 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_290_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_290_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_291_0[] = { 200, 228 };
uint16_t CHARGED_MOVELIST_291_0[] = { 70, 49, 45 };
pdex_mon_t DEXMON_291_0 = {
  .dex_number = 291,
  .name = "NINJASK",
  .form_name = "BASE",
  .family = 290,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 156, .attack = 199, .defense = 112 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_291_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_291_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_292_0[] = { 201, 213, -261 };
uint16_t CHARGED_MOVELIST_292_0[] = { 66, 45, 26 };
pdex_mon_t DEXMON_292_0 = {
  .dex_number = 292,
  .name = "SHEDINJA",
  .form_name = "BASE",
  .family = 290,
  .types = BUG_M | GHOST_M,
  .base_stats = { .stamina = 1, .attack = 153, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_292_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_292_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_293_0[] = { 222, 263 };
uint16_t CHARGED_MOVELIST_293_0[] = { 127, 84, 24 };
pdex_mon_t DEXMON_293_0 = {
  .dex_number = 293,
  .name = "WHISMUR",
  .form_name = "BASE",
  .family = 293,
  .types = NORMAL_M,
  .base_stats = { .stamina = 162, .attack = 92, .defense = 42 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_293_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_293_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_294_0[] = { 202, 241 };
uint16_t CHARGED_MOVELIST_294_0[] = { 127, 84, 24 };
pdex_mon_t DEXMON_294_0 = {
  .dex_number = 294,
  .name = "LOUDRED",
  .form_name = "BASE",
  .family = 293,
  .types = NORMAL_M,
  .base_stats = { .stamina = 197, .attack = 134, .defense = 81 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_294_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_294_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_295_0[] = { 202, 263 };
uint16_t CHARGED_MOVELIST_295_0[] = { 279, 84, 103 };
pdex_mon_t DEXMON_295_0 = {
  .dex_number = 295,
  .name = "EXPLOUD",
  .form_name = "BASE",
  .family = 293,
  .types = NORMAL_M,
  .base_stats = { .stamina = 232, .attack = 179, .defense = 137 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_295_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_295_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_296_0[] = { 241, 221 };
uint16_t CHARGED_MOVELIST_296_0[] = { 268, 56, 28 };
pdex_mon_t DEXMON_296_0 = {
  .dex_number = 296,
  .name = "MAKUHITA",
  .form_name = "BASE",
  .family = 296,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 176, .attack = 99, .defense = 54 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_296_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_296_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_297_0[] = { 243, 229 };
uint16_t CHARGED_MOVELIST_297_0[] = { 268, 245, 246, 310 };
pdex_mon_t DEXMON_297_0 = {
  .dex_number = 297,
  .name = "HARIYAMA",
  .form_name = "BASE",
  .family = 296,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 302, .attack = 209, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_297_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_297_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_298_0[] = { 231, 237 };
uint16_t CHARGED_MOVELIST_298_0[] = { 53, 39, 131 };
pdex_mon_t DEXMON_298_0 = {
  .dex_number = 298,
  .name = "AZURILL",
  .form_name = "BASE",
  .family = 183,
  .types = FAIRY_M | NORMAL_M,
  .base_stats = { .stamina = 137, .attack = 36, .defense = 71 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_298_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_298_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_299_0[] = { 227, 206 };
uint16_t CHARGED_MOVELIST_299_0[] = { 259, 64, 79 };
pdex_mon_t DEXMON_299_0 = {
  .dex_number = 299,
  .name = "NOSEPASS",
  .form_name = "BASE",
  .family = 299,
  .types = ROCK_M,
  .base_stats = { .stamina = 102, .attack = 82, .defense = 215 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_299_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_299_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_300_0[] = { 238, 221 };
uint16_t CHARGED_MOVELIST_300_0[] = { 26, 84, 251 };
pdex_mon_t DEXMON_300_0 = {
  .dex_number = 300,
  .name = "SKITTY",
  .form_name = "BASE",
  .family = 300,
  .types = NORMAL_M,
  .base_stats = { .stamina = 137, .attack = 84, .defense = 79 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_300_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_300_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_301_0[] = { 238, 234, 320 };
uint16_t CHARGED_MOVELIST_301_0[] = { 88, 84, 251 };
pdex_mon_t DEXMON_301_0 = {
  .dex_number = 301,
  .name = "DELCATTY",
  .form_name = "BASE",
  .family = 300,
  .types = NORMAL_M,
  .base_stats = { .stamina = 172, .attack = 132, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_301_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_301_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_302_0[] = { 213, 238 };
uint16_t CHARGED_MOVELIST_302_0[] = { 65, 280, 66 };
pdex_mon_t DEXMON_302_0 = {
  .dex_number = 302,
  .name = "SABLEYE",
  .form_name = "BASE",
  .family = 302,
  .types = DARK_M | GHOST_M,
  .base_stats = { .stamina = 137, .attack = 141, .defense = 136 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_302_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_302_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_303_0[] = { 202, 263, 327, 240 };
uint16_t CHARGED_MOVELIST_303_0[] = { 88, 20, 74, 319 };
pdex_mon_t DEXMON_303_0 = {
  .dex_number = 303,
  .name = "MAWILE",
  .form_name = "BASE",
  .family = 303,
  .types = FAIRY_M | STEEL_M,
  .base_stats = { .stamina = 137, .attack = 155, .defense = 141 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_303_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_303_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_304_0[] = { 221, 228 };
uint16_t CHARGED_MOVELIST_304_0[] = { 74, 63, 131 };
pdex_mon_t DEXMON_304_0 = {
  .dex_number = 304,
  .name = "ARON",
  .form_name = "BASE",
  .family = 304,
  .types = ROCK_M | STEEL_M,
  .base_stats = { .stamina = 137, .attack = 121, .defense = 141 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_304_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_304_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_305_0[] = { 228, 266 };
uint16_t CHARGED_MOVELIST_305_0[] = { 131, 64, 268 };
pdex_mon_t DEXMON_305_0 = {
  .dex_number = 305,
  .name = "LAIRON",
  .form_name = "BASE",
  .family = 304,
  .types = ROCK_M | STEEL_M,
  .base_stats = { .stamina = 155, .attack = 158, .defense = 198 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_305_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_305_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_306_0[] = { 253, 266, 297 };
uint16_t CHARGED_MOVELIST_306_0[] = { 78, 32, 268 };
pdex_mon_t DEXMON_306_0 = {
  .dex_number = 306,
  .name = "AGGRON",
  .form_name = "BASE",
  .family = 304,
  .types = ROCK_M | STEEL_M,
  .base_stats = { .stamina = 172, .attack = 198, .defense = 257 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_306_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_306_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_307_0[] = { 235, 241 };
uint16_t CHARGED_MOVELIST_307_0[] = { 33, 60, 56 };
pdex_mon_t DEXMON_307_0 = {
  .dex_number = 307,
  .name = "MEDITITE",
  .form_name = "BASE",
  .family = 307,
  .types = FIGHTING_M | PSYCHIC_M,
  .base_stats = { .stamina = 102, .attack = 78, .defense = 107 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_307_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_307_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_308_0[] = { 226, 243 };
uint16_t CHARGED_MOVELIST_308_0[] = { 33, 108, 246, 319 };
pdex_mon_t DEXMON_308_0 = {
  .dex_number = 308,
  .name = "MEDICHAM",
  .form_name = "BASE",
  .family = 307,
  .types = FIGHTING_M | PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 121, .defense = 152 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_308_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_308_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_309_0[] = { 219, 206 };
uint16_t CHARGED_MOVELIST_309_0[] = { 79, 35, 125 };
pdex_mon_t DEXMON_309_0 = {
  .dex_number = 309,
  .name = "ELECTRIKE",
  .form_name = "BASE",
  .family = 309,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 120, .attack = 123, .defense = 78 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_309_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_309_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_310_0[] = { 278, 249 };
uint16_t CHARGED_MOVELIST_310_0[] = { 78, 251, 102 };
pdex_mon_t DEXMON_310_0 = {
  .dex_number = 310,
  .name = "MANECTRIC",
  .form_name = "BASE",
  .family = 309,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 172, .attack = 215, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_310_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_310_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_311_0[] = { 206, 219 };
uint16_t CHARGED_MOVELIST_311_0[] = { 79, 35, 125, 272 };
pdex_mon_t DEXMON_311_0 = {
  .dex_number = 311,
  .name = "PLUSLE",
  .form_name = "BASE",
  .family = 311,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 155, .attack = 167, .defense = 129 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_311_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_311_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_312_0[] = { 206, 219 };
uint16_t CHARGED_MOVELIST_312_0[] = { 79, 35, 125, 272 };
pdex_mon_t DEXMON_312_0 = {
  .dex_number = 312,
  .name = "MINUN",
  .form_name = "BASE",
  .family = 312,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 155, .attack = 147, .defense = 150 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_312_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_312_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_313_0[] = { 261, 221 };
uint16_t CHARGED_MOVELIST_313_0[] = { 99, 49, 79 };
pdex_mon_t DEXMON_313_0 = {
  .dex_number = 313,
  .name = "VOLBEAT",
  .form_name = "BASE",
  .family = 313,
  .types = BUG_M,
  .base_stats = { .stamina = 163, .attack = 143, .defense = 166 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_313_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_313_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_314_0[] = { 261, 221 };
uint16_t CHARGED_MOVELIST_314_0[] = { 262, 49, 86 };
pdex_mon_t DEXMON_314_0 = {
  .dex_number = 314,
  .name = "ILLUMISE",
  .form_name = "BASE",
  .family = 314,
  .types = BUG_M,
  .base_stats = { .stamina = 163, .attack = 143, .defense = 166 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_314_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_314_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_315_0[] = { 224, 215 };
uint16_t CHARGED_MOVELIST_315_0[] = { 47, 90, 86 };
pdex_mon_t DEXMON_315_0 = {
  .dex_number = 315,
  .name = "ROSELIA",
  .form_name = "BASE",
  .family = 315,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 137, .attack = 186, .defense = 131 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_315_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_315_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_316_0[] = { 222, 241 };
uint16_t CHARGED_MOVELIST_316_0[] = { 18, 92, 39 };
pdex_mon_t DEXMON_316_0 = {
  .dex_number = 316,
  .name = "GULPIN",
  .form_name = "BASE",
  .family = 316,
  .types = POISON_M,
  .base_stats = { .stamina = 172, .attack = 80, .defense = 99 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_316_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_316_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_317_0[] = { 241, 260 };
uint16_t CHARGED_MOVELIST_317_0[] = { 92, 90, 39, 303 };
pdex_mon_t DEXMON_317_0 = {
  .dex_number = 317,
  .name = "SWALOT",
  .form_name = "BASE",
  .family = 316,
  .types = POISON_M,
  .base_stats = { .stamina = 225, .attack = 140, .defense = 159 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_317_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_317_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_318_0[] = { 202, 278 };
uint16_t CHARGED_MOVELIST_318_0[] = { 57, 279, 50 };
pdex_mon_t DEXMON_318_0 = {
  .dex_number = 318,
  .name = "CARVANHA",
  .form_name = "BASE",
  .family = 318,
  .types = DARK_M | WATER_M,
  .base_stats = { .stamina = 128, .attack = 171, .defense = 39 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_318_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_318_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_319_0[] = { 202, 283 };
uint16_t CHARGED_MOVELIST_319_0[] = { 107, 279, 50 };
pdex_mon_t DEXMON_319_0 = {
  .dex_number = 319,
  .name = "SHARPEDO",
  .form_name = "BASE",
  .family = 318,
  .types = DARK_M | WATER_M,
  .base_stats = { .stamina = 172, .attack = 243, .defense = 83 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_319_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_319_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_320_0[] = { 231, 230 };
uint16_t CHARGED_MOVELIST_320_0[] = { 268, 105, 131 };
pdex_mon_t DEXMON_320_0 = {
  .dex_number = 320,
  .name = "WAILMER",
  .form_name = "BASE",
  .family = 320,
  .types = WATER_M,
  .base_stats = { .stamina = 277, .attack = 136, .defense = 68 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_320_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_320_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_321_0[] = { 234, 230 };
uint16_t CHARGED_MOVELIST_321_0[] = { 284, 40, 14 };
pdex_mon_t DEXMON_321_0 = {
  .dex_number = 321,
  .name = "WAILORD",
  .form_name = "BASE",
  .family = 320,
  .types = WATER_M,
  .base_stats = { .stamina = 347, .attack = 175, .defense = 87 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_321_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_321_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_322_0[] = { 209, 221 };
uint16_t CHARGED_MOVELIST_322_0[] = { 95, 42, 127 };
pdex_mon_t DEXMON_322_0 = {
  .dex_number = 322,
  .name = "NUMEL",
  .form_name = "BASE",
  .family = 322,
  .types = FIRE_M | GROUND_M,
  .base_stats = { .stamina = 155, .attack = 119, .defense = 79 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_322_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_322_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_323_0[] = { 209, 241 };
uint16_t CHARGED_MOVELIST_323_0[] = { 31, 270, 116, 304 };
pdex_mon_t DEXMON_323_0 = {
  .dex_number = 323,
  .name = "CAMERUPT",
  .form_name = "BASE",
  .family = 322,
  .types = FIRE_M | GROUND_M,
  .base_stats = { .stamina = 172, .attack = 194, .defense = 136 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_323_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_323_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_324_0[] = { 269, 209 };
uint16_t CHARGED_MOVELIST_324_0[] = { 270, 116, 31 };
pdex_mon_t DEXMON_324_0 = {
  .dex_number = 324,
  .name = "TORKOAL",
  .form_name = "BASE",
  .family = 324,
  .types = FIRE_M,
  .base_stats = { .stamina = 172, .attack = 151, .defense = 203 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_324_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_324_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_325_0[] = { 231, 234 };
uint16_t CHARGED_MOVELIST_325_0[] = { 30, 70, 276 };
pdex_mon_t DEXMON_325_0 = {
  .dex_number = 325,
  .name = "SPOINK",
  .form_name = "BASE",
  .family = 325,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 125, .defense = 122 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_325_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_325_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_326_0[] = { 249, 274 };
uint16_t CHARGED_MOVELIST_326_0[] = { 108, 70, 276 };
pdex_mon_t DEXMON_326_0 = {
  .dex_number = 326,
  .name = "GRUMPIG",
  .form_name = "BASE",
  .family = 325,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 190, .attack = 171, .defense = 188 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_326_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_326_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_327_0[] = { 203, 226 };
uint16_t CHARGED_MOVELIST_327_0[] = { 26, 63, 111 };
pdex_mon_t DEXMON_327_0 = {
  .dex_number = 327,
  .name = "SPINDA",
  .form_name = "BASE",
  .family = 327,
  .types = NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 116, .defense = 116 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_327_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_327_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_328_0[] = { 216, 261 };
uint16_t CHARGED_MOVELIST_328_0[] = { 258, 26, 279 };
pdex_mon_t DEXMON_328_0 = {
  .dex_number = 328,
  .name = "TRAPINCH",
  .form_name = "BASE",
  .family = 328,
  .types = GROUND_M,
  .base_stats = { .stamina = 128, .attack = 162, .defense = 78 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_328_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_328_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_329_0[] = { 216, 204 };
uint16_t CHARGED_MOVELIST_329_0[] = { 258, 95, 49 };
pdex_mon_t DEXMON_329_0 = {
  .dex_number = 329,
  .name = "VIBRAVA",
  .form_name = "BASE",
  .family = 328,
  .types = DRAGON_M | GROUND_M,
  .base_stats = { .stamina = 137, .attack = 134, .defense = 99 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_329_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_329_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_330_0[] = { 216, 253 };
uint16_t CHARGED_MOVELIST_330_0[] = { 31, 83, 32, -304 };
pdex_mon_t DEXMON_330_0 = {
  .dex_number = 330,
  .name = "FLYGON",
  .form_name = "BASE",
  .family = 328,
  .types = DRAGON_M | GROUND_M,
  .base_stats = { .stamina = 190, .attack = 205, .defense = 168 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_330_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_330_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_331_0[] = { 236, 203 };
uint16_t CHARGED_MOVELIST_331_0[] = { 272, 123, 59 };
pdex_mon_t DEXMON_331_0 = {
  .dex_number = 331,
  .name = "CACNEA",
  .form_name = "BASE",
  .family = 331,
  .types = GRASS_M,
  .base_stats = { .stamina = 137, .attack = 156, .defense = 74 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_331_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_331_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_332_0[] = { 224, 203 };
uint16_t CHARGED_MOVELIST_332_0[] = { 16, 246, 272 };
pdex_mon_t DEXMON_332_0 = {
  .dex_number = 332,
  .name = "CACTURNE",
  .form_name = "BASE",
  .family = 331,
  .types = DARK_M | GRASS_M,
  .base_stats = { .stamina = 172, .attack = 221, .defense = 115 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_332_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_332_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_333_0[] = { 211, 263 };
uint16_t CHARGED_MOVELIST_333_0[] = { 84, 45, 39 };
pdex_mon_t DEXMON_333_0 = {
  .dex_number = 333,
  .name = "SWABLU",
  .form_name = "BASE",
  .family = 333,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 128, .attack = 76, .defense = 132 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_333_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_333_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_334_0[] = { 211, 204 };
uint16_t CHARGED_MOVELIST_334_0[] = { 257, 86, 82 };
pdex_mon_t DEXMON_334_0 = {
  .dex_number = 334,
  .name = "ALTARIA",
  .form_name = "BASE",
  .family = 333,
  .types = DRAGON_M | FLYING_M,
  .base_stats = { .stamina = 181, .attack = 141, .defense = 201 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_334_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_334_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_335_0[] = { 200, 213 };
uint16_t CHARGED_MOVELIST_335_0[] = { 245, 51, 26 };
pdex_mon_t DEXMON_335_0 = {
  .dex_number = 335,
  .name = "ZANGOOSE",
  .form_name = "BASE",
  .family = 335,
  .types = NORMAL_M,
  .base_stats = { .stamina = 177, .attack = 222, .defense = 124 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_335_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_335_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_336_0[] = { 224, 266 };
uint16_t CHARGED_MOVELIST_336_0[] = { 50, 279, 13 };
pdex_mon_t DEXMON_336_0 = {
  .dex_number = 336,
  .name = "SEVIPER",
  .form_name = "BASE",
  .family = 336,
  .types = POISON_M,
  .base_stats = { .stamina = 177, .attack = 196, .defense = 118 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_336_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_336_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_337_0[] = { 227, 235 };
uint16_t CHARGED_MOVELIST_337_0[] = { 108, 64, 87 };
pdex_mon_t DEXMON_337_0 = {
  .dex_number = 337,
  .name = "LUNATONE",
  .form_name = "BASE",
  .family = 337,
  .types = PSYCHIC_M | ROCK_M,
  .base_stats = { .stamina = 207, .attack = 178, .defense = 153 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_337_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_337_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_338_0[] = { 227, 235 };
uint16_t CHARGED_MOVELIST_338_0[] = { 108, 64, 116 };
pdex_mon_t DEXMON_338_0 = {
  .dex_number = 338,
  .name = "SOLROCK",
  .form_name = "BASE",
  .family = 338,
  .types = PSYCHIC_M | ROCK_M,
  .base_stats = { .stamina = 207, .attack = 178, .defense = 153 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_338_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_338_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_339_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_339_0[] = { 58, 39, 96 };
pdex_mon_t DEXMON_339_0 = {
  .dex_number = 339,
  .name = "BARBOACH",
  .form_name = "BASE",
  .family = 339,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 137, .attack = 93, .defense = 82 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_339_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_339_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_340_0[] = { 230, 216 };
uint16_t CHARGED_MOVELIST_340_0[] = { 105, 40, 96 };
pdex_mon_t DEXMON_340_0 = {
  .dex_number = 340,
  .name = "WHISCASH",
  .form_name = "BASE",
  .family = 339,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 242, .attack = 151, .defense = 141 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_340_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_340_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_341_0[] = { 237, 241 };
uint16_t CHARGED_MOVELIST_341_0[] = { 20, 53, 57 };
pdex_mon_t DEXMON_341_0 = {
  .dex_number = 341,
  .name = "CORPHISH",
  .form_name = "BASE",
  .family = 341,
  .types = WATER_M,
  .base_stats = { .stamina = 125, .attack = 141, .defense = 99 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_341_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_341_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_342_0[] = { 283, 278 };
uint16_t CHARGED_MOVELIST_342_0[] = { 20, 53, 51, 305 };
pdex_mon_t DEXMON_342_0 = {
  .dex_number = 342,
  .name = "CRAWDAUNT",
  .form_name = "BASE",
  .family = 341,
  .types = DARK_M | WATER_M,
  .base_stats = { .stamina = 160, .attack = 224, .defense = 142 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_342_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_342_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_343_0[] = { 235, 274 };
uint16_t CHARGED_MOVELIST_343_0[] = { 267, 30, 26 };
pdex_mon_t DEXMON_343_0 = {
  .dex_number = 343,
  .name = "BALTOY",
  .form_name = "BASE",
  .family = 343,
  .types = GROUND_M | PSYCHIC_M,
  .base_stats = { .stamina = 120, .attack = 77, .defense = 124 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_343_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_343_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_344_0[] = { 274, 235, 233 };
uint16_t CHARGED_MOVELIST_344_0[] = { 267, 108, 31, 304 };
pdex_mon_t DEXMON_344_0 = {
  .dex_number = 344,
  .name = "CLAYDOL",
  .form_name = "BASE",
  .family = 343,
  .types = GROUND_M | PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 140, .defense = 229 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_344_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_344_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_345_0[] = { 225, 260 };
uint16_t CHARGED_MOVELIST_345_0[] = { 272, 276, 62 };
pdex_mon_t DEXMON_345_0 = {
  .dex_number = 345,
  .name = "LILEEP",
  .form_name = "BASE",
  .family = 345,
  .types = GRASS_M | ROCK_M,
  .base_stats = { .stamina = 165, .attack = 105, .defense = 150 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_345_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_345_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_346_0[] = { 225, 260, 271 };
uint16_t CHARGED_MOVELIST_346_0[] = { 272, 95, 32 };
pdex_mon_t DEXMON_346_0 = {
  .dex_number = 346,
  .name = "CRADILY",
  .form_name = "BASE",
  .family = 345,
  .types = GRASS_M | ROCK_M,
  .base_stats = { .stamina = 200, .attack = 152, .defense = 194 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_346_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_346_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_347_0[] = { 261, 220 };
uint16_t CHARGED_MOVELIST_347_0[] = { 89, 57, 62 };
pdex_mon_t DEXMON_347_0 = {
  .dex_number = 347,
  .name = "ANORITH",
  .form_name = "BASE",
  .family = 347,
  .types = BUG_M | ROCK_M,
  .base_stats = { .stamina = 128, .attack = 176, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_347_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_347_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_348_0[] = { 200, 261 };
uint16_t CHARGED_MOVELIST_348_0[] = { 89, 105, 259 };
pdex_mon_t DEXMON_348_0 = {
  .dex_number = 348,
  .name = "ARMALDO",
  .form_name = "BASE",
  .family = 347,
  .types = BUG_M | ROCK_M,
  .base_stats = { .stamina = 181, .attack = 222, .defense = 174 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_348_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_348_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_349_0[] = { 231, 221 };
uint16_t CHARGED_MOVELIST_349_0[] = { 276 };
pdex_mon_t DEXMON_349_0 = {
  .dex_number = 349,
  .name = "FEEBAS",
  .form_name = "BASE",
  .family = 349,
  .types = WATER_M,
  .base_stats = { .stamina = 85, .attack = 29, .defense = 85 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_349_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_349_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_350_0[] = { 283, 253 };
uint16_t CHARGED_MOVELIST_350_0[] = { 284, 40, 14 };
pdex_mon_t DEXMON_350_0 = {
  .dex_number = 350,
  .name = "MILOTIC",
  .form_name = "BASE",
  .family = 349,
  .types = WATER_M,
  .base_stats = { .stamina = 216, .attack = 192, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_350_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_350_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_351_0[] = { 221, 264 };
uint16_t CHARGED_MOVELIST_351_0[] = { 122, 273 };
uint16_t FAST_MOVELIST_351_1[] = { 230, 221 };
uint16_t CHARGED_MOVELIST_351_1[] = { 107, 78, 295 };
uint16_t FAST_MOVELIST_351_2[] = { 244, 221 };
uint16_t CHARGED_MOVELIST_351_2[] = { 40, 39, 293 };
uint16_t FAST_MOVELIST_351_3[] = { 209, 221 };
uint16_t CHARGED_MOVELIST_351_3[] = { 103, 116, 292 };
pdex_mon_t DEXMON_351_3 = {
  .dex_number = 351,
  .name = "CASTFORM",
  .form_name = "SUNNY",
  .family = 351,
  .types = FIRE_M,
  .base_stats = { .stamina = 172, .attack = 139, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_351_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_351_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = NULL
};
pdex_mon_t DEXMON_351_2 = {
  .dex_number = 351,
  .name = "CASTFORM",
  .form_name = "SNOWY",
  .family = 351,
  .types = ICE_M,
  .base_stats = { .stamina = 172, .attack = 139, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_351_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_351_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_351_3
};
pdex_mon_t DEXMON_351_1 = {
  .dex_number = 351,
  .name = "CASTFORM",
  .form_name = "RAINY",
  .family = 351,
  .types = WATER_M,
  .base_stats = { .stamina = 172, .attack = 139, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_351_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_351_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_351_2
};
pdex_mon_t DEXMON_351_0 = {
  .dex_number = 351,
  .name = "CASTFORM",
  .form_name = "BASE",
  .family = 351,
  .types = NORMAL_M,
  .base_stats = { .stamina = 172, .attack = 139, .defense = 139 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_351_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_351_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = & DEXMON_351_1
};
uint16_t FAST_MOVELIST_352_0[] = { 212, 203 };
uint16_t CHARGED_MOVELIST_352_0[] = { 280, 24, 78, 39, 45, 66 };
pdex_mon_t DEXMON_352_0 = {
  .dex_number = 352,
  .name = "KECLEON",
  .form_name = "BASE",
  .family = 352,
  .types = NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 161, .defense = 189 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_352_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_352_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_353_0[] = { 238, 263 };
uint16_t CHARGED_MOVELIST_353_0[] = { 69, 265, 66 };
pdex_mon_t DEXMON_353_0 = {
  .dex_number = 353,
  .name = "SHUPPET",
  .form_name = "BASE",
  .family = 353,
  .types = GHOST_M,
  .base_stats = { .stamina = 127, .attack = 138, .defense = 65 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_353_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_353_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_354_0[] = { 264, 213 };
uint16_t CHARGED_MOVELIST_354_0[] = { 70, 86, 78 };
pdex_mon_t DEXMON_354_0 = {
  .dex_number = 354,
  .name = "BANETTE",
  .form_name = "BASE",
  .family = 353,
  .types = GHOST_M,
  .base_stats = { .stamina = 162, .attack = 218, .defense = 126 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_354_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_354_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_355_0[] = { 264, 263 };
uint16_t CHARGED_MOVELIST_355_0[] = { 69, 265, 66 };
pdex_mon_t DEXMON_355_0 = {
  .dex_number = 355,
  .name = "DUSKULL",
  .form_name = "BASE",
  .family = 355,
  .types = GHOST_M,
  .base_stats = { .stamina = 85, .attack = 70, .defense = 162 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_355_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_355_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_356_0[] = { 264, 238 };
uint16_t CHARGED_MOVELIST_356_0[] = { 67, 33, 115 };
pdex_mon_t DEXMON_356_0 = {
  .dex_number = 356,
  .name = "DUSCLOPS",
  .form_name = "BASE",
  .family = 355,
  .types = GHOST_M,
  .base_stats = { .stamina = 120, .attack = 124, .defense = 234 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_356_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_356_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_357_0[] = { 255, 215 };
uint16_t CHARGED_MOVELIST_357_0[] = { 127, 45, 117 };
pdex_mon_t DEXMON_357_0 = {
  .dex_number = 357,
  .name = "TROPIUS",
  .form_name = "BASE",
  .family = 357,
  .types = FLYING_M | GRASS_M,
  .base_stats = { .stamina = 223, .attack = 136, .defense = 163 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_357_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_357_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_358_0[] = { 274, 263 };
uint16_t CHARGED_MOVELIST_358_0[] = { 273, 70, 60, 60 };
pdex_mon_t DEXMON_358_0 = {
  .dex_number = 358,
  .name = "CHIMECHO",
  .form_name = "BASE",
  .family = 358,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 181, .attack = 175, .defense = 170 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_358_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_358_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_359_0[] = { 226, 278 };
uint16_t CHARGED_MOVELIST_359_0[] = { 16, 78, 22 };
pdex_mon_t DEXMON_359_0 = {
  .dex_number = 359,
  .name = "ABSOL",
  .form_name = "BASE",
  .family = 359,
  .types = DARK_M,
  .base_stats = { .stamina = 163, .attack = 246, .defense = 120 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_359_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_359_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_360_0[] = { 231, 243 };
uint16_t CHARGED_MOVELIST_360_0[] = { 276 };
pdex_mon_t DEXMON_360_0 = {
  .dex_number = 360,
  .name = "WYNAUT",
  .form_name = "BASE",
  .family = 202,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 216, .attack = 41, .defense = 86 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_360_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_360_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_361_0[] = { 244, 264 };
uint16_t CHARGED_MOVELIST_361_0[] = { 254, 111, 70 };
pdex_mon_t DEXMON_361_0 = {
  .dex_number = 361,
  .name = "SNORUNT",
  .form_name = "BASE",
  .family = 361,
  .types = ICE_M,
  .base_stats = { .stamina = 137, .attack = 95, .defense = 95 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_361_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_361_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_362_0[] = { 217, 218 };
uint16_t CHARGED_MOVELIST_362_0[] = { 254, 267, 70 };
pdex_mon_t DEXMON_362_0 = {
  .dex_number = 362,
  .name = "GLALIE",
  .form_name = "BASE",
  .family = 361,
  .types = ICE_M,
  .base_stats = { .stamina = 190, .attack = 162, .defense = 162 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_362_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_362_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_363_0[] = { 230, 241 };
uint16_t CHARGED_MOVELIST_363_0[] = { 248, 131, 105 };
pdex_mon_t DEXMON_363_0 = {
  .dex_number = 363,
  .name = "SPHEAL",
  .form_name = "BASE",
  .family = 363,
  .types = ICE_M | WATER_M,
  .base_stats = { .stamina = 172, .attack = 95, .defense = 90 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_363_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_363_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_364_0[] = { 230, 244 };
uint16_t CHARGED_MOVELIST_364_0[] = { 248, 131, 105 };
pdex_mon_t DEXMON_364_0 = {
  .dex_number = 364,
  .name = "SEALEO",
  .form_name = "BASE",
  .family = 363,
  .types = ICE_M | WATER_M,
  .base_stats = { .stamina = 207, .attack = 137, .defense = 132 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_364_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_364_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_365_0[] = { 283, 218 };
uint16_t CHARGED_MOVELIST_365_0[] = { 40, 31, 105 };
pdex_mon_t DEXMON_365_0 = {
  .dex_number = 365,
  .name = "WALREIN",
  .form_name = "BASE",
  .family = 363,
  .types = ICE_M | WATER_M,
  .base_stats = { .stamina = 242, .attack = 182, .defense = 176 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_365_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_365_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_366_0[] = { 230 };
uint16_t CHARGED_MOVELIST_366_0[] = { 131, 39, 105 };
pdex_mon_t DEXMON_366_0 = {
  .dex_number = 366,
  .name = "CLAMPERL",
  .form_name = "BASE",
  .family = 366,
  .types = WATER_M,
  .base_stats = { .stamina = 111, .attack = 133, .defense = 135 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_366_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_366_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_367_0[] = { 230, 202 };
uint16_t CHARGED_MOVELIST_367_0[] = { 279, 39, 58 };
pdex_mon_t DEXMON_367_0 = {
  .dex_number = 367,
  .name = "HUNTAIL",
  .form_name = "BASE",
  .family = 366,
  .types = WATER_M,
  .base_stats = { .stamina = 146, .attack = 197, .defense = 179 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_367_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_367_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_368_0[] = { 230, 235 };
uint16_t CHARGED_MOVELIST_368_0[] = { 85, 108, 105 };
pdex_mon_t DEXMON_368_0 = {
  .dex_number = 368,
  .name = "GOREBYSS",
  .form_name = "BASE",
  .family = 366,
  .types = WATER_M,
  .base_stats = { .stamina = 146, .attack = 211, .defense = 179 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_368_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_368_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_369_0[] = { 230, 234 };
uint16_t CHARGED_MOVELIST_369_0[] = { 62, 58, 107 };
pdex_mon_t DEXMON_369_0 = {
  .dex_number = 369,
  .name = "RELICANTH",
  .form_name = "BASE",
  .family = 369,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 225, .attack = 162, .defense = 203 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_369_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_369_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_370_0[] = { 230, 231 };
uint16_t CHARGED_MOVELIST_370_0[] = { 85, 105, 57 };
pdex_mon_t DEXMON_370_0 = {
  .dex_number = 370,
  .name = "LUVDISC",
  .form_name = "BASE",
  .family = 370,
  .types = WATER_M,
  .base_stats = { .stamina = 125, .attack = 81, .defense = 128 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_370_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_370_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_371_0[] = { 202, 209 };
uint16_t CHARGED_MOVELIST_371_0[] = { 24, 80, 279 };
pdex_mon_t DEXMON_371_0 = {
  .dex_number = 371,
  .name = "BAGON",
  .form_name = "BASE",
  .family = 371,
  .types = DRAGON_M,
  .base_stats = { .stamina = 128, .attack = 134, .defense = 93 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_371_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_371_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_372_0[] = { 209, 204 };
uint16_t CHARGED_MOVELIST_372_0[] = { 24, 82, 80 };
pdex_mon_t DEXMON_372_0 = {
  .dex_number = 372,
  .name = "SHELGON",
  .form_name = "BASE",
  .family = 371,
  .types = DRAGON_M,
  .base_stats = { .stamina = 163, .attack = 172, .defense = 155 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_372_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_372_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_373_0[] = { 253, 240, 202 };
uint16_t CHARGED_MOVELIST_373_0[] = { 103, 107, 285, -277 };
pdex_mon_t DEXMON_373_0 = {
  .dex_number = 373,
  .name = "SALAMENCE",
  .form_name = "BASE",
  .family = 371,
  .types = DRAGON_M | FLYING_M,
  .base_stats = { .stamina = 216, .attack = 277, .defense = 168 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_373_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_373_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_374_0[] = { 282 };
uint16_t CHARGED_MOVELIST_374_0[] = { 133 };
pdex_mon_t DEXMON_374_0 = {
  .dex_number = 374,
  .name = "BELDUM",
  .form_name = "BASE",
  .family = 374,
  .types = PSYCHIC_M | STEEL_M,
  .base_stats = { .stamina = 120, .attack = 96, .defense = 132 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_374_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_374_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_375_0[] = { 234, 228 };
uint16_t CHARGED_MOVELIST_375_0[] = { 108, 267, 60 };
pdex_mon_t DEXMON_375_0 = {
  .dex_number = 375,
  .name = "METANG",
  .form_name = "BASE",
  .family = 374,
  .types = PSYCHIC_M | STEEL_M,
  .base_stats = { .stamina = 155, .attack = 138, .defense = 176 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_375_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_375_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_376_0[] = { 229, 234 };
uint16_t CHARGED_MOVELIST_376_0[] = { 108, 36, 31, -301 };
pdex_mon_t DEXMON_376_0 = {
  .dex_number = 376,
  .name = "METAGROSS",
  .form_name = "BASE",
  .family = 374,
  .types = PSYCHIC_M | STEEL_M,
  .base_stats = { .stamina = 190, .attack = 257, .defense = 228 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_376_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_376_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_377_0[] = { 227, 241, 325 };
uint16_t CHARGED_MOVELIST_377_0[] = { 32, 252, 247 };
pdex_mon_t DEXMON_377_0 = {
  .dex_number = 377,
  .name = "REGIROCK",
  .form_name = "BASE",
  .family = 377,
  .types = ROCK_M,
  .base_stats = { .stamina = 190, .attack = 179, .defense = 309 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_377_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_377_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_378_0[] = { 218, 241, 325 };
uint16_t CHARGED_MOVELIST_378_0[] = { 40, 31, 247 };
pdex_mon_t DEXMON_378_0 = {
  .dex_number = 378,
  .name = "REGICE",
  .form_name = "BASE",
  .family = 378,
  .types = ICE_M,
  .base_stats = { .stamina = 190, .attack = 179, .defense = 309 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_378_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_378_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_379_0[] = { 228, 241, 325 };
uint16_t CHARGED_MOVELIST_379_0[] = { 36, 14, 247 };
pdex_mon_t DEXMON_379_0 = {
  .dex_number = 379,
  .name = "REGISTEEL",
  .form_name = "BASE",
  .family = 379,
  .types = STEEL_M,
  .base_stats = { .stamina = 190, .attack = 143, .defense = 285 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_379_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_379_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_380_0[] = { 204, 234, 320 };
uint16_t CHARGED_MOVELIST_380_0[] = { 108, 277, 78 };
pdex_mon_t DEXMON_380_0 = {
  .dex_number = 380,
  .name = "LATIAS",
  .form_name = "BASE",
  .family = 380,
  .types = DRAGON_M | PSYCHIC_M,
  .base_stats = { .stamina = 190, .attack = 228, .defense = 246 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_380_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_380_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_381_0[] = { 204, 234 };
uint16_t CHARGED_MOVELIST_381_0[] = { 108, 83, 116 };
pdex_mon_t DEXMON_381_0 = {
  .dex_number = 381,
  .name = "LATIOS",
  .form_name = "BASE",
  .family = 381,
  .types = DRAGON_M | PSYCHIC_M,
  .base_stats = { .stamina = 190, .attack = 268, .defense = 212 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_381_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_381_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_382_0[] = { 283 };
uint16_t CHARGED_MOVELIST_382_0[] = { 107, 40, 78, 284 };
pdex_mon_t DEXMON_382_0 = {
  .dex_number = 382,
  .name = "KYOGRE",
  .form_name = "BASE",
  .family = 382,
  .types = WATER_M,
  .base_stats = { .stamina = 205, .attack = 270, .defense = 228 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_382_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_382_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_383_0[] = { 216, 253 };
uint16_t CHARGED_MOVELIST_383_0[] = { 31, 103, 116, -115 };
pdex_mon_t DEXMON_383_0 = {
  .dex_number = 383,
  .name = "GROUDON",
  .form_name = "BASE",
  .family = 383,
  .types = GROUND_M,
  .base_stats = { .stamina = 205, .attack = 270, .defense = 228 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_383_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_383_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_384_0[] = { 255, 253 };
uint16_t CHARGED_MOVELIST_384_0[] = { 277, 45, 62 };
pdex_mon_t DEXMON_384_0 = {
  .dex_number = 384,
  .name = "RAYQUAZA",
  .form_name = "BASE",
  .family = 384,
  .types = DRAGON_M | FLYING_M,
  .base_stats = { .stamina = 213, .attack = 284, .defense = 170 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_384_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_384_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_385_0[] = { 235, 249 };
uint16_t CHARGED_MOVELIST_385_0[] = { 86, 108, 286 };
pdex_mon_t DEXMON_385_0 = {
  .dex_number = 385,
  .name = "JIRACHI",
  .form_name = "BASE",
  .family = 385,
  .types = PSYCHIC_M | STEEL_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_385_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_385_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_386_0[] = { 234, 249 };
uint16_t CHARGED_MOVELIST_386_0[] = { 288, 252, 14 };
uint16_t FAST_MOVELIST_386_1[] = { 234, 224 };
uint16_t CHARGED_MOVELIST_386_1[] = { 288, 252, 16 };
uint16_t FAST_MOVELIST_386_2[] = { 234, 243 };
uint16_t CHARGED_MOVELIST_386_2[] = { 288, 79, 64 };
uint16_t FAST_MOVELIST_386_3[] = { 234, 249 };
uint16_t CHARGED_MOVELIST_386_3[] = { 288, 79, 125 };
pdex_mon_t DEXMON_386_3 = {
  .dex_number = 386,
  .name = "DEOXYS",
  .form_name = "SPEED",
  .family = 386,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 137, .attack = 230, .defense = 218 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_386_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_386_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = NULL
};
pdex_mon_t DEXMON_386_2 = {
  .dex_number = 386,
  .name = "DEOXYS",
  .form_name = "DEFENSE",
  .family = 386,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 137, .attack = 144, .defense = 330 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_386_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_386_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_386_3
};
pdex_mon_t DEXMON_386_1 = {
  .dex_number = 386,
  .name = "DEOXYS",
  .form_name = "ATTACK",
  .family = 386,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 137, .attack = 414, .defense = 46 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_386_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_386_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_386_2
};
pdex_mon_t DEXMON_386_0 = {
  .dex_number = 386,
  .name = "DEOXYS",
  .form_name = "BASE",
  .family = 386,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 137, .attack = 345, .defense = 115 },
  .tags = TAG_MYTHIC_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_386_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_386_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_386_1
};
uint16_t FAST_MOVELIST_387_0[] = { 221, 215 };
uint16_t CHARGED_MOVELIST_387_0[] = { 273, 59, 131 };
pdex_mon_t DEXMON_387_0 = {
  .dex_number = 387,
  .name = "TURTWIG",
  .form_name = "BASE",
  .family = 387,
  .types = GRASS_M,
  .base_stats = { .stamina = 146, .attack = 119, .defense = 110 },
  .tags = TAG_SHADOW_ELIGABLE_M | TAG_STARTER_M,
  .fast_move_ids = FAST_MOVELIST_387_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_387_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_388_0[] = { 202, 215 };
uint16_t CHARGED_MOVELIST_388_0[] = { 273, 116, 131 };
pdex_mon_t DEXMON_388_0 = {
  .dex_number = 388,
  .name = "GROTLE",
  .form_name = "BASE",
  .family = 387,
  .types = GRASS_M,
  .base_stats = { .stamina = 181, .attack = 157, .defense = 143 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_388_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_388_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_389_0[] = { 202, 215 };
uint16_t CHARGED_MOVELIST_389_0[] = { 32, 116, 31, 258, -296 };
pdex_mon_t DEXMON_389_0 = {
  .dex_number = 389,
  .name = "TORTERRA",
  .form_name = "BASE",
  .family = 387,
  .types = GRASS_M | GROUND_M,
  .base_stats = { .stamina = 216, .attack = 202, .defense = 188 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_389_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_389_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_390_0[] = { 209, 220 };
uint16_t CHARGED_MOVELIST_390_0[] = { 21, 24, 101 };
pdex_mon_t DEXMON_390_0 = {
  .dex_number = 390,
  .name = "CHIMCHAR",
  .form_name = "BASE",
  .family = 390,
  .types = FIRE_M,
  .base_stats = { .stamina = 127, .attack = 113, .defense = 86 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_390_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_390_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_391_0[] = { 209, 241 };
uint16_t CHARGED_MOVELIST_391_0[] = { 21, 24, 56 };
pdex_mon_t DEXMON_391_0 = {
  .dex_number = 391,
  .name = "MONFERNO",
  .form_name = "BASE",
  .family = 390,
  .types = FIGHTING_M | FIRE_M,
  .base_stats = { .stamina = 162, .attack = 158, .defense = 105 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_391_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_391_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_392_0[] = { 269, 241 };
uint16_t CHARGED_MOVELIST_392_0[] = { 116, 24, 245, -298 };
pdex_mon_t DEXMON_392_0 = {
  .dex_number = 392,
  .name = "INFERNAPE",
  .form_name = "BASE",
  .family = 390,
  .types = FIGHTING_M | FIRE_M,
  .base_stats = { .stamina = 183, .attack = 222, .defense = 151 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_392_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_392_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_393_0[] = { 237, 222 };
uint16_t CHARGED_MOVELIST_393_0[] = { 53, 38, 111 };
pdex_mon_t DEXMON_393_0 = {
  .dex_number = 393,
  .name = "PIPLUP",
  .form_name = "BASE",
  .family = 393,
  .types = WATER_M,
  .base_stats = { .stamina = 142, .attack = 112, .defense = 102 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_393_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_393_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_394_0[] = { 237, 228 };
uint16_t CHARGED_MOVELIST_394_0[] = { 53, 107, 111 };
pdex_mon_t DEXMON_394_0 = {
  .dex_number = 394,
  .name = "PRINPLUP",
  .form_name = "BASE",
  .family = 393,
  .types = WATER_M,
  .base_stats = { .stamina = 162, .attack = 150, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_394_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_394_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_395_0[] = { 283, 228 };
uint16_t CHARGED_MOVELIST_395_0[] = { 107, 40, 36, -299 };
pdex_mon_t DEXMON_395_0 = {
  .dex_number = 395,
  .name = "EMPOLEON",
  .form_name = "BASE",
  .family = 393,
  .types = STEEL_M | WATER_M,
  .base_stats = { .stamina = 197, .attack = 210, .defense = 186 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_395_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_395_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_396_0[] = { 221, 219 };
uint16_t CHARGED_MOVELIST_396_0[] = { 45, 256 };
pdex_mon_t DEXMON_396_0 = {
  .dex_number = 396,
  .name = "STARLY",
  .form_name = "BASE",
  .family = 396,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 120, .attack = 101, .defense = 58 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_396_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_396_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_397_0[] = { 210, 219 };
uint16_t CHARGED_MOVELIST_397_0[] = { 45, 256, 42 };
pdex_mon_t DEXMON_397_0 = {
  .dex_number = 397,
  .name = "STARAVIA",
  .form_name = "BASE",
  .family = 396,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 142, .defense = 94 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_397_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_397_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_398_0[] = { 210, 219 };
uint16_t CHARGED_MOVELIST_398_0[] = { 256, 42, 245 };
pdex_mon_t DEXMON_398_0 = {
  .dex_number = 398,
  .name = "STARAPTOR",
  .form_name = "BASE",
  .family = 396,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 198, .attack = 234, .defense = 140 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_398_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_398_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_399_0[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_399_0[] = { 129, 279, 272 };
pdex_mon_t DEXMON_399_0 = {
  .dex_number = 399,
  .name = "BIDOOF",
  .form_name = "BASE",
  .family = 399,
  .types = NORMAL_M,
  .base_stats = { .stamina = 153, .attack = 80, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_399_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_399_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_400_0[] = { 230, 282 };
uint16_t CHARGED_MOVELIST_400_0[] = { 129, 14, 284 };
pdex_mon_t DEXMON_400_0 = {
  .dex_number = 400,
  .name = "BIBAREL",
  .form_name = "BASE",
  .family = 399,
  .types = NORMAL_M | WATER_M,
  .base_stats = { .stamina = 188, .attack = 162, .defense = 119 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_400_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_400_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_401_0[] = { 261, 201 };
uint16_t CHARGED_MOVELIST_401_0[] = { 133 };
pdex_mon_t DEXMON_401_0 = {
  .dex_number = 401,
  .name = "KRICKETOT",
  .form_name = "BASE",
  .family = 401,
  .types = BUG_M,
  .base_stats = { .stamina = 114, .attack = 45, .defense = 74 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_401_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_401_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_402_0[] = { 261, 200 };
uint16_t CHARGED_MOVELIST_402_0[] = { 49, 100, 45 };
pdex_mon_t DEXMON_402_0 = {
  .dex_number = 402,
  .name = "KRICKETUNE",
  .form_name = "BASE",
  .family = 401,
  .types = BUG_M,
  .base_stats = { .stamina = 184, .attack = 160, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_402_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_402_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_403_0[] = { 221, 206 };
uint16_t CHARGED_MOVELIST_403_0[] = { 35, 79, 125 };
pdex_mon_t DEXMON_403_0 = {
  .dex_number = 403,
  .name = "SHINX",
  .form_name = "BASE",
  .family = 403,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 128, .attack = 117, .defense = 64 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_403_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_403_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_404_0[] = { 206, 202 };
uint16_t CHARGED_MOVELIST_404_0[] = { 79, 251, 279 };
pdex_mon_t DEXMON_404_0 = {
  .dex_number = 404,
  .name = "LUXIO",
  .form_name = "BASE",
  .family = 403,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 155, .attack = 159, .defense = 95 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_404_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_404_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_405_0[] = { 206, 278, 281 };
uint16_t CHARGED_MOVELIST_405_0[] = { 14, 251, 279 };
pdex_mon_t DEXMON_405_0 = {
  .dex_number = 405,
  .name = "LUXRAY",
  .form_name = "BASE",
  .family = 403,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 190, .attack = 232, .defense = 156 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_405_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_405_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_406_0[] = { 281, 215 };
uint16_t CHARGED_MOVELIST_406_0[] = { 273, 272 };
pdex_mon_t DEXMON_406_0 = {
  .dex_number = 406,
  .name = "BUDEW",
  .form_name = "BASE",
  .family = 315,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 120, .attack = 91, .defense = 109 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_406_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_406_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_407_0[] = { 224, 215 };
uint16_t CHARGED_MOVELIST_407_0[] = { 116, 90, 86, 272 };
pdex_mon_t DEXMON_407_0 = {
  .dex_number = 407,
  .name = "ROSERADE",
  .form_name = "BASE",
  .family = 315,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 243, .defense = 185 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_407_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_407_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_408_0[] = { 234, 282 };
uint16_t CHARGED_MOVELIST_408_0[] = { 63, 62, 95 };
pdex_mon_t DEXMON_408_0 = {
  .dex_number = 408,
  .name = "CRANIDOS",
  .form_name = "BASE",
  .family = 408,
  .types = ROCK_M,
  .base_stats = { .stamina = 167, .attack = 218, .defense = 71 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_408_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_408_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_409_0[] = { 234, 297 };
uint16_t CHARGED_MOVELIST_409_0[] = { 64, 277, 24 };
pdex_mon_t DEXMON_409_0 = {
  .dex_number = 409,
  .name = "RAMPARDOS",
  .form_name = "BASE",
  .family = 408,
  .types = ROCK_M,
  .base_stats = { .stamina = 219, .attack = 295, .defense = 109 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_409_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_409_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_410_0[] = { 221, 266 };
uint16_t CHARGED_MOVELIST_410_0[] = { 63, 62, 268 };
pdex_mon_t DEXMON_410_0 = {
  .dex_number = 410,
  .name = "SHIELDON",
  .form_name = "BASE",
  .family = 410,
  .types = ROCK_M | STEEL_M,
  .base_stats = { .stamina = 102, .attack = 76, .defense = 195 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_410_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_410_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_411_0[] = { 297, 266 };
uint16_t CHARGED_MOVELIST_411_0[] = { 32, 24, 36 };
pdex_mon_t DEXMON_411_0 = {
  .dex_number = 411,
  .name = "BASTIODON",
  .form_name = "BASE",
  .family = 410,
  .types = ROCK_M | STEEL_M,
  .base_stats = { .stamina = 155, .attack = 94, .defense = 286 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_411_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_411_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_412_0[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_412_0[] = { 133 };
uint16_t FAST_MOVELIST_412_1[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_412_1[] = { 133 };
uint16_t FAST_MOVELIST_412_2[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_412_2[] = { 133 };
uint16_t FAST_MOVELIST_412_3[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_412_3[] = { 133 };
pdex_mon_t DEXMON_412_3 = {
  .dex_number = 412,
  .name = "BURMY",
  .form_name = "TRASH",
  .family = 412,
  .types = BUG_M,
  .base_stats = { .stamina = 120, .attack = 53, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_412_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_412_3,
  .charged_moves_cnt = 1,
 .form_idx = 3,
  .next_form = NULL
};
pdex_mon_t DEXMON_412_2 = {
  .dex_number = 412,
  .name = "BURMY",
  .form_name = "SANDY",
  .family = 412,
  .types = BUG_M,
  .base_stats = { .stamina = 120, .attack = 53, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_412_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_412_2,
  .charged_moves_cnt = 1,
 .form_idx = 2,
  .next_form = & DEXMON_412_3
};
pdex_mon_t DEXMON_412_1 = {
  .dex_number = 412,
  .name = "BURMY",
  .form_name = "PLANT",
  .family = 412,
  .types = BUG_M,
  .base_stats = { .stamina = 120, .attack = 53, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_412_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_412_1,
  .charged_moves_cnt = 1,
 .form_idx = 1,
  .next_form = & DEXMON_412_2
};
pdex_mon_t DEXMON_412_0 = {
  .dex_number = 412,
  .name = "BURMY",
  .form_name = "BASE",
  .family = 412,
  .types = BUG_M,
  .base_stats = { .stamina = 120, .attack = 53, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_412_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_412_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = & DEXMON_412_1
};
uint16_t FAST_MOVELIST_413_0[] = { 221, 201 };
uint16_t CHARGED_MOVELIST_413_0[] = { 133 };
uint16_t FAST_MOVELIST_413_1[] = { 235, 201 };
uint16_t CHARGED_MOVELIST_413_1[] = { 30, 273, 49 };
uint16_t FAST_MOVELIST_413_2[] = { 235, 201 };
uint16_t CHARGED_MOVELIST_413_2[] = { 30, 95, 49 };
uint16_t FAST_MOVELIST_413_3[] = { 235, 201 };
uint16_t CHARGED_MOVELIST_413_3[] = { 30, 74, 49 };
pdex_mon_t DEXMON_413_3 = {
  .dex_number = 413,
  .name = "WORMADAM",
  .form_name = "TRASH",
  .family = 412,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 155, .attack = 127, .defense = 175 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_413_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_413_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = NULL
};
pdex_mon_t DEXMON_413_2 = {
  .dex_number = 413,
  .name = "WORMADAM",
  .form_name = "SANDY",
  .family = 412,
  .types = BUG_M | GROUND_M,
  .base_stats = { .stamina = 155, .attack = 141, .defense = 180 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_413_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_413_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_413_3
};
pdex_mon_t DEXMON_413_1 = {
  .dex_number = 413,
  .name = "WORMADAM",
  .form_name = "PLANT",
  .family = 412,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 155, .attack = 141, .defense = 180 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_413_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_413_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_413_2
};
pdex_mon_t DEXMON_413_0 = {
  .dex_number = 413,
  .name = "WORMADAM",
  .form_name = "BASE",
  .family = 412,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 155, .attack = 141, .defense = 180 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_413_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_413_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = & DEXMON_413_1
};
uint16_t FAST_MOVELIST_414_0[] = { 255, 201 };
uint16_t CHARGED_MOVELIST_414_0[] = { 30, 45, 49 };
pdex_mon_t DEXMON_414_0 = {
  .dex_number = 414,
  .name = "MOTHIM",
  .form_name = "BASE",
  .family = 412,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 172, .attack = 185, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_414_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_414_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_415_0[] = { 201 };
uint16_t CHARGED_MOVELIST_415_0[] = { 49 };
pdex_mon_t DEXMON_415_0 = {
  .dex_number = 415,
  .name = "COMBEE",
  .form_name = "BASE",
  .family = 415,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 102, .attack = 59, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_415_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_415_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_416_0[] = { 201, 236, 200, 255 };
uint16_t CHARGED_MOVELIST_416_0[] = { 49, 65, 100, 311 };
pdex_mon_t DEXMON_416_0 = {
  .dex_number = 416,
  .name = "VESPIQUEN",
  .form_name = "BASE",
  .family = 415,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 172, .attack = 149, .defense = 190 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_416_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_416_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_417_0[] = { 206, 250 };
uint16_t CHARGED_MOVELIST_417_0[] = { 78, 79, 77 };
pdex_mon_t DEXMON_417_0 = {
  .dex_number = 417,
  .name = "PACHIRISU",
  .form_name = "BASE",
  .family = 417,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 155, .attack = 94, .defense = 172 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_417_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_417_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_418_0[] = { 230, 219 };
uint16_t CHARGED_MOVELIST_418_0[] = { 57, 105, 125 };
pdex_mon_t DEXMON_418_0 = {
  .dex_number = 418,
  .name = "BUIZEL",
  .form_name = "BASE",
  .family = 418,
  .types = WATER_M,
  .base_stats = { .stamina = 146, .attack = 132, .defense = 67 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_418_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_418_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_419_0[] = { 230, 283 };
uint16_t CHARGED_MOVELIST_419_0[] = { 57, 107, 125 };
pdex_mon_t DEXMON_419_0 = {
  .dex_number = 419,
  .name = "FLOATZEL",
  .form_name = "BASE",
  .family = 418,
  .types = WATER_M,
  .base_stats = { .stamina = 198, .attack = 221, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_419_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_419_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_420_0[] = { 221, 271 };
uint16_t CHARGED_MOVELIST_420_0[] = { 86, 47, 59 };
pdex_mon_t DEXMON_420_0 = {
  .dex_number = 420,
  .name = "CHERUBI",
  .form_name = "BASE",
  .family = 420,
  .types = GRASS_M,
  .base_stats = { .stamina = 128, .attack = 108, .defense = 92 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_420_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_420_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_421_0[] = { 215, 271 };
uint16_t CHARGED_MOVELIST_421_0[] = { 86, 14, 116 };
uint16_t FAST_MOVELIST_421_1[] = { 215, 271 };
uint16_t CHARGED_MOVELIST_421_1[] = { 86, 14, 116 };
uint16_t FAST_MOVELIST_421_2[] = { 215, 271 };
uint16_t CHARGED_MOVELIST_421_2[] = { 86, 14, 116, 292 };
pdex_mon_t DEXMON_421_2 = {
  .dex_number = 421,
  .name = "CHERRIM",
  .form_name = "SUNNY",
  .family = 420,
  .types = GRASS_M,
  .base_stats = { .stamina = 172, .attack = 170, .defense = 153 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_421_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_421_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_421_1 = {
  .dex_number = 421,
  .name = "CHERRIM",
  .form_name = "OVERCAST",
  .family = 420,
  .types = GRASS_M,
  .base_stats = { .stamina = 172, .attack = 170, .defense = 153 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_421_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_421_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_421_2
};
pdex_mon_t DEXMON_421_0 = {
  .dex_number = 421,
  .name = "CHERRIM",
  .form_name = "BASE",
  .family = 420,
  .types = GRASS_M,
  .base_stats = { .stamina = 172, .attack = 170, .defense = 153 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_421_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_421_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_421_1
};
uint16_t FAST_MOVELIST_422_0[] = { 233, 281 };
uint16_t CHARGED_MOVELIST_422_0[] = { 105, 96, 131 };
uint16_t FAST_MOVELIST_422_1[] = { 233, 281 };
uint16_t CHARGED_MOVELIST_422_1[] = { 105, 96, 131 };
uint16_t FAST_MOVELIST_422_2[] = { 233, 281 };
uint16_t CHARGED_MOVELIST_422_2[] = { 105, 96, 131 };
pdex_mon_t DEXMON_422_2 = {
  .dex_number = 422,
  .name = "SHELLOS",
  .form_name = "WEST_SEA",
  .family = 422,
  .types = WATER_M,
  .base_stats = { .stamina = 183, .attack = 103, .defense = 105 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_422_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_422_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_422_1 = {
  .dex_number = 422,
  .name = "SHELLOS",
  .form_name = "EAST_SEA",
  .family = 422,
  .types = WATER_M,
  .base_stats = { .stamina = 183, .attack = 103, .defense = 105 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_422_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_422_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_422_2
};
pdex_mon_t DEXMON_422_0 = {
  .dex_number = 422,
  .name = "SHELLOS",
  .form_name = "BASE",
  .family = 422,
  .types = WATER_M,
  .base_stats = { .stamina = 183, .attack = 103, .defense = 105 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_422_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_422_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_422_1
};
uint16_t FAST_MOVELIST_423_0[] = { 233, 281 };
uint16_t CHARGED_MOVELIST_423_0[] = { 105, 304, 131 };
uint16_t FAST_MOVELIST_423_1[] = { 233, 281 };
uint16_t CHARGED_MOVELIST_423_1[] = { 105, 304, 131 };
uint16_t FAST_MOVELIST_423_2[] = { 233, 281 };
uint16_t CHARGED_MOVELIST_423_2[] = { 105, 304, 131 };
pdex_mon_t DEXMON_423_2 = {
  .dex_number = 423,
  .name = "GASTRODON",
  .form_name = "WEST_SEA",
  .family = 422,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 244, .attack = 169, .defense = 143 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_423_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_423_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_423_1 = {
  .dex_number = 423,
  .name = "GASTRODON",
  .form_name = "EAST_SEA",
  .family = 422,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 244, .attack = 169, .defense = 143 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_423_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_423_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_423_2
};
pdex_mon_t DEXMON_423_0 = {
  .dex_number = 423,
  .name = "GASTRODON",
  .form_name = "BASE",
  .family = 422,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 244, .attack = 169, .defense = 143 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_423_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_423_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_423_1
};
uint16_t FAST_MOVELIST_424_0[] = { 220, 263 };
uint16_t CHARGED_MOVELIST_424_0[] = { 56, 14, 45 };
pdex_mon_t DEXMON_424_0 = {
  .dex_number = 424,
  .name = "AMBIPOM",
  .form_name = "BASE",
  .family = 190,
  .types = NORMAL_M,
  .base_stats = { .stamina = 181, .attack = 205, .defense = 143 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_424_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_424_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_425_0[] = { 264, 263 };
uint16_t CHARGED_MOVELIST_425_0[] = { 69, 111, 70 };
pdex_mon_t DEXMON_425_0 = {
  .dex_number = 425,
  .name = "DRIFLOON",
  .form_name = "BASE",
  .family = 425,
  .types = FLYING_M | GHOST_M,
  .base_stats = { .stamina = 207, .attack = 117, .defense = 80 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_425_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_425_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_426_0[] = { 264, 263 };
uint16_t CHARGED_MOVELIST_426_0[] = { 69, 111, 70 };
pdex_mon_t DEXMON_426_0 = {
  .dex_number = 426,
  .name = "DRIFBLIM",
  .form_name = "BASE",
  .family = 425,
  .types = FLYING_M | GHOST_M,
  .base_stats = { .stamina = 312, .attack = 180, .defense = 102 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_426_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_426_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_427_0[] = { 222, 219 };
uint16_t CHARGED_MOVELIST_427_0[] = { 115, 125 };
pdex_mon_t DEXMON_427_0 = {
  .dex_number = 427,
  .name = "BUNEARY",
  .form_name = "BASE",
  .family = 427,
  .types = NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 130, .defense = 105 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_427_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_427_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_428_0[] = { 222, 207 };
uint16_t CHARGED_MOVELIST_428_0[] = { 115, 14, 247 };
pdex_mon_t DEXMON_428_0 = {
  .dex_number = 428,
  .name = "LOPUNNY",
  .form_name = "BASE",
  .family = 427,
  .types = NORMAL_M,
  .base_stats = { .stamina = 163, .attack = 156, .defense = 194 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_428_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_428_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_429_0[] = { 203, 264 };
uint16_t CHARGED_MOVELIST_429_0[] = { 70, 16, 86 };
pdex_mon_t DEXMON_429_0 = {
  .dex_number = 429,
  .name = "MISMAGIUS",
  .form_name = "BASE",
  .family = 200,
  .types = GHOST_M,
  .base_stats = { .stamina = 155, .attack = 211, .defense = 187 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_429_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_429_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_430_0[] = { 211, 278 };
uint16_t CHARGED_MOVELIST_430_0[] = { 256, 108, 16, 257 };
pdex_mon_t DEXMON_430_0 = {
  .dex_number = 430,
  .name = "HONCHKROW",
  .form_name = "BASE",
  .family = 198,
  .types = DARK_M | FLYING_M,
  .base_stats = { .stamina = 225, .attack = 243, .defense = 103 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_430_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_430_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_431_0[] = { 220, 219 };
uint16_t CHARGED_MOVELIST_431_0[] = { 88, 79, 45 };
pdex_mon_t DEXMON_431_0 = {
  .dex_number = 431,
  .name = "GLAMEOW",
  .form_name = "BASE",
  .family = 431,
  .types = NORMAL_M,
  .base_stats = { .stamina = 135, .attack = 109, .defense = 82 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_431_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_431_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_432_0[] = { 220, 213 };
uint16_t CHARGED_MOVELIST_432_0[] = { 88, 78, 45 };
pdex_mon_t DEXMON_432_0 = {
  .dex_number = 432,
  .name = "PURUGLY",
  .form_name = "BASE",
  .family = 431,
  .types = NORMAL_M,
  .base_stats = { .stamina = 174, .attack = 172, .defense = 133 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_432_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_432_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_433_0[] = { 234, 263 };
uint16_t CHARGED_MOVELIST_433_0[] = { 13, 70, 60 };
pdex_mon_t DEXMON_433_0 = {
  .dex_number = 433,
  .name = "CHINGLING",
  .form_name = "BASE",
  .family = 358,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 128, .attack = 114, .defense = 94 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_433_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_433_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_434_0[] = { 220, 202 };
uint16_t CHARGED_MOVELIST_434_0[] = { 279, 24, 90 };
pdex_mon_t DEXMON_434_0 = {
  .dex_number = 434,
  .name = "STUNKY",
  .form_name = "BASE",
  .family = 434,
  .types = DARK_M | POISON_M,
  .base_stats = { .stamina = 160, .attack = 121, .defense = 90 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_434_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_434_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_435_0[] = { 224, 202 };
uint16_t CHARGED_MOVELIST_435_0[] = { 279, 24, 90 };
pdex_mon_t DEXMON_435_0 = {
  .dex_number = 435,
  .name = "SKUNTANK",
  .form_name = "BASE",
  .family = 434,
  .types = DARK_M | POISON_M,
  .base_stats = { .stamina = 230, .attack = 184, .defense = 132 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_435_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_435_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_436_0[] = { 221, 235 };
uint16_t CHARGED_MOVELIST_436_0[] = { 267, 60, 268 };
pdex_mon_t DEXMON_436_0 = {
  .dex_number = 436,
  .name = "BRONZOR",
  .form_name = "BASE",
  .family = 436,
  .types = PSYCHIC_M | STEEL_M,
  .base_stats = { .stamina = 149, .attack = 43, .defense = 154 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_436_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_436_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_437_0[] = { 238, 235 };
uint16_t CHARGED_MOVELIST_437_0[] = { 36, 108, 268, 95, 60 };
pdex_mon_t DEXMON_437_0 = {
  .dex_number = 437,
  .name = "BRONZONG",
  .form_name = "BASE",
  .family = 436,
  .types = PSYCHIC_M | STEEL_M,
  .base_stats = { .stamina = 167, .attack = 161, .defense = 213 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_437_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_437_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_438_0[] = { 227, 243 };
uint16_t CHARGED_MOVELIST_438_0[] = { 63, 31, 64 };
pdex_mon_t DEXMON_438_0 = {
  .dex_number = 438,
  .name = "BONSLY",
  .form_name = "BASE",
  .family = 185,
  .types = ROCK_M,
  .base_stats = { .stamina = 137, .attack = 124, .defense = 133 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_438_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_438_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_439_0[] = { 235, 222 };
uint16_t CHARGED_MOVELIST_439_0[] = { 30, 108, 60 };
pdex_mon_t DEXMON_439_0 = {
  .dex_number = 439,
  .name = "MIME_JR",
  .form_name = "BASE",
  .family = 122,
  .types = FAIRY_M | PSYCHIC_M,
  .base_stats = { .stamina = 85, .attack = 125, .defense = 142 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_439_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_439_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_440_0[] = { 222, 234 };
uint16_t CHARGED_MOVELIST_440_0[] = { 108 };
pdex_mon_t DEXMON_440_0 = {
  .dex_number = 440,
  .name = "HAPPINY",
  .form_name = "BASE",
  .family = 113,
  .types = NORMAL_M,
  .base_stats = { .stamina = 225, .attack = 25, .defense = 77 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_440_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_440_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_441_0[] = { 211, 239 };
uint16_t CHARGED_MOVELIST_441_0[] = { 265, 257, 42 };
pdex_mon_t DEXMON_441_0 = {
  .dex_number = 441,
  .name = "CHATOT",
  .form_name = "BASE",
  .family = 441,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 183, .attack = 183, .defense = 91 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_441_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_441_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_442_0[] = { 238, 203 };
uint16_t CHARGED_MOVELIST_442_0[] = { 66, 69, 70 };
pdex_mon_t DEXMON_442_0 = {
  .dex_number = 442,
  .name = "SPIRITOMB",
  .form_name = "BASE",
  .family = 442,
  .types = DARK_M | GHOST_M,
  .base_stats = { .stamina = 137, .attack = 169, .defense = 199 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_442_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_442_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_443_0[] = { 282, 216 };
uint16_t CHARGED_MOVELIST_443_0[] = { 26, 80, 131 };
pdex_mon_t DEXMON_443_0 = {
  .dex_number = 443,
  .name = "GIBLE",
  .form_name = "BASE",
  .family = 443,
  .types = DRAGON_M | GROUND_M,
  .base_stats = { .stamina = 151, .attack = 124, .defense = 84 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_443_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_443_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_444_0[] = { 282, 216 };
uint16_t CHARGED_MOVELIST_444_0[] = { 26, 80, 24 };
pdex_mon_t DEXMON_444_0 = {
  .dex_number = 444,
  .name = "GABITE",
  .form_name = "BASE",
  .family = 443,
  .types = DRAGON_M | GROUND_M,
  .base_stats = { .stamina = 169, .attack = 172, .defense = 125 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_444_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_444_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_445_0[] = { 253, 216 };
uint16_t CHARGED_MOVELIST_445_0[] = { 277, 31, 103, 258 };
pdex_mon_t DEXMON_445_0 = {
  .dex_number = 445,
  .name = "GARCHOMP",
  .form_name = "BASE",
  .family = 443,
  .types = DRAGON_M | GROUND_M,
  .base_stats = { .stamina = 239, .attack = 261, .defense = 193 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_445_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_445_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_446_0[] = { 221, 212 };
uint16_t CHARGED_MOVELIST_446_0[] = { 92, 131, 95 };
pdex_mon_t DEXMON_446_0 = {
  .dex_number = 446,
  .name = "MUNCHLAX",
  .form_name = "BASE",
  .family = 143,
  .types = NORMAL_M,
  .base_stats = { .stamina = 286, .attack = 137, .defense = 117 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_446_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_446_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_447_0[] = { 243, 219 };
uint16_t CHARGED_MOVELIST_447_0[] = { 123, 56, 28 };
pdex_mon_t DEXMON_447_0 = {
  .dex_number = 447,
  .name = "RIOLU",
  .form_name = "BASE",
  .family = 448,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 120, .attack = 127, .defense = 78 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_447_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_447_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_448_0[] = { 243, 229 };
uint16_t CHARGED_MOVELIST_448_0[] = { 36, 70, 245, 319, 332 };
pdex_mon_t DEXMON_448_0 = {
  .dex_number = 448,
  .name = "LUCARIO",
  .form_name = "BASE",
  .family = 448,
  .types = FIGHTING_M | STEEL_M,
  .base_stats = { .stamina = 172, .attack = 236, .defense = 144 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_448_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_448_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_449_0[] = { 221, 202 };
uint16_t CHARGED_MOVELIST_449_0[] = { 26, 63, 131 };
pdex_mon_t DEXMON_449_0 = {
  .dex_number = 449,
  .name = "HIPPOPOTAS",
  .form_name = "BASE",
  .family = 449,
  .types = GROUND_M,
  .base_stats = { .stamina = 169, .attack = 124, .defense = 118 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_449_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_449_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_450_0[] = { 240, 202, 326, 327 };
uint16_t CHARGED_MOVELIST_450_0[] = { 31, 32, 131, 304 };
pdex_mon_t DEXMON_450_0 = {
  .dex_number = 450,
  .name = "HIPPOWDON",
  .form_name = "BASE",
  .family = 449,
  .types = GROUND_M,
  .base_stats = { .stamina = 239, .attack = 201, .defense = 191 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_450_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_450_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_451_0[] = { 236, 260 };
uint16_t CHARGED_MOVELIST_451_0[] = { 89, 58, 90 };
pdex_mon_t DEXMON_451_0 = {
  .dex_number = 451,
  .name = "SKORUPI",
  .form_name = "BASE",
  .family = 451,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 120, .attack = 93, .defense = 151 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_451_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_451_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_452_0[] = { 236, 260, 202, 327 };
uint16_t CHARGED_MOVELIST_452_0[] = { 279, 58, 90, 311 };
pdex_mon_t DEXMON_452_0 = {
  .dex_number = 452,
  .name = "DRAPION",
  .form_name = "BASE",
  .family = 451,
  .types = DARK_M | POISON_M,
  .base_stats = { .stamina = 172, .attack = 180, .defense = 202 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_452_0,
  .fast_moves_cnt = 4,
  .charged_move_ids = CHARGED_MOVELIST_452_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_453_0[] = { 236, 224 };
uint16_t CHARGED_MOVELIST_453_0[] = { 123, 56, 90 };
pdex_mon_t DEXMON_453_0 = {
  .dex_number = 453,
  .name = "CROAGUNK",
  .form_name = "BASE",
  .family = 453,
  .types = FIGHTING_M | POISON_M,
  .base_stats = { .stamina = 134, .attack = 116, .defense = 76 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_453_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_453_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_454_0[] = { 224, 243 };
uint16_t CHARGED_MOVELIST_454_0[] = { 246, 96, 90 };
pdex_mon_t DEXMON_454_0 = {
  .dex_number = 454,
  .name = "TOXICROAK",
  .form_name = "BASE",
  .family = 453,
  .types = FIGHTING_M | POISON_M,
  .base_stats = { .stamina = 195, .attack = 211, .defense = 133 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_454_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_454_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_455_0[] = { 202, 214 };
uint16_t CHARGED_MOVELIST_455_0[] = { 118, 273, 279 };
pdex_mon_t DEXMON_455_0 = {
  .dex_number = 455,
  .name = "CARNIVINE",
  .form_name = "BASE",
  .family = 455,
  .types = GRASS_M,
  .base_stats = { .stamina = 179, .attack = 187, .defense = 136 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_455_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_455_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_456_0[] = { 222, 230 };
uint16_t CHARGED_MOVELIST_456_0[] = { 105, 39, 262 };
pdex_mon_t DEXMON_456_0 = {
  .dex_number = 456,
  .name = "FINNEON",
  .form_name = "BASE",
  .family = 456,
  .types = WATER_M,
  .base_stats = { .stamina = 135, .attack = 96, .defense = 116 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_456_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_456_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_457_0[] = { 283, 230 };
uint16_t CHARGED_MOVELIST_457_0[] = { 105, 40, 262 };
pdex_mon_t DEXMON_457_0 = {
  .dex_number = 457,
  .name = "LUMINEON",
  .form_name = "BASE",
  .family = 456,
  .types = WATER_M,
  .base_stats = { .stamina = 170, .attack = 142, .defense = 170 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_457_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_457_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_458_0[] = { 237, 221 };
uint16_t CHARGED_MOVELIST_458_0[] = { 105, 39, 45 };
pdex_mon_t DEXMON_458_0 = {
  .dex_number = 458,
  .name = "MANTYKE",
  .form_name = "BASE",
  .family = 226,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 128, .attack = 105, .defense = 179 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_458_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_458_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_459_0[] = { 244, 217 };
uint16_t CHARGED_MOVELIST_459_0[] = { 39, 273, 127 };
pdex_mon_t DEXMON_459_0 = {
  .dex_number = 459,
  .name = "SNOVER",
  .form_name = "BASE",
  .family = 459,
  .types = GRASS_M | ICE_M,
  .base_stats = { .stamina = 155, .attack = 115, .defense = 105 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_459_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_459_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_460_0[] = { 244, 215 };
uint16_t CHARGED_MOVELIST_460_0[] = { 40, 273, 277 };
pdex_mon_t DEXMON_460_0 = {
  .dex_number = 460,
  .name = "ABOMASNOW",
  .form_name = "BASE",
  .family = 459,
  .types = GRASS_M | ICE_M,
  .base_stats = { .stamina = 207, .attack = 178, .defense = 158 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_460_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_460_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_461_0[] = { 217, 238, 278 };
uint16_t CHARGED_MOVELIST_461_0[] = { 254, 247, 280 };
pdex_mon_t DEXMON_461_0 = {
  .dex_number = 461,
  .name = "WEAVILE",
  .form_name = "BASE",
  .family = 215,
  .types = DARK_M | ICE_M,
  .base_stats = { .stamina = 172, .attack = 243, .defense = 171 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_461_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_461_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_462_0[] = { 206, 249 };
uint16_t CHARGED_MOVELIST_462_0[] = { 252, 251, 36, 309 };
pdex_mon_t DEXMON_462_0 = {
  .dex_number = 462,
  .name = "MAGNEZONE",
  .form_name = "BASE",
  .family = 81,
  .types = ELECTRIC_M | STEEL_M,
  .base_stats = { .stamina = 172, .attack = 238, .defense = 205 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_462_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_462_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_463_0[] = { 212, 234 };
uint16_t CHARGED_MOVELIST_463_0[] = { 14, 31, 116, 70, -131 };
pdex_mon_t DEXMON_463_0 = {
  .dex_number = 463,
  .name = "LICKILICKY",
  .form_name = "BASE",
  .family = 108,
  .types = NORMAL_M,
  .base_stats = { .stamina = 242, .attack = 161, .defense = 181 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_463_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_463_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_464_0[] = { 233, 297 };
uint16_t CHARGED_MOVELIST_464_0[] = { 284, 31, 32, 302, 310, -334 };
pdex_mon_t DEXMON_464_0 = {
  .dex_number = 464,
  .name = "RHYPERIOR",
  .form_name = "BASE",
  .family = 111,
  .types = GROUND_M | ROCK_M,
  .base_stats = { .stamina = 251, .attack = 241, .defense = 190 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_464_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_464_0,
  .charged_moves_cnt = 6,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_465_0[] = { 214, 260 };
uint16_t CHARGED_MOVELIST_465_0[] = { 62, 90, 116, 118, 64 };
pdex_mon_t DEXMON_465_0 = {
  .dex_number = 465,
  .name = "TANGROWTH",
  .form_name = "BASE",
  .family = 114,
  .types = GRASS_M,
  .base_stats = { .stamina = 225, .attack = 207, .defense = 184 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_465_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_465_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_466_0[] = { 205, 207 };
uint16_t CHARGED_MOVELIST_466_0[] = { 77, 251, 78, 33 };
pdex_mon_t DEXMON_466_0 = {
  .dex_number = 466,
  .name = "ELECTIVIRE",
  .form_name = "BASE",
  .family = 125,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 181, .attack = 249, .defense = 163 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_466_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_466_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_467_0[] = { 269, 208 };
uint16_t CHARGED_MOVELIST_467_0[] = { 123, 115, 103, 108 };
pdex_mon_t DEXMON_467_0 = {
  .dex_number = 467,
  .name = "MAGMORTAR",
  .form_name = "BASE",
  .family = 126,
  .types = FIRE_M,
  .base_stats = { .stamina = 181, .attack = 247, .defense = 172 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_467_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_467_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_468_0[] = { 255, 281, 320 };
uint16_t CHARGED_MOVELIST_468_0[] = { 62, 86, 45, 24 };
pdex_mon_t DEXMON_468_0 = {
  .dex_number = 468,
  .name = "TOGEKISS",
  .form_name = "BASE",
  .family = 175,
  .types = FAIRY_M | FLYING_M,
  .base_stats = { .stamina = 198, .attack = 225, .defense = 217 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_468_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_468_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_469_0[] = { 201, 210 };
uint16_t CHARGED_MOVELIST_469_0[] = { 62, 45, 49 };
pdex_mon_t DEXMON_469_0 = {
  .dex_number = 469,
  .name = "YANMEGA",
  .form_name = "BASE",
  .family = 193,
  .types = BUG_M | FLYING_M,
  .base_stats = { .stamina = 200, .attack = 231, .defense = 156 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_469_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_469_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_470_0[] = { 215, 219 };
uint16_t CHARGED_MOVELIST_470_0[] = { 116, 117, 273, -300 };
pdex_mon_t DEXMON_470_0 = {
  .dex_number = 470,
  .name = "LEAFEON",
  .form_name = "BASE",
  .family = 133,
  .types = GRASS_M,
  .base_stats = { .stamina = 163, .attack = 216, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_470_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_470_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_471_0[] = { 217, 218 };
uint16_t CHARGED_MOVELIST_471_0[] = { 254, 111, 39, -300 };
pdex_mon_t DEXMON_471_0 = {
  .dex_number = 471,
  .name = "GLACEON",
  .form_name = "BASE",
  .family = 133,
  .types = ICE_M,
  .base_stats = { .stamina = 163, .attack = 238, .defense = 205 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_471_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_471_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_472_0[] = { 200, 210 };
uint16_t CHARGED_MOVELIST_472_0[] = { 31, 45, 51, 258 };
pdex_mon_t DEXMON_472_0 = {
  .dex_number = 472,
  .name = "GLISCOR",
  .form_name = "BASE",
  .family = 207,
  .types = FLYING_M | GROUND_M,
  .base_stats = { .stamina = 181, .attack = 185, .defense = 222 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_472_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_472_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_473_0[] = { 233, 244 };
uint16_t CHARGED_MOVELIST_473_0[] = { 254, 95, 32, -62 };
pdex_mon_t DEXMON_473_0 = {
  .dex_number = 473,
  .name = "MAMOSWINE",
  .form_name = "BASE",
  .family = 220,
  .types = GROUND_M | ICE_M,
  .base_stats = { .stamina = 242, .attack = 247, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_473_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_473_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_474_0[] = { 281, 249, 325 };
uint16_t CHARGED_MOVELIST_474_0[] = { 116, 14, 252, 40 };
pdex_mon_t DEXMON_474_0 = {
  .dex_number = 474,
  .name = "PORYGON_Z",
  .form_name = "BASE",
  .family = 474,
  .types = NORMAL_M,
  .base_stats = { .stamina = 198, .attack = 264, .defense = 150 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_474_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_474_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_475_0[] = { 235, 207, 320 };
uint16_t CHARGED_MOVELIST_475_0[] = { 245, 108, 117, -324 };
pdex_mon_t DEXMON_475_0 = {
  .dex_number = 475,
  .name = "GALLADE",
  .form_name = "BASE",
  .family = 280,
  .types = FIGHTING_M | PSYCHIC_M,
  .base_stats = { .stamina = 169, .attack = 237, .defense = 195 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_475_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_475_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_476_0[] = { 227, 206 };
uint16_t CHARGED_MOVELIST_476_0[] = { 72, 64, 79 };
pdex_mon_t DEXMON_476_0 = {
  .dex_number = 476,
  .name = "PROBOPASS",
  .form_name = "BASE",
  .family = 299,
  .types = ROCK_M | STEEL_M,
  .base_stats = { .stamina = 155, .attack = 135, .defense = 275 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_476_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_476_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_477_0[] = { 264, 263 };
uint16_t CHARGED_MOVELIST_477_0[] = { 69, 108, 16 };
pdex_mon_t DEXMON_477_0 = {
  .dex_number = 477,
  .name = "DUSKNOIR",
  .form_name = "BASE",
  .family = 355,
  .types = GHOST_M,
  .base_stats = { .stamina = 128, .attack = 180, .defense = 254 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_477_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_477_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_478_0[] = { 244, 264 };
uint16_t CHARGED_MOVELIST_478_0[] = { 254, 279, 70 };
pdex_mon_t DEXMON_478_0 = {
  .dex_number = 478,
  .name = "FROSLASS",
  .form_name = "BASE",
  .family = 361,
  .types = GHOST_M | ICE_M,
  .base_stats = { .stamina = 172, .attack = 171, .defense = 150 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_478_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_478_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_479_0[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_479_0[] = { 69, 79, 78 };
uint16_t FAST_MOVELIST_479_1[] = { 263, 255 };
uint16_t CHARGED_MOVELIST_479_1[] = { 69, 79, 78 };
uint16_t FAST_MOVELIST_479_2[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_479_2[] = { 40, 79, 78 };
uint16_t FAST_MOVELIST_479_3[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_479_3[] = { 270, 79, 78 };
uint16_t FAST_MOVELIST_479_4[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_479_4[] = { 69, 79, 78 };
uint16_t FAST_MOVELIST_479_5[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_479_5[] = { 107, 79, 78 };
pdex_mon_t DEXMON_479_5 = {
  .dex_number = 479,
  .name = "ROTOM",
  .form_name = "WASH",
  .family = 479,
  .types = ELECTRIC_M | WATER_M,
  .base_stats = { .stamina = 137, .attack = 204, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_479_5,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_479_5,
  .charged_moves_cnt = 3,
 .form_idx = 5,
  .next_form = NULL
};
pdex_mon_t DEXMON_479_4 = {
  .dex_number = 479,
  .name = "ROTOM",
  .form_name = "MOW",
  .family = 479,
  .types = ELECTRIC_M | GRASS_M,
  .base_stats = { .stamina = 137, .attack = 204, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_479_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_479_4,
  .charged_moves_cnt = 3,
 .form_idx = 4,
  .next_form = & DEXMON_479_5
};
pdex_mon_t DEXMON_479_3 = {
  .dex_number = 479,
  .name = "ROTOM",
  .form_name = "HEAT",
  .family = 479,
  .types = ELECTRIC_M | FIRE_M,
  .base_stats = { .stamina = 137, .attack = 204, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_479_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_479_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = & DEXMON_479_4
};
pdex_mon_t DEXMON_479_2 = {
  .dex_number = 479,
  .name = "ROTOM",
  .form_name = "FROST",
  .family = 479,
  .types = ELECTRIC_M | ICE_M,
  .base_stats = { .stamina = 137, .attack = 204, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_479_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_479_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_479_3
};
pdex_mon_t DEXMON_479_1 = {
  .dex_number = 479,
  .name = "ROTOM",
  .form_name = "FAN",
  .family = 479,
  .types = ELECTRIC_M | FLYING_M,
  .base_stats = { .stamina = 137, .attack = 204, .defense = 219 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_479_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_479_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_479_2
};
pdex_mon_t DEXMON_479_0 = {
  .dex_number = 479,
  .name = "ROTOM",
  .form_name = "BASE",
  .family = 479,
  .types = ELECTRIC_M | GHOST_M,
  .base_stats = { .stamina = 137, .attack = 185, .defense = 159 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_479_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_479_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_479_1
};
uint16_t FAST_MOVELIST_480_0[] = { 235, 274 };
uint16_t CHARGED_MOVELIST_480_0[] = { 275, 125, 78 };
pdex_mon_t DEXMON_480_0 = {
  .dex_number = 480,
  .name = "UXIE",
  .form_name = "BASE",
  .family = 480,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 181, .attack = 156, .defense = 270 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_480_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_480_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_481_0[] = { 235, 274 };
uint16_t CHARGED_MOVELIST_481_0[] = { 275, 125, 40 };
pdex_mon_t DEXMON_481_0 = {
  .dex_number = 481,
  .name = "MESPRIT",
  .form_name = "BASE",
  .family = 481,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 190, .attack = 212, .defense = 212 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_481_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_481_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_482_0[] = { 235, 274 };
uint16_t CHARGED_MOVELIST_482_0[] = { 275, 125, 103 };
pdex_mon_t DEXMON_482_0 = {
  .dex_number = 482,
  .name = "AZELF",
  .form_name = "BASE",
  .family = 482,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 181, .attack = 270, .defense = 151 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_482_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_482_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_483_0[] = { 204, 228 };
uint16_t CHARGED_MOVELIST_483_0[] = { 285, 74, 78 };
pdex_mon_t DEXMON_483_0 = {
  .dex_number = 483,
  .name = "DIALGA",
  .form_name = "BASE",
  .family = 483,
  .types = DRAGON_M | STEEL_M,
  .base_stats = { .stamina = 205, .attack = 275, .defense = 211 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_483_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_483_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_484_0[] = { 204, 253 };
uint16_t CHARGED_MOVELIST_484_0[] = { 285, 103, 107, 58 };
pdex_mon_t DEXMON_484_0 = {
  .dex_number = 484,
  .name = "PALKIA",
  .form_name = "BASE",
  .family = 484,
  .types = DRAGON_M | WATER_M,
  .base_stats = { .stamina = 189, .attack = 280, .defense = 215 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_484_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_484_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_485_0[] = { 269, 201 };
uint16_t CHARGED_MOVELIST_485_0[] = { 103, 74, 32, 24 };
pdex_mon_t DEXMON_485_0 = {
  .dex_number = 485,
  .name = "HEATRAN",
  .form_name = "BASE",
  .family = 485,
  .types = FIRE_M | STEEL_M,
  .base_stats = { .stamina = 209, .attack = 251, .defense = 213 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_485_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_485_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_486_0[] = { 234, 281 };
uint16_t CHARGED_MOVELIST_486_0[] = { 321, 247, 78 };
pdex_mon_t DEXMON_486_0 = {
  .dex_number = 486,
  .name = "REGIGIGAS",
  .form_name = "BASE",
  .family = 486,
  .types = NORMAL_M,
  .base_stats = { .stamina = 221, .attack = 287, .defense = 210 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_486_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_486_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_487_0[] = { 204, 213 };
uint16_t CHARGED_MOVELIST_487_0[] = { 83, 62, 66 };
uint16_t FAST_MOVELIST_487_1[] = { 204, 213 };
uint16_t CHARGED_MOVELIST_487_1[] = { 83, 62, 66 };
uint16_t FAST_MOVELIST_487_2[] = { 253, 213 };
uint16_t CHARGED_MOVELIST_487_2[] = { 82, 69, 70 };
pdex_mon_t DEXMON_487_2 = {
  .dex_number = 487,
  .name = "GIRATINA",
  .form_name = "ORIGIN",
  .family = 487,
  .types = DRAGON_M | GHOST_M,
  .base_stats = { .stamina = 284, .attack = 225, .defense = 187 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_487_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_487_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_487_1 = {
  .dex_number = 487,
  .name = "GIRATINA",
  .form_name = "ALTERED",
  .family = 487,
  .types = DRAGON_M | GHOST_M,
  .base_stats = { .stamina = 284, .attack = 187, .defense = 225 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_487_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_487_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_487_2
};
pdex_mon_t DEXMON_487_0 = {
  .dex_number = 487,
  .name = "GIRATINA",
  .form_name = "BASE",
  .family = 487,
  .types = DRAGON_M | GHOST_M,
  .base_stats = { .stamina = 284, .attack = 187, .defense = 225 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_487_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_487_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_487_1
};
uint16_t FAST_MOVELIST_488_0[] = { 226, 235 };
uint16_t CHARGED_MOVELIST_488_0[] = { 248, 87, 275, -272 };
pdex_mon_t DEXMON_488_0 = {
  .dex_number = 488,
  .name = "CRESSELIA",
  .form_name = "BASE",
  .family = 488,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 260, .attack = 152, .defense = 258 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_488_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_488_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_489_0[] = { 283, 237 };
uint16_t CHARGED_MOVELIST_489_0[] = { 53, 105, 284 };
pdex_mon_t DEXMON_489_0 = {
  .dex_number = 489,
  .name = "PHIONE",
  .form_name = "BASE",
  .family = 489,
  .types = WATER_M,
  .base_stats = { .stamina = 190, .attack = 162, .defense = 162 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_489_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_489_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_490_0[] = { 283, 237 };
uint16_t CHARGED_MOVELIST_490_0[] = { 53, 108, 284 };
pdex_mon_t DEXMON_490_0 = {
  .dex_number = 490,
  .name = "MANAPHY",
  .form_name = "BASE",
  .family = 490,
  .types = WATER_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_490_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_490_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_491_0[] = { 278, 238 };
uint16_t CHARGED_MOVELIST_491_0[] = { 247, 70, 16 };
pdex_mon_t DEXMON_491_0 = {
  .dex_number = 491,
  .name = "DARKRAI",
  .form_name = "BASE",
  .family = 491,
  .types = DARK_M,
  .base_stats = { .stamina = 172, .attack = 285, .defense = 198 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_491_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_491_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_492_0[] = { 281, 234 };
uint16_t CHARGED_MOVELIST_492_0[] = { 273, 272, 116 };
uint16_t FAST_MOVELIST_492_1[] = { 281, 234 };
uint16_t CHARGED_MOVELIST_492_1[] = { 273, 272, 116 };
uint16_t FAST_MOVELIST_492_2[] = { 281, 234 };
uint16_t CHARGED_MOVELIST_492_2[] = { 273, 272, 116 };
pdex_mon_t DEXMON_492_2 = {
  .dex_number = 492,
  .name = "SHAYMIN",
  .form_name = "SKY",
  .family = 492,
  .types = FLYING_M | GRASS_M,
  .base_stats = { .stamina = 225, .attack = 261, .defense = 166 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_492_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_492_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_492_1 = {
  .dex_number = 492,
  .name = "SHAYMIN",
  .form_name = "LAND",
  .family = 492,
  .types = GRASS_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_492_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_492_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_492_2
};
pdex_mon_t DEXMON_492_0 = {
  .dex_number = 492,
  .name = "SHAYMIN",
  .form_name = "BASE",
  .family = 492,
  .types = GRASS_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_492_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_492_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_492_1
};
uint16_t FAST_MOVELIST_493_0[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_0[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_1[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_1[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_2[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_2[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_3[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_3[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_4[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_4[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_5[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_5[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_6[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_6[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_7[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_7[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_8[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_8[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_9[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_9[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_10[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_10[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_11[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_11[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_12[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_12[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_13[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_13[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_14[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_14[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_15[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_15[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_16[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_16[] = { 275, 14, 277 };
uint16_t FAST_MOVELIST_493_17[] = { 266, 213 };
uint16_t CHARGED_MOVELIST_493_17[] = { 275, 14, 277 };
pdex_mon_t DEXMON_493_17 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "WATER",
  .family = 493,
  .types = WATER_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_17,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_17,
  .charged_moves_cnt = 3,
 .form_idx = 17,
  .next_form = NULL
};
pdex_mon_t DEXMON_493_16 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "STEEL",
  .family = 493,
  .types = STEEL_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_16,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_16,
  .charged_moves_cnt = 3,
 .form_idx = 16,
  .next_form = & DEXMON_493_17
};
pdex_mon_t DEXMON_493_15 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "ROCK",
  .family = 493,
  .types = ROCK_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_15,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_15,
  .charged_moves_cnt = 3,
 .form_idx = 15,
  .next_form = & DEXMON_493_16
};
pdex_mon_t DEXMON_493_14 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "PSYCHIC",
  .family = 493,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_14,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_14,
  .charged_moves_cnt = 3,
 .form_idx = 14,
  .next_form = & DEXMON_493_15
};
pdex_mon_t DEXMON_493_13 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "POISON",
  .family = 493,
  .types = POISON_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_13,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_13,
  .charged_moves_cnt = 3,
 .form_idx = 13,
  .next_form = & DEXMON_493_14
};
pdex_mon_t DEXMON_493_12 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "ICE",
  .family = 493,
  .types = ICE_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_12,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_12,
  .charged_moves_cnt = 3,
 .form_idx = 12,
  .next_form = & DEXMON_493_13
};
pdex_mon_t DEXMON_493_11 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "GROUND",
  .family = 493,
  .types = GROUND_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_11,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_11,
  .charged_moves_cnt = 3,
 .form_idx = 11,
  .next_form = & DEXMON_493_12
};
pdex_mon_t DEXMON_493_10 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "GRASS",
  .family = 493,
  .types = GRASS_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_10,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_10,
  .charged_moves_cnt = 3,
 .form_idx = 10,
  .next_form = & DEXMON_493_11
};
pdex_mon_t DEXMON_493_9 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "GHOST",
  .family = 493,
  .types = GHOST_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_9,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_9,
  .charged_moves_cnt = 3,
 .form_idx = 9,
  .next_form = & DEXMON_493_10
};
pdex_mon_t DEXMON_493_8 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "FLYING",
  .family = 493,
  .types = FLYING_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_8,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_8,
  .charged_moves_cnt = 3,
 .form_idx = 8,
  .next_form = & DEXMON_493_9
};
pdex_mon_t DEXMON_493_7 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "FIRE",
  .family = 493,
  .types = FIRE_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_7,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_7,
  .charged_moves_cnt = 3,
 .form_idx = 7,
  .next_form = & DEXMON_493_8
};
pdex_mon_t DEXMON_493_6 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "FIGHTING",
  .family = 493,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_6,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_6,
  .charged_moves_cnt = 3,
 .form_idx = 6,
  .next_form = & DEXMON_493_7
};
pdex_mon_t DEXMON_493_5 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "FAIRY",
  .family = 493,
  .types = FAIRY_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_5,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_5,
  .charged_moves_cnt = 3,
 .form_idx = 5,
  .next_form = & DEXMON_493_6
};
pdex_mon_t DEXMON_493_4 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "ELECTRIC",
  .family = 493,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_4,
  .charged_moves_cnt = 3,
 .form_idx = 4,
  .next_form = & DEXMON_493_5
};
pdex_mon_t DEXMON_493_3 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "DRAGON",
  .family = 493,
  .types = DRAGON_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = & DEXMON_493_4
};
pdex_mon_t DEXMON_493_2 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "DARK",
  .family = 493,
  .types = DARK_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_493_3
};
pdex_mon_t DEXMON_493_1 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "BUG",
  .family = 493,
  .types = BUG_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_493_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_493_2
};
pdex_mon_t DEXMON_493_0 = {
  .dex_number = 493,
  .name = "ARCEUS",
  .form_name = "BASE",
  .family = 493,
  .types = NORMAL_M,
  .base_stats = { .stamina = 237, .attack = 238, .defense = 238 },
  .tags = TAG_MYTHIC_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_493_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_493_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_493_1
};
uint16_t FAST_MOVELIST_494_0[] = { 235, 219 };
uint16_t CHARGED_MOVELIST_494_0[] = { 270, 247, 108, 342 };
pdex_mon_t DEXMON_494_0 = {
  .dex_number = 494,
  .name = "VICTINI",
  .form_name = "BASE",
  .family = 494,
  .types = FIRE_M | PSYCHIC_M,
  .base_stats = { .stamina = 225, .attack = 210, .defense = 210 },
  .tags = TAG_MYTHIC_M | TAG_STARTER_M,
  .fast_move_ids = FAST_MOVELIST_494_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_494_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_495_0[] = { 221, 214 };
uint16_t CHARGED_MOVELIST_495_0[] = { 273, 59, 13 };
pdex_mon_t DEXMON_495_0 = {
  .dex_number = 495,
  .name = "SNIVY",
  .form_name = "BASE",
  .family = 495,
  .types = GRASS_M,
  .base_stats = { .stamina = 128, .attack = 88, .defense = 107 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_495_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_495_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_496_0[] = { 266, 214 };
uint16_t CHARGED_MOVELIST_496_0[] = { 272, 312, 13 };
pdex_mon_t DEXMON_496_0 = {
  .dex_number = 496,
  .name = "SERVINE",
  .form_name = "BASE",
  .family = 495,
  .types = GRASS_M,
  .base_stats = { .stamina = 155, .attack = 122, .defense = 152 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_496_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_496_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_497_0[] = { 266, 214 };
uint16_t CHARGED_MOVELIST_497_0[] = { 272, 312, 45 };
pdex_mon_t DEXMON_497_0 = {
  .dex_number = 497,
  .name = "SERPERIOR",
  .form_name = "BASE",
  .family = 495,
  .types = GRASS_M,
  .base_stats = { .stamina = 181, .attack = 161, .defense = 204 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_497_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_497_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_498_0[] = { 221, 209 };
uint16_t CHARGED_MOVELIST_498_0[] = { 101, 24, 131 };
pdex_mon_t DEXMON_498_0 = {
  .dex_number = 498,
  .name = "TEPIG",
  .form_name = "BASE",
  .family = 498,
  .types = FIRE_M,
  .base_stats = { .stamina = 163, .attack = 115, .defense = 85 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_498_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_498_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_499_0[] = { 221, 209 };
uint16_t CHARGED_MOVELIST_499_0[] = { 101, 24, 63 };
pdex_mon_t DEXMON_499_0 = {
  .dex_number = 499,
  .name = "PIGNITE",
  .form_name = "BASE",
  .family = 498,
  .types = FIGHTING_M | FIRE_M,
  .base_stats = { .stamina = 207, .attack = 173, .defense = 106 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_499_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_499_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_500_0[] = { 207, 209 };
uint16_t CHARGED_MOVELIST_500_0[] = { 42, 64, 247 };
pdex_mon_t DEXMON_500_0 = {
  .dex_number = 500,
  .name = "EMBOAR",
  .form_name = "BASE",
  .family = 498,
  .types = FIGHTING_M | FIRE_M,
  .base_stats = { .stamina = 242, .attack = 235, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_500_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_500_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_501_0[] = { 221, 230 };
uint16_t CHARGED_MOVELIST_501_0[] = { 58, 105, 51 };
pdex_mon_t DEXMON_501_0 = {
  .dex_number = 501,
  .name = "OSHAWOTT",
  .form_name = "BASE",
  .family = 501,
  .types = WATER_M,
  .base_stats = { .stamina = 146, .attack = 117, .defense = 85 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_501_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_501_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_502_0[] = { 200, 230 };
uint16_t CHARGED_MOVELIST_502_0[] = { 58, 105, 100 };
pdex_mon_t DEXMON_502_0 = {
  .dex_number = 502,
  .name = "DEWOTT",
  .form_name = "BASE",
  .family = 501,
  .types = WATER_M,
  .base_stats = { .stamina = 181, .attack = 159, .defense = 116 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_502_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_502_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_503_0[] = { 200, 283 };
uint16_t CHARGED_MOVELIST_503_0[] = { 107, 40, 22 };
pdex_mon_t DEXMON_503_0 = {
  .dex_number = 503,
  .name = "SAMUROTT",
  .form_name = "BASE",
  .family = 501,
  .types = WATER_M,
  .base_stats = { .stamina = 216, .attack = 212, .defense = 157 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_503_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_503_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_504_0[] = { 221, 202 };
uint16_t CHARGED_MOVELIST_504_0[] = { 26, 129, 272 };
pdex_mon_t DEXMON_504_0 = {
  .dex_number = 504,
  .name = "PATRAT",
  .form_name = "BASE",
  .family = 504,
  .types = NORMAL_M,
  .base_stats = { .stamina = 128, .attack = 98, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_504_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_504_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_505_0[] = { 207, 202 };
uint16_t CHARGED_MOVELIST_505_0[] = { 279, 129, 272 };
pdex_mon_t DEXMON_505_0 = {
  .dex_number = 505,
  .name = "WATCHOG",
  .form_name = "BASE",
  .family = 504,
  .types = NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 165, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_505_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_505_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_506_0[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_506_0[] = { 79, 63, 26 };
pdex_mon_t DEXMON_506_0 = {
  .dex_number = 506,
  .name = "LILLIPUP",
  .form_name = "BASE",
  .family = 506,
  .types = NORMAL_M,
  .base_stats = { .stamina = 128, .attack = 107, .defense = 86 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_506_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_506_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_507_0[] = { 212, 282 };
uint16_t CHARGED_MOVELIST_507_0[] = { 79, 88, 26 };
pdex_mon_t DEXMON_507_0 = {
  .dex_number = 507,
  .name = "HERDIER",
  .form_name = "BASE",
  .family = 506,
  .types = NORMAL_M,
  .base_stats = { .stamina = 163, .attack = 145, .defense = 126 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_507_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_507_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_508_0[] = { 212, 282, 327 };
uint16_t CHARGED_MOVELIST_508_0[] = { 251, 88, 279 };
pdex_mon_t DEXMON_508_0 = {
  .dex_number = 508,
  .name = "STOUTLAND",
  .form_name = "BASE",
  .family = 506,
  .types = NORMAL_M,
  .base_stats = { .stamina = 198, .attack = 206, .defense = 182 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_508_0,
  .fast_moves_cnt = 3,
  .charged_move_ids = CHARGED_MOVELIST_508_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_509_0[] = { 220, 203 };
uint16_t CHARGED_MOVELIST_509_0[] = { 51, 88, 16 };
pdex_mon_t DEXMON_509_0 = {
  .dex_number = 509,
  .name = "PURRLOIN",
  .form_name = "BASE",
  .family = 509,
  .types = DARK_M,
  .base_stats = { .stamina = 121, .attack = 98, .defense = 73 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_509_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_509_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_510_0[] = { 320, 278 };
uint16_t CHARGED_MOVELIST_510_0[] = { 92, 88, 16 };
pdex_mon_t DEXMON_510_0 = {
  .dex_number = 510,
  .name = "LIEPARD",
  .form_name = "BASE",
  .family = 509,
  .types = DARK_M,
  .base_stats = { .stamina = 162, .attack = 187, .defense = 106 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_510_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_510_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_511_0[] = { 220, 214 };
uint16_t CHARGED_MOVELIST_511_0[] = { 273, 59, 279 };
pdex_mon_t DEXMON_511_0 = {
  .dex_number = 511,
  .name = "PANSAGE",
  .form_name = "BASE",
  .family = 511,
  .types = GRASS_M,
  .base_stats = { .stamina = 137, .attack = 104, .defense = 94 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_511_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_511_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_512_0[] = { 202, 214 };
uint16_t CHARGED_MOVELIST_512_0[] = { 116, 272, 279 };
pdex_mon_t DEXMON_512_0 = {
  .dex_number = 512,
  .name = "SIMISAGE",
  .form_name = "BASE",
  .family = 511,
  .types = GRASS_M,
  .base_stats = { .stamina = 181, .attack = 206, .defense = 133 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_512_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_512_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_513_0[] = { 220, 269 };
uint16_t CHARGED_MOVELIST_513_0[] = { 102, 101, 279 };
pdex_mon_t DEXMON_513_0 = {
  .dex_number = 513,
  .name = "PANSEAR",
  .form_name = "BASE",
  .family = 513,
  .types = FIRE_M,
  .base_stats = { .stamina = 137, .attack = 104, .defense = 94 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_513_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_513_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_514_0[] = { 202, 269 };
uint16_t CHARGED_MOVELIST_514_0[] = { 24, 103, 279 };
pdex_mon_t DEXMON_514_0 = {
  .dex_number = 514,
  .name = "SIMISEAR",
  .form_name = "BASE",
  .family = 513,
  .types = FIRE_M,
  .base_stats = { .stamina = 181, .attack = 206, .defense = 133 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_514_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_514_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_515_0[] = { 220, 230 };
uint16_t CHARGED_MOVELIST_515_0[] = { 284, 105, 279 };
pdex_mon_t DEXMON_515_0 = {
  .dex_number = 515,
  .name = "PANPOUR",
  .form_name = "BASE",
  .family = 515,
  .types = WATER_M,
  .base_stats = { .stamina = 137, .attack = 104, .defense = 94 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_515_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_515_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_516_0[] = { 202, 230 };
uint16_t CHARGED_MOVELIST_516_0[] = { 284, 107, 279 };
pdex_mon_t DEXMON_516_0 = {
  .dex_number = 516,
  .name = "SIMIPOUR",
  .form_name = "BASE",
  .family = 515,
  .types = WATER_M,
  .base_stats = { .stamina = 181, .attack = 206, .defense = 133 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_516_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_516_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_517_0[] = { 234, 249 };
uint16_t CHARGED_MOVELIST_517_0[] = { 30, 86, 60 };
pdex_mon_t DEXMON_517_0 = {
  .dex_number = 517,
  .name = "MUNNA",
  .form_name = "BASE",
  .family = 517,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 183, .attack = 111, .defense = 92 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_517_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_517_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_518_0[] = { 234, 249 };
uint16_t CHARGED_MOVELIST_518_0[] = { 275, 86, 60 };
pdex_mon_t DEXMON_518_0 = {
  .dex_number = 518,
  .name = "MUSHARNA",
  .form_name = "BASE",
  .family = 517,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 253, .attack = 183, .defense = 166 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_518_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_518_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_519_0[] = { 219, 255 };
uint16_t CHARGED_MOVELIST_519_0[] = { 42, 45, 121 };
pdex_mon_t DEXMON_519_0 = {
  .dex_number = 519,
  .name = "PIDOVE",
  .form_name = "BASE",
  .family = 519,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 137, .attack = 98, .defense = 80 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_519_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_519_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_520_0[] = { 255, 239 };
uint16_t CHARGED_MOVELIST_520_0[] = { 42, 45, 257 };
pdex_mon_t DEXMON_520_0 = {
  .dex_number = 520,
  .name = "TRANQUILL",
  .form_name = "BASE",
  .family = 519,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 158, .attack = 144, .defense = 107 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_520_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_520_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_521_0[] = { 255, 239 };
uint16_t CHARGED_MOVELIST_521_0[] = { 42, 14, 257 };
pdex_mon_t DEXMON_521_0 = {
  .dex_number = 521,
  .name = "UNFEZANT",
  .form_name = "BASE",
  .family = 519,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 226, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_521_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_521_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_522_0[] = { 219, 206 };
uint16_t CHARGED_MOVELIST_522_0[] = { 101, 35, 79 };
pdex_mon_t DEXMON_522_0 = {
  .dex_number = 522,
  .name = "BLITZLE",
  .form_name = "BASE",
  .family = 522,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 128, .attack = 118, .defense = 64 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_522_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_522_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_523_0[] = { 207, 206 };
uint16_t CHARGED_MOVELIST_523_0[] = { 101, 35, 251 };
pdex_mon_t DEXMON_523_0 = {
  .dex_number = 523,
  .name = "ZEBSTRIKA",
  .form_name = "BASE",
  .family = 522,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 181, .attack = 211, .defense = 136 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_523_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_523_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_524_0[] = { 221, 297 };
uint16_t CHARGED_MOVELIST_524_0[] = { 95, 259, 32 };
pdex_mon_t DEXMON_524_0 = {
  .dex_number = 524,
  .name = "ROGGENROLA",
  .form_name = "BASE",
  .family = 524,
  .types = ROCK_M,
  .base_stats = { .stamina = 146, .attack = 121, .defense = 110 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_524_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_524_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_525_0[] = { 233, 297 };
uint16_t CHARGED_MOVELIST_525_0[] = { 64, 95, 32 };
pdex_mon_t DEXMON_525_0 = {
  .dex_number = 525,
  .name = "BOLDORE",
  .form_name = "BASE",
  .family = 524,
  .types = ROCK_M,
  .base_stats = { .stamina = 172, .attack = 174, .defense = 143 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_525_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_525_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_526_0[] = { 233, 297 };
uint16_t CHARGED_MOVELIST_526_0[] = { 64, 116, 310, 268 };
pdex_mon_t DEXMON_526_0 = {
  .dex_number = 526,
  .name = "GIGALITH",
  .form_name = "BASE",
  .family = 524,
  .types = ROCK_M,
  .base_stats = { .stamina = 198, .attack = 226, .defense = 201 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_526_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_526_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_527_0[] = { 235, 255 };
uint16_t CHARGED_MOVELIST_527_0[] = { 121, 45, 60 };
pdex_mon_t DEXMON_527_0 = {
  .dex_number = 527,
  .name = "WOOBAT",
  .form_name = "BASE",
  .family = 527,
  .types = FLYING_M | PSYCHIC_M,
  .base_stats = { .stamina = 163, .attack = 107, .defense = 85 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_527_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_527_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_528_0[] = { 235, 255 };
uint16_t CHARGED_MOVELIST_528_0[] = { 108, 45, 275 };
pdex_mon_t DEXMON_528_0 = {
  .dex_number = 528,
  .name = "SWOOBAT",
  .form_name = "BASE",
  .family = 527,
  .types = FLYING_M | PSYCHIC_M,
  .base_stats = { .stamina = 167, .attack = 161, .defense = 119 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_528_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_528_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_529_0[] = { 220, 233 };
uint16_t CHARGED_MOVELIST_529_0[] = { 63, 26, 46 };
pdex_mon_t DEXMON_529_0 = {
  .dex_number = 529,
  .name = "DRILBUR",
  .form_name = "BASE",
  .family = 529,
  .types = GROUND_M,
  .base_stats = { .stamina = 155, .attack = 154, .defense = 85 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_529_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_529_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_530_0[] = { 228, 233 };
uint16_t CHARGED_MOVELIST_530_0[] = { 64, 31, 46, 74 };
pdex_mon_t DEXMON_530_0 = {
  .dex_number = 530,
  .name = "EXCADRILL",
  .form_name = "BASE",
  .family = 529,
  .types = GROUND_M | STEEL_M,
  .base_stats = { .stamina = 242, .attack = 255, .defense = 129 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_530_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_530_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_531_0[] = { 222, 234 };
uint16_t CHARGED_MOVELIST_531_0[] = { 84, 86, 14 };
pdex_mon_t DEXMON_531_0 = {
  .dex_number = 531,
  .name = "AUDINO",
  .form_name = "BASE",
  .family = 531,
  .types = NORMAL_M,
  .base_stats = { .stamina = 230, .attack = 114, .defense = 163 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_531_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_531_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_532_0[] = { 207, 222 };
uint16_t CHARGED_MOVELIST_532_0[] = { 56, 123, 63 };
pdex_mon_t DEXMON_532_0 = {
  .dex_number = 532,
  .name = "TIMBURR",
  .form_name = "BASE",
  .family = 532,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 181, .attack = 134, .defense = 87 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_532_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_532_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_533_0[] = { 207, 224 };
uint16_t CHARGED_MOVELIST_533_0[] = { 56, 123, 32 };
pdex_mon_t DEXMON_533_0 = {
  .dex_number = 533,
  .name = "GURDURR",
  .form_name = "BASE",
  .family = 532,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 198, .attack = 180, .defense = 134 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_533_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_533_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_534_0[] = { 243, 224 };
uint16_t CHARGED_MOVELIST_534_0[] = { 246, 247, 32 };
pdex_mon_t DEXMON_534_0 = {
  .dex_number = 534,
  .name = "CONKELDURR",
  .form_name = "BASE",
  .family = 532,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 233, .attack = 243, .defense = 158 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_534_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_534_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_535_0[] = { 216, 237 };
uint16_t CHARGED_MOVELIST_535_0[] = { 105, 96, 91 };
pdex_mon_t DEXMON_535_0 = {
  .dex_number = 535,
  .name = "TYMPOLE",
  .form_name = "BASE",
  .family = 535,
  .types = WATER_M,
  .base_stats = { .stamina = 137, .attack = 98, .defense = 78 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_535_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_535_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_536_0[] = { 216, 237 };
uint16_t CHARGED_MOVELIST_536_0[] = { 105, 304, 91 };
pdex_mon_t DEXMON_536_0 = {
  .dex_number = 536,
  .name = "PALPITOAD",
  .form_name = "BASE",
  .family = 535,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 181, .attack = 128, .defense = 109 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_536_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_536_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_537_0[] = { 216, 237 };
uint16_t CHARGED_MOVELIST_537_0[] = { 316, 304, 90 };
pdex_mon_t DEXMON_537_0 = {
  .dex_number = 537,
  .name = "SEISMITOAD",
  .form_name = "BASE",
  .family = 535,
  .types = GROUND_M | WATER_M,
  .base_stats = { .stamina = 233, .attack = 188, .defense = 150 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_537_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_537_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_538_0[] = { 207, 234 };
uint16_t CHARGED_MOVELIST_538_0[] = { 247, 56, 131 };
pdex_mon_t DEXMON_538_0 = {
  .dex_number = 538,
  .name = "THROH",
  .form_name = "BASE",
  .family = 538,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 260, .attack = 172, .defense = 160 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_538_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_538_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_539_0[] = { 207, 224 };
uint16_t CHARGED_MOVELIST_539_0[] = { 247, 56, 131 };
pdex_mon_t DEXMON_539_0 = {
  .dex_number = 539,
  .name = "SAWK",
  .form_name = "BASE",
  .family = 539,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 181, .attack = 231, .defense = 153 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_539_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_539_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_540_0[] = { 261, 201 };
uint16_t CHARGED_MOVELIST_540_0[] = { 273, 59, 262 };
pdex_mon_t DEXMON_540_0 = {
  .dex_number = 540,
  .name = "SEWADDLE",
  .form_name = "BASE",
  .family = 540,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 128, .attack = 96, .defense = 124 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_540_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_540_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_541_0[] = { 261, 201 };
uint16_t CHARGED_MOVELIST_541_0[] = { 273, 49, 262 };
pdex_mon_t DEXMON_541_0 = {
  .dex_number = 541,
  .name = "SWADLOON",
  .form_name = "BASE",
  .family = 540,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 146, .attack = 115, .defense = 162 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_541_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_541_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_542_0[] = { 215, 201 };
uint16_t CHARGED_MOVELIST_542_0[] = { 117, 100, 262 };
pdex_mon_t DEXMON_542_0 = {
  .dex_number = 542,
  .name = "LEAVANNY",
  .form_name = "BASE",
  .family = 540,
  .types = BUG_M | GRASS_M,
  .base_stats = { .stamina = 181, .attack = 205, .defense = 165 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_542_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_542_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_543_0[] = { 201, 236 };
uint16_t CHARGED_MOVELIST_543_0[] = { 99, 90, 267 };
pdex_mon_t DEXMON_543_0 = {
  .dex_number = 543,
  .name = "VENIPEDE",
  .form_name = "BASE",
  .family = 543,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 102, .attack = 83, .defense = 99 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_543_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_543_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_544_0[] = { 201, 236 };
uint16_t CHARGED_MOVELIST_544_0[] = { 99, 90, 267 };
pdex_mon_t DEXMON_544_0 = {
  .dex_number = 544,
  .name = "WHIRLIPEDE",
  .form_name = "BASE",
  .family = 543,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 120, .attack = 100, .defense = 173 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_544_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_544_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_545_0[] = { 201, 224 };
uint16_t CHARGED_MOVELIST_545_0[] = { 22, 90, 267, 100 };
pdex_mon_t DEXMON_545_0 = {
  .dex_number = 545,
  .name = "SCOLIPEDE",
  .form_name = "BASE",
  .family = 543,
  .types = BUG_M | POISON_M,
  .base_stats = { .stamina = 155, .attack = 203, .defense = 175 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_545_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_545_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_546_0[] = { 320, 215 };
uint16_t CHARGED_MOVELIST_546_0[] = { 273, 59, 272 };
pdex_mon_t DEXMON_546_0 = {
  .dex_number = 546,
  .name = "COTTONEE",
  .form_name = "BASE",
  .family = 546,
  .types = FAIRY_M | GRASS_M,
  .base_stats = { .stamina = 120, .attack = 71, .defense = 111 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_546_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_546_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_547_0[] = { 320, 215 };
uint16_t CHARGED_MOVELIST_547_0[] = { 272, 122, 87 };
pdex_mon_t DEXMON_547_0 = {
  .dex_number = 547,
  .name = "WHIMSICOTT",
  .form_name = "BASE",
  .family = 546,
  .types = FAIRY_M | GRASS_M,
  .base_stats = { .stamina = 155, .attack = 164, .defense = 176 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_547_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_547_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_548_0[] = { 320, 281 };
uint16_t CHARGED_MOVELIST_548_0[] = { 273, 59 };
pdex_mon_t DEXMON_548_0 = {
  .dex_number = 548,
  .name = "PETILIL",
  .form_name = "BASE",
  .family = 548,
  .types = GRASS_M,
  .base_stats = { .stamina = 128, .attack = 119, .defense = 91 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_548_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_548_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_549_0[] = { 320, 281 };
uint16_t CHARGED_MOVELIST_549_0[] = { 47, 14, 116 };
pdex_mon_t DEXMON_549_0 = {
  .dex_number = 549,
  .name = "LILLIGANT",
  .form_name = "BASE",
  .family = 548,
  .types = GRASS_M,
  .base_stats = { .stamina = 172, .attack = 214, .defense = 155 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_549_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_549_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_550_0[] = { 221, 230 };
uint16_t CHARGED_MOVELIST_550_0[] = { 57, 58, 316 };
uint16_t FAST_MOVELIST_550_1[] = { 221, 230 };
uint16_t CHARGED_MOVELIST_550_1[] = { 57, 58, 316 };
uint16_t FAST_MOVELIST_550_2[] = { 221, 230 };
uint16_t CHARGED_MOVELIST_550_2[] = { 57, 58, 316 };
pdex_mon_t DEXMON_550_2 = {
  .dex_number = 550,
  .name = "BASCULIN",
  .form_name = "RED_STRIPED",
  .family = 550,
  .types = WATER_M,
  .base_stats = { .stamina = 172, .attack = 189, .defense = 129 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_550_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_550_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_550_1 = {
  .dex_number = 550,
  .name = "BASCULIN",
  .form_name = "BLUE_STRIPED",
  .family = 550,
  .types = WATER_M,
  .base_stats = { .stamina = 172, .attack = 189, .defense = 129 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_550_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_550_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_550_2
};
pdex_mon_t DEXMON_550_0 = {
  .dex_number = 550,
  .name = "BASCULIN",
  .form_name = "BASE",
  .family = 550,
  .types = WATER_M,
  .base_stats = { .stamina = 172, .attack = 189, .defense = 129 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_550_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_550_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_550_1
};
uint16_t FAST_MOVELIST_551_0[] = { 202, 233 };
uint16_t CHARGED_MOVELIST_551_0[] = { 26, 279, 95 };
pdex_mon_t DEXMON_551_0 = {
  .dex_number = 551,
  .name = "SANDILE",
  .form_name = "BASE",
  .family = 551,
  .types = DARK_M | GROUND_M,
  .base_stats = { .stamina = 137, .attack = 132, .defense = 69 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_551_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_551_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_552_0[] = { 202, 233 };
uint16_t CHARGED_MOVELIST_552_0[] = { 31, 279, 95 };
pdex_mon_t DEXMON_552_0 = {
  .dex_number = 552,
  .name = "KROKOROK",
  .form_name = "BASE",
  .family = 551,
  .types = DARK_M | GROUND_M,
  .base_stats = { .stamina = 155, .attack = 155, .defense = 90 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_552_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_552_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_553_0[] = { 278, 233 };
uint16_t CHARGED_MOVELIST_553_0[] = { 31, 279, 277 };
pdex_mon_t DEXMON_553_0 = {
  .dex_number = 553,
  .name = "KROOKODILE",
  .form_name = "BASE",
  .family = 551,
  .types = DARK_M | GROUND_M,
  .base_stats = { .stamina = 216, .attack = 229, .defense = 158 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_553_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_553_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_554_0[] = { 221, 240 };
uint16_t CHARGED_MOVELIST_554_0[] = { 115, 101 };
uint16_t FAST_MOVELIST_554_1[] = { 221, 327 };
uint16_t CHARGED_MOVELIST_554_1[] = { 33, 39 };
pdex_mon_t DEXMON_554_1 = {
  .dex_number = 554,
  .name = "DARUMAKA",
  .form_name = "GALARIAN",
  .family = 554,
  .types = ICE_M,
  .base_stats = { .stamina = 172, .attack = 153, .defense = 86 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_554_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_554_1,
  .charged_moves_cnt = 2,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_554_0 = {
  .dex_number = 554,
  .name = "DARUMAKA",
  .form_name = "BASE",
  .family = 554,
  .types = FIRE_M,
  .base_stats = { .stamina = 172, .attack = 153, .defense = 86 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_554_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_554_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = & DEXMON_554_1
};
uint16_t FAST_MOVELIST_555_0[] = { 221, 240 };
uint16_t CHARGED_MOVELIST_555_0[] = { 270, 247, 108, 64 };
uint16_t FAST_MOVELIST_555_1[] = { 221, 327 };
uint16_t CHARGED_MOVELIST_555_1[] = { 270, 254, 310, 33 };
uint16_t FAST_MOVELIST_555_2[] = { 221, 327 };
uint16_t CHARGED_MOVELIST_555_2[] = { 270, 254, 310, 33 };
uint16_t FAST_MOVELIST_555_3[] = { 221, 240 };
uint16_t CHARGED_MOVELIST_555_3[] = { 270, 247, 108, 64 };
uint16_t FAST_MOVELIST_555_4[] = { 221, 240 };
uint16_t CHARGED_MOVELIST_555_4[] = { 270, 247, 108, 64 };
pdex_mon_t DEXMON_555_4 = {
  .dex_number = 555,
  .name = "DARMANITAN",
  .form_name = "ZEN",
  .family = 554,
  .types = FIRE_M | PSYCHIC_M,
  .base_stats = { .stamina = 233, .attack = 243, .defense = 202 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_555_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_555_4,
  .charged_moves_cnt = 4,
 .form_idx = 4,
  .next_form = NULL
};
pdex_mon_t DEXMON_555_3 = {
  .dex_number = 555,
  .name = "DARMANITAN",
  .form_name = "STANDARD",
  .family = 554,
  .types = FIRE_M,
  .base_stats = { .stamina = 233, .attack = 263, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_555_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_555_3,
  .charged_moves_cnt = 4,
 .form_idx = 3,
  .next_form = & DEXMON_555_4
};
pdex_mon_t DEXMON_555_2 = {
  .dex_number = 555,
  .name = "DARMANITAN",
  .form_name = "GALARIAN_ZEN",
  .family = 554,
  .types = FIRE_M | ICE_M,
  .base_stats = { .stamina = 233, .attack = 323, .defense = 123 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_555_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_555_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = & DEXMON_555_3
};
pdex_mon_t DEXMON_555_1 = {
  .dex_number = 555,
  .name = "DARMANITAN",
  .form_name = "GALARIAN_STANDARD",
  .family = 554,
  .types = ICE_M,
  .base_stats = { .stamina = 233, .attack = 263, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_555_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_555_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_555_2
};
pdex_mon_t DEXMON_555_0 = {
  .dex_number = 555,
  .name = "DARMANITAN",
  .form_name = "BASE",
  .family = 554,
  .types = FIRE_M,
  .base_stats = { .stamina = 233, .attack = 263, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_555_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_555_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_555_1
};
uint16_t FAST_MOVELIST_556_0[] = { 271, 224 };
uint16_t CHARGED_MOVELIST_556_0[] = { 45, 47, 116 };
pdex_mon_t DEXMON_556_0 = {
  .dex_number = 556,
  .name = "MARACTUS",
  .form_name = "BASE",
  .family = 556,
  .types = GRASS_M,
  .base_stats = { .stamina = 181, .attack = 201, .defense = 130 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_556_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_556_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_557_0[] = { 223, 297 };
uint16_t CHARGED_MOVELIST_557_0[] = { 259, 100, 63 };
pdex_mon_t DEXMON_557_0 = {
  .dex_number = 557,
  .name = "DWEBBLE",
  .form_name = "BASE",
  .family = 557,
  .types = BUG_M | ROCK_M,
  .base_stats = { .stamina = 137, .attack = 118, .defense = 128 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_557_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_557_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_558_0[] = { 200, 297 };
uint16_t CHARGED_MOVELIST_558_0[] = { 259, 100, 64 };
pdex_mon_t DEXMON_558_0 = {
  .dex_number = 558,
  .name = "CRUSTLE",
  .form_name = "BASE",
  .family = 557,
  .types = BUG_M | ROCK_M,
  .base_stats = { .stamina = 172, .attack = 188, .defense = 200 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_558_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_558_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_559_0[] = { 241, 238 };
uint16_t CHARGED_MOVELIST_559_0[] = { 303, 123, 280 };
pdex_mon_t DEXMON_559_0 = {
  .dex_number = 559,
  .name = "SCRAGGY",
  .form_name = "BASE",
  .family = 559,
  .types = DARK_M | FIGHTING_M,
  .base_stats = { .stamina = 137, .attack = 132, .defense = 132 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_559_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_559_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_560_0[] = { 243, 278 };
uint16_t CHARGED_MOVELIST_560_0[] = { 303, 319, 280 };
pdex_mon_t DEXMON_560_0 = {
  .dex_number = 560,
  .name = "SCRAFTY",
  .form_name = "BASE",
  .family = 559,
  .types = DARK_M | FIGHTING_M,
  .base_stats = { .stamina = 163, .attack = 163, .defense = 222 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_560_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_560_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_561_0[] = { 255, 234 };
uint16_t CHARGED_MOVELIST_561_0[] = { 121, 30, 62, 99 };
pdex_mon_t DEXMON_561_0 = {
  .dex_number = 561,
  .name = "SIGILYPH",
  .form_name = "BASE",
  .family = 561,
  .types = FLYING_M | PSYCHIC_M,
  .base_stats = { .stamina = 176, .attack = 204, .defense = 167 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_561_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_561_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_562_0[] = { 263, 234 };
uint16_t CHARGED_MOVELIST_562_0[] = { 70, 16, 69 };
pdex_mon_t DEXMON_562_0 = {
  .dex_number = 562,
  .name = "YAMASK",
  .form_name = "BASE",
  .family = 562,
  .types = GHOST_M,
  .base_stats = { .stamina = 116, .attack = 95, .defense = 141 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_562_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_562_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_563_0[] = { 263, 234 };
uint16_t CHARGED_MOVELIST_563_0[] = { 70, 16, 108 };
pdex_mon_t DEXMON_563_0 = {
  .dex_number = 563,
  .name = "COFAGRIGUS",
  .form_name = "BASE",
  .family = 562,
  .types = GHOST_M,
  .base_stats = { .stamina = 151, .attack = 163, .defense = 237 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_563_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_563_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_564_0[] = { 230, 202 };
uint16_t CHARGED_MOVELIST_564_0[] = { 284, 62, 131 };
pdex_mon_t DEXMON_564_0 = {
  .dex_number = 564,
  .name = "TIRTOUGA",
  .form_name = "BASE",
  .family = 564,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 144, .attack = 134, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_564_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_564_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_565_0[] = { 230, 227 };
uint16_t CHARGED_MOVELIST_565_0[] = { 284, 62, 131 };
pdex_mon_t DEXMON_565_0 = {
  .dex_number = 565,
  .name = "CARRACOSTA",
  .form_name = "BASE",
  .family = 564,
  .types = ROCK_M | WATER_M,
  .base_stats = { .stamina = 179, .attack = 192, .defense = 197 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_565_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_565_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_566_0[] = { 219, 210 };
uint16_t CHARGED_MOVELIST_566_0[] = { 83, 62, 279 };
pdex_mon_t DEXMON_566_0 = {
  .dex_number = 566,
  .name = "ARCHEN",
  .form_name = "BASE",
  .family = 566,
  .types = FLYING_M | ROCK_M,
  .base_stats = { .stamina = 146, .attack = 213, .defense = 89 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_566_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_566_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_567_0[] = { 239, 210 };
uint16_t CHARGED_MOVELIST_567_0[] = { 83, 62, 279 };
pdex_mon_t DEXMON_567_0 = {
  .dex_number = 567,
  .name = "ARCHEOPS",
  .form_name = "BASE",
  .family = 566,
  .types = FLYING_M | ROCK_M,
  .base_stats = { .stamina = 181, .attack = 292, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_567_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_567_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_568_0[] = { 222, 282 };
uint16_t CHARGED_MOVELIST_568_0[] = { 92, 59, 92 };
pdex_mon_t DEXMON_568_0 = {
  .dex_number = 568,
  .name = "TRUBBISH",
  .form_name = "BASE",
  .family = 568,
  .types = POISON_M,
  .base_stats = { .stamina = 137, .attack = 96, .defense = 122 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_568_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_568_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_569_0[] = { 260, 282 };
uint16_t CHARGED_MOVELIST_569_0[] = { 303, 59, 92, 131 };
pdex_mon_t DEXMON_569_0 = {
  .dex_number = 569,
  .name = "GARBODOR",
  .form_name = "BASE",
  .family = 568,
  .types = POISON_M,
  .base_stats = { .stamina = 190, .attack = 181, .defense = 164 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_569_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_569_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_570_0[] = { 220, 238 };
uint16_t CHARGED_MOVELIST_570_0[] = { 280, 45, 16 };
pdex_mon_t DEXMON_570_0 = {
  .dex_number = 570,
  .name = "ZORUA",
  .form_name = "BASE",
  .family = 570,
  .types = DARK_M,
  .base_stats = { .stamina = 120, .attack = 153, .defense = 78 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_570_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_570_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_571_0[] = { 213, 278 };
uint16_t CHARGED_MOVELIST_571_0[] = { 280, 90, 24 };
pdex_mon_t DEXMON_571_0 = {
  .dex_number = 571,
  .name = "ZOROARK",
  .form_name = "BASE",
  .family = 570,
  .types = DARK_M,
  .base_stats = { .stamina = 155, .attack = 250, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_571_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_571_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_572_0[] = { 222, 320 };
uint16_t CHARGED_MOVELIST_572_0[] = { 125, 79, 58 };
pdex_mon_t DEXMON_572_0 = {
  .dex_number = 572,
  .name = "MINCCINO",
  .form_name = "BASE",
  .family = 572,
  .types = NORMAL_M,
  .base_stats = { .stamina = 146, .attack = 98, .defense = 80 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_572_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_572_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_573_0[] = { 222, 320 };
uint16_t CHARGED_MOVELIST_573_0[] = { 14, 79, 58 };
pdex_mon_t DEXMON_573_0 = {
  .dex_number = 573,
  .name = "CINCCINO",
  .form_name = "BASE",
  .family = 572,
  .types = NORMAL_M,
  .base_stats = { .stamina = 181, .attack = 198, .defense = 130 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_573_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_573_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_574_0[] = { 222, 235 };
uint16_t CHARGED_MOVELIST_574_0[] = { 30, 60, 108 };
pdex_mon_t DEXMON_574_0 = {
  .dex_number = 574,
  .name = "GOTHITA",
  .form_name = "BASE",
  .family = 574,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 128, .attack = 98, .defense = 112 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_574_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_574_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_575_0[] = { 222, 235 };
uint16_t CHARGED_MOVELIST_575_0[] = { 30, 275, 108 };
pdex_mon_t DEXMON_575_0 = {
  .dex_number = 575,
  .name = "GOTHORITA",
  .form_name = "BASE",
  .family = 574,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 155, .attack = 137, .defense = 153 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_575_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_575_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_576_0[] = { 320, 235 };
uint16_t CHARGED_MOVELIST_576_0[] = { 64, 275, 108 };
pdex_mon_t DEXMON_576_0 = {
  .dex_number = 576,
  .name = "GOTHITELLE",
  .form_name = "BASE",
  .family = 574,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 172, .attack = 176, .defense = 205 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_576_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_576_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_577_0[] = { 281, 234 };
uint16_t CHARGED_MOVELIST_577_0[] = { 60, 265, 78 };
pdex_mon_t DEXMON_577_0 = {
  .dex_number = 577,
  .name = "SOLOSIS",
  .form_name = "BASE",
  .family = 577,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 128, .attack = 170, .defense = 83 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_577_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_577_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_578_0[] = { 281, 234 };
uint16_t CHARGED_MOVELIST_578_0[] = { 60, 265, 78 };
pdex_mon_t DEXMON_578_0 = {
  .dex_number = 578,
  .name = "DUOSION",
  .form_name = "BASE",
  .family = 577,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 163, .attack = 208, .defense = 103 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_578_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_578_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_579_0[] = { 281, 234 };
uint16_t CHARGED_MOVELIST_579_0[] = { 275, 70, 78 };
pdex_mon_t DEXMON_579_0 = {
  .dex_number = 579,
  .name = "REUNICLUS",
  .form_name = "BASE",
  .family = 577,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 242, .attack = 214, .defense = 148 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_579_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_579_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_580_0[] = { 230, 210 };
uint16_t CHARGED_MOVELIST_580_0[] = { 45, 53, 256 };
pdex_mon_t DEXMON_580_0 = {
  .dex_number = 580,
  .name = "DUCKLETT",
  .form_name = "BASE",
  .family = 580,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 158, .attack = 84, .defense = 96 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_580_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_580_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_581_0[] = { 230, 255 };
uint16_t CHARGED_MOVELIST_581_0[] = { 39, 53, 122 };
pdex_mon_t DEXMON_581_0 = {
  .dex_number = 581,
  .name = "SWANNA",
  .form_name = "BASE",
  .family = 580,
  .types = FLYING_M | WATER_M,
  .base_stats = { .stamina = 181, .attack = 182, .defense = 132 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_581_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_581_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_582_0[] = { 244, 263 };
uint16_t CHARGED_MOVELIST_582_0[] = { 111, 39, 99 };
pdex_mon_t DEXMON_582_0 = {
  .dex_number = 582,
  .name = "VANILLITE",
  .form_name = "BASE",
  .family = 582,
  .types = ICE_M,
  .base_stats = { .stamina = 113, .attack = 118, .defense = 106 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_582_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_582_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_583_0[] = { 218, 263 };
uint16_t CHARGED_MOVELIST_583_0[] = { 111, 39, 99 };
pdex_mon_t DEXMON_583_0 = {
  .dex_number = 583,
  .name = "VANILLISH",
  .form_name = "BASE",
  .family = 582,
  .types = ICE_M,
  .base_stats = { .stamina = 139, .attack = 151, .defense = 138 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_583_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_583_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_584_0[] = { 218, 263 };
uint16_t CHARGED_MOVELIST_584_0[] = { 40, 36, 99 };
pdex_mon_t DEXMON_584_0 = {
  .dex_number = 584,
  .name = "VANILLUXE",
  .form_name = "BASE",
  .family = 582,
  .types = ICE_M,
  .base_stats = { .stamina = 174, .attack = 218, .defense = 184 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_584_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_584_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_585_0[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_585_0[] = { 273, 59, 251 };
uint16_t FAST_MOVELIST_585_1[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_585_1[] = { 273, 59, 251 };
uint16_t FAST_MOVELIST_585_2[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_585_2[] = { 273, 59, 251 };
uint16_t FAST_MOVELIST_585_3[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_585_3[] = { 273, 59, 251 };
uint16_t FAST_MOVELIST_585_4[] = { 221, 282 };
uint16_t CHARGED_MOVELIST_585_4[] = { 273, 59, 251 };
pdex_mon_t DEXMON_585_4 = {
  .dex_number = 585,
  .name = "DEERLING",
  .form_name = "WINTER",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 115, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_585_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_585_4,
  .charged_moves_cnt = 3,
 .form_idx = 4,
  .next_form = NULL
};
pdex_mon_t DEXMON_585_3 = {
  .dex_number = 585,
  .name = "DEERLING",
  .form_name = "SUMMER",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 115, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_585_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_585_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = & DEXMON_585_4
};
pdex_mon_t DEXMON_585_2 = {
  .dex_number = 585,
  .name = "DEERLING",
  .form_name = "SPRING",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 115, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_585_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_585_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_585_3
};
pdex_mon_t DEXMON_585_1 = {
  .dex_number = 585,
  .name = "DEERLING",
  .form_name = "AUTUMN",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 115, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_585_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_585_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_585_2
};
pdex_mon_t DEXMON_585_0 = {
  .dex_number = 585,
  .name = "DEERLING",
  .form_name = "BASE",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 155, .attack = 115, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_585_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_585_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_585_1
};
uint16_t FAST_MOVELIST_586_0[] = { 238, 282 };
uint16_t CHARGED_MOVELIST_586_0[] = { 22, 116, 251, 14 };
uint16_t FAST_MOVELIST_586_1[] = { 238, 282 };
uint16_t CHARGED_MOVELIST_586_1[] = { 22, 116, 251, 14 };
uint16_t FAST_MOVELIST_586_2[] = { 238, 282 };
uint16_t CHARGED_MOVELIST_586_2[] = { 22, 116, 251, 14 };
uint16_t FAST_MOVELIST_586_3[] = { 238, 282 };
uint16_t CHARGED_MOVELIST_586_3[] = { 22, 116, 251, 14 };
uint16_t FAST_MOVELIST_586_4[] = { 238, 282 };
uint16_t CHARGED_MOVELIST_586_4[] = { 22, 116, 251, 14 };
pdex_mon_t DEXMON_586_4 = {
  .dex_number = 586,
  .name = "SAWSBUCK",
  .form_name = "WINTER",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_586_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_586_4,
  .charged_moves_cnt = 4,
 .form_idx = 4,
  .next_form = NULL
};
pdex_mon_t DEXMON_586_3 = {
  .dex_number = 586,
  .name = "SAWSBUCK",
  .form_name = "SUMMER",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_586_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_586_3,
  .charged_moves_cnt = 4,
 .form_idx = 3,
  .next_form = & DEXMON_586_4
};
pdex_mon_t DEXMON_586_2 = {
  .dex_number = 586,
  .name = "SAWSBUCK",
  .form_name = "SPRING",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_586_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_586_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = & DEXMON_586_3
};
pdex_mon_t DEXMON_586_1 = {
  .dex_number = 586,
  .name = "SAWSBUCK",
  .form_name = "AUTUMN",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_586_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_586_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_586_2
};
pdex_mon_t DEXMON_586_0 = {
  .dex_number = 586,
  .name = "SAWSBUCK",
  .form_name = "BASE",
  .family = 585,
  .types = GRASS_M | NORMAL_M,
  .base_stats = { .stamina = 190, .attack = 198, .defense = 146 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_586_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_586_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_586_1
};
uint16_t FAST_MOVELIST_587_0[] = { 205, 219 };
uint16_t CHARGED_MOVELIST_587_0[] = { 35, 45, 79 };
pdex_mon_t DEXMON_587_0 = {
  .dex_number = 587,
  .name = "EMOLGA",
  .form_name = "BASE",
  .family = 587,
  .types = ELECTRIC_M | FLYING_M,
  .base_stats = { .stamina = 146, .attack = 158, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_587_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_587_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_588_0[] = { 211, 200 };
uint16_t CHARGED_MOVELIST_588_0[] = { 99, 100, 46, 45 };
pdex_mon_t DEXMON_588_0 = {
  .dex_number = 588,
  .name = "KARRABLAST",
  .form_name = "BASE",
  .family = 588,
  .types = BUG_M,
  .base_stats = { .stamina = 137, .attack = 137, .defense = 87 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_588_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_588_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_589_0[] = { 243, 201 };
uint16_t CHARGED_MOVELIST_589_0[] = { 22, 303, 46, 45 };
pdex_mon_t DEXMON_589_0 = {
  .dex_number = 589,
  .name = "ESCAVALIER",
  .form_name = "BASE",
  .family = 588,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 172, .attack = 223, .defense = 187 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_589_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_589_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_590_0[] = { 263, 238 };
uint16_t CHARGED_MOVELIST_590_0[] = { 273, 131, 272 };
pdex_mon_t DEXMON_590_0 = {
  .dex_number = 590,
  .name = "FOONGUS",
  .form_name = "BASE",
  .family = 590,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 170, .attack = 97, .defense = 91 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_590_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_590_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_591_0[] = { 263, 238 };
uint16_t CHARGED_MOVELIST_591_0[] = { 280, 90, 272 };
pdex_mon_t DEXMON_591_0 = {
  .dex_number = 591,
  .name = "AMOONGUSS",
  .form_name = "BASE",
  .family = 590,
  .types = GRASS_M | POISON_M,
  .base_stats = { .stamina = 249, .attack = 155, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_591_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_591_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_592_0[] = { 237, 264 };
uint16_t CHARGED_MOVELIST_592_0[] = { 265, 39, 69 };
uint16_t FAST_MOVELIST_592_1[] = { 237, 264 };
uint16_t CHARGED_MOVELIST_592_1[] = { 265, 39, 69 };
pdex_mon_t DEXMON_592_1 = {
  .dex_number = 592,
  .name = "FRILLISH",
  .form_name = "FEMALE",
  .family = 592,
  .types = GHOST_M | WATER_M,
  .base_stats = { .stamina = 146, .attack = 115, .defense = 134 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_592_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_592_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_592_0 = {
  .dex_number = 592,
  .name = "FRILLISH",
  .form_name = "BASE",
  .family = 592,
  .types = GHOST_M | WATER_M,
  .base_stats = { .stamina = 146, .attack = 115, .defense = 134 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_592_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_592_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_592_1
};
uint16_t FAST_MOVELIST_593_0[] = { 237, 264 };
uint16_t CHARGED_MOVELIST_593_0[] = { 70, 39, 53 };
uint16_t FAST_MOVELIST_593_1[] = { 237, 264 };
uint16_t CHARGED_MOVELIST_593_1[] = { 70, 39, 53 };
pdex_mon_t DEXMON_593_1 = {
  .dex_number = 593,
  .name = "JELLICENT",
  .form_name = "FEMALE",
  .family = 592,
  .types = GHOST_M | WATER_M,
  .base_stats = { .stamina = 225, .attack = 159, .defense = 178 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_593_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_593_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_593_0 = {
  .dex_number = 593,
  .name = "JELLICENT",
  .form_name = "BASE",
  .family = 592,
  .types = GHOST_M | WATER_M,
  .base_stats = { .stamina = 225, .attack = 159, .defense = 178 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_593_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_593_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_593_1
};
uint16_t FAST_MOVELIST_594_0[] = { 283, 281 };
uint16_t CHARGED_MOVELIST_594_0[] = { 107, 40, 108 };
pdex_mon_t DEXMON_594_0 = {
  .dex_number = 594,
  .name = "ALOMOMOLA",
  .form_name = "BASE",
  .family = 594,
  .types = WATER_M,
  .base_stats = { .stamina = 338, .attack = 138, .defense = 131 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_594_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_594_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_595_0[] = { 249, 203 };
uint16_t CHARGED_MOVELIST_595_0[] = { 89, 49, 35 };
pdex_mon_t DEXMON_595_0 = {
  .dex_number = 595,
  .name = "JOLTIK",
  .form_name = "BASE",
  .family = 595,
  .types = BUG_M | ELECTRIC_M,
  .base_stats = { .stamina = 137, .attack = 110, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_595_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_595_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_596_0[] = { 250, 200 };
uint16_t CHARGED_MOVELIST_596_0[] = { 89, 49, 35, 273 };
pdex_mon_t DEXMON_596_0 = {
  .dex_number = 596,
  .name = "GALVANTULA",
  .form_name = "BASE",
  .family = 595,
  .types = BUG_M | ELECTRIC_M,
  .base_stats = { .stamina = 172, .attack = 201, .defense = 128 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_596_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_596_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_597_0[] = { 221, 228 };
uint16_t CHARGED_MOVELIST_597_0[] = { 267, 36, 74 };
pdex_mon_t DEXMON_597_0 = {
  .dex_number = 597,
  .name = "FERROSEED",
  .form_name = "BASE",
  .family = 597,
  .types = GRASS_M | STEEL_M,
  .base_stats = { .stamina = 127, .attack = 82, .defense = 155 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_597_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_597_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_598_0[] = { 271, 228 };
uint16_t CHARGED_MOVELIST_598_0[] = { 118, 36, 303, 78, 309 };
pdex_mon_t DEXMON_598_0 = {
  .dex_number = 598,
  .name = "FERROTHORN",
  .form_name = "BASE",
  .family = 597,
  .types = GRASS_M | STEEL_M,
  .base_stats = { .stamina = 179, .attack = 158, .defense = 223 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_598_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_598_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_599_0[] = { 250, 249 };
uint16_t CHARGED_MOVELIST_599_0[] = { 20, 35, 252 };
pdex_mon_t DEXMON_599_0 = {
  .dex_number = 599,
  .name = "KLINK",
  .form_name = "BASE",
  .family = 599,
  .types = STEEL_M,
  .base_stats = { .stamina = 120, .attack = 98, .defense = 121 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_599_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_599_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_600_0[] = { 205, 249 };
uint16_t CHARGED_MOVELIST_600_0[] = { 20, 79, 252 };
pdex_mon_t DEXMON_600_0 = {
  .dex_number = 600,
  .name = "KLANG",
  .form_name = "BASE",
  .family = 599,
  .types = STEEL_M,
  .base_stats = { .stamina = 155, .attack = 150, .defense = 174 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_600_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_600_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_601_0[] = { 205, 249 };
uint16_t CHARGED_MOVELIST_601_0[] = { 14, 36, 252, 309 };
pdex_mon_t DEXMON_601_0 = {
  .dex_number = 601,
  .name = "KLINKLANG",
  .form_name = "BASE",
  .family = 601,
  .types = STEEL_M,
  .base_stats = { .stamina = 155, .attack = 199, .defense = 214 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_601_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_601_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_602_0[] = { 221, 206 };
uint16_t CHARGED_MOVELIST_602_0[] = { 133 };
pdex_mon_t DEXMON_602_0 = {
  .dex_number = 602,
  .name = "TYNAMO",
  .form_name = "BASE",
  .family = 602,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 111, .attack = 105, .defense = 78 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_602_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_602_0,
  .charged_moves_cnt = 1,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_603_0[] = { 225, 206 };
uint16_t CHARGED_MOVELIST_603_0[] = { 279, 79, 35 };
pdex_mon_t DEXMON_603_0 = {
  .dex_number = 603,
  .name = "EELEKTRIK",
  .form_name = "BASE",
  .family = 602,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 163, .attack = 156, .defense = 130 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_603_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_603_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_604_0[] = { 225, 206 };
uint16_t CHARGED_MOVELIST_604_0[] = { 279, 79, 303, 83 };
pdex_mon_t DEXMON_604_0 = {
  .dex_number = 604,
  .name = "EELEKTROSS",
  .form_name = "BASE",
  .family = 602,
  .types = ELECTRIC_M,
  .base_stats = { .stamina = 198, .attack = 217, .defense = 152 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_604_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_604_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_605_0[] = { 235, 263 };
uint16_t CHARGED_MOVELIST_605_0[] = { 30, 16, 108 };
pdex_mon_t DEXMON_605_0 = {
  .dex_number = 605,
  .name = "ELGYEM",
  .form_name = "BASE",
  .family = 605,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 146, .attack = 148, .defense = 100 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_605_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_605_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_606_0[] = { 235, 263 };
uint16_t CHARGED_MOVELIST_606_0[] = { 64, 16, 108 };
pdex_mon_t DEXMON_606_0 = {
  .dex_number = 606,
  .name = "BEHEEYEM",
  .form_name = "BASE",
  .family = 605,
  .types = PSYCHIC_M,
  .base_stats = { .stamina = 181, .attack = 221, .defense = 163 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_606_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_606_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_607_0[] = { 263, 209 };
uint16_t CHARGED_MOVELIST_607_0[] = { 101, 102, 42 };
pdex_mon_t DEXMON_607_0 = {
  .dex_number = 607,
  .name = "LITWICK",
  .form_name = "BASE",
  .family = 607,
  .types = FIRE_M | GHOST_M,
  .base_stats = { .stamina = 137, .attack = 108, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_607_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_607_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_608_0[] = { 263, 209 };
uint16_t CHARGED_MOVELIST_608_0[] = { 273, 102, 42 };
pdex_mon_t DEXMON_608_0 = {
  .dex_number = 608,
  .name = "LAMPENT",
  .form_name = "BASE",
  .family = 607,
  .types = FIRE_M | GHOST_M,
  .base_stats = { .stamina = 155, .attack = 169, .defense = 115 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_608_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_608_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_609_0[] = { 264, 269 };
uint16_t CHARGED_MOVELIST_609_0[] = { 273, 70, 270 };
pdex_mon_t DEXMON_609_0 = {
  .dex_number = 609,
  .name = "CHANDELURE",
  .form_name = "BASE",
  .family = 607,
  .types = FIRE_M | GHOST_M,
  .base_stats = { .stamina = 155, .attack = 271, .defense = 182 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_609_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_609_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_610_0[] = { 220, 266 };
uint16_t CHARGED_MOVELIST_610_0[] = { 83, 58, 82 };
pdex_mon_t DEXMON_610_0 = {
  .dex_number = 610,
  .name = "AXEW",
  .form_name = "BASE",
  .family = 610,
  .types = DRAGON_M,
  .base_stats = { .stamina = 130, .attack = 154, .defense = 101 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_610_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_610_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_611_0[] = { 253, 266 };
uint16_t CHARGED_MOVELIST_611_0[] = { 83, 58, 51 };
pdex_mon_t DEXMON_611_0 = {
  .dex_number = 611,
  .name = "FRAXURE",
  .form_name = "BASE",
  .family = 610,
  .types = DRAGON_M,
  .base_stats = { .stamina = 165, .attack = 212, .defense = 123 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_611_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_611_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_612_0[] = { 253, 243 };
uint16_t CHARGED_MOVELIST_612_0[] = { 83, 284, 51, 31 };
pdex_mon_t DEXMON_612_0 = {
  .dex_number = 612,
  .name = "HAXORUS",
  .form_name = "BASE",
  .family = 610,
  .types = DRAGON_M,
  .base_stats = { .stamina = 183, .attack = 284, .defense = 172 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_612_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_612_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_613_0[] = { 244, 320 };
uint16_t CHARGED_MOVELIST_613_0[] = { 33, 111, 88 };
pdex_mon_t DEXMON_613_0 = {
  .dex_number = 613,
  .name = "CUBCHOO",
  .form_name = "BASE",
  .family = 613,
  .types = ICE_M,
  .base_stats = { .stamina = 146, .attack = 128, .defense = 74 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_613_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_613_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_614_0[] = { 244, 320 };
uint16_t CHARGED_MOVELIST_614_0[] = { 33, 284, 88 };
pdex_mon_t DEXMON_614_0 = {
  .dex_number = 614,
  .name = "BEARTIC",
  .form_name = "BASE",
  .family = 613,
  .types = ICE_M,
  .base_stats = { .stamina = 216, .attack = 233, .defense = 152 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_614_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_614_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_615_0[] = { 217, 218 };
uint16_t CHARGED_MOVELIST_615_0[] = { 248, 51, 116, 105 };
pdex_mon_t DEXMON_615_0 = {
  .dex_number = 615,
  .name = "CRYOGONAL",
  .form_name = "BASE",
  .family = 615,
  .types = ICE_M,
  .base_stats = { .stamina = 190, .attack = 190, .defense = 218 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_615_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_615_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_616_0[] = { 225, 260 };
uint16_t CHARGED_MOVELIST_616_0[] = { 49, 131, 99 };
pdex_mon_t DEXMON_616_0 = {
  .dex_number = 616,
  .name = "SHELMET",
  .form_name = "BASE",
  .family = 616,
  .types = BUG_M,
  .base_stats = { .stamina = 137, .attack = 72, .defense = 140 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_616_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_616_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_617_0[] = { 225, 260 };
uint16_t CHARGED_MOVELIST_617_0[] = { 49, 303, 99, 247 };
pdex_mon_t DEXMON_617_0 = {
  .dex_number = 617,
  .name = "ACCELGOR",
  .form_name = "BASE",
  .family = 616,
  .types = BUG_M,
  .base_stats = { .stamina = 190, .attack = 220, .defense = 120 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_617_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_617_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_618_0[] = { 205, 216 };
uint16_t CHARGED_MOVELIST_618_0[] = { 96, 35, 316 };
uint16_t FAST_MOVELIST_618_1[] = { 216, 228 };
uint16_t CHARGED_MOVELIST_618_1[] = { 31, 36, 316, 64 };
pdex_mon_t DEXMON_618_1 = {
  .dex_number = 618,
  .name = "STUNFISK",
  .form_name = "GALARIAN",
  .family = 618,
  .types = GROUND_M | STEEL_M,
  .base_stats = { .stamina = 240, .attack = 144, .defense = 171 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_618_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_618_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = NULL
};
pdex_mon_t DEXMON_618_0 = {
  .dex_number = 618,
  .name = "STUNFISK",
  .form_name = "BASE",
  .family = 618,
  .types = ELECTRIC_M | GROUND_M,
  .base_stats = { .stamina = 240, .attack = 144, .defense = 171 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_618_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_618_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_618_1
};
uint16_t FAST_MOVELIST_619_0[] = { 207, 222 };
uint16_t CHARGED_MOVELIST_619_0[] = { 123, 56, 247 };
pdex_mon_t DEXMON_619_0 = {
  .dex_number = 619,
  .name = "MIENFOO",
  .form_name = "BASE",
  .family = 619,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 128, .attack = 160, .defense = 98 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_619_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_619_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_620_0[] = { 207, 224 };
uint16_t CHARGED_MOVELIST_620_0[] = { 123, 272, 32 };
pdex_mon_t DEXMON_620_0 = {
  .dex_number = 620,
  .name = "MIENSHAO",
  .form_name = "BASE",
  .family = 619,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 163, .attack = 258, .defense = 127 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_620_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_620_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_621_0[] = { 253, 202 };
uint16_t CHARGED_MOVELIST_621_0[] = { 83, 51, 14 };
pdex_mon_t DEXMON_621_0 = {
  .dex_number = 621,
  .name = "DRUDDIGON",
  .form_name = "BASE",
  .family = 621,
  .types = DRAGON_M,
  .base_stats = { .stamina = 184, .attack = 213, .defense = 170 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_621_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_621_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_622_0[] = { 263, 233 };
uint16_t CHARGED_MOVELIST_622_0[] = { 67, 123, 265 };
pdex_mon_t DEXMON_622_0 = {
  .dex_number = 622,
  .name = "GOLETT",
  .form_name = "BASE",
  .family = 622,
  .types = GHOST_M | GROUND_M,
  .base_stats = { .stamina = 153, .attack = 127, .defense = 92 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_622_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_622_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_623_0[] = { 263, 233 };
uint16_t CHARGED_MOVELIST_623_0[] = { 67, 246, 304 };
pdex_mon_t DEXMON_623_0 = {
  .dex_number = 623,
  .name = "GOLURK",
  .form_name = "BASE",
  .family = 622,
  .types = GHOST_M | GROUND_M,
  .base_stats = { .stamina = 205, .attack = 222, .defense = 154 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_623_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_623_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_624_0[] = { 220, 200 };
uint16_t CHARGED_MOVELIST_624_0[] = { 51, 74, 100 };
pdex_mon_t DEXMON_624_0 = {
  .dex_number = 624,
  .name = "PAWNIARD",
  .form_name = "BASE",
  .family = 624,
  .types = DARK_M | STEEL_M,
  .base_stats = { .stamina = 128, .attack = 154, .defense = 114 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_624_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_624_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_625_0[] = { 278, 228 };
uint16_t CHARGED_MOVELIST_625_0[] = { 16, 74, 100, 247 };
pdex_mon_t DEXMON_625_0 = {
  .dex_number = 625,
  .name = "BISHARP",
  .form_name = "BASE",
  .family = 624,
  .types = DARK_M | STEEL_M,
  .base_stats = { .stamina = 163, .attack = 232, .defense = 176 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_625_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_625_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_626_0[] = { 234, 216 };
uint16_t CHARGED_MOVELIST_626_0[] = { 22, 127, 302, 31 };
pdex_mon_t DEXMON_626_0 = {
  .dex_number = 626,
  .name = "BOUFFALANT",
  .form_name = "BASE",
  .family = 626,
  .types = NORMAL_M,
  .base_stats = { .stamina = 216, .attack = 195, .defense = 182 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_626_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_626_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_627_0[] = { 211, 210 };
uint16_t CHARGED_MOVELIST_627_0[] = { 45, 256, 63 };
pdex_mon_t DEXMON_627_0 = {
  .dex_number = 627,
  .name = "RUFFLET",
  .form_name = "BASE",
  .family = 627,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 172, .attack = 150, .defense = 97 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_627_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_627_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_628_0[] = { 239, 255 };
uint16_t CHARGED_MOVELIST_628_0[] = { 42, 256, 64 };
pdex_mon_t DEXMON_628_0 = {
  .dex_number = 628,
  .name = "BRAVIARY",
  .form_name = "BASE",
  .family = 627,
  .types = FLYING_M | NORMAL_M,
  .base_stats = { .stamina = 225, .attack = 232, .defense = 152 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_628_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_628_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_629_0[] = { 238, 255 };
uint16_t CHARGED_MOVELIST_629_0[] = { 16, 256, 280 };
pdex_mon_t DEXMON_629_0 = {
  .dex_number = 629,
  .name = "VULLABY",
  .form_name = "BASE",
  .family = 629,
  .types = DARK_M | FLYING_M,
  .base_stats = { .stamina = 172, .attack = 105, .defense = 139 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_629_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_629_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_630_0[] = { 278, 255 };
uint16_t CHARGED_MOVELIST_630_0[] = { 16, 45, 280, 70 };
pdex_mon_t DEXMON_630_0 = {
  .dex_number = 630,
  .name = "MANDIBUZZ",
  .form_name = "BASE",
  .family = 629,
  .types = DARK_M | FLYING_M,
  .base_stats = { .stamina = 242, .attack = 129, .defense = 205 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_630_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_630_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_631_0[] = { 212, 269 };
uint16_t CHARGED_MOVELIST_631_0[] = { 24, 77, 319 };
pdex_mon_t DEXMON_631_0 = {
  .dex_number = 631,
  .name = "HEATMOR",
  .form_name = "BASE",
  .family = 631,
  .types = FIRE_M,
  .base_stats = { .stamina = 198, .attack = 204, .defense = 129 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_631_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_631_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_632_0[] = { 201, 228 };
uint16_t CHARGED_MOVELIST_632_0[] = { 100, 74, 32 };
pdex_mon_t DEXMON_632_0 = {
  .dex_number = 632,
  .name = "DURANT",
  .form_name = "BASE",
  .family = 632,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 151, .attack = 217, .defense = 188 },
  .tags = TAG_REGIONAL_M,
  .fast_move_ids = FAST_MOVELIST_632_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_632_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_633_0[] = { 221, 204 };
uint16_t CHARGED_MOVELIST_633_0[] = { 82, 279, 131 };
pdex_mon_t DEXMON_633_0 = {
  .dex_number = 633,
  .name = "DEINO",
  .form_name = "BASE",
  .family = 633,
  .types = DARK_M | DRAGON_M,
  .base_stats = { .stamina = 141, .attack = 116, .defense = 93 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_633_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_633_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_634_0[] = { 202, 204 };
uint16_t CHARGED_MOVELIST_634_0[] = { 82, 16, 131 };
pdex_mon_t DEXMON_634_0 = {
  .dex_number = 634,
  .name = "ZWEILOUS",
  .form_name = "BASE",
  .family = 633,
  .types = DARK_M | DRAGON_M,
  .base_stats = { .stamina = 176, .attack = 159, .defense = 135 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_634_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_634_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_635_0[] = { 202, 204 };
uint16_t CHARGED_MOVELIST_635_0[] = { 82, 16, 36 };
pdex_mon_t DEXMON_635_0 = {
  .dex_number = 635,
  .name = "HYDREIGON",
  .form_name = "BASE",
  .family = 633,
  .types = DARK_M | DRAGON_M,
  .base_stats = { .stamina = 211, .attack = 256, .defense = 188 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_635_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_635_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_636_0[] = { 209, 201 };
uint16_t CHARGED_MOVELIST_636_0[] = { 101, 49, 21 };
pdex_mon_t DEXMON_636_0 = {
  .dex_number = 636,
  .name = "LARVESTA",
  .form_name = "BASE",
  .family = 636,
  .types = BUG_M | FIRE_M,
  .base_stats = { .stamina = 146, .attack = 156, .defense = 107 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_636_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_636_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_637_0[] = { 269, 201 };
uint16_t CHARGED_MOVELIST_637_0[] = { 270, 49, 116, 122 };
pdex_mon_t DEXMON_637_0 = {
  .dex_number = 637,
  .name = "VOLCARONA",
  .form_name = "BASE",
  .family = 636,
  .types = BUG_M | FIRE_M,
  .base_stats = { .stamina = 198, .attack = 264, .defense = 189 },
  .tags = TAG_NONE_M,
  .fast_move_ids = FAST_MOVELIST_637_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_637_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_638_0[] = { 228, 234 };
uint16_t CHARGED_MOVELIST_638_0[] = { 245, 74, 32, -330 };
pdex_mon_t DEXMON_638_0 = {
  .dex_number = 638,
  .name = "COBALION",
  .form_name = "BASE",
  .family = 638,
  .types = FIGHTING_M | STEEL_M,
  .base_stats = { .stamina = 209, .attack = 192, .defense = 229 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_638_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_638_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_639_0[] = { 297, 234 };
uint16_t CHARGED_MOVELIST_639_0[] = { 245, 31, 64 };
pdex_mon_t DEXMON_639_0 = {
  .dex_number = 639,
  .name = "TERRAKION",
  .form_name = "BASE",
  .family = 639,
  .types = FIGHTING_M | ROCK_M,
  .base_stats = { .stamina = 209, .attack = 260, .defense = 192 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_639_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_639_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_640_0[] = { 219, 234 };
uint16_t CHARGED_MOVELIST_640_0[] = { 245, 117, 32 };
pdex_mon_t DEXMON_640_0 = {
  .dex_number = 640,
  .name = "VIRIZION",
  .form_name = "BASE",
  .family = 640,
  .types = FIGHTING_M | GRASS_M,
  .base_stats = { .stamina = 209, .attack = 192, .defense = 229 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_640_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_640_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_641_0[] = { 202, 255 };
uint16_t CHARGED_MOVELIST_641_0[] = { 272, 16, 14, 122 };
uint16_t FAST_MOVELIST_641_1[] = { 202, 255 };
uint16_t CHARGED_MOVELIST_641_1[] = { 272, 16, 14, 122 };
uint16_t FAST_MOVELIST_641_2[] = { 202, 255 };
uint16_t CHARGED_MOVELIST_641_2[] = { 272, 16, 14, 122 };
pdex_mon_t DEXMON_641_2 = {
  .dex_number = 641,
  .name = "TORNADUS",
  .form_name = "THERIAN",
  .family = 641,
  .types = FLYING_M,
  .base_stats = { .stamina = 188, .attack = 238, .defense = 189 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_641_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_641_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_641_1 = {
  .dex_number = 641,
  .name = "TORNADUS",
  .form_name = "INCARNATE",
  .family = 641,
  .types = FLYING_M,
  .base_stats = { .stamina = 188, .attack = 266, .defense = 164 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_641_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_641_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_641_2
};
pdex_mon_t DEXMON_641_0 = {
  .dex_number = 641,
  .name = "TORNADUS",
  .form_name = "BASE",
  .family = 641,
  .types = FLYING_M,
  .base_stats = { .stamina = 188, .attack = 266, .defense = 164 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_641_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_641_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_641_1
};
uint16_t FAST_MOVELIST_642_0[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_642_0[] = { 279, 78, 123, 77 };
uint16_t FAST_MOVELIST_642_1[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_642_1[] = { 279, 78, 123, 77 };
uint16_t FAST_MOVELIST_642_2[] = { 263, 205 };
uint16_t CHARGED_MOVELIST_642_2[] = { 279, 78, 123, 77 };
pdex_mon_t DEXMON_642_2 = {
  .dex_number = 642,
  .name = "THUNDURUS",
  .form_name = "THERIAN",
  .family = 642,
  .types = ELECTRIC_M | FLYING_M,
  .base_stats = { .stamina = 188, .attack = 295, .defense = 161 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_642_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_642_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_642_1 = {
  .dex_number = 642,
  .name = "THUNDURUS",
  .form_name = "INCARNATE",
  .family = 642,
  .types = ELECTRIC_M | FLYING_M,
  .base_stats = { .stamina = 188, .attack = 266, .defense = 164 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_642_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_642_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_642_2
};
pdex_mon_t DEXMON_642_0 = {
  .dex_number = 642,
  .name = "THUNDURUS",
  .form_name = "BASE",
  .family = 642,
  .types = ELECTRIC_M | FLYING_M,
  .base_stats = { .stamina = 188, .attack = 266, .defense = 164 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_642_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_642_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_642_1
};
uint16_t FAST_MOVELIST_643_0[] = { 204, 240 };
uint16_t CHARGED_MOVELIST_643_0[] = { 279, 270, 285, 32 };
pdex_mon_t DEXMON_643_0 = {
  .dex_number = 643,
  .name = "RESHIRAM",
  .form_name = "BASE",
  .family = 643,
  .types = DRAGON_M | FIRE_M,
  .base_stats = { .stamina = 205, .attack = 275, .defense = 211 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_643_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_643_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_644_0[] = { 204, 249 };
uint16_t CHARGED_MOVELIST_644_0[] = { 277, 251, 36, 279 };
pdex_mon_t DEXMON_644_0 = {
  .dex_number = 644,
  .name = "ZEKROM",
  .form_name = "BASE",
  .family = 644,
  .types = DRAGON_M | ELECTRIC_M,
  .base_stats = { .stamina = 205, .attack = 275, .defense = 211 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_644_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_644_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_645_0[] = { 216, 227 };
uint16_t CHARGED_MOVELIST_645_0[] = { 304, 277, 64, 247 };
uint16_t FAST_MOVELIST_645_1[] = { 216, 227 };
uint16_t CHARGED_MOVELIST_645_1[] = { 304, 277, 64, 247 };
uint16_t FAST_MOVELIST_645_2[] = { 216, 227 };
uint16_t CHARGED_MOVELIST_645_2[] = { 304, 277, 64, 247 };
pdex_mon_t DEXMON_645_2 = {
  .dex_number = 645,
  .name = "LANDORUS",
  .form_name = "THERIAN",
  .family = 645,
  .types = FLYING_M | GROUND_M,
  .base_stats = { .stamina = 205, .attack = 289, .defense = 179 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_645_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_645_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_645_1 = {
  .dex_number = 645,
  .name = "LANDORUS",
  .form_name = "INCARNATE",
  .family = 645,
  .types = FLYING_M | GROUND_M,
  .base_stats = { .stamina = 205, .attack = 261, .defense = 182 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_645_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_645_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_645_2
};
pdex_mon_t DEXMON_645_0 = {
  .dex_number = 645,
  .name = "LANDORUS",
  .form_name = "BASE",
  .family = 645,
  .types = FLYING_M | GROUND_M,
  .base_stats = { .stamina = 205, .attack = 261, .defense = 182 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_645_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_645_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_645_1
};
uint16_t FAST_MOVELIST_646_0[] = { 204, 239 };
uint16_t CHARGED_MOVELIST_646_0[] = { 83, 40, 285 };
uint16_t FAST_MOVELIST_646_1[] = { 253, 213 };
uint16_t CHARGED_MOVELIST_646_1[] = { 74, 40, 32, 277 };
uint16_t FAST_MOVELIST_646_2[] = { 204, 239 };
uint16_t CHARGED_MOVELIST_646_2[] = { 82, 40, 62, 247 };
pdex_mon_t DEXMON_646_2 = {
  .dex_number = 646,
  .name = "KYUREM",
  .form_name = "WHITE",
  .family = 646,
  .types = DRAGON_M | ICE_M,
  .base_stats = { .stamina = 245, .attack = 310, .defense = 183 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_646_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_646_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_646_1 = {
  .dex_number = 646,
  .name = "KYUREM",
  .form_name = "BLACK",
  .family = 646,
  .types = DRAGON_M | ICE_M,
  .base_stats = { .stamina = 245, .attack = 310, .defense = 183 },
  .tags = TAG_LEGENDARY_M,
  .fast_move_ids = FAST_MOVELIST_646_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_646_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_646_2
};
pdex_mon_t DEXMON_646_0 = {
  .dex_number = 646,
  .name = "KYUREM",
  .form_name = "BASE",
  .family = 646,
  .types = DRAGON_M | ICE_M,
  .base_stats = { .stamina = 245, .attack = 246, .defense = 170 },
  .tags = TAG_LEGENDARY_M | TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_646_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_646_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_646_1
};
uint16_t FAST_MOVELIST_647_0[] = { 224, 207 };
uint16_t CHARGED_MOVELIST_647_0[] = { 57, 245, 107, 100 };
uint16_t FAST_MOVELIST_647_1[] = { 224, 207 };
uint16_t CHARGED_MOVELIST_647_1[] = { 57, 245, 107, 100 };
uint16_t FAST_MOVELIST_647_2[] = { 224, 207 };
uint16_t CHARGED_MOVELIST_647_2[] = { 57, 245, 107, 100 };
pdex_mon_t DEXMON_647_2 = {
  .dex_number = 647,
  .name = "KELDEO",
  .form_name = "RESOLUTE",
  .family = 647,
  .types = FIGHTING_M | WATER_M,
  .base_stats = { .stamina = 209, .attack = 260, .defense = 192 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_647_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_647_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_647_1 = {
  .dex_number = 647,
  .name = "KELDEO",
  .form_name = "ORDINARY",
  .family = 647,
  .types = FIGHTING_M | WATER_M,
  .base_stats = { .stamina = 209, .attack = 260, .defense = 192 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_647_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_647_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_647_2
};
pdex_mon_t DEXMON_647_0 = {
  .dex_number = 647,
  .name = "KELDEO",
  .form_name = "BASE",
  .family = 647,
  .types = FIGHTING_M | WATER_M,
  .base_stats = { .stamina = 209, .attack = 260, .defense = 192 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_647_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_647_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_647_1
};
uint16_t FAST_MOVELIST_648_0[] = { 219, 207 };
uint16_t CHARGED_MOVELIST_648_0[] = { 245, 115, 33, 14 };
uint16_t FAST_MOVELIST_648_1[] = { 219, 235 };
uint16_t CHARGED_MOVELIST_648_1[] = { 60, 79, 86, 14 };
uint16_t FAST_MOVELIST_648_2[] = { 219, 207 };
uint16_t CHARGED_MOVELIST_648_2[] = { 245, 115, 33, 14 };
pdex_mon_t DEXMON_648_2 = {
  .dex_number = 648,
  .name = "MELOETTA",
  .form_name = "PIROUETTE",
  .family = 648,
  .types = FIGHTING_M | NORMAL_M,
  .base_stats = { .stamina = 225, .attack = 269, .defense = 188 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_648_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_648_2,
  .charged_moves_cnt = 4,
 .form_idx = 2,
  .next_form = NULL
};
pdex_mon_t DEXMON_648_1 = {
  .dex_number = 648,
  .name = "MELOETTA",
  .form_name = "ARIA",
  .family = 648,
  .types = NORMAL_M | PSYCHIC_M,
  .base_stats = { .stamina = 225, .attack = 250, .defense = 225 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_648_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_648_1,
  .charged_moves_cnt = 4,
 .form_idx = 1,
  .next_form = & DEXMON_648_2
};
pdex_mon_t DEXMON_648_0 = {
  .dex_number = 648,
  .name = "MELOETTA",
  .form_name = "BASE",
  .family = 648,
  .types = NORMAL_M | PSYCHIC_M,
  .base_stats = { .stamina = 225, .attack = 250, .defense = 225 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_648_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_648_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = & DEXMON_648_1
};
uint16_t FAST_MOVELIST_649_0[] = { 228, 200 };
uint16_t CHARGED_MOVELIST_649_0[] = { 100, 72, 14 };
uint16_t FAST_MOVELIST_649_1[] = { 228, 200 };
uint16_t CHARGED_MOVELIST_649_1[] = { 100, 72, 24 };
uint16_t FAST_MOVELIST_649_2[] = { 228, 200 };
uint16_t CHARGED_MOVELIST_649_2[] = { 100, 72, 39 };
uint16_t FAST_MOVELIST_649_3[] = { 228, 200 };
uint16_t CHARGED_MOVELIST_649_3[] = { 100, 72, 92 };
uint16_t FAST_MOVELIST_649_4[] = { 228, 200 };
uint16_t CHARGED_MOVELIST_649_4[] = { 100, 72, 14 };
uint16_t FAST_MOVELIST_649_5[] = { 228, 200 };
uint16_t CHARGED_MOVELIST_649_5[] = { 100, 72, 252 };
pdex_mon_t DEXMON_649_5 = {
  .dex_number = 649,
  .name = "GENESECT",
  .form_name = "SHOCK",
  .family = 649,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 174, .attack = 252, .defense = 199 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_649_5,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_649_5,
  .charged_moves_cnt = 3,
 .form_idx = 5,
  .next_form = NULL
};
pdex_mon_t DEXMON_649_4 = {
  .dex_number = 649,
  .name = "GENESECT",
  .form_name = "NORMAL",
  .family = 649,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 174, .attack = 252, .defense = 199 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_649_4,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_649_4,
  .charged_moves_cnt = 3,
 .form_idx = 4,
  .next_form = & DEXMON_649_5
};
pdex_mon_t DEXMON_649_3 = {
  .dex_number = 649,
  .name = "GENESECT",
  .form_name = "DOUSE",
  .family = 649,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 174, .attack = 252, .defense = 199 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_649_3,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_649_3,
  .charged_moves_cnt = 3,
 .form_idx = 3,
  .next_form = & DEXMON_649_4
};
pdex_mon_t DEXMON_649_2 = {
  .dex_number = 649,
  .name = "GENESECT",
  .form_name = "CHILL",
  .family = 649,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 174, .attack = 252, .defense = 199 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_649_2,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_649_2,
  .charged_moves_cnt = 3,
 .form_idx = 2,
  .next_form = & DEXMON_649_3
};
pdex_mon_t DEXMON_649_1 = {
  .dex_number = 649,
  .name = "GENESECT",
  .form_name = "BURN",
  .family = 649,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 174, .attack = 252, .defense = 199 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_649_1,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_649_1,
  .charged_moves_cnt = 3,
 .form_idx = 1,
  .next_form = & DEXMON_649_2
};
pdex_mon_t DEXMON_649_0 = {
  .dex_number = 649,
  .name = "GENESECT",
  .form_name = "BASE",
  .family = 649,
  .types = BUG_M | STEEL_M,
  .base_stats = { .stamina = 174, .attack = 252, .defense = 199 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_649_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_649_0,
  .charged_moves_cnt = 3,
 .form_idx = 0,
  .next_form = & DEXMON_649_1
};
uint16_t FAST_MOVELIST_808_0[] = { 205 };
uint16_t CHARGED_MOVELIST_808_0[] = { 36, 79 };
pdex_mon_t DEXMON_808_0 = {
  .dex_number = 808,
  .name = "MELTAN",
  .form_name = "BASE",
  .family = 808,
  .types = STEEL_M,
  .base_stats = { .stamina = 130, .attack = 118, .defense = 99 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_808_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_808_0,
  .charged_moves_cnt = 2,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_809_0[] = { 205 };
uint16_t CHARGED_MOVELIST_809_0[] = { 36, 79, 14, 64, 310 };
pdex_mon_t DEXMON_809_0 = {
  .dex_number = 809,
  .name = "MELMETAL",
  .form_name = "BASE",
  .family = 808,
  .types = STEEL_M,
  .base_stats = { .stamina = 264, .attack = 226, .defense = 190 },
  .tags = TAG_MYTHIC_M,
  .fast_move_ids = FAST_MOVELIST_809_0,
  .fast_moves_cnt = 1,
  .charged_move_ids = CHARGED_MOVELIST_809_0,
  .charged_moves_cnt = 5,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_862_0[] = { 243, 212 };
uint16_t CHARGED_MOVELIST_862_0[] = { 28, 51, 14, 92 };
pdex_mon_t DEXMON_862_0 = {
  .dex_number = 862,
  .name = "OBSTAGOON",
  .form_name = "BASE",
  .family = 263,
  .types = DARK_M | NORMAL_M,
  .base_stats = { .stamina = 212, .attack = 180, .defense = 194 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_862_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_862_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_863_0[] = { 228, 213 };
uint16_t CHARGED_MOVELIST_863_0[] = { 74, 245, 88, 280 };
pdex_mon_t DEXMON_863_0 = {
  .dex_number = 863,
  .name = "PERRSERKER",
  .form_name = "BASE",
  .family = 52,
  .types = STEEL_M,
  .base_stats = { .stamina = 172, .attack = 195, .defense = 162 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_863_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_863_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};
uint16_t FAST_MOVELIST_865_0[] = { 243, 200 };
uint16_t CHARGED_MOVELIST_865_0[] = { 245, 256, 117, 51 };
pdex_mon_t DEXMON_865_0 = {
  .dex_number = 865,
  .name = "SIRFETCHD",
  .form_name = "BASE",
  .family = 83,
  .types = FIGHTING_M,
  .base_stats = { .stamina = 158, .attack = 248, .defense = 176 },
  .tags = TAG_SHADOW_ELIGABLE_M,
  .fast_move_ids = FAST_MOVELIST_865_0,
  .fast_moves_cnt = 2,
  .charged_move_ids = CHARGED_MOVELIST_865_0,
  .charged_moves_cnt = 4,
 .form_idx = 0,
  .next_form = NULL
};

/* ------------------------------------------------------------------------- */


pdex_mon_t * POKEDEX[] = {
  & DEXMON_1_0,
  & DEXMON_2_0,
  & DEXMON_3_0,
  & DEXMON_4_0,
  & DEXMON_5_0,
  & DEXMON_6_0,
  & DEXMON_7_0,
  & DEXMON_8_0,
  & DEXMON_9_0,
  & DEXMON_10_0,
  & DEXMON_11_0,
  & DEXMON_12_0,
  & DEXMON_13_0,
  & DEXMON_14_0,
  & DEXMON_15_0,
  & DEXMON_16_0,
  & DEXMON_17_0,
  & DEXMON_18_0,
  & DEXMON_19_0,
  & DEXMON_20_0,
  & DEXMON_21_0,
  & DEXMON_22_0,
  & DEXMON_23_0,
  & DEXMON_24_0,
  & DEXMON_25_0,
  & DEXMON_26_0,
  & DEXMON_27_0,
  & DEXMON_28_0,
  & DEXMON_29_0,
  & DEXMON_30_0,
  & DEXMON_31_0,
  & DEXMON_32_0,
  & DEXMON_33_0,
  & DEXMON_34_0,
  & DEXMON_35_0,
  & DEXMON_36_0,
  & DEXMON_37_0,
  & DEXMON_38_0,
  & DEXMON_39_0,
  & DEXMON_40_0,
  & DEXMON_41_0,
  & DEXMON_42_0,
  & DEXMON_43_0,
  & DEXMON_44_0,
  & DEXMON_45_0,
  & DEXMON_46_0,
  & DEXMON_47_0,
  & DEXMON_48_0,
  & DEXMON_49_0,
  & DEXMON_50_0,
  & DEXMON_51_0,
  & DEXMON_52_0,
  & DEXMON_53_0,
  & DEXMON_54_0,
  & DEXMON_55_0,
  & DEXMON_56_0,
  & DEXMON_57_0,
  & DEXMON_58_0,
  & DEXMON_59_0,
  & DEXMON_60_0,
  & DEXMON_61_0,
  & DEXMON_62_0,
  & DEXMON_63_0,
  & DEXMON_64_0,
  & DEXMON_65_0,
  & DEXMON_66_0,
  & DEXMON_67_0,
  & DEXMON_68_0,
  & DEXMON_69_0,
  & DEXMON_70_0,
  & DEXMON_71_0,
  & DEXMON_72_0,
  & DEXMON_73_0,
  & DEXMON_74_0,
  & DEXMON_75_0,
  & DEXMON_76_0,
  & DEXMON_77_0,
  & DEXMON_78_0,
  & DEXMON_79_0,
  & DEXMON_80_0,
  & DEXMON_81_0,
  & DEXMON_82_0,
  & DEXMON_83_0,
  & DEXMON_84_0,
  & DEXMON_85_0,
  & DEXMON_86_0,
  & DEXMON_87_0,
  & DEXMON_88_0,
  & DEXMON_89_0,
  & DEXMON_90_0,
  & DEXMON_91_0,
  & DEXMON_92_0,
  & DEXMON_93_0,
  & DEXMON_94_0,
  & DEXMON_95_0,
  & DEXMON_96_0,
  & DEXMON_97_0,
  & DEXMON_98_0,
  & DEXMON_99_0,
  & DEXMON_100_0,
  & DEXMON_101_0,
  & DEXMON_102_0,
  & DEXMON_103_0,
  & DEXMON_104_0,
  & DEXMON_105_0,
  & DEXMON_106_0,
  & DEXMON_107_0,
  & DEXMON_108_0,
  & DEXMON_109_0,
  & DEXMON_110_0,
  & DEXMON_111_0,
  & DEXMON_112_0,
  & DEXMON_113_0,
  & DEXMON_114_0,
  & DEXMON_115_0,
  & DEXMON_116_0,
  & DEXMON_117_0,
  & DEXMON_118_0,
  & DEXMON_119_0,
  & DEXMON_120_0,
  & DEXMON_121_0,
  & DEXMON_122_0,
  & DEXMON_123_0,
  & DEXMON_124_0,
  & DEXMON_125_0,
  & DEXMON_126_0,
  & DEXMON_127_0,
  & DEXMON_128_0,
  & DEXMON_129_0,
  & DEXMON_130_0,
  & DEXMON_131_0,
  & DEXMON_132_0,
  & DEXMON_133_0,
  & DEXMON_134_0,
  & DEXMON_135_0,
  & DEXMON_136_0,
  & DEXMON_137_0,
  & DEXMON_138_0,
  & DEXMON_139_0,
  & DEXMON_140_0,
  & DEXMON_141_0,
  & DEXMON_142_0,
  & DEXMON_143_0,
  & DEXMON_144_0,
  & DEXMON_145_0,
  & DEXMON_146_0,
  & DEXMON_147_0,
  & DEXMON_148_0,
  & DEXMON_149_0,
  & DEXMON_150_0,
  & DEXMON_151_0,
  & DEXMON_152_0,
  & DEXMON_153_0,
  & DEXMON_154_0,
  & DEXMON_155_0,
  & DEXMON_156_0,
  & DEXMON_157_0,
  & DEXMON_158_0,
  & DEXMON_159_0,
  & DEXMON_160_0,
  & DEXMON_161_0,
  & DEXMON_162_0,
  & DEXMON_163_0,
  & DEXMON_164_0,
  & DEXMON_165_0,
  & DEXMON_166_0,
  & DEXMON_167_0,
  & DEXMON_168_0,
  & DEXMON_169_0,
  & DEXMON_170_0,
  & DEXMON_171_0,
  & DEXMON_172_0,
  & DEXMON_173_0,
  & DEXMON_174_0,
  & DEXMON_175_0,
  & DEXMON_176_0,
  & DEXMON_177_0,
  & DEXMON_178_0,
  & DEXMON_179_0,
  & DEXMON_180_0,
  & DEXMON_181_0,
  & DEXMON_182_0,
  & DEXMON_183_0,
  & DEXMON_184_0,
  & DEXMON_185_0,
  & DEXMON_186_0,
  & DEXMON_187_0,
  & DEXMON_188_0,
  & DEXMON_189_0,
  & DEXMON_190_0,
  & DEXMON_191_0,
  & DEXMON_192_0,
  & DEXMON_193_0,
  & DEXMON_194_0,
  & DEXMON_195_0,
  & DEXMON_196_0,
  & DEXMON_197_0,
  & DEXMON_198_0,
  & DEXMON_199_0,
  & DEXMON_200_0,
  & DEXMON_201_0,
  & DEXMON_202_0,
  & DEXMON_203_0,
  & DEXMON_204_0,
  & DEXMON_205_0,
  & DEXMON_206_0,
  & DEXMON_207_0,
  & DEXMON_208_0,
  & DEXMON_209_0,
  & DEXMON_210_0,
  & DEXMON_211_0,
  & DEXMON_212_0,
  & DEXMON_213_0,
  & DEXMON_214_0,
  & DEXMON_215_0,
  & DEXMON_216_0,
  & DEXMON_217_0,
  & DEXMON_218_0,
  & DEXMON_219_0,
  & DEXMON_220_0,
  & DEXMON_221_0,
  & DEXMON_222_0,
  & DEXMON_223_0,
  & DEXMON_224_0,
  & DEXMON_225_0,
  & DEXMON_226_0,
  & DEXMON_227_0,
  & DEXMON_228_0,
  & DEXMON_229_0,
  & DEXMON_230_0,
  & DEXMON_231_0,
  & DEXMON_232_0,
  & DEXMON_233_0,
  & DEXMON_234_0,
  & DEXMON_235_0,
  & DEXMON_236_0,
  & DEXMON_237_0,
  & DEXMON_238_0,
  & DEXMON_239_0,
  & DEXMON_240_0,
  & DEXMON_241_0,
  & DEXMON_242_0,
  & DEXMON_243_0,
  & DEXMON_244_0,
  & DEXMON_245_0,
  & DEXMON_246_0,
  & DEXMON_247_0,
  & DEXMON_248_0,
  & DEXMON_249_0,
  & DEXMON_250_0,
  & DEXMON_251_0,
  & DEXMON_252_0,
  & DEXMON_253_0,
  & DEXMON_254_0,
  & DEXMON_255_0,
  & DEXMON_256_0,
  & DEXMON_257_0,
  & DEXMON_258_0,
  & DEXMON_259_0,
  & DEXMON_260_0,
  & DEXMON_261_0,
  & DEXMON_262_0,
  & DEXMON_263_0,
  & DEXMON_264_0,
  & DEXMON_265_0,
  & DEXMON_266_0,
  & DEXMON_267_0,
  & DEXMON_268_0,
  & DEXMON_269_0,
  & DEXMON_270_0,
  & DEXMON_271_0,
  & DEXMON_272_0,
  & DEXMON_273_0,
  & DEXMON_274_0,
  & DEXMON_275_0,
  & DEXMON_276_0,
  & DEXMON_277_0,
  & DEXMON_278_0,
  & DEXMON_279_0,
  & DEXMON_280_0,
  & DEXMON_281_0,
  & DEXMON_282_0,
  & DEXMON_283_0,
  & DEXMON_284_0,
  & DEXMON_285_0,
  & DEXMON_286_0,
  & DEXMON_287_0,
  & DEXMON_288_0,
  & DEXMON_289_0,
  & DEXMON_290_0,
  & DEXMON_291_0,
  & DEXMON_292_0,
  & DEXMON_293_0,
  & DEXMON_294_0,
  & DEXMON_295_0,
  & DEXMON_296_0,
  & DEXMON_297_0,
  & DEXMON_298_0,
  & DEXMON_299_0,
  & DEXMON_300_0,
  & DEXMON_301_0,
  & DEXMON_302_0,
  & DEXMON_303_0,
  & DEXMON_304_0,
  & DEXMON_305_0,
  & DEXMON_306_0,
  & DEXMON_307_0,
  & DEXMON_308_0,
  & DEXMON_309_0,
  & DEXMON_310_0,
  & DEXMON_311_0,
  & DEXMON_312_0,
  & DEXMON_313_0,
  & DEXMON_314_0,
  & DEXMON_315_0,
  & DEXMON_316_0,
  & DEXMON_317_0,
  & DEXMON_318_0,
  & DEXMON_319_0,
  & DEXMON_320_0,
  & DEXMON_321_0,
  & DEXMON_322_0,
  & DEXMON_323_0,
  & DEXMON_324_0,
  & DEXMON_325_0,
  & DEXMON_326_0,
  & DEXMON_327_0,
  & DEXMON_328_0,
  & DEXMON_329_0,
  & DEXMON_330_0,
  & DEXMON_331_0,
  & DEXMON_332_0,
  & DEXMON_333_0,
  & DEXMON_334_0,
  & DEXMON_335_0,
  & DEXMON_336_0,
  & DEXMON_337_0,
  & DEXMON_338_0,
  & DEXMON_339_0,
  & DEXMON_340_0,
  & DEXMON_341_0,
  & DEXMON_342_0,
  & DEXMON_343_0,
  & DEXMON_344_0,
  & DEXMON_345_0,
  & DEXMON_346_0,
  & DEXMON_347_0,
  & DEXMON_348_0,
  & DEXMON_349_0,
  & DEXMON_350_0,
  & DEXMON_351_0,
  & DEXMON_352_0,
  & DEXMON_353_0,
  & DEXMON_354_0,
  & DEXMON_355_0,
  & DEXMON_356_0,
  & DEXMON_357_0,
  & DEXMON_358_0,
  & DEXMON_359_0,
  & DEXMON_360_0,
  & DEXMON_361_0,
  & DEXMON_362_0,
  & DEXMON_363_0,
  & DEXMON_364_0,
  & DEXMON_365_0,
  & DEXMON_366_0,
  & DEXMON_367_0,
  & DEXMON_368_0,
  & DEXMON_369_0,
  & DEXMON_370_0,
  & DEXMON_371_0,
  & DEXMON_372_0,
  & DEXMON_373_0,
  & DEXMON_374_0,
  & DEXMON_375_0,
  & DEXMON_376_0,
  & DEXMON_377_0,
  & DEXMON_378_0,
  & DEXMON_379_0,
  & DEXMON_380_0,
  & DEXMON_381_0,
  & DEXMON_382_0,
  & DEXMON_383_0,
  & DEXMON_384_0,
  & DEXMON_385_0,
  & DEXMON_386_0,
  & DEXMON_387_0,
  & DEXMON_388_0,
  & DEXMON_389_0,
  & DEXMON_390_0,
  & DEXMON_391_0,
  & DEXMON_392_0,
  & DEXMON_393_0,
  & DEXMON_394_0,
  & DEXMON_395_0,
  & DEXMON_396_0,
  & DEXMON_397_0,
  & DEXMON_398_0,
  & DEXMON_399_0,
  & DEXMON_400_0,
  & DEXMON_401_0,
  & DEXMON_402_0,
  & DEXMON_403_0,
  & DEXMON_404_0,
  & DEXMON_405_0,
  & DEXMON_406_0,
  & DEXMON_407_0,
  & DEXMON_408_0,
  & DEXMON_409_0,
  & DEXMON_410_0,
  & DEXMON_411_0,
  & DEXMON_412_0,
  & DEXMON_413_0,
  & DEXMON_414_0,
  & DEXMON_415_0,
  & DEXMON_416_0,
  & DEXMON_417_0,
  & DEXMON_418_0,
  & DEXMON_419_0,
  & DEXMON_420_0,
  & DEXMON_421_0,
  & DEXMON_422_0,
  & DEXMON_423_0,
  & DEXMON_424_0,
  & DEXMON_425_0,
  & DEXMON_426_0,
  & DEXMON_427_0,
  & DEXMON_428_0,
  & DEXMON_429_0,
  & DEXMON_430_0,
  & DEXMON_431_0,
  & DEXMON_432_0,
  & DEXMON_433_0,
  & DEXMON_434_0,
  & DEXMON_435_0,
  & DEXMON_436_0,
  & DEXMON_437_0,
  & DEXMON_438_0,
  & DEXMON_439_0,
  & DEXMON_440_0,
  & DEXMON_441_0,
  & DEXMON_442_0,
  & DEXMON_443_0,
  & DEXMON_444_0,
  & DEXMON_445_0,
  & DEXMON_446_0,
  & DEXMON_447_0,
  & DEXMON_448_0,
  & DEXMON_449_0,
  & DEXMON_450_0,
  & DEXMON_451_0,
  & DEXMON_452_0,
  & DEXMON_453_0,
  & DEXMON_454_0,
  & DEXMON_455_0,
  & DEXMON_456_0,
  & DEXMON_457_0,
  & DEXMON_458_0,
  & DEXMON_459_0,
  & DEXMON_460_0,
  & DEXMON_461_0,
  & DEXMON_462_0,
  & DEXMON_463_0,
  & DEXMON_464_0,
  & DEXMON_465_0,
  & DEXMON_466_0,
  & DEXMON_467_0,
  & DEXMON_468_0,
  & DEXMON_469_0,
  & DEXMON_470_0,
  & DEXMON_471_0,
  & DEXMON_472_0,
  & DEXMON_473_0,
  & DEXMON_474_0,
  & DEXMON_475_0,
  & DEXMON_476_0,
  & DEXMON_477_0,
  & DEXMON_478_0,
  & DEXMON_479_0,
  & DEXMON_480_0,
  & DEXMON_481_0,
  & DEXMON_482_0,
  & DEXMON_483_0,
  & DEXMON_484_0,
  & DEXMON_485_0,
  & DEXMON_486_0,
  & DEXMON_487_0,
  & DEXMON_488_0,
  & DEXMON_489_0,
  & DEXMON_490_0,
  & DEXMON_491_0,
  & DEXMON_492_0,
  & DEXMON_493_0,
  & DEXMON_494_0,
  & DEXMON_495_0,
  & DEXMON_496_0,
  & DEXMON_497_0,
  & DEXMON_498_0,
  & DEXMON_499_0,
  & DEXMON_500_0,
  & DEXMON_501_0,
  & DEXMON_502_0,
  & DEXMON_503_0,
  & DEXMON_504_0,
  & DEXMON_505_0,
  & DEXMON_506_0,
  & DEXMON_507_0,
  & DEXMON_508_0,
  & DEXMON_509_0,
  & DEXMON_510_0,
  & DEXMON_511_0,
  & DEXMON_512_0,
  & DEXMON_513_0,
  & DEXMON_514_0,
  & DEXMON_515_0,
  & DEXMON_516_0,
  & DEXMON_517_0,
  & DEXMON_518_0,
  & DEXMON_519_0,
  & DEXMON_520_0,
  & DEXMON_521_0,
  & DEXMON_522_0,
  & DEXMON_523_0,
  & DEXMON_524_0,
  & DEXMON_525_0,
  & DEXMON_526_0,
  & DEXMON_527_0,
  & DEXMON_528_0,
  & DEXMON_529_0,
  & DEXMON_530_0,
  & DEXMON_531_0,
  & DEXMON_532_0,
  & DEXMON_533_0,
  & DEXMON_534_0,
  & DEXMON_535_0,
  & DEXMON_536_0,
  & DEXMON_537_0,
  & DEXMON_538_0,
  & DEXMON_539_0,
  & DEXMON_540_0,
  & DEXMON_541_0,
  & DEXMON_542_0,
  & DEXMON_543_0,
  & DEXMON_544_0,
  & DEXMON_545_0,
  & DEXMON_546_0,
  & DEXMON_547_0,
  & DEXMON_548_0,
  & DEXMON_549_0,
  & DEXMON_550_0,
  & DEXMON_551_0,
  & DEXMON_552_0,
  & DEXMON_553_0,
  & DEXMON_554_0,
  & DEXMON_555_0,
  & DEXMON_556_0,
  & DEXMON_557_0,
  & DEXMON_558_0,
  & DEXMON_559_0,
  & DEXMON_560_0,
  & DEXMON_561_0,
  & DEXMON_562_0,
  & DEXMON_563_0,
  & DEXMON_564_0,
  & DEXMON_565_0,
  & DEXMON_566_0,
  & DEXMON_567_0,
  & DEXMON_568_0,
  & DEXMON_569_0,
  & DEXMON_570_0,
  & DEXMON_571_0,
  & DEXMON_572_0,
  & DEXMON_573_0,
  & DEXMON_574_0,
  & DEXMON_575_0,
  & DEXMON_576_0,
  & DEXMON_577_0,
  & DEXMON_578_0,
  & DEXMON_579_0,
  & DEXMON_580_0,
  & DEXMON_581_0,
  & DEXMON_582_0,
  & DEXMON_583_0,
  & DEXMON_584_0,
  & DEXMON_585_0,
  & DEXMON_586_0,
  & DEXMON_587_0,
  & DEXMON_588_0,
  & DEXMON_589_0,
  & DEXMON_590_0,
  & DEXMON_591_0,
  & DEXMON_592_0,
  & DEXMON_593_0,
  & DEXMON_594_0,
  & DEXMON_595_0,
  & DEXMON_596_0,
  & DEXMON_597_0,
  & DEXMON_598_0,
  & DEXMON_599_0,
  & DEXMON_600_0,
  & DEXMON_601_0,
  & DEXMON_602_0,
  & DEXMON_603_0,
  & DEXMON_604_0,
  & DEXMON_605_0,
  & DEXMON_606_0,
  & DEXMON_607_0,
  & DEXMON_608_0,
  & DEXMON_609_0,
  & DEXMON_610_0,
  & DEXMON_611_0,
  & DEXMON_612_0,
  & DEXMON_613_0,
  & DEXMON_614_0,
  & DEXMON_615_0,
  & DEXMON_616_0,
  & DEXMON_617_0,
  & DEXMON_618_0,
  & DEXMON_619_0,
  & DEXMON_620_0,
  & DEXMON_621_0,
  & DEXMON_622_0,
  & DEXMON_623_0,
  & DEXMON_624_0,
  & DEXMON_625_0,
  & DEXMON_626_0,
  & DEXMON_627_0,
  & DEXMON_628_0,
  & DEXMON_629_0,
  & DEXMON_630_0,
  & DEXMON_631_0,
  & DEXMON_632_0,
  & DEXMON_633_0,
  & DEXMON_634_0,
  & DEXMON_635_0,
  & DEXMON_636_0,
  & DEXMON_637_0,
  & DEXMON_638_0,
  & DEXMON_639_0,
  & DEXMON_640_0,
  & DEXMON_641_0,
  & DEXMON_642_0,
  & DEXMON_643_0,
  & DEXMON_644_0,
  & DEXMON_645_0,
  & DEXMON_646_0,
  & DEXMON_647_0,
  & DEXMON_648_0,
  & DEXMON_649_0,
  & DEXMON_808_0,
  & DEXMON_809_0,
  & DEXMON_862_0,
  & DEXMON_863_0,
  & DEXMON_865_0
};


/* ========================================================================= */

/* vim: set filetype=c : */
