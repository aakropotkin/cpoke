
/* Summary: ----------------------------------------------------------- {{{1 *

   This header file contains a library of advanced C Pre-Processor (CPP) macros
   which implement various useful functions, such as iteration, in the
   pre-processor.

   Though the file name (quite validly) labels this as magic, there should be
   enough documentation in the comments for a reader only casually familiar
   with the CPP to be able to understand how everything works.

   The majority of the magic tricks used in this file are based on those
   described by pfultz2 in his "Cloak" library:

   https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms

   Major differences are a greater level of detailed explanation in this
   implementation and also a refusal to include any macros which require a O(N)
   macro definitions to handle O(N) arguments (with the exception of DEFERn).

 * End Summary -------------------------------------------------------- }}}1 */

#ifndef _FN_MACROS_H
#define _FN_MACROS_H

/* About: ------------------------------------------------------------- {{{1 *
   Force the pre-processor to expand the macro a large number of times. Usage:

     `EVAL( expression )`

   This is useful when you have a macro which evaluates to a valid macro
   expression which is not subsequently expanded in the same pass. A contrived,
   but easy to understand, example of such a macro follows. Note that though
   this example is contrived, this behaviour is abused to implement bounded
   recursion in macros such as FOR.
     ```
     #define A( x )                  x + 1
     #define EMPTY
     #define NOT_QUITE_RIGHT( x )    A EMPTY( x )
     NOT_QUITE_RIGHT( 999 )
    ```
   Here's what happens inside the C preprocessor:

   1. It sees a macro `NOT_QUITE_RIGHT` and performs a single macro expansion
      pass on its arguments. Since the argument is `999` and this isn't a
      macro, this is a boring step resulting in no change.

   2. The NOT_QUITE_RIGHT macro is substituted for its definition giving
      `A EMPTY() (x)`

   3. The expander moves from left-to-right trying to expand the macro:
      The first token, A, cannot be expanded since there are no brackets
      immediately following it. The second token `EMPTY()`, however, can be
      expanded (recursively in this manner) and is replaced with `` (nothing).

   4. Expansion continues from the start of the substituted test (which in this
      case is just empty), and sees `( 999 )` but since no macro name is
      present, nothing is done. This results in a final expansion of
      `A ( 999 )`.

   Unfortunately, this doesn't quite meet expectations since you may expect
   that `A ( 999 )` would have been expanded into `999 + 1`. Unfortunately this
   requires a second expansion pass but luckily we can force the macro
   processor to make more passes by abusing the first step of macro expansion:
   the preprocessor expands arguments in their own pass.If we define a macro
   which does nothing except produce its arguments e.g.:
   `#define PASS_THROUGH(...) __VA_ARGS__`

   We can now do `PASS_THROUGH(NOT_QUITE_RIGHT( 999 ) )` causing
   `NOT_QUITE_RIGHT` to be expanded to `A ( 999 )`, as described above, when
   the arguments are expanded.  Now when the body of `PASS_THROUGH` is
   expanded, `A ( 999 )` gets expanded to `999 + 1`.

 * End About ---------------------------------------------------------- }}}1 */

/* Eval: -------------------------------------------------------------- {{{1 */

/* Eval Notes: -------------------------------------------------------- {{{2 *
   The EVAL defined below is essentially equivalent to a large nesting of
   `PASS_THROUGH( PASS_THROUGH( PASS_THROUGH( ...` which results in the
   preprocessor making a large number of expansion passes over the given
   expression.
 * End Eval Notes ----------------------------------------------------- }}}2 */

#define EVAL( ... )        EVAL1024( __VA_ARGS__ )
#define EVAL1024( ... )    EVAL512( EVAL512( __VA_ARGS__ ) )
#define EVAL512( ... )     EVAL256( EVAL256( __VA_ARGS__ ) )
#define EVAL256( ... )     EVAL128( EVAL128( __VA_ARGS__ ) )
#define EVAL128( ... )     EVAL64( EVAL64( __VA_ARGS__ ) )
#define EVAL64( ... )      EVAL32( EVAL32( __VA_ARGS__ ) )
#define EVAL32( ... )      EVAL16( EVAL16( __VA_ARGS__ ) )
#define EVAL16( ... )      EVAL8( EVAL8( __VA_ARGS__ ) )
#define EVAL8( ... )       EVAL4( EVAL4( __VA_ARGS__ ) )
#define EVAL4( ... )       EVAL2( EVAL2( __VA_ARGS__ ) )
#define EVAL2( ... )       EVAL1( EVAL1( __VA_ARGS__ ) )
#define EVAL1( ... )       __VA_ARGS__

/* End Eval ----------------------------------------------------------- }}}1 */

/* Common Values: ----------------------------------------------------- {{{1 */

/* Macros which expand to common values */
#define PASS( ... )    __VA_ARGS__
#define EMPTY()
#define COMMA()        ,
#define SEMICOLON()    ;
#define PLUS()         +
#define ZERO()         0
#define ONE()          1
#define ID( _VAL )     _VAL

/* End Common Values -------------------------------------------------- }}}1 */

/* Defer: ------------------------------------------------------------- {{{1 */

/* Defer Notes: ------------------------------------------------------- {{{2 *

   Causes a function-style macro to require an additional pass to be expanded.

   This is useful, for example, when trying to implement recursion since the
   recursive step must not be expanded in a single pass as the pre-processor
   will catch it and prevent it.

   Usage:

     `DEFER1( IN_NEXT_PASS ) ( args, to, the, macro )`

   How it works:

   1. When `DEFER1` is expanded, first its arguments are expanded which are
      simply `IN_NEXT_PASS`. Since this is a function-style macro and it has no
      arguments, nothing will happen.

   2. The body of `DEFER1` will now be expanded resulting in `EMPTY()` being
      deleted. This results in `IN_NEXT_PASS ( args, to, the_macro )`.
      Note that since the macro expander has already passed `IN_NEXT_PASS` by
      the time it expands `EMPTY()` and so it won't spot that the brackets
      which remain can be applied to `IN_NEXT_PASS`.

   3. At this point the macro expansion completes. If one more pass is made,
      `IN_NEXT_PASS( args, to, the, macro )` will be expanded as desired.

 * End Defer Notes ---------------------------------------------------- }}}2 */

#define DEFER1( id )    id EMPTY()

/* DeferX Notes: ------------------------------------------------------ {{{2 *

   As with `DEFER1` except here n additional passes are required for `DEFERX`.

   The mechanism is analogous.

   Note that there doesn't appear to be a way of combining `DEFERX` macros in
   order to achieve exponentially increasing defers e.g. as is done by `EVAL`.

 * End DeferX Notes --------------------------------------------------- }}}2 */

#define DEFER2( id )    id EMPTY EMPTY()()
#define DEFER3( id )    id EMPTY EMPTY EMPTY()()()
#define DEFER4( id )    id EMPTY EMPTY EMPTY EMPTY()()()()
#define DEFER5( id )    id EMPTY EMPTY EMPTY EMPTY EMPTY()()()()()
#define DEFER6( id )    id EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY()()()()()()
#define DEFER7( id )    id EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY    \
                           EMPTY()()()()()()()
#define DEFER8( id )    id EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY \
                           EMPTY()()()()()()()()

/* End Defer ---------------------------------------------------------- }}}1 */

/* Concatenate: ------------------------------------------------------- {{{1 */

/* Cat Notes:
   Indirection around the standard ## concatenation operator. This simply
   ensures that the arguments are expanded (once) before concatenation.
 */

#ifndef CAT
#  define CAT( a, ... ) _CAT( a, __VA_ARGS__ )
#endif /* ndef CAT */

#ifndef _CAT
#  define _CAT( a, ... ) a ## __VA_ARGS__
#endif /* ndef _CAT */

#ifndef CAT3
#  define CAT3( a, b, ... ) _CAT3( a, b, __VA_ARGS__ )
#endif /* ndef CAT3 */

#ifndef _CAT3
#  define _CAT3( a, b, ... ) a ## b ## __VA_ARGS__
#endif /* ndef _CAT3 */

/* End Concatenate ---------------------------------------------------- }}}1 */

/* First/Second: ------------------------------------------------------ {{{1 */

/* Get the first argument and ignore the rest. */
#define FIRST(a, ...) a

/* Get the second argument and ignore the rest. */
#define SECOND(a, b, ...) b

/* End First/Second --------------------------------------------------- }}}1 */

/* Probe: ------------------------------------------------------------- {{{1 */

/* Probe Notes: ------------------------------------------------------- {{{2 *

   Expects a single input (not containing commas). Returns 1 if the input is
   `PROBE()` and otherwise returns 0.

   This can be useful as the basis of a `NOT` function.

   This macro abuses the fact that `PROBE()` contains a comma while other valid
   inputs must not.

 * End Prob Notes ----------------------------------------------------- }}}2 */

#define IS_PROBE(...) SECOND(__VA_ARGS__, 0)
#define PROBE() ~, 1

/* Strip any excess commas from a set of arguments. */
#define REMOVE_TRAILING_COMMAS( ... )    MAP( PASS, COMMA, __VA_ARGS__ )

/* End Probe ---------------------------------------------------------- }}}1 */

/* Booleans and Conditionals: ----------------------------------------- {{{1 */

/* Not Notes: ---------------------------------------------------------- {{{2 *

   Logical negation. 0 is defined as false and everything else as true.

   When 0, `_NOT_0` will be found which evaluates to the `PROBE`. When 1
   (or any other value) is given, an appropriately named macro won't be found
   and the concatenated string will be produced.
   `IS_PROBE` then simply checks to see if the `PROBE` was returned, cleanly
   converting the argument into a 1 or 0.

 * End Not Notes ------------------------------------------------------ }}}2 */

#define NOT( x )    IS_PROBE( _CAT( _NOT_, x ) )
#define _NOT_0    PROBE()

/* Bool Notes:
   Macro version of C's famous "cast to bool" operator (i.e. !!) which takes
   anything and casts it to 0 if it is 0 and 1 otherwise.
 */
#define BOOL( x )    NOT( NOT( x ) )

/* Logical OR. Simply performs a lookup. */
#define OR( a, b )    _CAT3( _OR_, a, b )
#define _OR_00    0
#define _OR_01    1
#define _OR_10    1
#define _OR_11    1

/* Logical AND. Simply performs a lookup. */
#define AND( a, b )    _CAT3( _AND_, a, b )
#define _AND_00    0
#define _AND_01    0
#define _AND_10    0
#define _AND_11    1

/* If Notes: ---------------------------------------------------------- {{{2 *

   Macro if statement. Usage:

     `IF( c ) ( expansion when true )`

   Here's how:

   1. The preprocessor expands the arguments to `_IF` casting the condition to
      `0` or `1`.

   2. The casted condition is concatencated with `_IF_` giving `_IF_0` or
      `_IF_1`.

   3. The `_IF_0` and `_IF_1` macros either returns the argument or doesn't
      (e.g.  they implement the "choice selection" part of the macro).

   4. Note that the `true` clause is in the extra set of brackets; thus these
      become the arguments to `_IF_0` or `_IF_1` and thus a selection is made!

 * End If Notes ------------------------------------------------------- }}}2 */

#define IF( c )         _IF( BOOL( c ) )
#define _IF( c )        _CAT( _IF_, c )
#define _IF_0( ... )
#define _IF_1( ... )    __VA_ARGS__

/* If/Else Notes: ----------------------------------------------------- {{{2 *

   Macro if/else statement. Usage:
     ```
     IF_ELSE(c)( \
       expansion when true, \
       expansion when false \
     )
     ```

   The mechanism is analogous to `IF`.

 * End If/Else Notes -------------------------------------------------- }}}2 */

#define IF_ELSE( c )          _IF_ELSE( BOOL( c ) )
#define _IF_ELSE( c )         _CAT( _IF_ELSE_, c )
#define _IF_ELSE_0( t, f )    f
#define _IF_ELSE_1( t, f )    t

/* End Booleans and Conditionals -------------------------------------- }}}1 */

/* Has Arguments Predicate: ------------------------------------------- {{{1 */

/* Has Arguments Predicate Notes: ------------------------------------- {{{2 *

   Macro which checks if it has any arguments. Returns `0` if there are no
   arguments, `1` otherwise.

   Limitation: `HAS_ARGS( , 1, 2, 3 )` returns `0` -- this check essentially
   only checks that the first argument exists.

   This macro works as follows:

   1. `_END_OF_ARGUMENTS_` is concatenated with the first argument.

   2. If the first argument is not present then only `_END_OF_ARGUMENTS_` will
      remain, otherwise `_END_OF_ARGUMENTS something_here` will remain. This
      remaining argument can start with parentheses.

   3. In the former case, the `_END_OF_ARGUMENTS_( 0 )` macro expands to a
      0 when it is expanded. In the latter, a non-zero result remains. If the
      first argument started with parentheses these will mostly not contain
      only a single 0, but e.g a C cast or some arithmetic operation that will
      cause the `BOOL` in `_END_OF_ARGUMENTS_` to be one.

   4. `BOOL` is used to force non-zero results into 1 giving the clean 0 or 1
      output required.

 * End Has Arguments Predicate Notes ---------------------------------- }}}2 */

#define HAS_ARGS( ... ) BOOL( FIRST( _END_OF_ARGUMENTS_ __VA_ARGS__ )( 0 ) )
#define _END_OF_ARGUMENTS_( ... ) BOOL( FIRST( __VA_ARGS__ ) )

/* End Has Arguments Predicate ---------------------------------------- }}}1 */

/* Map: --------------------------------------------------------------- {{{1 */

/* Map Notes: --------------------------------------------------------- {{{2 *

   Macro map/list comprehension. Usage:

     `MAP( op, sep, ... )`

   Produces a `sep()`-separated list of the result of `op( arg )` for each arg.

   Example Usage:
     ```
     #define MAKE_HAPPY( x )    happy_ ## x
     #define COMMA()            ,
     MAP( MAKE_HAPPY, COMMA, 1, 2, 3 )
     ```

   Which expands to:
      `happy_1 , happy_2 , happy_3`

   How it works:

   1. The `MAP` macro simply maps the inner `MAP_INNER` function in an `EVAL`
      which forces it to be expanded a large number of times, thus enabling
      many steps of iteration (see step 6).

   2. The `MAP_INNER` macro is substituted for its body.

   3. In the body, `op( cur_val )` is substituted giving the value for this
      iteration.

   4. The `IF` macro expands according to whether further iterations are
      required. This expansion either produces `_IF_0` or `_IF_1`.

   5. Since the `IF` is followed by a set of brackets containing the "if true"
      clause, these become the argument to `_IF_0` or `_IF_1`. At this point,
      the macro in the brackets will be expanded giving the separator followed
      by `_MAP_INNER EMPTY() () ( op, sep, __VA_ARGS__ )`.

   5. If the `IF` was not taken, the above will simply be discarded and
      everything stops. If the `IF` is taken, The expression is then processed a
      second time yielding `_MAP_INNER() ( op, sep, __VA_ARGS__ )`.
      Note that this call looks very similar to the  essentially the same as
      the original call except the first argument has been dropped.

   6. At this point expansion of `MAP_INNER` will terminate.
      However, since we can force more rounds of expansion using `EVAL1`.
      In the argument - expansion pass of the `EVAL1`, `_MAP_INNER()` is
      expanded to `MAP_INNER` which is then expanded using the arguments which
      follow it as in step 2 - 5.
      This is followed by a second expansion pass as the substitution of
      `EVAL1()` is expanded executing 2 - 5 a second time.
      This results in up to two iterations occurring.Using many nested `EVAL1`
      macros, i.e.the very - deeply - nested `EVAL` macro, will in this manner
      produce further iterations, hence the outer MAP macro doing this for us.

   Important tricks used:

   * If we directly produce `MAP_INNER` in an expansion of `MAP_INNER`, a
     special case in the preprocessor will prevent it being expanded in the
     future, even if we `EVAL`. As a result, the `MAP_INNER` macro carefully
     only expands to something containing `_MAP_INNER()` which requires a
     further expansion step to invoke `MAP_INNER` and thus implementing the
     recursion.

   * To prevent `_MAP_INNER` being expanded within the macro we must first
     defer its expansion during its initial pass as an argument to `_IF_0` or
     `_IF_1`. We must then defer its expansion a second time as part of the
      body of the `_IF_0`. As a result hence the `DEFER2`.

   * `_MAP_INNER` seemingly gets away with producing itself because it actually
     only produces `MAP_INNER`. It just happens that when `_MAP_INNER()` is
     expanded in this case it is followed by some arguments which get consumed
     by MAP_INNER and produce a `_MAP_INNER`.  As such, the macro expander
     never marks `_MAP_INNER` as expanding to itself and thus it will still be
     expanded in future productions of itself.

 * End Map Notes ------------------------------------------------------ }}}2 */

#define MAP( ... )                     \
  IF( HAS_ARGS( __VA_ARGS__ ) )        \
    (                                  \
      EVAL( MAP_INNER( __VA_ARGS__ ) ) \
    )

#define MAP_INNER( op, sep, cur_val, ... )                      \
  op( cur_val )                                                 \
  IF( HAS_ARGS( __VA_ARGS__ ) )                                 \
    (                                                           \
      sep() DEFER2( _MAP_INNER ) () ( op, sep, ## __VA_ARGS__ ) \
    )
#define _MAP_INNER() MAP_INNER

/* End Map ------------------------------------------------------------ }}}1 */

/* Map With ID: ------------------------------------------------------- {{{1 */

/* Map With ID Notes: ------------------------------------------------- {{{2 *

   This is a variant of the MAP macro which also includes as an argument to the
   operation a valid C variable name which is different for each iteration.

   Usage:
     `MAP_WITH_ID( op, sep, ... )`

   Where op is a macro op(val, id) which takes a list value and an ID. This ID
   will simply be a unary number using the digit "I", that is, I, II, III,
   IIII, and so on.

   Example:
     ```
     #define MAKE_STATIC_VAR( type, name )    static type name;
     MAP_WITH_ID( MAKE_STATIC_VAR, EMPTY, int, int, int, bool, char )
     ```

   Which expands to:
     ```
     static int I; static int II; static int III; static bool IIII; \
     static char IIIII;
     ```

   The mechanism is analogous to the MAP macro.

 * End Map With ID Notes ---------------------------------------------- }}}2 */

#define MAP_WITH_ID( op, sep, ... )                          \
  IF( HAS_ARGS( __VA_ARGS__ ) )                              \
    (                                                        \
      EVAL( MAP_WITH_ID_INNER( op, sep, I, ## __VA_ARGS__) ) \
    )

#define MAP_WITH_ID_INNER( op, sep, id, cur_val, ... )                     \
  op( cur_val, id )                                                        \
  IF( HAS_ARGS( __VA_ARGS__ ) )                                            \
    (                                                                      \
      sep() DEFER2(                                                        \
        _MAP_WITH_ID_INNER ) () ( op, sep, _CAT( id, I ), ## __VA_ARGS__ ) \
    )
#define _MAP_WITH_ID_INNER() MAP_WITH_ID_INNER

/* End Map With ID ---------------------------------------------------- }}}1 */

/* Map Pairs: --------------------------------------------------------- {{{1 */

/* Map Pairs Notes: --------------------------------------------------- {{{2 *

   This is a variant of the `MAP` macro which iterates over pairs rather than
   singletons.

   Usage:
     `MAP_PAIRS( op, sep, ... )`

   Where op is a macro `op( val_1, val_2 )` which takes two list values.

   Example:
     ```
     #define MAKE_STATIC_VAR( type, name ) static type name;
     MAP_PAIRS( MAKE_STATIC_VAR, EMPTY, char, my_char, int, my_int )
     ```
   Which expands to:
     `static char my_char; static int my_int;`

   The mechanism is analogous to the MAP macro.

 * End Map Pairs Notes ------------------------------------------------ }}}2 */

#define MAP_PAIRS( op, sep, ... )                     \
  IF( HAS_ARGS( __VA_ARGS__ ) )                       \
    (                                                 \
      EVAL( MAP_PAIRS_INNER( op, sep, __VA_ARGS__ ) ) \
    )

#define MAP_PAIRS_INNER( op, sep, cur_val_1, cur_val_2, ... )      \
  op( cur_val_1, cur_val_2 )                                       \
  IF( HAS_ARGS( __VA_ARGS__ ) )                                    \
    (                                                              \
      sep() DEFER2( _MAP_PAIRS_INNER ) () ( op, sep, __VA_ARGS__ ) \
    )
#define _MAP_PAIRS_INNER()    MAP_PAIRS_INNER

/* End Map Pairs ------------------------------------------------------ }}}1 */

/* Map Slide: --------------------------------------------------------- {{{1 */

/* Map Slide Notes: --------------------------------------------------- {{{2 *

   This is a variant of the MAP macro which iterates over a two-element sliding
   window.

   Usage:
     `MAP_SLIDE( op, last_op, sep, ... )`

   Where op is a macro `op( val_1, val_2 )` which takes the two list values
   currently in the window. last_op is a macro taking a single value which is
   called for the last argument.

   Example:
    ```
      #define SIMON_SAYS_OP(simon, next) IF(NOT(simon()))(next)
      #define SIMON_SAYS_LAST_OP(val) last_but_not_least_##val
      #define SIMON_SAYS() 0

      MAP_SLIDE(
        SIMON_SAYS_OP,
        SIMON_SAYS_LAST_OP,
        EMPTY,
        wiggle,
        SIMON_SAYS,
        dance,
        move,
        SIMON_SAYS,
        boogie,
        stop
               )
    ```

   Which expands to:
     `dance boogie last_but_not_least_stop`

   The mechanism is analogous to the MAP macro.

 * End Map Slide ------------------------------------------------------ }}}2 */

#define MAP_SLIDE( op, last_op, sep, ... )                     \
  IF( HAS_ARGS( __VA_ARGS__ ) )                                \
    (                                                          \
      EVAL( MAP_SLIDE_INNER( op, last_op, sep, __VA_ARGS__ ) ) \
    )

#define MAP_SLIDE_INNER( op, last_op, sep, cur_val, ... )                 \
  IF( HAS_ARGS( __VA_ARGS__ ) )                                           \
    (                                                                     \
      op( cur_val, FIRST( __VA_ARGS__ ) )                                 \
    )                                                                     \
  IF( NOT( HAS_ARGS( __VA_ARGS__ ) ) )                                    \
    (                                                                     \
      last_op( cur_val )                                                  \
    )                                                                     \
  IF( HAS_ARGS( __VA_ARGS__ ) )                                           \
  (                                                                       \
    sep() DEFER2( _MAP_SLIDE_INNER ) () ( op, last_op, sep, __VA_ARGS__ ) \
  )
#define _MAP_SLIDE_INNER() MAP_SLIDE_INNER

/* End Map Slide ------------------------------------------------------ }}}1 */

#endif /* fnmacros.h */

/* vim: set foldmethod=marker foldlevel=0 : */
