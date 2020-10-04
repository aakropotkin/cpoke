# cpoke
A Pokemon Go PvP Simulator written in C. The goal is to overcome many of the limitations imposed on PvPoke by JavaScript's memory management system, as well as eliminate the need for a Web Stack. Ultimately this codebase should aim to produce a variety of small re-usable functions and API which can easily be extended/used for other projects.

For example, `cpoke` may implement a GUI/TUI system, but the core code should not depend on these systems; which would limit the ability of future developers to use this simulator as a piece of their own project, with it's own GUI/TUI.


One of the core issues in PvPoke was it's memory management. While C is significantly more flexible in this regard, still be mindful to keep allocations to a minimum, and be as efficient as possible. The more lightweight the codebase can remain, the easier it will be to expand simulation detail. For example, simulating all pokemon with all movesets in all shield scenarios is simply not feasible if we are bogged down by poor MM. It is a slippery slope to start sacrificing movesets and pokemon selections to make up for slow simulations.


API/headers should operate in such a generalized that data sources ( whether by SQL, JSON Parsing, etc ) are abstracted away from the Simulator. Similarly the codebase should remain in separate modules such that shared objects may be compiled and wrapped by other languages, so that parts of this system might be used by Python, C++, etc without needing to modify the codebase extensively. Our own compilation can of course flatten these modules, optimizing out separations into a single binary for direct usage. See the headers `store.h` and `gm_store.h` for an example of an API/module definition and an implementation of that module.

## Dependencies
- `libpcre.so` and `pcre-config`
- `libcurl.so` and `curl-config` ( Optional: Required for `fetch_gm` )
- GCC ( Note to OSX users: the REAL GCC, provided by `brew`. Not that fake ass Xcode gcc-llvm shit! )


## Getting Started
The battle simulator was very recently completed, and you will notice that `main.c` is nearly empty at this point, instead I suggest building the following:

```sh
# In the root of the project
make test;
./test;
# Check for "FAIL" in the output
```


If you're new to the repo, you will find the most useful examples under `src/test/`, `test_battle.c` is most likely the file most people will be interested in.
The overview of how a battle simulations is first to define the pokemon which will be used, define the players' AI, and finally to run the simulation.

You can define a pokemon from scratch inline, but a pipeline exists for constructing an instance of `pvp_pokemon_t` used by the battle simulator from "pokedex" data `pdex_mon_t`. An abstract data provider interface `store_t` is used to organize most big collections of raw data, there are two implementations of that interace that can provide Pokedex and Move data. `gm_store` builds a data store directly from `GAME_MASTER.json`, and can export it's data to `JSON` or static `C`. A static dump of `gm_store` can be reloaded using `cstore`, which provides exactly the same data, but skips parsing of `GAME_MASTER.json`. In most cases you will likely prefer `cstore`, particularly because we do not currently support `GAME_MASTER_V2.json`. You will find examples of how to initialize a `cstore`, and use it to pull `pdex_mon_t` and `store_move_t` information to construct teams. `roster_pokemon_t` is an intermediary representation that represents a specific instance of a pokemon with IVs, level, and moves; eventually users will be able to import/export their pokemon collection using this type, ideally using CalcyIVs' format. Helper functions exist to convert `roster_pokemon_t` into `pvp_pokemon_t` and down the line they should similar be able to create `pve_pokemon_t` for Raid Simulations. Next we need to define the players' AI, for this an abstract `ai_t` interface exists to allow AI implementations to be swapped in and out. Currently only `naive_ai` exists, which essentially fights like a Rocket Grunt; `pvpoke_ai` is being implemented, and users are encouraged to define their own AIs as well. Once your AIs are loaded simply call `simulate_battle` to find out who the winner is!

A battle logging system needs to be implemented to get more interesting analysis from battles, but things are still early days so be patient or pitch in!


## COMPLETED
- Abstract interfaces for AI modules and Data Stores.
- Parsing and storage of `GAME_MASTER.json`.
- Functional Data Store for Pokemon (Pokedex) and PvP move data.
- Object definitions for most everything required by the PvP Simulator.
- Calculators for simulations. ( CP, Damage, etc... )
- Battle simulation. ( Testing should be extended )


## TODO
See "Projects" tab for full details.
- Battle logging and improved AI are the most pressing.
- Parsing of CalcyIV rosters.
- Data stores for rosters.
- CFFI Python Bindings.


## Notes
- "ext" files are those which are not authored by devs here, but have been included to lock versions/ease build process.
- Many "util" files are authored by alexameen for use across projects, and should not be explicitly targeted for `cpoke`. ( If you extend them, keep things genearalized for use in "any project" ).
- I am particularly picky about code formatting; but don't let that stop you from putting in PRs. Just don't be surprised if I swoop in and reformat after the fact. <3
- `fetch_gm` is currently broken! Sadly the release of `V2_GAME_MASTER.json` threw a wrench in things. Hopefully `pokemongodev`will decode those soon. For now we are working off an old V1 file. This is plenty to chew on at this stage, but it is missing Megas and any new changes that were released after the V2 encoding was cooked up.
