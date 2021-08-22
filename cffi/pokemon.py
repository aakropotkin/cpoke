import cpoke_ffi as cpoke


def get_pokemon(dex_num, form_idx, scope):
    mon_pp = cpoke.ffi.new('pdex_mon_t **')
    scope.append(mon_pp)
    cpoke.require_success(cpoke.lib.cstore_get_pokemon(cpoke.cstore_p, dex_num, form_idx, mon_pp), 'cstore_get_pokemon failure.')
    return mon_pp[0]


def generate_pokedex(scope):
    dex_num = 1
    while True:
        try:
            for form_idx in range(5):
                try:
                    mon = get_pokemon(dex_num, form_idx, scope)
                    yield mon
                except cpoke.StoreStatus as ss:
                    if form_idx == 0:
                        raise ss
                else:
                    break
        except cpoke.StoreStatus:
            raise StopIteration
        dex_num += 1


def pokemon_fast_move_ids(mon):
    """mon::pdex_mon_t *"""
    return [mon.fast_move_ids[i] for i in range(mon.fast_moves_cnt)]


def pokemon_charged_move_ids(mon):
    """mon::pdex_mon_t *"""
    return [mon.charged_move_ids[i] for i in range(mon.charged_moves_cnt)]


def construct_roster_pokemon(dex_num: int, form_idx: int, level: float, attack: int, stamina: int, defense: int, fast_move_id: int, charge_move_id1: int, charge_move_id2: int, scope: list):
    base = cpoke.ffi.new('base_pokemon_t *')
    rost = cpoke.ffi.new('roster_pokemon_t *')
    rost.base = base
    rost.fast_move_id = fast_move_id
    rost.charged_move_ids = (charge_move_id1, charge_move_id2)
    cpoke.require_success(cpoke.lib.base_mon_from_store(cpoke.cstore_p, dex_num, form_idx, level, attack, stamina, defense, base),
                          'base_mon_from_store failure.')
    scope.extend((base, rost))
    return rost


def construct_league_optimal_pokemon(dex_num: int, form_idx: int, max_cp: int, fast_move_id: int, charge_move_id1: int, charge_move_id2: int, scope: list):
    mon_pp = cpoke.ffi.new('pdex_mon_t **')
    cpoke.require_success(cpoke.lib.cstore_get_pokemon(cpoke.cstore_p, dex_num, form_idx, mon_pp), 'cstore_get_pokemon failure.')
    base = cpoke.ffi.new('base_pokemon_t *')
    rost = cpoke.ffi.new('roster_pokemon_t *')
    new_stats_p = cpoke.ffi.new('stats_t *')
    new_lv_p = cpoke.ffi.new('float *')
    ok = cpoke.lib.brute_maximize_ivs(max_cp, mon_pp[0].base_stats, new_stats_p, new_lv_p)
    assert ok
    rost.base = base
    rost.fast_move_id = fast_move_id
    rost.charged_move_ids = (charge_move_id1, charge_move_id2)
    cpoke.require_success(cpoke.lib.base_mon_from_store(
        cpoke.cstore_p, dex_num, form_idx, new_lv_p[0], new_stats_p.attack,
        new_stats_p.stamina, new_stats_p.defense, base), 'base_mon_from_store failure.')
    scope.extend((base, rost))
    return rost

import pdb
scope = []

for i, mon in enumerate(generate_pokedex(scope)):
    print(i, cpoke.cdata_dict(mon))
    if i > 10:
        break

# pdb.set_trace()
mon = get_pokemon(3, 0, scope)
#move_id = 214
move_id = 13
store_move_p = cpoke.ffi.new('store_move_t *')
store_move_pp = cpoke.ffi.new('store_move_t **')
store_move_pp[0] = store_move_p

rsl = cpoke.lib.cstore_get_move(cpoke.cstore_p, move_id, store_move_pp)



cpoke.dump(mon)
rost_ven = construct_league_optimal_pokemon(3, 0, 2500, 214, 296, 90, scope)


# works:
#cpoke.lib.do_printf(b"hi\0")
# doesn't:
#cpoke.lib.test_stuff()
# cpoke.lib.test_cstore_get_pokemon_by_name()
