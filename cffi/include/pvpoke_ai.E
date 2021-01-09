//__FROM__: include/ai/pvpoke_ai.h
struct pvp_battle_s;
typedef enum packed {
  USER_CONTROLLED, NOVICE, RIVAL, ELITE, CHAMPION
} pvpoke_ai_level_t;

typedef pvpoke_ai_level_t pvpoke_ai_aux_t;




//@@
/*
DEFINE_ENUM_WITH_FLAGS( strat, DEFAULT_STRAT, SHIELD_STRAT, SWITCH_BASIC,
                        SWITCH_FARM, SWITCH_ADVANCED, FARM_ENERGY, OVERFARM,
                        BAIT_SHIELDS, WAIT_CLOCK, PRESERVE_SWITCH_ADVANTAGE,
                        ADVANCED_SHIELDING, BAD_DECISION_PROTECTION,
                        SACRIFICIAL_SWAP
                      ) transparent;
*/
/*
typedef enum { DEFAULT_STRAT , SHIELD_STRAT , SWITCH_BASIC , SWITCH_FARM , SWITCH_ADVANCED , FARM_ENERGY , OVERFARM , BAIT_SHIELDS , WAIT_CLOCK , PRESERVE_SWITCH_ADVANTAGE , ADVANCED_SHIELDING , BAD_DECISION_PROTECTION , SACRIFICIAL_SWAP } strat_t; typedef enum { DEFAULT_STRAT_M = ( ( ( !! ( DEFAULT_STRAT ) ) << ( DEFAULT_STRAT ) ) >> 1 ) , SHIELD_STRAT_M = ( ( ( !! ( SHIELD_STRAT ) ) << ( SHIELD_STRAT ) ) >> 1 ) , SWITCH_BASIC_M = ( ( ( !! ( SWITCH_BASIC ) ) << ( SWITCH_BASIC ) ) >> 1 ) , SWITCH_FARM_M = ( ( ( !! ( SWITCH_FARM ) ) << ( SWITCH_FARM ) ) >> 1 ) , SWITCH_ADVANCED_M = ( ( ( !! ( SWITCH_ADVANCED ) ) << ( SWITCH_ADVANCED ) ) >> 1 ) , FARM_ENERGY_M = ( ( ( !! ( FARM_ENERGY ) ) << ( FARM_ENERGY ) ) >> 1 ) , OVERFARM_M = ( ( ( !! ( OVERFARM ) ) << ( OVERFARM ) ) >> 1 ) , BAIT_SHIELDS_M = ( ( ( !! ( BAIT_SHIELDS ) ) << ( BAIT_SHIELDS ) ) >> 1 ) , WAIT_CLOCK_M = ( ( ( !! ( WAIT_CLOCK ) ) << ( WAIT_CLOCK ) ) >> 1 ) , PRESERVE_SWITCH_ADVANTAGE_M = ( ( ( !! ( PRESERVE_SWITCH_ADVANTAGE ) ) << ( PRESERVE_SWITCH_ADVANTAGE ) ) >> 1 ) , ADVANCED_SHIELDING_M = ( ( ( !! ( ADVANCED_SHIELDING ) ) << ( ADVANCED_SHIELDING ) ) >> 1 ) , BAD_DECISION_PROTECTION_M = ( ( ( !! ( BAD_DECISION_PROTECTION ) ) << ( BAD_DECISION_PROTECTION ) ) >> 1 ) , SACRIFICIAL_SWAP_M = ( ( ( !! ( SACRIFICIAL_SWAP ) ) << ( SACRIFICIAL_SWAP ) ) >> 1 ) } strat_mask_t; typedef union { strat_mask_t mask; struct { unsigned int SHIELD_STRAT : 1 ; unsigned int SWITCH_BASIC : 1 ; unsigned int SWITCH_FARM : 1 ; unsigned int SWITCH_ADVANCED : 1 ; unsigned int FARM_ENERGY : 1 ; unsigned int OVERFARM : 1 ; unsigned int BAIT_SHIELDS : 1 ; unsigned int WAIT_CLOCK : 1 ; unsigned int PRESERVE_SWITCH_ADVANTAGE : 1 ; unsigned int ADVANCED_SHIELDING : 1 ; unsigned int BAD_DECISION_PROTECTION : 1 ; unsigned int SACRIFICIAL_SWAP : 1; }; } strat_flags_t;
*/

typedef enum {DEFAULT_STRAT, SHIELD_STRAT, SWITCH_BASIC,
                        SWITCH_FARM, SWITCH_ADVANCED, FARM_ENERGY, OVERFARM,
                        BAIT_SHIELDS, WAIT_CLOCK, PRESERVE_SWITCH_ADVANTAGE,
                        ADVANCED_SHIELDING, BAD_DECISION_PROTECTION,
                        SACRIFICIAL_SWAP} strat_t;
typedef unsigned int strat_mask_t;
typedef union { strat_mask_t mask; struct { unsigned int SHIELD_STRAT : 1 ; unsigned int SWITCH_BASIC : 1 ; unsigned int SWITCH_FARM : 1 ; unsigned int SWITCH_ADVANCED : 1 ; unsigned int FARM_ENERGY : 1 ; unsigned int OVERFARM : 1 ; unsigned int BAIT_SHIELDS : 1 ; unsigned int WAIT_CLOCK : 1 ; unsigned int PRESERVE_SWITCH_ADVANTAGE : 1 ; unsigned int ADVANCED_SHIELDING : 1 ; unsigned int BAD_DECISION_PROTECTION : 1 ; unsigned int SACRIFICIAL_SWAP : 1; }; } strat_flags_t;







struct pvpoke_ai_rules_s {
  bool two_charged_moves : 1;
  uint16_t iv_combo_range : 15;
  uint8_t energy_guess_accuracy : 4;
  uint8_t reaction_time : 4;
  uint8_t move_guess_certainty : 2;
  strat_flags_t strategies;
} packed;

typedef struct pvpoke_ai_rules_s pvpoke_ai_rules_t;



/*
const pvpoke_ai_rules_t AI_ARCHETYPES[] = {
                        {
    .two_charged_moves = true,
    .iv_combo_range = 0,
    .energy_guess_accuracy = 0,
    .reaction_time = 0,
    .move_guess_certainty = 0,
    .strategies = { DEFAULT_STRAT_M }
  }, {
    .two_charged_moves = false,
    .iv_combo_range = 3000,
    .energy_guess_accuracy = 15,
    .reaction_time = 12,
    .move_guess_certainty = 0,
    .strategies = { SHIELD_STRAT_M }
  }, {
    .two_charged_moves = true,
    .iv_combo_range = 2000,
    .energy_guess_accuracy = 10,
    .reaction_time = 8,
    .move_guess_certainty = 1,
    .strategies = { SHIELD_STRAT_M | SWITCH_BASIC_M }
  }, {
    .two_charged_moves = true,
    .iv_combo_range = 1000,
    .energy_guess_accuracy = 5,
    .reaction_time = 4,
    .move_guess_certainty = 2,
    .strategies = { SHIELD_STRAT_M | SWITCH_BASIC_M | FARM_ENERGY_M |
                               BAIT_SHIELDS_M }
  }, {
    .two_charged_moves = true,
    .iv_combo_range = 200,
    .energy_guess_accuracy = 0,
    .reaction_time = 0,
    .move_guess_certainty = 3,
    .strategies = { SHIELD_STRAT_M | SWITCH_BASIC_M | FARM_ENERGY_M |
                               OVERFARM_M | BAIT_SHIELDS_M | WAIT_CLOCK_M |
                               PRESERVE_SWITCH_ADVANTAGE_M |
                               ADVANCED_SHIELDING_M |
                               BAD_DECISION_PROTECTION_M | SACRIFICIAL_SWAP_M }
  }
};
*/



typedef enum packed {
  BOTH_BAIT, NEITHER_BAIT, NO_BAIT, FARM
} stype_t;


struct scenario_s {
  stype_t name;

  uint32_t * matchups;
  uint32_t average;
  uint8_t min_shields;
} packed;

typedef struct scenario_s scenario_t;




struct roster_performance_s {
  roster_pokemon_t * pokemon;
  scenario_t * scenarios;
  uint32_t average;
} packed;

typedef struct roster_performance_s roster_performance_t;






typedef enum packed {
  BASIC, BEST, COUNTER, UNBALANCED, SAME_TEAM, SAME_TEAM_DIFFERENT_LEAD,
  COUNTER_LAST_LEAD
} dtype_t;

struct decision_option_s {
  dtype_t name;
  uint32_t weight;
} packed;

typedef struct decision_option_s decision_option_t;





ai_status_t pvpoke_ai_select_team( roster_t * our_roster,
                                   roster_t * their_roser,
                                   pvp_team_t * team,
                                   void *
                                 );

ai_status_t pvpoke_ai_decide_action( bool decide_p1,
                                     const struct pvp_battle_s * battle,
                                     pvp_action_t * choice
                                   );

ai_status_t pvpoke_ai_init( ai_t * ai, void * init_aux );
void pvpoke_ai_free( ai_t * ai );
//__FROM__: include/ai/naive_ai.h
struct pvp_battle_s;




ai_status_t naive_ai_select_team( roster_t * our_roster,
                                  roster_t * their_roser,
                                  pvp_pokemon_t * team,
                                  store_t * store,
                                  void * aux
                                );

ai_status_t naive_ai_decide_action( bool decide_p1,
                                    const struct pvp_battle_s * battle,
                                    pvp_action_t * choice,
                                    void * aux
                                  );

ai_status_t naive_ai_init( ai_t * ai, void * init_aux );
void naive_ai_free( ai_t * ai );
