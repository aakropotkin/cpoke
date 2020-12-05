/* -*- mode: c; -*- */

/* ========================================================================== */

#include "pokedex.h"
#include "defs/cstore_template.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/* -------------------------------------------------------------------------- */

  void
pdex_mon_init( pdex_mon_t      * mon,
               uint16_t          dex_num,
               const char      * name,
               size_t            name_len,
               uint16_t          family,
               uint8_t           form_num,
               ptype_t           type1,
               ptype_t           type2,
               uint16_t          stamina,
               uint16_t          attack,
               uint16_t          defense,
               pdex_tag_mask_t   tags,
               int16_t         * fast_move_ids,
               uint8_t           fast_moves_cnt,
               int16_t         * charged_move_ids,
               uint8_t           charged_moves_cnt
             )
{
  assert( mon != NULL );
  assert( 0 < dex_num );
  assert( dex_num < 1000 );
  assert( family < 1000 );
  assert( form_num < 100 );
  assert( ( fast_moves_cnt == 0 ) || ( fast_move_ids != NULL ) );
  assert( ( charged_moves_cnt == 0 ) || ( charged_move_ids != NULL ) );

  mon->dex_number = dex_num;

  mon->name = strndup( name, name_len );
  assert( mon->name != NULL );

  mon->family   = family;
  mon->form_idx = form_num;
  mon->types    = get_ptype_mask( type1 ) | get_ptype_mask( type2 );

  mon->base_stats.stamina = stamina;
  mon->base_stats.attack  = attack;
  mon->base_stats.defense = defense;

  mon->tags = tags;
  /* Add missing `starter' tag */
  if ( ( !( mon->tags & TAG_STARTER_M ) ) && is_starter( mon->dex_number ) )
    {
      mon->tags |= TAG_STARTER_M;
    } /* Add missing `regional' tag */
  if ( ( !( mon->tags & TAG_REGIONAL_M ) ) && is_regional( mon->dex_number ) )
    {
      mon->tags |= TAG_REGIONAL_M;
    }

  /* Add fast moves */
  if ( 0 < fast_moves_cnt )
    {
      mon->fast_move_ids =
        (int16_t *) malloc( sizeof( int16_t ) * fast_moves_cnt );
      assert( mon->fast_move_ids );
      memcpy( mon->fast_move_ids,
              fast_move_ids,
              sizeof( int16_t ) * fast_moves_cnt
            );
    }

  /*  Add charged moves */
  if ( 0 < charged_moves_cnt )
    {
      mon->charged_move_ids =
        (int16_t *) malloc( sizeof( int16_t ) * charged_moves_cnt );
      assert( mon->charged_move_ids );
      memcpy( mon->charged_move_ids,
              charged_move_ids,
              sizeof( int16_t ) * charged_moves_cnt
            );
    }
}


/* -------------------------------------------------------------------------- */

  void
pdex_mon_free( pdex_mon_t * mon )
{
  if ( mon == NULL ) return;

  free( mon->name );
  mon->name = NULL;

  free( mon->form_name );
  mon->form_name = NULL;

  free( mon->fast_move_ids );
  mon->fast_move_ids = NULL;

  free( mon->charged_move_ids );
  mon->charged_move_ids = NULL;

  mon->dex_number        = 0;
  mon->family            = 0;
  mon->types             = PT_NONE_M;
  mon->base_stats        = (stats_t) { 0, 0, 0 };
  mon->tags              = TAG_NONE_M;
  mon->fast_moves_cnt    = 0;
  mon->charged_moves_cnt = 0;
  mon->form_idx          = 0;

  if ( mon->next_form != NULL ) pdex_mon_free( mon->next_form );
  free( mon );
}


/* -------------------------------------------------------------------------- */

  int
fprint_pdex_tag_mask( FILE * fd, const char * sep, pdex_tag_mask_t tm )
{
  bool fst = true;
  int  pc  = 0;

  /* Masking aginst 0 will always fail, so `PT_NONE' is a special case. */
  if ( tm == TAG_NONE_M )
    {
      return fprintf( fd, "%s", get_pdex_tag_name( TAG_NONE ) );
    }

  for ( int i = 1; i < NUM_PDEX_TAGS; i++ )
    {
      if ( tm & get_pdex_tag_mask( i ) )
        {
          /* Don't print a seperator for the first match. */
          if ( fst ) fst = false;
          else       pc += fprintf( fd, "%s", sep );
          pc += fprintf( fd, "%s", get_pdex_tag_name( i ) );
        }
    }

  return pc;
}


/* -------------------------------------------------------------------------- */

  int
fprint_pdex_mon( FILE * stream, const pdex_mon_t * mon )
{
  int          pc   = 0;
  pdex_mon_t * form = NULL;
  bool         fst  = false;

  pc += fprintf( stream, "(pdex_mon_t) {\n" );
  pc += fprintf( stream, "  dex_number: %d,\n", mon->dex_number );
  pc += fprintf( stream, "  name: \"%s\",\n", mon->name );
  pc += fprintf( stream, "  form_name: \"%s\",\n", mon->form_name );
  pc += fprintf( stream, "  family: %d,\n", mon->family );
  pc += fprintf( stream, "  types: [ " );
  pc += fprint_ptype_mask( stream, ", ", mon->types );
  pc += fprintf( stream, " ],\n" );
  pc += fprintf( stream,
                 "  base_stats: { stamina: %d, attack: %d, defense: %d },\n",
                 mon->base_stats.stamina,
                 mon->base_stats.attack,
                 mon->base_stats.defense
               );

  pc += fprintf( stream, "  tags: [ " );
  if ( mon->tags != TAG_NONE_M )
    {
      pc += fprint_pdex_tag_mask( stream, ", ", mon->tags );
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  fast_move_ids: [ " );
  if ( 0 < mon->fast_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->fast_moves_cnt; i++ )
        {
          if ( 0 < mon->fast_move_ids[i] )
            {
              if ( fst ) pc += fprintf( stream, ", " );
              pc += fprintf( stream, "%d", mon->fast_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  legacy_fast_move_ids: [ " );
  if ( 0 < mon->fast_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->fast_moves_cnt; i++ )
        {
          if ( mon->fast_move_ids[i] < 0 )
            {
              if ( fst ) pc += fprintf( stream, ", " );
              pc += fprintf( stream, "%d", - mon->fast_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  charged_move_ids: [ " );
  if ( 0 < mon->charged_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->charged_moves_cnt; i++ )
        {
          if ( 0 < mon->charged_move_ids[i] )
            {
              if ( fst ) pc += fprintf( stream, ", " );
              pc += fprintf( stream, "%d", mon->charged_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  legacy_charged_move_ids: [ " );
  if ( 0 < mon->charged_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->charged_moves_cnt; i++ )
        {
          if ( mon->charged_move_ids[i] < 0 )
            {
              if ( fst ) pc += fprintf( stream, ", " );
              pc += fprintf( stream, "%d", - mon->charged_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  forms: [ " );
  if ( mon->next_form != NULL )
    {
      pc += fprintf( stream, "\"%s\"", mon->next_form->form_name );
      form = mon->next_form;
      while ( form->next_form != NULL )
        {
          pc += fprintf( stream, ", \"%s\"", form->next_form->form_name );
          form = form->next_form;
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "]\n" );

  pc += fprintf( stream, "}\n" );

  return pc;
}


/* -------------------------------------------------------------------------- */

  int
fprint_pdex_mon_json( FILE * stream, const pdex_mon_t * mon )
{
  int          pc   = 0;
  pdex_mon_t * form = NULL;
  bool         fst  = false;

  pc += fprintf( stream, "{\n" );
  pc += fprintf( stream, "  \"dex_number\": %d,\n", mon->dex_number );
  pc += fprintf( stream, "  \"name\": \"%s\",\n", mon->name );
  pc += fprintf( stream, "  \"form_name\": \"%s\",\n", mon->form_name );
  pc += fprintf( stream, "  \"family\": %d,\n", mon->family );
  pc += fprintf( stream, "  \"types\": [ \"" );
  pc += fprint_ptype_mask( stream, "\", \"", mon->types );
  pc += fprintf( stream, "\" ],\n" );
  pc += fprintf( stream,
                 "  \"base_stats\": { \"stamina\": %d, \"attack\": "
                 "%d, \"defense\": %d },\n",
                 mon->base_stats.stamina,
                 mon->base_stats.attack,
                 mon->base_stats.defense
               );

  pc += fprintf( stream, "  \"tags\": [ " );
  if ( mon->tags != TAG_NONE_M )
    {
      pc += fprintf( stream, "\"" );
      pc += fprint_pdex_tag_mask( stream, "\", \"", mon->tags );
      pc += fprintf( stream, "\" " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  \"fast_move_ids\": [ " );
  if ( 0 < mon->fast_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->fast_moves_cnt; i++ )
        {
          if ( 0 < mon->fast_move_ids[i] )
            {
              if ( fst ) fprintf( stream, ", " );
              pc += fprintf( stream, "%d", mon->fast_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  \"legacy_fast_move_ids\": [ " );
  if ( 0 < mon->fast_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->fast_moves_cnt; i++ )
        {
          if ( mon->fast_move_ids[i] < 0 )
            {
              if ( fst ) fprintf( stream, ", " );
              pc += fprintf( stream, "%d", - mon->fast_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  \"charged_move_ids\": [ " );
  if ( 0 < mon->charged_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->charged_moves_cnt; i++ )
        {
          if ( 0 < mon->charged_move_ids[i] )
            {
              if ( fst ) fprintf( stream, ", " );
              pc += fprintf( stream, "%d", mon->charged_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "],\n" );

  pc += fprintf( stream, "  \"legacy_charged_move_ids\": [ " );
  if ( 0 < mon->charged_moves_cnt )
    {
      fst = false;
      for ( uint16_t i = 0; i < mon->charged_moves_cnt; i++ )
        {
          if ( mon->charged_move_ids[i] < 0 )
            {
              if ( fst ) fprintf( stream, ", " );
              pc += fprintf( stream, "%d", - mon->charged_move_ids[i] );
              fst = true;
            }
        }
      pc += fprintf( stream, " " );
    }
  pc += fprintf( stream, "]\n}" );

  if ( mon->next_form != NULL )
    {
      pc += fprintf( stream, ", " );
      pc += fprint_pdex_mon_json( stream, mon->next_form );
    }

  return pc;
}


/* -------------------------------------------------------------------------- */

  int
fprint_pdex_mon_c( FILE * stream, const pdex_mon_t * mon )
{
  int          pc   = 0;
  pdex_mon_t * form = NULL;

    pc += fprintf( stream,
                    MOVELIST_FMT,
                    "FAST",
                    mon->dex_number,
                    mon->form_idx
                  );
    if ( 0 < mon->fast_moves_cnt )
      {
        pc += fprintf( stream, "{ %d", mon->fast_move_ids[0] );
        for ( uint16_t i = 1; i < mon->fast_moves_cnt; i++ )
          {
            pc += fprintf( stream, ", %d", mon->fast_move_ids[i] );
          }
        pc += fprintf( stream, " " );
      }
    else
      {
        pc += fprintf( stream, "{" );
      }
    pc += fprintf( stream, "};\n" );


    pc += fprintf( stream,
                   MOVELIST_FMT,
                   "CHARGED",
                   mon->dex_number,
                   mon->form_idx
                 );
    if ( 0 < mon->charged_moves_cnt )
      {
        pc += fprintf( stream, "{ %d", mon->charged_move_ids[0] );
        for ( uint16_t i = 1; i < mon->charged_moves_cnt; i++ )
          {
            pc += fprintf( stream, ", %d", mon->charged_move_ids[i] );
          }
        pc += fprintf( stream, " " );
      }
    else
      {
        pc += fprintf( stream, "{" );
      }
    pc += fprintf( stream, "};\n" );


  if ( mon->next_form != NULL )
    {
      pc += fprint_pdex_mon_c( stream, mon->next_form );
      pc += fprintf( stream, ";\n" );
    }

  pc += fprintf( stream, POKEMON_FMT, mon->dex_number, mon->form_idx );
  pc += fprintf( stream, "{\n" );
  pc += fprintf( stream, "  .dex_number = %d,\n", mon->dex_number );
  pc += fprintf( stream, "  .name = \"%s\",\n", mon->name );
  pc += fprintf( stream, "  .form_name = \"%s\",\n", mon->form_name );
  pc += fprintf( stream, "  .family = %d,\n", mon->family );
  pc += fprintf( stream, "  .types = " );
  pc += fprint_ptype_mask( stream, "_M | ", mon->types );
  pc += fprintf( stream, "_M,\n" );
  pc += fprintf( stream,
                 "  .base_stats = { .stamina = %d, .attack = %d, "
                 ".defense = %d },",
                 mon->base_stats.stamina,
                 mon->base_stats.attack,
                 mon->base_stats.defense
               );

  pc += fprintf( stream, "\n  .tags = TAG_" );
  pc += fprint_pdex_tag_mask( stream, "_M | TAG_", mon->tags );
  pc += fprintf( stream, "_M,\n" );

  pc += fprintf( stream,
                 "  .fast_move_ids = FAST_MOVELIST_%u_%u,\n",
                 mon->dex_number,
                 mon->form_idx
               );

  pc += fprintf( stream, "  .fast_moves_cnt = %u,\n", mon->fast_moves_cnt );

  pc += fprintf( stream,
                 "  .charged_move_ids = CHARGED_MOVELIST_%u_%u,\n",
                 mon->dex_number,
                 mon->form_idx
               );
  pc += fprintf( stream,
                 "  .charged_moves_cnt = %u,\n",
                 mon->charged_moves_cnt
               );

  pc += fprintf( stream, " .form_idx = %d,\n", mon->form_idx );

  if ( mon->next_form == NULL )
    {
      pc += fprintf( stream, "  .next_form = NULL" );
    }
  else
    {
      pc += fprintf( stream,
                     "  .next_form = & DEXMON_%u_%u",
                     mon->dex_number,
                     mon->next_form->form_idx
                   );
    }

  pc += fprintf( stream, "\n}" );

  return pc;
}


/* -------------------------------------------------------------------------- */

/**
 * Ignore names, tags, and family.
 * This implementation isn't trying to sort. Feel free to change it.
 */
  int
cmp_pdex_mon_practical( pdex_mon_t * a, pdex_mon_t * b )
{
  int cmp = 0;
  if ( a == b )                         return 0;  /* Equal */
  if ( ( a == NULL ) || ( b == NULL ) ) return 1;  /* Not Equal */

  /* Compare strings last */
  cmp = a->dex_number - b->dex_number;
  if ( cmp != 0 ) return cmp;
  cmp = a->types - b->types;
  if ( cmp != 0 ) return cmp;
  cmp = a->fast_moves_cnt - b->fast_moves_cnt;
  if ( cmp != 0 ) return cmp;
  cmp = a->charged_moves_cnt - b->charged_moves_cnt;
  if ( cmp != 0 ) return cmp;
  cmp = a->base_stats.attack - b->base_stats.attack;
  if ( cmp != 0 ) return cmp;
  cmp = a->base_stats.defense - b->base_stats.defense;
  if ( cmp != 0 ) return cmp;
  cmp = a->base_stats.stamina - b->base_stats.stamina;
  if ( cmp != 0 ) return cmp;
  /* Match fast moves, ignoring order */
  for ( uint8_t ma = 0; ma < a->fast_moves_cnt; ma++ )
    {
      cmp = 1;
      for ( uint8_t mb = 0; mb < b->fast_moves_cnt; mb++ )
        {
          if ( a->fast_move_ids[ma] == b->fast_move_ids[mb] )
            {
              cmp = 0;
              break;
            }
        }
      if ( cmp != 0 ) return cmp;
    }
  /* Match charged moves, ignoring order */
  for ( uint8_t ma = 0; ma < a->charged_moves_cnt; ma++ )
    {
      cmp = 1;
      for ( uint8_t mb = 0; mb < b->charged_moves_cnt; mb++ )
        {
          if ( a->charged_move_ids[ma] == b->charged_move_ids[mb] )
            {
              cmp = 0;
              break;
            }
        }
      if ( cmp != 0 ) return cmp;
    }

  return 0;  /* Equal */
}


/**
 * Does not compare `form_idx' because different data sources might lead to
 * different orderings.
 * This implementation isn't trying to sort. Feel free to change it.
 */
  int
cmp_pdex_mon( pdex_mon_t * a, pdex_mon_t * b )
{
  int cmp = cmp_pdex_mon_practical( a, b );
  if ( cmp != 0 ) return cmp;

  cmp = a->family - b->family;
  if ( cmp != 0 ) return cmp;
  cmp = a->tags - b->tags;
  if ( cmp != 0 ) return cmp;
  /* Okay, finally do the strings */
  cmp = strcmp( a->name, b->name );
  if ( cmp != 0 ) return cmp;
  cmp = strcmp( a->form_name, b->form_name );
  if ( cmp != 0 ) return cmp;

  return 0;  /* Equal */
}


/* -------------------------------------------------------------------------- */


/* ========================================================================== */

/* vim: set filetype=c : */
