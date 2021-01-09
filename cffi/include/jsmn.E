//__FROM__: include/ext/jsmn.h
typedef enum {
  JSMN_UNDEFINED = 0,
  JSMN_OBJECT = 1,
  JSMN_ARRAY = 2,
  JSMN_STRING = 3,
  JSMN_PRIMITIVE = 4
} jsmntype_t;

typedef enum jsmnerr {

  JSMN_ERROR_NOMEM = -1,

  JSMN_ERROR_INVAL = -2,

  JSMN_ERROR_PART = -3
} jsmnerr_t;







typedef struct jsmntok {
  jsmntype_t type;
  int start;
  int end;
  int size;



} jsmntok_t;





typedef struct jsmn_parser {
  unsigned int pos;
  unsigned int toknext;
  int toksuper;
} jsmn_parser;




static void jsmn_init(jsmn_parser *parser);






static int jsmn_parse(jsmn_parser *parser, const char *js, const size_t len,
                        jsmntok_t *tokens, const unsigned int num_tokens);





static jsmntok_t *jsmn_alloc_token(jsmn_parser *parser, jsmntok_t *tokens,
                                   const size_t num_tokens);



static void jsmn_fill_token(jsmntok_t *token, const jsmntype_t type,
                            const int start, const int end);



static int jsmn_parse_primitive(jsmn_parser *parser, const char *js,
                                const size_t len, jsmntok_t *tokens,
                                const size_t num_tokens);



static int jsmn_parse_string(jsmn_parser *parser, const char *js,
                             const size_t len, jsmntok_t *tokens,
                             const size_t num_tokens);



static int jsmn_parse(jsmn_parser *parser, const char *js, const size_t len,
                        jsmntok_t *tokens, const unsigned int num_tokens);




static void jsmn_init(jsmn_parser *parser);

//__FROM__: include/ext/jsmn_iterator.h
typedef enum jsmnitererr {

  JSMNITER_ERR_PARAMETER = -4,

  JSMNITER_ERR_TYPE = -5,

  JSMNITER_ERR_NOIDENT = -6,

  JSMNITER_ERR_BROKEN = -7,
} jsmnitererr_t;







typedef struct {
  jsmntok_t * jsmn_tokens;
  unsigned int jsmn_len;
  unsigned int parent_pos;
  unsigned int parser_pos;
  unsigned int index;
} jsmn_iterator_t;
int jsmn_iterator_find_last( jsmntok_t * jsmn_tokens,
                             unsigned int jsmn_len,
                             unsigned int parser_pos
                           );
jsmnitererr_t jsmn_iterator_init( jsmn_iterator_t * iterator,
                                  jsmntok_t * jsmn_tokens,
                                  unsigned int jsmn_len,
                                  unsigned int parser_pos
                                );
int jsmn_iterator_next( jsmn_iterator_t * iterator,
                        jsmntok_t ** jsmn_identifier,
                        jsmntok_t ** jsmn_value,
                        unsigned int next_value_index
                      );
//__FROM__: include/util/json_util.h
typedef struct jsmn_parser jsmn_parser_t;
jsmnerr_t jsmn_parse_realloc( jsmn_parser_t * parser,
                              const char * js,
                              size_t len,
                              jsmntok_t ** tokens,
                              size_t * num_tokens
                            );







typedef struct {
  char * fpath;
  char * buffer;
  size_t buffer_len;
  jsmn_parser_t jparser;
  jsmntok_t * tokens;
  size_t tokens_cnt;
} jsmn_file_parser_t;

void jsmn_file_parser_free( jsmn_file_parser_t * parser );







size_t jsmn_file_parser_init( jsmn_file_parser_t * f_parser,
                              const char * fpath
                            );
size_t toklen( const jsmntok_t * token );
int fprint_tok( FILE * stream, const char * json, const jsmntok_t * token );
int print_tok( const char * json, const jsmntok_t * token );




bool jsoneq( const char * json, const jsmntok_t * token, const char * str );
bool jsoneq_str( const char * json, const jsmntok_t * token, const char * str );
bool jsoneq_int( const char * json, const jsmntok_t * token, const int i );




bool jsonmatch_str( const char * json,
                    const jsmntok_t * token,
                    regex_t * regex
                  );
bool jsonmatch_str_pcre( const char * json,
                         const jsmntok_t * token,
                         pcre * regex
                       );
typedef bool ( * jsmntok_pred_fn )( const char *,
                                    const jsmntok_t *,
                                    void *
                                  );

static bool jsoneq_p( const char * json, const jsmntok_t * token, void * str );

static bool jsoneq_str_p( const char * json, const jsmntok_t * token,
                          void * str );
static bool jsoneq_int_p( const char * json, const jsmntok_t * token, void * i );

static bool jsonmatch_str_p( const char * json, const jsmntok_t * token,
                             void * r );

static bool jsonmatch_str_pcre_p( const char * json, const jsmntok_t * token,
                                  void * r );

  static bool
json_true_p( const char * json, const jsmntok_t * token, void * p );
int json_find( const char * json,
               const jsmntok_t * tokens,
               jsmntok_pred_fn pred,
               void * aux,
               size_t jsmn_len,
               size_t parser_pos
             );
int jsmn_iterator_find_next( const char * json,
                             jsmn_iterator_t * iterator,
                             jsmntok_t ** jsmn_identifier,
                             jsmntok_pred_fn identifier_pred,
                             void * identifier_aux,
                             jsmntok_t ** jsmn_value,
                             jsmntok_pred_fn value_pred,
                             void * value_aux,
                             size_t next_value_index
                           );







  static int
jsmn_iterator_find_key( const char * json,
                        jsmn_iterator_t * iterator,
                        jsmntok_t ** jsmn_identifier,
                        jsmntok_pred_fn identifier_pred,
                        void * identifier_aux,
                        jsmntok_t ** jsmn_value,
                        size_t next_value_index
                      );







  static int
jsmn_iterator_find_key_seq( const char * json,
                            jsmn_iterator_t * iterator,
                            jsmntok_t ** jsmn_identifier,
                            const char * str,
                            jsmntok_t ** jsmn_value,
                            size_t next_value_index
                            );

  static bool
jsmn_iterator_has_key( const char * json,
                       jsmn_iterator_t * iterator,
                       jsmntok_pred_fn identifier_pred,
                       void * identifier_aux,
                       size_t next_value_index
                     );







  static bool
jsmn_iterator_has_key_seq( const char * json,
                           jsmn_iterator_t * iterator,
                           char * str,
                           size_t next_value_index
                         );
  static size_t
jsmn_iterator_count( const char * json,
                     jsmn_iterator_t * iterator,
                     jsmntok_pred_fn identifier_pred,
                     void * identifier_aux,
                     jsmntok_pred_fn value_pred,
                     void * value_aux,
                     size_t next_value_index
                   );
jsmn_iterator_count_keys_pat( const char * json,
                              jsmn_iterator_t * iterator,
                              regex_t * regexp,
                              size_t next_value_index
                            );
  static size_t
jsmn_iterator_count_keys_pat_pcre( const char * json,
                                   jsmn_iterator_t * iterator,
                                   pcre * regexp,
                                   size_t next_value_index
                                 );





typedef jsmn_iterator_t jsmni_t;
//__FROM__: include/util/jsmn_iterator_stack.h
typedef jsmn_iterator_t jsmn_stacked_iterator_t;


struct jsmn_iterator_stack_s {
  jsmntok_t * tokens;
  jsmn_stacked_iterator_t * stack;
  unsigned long * is_object_flags;
  unsigned short stack_size;
  unsigned short stack_index;
  unsigned int jsmn_len;
  unsigned int hint;
};

typedef struct jsmn_iterator_stack_s jsmn_iterator_stack_t;




  static bool
get_is_object( const jsmn_iterator_stack_t * iter_stack, unsigned int idx );

  static jsmnitererr_t
set_is_object( jsmn_iterator_stack_t * iter_stack, unsigned int idx, bool val );




  static jsmn_iterator_t *
current_iterator( const jsmn_iterator_stack_t * iter_stack );



  static jsmnitererr_t
jsmn_iterator_stack_init( jsmn_iterator_stack_t * iter_stack,
                          jsmntok_t * tokens,
                          unsigned int jsmn_len,
                          unsigned short stack_size
                        );




  static void
jsmn_iterator_stack_free( jsmn_iterator_stack_t * iter_stack );



  static jsmnitererr_t
jsmn_iterator_stack_push( jsmn_iterator_stack_t * iter_stack,
                          unsigned int parser_pos
                        );
  static jsmnitererr_t
jsmn_iterator_stack_push_curr( jsmn_iterator_stack_t * iter_stack );





  static int
jsmn_iterator_stack_pop( jsmn_iterator_stack_t * iter_stack );








  static int
jsmn_iterator_stack_jump( jsmn_iterator_stack_t * iter_stack, unsigned short i );




  static jsmnitererr_t
jsmn_iterator_stack_open( const char * buffer,
                          jsmn_iterator_stack_t * iter_stack,
                          jsmntok_pred_fn identifier_pred,
                          void * identifier_aux,
                          jsmntok_pred_fn value_pred,
                          void * value_aux,
                          size_t next_value_index
                        );



  static jsmnitererr_t
jsmn_iterator_stack_open_key( const char * buffer,
                              jsmn_iterator_stack_t * iter_stack,
                              jsmntok_pred_fn identifier_pred,
                              void * identifier_aux,
                              size_t next_value_index
                            );




  static jsmnitererr_t
jsmn_iterator_stack_open_key_seq( const char * buffer,
                                  jsmn_iterator_stack_t * iter_stack,
                                  char * str,
                                  size_t next_value_index
                                );






typedef jsmn_iterator_stack_t jsmnis_t;
