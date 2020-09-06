# ========================================================================== #


.DEFAULT_GOAL := cpoke
.PHONY = all clean gamemaster

CC = gcc

SRCPATH     = src
INCLUDEPATH = include
DEFSPATH    = data/defs

# `-fms-extensions' enables struct inheritence
CFLAGS      += -I${INCLUDEPATH} -I${DEFSPATH} -fms-extensions -DJSMN_STATIC
LINKERFLAGS = -lm $(shell curl-config --libs)

HEADERS := $(wildcard ${INCLUDEPATH}/*.h) $(wildcard ${INCLUDEPATH}/*/*.h)
DEFS    := $(wildcard ${DEFSPATH}/*.def)
SRCS    := $(wildcard ${SRCPATH}/*.c) $(wildcard ${SRCPATH}/*/*.c)
BINS    := cpoke parse_gm fetch_gm test

CORE_OBJECTS := pokemon.o player.o ptypes.o battle.o files.o json_util.o
CORE_OBJECTS += ptype_traits.o moves.o cpms.o damage_modifiers.o

TEST_SRCS    := test_json.c test_pokemon.c test_ptypes.c
TEST_OBJECTS := test_json.o test_pokemon.o test_ptypes.o


# -------------------------------------------------------------------------- #

main.o: ${SRCPATH}/main.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

cpoke: main.o ${CORE_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

parse_gm.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

parse_gm: parse_gm.o files.o
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

fetch_gm.o: ${SRCPATH}/fetch_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

fetch_gm: fetch_gm.o
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

pokemon.o: ${SRCPATH}/pokemon.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

cpms.o: ${SRCPATH}/cpms.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

player.o: ${SRCPATH}/player.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

ptypes.o: ${SRCPATH}/ptypes.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

ptype_traits.o: ${SRCPATH}/ptype_traits.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

damage_modifiers.o: ${SRCPATH}/damage_modifiers.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

battle.o: ${SRCPATH}/battle.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

moves.o: ${SRCPATH}/moves.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

files.o: ${SRCPATH}/util/files.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

json_util.o: ${SRCPATH}/util/json_util.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

test_json.o: ${SRCPATH}/test/test_json.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_pokemon.o: ${SRCPATH}/test/test_pokemon.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_ptypes.o: ${SRCPATH}/test/test_ptypes.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test.o: ${SRCPATH}/test/test.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_main.o: ${SRCPATH}/test/test.c ${HEADERS}
	${CC} ${CFLAGS} -DMK_TEST_BINARY -c $< -o test_main.o

test: test_main.o ${CORE_OBJECTS} ${TEST_OBJECTS}
	${CC} ${LINKERFLAGS} $^ -o $@


# -------------------------------------------------------------------------- #

data/GAME_MASTER.json: FORCE
	wget -O $@ 'https://github.com/pokemongo-dev-contrib/pokemongo-game-master/raw/master/versions/latest/GAME_MASTER.json'

gamemaster: data/GAME_MASTER.json


# -------------------------------------------------------------------------- #

clean:
	@echo "Cleaning Up..."
	rm -rvf *.o ${BINS};


FORCE:

# ========================================================================== #
