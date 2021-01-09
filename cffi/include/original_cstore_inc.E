













struct store_s;




typedef enum {
  STORE_NULL_STATUS,
  STORE_SUCCESS,
  STORE_ERROR_FAIL,
  STORE_ERROR_BAD_VALUE,
  STORE_ERROR_NOMEM,
  STORE_ERROR_NOT_FOUND,
  STORE_ERROR_NOT_WRITABLE,
  STORE_ERROR_NOT_DEFINED
} store_status_t;




typedef enum { SF_NONE , SF_WRITABLE , SF_THREAD_SAFE , SF_OFFICIAL_DATA , SF_CUSTOM_DATA , SF_EXPORTABLE , SF_STANDARD_KEY , SF_TYPED , SF_GET_STRING , SF_GET_TYPED_STRING } store_flag_t;

/*typedef enum { SF_NONE_M = ( ( ( !! ( SF_NONE ) ) << ( SF_NONE ) ) >> 1 ) , SF_WRITABLE_M = ( ( ( !! ( SF_WRITABLE ) ) << ( SF_WRITABLE ) ) >> 1 ) , SF_THREAD_SAFE_M = ( ( ( !! ( SF_THREAD_SAFE ) ) << ( SF_THREAD_SAFE ) ) >> 1 ) , SF_OFFICIAL_DATA_M = ( ( ( !! ( SF_OFFICIAL_DATA ) ) << ( SF_OFFICIAL_DATA ) ) >> 1 ) , SF_CUSTOM_DATA_M = ( ( ( !! ( SF_CUSTOM_DATA ) ) << ( SF_CUSTOM_DATA ) ) >> 1 ) , SF_EXPORTABLE_M = ( ( ( !! ( SF_EXPORTABLE ) ) << ( SF_EXPORTABLE ) ) >> 1 ) , SF_STANDARD_KEY_M = ( ( ( !! ( SF_STANDARD_KEY ) ) << ( SF_STANDARD_KEY ) ) >> 1 ) , SF_TYPED_M = ( ( ( !! ( SF_TYPED ) ) << ( SF_TYPED ) ) >> 1 ) , SF_GET_STRING_M = ( ( ( !! ( SF_GET_STRING ) ) << ( SF_GET_STRING ) ) >> 1 ) , SF_GET_TYPED_STRING_M = ( ( ( !! ( SF_GET_TYPED_STRING ) ) << ( SF_GET_TYPED_STRING ) ) >> 1 ) } store_flag_mask_t; 
 */
// @@hack
typedef unsigned int store_flag_mask_t;


typedef union { store_flag_mask_t mask; struct { unsigned int SF_WRITABLE : 1 ; unsigned int SF_THREAD_SAFE : 1 ; unsigned int SF_OFFICIAL_DATA : 1 ; unsigned int SF_CUSTOM_DATA : 1 ; unsigned int SF_EXPORTABLE : 1 ; unsigned int SF_STANDARD_KEY : 1 ; unsigned int SF_TYPED : 1 ; unsigned int SF_GET_STRING : 1 ; unsigned int SF_GET_TYPED_STRING : 1; }; } store_flag_flags_t;

typedef enum {
  STORE_UNKNOWN,
  STORE_STRING,
  STORE_NUM,
  STORE_FUNCTION,
  STORE_POKEDEX,
  STORE_MOVE,
  STORE_ROSTER,
  STORE_CUP,
  STORE_PVP_POKEMON,
  STORE_PVP_TEAM,
  STORE_PVP_BATTLE,
  STORE_PVP_BATTLE_LOG,
  STORE_PVP_POKEMON_RANKING,
  STORE_PVP_MOVE_RANKING,
  STORE_ANALYTICS,
  STORE_CUSTOM
} store_type_t;





typedef enum {
  SS_UNKNOWN, SS_C, SS_JSON, SS_SQL
} store_sink_t;




struct store_key_s {
  store_type_t key_type;
  store_type_t val_type;
  union {
    uint32_t data_f;
    struct {
      union { uint16_t data_h0; struct { uint8_t data_q0, data_q1; }; };
      union { uint16_t data_h1; struct { uint8_t data_q2, data_q3; }; };
    };
  } ;
};
typedef struct store_key_s store_key_t;
typedef bool ( * store_has_fn )( struct store_s *, store_key_t );
typedef int ( * store_get_fn )( struct store_s *, store_key_t, void ** );
typedef int ( * store_init_fn )( struct store_s *, void * );
typedef void ( * store_free_fn )( struct store_s * );


typedef int ( * store_get_str_fn )( struct store_s *, const char *, void ** );

typedef int ( * store_get_str_t_fn )( struct store_s *,
                                       store_type_t,
                                       const char *,
                                       void **
                                     );

typedef int ( * store_add_fn )( struct store_s *, store_key_t, void * );
typedef int ( * store_set_fn )( struct store_s *, store_key_t, void * );

typedef int ( * store_export_fn )( struct store_s *, store_sink_t, void * );




struct store_s {
  char * name;
  store_flag_mask_t flags;
  store_has_fn has;
  store_get_fn get;
  store_get_str_fn get_str;
  store_get_str_t_fn get_str_t;
  store_add_fn add;
  store_set_fn set;
  store_export_fn export;
  store_init_fn init;
  store_free_fn free;
  void * aux;
};

typedef struct store_s store_t;







typedef struct UT_hash_bucket {
   struct UT_hash_handle *hh_head;
   unsigned count;
   unsigned expand_mult;

} UT_hash_bucket;





typedef struct UT_hash_table {
   UT_hash_bucket *buckets;
   unsigned num_buckets, log2_num_buckets;
   unsigned num_items;
   struct UT_hash_handle *tail;
   ptrdiff_t hho;



   unsigned ideal_chain_maxlen;




   unsigned nonideal_items;







   unsigned ineff_expands, noexpand;

   uint32_t signature;






} UT_hash_table;

typedef struct UT_hash_handle {
   struct UT_hash_table *tbl;
   void *prev;
   void *next;
   struct UT_hash_handle *hh_prev;
   struct UT_hash_handle *hh_next;
   void *key;
   unsigned keylen;
   unsigned hashv;
} UT_hash_handle;



typedef enum { PT_NONE , BUG , DARK , DRAGON , ELECTRIC , FAIRY , FIGHTING , FIRE , FLYING , GHOST , GRASS , GROUND , ICE , NORMAL , POISON , PSYCHIC , ROCK , STEEL , WATER } ptype_t;

/*
  typedef enum { PT_NONE_M = ( ( ( !! ( PT_NONE ) ) << ( PT_NONE ) ) >> 1 ) , BUG_M = ( ( ( !! ( BUG ) ) << ( BUG ) ) >> 1 ) , DARK_M = ( ( ( !! ( DARK ) ) << ( DARK ) ) >> 1 ) , DRAGON_M = ( ( ( !! ( DRAGON ) ) << ( DRAGON ) ) >> 1 ) , ELECTRIC_M = ( ( ( !! ( ELECTRIC ) ) << ( ELECTRIC ) ) >> 1 ) , FAIRY_M = ( ( ( !! ( FAIRY ) ) << ( FAIRY ) ) >> 1 ) , FIGHTING_M = ( ( ( !! ( FIGHTING ) ) << ( FIGHTING ) ) >> 1 ) , FIRE_M = ( ( ( !! ( FIRE ) ) << ( FIRE ) ) >> 1 ) , FLYING_M = ( ( ( !! ( FLYING ) ) << ( FLYING ) ) >> 1 ) , GHOST_M = ( ( ( !! ( GHOST ) ) << ( GHOST ) ) >> 1 ) , GRASS_M = ( ( ( !! ( GRASS ) ) << ( GRASS ) ) >> 1 ) , GROUND_M = ( ( ( !! ( GROUND ) ) << ( GROUND ) ) >> 1 ) , ICE_M = ( ( ( !! ( ICE ) ) << ( ICE ) ) >> 1 ) , NORMAL_M = ( ( ( !! ( NORMAL ) ) << ( NORMAL ) ) >> 1 ) , POISON_M = ( ( ( !! ( POISON ) ) << ( POISON ) ) >> 1 ) , PSYCHIC_M = ( ( ( !! ( PSYCHIC ) ) << ( PSYCHIC ) ) >> 1 ) , ROCK_M = ( ( ( !! ( ROCK ) ) << ( ROCK ) ) >> 1 ) , STEEL_M = ( ( ( !! ( STEEL ) ) << ( STEEL ) ) >> 1 ) , WATER_M = ( ( ( !! ( WATER ) ) << ( WATER ) ) >> 1 ) } ptype_mask_t;*/
//@@hack
typedef unsigned int ptype_mask_t;

typedef union { ptype_mask_t mask; struct { unsigned int BUG : 1 ; unsigned int DARK : 1 ; unsigned int DRAGON : 1 ; unsigned int ELECTRIC : 1 ; unsigned int FAIRY : 1 ; unsigned int FIGHTING : 1 ; unsigned int FIRE : 1 ; unsigned int FLYING : 1 ; unsigned int GHOST : 1 ; unsigned int GRASS : 1 ; unsigned int GROUND : 1 ; unsigned int ICE : 1 ; unsigned int NORMAL : 1 ; unsigned int POISON : 1 ; unsigned int PSYCHIC : 1 ; unsigned int ROCK : 1 ; unsigned int STEEL : 1 ; unsigned int WATER : 1; }; } ptype_flags_t;



int fprint_ptype_mask( FILE * fd, const char * sep, ptype_mask_t pm );
struct ptype_traits_s {
  ptype_mask_t resistances : 18;
  ptype_mask_t weaknesses : 18;
  ptype_mask_t immunities : 18;
} ;

typedef struct ptype_traits_s ptype_traits_t;



         float get_damage_modifier_mono( ptype_t def_type, ptype_t atk_type );
         float get_damage_modifier_duo( ptype_t def_type1,
                                        ptype_t def_type2,
                                        ptype_t atk_type
                                      );

         float get_damage_modifier( ptype_mask_t def_types, ptype_t atk_type );

         float
get_damage_modifier_flags( ptype_flags_t def_types, ptype_t atk_type );




typedef enum {
  bc_1000, bc_0500, bc_0300, bc_0125, bc_0100, bc_0000
} buff_chance_t;




struct stat_buff_s {
  uint8_t target : 1;
  uint8_t debuffp : 1;
  uint8_t amount : 2;
} ;
typedef struct stat_buff_s stat_buff_t;


struct buff_s {
  buff_chance_t chance;
  stat_buff_t atk_buff;
  stat_buff_t def_buff;
} ;
typedef struct buff_s buff_t;


typedef enum {
  B_4_8, B_4_7, B_4_6, B_4_5,
  B_4_4,
  B_5_4, B_6_4, B_7_4, B_8_4
} buff_level_t;




struct buff_state_s {
  buff_level_t atk_buff_lv;
  buff_level_t def_buff_lv;
} ;
typedef struct buff_state_s buff_state_t;

void apply_buff( buff_state_t * buff_state, buff_t buff );







struct base_move_s {
  uint16_t move_id;
  ptype_t type;
  bool is_fast : 1;
  uint8_t power;
  uint8_t energy;
} ;
typedef struct base_move_s base_move_t;

static const base_move_t NO_MOVE = {
  .move_id = 0,
  .type = PT_NONE,
  .is_fast = false,
  .power = 0,
  .energy = 0
};
struct pve_move_s {
  base_move_t /*@@*/ base_move;
  uint16_t cooldown;
} ;
typedef struct pve_move_s pve_move_t;

int pve_move_from_store( store_t * store,
                         uint16_t move_id,
                         pve_move_t * move
                       );




struct pvp_charged_move_s {
  base_move_t /*@@*/ base_move;
  buff_t buff;
} ;
typedef struct pvp_charged_move_s pvp_charged_move_t;

int pvp_charged_move_from_store( store_t * store,
                                 uint16_t move_id,
                                 pvp_charged_move_t * move
                               );




struct pvp_fast_move_s {
  base_move_t /*@@*/ base_move;
  uint8_t turns : 2;
} ;
typedef struct pvp_fast_move_s pvp_fast_move_t;

int pvp_fast_move_from_store( store_t * store,
                              uint16_t move_id,
                              pvp_fast_move_t * move
                            );
struct store_move_s {
  char * name;
  ptype_t type;
  bool is_fast : 1;
  uint16_t move_id;
  uint16_t cooldown;
  uint8_t pve_power;
  uint8_t pvp_power;
  uint8_t pve_energy;
  uint8_t pvp_energy;
  buff_t buff;
  UT_hash_handle hh_name;
  UT_hash_handle hh_move_id;
};
typedef struct store_move_s store_move_t;

int fprint_buff( FILE * stream, const buff_t * buff );


int fprint_buff_json( FILE * stream, const buff_t * buff );


int fprint_buff_c( FILE * stream, const buff_t * buff );





int fprint_store_move( FILE * stream, const store_move_t * move );


int fprint_store_move_json( FILE * stream, const store_move_t * move );


int fprint_store_move_c( FILE * stream, const store_move_t * move );

struct stats_s { uint16_t attack, stamina, defense; } ;
typedef struct stats_s stats_t;




typedef enum { TAG_NONE , TAG_LEGENDARY , TAG_MYTHIC , TAG_MEGA , TAG_SHADOW_ELIGABLE , TAG_SHADOW , TAG_PURE , TAG_ALOLAN , TAG_GALARIAN , TAG_STARTER , TAG_REGIONAL } pdex_tag_t;

/*typedef enum { TAG_NONE_M = ( ( ( !! ( TAG_NONE ) ) << ( TAG_NONE ) ) >> 1 ) , TAG_LEGENDARY_M = ( ( ( !! ( TAG_LEGENDARY ) ) << ( TAG_LEGENDARY ) ) >> 1 ) , TAG_MYTHIC_M = ( ( ( !! ( TAG_MYTHIC ) ) << ( TAG_MYTHIC ) ) >> 1 ) , TAG_MEGA_M = ( ( ( !! ( TAG_MEGA ) ) << ( TAG_MEGA ) ) >> 1 ) , TAG_SHADOW_ELIGABLE_M = ( ( ( !! ( TAG_SHADOW_ELIGABLE ) ) << ( TAG_SHADOW_ELIGABLE ) ) >> 1 ) , TAG_SHADOW_M = ( ( ( !! ( TAG_SHADOW ) ) << ( TAG_SHADOW ) ) >> 1 ) , TAG_PURE_M = ( ( ( !! ( TAG_PURE ) ) << ( TAG_PURE ) ) >> 1 ) , TAG_ALOLAN_M = ( ( ( !! ( TAG_ALOLAN ) ) << ( TAG_ALOLAN ) ) >> 1 ) , TAG_GALARIAN_M = ( ( ( !! ( TAG_GALARIAN ) ) << ( TAG_GALARIAN ) ) >> 1 ) , TAG_STARTER_M = ( ( ( !! ( TAG_STARTER ) ) << ( TAG_STARTER ) ) >> 1 ) , TAG_REGIONAL_M = ( ( ( !! ( TAG_REGIONAL ) ) << ( TAG_REGIONAL ) ) >> 1 ) } pdex_tag_mask_t; */
//@@hack
typedef unsigned int pdex_tag_mask_t;

 typedef union { pdex_tag_mask_t mask; struct { unsigned int TAG_LEGENDARY : 1 ; unsigned int TAG_MYTHIC : 1 ; unsigned int TAG_MEGA : 1 ; unsigned int TAG_SHADOW_ELIGABLE : 1 ; unsigned int TAG_SHADOW : 1 ; unsigned int TAG_PURE : 1 ; unsigned int TAG_ALOLAN : 1 ; unsigned int TAG_GALARIAN : 1 ; unsigned int TAG_STARTER : 1 ; unsigned int TAG_REGIONAL : 1; }; } pdex_tag_flags_t;




int fprint_pdex_tag_mask( FILE * fd, const char * sep, pdex_tag_mask_t tm );







struct region_s {
  char * name;
  uint16_t dex_start;
  uint16_t dex_end;
};
typedef struct region_s region_t;


typedef enum {
  R_KANTO = 0,
  R_JOHTO,
  R_HOENN,
  R_SINNOH,
  R_UNOVA,
  R_KALOS,
  R_UNKNOWN
} region_e;







struct pdex_mon_s {
  uint16_t dex_number;
  char * name;

  char * form_name;

  uint16_t family;
  ptype_mask_t types;
  stats_t base_stats;
  pdex_tag_mask_t tags;
  int16_t * fast_move_ids;
  uint8_t fast_moves_cnt;
  int16_t * charged_move_ids;
  uint8_t charged_moves_cnt;
  uint8_t form_idx;
  struct pdex_mon_s * next_form;

  UT_hash_handle hh_name;
  UT_hash_handle hh_dex_num;
};
typedef struct pdex_mon_s pdex_mon_t;





void pdex_mon_init( pdex_mon_t * mon,
                    uint16_t dex_num,
                    const char * name,
                    size_t name_len,
                    uint16_t family,
                    uint8_t form_num,
                    ptype_t type1,
                    ptype_t type2,
                    uint16_t stamina,
                    uint16_t attack,
                    uint16_t defense,
                    pdex_tag_mask_t tags,
                    int16_t * fast_move_ids,
                    uint8_t fast_moves_cnt,
                    int16_t * charged_move_ids,
                    uint8_t charged_moves_cnt
                  );
void pdex_mon_free( pdex_mon_t * mon );




int fprint_pdex_mon( FILE * stream, const pdex_mon_t * mon );
int fprint_pdex_mon_json( FILE * stream, const pdex_mon_t * mon );
int fprint_pdex_mon_c( FILE * stream, const pdex_mon_t * mon );
int cmp_pdex_mon( pdex_mon_t * a, pdex_mon_t * b );
int cmp_pdex_mon_practical( pdex_mon_t * a, pdex_mon_t * b );




struct cstore_aux_s {
  uint16_t mons_cnt;
  uint16_t moves_cnt;
  pdex_mon_t * mons_by_name;
  store_move_t * moves_by_id;
  store_move_t * moves_by_name;
};
typedef struct cstore_aux_s cstore_aux_t;



typedef store_t cstore_t;




bool cstore_has( store_t * cstore, store_key_t key );
int cstore_get( store_t * cstore, store_key_t key, void ** val );
int cstore_get_str( store_t * cstore, const char *, void ** val );
int cstore_get_str_t( store_t * cstore,
                       store_type_t val_type,
                       const char * key,
                       void ** val
                     );
int cstore_init( store_t * cstore, void * pokedex );
void cstore_free( store_t * cstore );




int cstore_get_pokemon( cstore_t * cstore,
                        uint16_t dex_num,
                        uint8_t form_idx,
                        pdex_mon_t ** mon
                      );

int cstore_get_pokemon_by_name( cstore_t * cstore,
                                const char * name,
                                pdex_mon_t ** mon
                              );




int cstore_get_move( cstore_t * cstore,
                     uint16_t move_id,
                     store_move_t ** move
                   );

int cstore_get_move_by_name( cstore_t * cstore,
                             const char * name,
                             store_move_t ** move
                           );



const store_t *get_cstore_p();
int get_pokemon_by_name(        const char *  name,
                                pdex_mon_t ** mon
				);
