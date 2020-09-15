/* -*- mode: c; -*- */

/* ========================================================================= */

#include <stdio.h>
#include "pokedex.h"

/* ------------------------------------------------------------------------- */

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
               uint16_t        * fast_move_ids,
               uint8_t           fast_moves_cnt,
               uint16_t        * charged_move_ids,
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

  mon->family = family;
  mon->form   = form_num;
  mon->type   = get_ptype_mask( type1 ) | get_ptype_mask( type2 );

  mon->base_stats.stamina = stamina;
  mon->base_stats.attack  = attack;
  mon->base_stats.defense = defense;

  mon->tags = tags;
  /* Add missing `starter' tag */
  if ( ( !( mon->tags & TAG_STARTER_M ) ) && is_starter( mon->dex_number ) )
    {
      mon->tags |= TAG_STARTER_M;
    }
  /* Add missing `regional' tag */
  if ( ( !( mon->tags & TAG_REGIONAL_M ) ) && is_regional( mon->dex_number ) )
    {
      mon->tags |= TAG_REGIONAL_M;
    }

  /* Add fast moves */
  if ( 0 < fast_moves_cnt )
    {
      mon->fast_move_ids =
        (uint16_t *) malloc( sizeof( uint16_t ) * fast_moves_cnt );
      assert( mon->fast_move_ids );
      memcpy( mon->fast_move_ids,
              fast_move_ids,
              sizeof( uint16_t ) * fast_moves_cnt
            );
    }

  /*  Add charged moves */
  if ( 0 < charged_moves_cnt )
    {
      mon->charged_move_ids =
        (uint16_t *) malloc( sizeof( uint16_t ) * charged_moves_cnt );
      assert( mon->charged_move_ids );
      memcpy( mon->charged_move_ids,
              charged_move_ids,
              sizeof( uint16_t ) * charged_moves_cnt
            );
    }

  mon->hkey = pdex_mon_hkey( mon );
}


  void
pdex_mon_free( pdex_mon_t * mon )
{
  if ( mon == NULL ) return;
  free( mon->name );
  mon->name = NULL;
  free( mon->fast_move_ids );
  mon->fast_move_ids = NULL;
  free( mon->charged_move_ids );
  mon->charged_move_ids = NULL;

  mon->dex_number        = 0;
  mon->family            = 0;
  mon->form              = 0;
  mon->types             = PT_NONE_M;
  mon->base_stats        = { 0, 0, 0 };
  mon->tags              = TAG_NONE_M;
  mon->fast_moves_cnt    = 0;
  mon->charged_moves_cnt = 0;
  /* FIXME handle hkey */
}


/* ------------------------------------------------------------------------- */

  int
fprint_pdex_mon( FILE * stream, const pdex_mon_t * mon )
{
  fprintf( stream, "(pdex_mon_t) {\n" );
  fprintf( stream, "  dex_number: %d,\n", mon->dex_number );
  fprintf( stream, "  name: \"%s\",\n", mon->name );
  fprintf( stream, "  types: " );
  fprint_ptype_mask( stream, " & ", mon->types );
  fprintf( stream, ",\n" );
  fprintf( stream,
           "  stats: { stamina: %d, attack: %d, defense: %d },\n",
           mon->base_stats.stamina,
           mon->base_stats.attack,
           mon->base_stats.defense
         );
  fprintf( stream, "}\n" );
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
