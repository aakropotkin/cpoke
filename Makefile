# ========================================================================== #

.DEFAULT_GOAL := cpoke
.PHONY = all clean #gamemaster

CC = gcc

SRCPATH     = src
INCLUDEPATH = include
DEFSPATH    = data/defs

CURL_CFLAGS      = $(shell curl-config --cflags)
CURL_LINKERFLAGS = $(shell curl-config --libs)
PCRE_CFLAGS      = $(shell pcre-config --cflags)
PCRE_LINKERFLAGS = $(shell pcre-config --libs)

# `-fms-extensions' enables struct inheritence
CFLAGS      += -g -I${INCLUDEPATH} -I${DEFSPATH}
CFLAGS      += -fms-extensions -DJSMN_STATIC -std=gnu11
CFLAGS      += ${PCRE_CFLAGS}
LINKERFLAGS = -g -lm ${PCRE_LINKERFLAGS}

HEADERS := $(wildcard ${INCLUDEPATH}/*.h) $(wildcard ${INCLUDEPATH}/*/*.h)
SRCS    := $(wildcard ${SRCPATH}/*.c) $(wildcard ${SRCPATH}/*/*.c)
BINS    := cpoke parse_gm fetch_gm test iv_store_build

EXT_OBJECTS  := jsmn_iterator.o
UTIL_OBJECTS := files.o json_util.o

CORE_OBJECTS := pokemon.o ptypes.o pokedex.o moves.o
CORE_OBJECTS += ${UTIL_OBJECTS} ${EXT_OBJECTS}

CSTORE_OBJECTS := cstore.o cstore_data.o

SIM_OBJECTS := battle.o player.o

SUBTESTS := json pokemon ptypes parse_gm cstore battle player naive_ai
SUBTEST_OBJECTS := $(patsubst %,test_%.o,${SUBTESTS})
SUBTEST_MAIN_OBJECTS := $(patsubst %,test_%_main.o,${SUBTESTS})
SUBTEST_BINS := $(patsubst %,test_%,${SUBTESTS})

GM_OBJECTS := parse_gm.o gm_store.o fetch_gm.o

NAIVE_AI_OBJECTS := naive_ai.o


# -------------------------------------------------------------------------- #

cpoke: main.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

data/cstore_data.c: parse_gm
	./parse_gm -f data/GAME_MASTER.json -e c > $@

cstore_data.o: data/cstore_data.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

# -------------------------------------------------------------------------- #

parse_gm_main.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_PARSE_GM_BINARY -c $< -o $@

parse_gm: parse_gm_main.o gm_store.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@

# -------------------------------------------------------------------------- #

iv_store_build_main.o: ${SRCPATH}/iv_store_build.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_IV_STORE_BUILD_BINARY -c $< -o iv_store_build_main.o

iv_store_build: iv_store_build_main.o cstore_data.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@

# -------------------------------------------------------------------------- #

fetch_gm.o: ${SRCPATH}/fetch_gm.c ${HEADERS}
	${CC} ${CFLAGS} ${CURL_CFLAGS} -c $<

fetch_gm: fetch_gm.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} ${CURL_LINKERFLAGS} $^ -o $@


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
	${CC} ${LINKERFLAGS} $^ -o $@

# Extra Dependencies:
test_battle: ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS}
test_pokemon: ${CSTORE_OBJECTS}
test: ${SUBTEST_OBJECTS} $(filter-out fetch_gm.o,${GM_OBJECTS})
test: ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS}


# -------------------------------------------------------------------------- #

# NOTE: `GAME_MASTER.json' files are currently broken since Niantic started
#       encoding them. For now we are working off of an old un-encrypted copy!
# data/GAME_MASTER.json: FORCE
# 	wget -O $@ 'https://raw.githubusercontent.com/pokemongo-dev-contrib/pokemongo-game-master/master/versions/latest/V2_GAME_MASTER.json'

# gamemaster: data/GAME_MASTER.json


# -------------------------------------------------------------------------- #

clean:
	@echo "Cleaning Up..."
	rm -rvf *.o ${BINS} ${SUBTEST_BINS};


FORCE:

# ========================================================================== #
