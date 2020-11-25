
CC := gcc
RM := rm

NIX_PROFILE_PATH := ${HOME}/.nix-profile
NIX_LIBS := ${NIX_PROFILE_PATH}/lib
NIX_INCS := ${NIX_PROFILE_PATH}/include

OCL_FLAGS := -I${NIX_INCS} -L${NIX_LIBS} -lOpenCL
DBG_FLAGS := -ggdb

BINS := main


main: main.c cp_from_stats.cl
	${CC} ${OCL_FLAGS} main.c -o main

main-g: main.c cp_from_stats.cl
	${CC} ${OCL_FLAGS} ${DBG_FLAGS} main.c -o main-g

clean:
	${RM} -rf ${BINS}
