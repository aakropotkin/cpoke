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

  /* Find first pokemon in GM */
  int first_pokemon_tok_idx = 0;
  for ( int i = 1; i < (int) rsl; i++ ) {
    if ( jsonmatch_str( gparser.buffer,
                        &( gparser.tokens[i] ),
                        &pkmn_tmp_regex )
       ) {
      printf( "First Pokemon templateId at token # %d\n", i );
      printf( "templateId = \"" );
      print_tok( gparser.buffer, &( gparser.tokens[i] ) );
      printf( "\"\n" );
      first_pokemon_tok_idx = i - 2; /* The "Parent" token is a list member */
      printf( "Full Token: \n" );
      print_tok( gparser.buffer, &( gparser.tokens[first_pokemon_tok_idx] ) );
      putchar( '\n' );
      break;
    }
  }

  /* Cleanup */
  regfree( &pkmn_tmp_regex );
  free_gm_parser( &gparser );

  return EXIT_SUCCESS;
}

/* ========================================================================= */
