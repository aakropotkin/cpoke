/* -*- mode: c; -*- */

#ifndef _PARSE_CSV_H
#define _PARSE_CSV_H

/* ========================================================================= */

#include <assert.h>
#include "moves.h"
#include "pokedex.h"
#include "ptypes.h"
#include "util/macros.h"
#include "pokemon.h"
#include "gm_store.h"
#include <stdint.h>
#include <string.h>


/* ------------------------------------------------------------------------- */

/**
 * The purpose of this file is to parse a user's Pokemon collection from a
 * CSV file, creating a `roster_t'.
 * <p>
 * The parser is meant to read the format exported by Pokebattler.
 * It DOES NOT, read the same "flexible" format used to "import to Pokebattler".
 * Ultimately we should aim to accept the same flexible imports, but for now
 * we're going to keep things simple.
 * <p>
 * The only real hiccup is that Pokebattler writes a pokemon's form with it's
 * name, so "Galarian Stunfisk" has the field `pokemon = STUNFISK_GALARIAN_FORM'
 */

enum pokebattler_field_e {
  PBF_ID = 0,
  PBF_IMPORTED_ID,
  PBF_POKEMON,
  PBF_NAME,
  PBF_CP,
  PBF_LEVEL,
  PBF_IV_ATK,
  PBF_IV_DEF,
  PBF_IV_STA,
  PBF_FAST_MOVE,
  PBF_CHARGED1,
  PBF_SHINY,
  PBF_LUCKY,
  PBF_CHARGED2
};

/**
 * Okay this is the annoying part.
 * We have to split the form name out of this field.
 * The easiest way to do this is to pull the name until the first '_'
 * character, treating a handful of Pokemon as edge cases explicitly.
 * This definitely isn't ideal, but the alternative would be an incredibly
 * costly regex search of the entire store for a lot of pokemon.
 *
 * The edge cases are:
 *   - NIDORAN_FEMALE
 *   - NIDORAN_MALE
 *   - MR_MIME
 *   - HO_OH
 *   - MIME_JR
 *   - PORYGON_Z
 *
 * The trickier of these are those with Shadow forms.
 * Be cautious because if Shadow Ho-Oh is ever released, you're going to need
 * to update this.
 */
static const char * PBF_SPACED_NAMES = {
  "NIDORAN_FEMALE", "NIDORAN_MALE", "MR_MIME", "HO_OH", "MIME_JR", "PORYGON_Z"
};

  int
parse_pokebattler_name( const char     * str,
                              uint16_t * dex_number,
                              uint8_t  * form_idx,
                              store_t  * gm_store
                      )
{

}

/**
 * Example data:
 *
 * id,importedId,pokemon,name,cp,level,individualAttack,individualDefense,individualStamina,quickMove,cinematicMove,shiny,lucky,cinematicMove2
 * 5616504,,STUNFISK_GALARIAN_FORM,,1235,20,15,15,15,MUD_SHOT_FAST,EARTHQUAKE,false,false,ROCK_SLIDE
 */
  int
parse_csv_pokemon( char             * line,
                   roster_pokemon_t * mon,
                   store_t          * gm_store
                 )
{
  assert( line != NULL );
  assert( mon != NULL );
  assert( mon->base != NULL );
  assert( gm_store != NULL );

  const char         * fields[PBF_CHARGED2 + 1];
        uint8_t        i                        = 0;
        int            rsl                      = STORE_FAILURE;
        pdex_mon_t   * pdex_mon                 = NULL;
        store_move_t * move                     = NULL;

  /* Initialize existing data */
  mon->base->pdex_mon      = NULL;

  /* Slice fields on commas */
  for ( const char * tok = strtok( line, "," );
        ( tok != NULL ) && ( *tok != NULL );
        tok = strtok( NULL, ",\n" )
      ) fields[i++] = tok;
  assert( i == ( PBF_CHARGED2 + 1 ) );

  /* The easy stuff */
  mon->base->level       = atof( fields[PBF_LEVEL] );
  mon->base->ivs.attack  = atoi( fields[PBF_IV_ATK] );
  mon->base->ivs.defense = atoi( fields[PBF_IV_DEF] );
  mon->base->ivs.stamina = atoi( fields[PBF_IV_STA] );

  /* Strip `_FAST' suffix from fast move names */
  fields[PBF_FAST_MOVE][strlen( fields[PBF_FAST_MOVE] ) - 6] = '\0';
  rsl = gm_store_get_move_by_name( gm_store, fields[PBF_FAST_MOVE], & move );
  assert( rsl == STORE_SUCCESS );
  mon->fast_move_id = move->move_id;
  move = NULL;

  rsl = gm_store_get_move_by_name( gm_store, fields[PBF_CHARGED1], & move );
  assert( rsl == STORE_SUCCESS );
  mon->charged_move_ids[0] = move->move_id;
  move = NULL;

  /* Tokenizer should put an empty string for missing fields */
  if ( fields[PBF_CHARGED2][0] != '\0' )
    {
      rsl = gm_store_get_move_by_name( gm_store, fields[PBF_CHARGED2], & move );
      assert( rsl == STORE_SUCCESS );
      mon->charged_move_ids[1] = move->move_id;
      move = NULL;
    }
  else
    {
      mon->charged_move_ids[1] = 0;
    }

}





/* ========================================================================= */



#endif /* parse_csv.h */

/* vim: set filetype=c : */
