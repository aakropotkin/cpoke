AM_CPPFLAGS = -I$(top_builddir)/include
AM_CFLAGS = -fms-extensions -DJSMN_STATIC -std=gnu11
AM_LDFLAGS = -lm -ldl

test_names = json pokemon ptypes parse_gm cstore battle player naive_ai filter
test_names += fuzzy

bin_PROGRAMS = test parse_gm fetch_gm iv_store_build cpoke

ext_sources = ext/jsmn_iterator.c
util_sources = util/files.c util/json_util.c
core_sources = pokemon.c ptypes.c pokedex.c moves.c
sim_sources = naive_ai.c
gm_sources = parse_gm.c gm_store.c fetch_gm.c
cstore_sources = cstore.c cstore_data.c
test_sources = ${test_names:%=test/test_%.c}

#fetch_gm_HEADERS = $(top_builddir)/include/util/curl_util.h
fetch_gm_SOURCES = fetch_gm.c
