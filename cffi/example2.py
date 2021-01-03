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
'''

def read_file(path):
    with open(path, 'rt') as f:
        return f.read()

all_e = read_file('include/all.E2')

cdefs = header + all_e + extra_e

ffi.cdef(cdefs)

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

if False:
    cstore_p = lib.get_cstore_p()
    name = ffi.new('char[]', b'BULBASAUR')
    mon_pp = ffi.new('pdex_mon_t **')
    lib.cstore_get_pokemon_by_name(cstore_p, name, mon_pp)
    mon_p = mon_pp[0]
    print((mon_p.dex_number, ffi.string(mon_p.name), mon_p.types))

if False:
    name = ffi.new('char[]', b'BULBASAUR\x00')
    mon_pp = ffi.new('pdex_mon_t **')
    print(lib.get_pokemon_by_name(name, mon_pp))

pdb.set_trace()


