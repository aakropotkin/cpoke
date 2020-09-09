/* -*- mode: c; -*- */

/* ========================================================================= */

#include "parse_gm.h"
#include "ext/jsmn.h"
#include "ext/jsmn_iterator.h"
#include "util/json_util.h"
#include "util/jsmn_iterator_stack.h"
#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */

  int
main( int argc, char * argv[], char ** envp )
{

  /* Parse file */
  gm_parser_t gparser;
  size_t rsl = init_gm_parser( "./data/GAME_MASTER.json", &gparser );
  assert( rsl != 0 );

  /* Compile Regex patterns for templateIds */
  regex_t pkmn_tmp_regex, pvp_move_tmp_regex, pvp_fast_move_tmp_regex;
  int     rc_rsl = regcomp( &pkmn_tmp_regex, pokemon_template_pat, REG_NOSUB );
  assert( rc_rsl == 0 );
  rc_rsl = regcomp( &pvp_move_tmp_regex, pvp_move_template_pat, REG_NOSUB );
  assert( rc_rsl == 0 );
  rc_rsl = regcomp( &pvp_fast_move_tmp_regex,
                    pvp_fast_move_template_pat,
                    REG_NOSUB
                  );
  assert( rc_rsl == 0 );


  jsmn_iterator_stack_t iter_stack;
  int jsmn_rsl = jsmnis_init( &iter_stack,
                              gparser.tokens,
                              gparser.tokens_cnt,
                              8
                            );
  assert( jsmn_rsl == 0 );

  jsmn_rsl = jsmnis_push( &iter_stack, 0 ); /* Open the top level object */
  assert( jsmn_rsl == 0 );

  /* Open the item template list */
  jsmn_rsl =
    jsmnis_open_key_seq( gparser.buffer, &iter_stack, "itemTemplate", 0 );
  assert( jsmn_rsl == 0 );


  /* Iterate over items */
  jsmntok_t * key  = NULL;
  jsmntok_t * val  = NULL;
  int         idx  = 0;
  jsmntok_t * item = NULL;

  jsmnis_a_while( &iter_stack, &item )
    {
      /* Open the current item */
      jsmnis_push_curr( &iter_stack );

      /* See if this item's templateId matches that of a Pokemon */
      key = NULL;
      val = NULL;
      idx = jsmni_find_next( gparser.buffer,
                            jsmnis_curr( &iter_stack ),
                            &key,
                            jsoneq_str_p,
                            (void *) "templateId",
                            &val,
                             //jsonmatch_str_p,
                             //(void *) &pkmn_tmp_regex,
                            jsoneq_str_p,
                            (void *) "FORMS_V0002_POKEMON_IVYSAUR",
                            0
                          );
      if ( idx <= 0 )
        {
          jsmnis_pop( &iter_stack ); /* Close the item */
          continue;
        }

      /* Find number of forms for Ivysaur */
      jsmni_next( jsmnis_curr( &iter_stack ), &key, &val, 0 );
      jsmnis_push_curr( &iter_stack );
      jsmni_next( jsmnis_curr( &iter_stack ), &key, &val, 0 );
      jsmni_next( jsmnis_curr( &iter_stack ), &key, &val, 0 );
      printf( "SIZE: %d\n", val->size );
      return 0;

      /* You have to pop/close before parsing because `iter_stack' is currently
      * pointed inside the item template, not pointing at it's root. */
      pdex_mon_t mon;
      parse_pdex_mon( gparser.buffer,
                      &iter_stack,
                      &mon
                    );
      print_pdex_mon( &mon );

      jsmnis_pop( &iter_stack );
    }


  /* Cleanup */
  jsmnis_free( &iter_stack );
  regfree( &pkmn_tmp_regex );
  free_gm_parser( &gparser );

  return EXIT_SUCCESS;
}



/* ========================================================================= */

/* vim: set filetype=c : */
