# ========================================================================== #


.DEFAULT_GOAL := cpoke
.PHONY = all clean gamemaster

CC = gcc

SRCPATH     = src
INCLUDEPATH = include
DEFSPATH    = data/defs

# `-fms-extensions' enables struct inheritence
CFLAGS      += -I${INCLUDEPATH} -I${DEFSPATH} -fms-extensions
LINKERFLAGS = -lm $(shell curl-config --libs)

HEADERS := $(wildcard ${INCLUDEPATH}/*.h) $(wildcard ${INCLUDEPATH}/*/*.h)
DEFS    := $(wildcard ${DEFSPATH}/*.def)
SRCS    := $(wildcard ${SRCPATH}/*.c) $(wildcard ${SRCPATH}/*/*.c)
BINS    := cpoke parse_gm test_utils test_ptypes test_pokemon fetch_gm

CORE_OBJECTS := pokemon.o player.o ptypes.o battle.o files.o


# -------------------------------------------------------------------------- #

main.o: ${SRCPATH}/main.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

cpoke: main.o ${CORE_OBJECTS} ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


# -------------------------------------------------------------------------- #

parse_gm.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

parse_gm: parse_gm.o files.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


# -------------------------------------------------------------------------- #

fetch_gm.o: ${SRCPATH}/fetch_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

fetch_gm: fetch_gm.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


# -------------------------------------------------------------------------- #

pokemon.o: ${SRCPATH}/pokemon.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

player.o: ${SRCPATH}/player.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

ptypes.o: ${SRCPATH}/ptypes.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

battle.o: ${SRCPATH}/battle.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

files.o: ${SRCPATH}/util/files.c ${HEADERS}
	${CC} ${CFLAGS} -c $<


# -------------------------------------------------------------------------- #

test_utils.o: ${SRCPATH}/test/test_utils.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_utils: test_utils.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


test_ptypes.o: ${SRCPATH}/test/test_ptypes.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_ptypes: test_ptypes.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


test_pokemon.o: ${SRCPATH}/test/test_pokemon.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

test_pokemon: test_pokemon.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


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
