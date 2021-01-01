# -*- mode: makefile-gmake -*-
# =========================================================================== #

.DEFAULT_GOAL := cpoke
.PHONY = clean check_gcc print_gcc_info #gamemaster

BINS := cpoke parse_gm fetch_gm test iv_store_build
all: ${BINS}


# --------------------------------------------------------------------------- #

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


# --------------------------------------------------------------------------- #

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
CFLAGS      += -fms-extensions -DJSMN_STATIC -std=gnu11
CFLAGS      += ${PCRE_CFLAGS}
LINKERFLAGS = -g -lm ${PCRE_LINKERFLAGS}


# --------------------------------------------------------------------------- #

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


# -------------------------------------------------------------------------- #

cpoke: main.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}


# -------------------------------------------------------------------------- #

data/cstore_data.c: parse_gm fetch_gm
	./fetch_gm
	./parse_gm -f data/GAME_MASTER.json -e c > $@

cstore_data.o: data/cstore_data.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

# -------------------------------------------------------------------------- #

parse_gm_main.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_PARSE_GM_BINARY -c $< -o $@

parse_gm: parse_gm_main.o gm_store.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}

# -------------------------------------------------------------------------- #

iv_store_build_main.o: ${SRCPATH}/iv_store_build.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_IV_STORE_BUILD_BINARY -c $< -o iv_store_build_main.o

iv_store_build: iv_store_build_main.o cstore_data.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS}

# -------------------------------------------------------------------------- #

fetch_gm.o: ${SRCPATH}/fetch_gm.c ${HEADERS}
	${CC} ${CFLAGS} ${CURL_CFLAGS} -c $<

fetch_gm: fetch_gm.o ${CORE_OBJECTS}
	${CC} $^ -o $@ ${LINKERFLAGS} ${CURL_LINKERFLAGS}


# -------------------------------------------------------------------------- #

${UTIL_OBJECTS}: %.o: ${SRCPATH}/util/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

${EXT_OBJECTS}: %.o: ${SRCPATH}/ext/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

%.o: ${SRCPATH}/%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

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

cpoke.so: ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS} ${CORE_OBJECTS} ${SUBTEST_OBJECTS} $(filter-out fetch_gm.o,${GM_OBJECTS})
	${CC} ${LINKERFLAGS} -shared $^ -o $@



# -------------------------------------------------------------------------- #

# NOTE: `GAME_MASTER.json' files are currently broken since Niantic started
#       encoding them. For now we are working off of an old un-encrypted copy!
data/GAME_MASTER.json: FORCE
	wget -O $@ 'https://raw.githubusercontent.com/pokemongo-dev-contrib/pokemongo-game-master/master/versions/latest/V2_GAME_MASTER.json'

gamemaster: data/GAME_MASTER.json


# -------------------------------------------------------------------------- #

# DO NOT DELETE GAME_MASTER.json or cstore_data.c
# - GAME_MASTER.json cannot be updated until pokemongo-dev fixes their repo.
# - cstore_data.c is time consuming to rebuild.
clean:
	@echo "Cleaning Up..."
	rm -rvf ./data/cstore_data.c ./data/GAME_MASTER.json;
	rm -rvf *.o ${BINS} ${SUBTEST_BINS};


FORCE:


# -------------------------------------------------------------------------- #

print_gcc_info:
	@echo "IS_OSX    : ${IS_OSX}"
	@echo "CC        : ${CC}"
	@echo "CC_VERSION: ${CC_VERSION}"
	@echo "CC_V_MAJOR: ${CC_V_MAJOR}"
	@echo "CC_V_MINOR: ${CC_V_MINOR}"
	@echo "CC_V_PATCH: ${CC_V_PATCH}"


# -------------------------------------------------------------------------- #



# ========================================================================== #
# vim: set filetype=make :

%.E: ${INCLUDEPATH}/%.h  ${HEADERS}
	clang ${CFLAGS} -D'__attribute__(x)=' -P -E -nostdinc -nobuiltininc $< > data/$@ 2>/dev/null || true
#	${CC} ${CFLAGS} -D'__attribute__(x)=' -E $< > data/$@

all_e: ${HEADERS}
	clang ${CFLAGS} -D'__attribute__(x)=' -P -E -nostdinc -nobuiltininc ${HEADERS} > data/$@ 2>/dev/null || true

