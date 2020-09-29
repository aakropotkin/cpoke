# ========================================================================== #


.DEFAULT_GOAL := cpoke
.PHONY = all clean gamemaster

CC = gcc

SRCPATH     = src
INCLUDEPATH = include
DEFSPATH    = data/defs

# `-fms-extensions' enables struct inheritence
CFLAGS      += -g -I${INCLUDEPATH} -I${DEFSPATH} -fms-extensions -DJSMN_STATIC
LINKERFLAGS = -g -lm $(shell curl-config --libs)

HEADERS := $(wildcard ${INCLUDEPATH}/*.h) $(wildcard ${INCLUDEPATH}/*/*.h)
SRCS    := $(wildcard ${SRCPATH}/*.c) $(wildcard ${SRCPATH}/*/*.c)
BINS    := cpoke parse_gm fetch_gm test

EXT_OBJECTS  := jsmn_iterator.o
UTIL_OBJECTS := files.o json_util.o

CORE_OBJECTS := pokemon.o ptypes.o pokedex.o moves.o
CORE_OBJECTS += ${UTIL_OBJECTS} ${EXT_OBJECTS}

CSTORE_OBJECTS := cstore.o cstore_data.o

SIM_OBJECTS := battle.o player.o

TEST_OBJECTS := test_json.o test_pokemon.o test_ptypes.o test_parse_gm.o
TEST_OBJECTS += test_cstore.o test_battle.o test_player.o test_naive_ai.o

GM_OBJECTS := parse_gm.o gm_store.o fetch_gm.o

NAIVE_AI_OBJECTS := naive_ai.o

TEST_DEPS := ${CORE_OBJECTS} ${TEST_OBJECTS} parse_gm.o gm_store.o
TEST_DEPS += ${CSTORE_OBJECTS} ${SIM_OBJECTS} ${NAIVE_AI_OBJECTS}


# -------------------------------------------------------------------------- #

main.o: ${SRCPATH}/main.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

cpoke: main.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

cstore.o: ${SRCPATH}/cstore.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

data/cstore_data.c: parse_gm
	./parse_gm -f data/GAME_MASTER.json -e c > $@

cstore_data.o: data/cstore_data.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

gm_store.o: ${SRCPATH}/gm_store.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

parse_gm.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

parse_gm_main.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_PARSE_GM_BINARY -c $< -o parse_gm_main.o

parse_gm: parse_gm_main.o gm_store.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

fetch_gm.o: ${SRCPATH}/fetch_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

fetch_gm: fetch_gm.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

pokedex.o: ${SRCPATH}/pokedex.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

pokemon.o: ${SRCPATH}/pokemon.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

ptypes.o: ${SRCPATH}/ptypes.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

moves.o: ${SRCPATH}/moves.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

battle.o: ${SRCPATH}/battle.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

player.o: ${SRCPATH}/player.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

naive_ai.o: ${SRCPATH}/naive_ai.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

files.o: ${SRCPATH}/util/files.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

json_util.o: ${SRCPATH}/util/json_util.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

jsmn_iterator.o: ${SRCPATH}/ext/jsmn_iterator.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

test_json.o: ${SRCPATH}/test/test_json.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_pokemon.o: ${SRCPATH}/test/test_pokemon.c ${HEADERS}
	${CC} ${CFLAGS} -I. -c $<

test_ptypes.o: ${SRCPATH}/test/test_ptypes.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_parse_gm.o: ${SRCPATH}/test/test_parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_cstore.o: ${SRCPATH}/test/test_cstore.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_battle.o: ${SRCPATH}/test/test_battle.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_naive_ai.o: ${SRCPATH}/test/test_naive_ai.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_player.o: ${SRCPATH}/test/test_player.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test.o: ${SRCPATH}/test/test.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_main.o: ${SRCPATH}/test/test.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_TEST_BINARY -c $< -o test_main.o

test: test_main.o ${TEST_DEPS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

data/GAME_MASTER.json: FORCE
	wget -O $@ 'https://raw.githubusercontent.com/pokemongo-dev-contrib/pokemongo-game-master/master/versions/latest/V2_GAME_MASTER.json'

gamemaster: data/GAME_MASTER.json


# -------------------------------------------------------------------------- #

clean:
	@echo "Cleaning Up..."
	rm -rvf *.o ${BINS};


FORCE:

# ========================================================================== #
