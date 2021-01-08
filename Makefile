# -*- mode: makefile-gmake -*-
# ============================================================================ #

.DEFAULT_GOAL := cpoke
.PHONY = clean check_gcc print_gcc_info gamemaster get_ordered_e

BINS := cpoke parse_gm fetch_gm test iv_store_build
all: ${BINS} cffi/data/all.E


# ---------------------------------------------------------------------------- #

CC = gcc
IS_OSX := $(shell ${CC} --version|grep -qi '\(apple\|llvm\|clang\)'           \
                    && echo 1 || echo 0)
CC_VERSION := $(shell ${CC} -dumpversion)
CC_V_MAJOR := $(shell ${CC} -dumpversion|cut -d'.' -f1)
CC_V_MINOR := $(shell ${CC} -dumpversion|cut -d'.' -f2)
CC_V_PATCH := $(shell ${CC} -dumpversion|cut -d'.' -f3)

check_gcc:
	@if [[ ${IS_OSX} = 1 ]]; then                                               \
		echo "You must use the REAL GCC, not Apple's Clang LLVM crap";            \
		echo "Download GCC using 'brew' or 'port', and make sure GCC is in PATH"; \
	  exit 1;                                                                   \
	fi

# GCC version will be verified FOR ALL make targets.
# If someone is trying to use Clang it should stop them.
ifeq "${IS_OSX}" "1"
*: check_gcc
endif


# ---------------------------------------------------------------------------- #

SRCPATH     = src
INCLUDEPATH = include
DEFSPATH    = data/defs

HEADERS := $(wildcard ${INCLUDEPATH}/*.h) $(wildcard ${INCLUDEPATH}/*/*.h)
SRCS    := $(wildcard ${SRCPATH}/*.c) $(wildcard ${SRCPATH}/*/*.c)

CURL_CFLAGS      = $(shell curl-config --cflags)
CURL_LINKERFLAGS = $(shell curl-config --libs)
PCRE_CFLAGS      = $(shell pcre-config --cflags)
PCRE_LINKERFLAGS = $(shell pcre-config --libs)

# `-fms-extensions' enables struct inheritence
CFLAGS      += -g -I${INCLUDEPATH} -I${DEFSPATH}
CFLAGS      += -fms-extensions -DJSMN_STATIC -std=gnu11 -fPIC
CFLAGS      += ${PCRE_CFLAGS}
LINKERFLAGS = -g -lm ${PCRE_LINKERFLAGS}


# ---------------------------------------------------------------------------- #

EXT_OBJECTS  := jsmn_iterator.o
UTIL_OBJECTS := files.o json_util.o

CORE_OBJECTS := pokemon.o ptypes.o pokedex.o moves.o
CORE_OBJECTS += ${UTIL_OBJECTS} ${EXT_OBJECTS}

SIM_OBJECTS := battle.o player.o
NAIVE_AI_OBJECTS := naive_ai.o

GM_OBJECTS := parse_gm.o gm_store.o fetch_gm.o
CSTORE_OBJECTS := cstore.o cstore_data.o

SUBTESTS := json pokemon ptypes parse_gm cstore battle player naive_ai filter
SUBTESTS += fuzzy
SUBTEST_OBJECTS := $(patsubst %,test_%.o,${SUBTESTS})
SUBTEST_MAIN_OBJECTS := $(patsubst %,test_%_main.o,${SUBTESTS})
SUBTEST_BINS := $(patsubst %,test_%,${SUBTESTS})


# ---------------------------------------------------------------------------- #

cpoke: main.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}


# ---------------------------------------------------------------------------- #

data/cstore_data.c: parse_gm fetch_gm
	./fetch_gm
	./parse_gm -f data/GAME_MASTER.json -e c > $@

cstore_data.o: data/cstore_data.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

# ---------------------------------------------------------------------------- #

parse_gm_main.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_PARSE_GM_BINARY -c $< -o $@

parse_gm: parse_gm_main.o gm_store.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}

# ---------------------------------------------------------------------------- #

iv_store_build_main.o: ${SRCPATH}/iv_store_build.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_IV_STORE_BUILD_BINARY -c $< -o iv_store_build_main.o

iv_store_build: iv_store_build_main.o cstore_data.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}

# ---------------------------------------------------------------------------- #

fetch_gm.o: ${SRCPATH}/fetch_gm.c ${HEADERS}
	${CC} ${CFLAGS} ${CURL_CFLAGS} -c $<

fetch_gm: fetch_gm.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS} ${CURL_LINKERFLAGS}


# ---------------------------------------------------------------------------- #

${UTIL_OBJECTS}: %.o: ${SRCPATH}/util/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

${EXT_OBJECTS}: %.o: ${SRCPATH}/ext/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

%.o: ${SRCPATH}/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# ---------------------------------------------------------------------------- #

${SUBTEST_OBJECTS} test.o: %.o: ${SRCPATH}/test/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

${SUBTEST_MAIN_OBJECTS} test_main.o: %_main.o: ${SRCPATH}/test/%.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_TEST_BINARY -c $< -o $@

${SUBTEST_BINS} test: %: %_main.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}

# Extra Dependencies:
test_battle: ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS}
test_pokemon: ${CSTORE_OBJECTS}
test: ${SUBTEST_OBJECTS} $(filter-out fetch_gm.o,${GM_OBJECTS})
test: ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS}

cffi/cpoke.so: $(filter-out fetch_gm.o,${GM_OBJECTS})
cffi/cpoke.so: ${CORE_OBJECTS} ${SUBTEST_OBJECTS}
cffi/cpoke.so: ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS}
	${CC} ${LINKERFLAGS} -shared $^ -o $@



# ---------------------------------------------------------------------------- #

# NOTE: `GAME_MASTER.json' files are currently broken since Niantic started
#       encoding them. For now we are working off of an old un-encrypted copy!
GM_URL := 'https://raw.githubusercontent.com/pokemongo-dev-contrib/pokemongo-'
GM_URL := ${GM_URL}'game-master/master/versions/latest/V2_GAME_MASTER.json'
data/GAME_MASTER.json: FORCE
	wget -O $@ ${GM_URL}

gamemaster: data/GAME_MASTER.json


# ---------------------------------------------------------------------------- #

# DO NOT DELETE GAME_MASTER.json or cstore_data.c
# - GAME_MASTER.json cannot be updated until pokemongo-dev fixes their repo.
# - cstore_data.c is time consuming to rebuild.
clean:
	@echo "Cleaning Up..."
	rm -rvf ./data/cstore_data.c ./data/GAME_MASTER.json;
	rm -rvf ./cffi/cpoke.so ./cffi/data/* ./cffi/include/*;
	rm -rvf *.o ${BINS} ${SUBTEST_BINS};


FORCE:


# ---------------------------------------------------------------------------- #

print_gcc_info:
	@echo "IS_OSX    : ${IS_OSX}"
	@echo "CC        : ${CC}"
	@echo "CC_VERSION: ${CC_VERSION}"
	@echo "CC_V_MAJOR: ${CC_V_MAJOR}"
	@echo "CC_V_MINOR: ${CC_V_MINOR}"
	@echo "CC_V_PATCH: ${CC_V_PATCH}"


# ---------------------------------------------------------------------------- #

cffi/data/%.proto: ${SRCPATH}/%.c ${HEADERS}
	mkdir -p $(@D)
	cproto  -I${INCLUDEPATH} -I${DEFSPATH} ${PCRE_CFLAGS} -s -i -v              \
          -DJSMN_STATIC -o $@ $< || true

ALL_PROTO = ${subst ${SRCPATH}/,cffi/data/,${subst .c,.proto,${SRCS}}}
cffi/data/all.proto: ${ALL_PROTO} ${HEADERS}
	cat ${ALL_PROTO} > cffi/data/all.proto

cffi/data/%.X: ${SRCPATH}/%.c ${HEADERS}
	mkdir -p $(@D)
	${CC} ${CFLAGS} -E $< > $@

ALL_X = ${subst ${SRCPATH}/,cffi/data/,${subst .c,.X,${SRCS}}}
cffi/data/all.X: ${ALL_X} ${HEADERS}
	cat ${ALL_X} > cffi/data/all.X


# ---------------------------------------------------------------------------- #

cffi/data/%.EE: ${INCLUDEPATH}/%.h  ${HEADERS}
	clang ${CFLAGS} -D'__attribute__(x)=' -P -E -nostdinc -nobuiltininc $< \
    > cffi/data/$@ 2>/dev/null || true

cffi/data/all.EE: ${HEADERS}
	clang ${CFLAGS} -D'__attribute__(x)=' -P -E -nostdinc -nobuiltininc         \
    ${HEADERS} > $@ 2>/dev/null || true

NO_INCLUDE_CFLAGS = -g -fms-extensions -DJSMN_STATIC -std=gnu11
cffi/data/%.E: ${INCLUDEPATH}/%.h  ${HEADERS}
	mkdir -p tmp/$(<D)
	mkdir -p $(@D)
	cp $< tmp/$<
	echo //__FROM__: $< > $@
	clang ${NO_INCLUDE_CFLAGS} -D'__attribute__(x)=' -P -E -nostdinc            \
    -nobuiltininc tmp/$< >> $@ 2>/dev/null || true
	rm -fr tmp

cffi/data/all.M:
	${CC} ${CFLAGS} -MM -MG ${SRCS} > cffi/data/all.M


# ---------------------------------------------------------------------------- #

ORDERED_E_CMD := "python3 cffi/hack_all_M.py|tail -n1|sed 's/^.* = //';"

get_ordered_e: cffi/data/all.M cffi/hack_all_M.py
	$(eval ORDERED_E :=$(shell sh -c ${ORDERED_E_CMD}) )

ALL_E := $(subst ${INCLUDEPATH}/,cffi/data/,${subst .h,.E,${HEADERS}})

cffi/data/all.E:  get_ordered_e ${ALL_E} ${HEADERS}
	cat ${ORDERED_E} > cffi/data/all.E


# ---------------------------------------------------------------------------- #



# ============================================================================ #
# vim: set filetype=make :
