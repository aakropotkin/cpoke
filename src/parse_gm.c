/* -*- mode: c; -*- */

/* ========================================================================= */

#include <parse_gm.h>
#include <stdio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */

int
main( int argc, char * argv[], char ** envp ) {

  /* Parse file */
  gm_parser_t gparser;
  size_t rsl = init_gm_parser( "./data/GAME_MASTER.json", &gparser );
  assert( rsl != 0 );

  /* Compile Regex */
  regex_t pkmn_tmp_regex;
  int     rc_rsl = regcomp( &pkmn_tmp_regex, pokemon_template_pat, REG_NOSUB );
  assert( rc_rsl == 0 );

  int i = json_find( gparser.buffer,
                     gparser.tokens,
                     jsonmatch_str_p,
                     (void *) &pkmn_tmp_regex,
                     rsl,
                     0
                   );
  int first_pokemon_tok_idx = i - 2;

  printf( "First Pokemon templateId at token # %d\n", i );
  printf( "templateId = \"" );
  print_tok( gparser.buffer, &( gparser.tokens[i] ) );
  printf( "\"\n" );
  printf( "Full Token: \n" );
  print_tok( gparser.buffer, &( gparser.tokens[first_pokemon_tok_idx] ) );
  putchar( '\n' );

  for ( size_t j = i; gparser.tokens[j].end < gparser.tokens[i - 2].end; j++ )
    {
      printf( "token %d: ", j - i );
      print_tok( gparser.buffer, &( gparser.tokens[j] ) );
      printf( "\n" );
    }

  /* Cleanup */
  regfree( &pkmn_tmp_regex );
  free_gm_parser( &gparser );

  return EXIT_SUCCESS;
}



/* ========================================================================= */

/* vim: set filetype=c : */
