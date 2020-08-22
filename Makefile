# ========================================================================== #


.DEFAULT_GOAL := cpoke
.PHONY = all clean

CC = gcc

SRCPATH     = src
INCLUDEPATH = include
DEFSPATH    = data/defs

# `-fms-extensions' enables struct inheritence
CFLAGS      = -I${INCLUDEPATH} -I${DEFSPATH} -fms-extensions
LINKERFLAGS = -lm

HEADERS := $(wildcard ${INCLUDEPATH}/*.h) $(wildcard ${INCLUDEPATH}/*/*.h)
DEFS    := $(wildcard ${DEFSPATH}/*.def)
SRCS    := $(wildcard ${SRCPATH}/*.c) $(wildcard ${SRCPATH}/*/*.c)
BINS    := cpoke parse_gm test_utils test_ptypes test_pokemon


# -------------------------------------------------------------------------- #

main.o: ${SRCPATH}/main.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

cpoke: main.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


# -------------------------------------------------------------------------- #

parse_gm.o: ${SRCPATH}/parse_gm.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

parse_gm: parse_gm.o ${HEADERS}
	${CC} ${LINKERFLAGS} $< -o $@


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

clean:
	@echo "Cleaning Up..."
	rm -rvf *.o ${BINS};


# ========================================================================== #
