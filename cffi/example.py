# make cffi/cpoke.so

from cffi import FFI
import pdb

ffi = FFI()

lib = ffi.dlopen('./cpoke.so')
print('Loaded lib {0}'.format(lib))

header = '''
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
'''

extra_e = '''
const store_t *get_cstore_p();
int get_pokemon_by_name(        const char *  name,
                                pdex_mon_t ** mon
				);

const store_t CSTORE;
int do_printf(char *s);
bool test_stuff();

static bool test_cstore_get_pokemon(void);
static bool test_cstore_get_pokemon_by_name(void);
static bool test_cstore_get_move(void);
static bool test_cstore_get_move_by_name(void);
static bool test_cstore_get(void);

'''

def read_file(path):
    with open(path, 'rt') as f:
        return f.read()

all_e = read_file('include/all.E2')

cdefs = header + all_e + extra_e

ffi.cdef(cdefs)


def cdata_dict1(x):
    if x == ffi.NULL or not isinstance(x, ffi.CData):
        return x
    return {key: getattr(x, key) for key in dir(x)}

def cdata_dict(x, expand_char_star=True):
    if x == ffi.NULL or not isinstance(x, ffi.CData) or len(dir(x)) == 0:
        if expand_char_star and repr(x).startswith("<cdata 'char *'"):
            return ffi.string(x)
        return x
    return {key: cdata_dict(getattr(x, key)) for key in dir(x)}


def dump_mro(x):
    for u in x.__class__.mro():
        print(dir(u))

def all_members(aClass):
    try:
        # Try getting all relevant classes in method-resolution order
        mro = list(aClass.__mro__)
    except AttributeError:
        # If a class has no __mro__, then it's a classic class
        def getmro(aClass, recurse):
            mro = [aClass]
            for base in aClass.__bases__: mro.extend(recurse(base, recurse))
            return mro
        mro = getmro(aClass, getmro)
    mro.reverse()
    members = {}
    for someClass in mro: members.update(vars(someClass))
    return members



tmp1 = ffi.new('stats_t[]', [(79, 99, 59)]) # ralt
tmp2 = ffi.new('stats_t[]', [(4, 6, 12)]) # iv
tmp_out = lib.get_cp_from_stats(tmp1[0], tmp2[0], 20.)
assert tmp_out == 255
print(tmp_out)

cstore_p = lib.get_cstore_p()
mon_pp = ffi.new('pdex_mon_t **')
lib.cstore_get_pokemon(cstore_p, 1, 0, mon_pp)
mon_p = mon_pp[0]
print((mon_p.dex_number, ffi.string(mon_p.name), mon_p.types))
print(cdata_dict(mon_p))

if False:
    cstore_p = lib.get_cstore_p()
    name = ffi.new('char[]', b'BULBASAUR')
    mon_pp = ffi.new('pdex_mon_t **')
    pdb.set_trace()
    lib.cstore_get_pokemon_by_name(cstore_p, name, mon_pp)
    mon_p = mon_pp[0]
    print((mon_p.dex_number, ffi.string(mon_p.name), mon_p.types))

if False:
    cstore_p = lib.get_cstore_p()
    name = ffi.new('char[]', b'WRAP')
    move_pp = ffi.new('store_move_t **')
    lib.cstore_get_move_by_name(cstore_p, name, move_pp)

if False:
    name = ffi.new('char[]', b'BULBASAUR\x00')
    mon_pp = ffi.new('pdex_mon_t **')
    print(lib.get_pokemon_by_name(name, mon_pp))


if False:
    base_ven = ffi.new('base_pokemon_t *')
    rost_ven = ffi.new('roster_pokemon_t *')
    rost_ven.base = base_ven
    rost_ven.fast_move_id = 214 # Vine Whip
    rost_ven.charged_move_ids = (296, 90) # Frenzy Plant, Sludge Bomb
    lib.base_mon_from_store(cstore_p, 1, 0, 20., 15, 15, 15, base_ven)
    isinstance( rost_ven.base[0].ivs, ffi.CData)
    print(cdata_dict(rost_ven.base[0].ivs))
    print(cdata_dict(rost_ven))

    
def construct_roster_pokemon(dex_num: int, form_idx: int, level: float, attack: int, stamina: int, defense: int, fast_move_id: int, charge_move_id1: int, charge_move_id2: int, scope: list):
    base = ffi.new('base_pokemon_t *')
    rost = ffi.new('roster_pokemon_t *')
    rost.base = base
    rost.fast_move_id = fast_move_id # Vine Whip
    rost.charged_move_ids = (charge_move_id1, charge_move_id2)
    rsl = lib.base_mon_from_store(cstore_p, dex_num, form_idx, level, attack, stamina, defense, base)
    assert rsl == lib.STORE_SUCCESS
    scope.extend((base, rost))
    return rost

def construct_naive_ai(scope):
    p1_ai = ffi.new('ai_t *')
    p1_ai_name = ffi.new('char[]', b'Naive AI')
    p1_ai.name = p1_ai_name
    # p1_ai.select_team = ffi.addressof(lib, 'naive_ai_select_team')
    p1_ai.select_team = lib.naive_ai_select_team
    p1_ai.decide_action = lib.naive_ai_decide_action
    p1_ai.init = lib.naive_ai_init
    p1_ai.free = lib.naive_ai_free
    p1_ai.aux = ffi.NULL
    scope.extend((p1_ai, p1_ai_name))
    return p1_ai
    
scope = []
rost_ven = construct_roster_pokemon(1, 0, 20., 15, 15, 15, 214, 296, 90, scope)
print(cdata_dict(rost_ven))
rost_vap = construct_roster_pokemon(134, 0, 20., 15, 15, 15, 230, 58, 300, scope)
print(cdata_dict(rost_vap))

p1_ai = construct_naive_ai(scope)
p2_ai = construct_naive_ai(scope)

p1 = ffi.new('pvp_player_t *')
p2 = ffi.new('pvp_player_t *')
a1 = ffi.new('pvp_action_t *')
a2 = ffi.new('pvp_action_t *')
battle = ffi.new('pvp_battle_t *')

#lib.pvp_pokemon_init(p1.team + 0, rost_ven, cstore_p)
#lib.pvp_pokemon_init(p2.team + 0, rost_vap, cstore_p)

# assert p1.team[0].fast_move.move_id == 214

pdb.set_trace()

