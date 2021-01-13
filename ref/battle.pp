{ -*- mode: pascal; -*- }

{ ============================================================================ }

program battle_simulator;

{
  Pseudocode Outline of Battle Simulator.

  Pascal was simply a convenient filetype for my editor's syntax highlighting
  I am ignoring Pascal's naming conventions so that they match the names used
  in our C code.

  `^ variant' is equivelant to `void *'

  `^' is used in place of `*' and `&' symbols from C.
}


{ ---------------------------------------------------------------------------- }

type
ptype_t = ( PT_NONE, BUG, DARK, DRAGON, ELECTRIC, FAIRY, FIGHTING, FIRE, FLYING,
            GHOST, GRASS, GROUND, ICE, NORMAL, POISON, PSYCHIC, ROCK, STEEL,
            WATER
          );

ptype_mask_t = longword;  { Represents a set of unique ptype_t values }

stats_t = record
             attack, stamina defense : integer;
          end;


{ ---------------------------------------------------------------------------- }

type
buff_chance_t = ( 1.0, 0.5, 0.3, 0.125, 0.1, 0.0 );

stat_buff_t = record
                 target  : ( SELF, OPPONENT );
                 debuffp : ( BUFF, DEBUFF );
                 amount  : ( BUFF_NONE, BUFF_NORMAL, BUFF_HARSH, BUFF_SHARP );
              end;

buff_t = record
            chance             : buff_chance_t;
            atk_buff, def_buff : stat_buff_t;
         end;

buff_level_t = -4 ... 4;

buff_state_t = record
                  atk_buff_lv, def_buff_lv : buff_level_t;
               end;


{ ---------------------------------------------------------------------------- }

type
pvp_fast_move_t = record
                     move_id       : integer;
                     type_         : ptype_t;  { Actually named `type' }
                     power, energy : integer;
                     turns         : 1 ... 4;
                  end;

pvp_charged_move_t = record
                        move_id       : integer;
                        type_         : ptype_t;  { Actually named `type' }
                        power, energy : integer;
                        buff          : buff_t;
                     end;


{ ---------------------------------------------------------------------------- }

type
pvp_pokemon_t = record
                   level                : 2 ... 100;  { x2 in game level }
                   stats                : stats_t;
                   types                : ptype_mask_t;
                   hp, cooldown, energy : integer;
                   buffs                : buff_state_t;
                   fast_move            : pvp_fast_move_t;
                   charged_moves        : array[0..1] of pvp_charged_move_t;
                end;


{ ---------------------------------------------------------------------------- }

type store_t = variant;  { Not relevant here }


{ ---------------------------------------------------------------------------- }

type
base_pokemon_t = record
                    level             : 2 ... 100;  { x2 in game level }
                    stats             : stats_t;
                    types             : ptype_mask_t;
                    fast_move_id      : integer;
                    charged_moves_ids : array[0..1] of integer;
                 end;

roster_t = array of base_pokemon_t;


{ ---------------------------------------------------------------------------- }

type
ai_status_t = ( AI_NULL_STATUS, AI_SUCCESS, AI_ERROR_FAIL, AI_ERROR_BAD_VALUE,
                AI_ERROR_NOMEM
              );

select_team_fn = function( our_roster   : ^ roster_t,
                           their_roster : ^ roster_t,
                           team         : array[0..2] of pvp_pokemon_t,
                           store        : ^ store_t,
                           aux          : ^ variant
                         ) : ai_status_t;

decide_action_fn = function( decide_p1 : bool,
                             battle    : ^ pvp_battle_t,
                             choice    : ^ pvp_action_t,
                             aux       : ^ variant
                           ) : ai_status_t;

ai_init_fn = function( ai : ^ ai_t, aux : ^ variant ) : ai_status_t;

ai_free_fn = procedure( ai : ^ ai_t );

ai_t = record
          name                                      : string;
          select_team                               : select_team_fn;
          decide_action, decide_swap, decide_shield : decide_action_fn;
          init                                      : ai_init_fn;
          free                                      : ai_free_fn;
          aux                                       : ^ variant;
       end;


{ ---------------------------------------------------------------------------- }

type
pvp_player_t = record
                  ai                      : ^ ai_t;
                  team                    : array[0..2] of pvp_pokemon_t;
                  active_pokemon, shields : 0 ... 2;
                  switch_turns            : 0 ... 5;
               end;


{ ---------------------------------------------------------------------------- }

type
pvp_action_t = ( ACT_NULL, FAST, WAIT, CHARGED1, CHARGED2, SWITCH1, SWITCH2,
                 SHIELD
               );

battle_phase_t = ( COUNTDOWN, NEUTRAL, SUSPEND_CHARGED, SUSPEND_CHARGED_ATTACK,
                   SUSPEND_CHARGED_SHIELD, SUSPEND_CHARGED_NO_SHIELD,
                   SUSPEND_SWITCH_P1, SUSPEND_SWITCH_P2, SUSPEND_SWITCH_TIE,
                   GAME_OVER
                 );

cmp_rule_t = ( CMP_IDEAL, CMP_ALTERNATE, CMP_FAVOR_P1, CMP_FAVOR_P2 );

pvp_battle_t = record
                  p1, p2               : ^ pvp_player_t;
                  p1_action, p2_action : pvp_action_t;
                  stashed_action       : pvp_action_t;
                  turn                 : integer;
                  phase                : battle_phase_t;
                  cmp_rule             : cmp_rule_t;
                  cmp_alt_state        : ( PLAYER1, PLAYER2 );
                  ai_aux_cache         : array[0..1] of ^ variant;
               end;


{ ---------------------------------------------------------------------------- }

procedure pvp_battle_init( battle : ^ pvp_battle_t;
                           p1     : ^ ai_t;
                           team1  : array[0..2] of pvp_pokemon_t;
                           aux1   : ^ variant;
                           p2     : ^ ai_t;
                           team2  : array[0..2] of pvp_pokemon_t;
                           aux2   : ^ variant;
                         );
begin
   { Allocate Players }
   new( battle^.p1 );
   new( battle^.p2 );
   { Cache AI Aux values }
   battle^.ai_aux_cache[0] := aux1;
   battle^.ai_aux_cache[1] := aux2;
   { Initialize AI }
   battle^.p1^.ai := p1;
   battle^.p2^.ai := p2;
   battle^.p1^.ai^.init( battle^.p1^.ai, aux1 );
   battle^.p2^.ai^.init( battle^.p2^.ai, aux2 );
   { Set Initial Battle State }
   battle^.p1_action      := ACT_NULL;
   battle^.p2_action      := ACT_NULL;
   battle^.stashed_action := ACT_NULL;
   battle^.turn           := 0;
   battle^.phase          := COUNTDOWN;
   battle^.cmp_alt_state  := PLAYER1;

   { Copy Teams }
   for i := 0 to 2 do
      begin
         battle^.p1^.team[i] := team1[i];
         battle^.p2^.team[i] := team2[i];
      end;

   { Set Initial Player State }
   battle^.p1^.active_pokemon := 0;
   battle^.p1^.shields        := 2;
   battle^.p1^.switch_turns   := 0;

   battle^.p2^.active_pokemon := 0;
   battle^.p2^.shields        := 2;
   battle^.p2^.switch_turns   := 0;

   { Set Initial Pokemon State }
   for i := 0 to 2 do
      begin
          battle^.p1^.team[i].hp := calculate_hp( battle^.p1^.team[i] );
          battle^.p1^.team[i].energy            := 0;
          battle^.p1^.team[i].buffs.atk_buff_lv := 0;
          battle^.p1^.team[i].buffs.def_buff_lv := 0;
          battle^.p1^.team[i].cooldown          := 0;

          battle^.p2^.team[i].hp := calculate_hp( battle^.p1^.team[i] );
          battle^.p2^.team[i].energy            := 0;
          battle^.p2^.team[i].buffs.atk_buff_lv := 0;
          battle^.p2^.team[i].buffs.def_buff_lv := 0;
          battle^.p2^.team[i].cooldown          := 0;
      end;
end;


{ ---------------------------------------------------------------------------- }

procedure pvp_battle_reset( battle : ^ pvp_battle_t );
begin
   { Reset Battle State }
   battle^.p1_action      := ACT_NULL;
   battle^.p2_action      := ACT_NULL;
   battle^.stashed_action := ACT_NULL;
   battle^.turn           := 0;
   battle^.phase          := COUNTDOWN;
   battle^.cmp_alt_state  := PLAYER1;

   { Reset Player State }
   battle^.p1^.active_pokemon := 0;
   battle^.p1^.shields        := 2;
   battle^.p1^.switch_turns   := 0;

   battle^.p2^.active_pokemon := 0;
   battle^.p2^.shields        := 2;
   battle^.p2^.switch_turns   := 0;

   { Reset Pokemon State }
   for i := 0 to 2 do
      begin
          battle^.p1^.team[i].hp := calculate_hp( battle^.p1^.team[i] );
          battle^.p1^.team[i].energy            := 0;
          battle^.p1^.team[i].buffs.atk_buff_lv := 0;
          battle^.p1^.team[i].buffs.def_buff_lv := 0;
          battle^.p1^.team[i].cooldown          := 0;

          battle^.p2^.team[i].hp := calculate_hp( battle^.p1^.team[i] );
          battle^.p2^.team[i].energy            := 0;
          battle^.p2^.team[i].buffs.atk_buff_lv := 0;
          battle^.p2^.team[i].buffs.def_buff_lv := 0;
          battle^.p2^.team[i].cooldown          := 0;
      end;
end;

{ ---------------------------------------------------------------------------- }


procedure pvp_battle_free( battle : ^ pvp_battle_t );
begin
   dispose( battle^.p1 );
   dispose( battle^.p2 );
   dispose( battle );
end;



{ ---------------------------------------------------------------------------- }



{ ============================================================================ }

{ vim: set filetype=pascal : }
