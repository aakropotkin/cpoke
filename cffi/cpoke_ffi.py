from cffi import FFI

ffi = FFI()

lib = ffi.dlopen('./cpoke.so')
# print('Loaded lib {0}'.format(lib))

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
bool test_cstore_get_pokemon_by_name();
'''

def read_file(path):
    with open(path, 'rt') as f:
        return f.read()

all_e = read_file('include/all.E2')

cdefs = header + all_e + extra_e

ffi.cdef(cdefs)
cstore_p = lib.get_cstore_p()


def cdata_dict1(x):
    if x == ffi.NULL or not isinstance(x, ffi.CData):
        return x
    return {key: getattr(x, key) for key in dir(x)}


def cdata_dict(x, expand_char_star=True):
    if x == ffi.NULL:
        return x
    if not isinstance(x, ffi.CData) or len(dir(x)) == 0:
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


class CpokeError(Exception):
    pass


class StoreStatus(CpokeError):
    pass


def require_success(rsl, message):
    if rsl != lib.STORE_SUCCESS:
        raise StoreStatus(message + f':{rsl}')


def dump(x):
    print(cdata_dict(x))
    
