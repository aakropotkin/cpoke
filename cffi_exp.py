# make cpoke.so
# To get inspiration for the function prototypes, for each .h,
# such as include/pokemon.h, use:
#   make pokemon.E
# which writes to data/pokemon.E using the -E feature of gcc (and redefines
# __attributes__ to disappear). From these, you can glean the structs and
# function prototypes.

from cffi import FFI

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

pokemon_simple_h = '''
/*
struct stats_s { uint16_t attack, stamina, defense; };
typedef struct stats_s stats_t;
*/

uint16_t get_cp_from_stats( stats_t base, stats_t ivs, float level );
stats_t get_effective_stats( stats_t base, stats_t ivs, float level );
uint16_t get_hp_from_stam_lv( uint16_t stam, float lv );
'''

def read_file(path):
    with open(path, 'rt') as f:
        return f.read()

cstore_h = read_file('cffi_exp_cstore_inc.h')

cdefs = header + cstore_h + pokemon_simple_h

ffi.cdef(cdefs)

tmp1 = ffi.new('stats_t[]', [(79, 99, 59)]) # ralt
tmp2 = ffi.new('stats_t[]', [(4, 6, 12)]) # iv
tmp_out = lib.get_cp_from_stats(tmp1[0], tmp2[0], 20.)
assert tmp_out == 255
print(tmp_out)

cstore_p = ffi.new('store_t *')
# lib.cstore_get()
