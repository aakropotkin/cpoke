{ -*- mode: pascal; -*- }

{ ============================================================================ }

program battle_simulator;

{
  Pseudocode Outline of Battle Simulator.

  The purpose of this file is to express the Battle Simulator's behavior in a
  language that nearly any programmer can read; and to consolidate the relevant
  structures/data types in one place for quick reference.

  I am ignoring Pascal naming conventions so that they match the names used
  in our C code.

  Some datatypes that are less relevant have been simplified and some fake
  functions with descriptive names ( marked by `_NR` for "not real" ) have been
  concocted to shorten some processes.

  I have not shortened/excluded any of the default values in the `init` and
  `reset` functions, since those values are likely relevant to those who
  implement AI modules.


  Pascal/C Equivelancies:

  `^ variant` is equivelant to `void *`

  `^` is used in place of `&` and `*` symbols from C.
  The only difference being that for pointers Pascal does `^ TYPENAME` rather
  than `TYPENAME *` in C.

  `^.` is used in place of `->` symbols from C.

  `new`/`dispose` are equivelant to `malloc`/`free`.

  `procedure`s as `function`s that do not have a return ( `void` in C ).

  `record`s are equivelant to `struct`s in C.

  Pascal returns values by setting the function name as if it were a variable
  withing the body `function foo : boolean; begin foo := true; end;`
}


{ ---------------------------------------------------------------------------- }

type
any_p = ^ variant;


{ ---------------------------------------------------------------------------- }

type
ptype_t = ( PT_NONE, BUG, DARK, DRAGON, ELECTRIC, FAIRY, FIGHTING, FIRE, FLYING,
            GHOST, GRASS, GROUND, ICE, NORMAL, POISON, PSYCHIC, ROCK, STEEL,
            WATER
          );

ptype_mask_t = longword;  { Represents a set of unique ptype_t values }

stats_t = record
             attack, stamina, defense : integer;
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
pvp_pokemon_p = ^ pvp_pokemon_t;


{ ---------------------------------------------------------------------------- }

type
store_t = variant;  { Not relevant here }
store_p = ^ store_t;


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
roster_p = ^ roster_t;


{ ---------------------------------------------------------------------------- }

type
ai_status_t = ( AI_NULL_STATUS, AI_SUCCESS, AI_ERROR_FAIL, AI_ERROR_BAD_VALUE,
                AI_ERROR_NOMEM
              );

select_team_fn = function( our_roster   : roster_p;
                           their_roster : roster_p;
                           team         : array[0..2] of pvp_pokemon_t;
                           store        : store_p;
                           aux          : any_p
                         ) : ai_status_t;

decide_action_fn = function( decide_p1 : boolean;
                             battle    : pvp_battle_p;
                             choice    : pvp_action_p;
                             aux       : any_p
                           ) : ai_status_t;

ai_init_fn = function( ai : ai_p; aux : any_p ) : ai_status_t;

ai_free_fn = procedure( ai : ai_p );

ai_t = record
          name                                      : string;
          select_team                               : select_team_fn;
          decide_action, decide_swap, decide_shield : decide_action_fn;
          init                                      : ai_init_fn;
          free                                      : ai_free_fn;
          aux                                       : any_p;
       end;
ai_p = ^ ai_t;


{ ---------------------------------------------------------------------------- }

type
pvp_player_t = record
                  ai                      : ai_p;
                  team                    : array[0..2] of pvp_pokemon_t;
                  active_pokemon, shields : 0 ... 2;
                  switch_turns            : 0 ... 5;
               end;
pvp_player_p = ^ pvp_player_t;


{ ---------------------------------------------------------------------------- }

type
pvp_action_t = ( ACT_NULL, FAST, WAIT, CHARGED1, CHARGED2, SWITCH1, SWITCH2,
                 SHIELD
               );
pvp_action_p = ^ pvp_action_t;

battle_phase_t = ( COUNTDOWN, NEUTRAL, SUSPEND_CHARGED, SUSPEND_CHARGED_ATTACK,
                   SUSPEND_CHARGED_SHIELD, SUSPEND_CHARGED_NO_SHIELD,
                   SUSPEND_SWITCH_P1, SUSPEND_SWITCH_P2, SUSPEND_SWITCH_TIE,
                   GAME_OVER
                 );

cmp_rule_t = ( CMP_IDEAL, CMP_ALTERNATE, CMP_FAVOR_P1, CMP_FAVOR_P2 );

pvp_battle_t = record
                  p1, p2               : pvp_player_p;
                  p1_action, p2_action : pvp_action_t;
                  stashed_action       : pvp_action_t;
                  turn, countdown      : integer;
                  phase                : battle_phase_t;
                  cmp_rule             : cmp_rule_t;
                  cmp_alt_state        : ( PLAYER1, PLAYER2 );
                  ai_aux_cache         : array[0..1] of any_p;
               end;
pvp_battle_p = ^ pvp_battle_t;


{ ============================================================================ }

const
   SWITCH_TIMEOUT_TURNS = 26


{ ============================================================================ }

procedure pvp_battle_init( battle : pvp_battle_p;
                           p1     : ai_p;
                           team1  : array[0..2] of pvp_pokemon_t;
                           aux1   : any_p;
                           p2     : ai_p;
                           team2  : array[0..2] of pvp_pokemon_t;
                           aux2   : any_p;
                         );
begin
   { Allocate Players }
   new( battle^.p1 );
   new( battle^.p2 );
   { Cache AI Aux Values }
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
          battle^.p1^.team[i].hp := calculate_hp_NR( battle^.p1^.team[i] );
          battle^.p1^.team[i].energy            := 0;
          battle^.p1^.team[i].buffs.atk_buff_lv := 0;
          battle^.p1^.team[i].buffs.def_buff_lv := 0;
          battle^.p1^.team[i].cooldown          := 0;

          battle^.p2^.team[i].hp := calculate_hp_NR( battle^.p2^.team[i] );
          battle^.p2^.team[i].energy            := 0;
          battle^.p2^.team[i].buffs.atk_buff_lv := 0;
          battle^.p2^.team[i].buffs.def_buff_lv := 0;
          battle^.p2^.team[i].cooldown          := 0;
      end;
end;


{ ---------------------------------------------------------------------------- }

procedure pvp_battle_reset( battle : pvp_battle_p );
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
          battle^.p1^.team[i].hp := calculate_hp_NR( battle^.p1^.team[i] );
          battle^.p1^.team[i].energy            := 0;
          battle^.p1^.team[i].buffs.atk_buff_lv := 0;
          battle^.p1^.team[i].buffs.def_buff_lv := 0;
          battle^.p1^.team[i].cooldown          := 0;

          battle^.p2^.team[i].hp := calculate_hp_NR( battle^.p2^.team[i] );
          battle^.p2^.team[i].energy            := 0;
          battle^.p2^.team[i].buffs.atk_buff_lv := 0;
          battle^.p2^.team[i].buffs.def_buff_lv := 0;
          battle^.p2^.team[i].cooldown          := 0;
      end;
end;

{ ---------------------------------------------------------------------------- }


procedure pvp_battle_free( battle : pvp_battle_p );
begin
   dispose( battle^.p1 );
   dispose( battle^.p2 );
   dispose( battle );
end;


{ ---------------------------------------------------------------------------- }

{ Helper to find the count of un-fainted pokemon for a given player }
function get_remaining_pokemon( player : pvp_player_p ) : boolean;
begin
    get_remaining_pokemon := 0;
    for i := 0 to 2 do
        if ( 0 < player^.team[i].hp ) then
            get_remaining_pokemon := get_remaining_pokemon + 1;
end;


{ ---------------------------------------------------------------------------- }

{ Determine if a given action would be valid for a given player based on the
  current battle state }
function is_valid_action( decide_p1 : boolean;
                          action    : pvp_action_t;
                          battle    : pvp_battle_p
                        ) : boolean;
var
  self   : pvp_player_p;
  active : pvp_pokemon_p;
begin
  if decide_p1 then self := battle^.p1 else self := battle^.p2;
  active := @ self^.team[self^.active_pokemon];

  case ( action ) of
    FAST:
      is_valid_action := ( battle^.phase = NEUTRAL ) and ( 0 < active^.hp );

    WAIT:
      is_valid_action := true;

    CHARGED1:
      is_valid_action := ( battle^.phase = NEUTRAL ) and ( 0 < active^.hp ) and
                         ( active^.chared_moves[0]^.energy <= active^.energy );

    CHARGED2:
      is_valid_action := ( battle^.phase = NEUTRAL ) and ( 0 < active^.hp ) and
                         ( active^.charged_moves[1].move_id <> 0 ) and
                         ( active^.chared_moves[1]^.energy <= active^.energy );

    SWITCH1:
      begin
        if ( 0 < active^.hp ) then
          is_valid_action := 1 < get_remaining_pokemon( player )
        else
          is_valid_action := 0 < get_remaining_pokemon( player )
      end;

    SWITCH2:
      begin
        if ( 0 < active^.hp ) then
          is_valid_action := 2 < get_remaining_pokemon( player )
        else
          is_valid_action := 1 < get_remaining_pokemon( player )
      end;

    SHIELD:
      is_valid_action := ( battle^.phase == SUSPEND_CHARGED ) and
                         ( 0 < self^.shields );

    else
      is_valid_action := false;
  end;
end;


{ ---------------------------------------------------------------------------- }

{ Decide the next action for the player indicated by `decide_p1` }
function decide_action( decide_p1 : boolean;
                        battle    : pvp_battle_p
                      ) : pvp_action_t;
var action : pvp_action_t;
begin
    action := ACT_NULL;
    { If player has cooldown remaining from a previous move they must wait. }
    if ( ( decide_p1 and then ( 0 < get_player_cooldown_NR( battle^.p1 ) ) ) or
         ( decide_p2 and then ( 0 < get_player_cooldown_NR( battle^.p2 ) ) )
       ) then
        action := WAIT
    else
    { Call the `decide_action` function for the player AI }
    if ( decide_p1 ) then
        battle^.p1^.ai^.decide_action( decide_p1,
                                       battle,
                                       @ action, { Set by reference }
                                       battle^.p1^.ai^.aux
                                     )
    else
        battle^.p2^.ai^.decide_action( decide_p1,
                                       battle,
                                       @ action, { Set by reference }
                                       battle^.p2^.ai^.aux
                                     );
    decide_action := action;
end;


{ ---------------------------------------------------------------------------- }

{ Helper to decrement a given Player's switch timer }
procedure decr_switch_timer( player : pvp_battle_p; x : integer );
if ( 0 < player^.switch_turns ) then
   player^.switch_turns := max( player^.switch_turns - x, 0 );


procedure handle_faints( p1_mon_alive, p2_mon_alive : boolean;
                         battle                     : pvp_battle_p
                       );
var
   target       : pvp_player_p;
begin
   swap_timeout := 0;
   target       := Nil;

   if ( not ( p1_mon_alive or p2_mon_alive ) ) then { Both Fainted }
      begin
         swap_timeout  := SWITCH_TIMEOUT_TURNS;
         battle^.phase := SUSPEND_SWITCH_TIE;
         battle^.p1_action = decide_swap( true, battle );
         battle^.p2_action = decide_swap( false, battle );
         while ( ( 0 < swap_timeout ) and
                 ( ( battle^.p1_action = WAIT ) or
                   ( battle^.p2_action = WAIT )
                 )
               ) do
            begin
               swap_timeout := swap_timeout - 1;
               eval_turn( battle );
               battle^.turn := battle^.turn + 1;
               decr_switch_timer( battle^.p1, 1 );
               decr_switch_timer( battle^.p2, 1 );

               if ( battle^.p1_action = WAIT ) then
                  begin
                     battle^.p1_action := ACT_NULL;
                     battle^.p1_action := decide_swap( true, battle );
                  end;
               if ( battle^.p2_action = WAIT ) then
                  begin
                      battle^.p2_action := ACT_NULL;
                      battle^.p2_action := decide_swap( false, battle );
                  end;
            end;
         { Check to see if anyone waited out the timer.
           force SWAP1 if they did }
      end;
end;


{ ---------------------------------------------------------------------------- }

function eval_turn_simulated( battle : pvp_battle_p ) : boolean;
begin
end;


{ ---------------------------------------------------------------------------- }

{ Helper to decrement a given Player's Active Pokemon's cooldown timer }
procedure decr_cooldown( player : pvp_battle_p; x : integer );
if ( 0 < player^.team[player^.active_pokemon].cooldown ) then
   player^.team[player^.active_pokemon].coodown :=
     max( player^.team[player^.active_pokemon].coodown - x, 0 );


{ Simulate a battle, return the number of turns evaluated. }
function simulate_battle( battle : pvp_battle_p ) : integer;
var p1_mon_alive, p2_mon_alive : boolean;
begin
    assert( battle^.phase = COOLDOWN );
    { Give opportunity to swap during countdown. }
    battle^.p1_action := decide_action( true, battle );
    battle^.p2_action := decide_action( false, battle );

    battle^.phase := NEUTRAL;
    p1_mon_alive  := true;
    p2_mon_alive  := true;

    while ( not eval_turn( battle ) ) do
        begin
            { Decrement Player Switch Timers }
            if ( 0 < battle^.p1^.switch_timer ) then
                battle^.p1^.switch_timer := battle^.p1^.switch_timer - 1;
            if ( 0 < battle^.p2^.switch_timer ) then
                battle^.p2^.switch_timer := battle^.p2^.switch_timer - 1;

            { Decrement Cooldown of Players Active Pokemon }
            decr_cooldown( battle^.p1, 1 );
            decr_cooldown( battle^.p2, 1 );

            battle^.turn := battle^.turn + 1;

            battle^.p1_action := decide_action( true, battle );
            battle^.p2_action := decide_action( false, battle );

            { FIXME: Handle Swap }
            { FIXME: Handle Charged Moves/Shields here }
            { FIXME: Check CMP Ties when both use Charged }
            { FIXME: Stash action for Shielder }
            { FIXME: Decide shield }
            { FIXME: Apply Charged Damage/Expend Shield }
            { FIXME: Handle faint for shielder }
            { FIXME: Pop stashed action }
            { FIXME: If action is Charged, Decide shield ( no stash ) }
            { FIXME: Apply Charged Damage/Expend Shield or apply Fast Damage }

            { Handle Faints }
            p1_mon_alive := is_active_pokemon_alive( battle^.p1 );
            p2_mon_alive := is_active_pokemon_alive( battle^.p2 );
            if ( not ( p1_mon_alive or p2_mon_alive ) ) then
                handle_faints( p1_mon_alive, p2_mon_alive, battle );
        end;

    battle^.phase := GAME_OVER;

    simulate_battle := battle^.turn;
end;


{ ---------------------------------------------------------------------------- }



{ ============================================================================ }

{ vim: set filetype=pascal : }
