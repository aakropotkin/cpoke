/* -*- mode: c; -*- */

/* ========================================================================= */

#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include "ptypes.h"
#include "parse_gm.h"
#include "util/json_util.h"
#include "util/macros.h"
#include "util/test_util.h"
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* ------------------------------------------------------------------------- */

/* This is normally nested in `.itemTemplate: [...]' */
static const char JSON1[] = R"RAW_JSON(
  [ { "templateId": "V0001_POKEMON_BULBASAUR_NORMAL",
      "pokemon": {
        "uniqueId": "BULBASAUR",
        "modelScale": 1.09,
        "type1": "POKEMON_TYPE_GRASS",
        "type2": "POKEMON_TYPE_POISON",
        "camera": {
          "diskRadiusM": 0.5723,
          "cylinderRadiusM": 0.5,
          "cylinderHeightM": 0.763,
          "shoulderModeScale": 0.5
        },
        "encounter": {
          "baseCaptureRate": 0.2,
          "baseFleeRate": 0.1,
          "collisionRadiusM": 0.3815,
          "collisionHeightM": 0.654,
          "collisionHeadRadiusM": 0.2725,
          "movementType": "MOVEMENT_JUMP",
          "movementTimerS": 10.0,
          "jumpTimeS": 1.15,
          "attackTimerS": 29.0,
          "attackProbability": 0.1,
          "dodgeProbability": 0.15,
          "dodgeDurationS": 1.0,
          "dodgeDistance": 1.0,
          "cameraDistance": 3.75,
          "minPokemonActionFrequencyS": 0.2,
          "maxPokemonActionFrequencyS": 1.6
        },
        "stats": {
          "baseStamina": 128,
          "baseAttack": 118,
          "baseDefense": 111
        },
        "quickMoves": ["VINE_WHIP_FAST", "TACKLE_FAST"],
        "cinematicMoves": ["SLUDGE_BOMB", "SEED_BOMB", "POWER_WHIP"],
        "animTime": [1.6667, 0.6667, 1.6667, 1.8333, 0.0, 2.1667, 1.4,
                      1.466667],
        "evolution": ["IVYSAUR"],
        "evolutionPips": 1,
        "pokedexHeightM": 0.7,
        "pokedexWeightKg": 6.9,
        "heightStdDev": 0.0875,
        "weightStdDev": 0.8625,
        "familyId": "FAMILY_BULBASAUR",
        "candyToEvolve": 25,
        "kmBuddyDistance": 3.0,
        "modelHeight": 0.7,
        "evolutionBranch": [{
          "evolution": "IVYSAUR",
          "candyCost": 25,
          "form": "IVYSAUR_NORMAL"
        }],
        "modelScaleV2": 0.89,
        "form": "BULBASAUR_NORMAL",
        "buddyOffsetMale": [0.0, 0.0, 0.0],
        "buddyOffsetFemale": [0.0, 0.0, 0.0],
        "buddyScale": 19.0,
        "thirdMove": {
          "stardustToUnlock": 10000,
          "candyToUnlock": 25
        },
        "isTransferable": true,
        "isDeployable": true,
        "buddyGroupNumber": 2
      }
    }
  ]
)RAW_JSON";

static const size_t JSON1_LEN = array_size( JSON1 );


/* ------------------------------------------------------------------------- */

#define parse_gm_json_str( STR_NAME, TOKEN_LIST_NAME, COUNT_NAME )            \
  jsmntok_t * TOKEN_LIST_NAME = NULL;                                         \
  jsmn_parser_t STR_NAME ## _PARSER;                                          \
  size_t COUNT_NAME = 0;                                                      \
  long STR_NAME ## _PARSER_RSL = jsmn_parse_realloc( & STR_NAME ## _PARSER,   \
                                                     ( STR_NAME ),            \
                                                     ( STR_NAME ## _LEN ),    \
                                                     &( TOKEN_LIST_NAME ),    \
                                                     &( COUNT_NAME )          \
                                                   );                         \
  COUNT_NAME = STR_NAME ## _PARSER_RSL


/* ------------------------------------------------------------------------- */

  static bool
test_regex_patterns( void )
{
  /* Compile Regex patterns for templateIds */
  gm_regexes_t regs;
  int          rsl = gm_regexes_init( &regs );
  assert( rsl == 0 );

  /* FIXME test pokemon */
  char test_str1[] = "COMBAT_V0013_MOVE_WRAP";
  char test_str2[] = "COMBAT_V0062_MOVE_ANCIENT_POWER";
  char test_str3[] = "COMBAT_V0200_MOVE_FURY_CUTTER_FAST";

  expect( regexec( &regs.tmpl_pvp_move, test_str1, 0, NULL, 0 ) == 0 );
  expect( regexec( &regs.tmpl_pvp_move, test_str2, 0, NULL, 0 ) == 0 );
  expect( regexec( &regs.tmpl_pvp_move, test_str3, 0, NULL, 0 ) == 0 );

  expect( regexec( &regs.tmpl_pvp_fast, test_str1, 0, NULL, 0 ) != 0 );
  expect( regexec( &regs.tmpl_pvp_fast, test_str2, 0, NULL, 0 ) != 0 );
  expect( regexec( &regs.tmpl_pvp_fast, test_str3, 0, NULL, 0 ) == 0 );

  expect( regexec( &regs.tmpl_mon, test_str1, 0, NULL, 0 ) != 0 );
  expect( regexec( &regs.tmpl_mon, test_str2, 0, NULL, 0 ) != 0 );
  expect( regexec( &regs.tmpl_mon, test_str3, 0, NULL, 0 ) != 0 );

  gm_regexes_free( &regs );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_parse_gm_type( void )
{
  /* Try parsing on a simple, one token JSON string */
  const char fairy_str[] = "POKEMON_TYPE_FAIRY";
  jsmntok_t  tok = {
    .type  = JSMN_STRING,
    .start = 0,
    .end   = array_size( fairy_str ),
    .size  = 0
  };
  expect( parse_gm_type( fairy_str, &tok ) == FAIRY );

  /* Try parsing on a full pokemon's GM entry */
  parse_gm_json_str( JSON1, tokens, tokens_cnt );
  assert( 0 < JSON1_PARSER_RSL );
  size_t buffer_len = JSON1_LEN;

  int type_idx = json_find( JSON1,
                            tokens,
                            jsoneq_str_p,
                            (void *) "type1",
                            tokens_cnt,
                            0
                          );
  type_idx++; /* Current index is the key, the next is the value. */

  assert( jsoneq_str( JSON1, tokens + type_idx, "POKEMON_TYPE_GRASS" ) );
  ptype_t type1 = parse_gm_type( JSON1, tokens + type_idx );
  expect( type1 == GRASS );

  type_idx += 2; /* Type 2's value is 2 tokens forward in this case. */
  assert( jsoneq_str( JSON1, tokens + type_idx, "POKEMON_TYPE_POISON" ) );
  ptype_t type2 = parse_gm_type( JSON1, tokens + type_idx );
  expect( type2 == POISON );

  free( tokens );

  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_parse_gm_dex_num( void )
{
  const char tid_str[] = "V0001_POKEMON_BULBASAUR_NORMAL";
  jsmntok_t tid_tok = {
    .type  = JSMN_STRING,
    .start = 0,
    .end   = array_size( tid_str ),
    .size  = 0
  };
  uint16_t dex_num = parse_gm_dex_num( tid_str, &tid_tok );
  expect( dex_num == 1 );
  return true;
}


/* ------------------------------------------------------------------------- */

  static bool
test_parse_gm_stats( void )
{
  const char stats_str[] = R"RAW_JSON(
      { "baseStamina": 128 "baseAttack": 118 "baseDefense": 111 }
    )RAW_JSON";
  size_t stats_str_len = array_size( stats_str );
  jsmntok_t tokens[7];
  jsmn_parser_t jparser;
  jsmn_init( &jparser );
  int tokens_cnt = jsmn_parse( &jparser, stats_str, stats_str_len, tokens, 7 );
  jsmnis_t iter_stack;
  jsmnis_init( &iter_stack, tokens, tokens_cnt, 3 );
  jsmnis_push( &iter_stack, 0 );

  stats_t stats = parse_gm_stats( stats_str, &iter_stack );
  expect( stats.stamina == 128 );
  expect( stats.attack == 118 );
  expect( stats.defense == 111 );

  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_parse_gm( void )
{
  bool rsl = true;
  rsl &= do_test( regex_patterns );
  rsl &= do_test( parse_gm_type );
  rsl &= do_test( parse_gm_dex_num );
  rsl &= do_test( parse_gm_stats );
  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
