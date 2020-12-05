/* -*- mode: c; -*- */
/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _LINUX_LIST_H
#define _LINUX_LIST_H

/* ========================================================================== */

#include <stddef.h>
#include <stdbool.h>

#define ENABLE_CHECK_DATA_CORRUPTION 1
#define CRASH_ON_DATA_CORRUPTION     1

#ifndef ENABLE_CHECK_DATA_CORRUPTION
  #define CHECK_DATA_CORRUPTION    0
#elif   ENABLE_CHECK_DATA_CORRUPTION == 1
  #include <stdarg.h>
  #include <stdio.h>
  #ifndef CRASH_ON_DATA_CORRUPTION
    #define CRASH_ON_DATA_CORRUPTION 0
  #elif   CRASH_ON_DATA_CORRUPTION == 1
    #include <assert.h>
    #define BUG()  assert( 0 );
  #endif
    #if CRASH_ON_DATA_CORRUPTION != 1
    #define BUG()  asm volatile( "nop" )
  #endif
#endif


#pragma GCC diagnostic ignored "-Wunused-parameter"


/* -------------------------------------------------------------------------- */

/**
 * Linked List:
 *
 * Expropriated from `linux/kernel/include/list.h`. Modified to reduce
 * dependencies on Kernel libs.
 *
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 *
 * Notable Changes:
 * - All instances of `WRITE_ONCE` and `READ_ONCE` have been removed, and have
 *   instead been replaced with `volatile` reads and writes.
 * - `typedef`s have been added for convenience, but are not used in this file.
 */


/* -------------------------------------------------------------------------- */


/* DoublyLinked List */
struct list_head
{
  struct list_head * next, * prev;
};
typedef struct list_head  list_t;

/* Singly Linked list */
struct hlist_head
{
  struct hlist_node * first;
};

struct hlist_node
{
  struct hlist_node * next, ** pprev;
};
typedef struct hlist_head hlist_t;
typedef struct hlist_node hnode_t;


/* -------------------------------------------------------------------------- */

/**
 * Initial value of a list node should point to itself with
 * both `next` and `prev` pointers.
 */

/* Declares head in the definition of a literal */
#define DECL_LIST( SELF )  { &( SELF ), &( SELF ) }

/* Define a list head outside of a structure */
#define DEF_LIST( NAME )  list_t NAME = DECL_LIST( NAME )

/* Initialize an existing list head, generally used on struct members */
  static inline void
init_list( list_t * list )
{
  ( (volatile list_t *) list )->next = list;
  list->prev = list;
}

/* Arbitrary values to mark deleted elements. */
#define LIST_POISON1  (void *) 0x100
#define LIST_POISON2  (void *) 0x200


/* -------------------------------------------------------------------------- */

/* Macros to provide branching hints to the compiler  */
#ifndef likely
#define likely( X )    __builtin_expect( ( X ), 1 )
#endif
#ifndef unlikely
#define unlikely( X )  __builtin_expect( ( X ), 0 )
#endif

#if ENABLE_CHECK_DATA_CORRUPTION == 1
/* Prevents compiler from optimizing out a return value */
#ifndef __must_check
#define __must_check  __attribute__(( warn_unused_result ))
#endif

static inline __must_check int check_data_corruption( int v ) { return v; }
#define CHECK_DATA_CORRUPTION( COND, FMT, ... )                               \
  check_data_corruption(                                                      \
    __extension__(                                                            \
    {                                                                         \
      int corrupt = unlikely( COND );                                         \
      if ( corrupt )                                                          \
        {                                                                     \
          va_list args;                                                       \
          va_start( args, FMT );                                              \
          vfprintf( stderr, FMT , args );                                     \
          va_end( args );                                                     \
          BUG();                                                              \
        }                                                                     \
      corrupt;                                                                \
    }                                                                         \
                 )                                                            \
                       )

  static inline bool
__is_list_add_valid( list_t * new, list_t * prev, list_t * next )
{
	if ( CHECK_DATA_CORRUPTION(
          next->prev != prev,
          "list_add corruption. next->prev should be prev (%px), but was %px."
          " (next=%px).\n",
          prev, next->prev, next
                            ) ||
	     CHECK_DATA_CORRUPTION(
          prev->next != next,
          "list_add corruption. prev->next should be next (%px), but was %px."
          " (prev=%px).\n",
          next, prev->next, prev
                            ) ||
	     CHECK_DATA_CORRUPTION(
          new == prev || new == next,
          "list_add double add: new=%px, prev=%px, next=%px.\n",
          new, prev, next
                             )
     ) return false;
	return true;
}

  static inline bool
__is_list_del_entry_valid( list_t * entry )
{
	list_t * prev, * next;

	prev = entry->prev;
	next = entry->next;

	if ( CHECK_DATA_CORRUPTION(
         next == LIST_POISON1,
         "list_del corruption, %px->next is LIST_POISON1 (%px)\n",
         entry, LIST_POISON1 ) ||
       CHECK_DATA_CORRUPTION(
         prev == LIST_POISON2,
         "list_del corruption, %px->prev is LIST_POISON2 (%px)\n",
         entry,
         LIST_POISON2       ) ||
	     CHECK_DATA_CORRUPTION(
         prev->next != entry,
         "list_del corruption. prev->next should be %px, but was %px\n",
         entry, prev->next  ) ||
	     CHECK_DATA_CORRUPTION(
         next->prev != entry,
         "list_del corruption. next->prev should be %px, but was %px\n",
         entry, next->prev  )
     ) return false;
  return true;
}

#else /* -------------------------------------------------------------------- */

  static inline bool
__is_list_add_valid( list_t * new, list_t * prev, list_t * next )
{
  return true;
}

  static inline bool
__is_list_del_entry_valid( list_t * entry )
{
  return true;
}
#endif

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
  static inline void
__list_add( list_t * new, list_t * prev, list_t * next )
{
  if ( ! __is_list_add_valid( new, prev, next ) ) return;
  next->prev = new;
  new->next  = next;
  new->prev  = prev;
  ( (volatile list_t *) prev )->next = new;
}


/* -------------------------------------------------------------------------- */

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks. When you continually add to a list's
 * head, this is equivelant to "pushing" an element to the top of a stack.
 */
  static inline void
list_add( list_t * new, list_t * head )
{
  __list_add( new, head, head->next );
}


/* -------------------------------------------------------------------------- */

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
  static inline void
list_add_tail( list_t * new, list_t * head )
{
  __list_add( new, head->prev, head );
}


/* -------------------------------------------------------------------------- */

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
  static inline void
__list_del( list_t * prev, list_t * next )
{
  next->prev = prev;
  ( (volatile list_t *) prev )->next = next;
}

/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
  static inline void
__list_del_entry( list_t * entry )
{
  if ( ! __is_list_del_entry_valid( entry ) ) return;
  __list_del( entry->prev, entry->next );
}

  static inline void
list_del( list_t * entry )
{
  __list_del_entry (entry);
  entry->next = LIST_POISON1;
  entry->prev = LIST_POISON2;
}


/* -------------------------------------------------------------------------- */

/**
 * list_replace - replace old entry by new one
 * @old : the element to be replaced
 * @new : the new element to insert
 *
 * If @old was empty, it will be overwritten.
 */
  static inline void
list_replace( list_t * old, list_t * new )
{
  new->next       = old->next;
  new->next->prev = new;
  new->prev       = old->prev;
  new->prev->next = new;
}

  static inline void
list_replace_init( list_t * old, list_t * new )
{
  list_replace( old, new );
  init_list( old );
}


/* -------------------------------------------------------------------------- */

/**
 * list_del_init - deletes entry from list and reinitialize it.
 * @entry: the element to delete from the list.
 */
  static inline void
list_del_init( list_t * entry )
{
  __list_del_entry( entry );
  init_list( entry );
}


/* -------------------------------------------------------------------------- */

/**
 * list_move - delete from one list and add as another's head
 * @list: the entry to move
 * @head: the head that will precede our entry
 */
  static inline void
list_move( list_t * list, list_t * head )
{
  __list_del_entry( list );
  list_add( list, head );
}

/**
 * list_move_tail - delete from one list and add as another's tail
 * @list: the entry to move
 * @head: the head that will follow our entry
 */
  static inline void
list_move_tail( list_t * list, list_t * head )
{
  __list_del_entry (list);
  list_add_tail (list, head);
}

/**
 * list_bulk_move_tail - move a subsection of a list to its tail
 * @head: the head that will follow our entry
 * @first: first entry to move
 * @last: last entry to move, can be the same as first
 *
 * Move all entries between @first and including @last before @head.
 * All three entries must belong to the same linked list.
 */
  static inline void
list_bulk_move_tail( list_t * head, list_t * first, list_t * last )
{
  first->prev->next = last->next;
  last->next->prev  = first->prev;

  head->prev->next = first;
  first->prev      = head->prev;

  last->next = head;
  head->prev = last;
}


/* -------------------------------------------------------------------------- */

/**
 * list_is_first -- tests whether @list is the first entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
  static inline int
is_list_first( const list_t * list, const list_t * head )
{
  return list->prev == head;
}

/**
 * list_is_last - tests whether @list is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
  static inline int
is_list_last( const list_t * list, const  list_t * head )
{
  return list->next == head;
}

/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
  static inline int
is_list_empty( const list_t * head )
{
  return ( (volatile const  list_t *) head )->next == head;
}

/**
 * list_empty_careful - tests whether a list is empty and not being modified
 * @head: the list to test
 *
 * Description:
 * tests whether a list is empty _and_ checks that no other CPU might be
 * in the process of modifying either member (next or prev)
 *
 * NOTE: using list_empty_careful() without synchronization
 * can only be safe if the only activity that can happen
 * to the list entry is list_del_init(). Eg. it cannot be used
 * if another CPU could re-list_add() it.
 */
  static inline int
is_list_empty_careful( const list_t * head )
{
  list_t * next = head->next;
  return ( next == head ) && ( next == head->prev );
}


/* -------------------------------------------------------------------------- */

/**
 * list_rotate_left - rotate the list to the left
 * @head: the head of the list
 */
  static inline void
list_rotate_left( list_t * head )
{
  list_t * first;
  if (  ! is_list_empty( head ) )
    {
      first = head->next;
      list_move_tail( first, head );
    }
}


/* -------------------------------------------------------------------------- */

/**
 * list_is_singular - tests whether a list has just one entry.
 * @head: the list to test.
 */
  static inline int
is_list_singular( const list_t * head  )
{
  return ( ! is_list_empty( head ) ) && ( head->next == head->prev );
}


/* -------------------------------------------------------------------------- */

  static inline void
__list_cut_position( list_t * list, list_t * head, list_t * entry )
{
  struct list_head * new_first = entry->next;

  list->next       = head->next;
  list->next->prev = list;
  list->prev       = entry;
  entry->next      = list;
  head->next       = new_first;
  new_first->prev  = head;
}

/**
 * list_cut_position - cut a list into two
 * @list: a new list to add all removed entries
 * @head: a list with entries
 * @entry: an entry within head, could be the head itself
 *	and if so we won't cut the list
 *
 * This helper moves the initial part of @head, up to and
 * including @entry, from @head to @list. You should
 * pass on @entry an element you know is on @head. @list
 * should be an empty list or a list you do not care about
 * losing its data.
 *
 */
  static inline void
list_cut_position( list_t * list, list_t * head, list_t * entry )
{
  if ( is_list_empty( head ) ) return;

  if ( is_list_singular( head ) &&
       ( ( head->next != entry ) && ( head != entry ) )
     ) return;

  if ( entry == head ) init_list( list );
  else                 __list_cut_position( list, head, entry );
}

/**
 * list_cut_before - cut a list into two, before given entry
 * @list: a new list to add all removed entries
 * @head: a list with entries
 * @entry: an entry within head, could be the head itself
 *
 * This helper moves the initial part of @head, up to but
 * excluding @entry, from @head to @list.  You should pass
 * in @entry an element you know is on @head.  @list should
 * be an empty list or a list you do not care about losing
 * its data.
 * If @entry == @head, all entries on @head are moved to
 * @list.
 */
  static inline void
list_cut_before( list_t * list, list_t * head, list_t * entry )
{
  if ( head->next == entry  )
    {
      init_list( list );
      return;
    }
  list->next       = head->next;
  list->next->prev = list;
  list->prev       = entry->prev;
  list->prev->next = list;
  head->next       = entry;
  entry->prev      = head;
}


/* -------------------------------------------------------------------------- */

  static inline void
__list_splice (const list_t * list, list_t * prev, list_t * next)
{
  list_t * first = list->next;
  list_t * last  = list->prev;

  first->prev = prev;
  prev->next  = first;

  last->next = next;
  next->prev = last;
}

/**
 * list_splice - join two lists, this is designed for stacks
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 */
  static inline void
list_splice( const list_t * list, list_t * head  )
{
  if ( ! is_list_empty( list ) ) __list_splice( list, head, head->next );
}

/**
 * list_splice_tail - join two lists, each list being a queue
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 */
  static inline void
list_splice_tail( list_t * list, list_t * head )
{
  if ( ! is_list_empty( list ) ) __list_splice( list, head->prev, head );
}

/**
 * list_splice_init - join two lists and reinitialise the emptied list.
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * The list at @list is reinitialised
 */
  static inline void
list_splice_init(list_t * list, list_t * head  )
{
  if ( ! is_list_empty( list ) )
    {
      __list_splice( list, head, head->next );
      init_list( list );
    }
}

/**
 * list_splice_tail_init - join two lists and reinitialise the emptied list
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * Each of the lists is a queue.
 * The list at @list is reinitialised
 */
  static inline void
list_splice_tail_init( list_t * list, list_t * head )
{
  if ( ! is_list_empty( list ) )
    {
      __list_splice( list, head->prev, head );
      init_list( list );
    }
}


/* -------------------------------------------------------------------------- */

#ifndef offsetof
#define offsetof( TYPE, MEMBER ) ( (size_t) &( (TYPE *) 0 )->MEMBER )
#endif

/**
 * container_of - cast a member of a structure out to the containing structure
 * @PTR:        the pointer to the member.
 * @TYPE:       the type of the container struct this is embedded in.
 * @MEMBER:     the name of the member within the struct.
 *
 */
#ifndef container_of
#define container_of( PTR, TYPE, MEMBER )                                     \
  __extension__(                                                              \
  {                                                                           \
        const typeof( ( (TYPE *) 0 )->MEMBER ) *__mptr = ( PTR );             \
        (TYPE *)( (char *) __mptr - offsetof( TYPE, MEMBER ) );               \
  }                                                                           \
               )
#endif


/* -------------------------------------------------------------------------- */

/**
 * list_entry - get the struct for this entry
 * @PTR:	the &struct list_head pointer.
 * @TYPE:	the type of the struct this is embedded in.
 * @MEMBER:	the name of the list_head within the struct.
 */
#define list_entry( PTR, TYPE, MEMBER )  container_of( PTR, TYPE, MEMBER )

/**
 * list_first_entry - get the first element from a list
 * @PTR:	the list head to take the element from.
 * @TYPE:	the type of the struct this is embedded in.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_first_entry( PTR, TYPE, MEMBER )                                 \
  list_entry( ( PTR )->next, TYPE, MEMBER )

/**
 * list_last_entry - get the last element from a list
 * @PTR:	the list head to take the element from.
 * @TYPE:	the type of the struct this is embedded in.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_last_entry( PTR, TYPE, MEMBER )                                  \
  list_entry( ( PTR )->prev, TYPE, MEMBER )

/**
 * list_first_entry_or_null - get the first element from a list
 * @PTR:	the list head to take the element from.
 * @TYPE:	the type of the struct this is embedded in.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Note that if the list is empty, it returns NULL.
 */
#define list_first_entry_or_null( PTR, TYPE, MEMBER )                         \
  __extension__(                                                              \
  {                                                                           \
    list_t * head__ = ( PTR );                                                \
    list_t * curr__  = ( ( (volatile list_t *) head__)->next );               \
    ( curr__ != head__ ) ? list_entry( curr__, TYPE, MEMBER ) : NULL;         \
  }                                                                           \
               )


/* -------------------------------------------------------------------------- */

/**
 * list_next_entry - get the next element in list
 * @CURR:	the type * to cursor
 * @MEMBER:	the name of the list_head within the struct.
 */
#define list_next_entry( CURR, MEMBER )                                       \
  list_entry( ( CURR )->MEMBER.next, typeof( * ( CURR ) ), MEMBER )

/**
 * list_prev_entry - get the prev element in list
 * @CURR:	the type * to cursor
 * @MEMBER:	the name of the list_head within the struct.
 */
#define list_prev_entry( CURR, MEMBER )                                       \
  list_entry( ( CURR )->MEMBER.prev, typeof( * ( CURR ) ), MEMBER )


/* -------------------------------------------------------------------------- */

/**
 * list_for_each	-	iterate over a list
 * @CURR:	the &struct list_head to use as a loop cursor.
 * @HEAD:	the head for your list.
 */
#define list_for_each( CURR, HEAD )                                           \
  for ( CURR = ( HEAD )->next; CURR != ( head ); CURR = CURR->next )

/**
 * list_for_each_prev	-	iterate over a list backwards
 * @CURR:	the &struct list_head to use as a loop cursor.
 * @HEAD:	the head for your list.
 */
#define list_for_each_prev( CURR, HEAD )                                      \
  for ( CURR = ( HEAD )->prev; CURR != ( HEAD ); CURR = CURR->prev )

/**
 * list_for_each_safe - iterate over a list safe against removal of list entry
 * @CURR:	the &struct list_head to use as a loop cursor.
 * @N:		another &struct list_head to use as temporary storage
 * @HEAD:	the head for your list.
 */
#define list_for_each_safe( CURR, N, HEAD )                                   \
  for ( CURR = ( HEAD )->next, N = CURR->next; CURR != ( HEAD );              \
        CURR = N, N = CURR->next )

/**
 * list_for_each_prev_safe - iterate over a list backwards safe against removal
 * of list entry
 * @CURR:	the &struct list_head to use as a loop cursor.
 * @N:		another &struct list_head to use as temporary storage
 * @HEAD:	the head for your list.
 */
#define list_for_each_prev_safe( CURR, N, HEAD )                              \
  for ( CURR = ( HEAD )->prev, N = CURR->prev;                                \
        CURR != ( HEAD ); CURR = N, N = CURR->prev )


/* -------------------------------------------------------------------------- */

/**
 * list_for_each_entry	-	iterate over list of given type
 * @CURR:	the type * to use as a loop cursor.
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 */
#define list_for_each_entry( CURR, HEAD, MEMBER )                             \
  for ( CURR = list_first_entry( HEAD, typeof( * CURR ), MEMBER );            \
        & CURR->MEMBER != ( HEAD ); CURR = list_next_entry( CURR, MEMBER ) )

/**
 * list_for_each_entry_reverse - iterate backwards over list of given type.
 * @CURR:	the type * to use as a loop cursor.
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 */
#define list_for_each_entry_reverse(CURR, HEAD, MEMBER)                       \
  for ( CURR = list_last_entry( HEAD, typeof( * CURR ), MEMBER );             \
        & CURR->MEMBER != ( HEAD ); CURR = list_prev_entry( CURR, MEMBER ) )


/* -------------------------------------------------------------------------- */

/**
 * list_prepare_entry - prepare a pos entry for use in
 * list_for_each_entry_continue()
 * @CURR:	the type * to use as a start point
 * @HEAD:	the head of the list
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Prepares a pos entry for use as a start point in
 * list_for_each_entry_continue().
 */
#define list_prepare_entry( CURR, HEAD, MEMBER )                              \
  ( ( POS ) ? : list_entry( HEAD, typeof( * POS ), MEMBER ) )

/**
 * list_for_each_entry_continue - continue iteration over list of given type
 * @CURR:	the type * to use as a loop cursor.
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Continue to iterate over list of given type, continuing after
 * the current position.
 */
#define list_for_each_entry_continue( CURR, HEAD, MEMBER )                    \
  for ( CURR = list_next_entry( CURR, MEMBER ); & CURR->MEMBER != ( HEAD );   \
        CURR = list_next_entry( CURR, MEMBER ) )

/**
 * list_for_each_entry_continue_reverse - iterate backwards from the given
 * point
 * @CURR:	the type * to use as a loop cursor.
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Start to iterate over list of given type backwards, continuing after
 * the current position.
 */
#define list_for_each_entry_continue_reverse( CURR, HEAD, MEMBER )            \
  for ( CURR = list_prev_entry( CURR, MEMBER ); & CURR->MEMBER != ( HEAD );   \
        CURR = list_prev_entry( CURR, MEMBER ) )


/* -------------------------------------------------------------------------- */

/**
 * list_for_each_entry_from - iterate over list of given type from the current
 * point
 * @CURR:	the type * to use as a loop cursor.
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Iterate over list of given type, continuing from current position.
 */
#define list_for_each_entry_from( CURR, HEAD, MEMBER )                        \
  for (; & CURR->MEMBER != ( HEAD ); CURR = list_next_entry( CURR, MEMBER ) )

/**
 * list_for_each_entry_from_reverse - iterate backwards over list of given type
 *                                    from the current point
 * @CURR:	the type * to use as a loop cursor.
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Iterate backwards over list of given type, continuing from current position.
 */
#define list_for_each_entry_from_reverse( CURR, HEAD, MEMBER )                \
  for (; & CURR->MEMBER != ( HEAD ); CURR = list_prev_entry( CURR, MEMBER ) )

/**
 * list_for_each_entry_safe - iterate over list of given type safe against
 * removal of list entry
 * @CURR:	the type * to use as a loop cursor.
 * @N:		another type * to use as temporary storage
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 */
#define list_for_each_entry_safe(CURR, N, HEAD, MEMBER)                       \
  for ( CURR = list_first_entry( HEAD, typeof( * CURR ), MEMBER ),            \
        N = list_next_entry( CURR, MEMBER ); & CURR->MEMBER != ( HEAD );      \
        CURR = N, N = list_next_entry( N, MEMBER ) )

/**
 * list_for_each_entry_safe_continue - continue list iteration safe against
 * removal
 * @CURR:	the type * to use as a loop cursor.
 * @N:		another type * to use as temporary storage
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Iterate over list of given type, continuing after current point,
 * safe against removal of list entry.
 */
#define list_for_each_entry_safe_continue(CURR, N, HEAD, MEMBER)              \
  for ( CURR = list_next_entry( CURR, MEMBER ),                               \
        N = list_next_entry( CURR, MEMBER ); & CURR->MEMBER != ( HEAD );      \
       CURR = N, N = list_next_entry( N, MEMBER ) )

/**
 * list_for_each_entry_safe_from - iterate over list from current point safe
 * against removal
 * @CURR:	the type * to use as a loop cursor.
 * @N:		another type * to use as temporary storage
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Iterate over list of given type from current point, safe against
 * removal of list entry.
 */
#define list_for_each_entry_safe_from( CURR, N, HEAD, MEMBER )                \
  for ( N = list_next_entry( CURR, MEMBER ); & CURR->MEMBER != ( HEAD );      \
        CURR = N, N = list_next_entry( N, MEMBER ) )

/**
 * list_for_each_entry_safe_reverse - iterate backwards over list safe against
 * removal
 * @CURR:	the type * to use as a loop cursor.
 * @N:		another type * to use as temporary storage
 * @HEAD:	the head for your list.
 * @MEMBER:	the name of the list_head within the struct.
 *
 * Iterate backwards over list of given type, safe against removal
 * of list entry.
 */
#define list_for_each_entry_safe_reverse( CURR, N, HEAD, MEMBER )             \
  for ( CURR = list_last_entry( HEAD, typeof( * CURR ), MEMBER ),             \
        N = list_prev_entry( CURR, MEMBER ); & CURR->MEMBER != ( HEAD );      \
        CURR = N, N = list_prev_entry( N, MEMBER ) )


/* -------------------------------------------------------------------------- */

/**
 * list_safe_reset_next - reset a stale list_for_each_entry_safe loop
 * @pos:	the loop cursor used in the list_for_each_entry_safe loop
 * @n:		temporary storage used in list_for_each_entry_safe
 * @member:	the name of the list_head within the struct.
 *
 * list_safe_reset_next is not safe to use in general if the list may be
 * modified concurrently (eg. the lock is dropped in the loop body). An
 * exception to this is if the cursor element (pos) is pinned in the list,
 * and list_safe_reset_next is called after re-taking the lock and before
 * completing the current iteration of the loop body.
 */
#define list_safe_reset_next(pos, n, member) \
  n = list_next_entry (pos, member)


/* -------------------------------------------------------------------------- */

/* Compare function to be used with `list_sort' */
typedef int __attribute__(( nonnull( 2, 3 ) ))
  (*cmp_func)( void *, list_t const *, list_t const * );

/**
 * Returns a list organized in an intermediate format suited
 * to chaining of merge() calls: null-terminated, no reserved or
 * sentinel head node, "prev" links not maintained.
 */
  __attribute__(( nonnull( 2, 3, 4 ) )) static list_t *
merge( void * priv, cmp_func cmp, list_t * a, list_t * b )
{
	list_t * head, ** tail = & head;
	for ( ;; )
    {
      /* if equal, take 'a' -- important for sort stability */
      if ( cmp( priv, a, b ) <= 0 )
        {
          *tail = a;
          tail  = & a->next;
          a = a->next;
          if ( a == NULL )
            {
              *tail = b;
              break;
            }
        } else {
          *tail = b;
          tail  = & b->next;
          b = b->next;
          if ( b == NULL )
            {
              *tail = a;
              break;
            }
        }
    }
	return head;
}


/**
 * Combine final list merge with restoration of standard doubly-linked
 * list structure.  This approach duplicates code from merge(), but
 * runs faster than the tidier alternatives of either a separate final
 * prev-link restoration pass, or maintaining the prev links
 * throughout.
 */
  __attribute__(( nonnull( 2, 3, 4, 5 ) )) static void
merge_final( void * priv, cmp_func cmp, list_t * head, list_t * a, list_t * b )
{
	list_t * tail = head;
	uint8_t count = 0;

	for ( ;; )
    {
      /* if equal, take 'a' -- important for sort stability */
      if ( cmp( priv, a, b ) <= 0 )
        {
          tail->next = a;
          a->prev    = tail;
          tail       = a;
          a          = a->next;
          if ( a == NULL ) break;
        } else {
          tail->next = b;
          b->prev    = tail;
          tail       = b;
          b          = b->next;
          if ( b == NULL )
            {
              b = a;
              break;
            }
        }
    }

	/* Finish linking remainder of list b on to tail */
	tail->next = b;
	do {
		/*
		 * If the merge is highly unbalanced (e.g. the input is
		 * already sorted), this loop may run many iterations.
		 * Continue callbacks to the client even though no
		 * element comparison is needed, so the client's cmp()
		 * routine can invoke cond_resched() periodically.
		 */
		if ( unlikely( 0 == ++count ) ) cmp( priv, b, b );
		b->prev = tail;
		tail    = b;
		b = b->next;
	} while ( b != NULL );

	/* And the final links to make a circular doubly-linked list */
	tail->next = head;
	head->prev = tail;
}


/**
 * list_sort - sort a list
 * @priv: private data, opaque to list_sort(), passed to @cmp
 * @head: the list to sort
 * @cmp: the elements comparison function
 *
 * The comparison funtion @cmp must return > 0 if @a should sort after
 * @b ("@a > @b" if you want an ascending sort), and <= 0 if @a should
 * sort before @b *or* their original order should be preserved.  It is
 * always called with the element that came first in the input in @a,
 * and list_sort is a stable sort, so it is not necessary to distinguish
 * the @a < @b and @a == @b cases.
 *
 * This is compatible with two styles of @cmp function:
 * - The traditional style which returns <0 / =0 / >0, or
 * - Returning a boolean 0/1.
 * The latter offers a chance to save a few cycles in the comparison
 * (which is used by e.g. plug_ctx_cmp() in block/blk-mq.c).
 *
 * A good way to write a multi-word comparison is::
 *
 *	if (a->high != b->high)
 *		return a->high > b->high;
 *	if (a->middle != b->middle)
 *		return a->middle > b->middle;
 *	return a->low > b->low;
 *
 *
 * This mergesort is as eager as possible while always performing at least
 * 2:1 balanced merges.  Given two pending sublists of size 2^k, they are
 * merged to a size-2^(k+1) list as soon as we have 2^k following elements.
 *
 * Thus, it will avoid cache thrashing as long as 3*2^k elements can
 * fit into the cache.  Not quite as good as a fully-eager bottom-up
 * mergesort, but it does use 0.2*n fewer comparisons, so is faster in
 * the common case that everything fits into L1.
 *
 *
 * The merging is controlled by "count", the number of elements in the
 * pending lists.  This is beautiully simple code, but rather subtle.
 *
 * Each time we increment "count", we set one bit (bit k) and clear
 * bits k-1 .. 0.  Each time this happens (except the very first time
 * for each bit, when count increments to 2^k), we merge two lists of
 * size 2^k into one list of size 2^(k+1).
 *
 * This merge happens exactly when the count reaches an odd multiple of
 * 2^k, which is when we have 2^k elements pending in smaller lists,
 * so it's safe to merge away two lists of size 2^k.
 *
 * After this happens twice, we have created two lists of size 2^(k+1),
 * which will be merged into a list of size 2^(k+2) before we create
 * a third list of size 2^(k+1), so there are never more than two pending.
 *
 * The number of pending lists of size 2^k is determined by the
 * state of bit k of "count" plus two extra pieces of information:
 *
 * - The state of bit k-1 (when k == 0, consider bit -1 always set), and
 * - Whether the higher-order bits are zero or non-zero (i.e.
 *   is count >= 2^(k+1)).
 *
 * There are six states we distinguish.  "x" represents some arbitrary
 * bits, and "y" represents some arbitrary non-zero bits:
 * 0:  00x: 0 pending of size 2^k;           x pending of sizes < 2^k
 * 1:  01x: 0 pending of size 2^k; 2^(k-1) + x pending of sizes < 2^k
 * 2: x10x: 0 pending of size 2^k; 2^k     + x pending of sizes < 2^k
 * 3: x11x: 1 pending of size 2^k; 2^(k-1) + x pending of sizes < 2^k
 * 4: y00x: 1 pending of size 2^k; 2^k     + x pending of sizes < 2^k
 * 5: y01x: 2 pending of size 2^k; 2^(k-1) + x pending of sizes < 2^k
 * (merge and loop back to state 2)
 *
 * We gain lists of size 2^k in the 2->3 and 4->5 transitions (because
 * bit k-1 is set while the more significant bits are non-zero) and
 * merge them away in the 5->2 transition.  Note in particular that just
 * before the 5->2 transition, all lower-order bits are 11 (state 3),
 * so there is one list of each smaller size.
 *
 * When we reach the end of the input, we merge all the pending
 * lists, from smallest to largest.  If you work through cases 2 to
 * 5 above, you can see that the number of elements we merge with a list
 * of size 2^k varies from 2^(k-1) (cases 3 and 5 when x == 0) to
 * 2^(k+1) - 1 (second merge of case 5 when x == 2^(k-1) - 1).
 */
  __attribute__(( nonnull( 2, 3 ) )) static void
list_sort( void   * priv,
           list_t * head,
		       int (*cmp)( void *priv, list_t * a, list_t * b )
         )
{
	list_t * list = head->next, * pending = NULL;
	size_t count = 0;	/* Count of pending */

	if ( list == head->prev ) return; /* Zero or one elements */

	/* Convert to a null-terminated singly-linked list. */
	head->prev->next = NULL;

	/*
	 * Data structure invariants:
	 * - All lists are singly linked and null-terminated; prev
	 *   pointers are not maintained.
	 * - pending is a prev-linked "list of lists" of sorted
	 *   sublists awaiting further merging.
	 * - Each of the sorted sublists is power-of-two in size.
	 * - Sublists are sorted by size and age, smallest & newest at front.
	 * - There are zero to two sublists of each size.
	 * - A pair of pending sublists are merged as soon as the number
	 *   of following pending elements equals their size (i.e.
	 *   each time count reaches an odd multiple of that size).
	 *   That ensures each later final merge will be at worst 2:1.
	 * - Each round consists of:
	 *   - Merging the two sublists selected by the highest bit
	 *     which flips when count is incremented, and
	 *   - Adding an element from the input as a size-1 sublist.
	 */
	do {
		size_t bits;
		list_t ** tail = & pending;

		/* Find the least-significant clear bit in count */
		for ( bits = count; bits & 1; bits >>= 1 ) tail = & ( * tail )->prev;
		/* Do the indicated merge */
		if ( likely( bits ) )
      {
        list_t * a = *tail, *b = a->prev;

        a = merge( priv, (cmp_func) cmp, b, a );
        /* Install the merged result in place of the inputs */
        a->prev = b->prev;
        *tail   = a;
      }

		/* Move one element from input list to pending */
		list->prev    = pending;
		pending       = list;
		list          = list->next;
		pending->next = NULL;
		count++;
	} while ( list != NULL );

	/* End of input; merge together all the pending lists. */
	list    = pending;
	pending = pending->prev;
	for ( ;; )
    {
      list_t * next = pending->prev;

      if ( next == NULL ) break;
      list = merge( priv, (cmp_func) cmp, pending, list );
      pending = next;
    }
	/* The final merge, rebuilding prev links */
	merge_final( priv, (cmp_func) cmp, head, pending, list );
}


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

/*
 * Double linked lists with a single pointer list head.
 * Mostly useful for hash tables where the two pointer list head is
 * too wasteful.
 * You lose the ability to access the tail in O(1).
 */

#define DECL_HLIST_HEAD  { .first = NULL }
#define DEF_HLIST_HEAD( NAME )  struct hlist_head NAME = { .first = NULL }
#define INIT_HLIST_HEAD( PTR )  ( ( PTR )->first = NULL )

  static inline void
INIT_HLIST_NODE( struct hlist_node * h )
{
  h->next  = NULL;
  h->pprev = NULL;
}

  static inline int
hlist_unhashed( const struct hlist_node * h )
{
  return ! h->pprev;
}

static inline int hlist_empty (const struct hlist_head * h)
{
  //return !READ_ONCE(h->first);
  return !((volatile const struct hlist_head *) h)->first;
}

static inline void __hlist_del (struct hlist_node * n)
{
  struct hlist_node *  next  = n->next;
  struct hlist_node ** pprev = n->pprev;

  //WRITE_ONCE(*pprev, next);
  *(volatile struct hlist_node **) pprev = next;
  if (next)
    next->pprev = pprev;
}

static inline void hlist_del (struct hlist_node * n)
{
  __hlist_del (n);
  n->next  = LIST_POISON1;
  n->pprev = LIST_POISON2;
}

static inline void hlist_del_init (struct hlist_node * n)
{
  if (!hlist_unhashed (n))
    {
      __hlist_del (n);
      INIT_HLIST_NODE (n);
    }
}

static inline void hlist_add_head (struct hlist_node * n,
                                   struct hlist_head * h)
{
  struct hlist_node * first = h->first;

  n->next = first;
  if (first)
    first->pprev = &n->next;
  //WRITE_ONCE(h->first, n);
  ((volatile struct hlist_head *) h)->first = n;
  n->pprev = &h->first;
}

/* next must be != NULL */
static inline void hlist_add_before (struct hlist_node * n,
                                     struct hlist_node * next)
{
  n->pprev    = next->pprev;
  n->next     = next;
  next->pprev = &n->next;
  //WRITE_ONCE(*(n->pprev), n);
  *((volatile struct hlist_node *) n)->pprev = n;
}

static inline void hlist_add_behind (struct hlist_node * n,
                                     struct hlist_node * prev)
{
  n->next = prev->next;
  //WRITE_ONCE(prev->next, n);
  ((volatile struct hlist_node *) prev)->next = n;
  n->pprev = &prev->next;

  if (n->next)
    n->next->pprev = &n->next;
}

/* after that we'll appear to be on some hlist and hlist_del will work */
static inline void hlist_add_fake (struct hlist_node * n)
{
  n->pprev = &n->next;
}

static inline bool hlist_fake (struct hlist_node * h)
{
  return h->pprev == &h->next;
}

/*
 * Check whether the node is the only node of the head without
 * accessing head:
 */
static inline bool
hlist_is_singular_node (struct hlist_node * n, struct hlist_head * h)
{
  return !n->next && n->pprev == &h->first;
}

/*
 * Move a list from one list head to another. Fixup the pprev
 * reference of the first entry if it exists.
 */
static inline void hlist_move_list (struct hlist_head * old,
                                    struct hlist_head * new)
{
  new->first = old->first;
  if (new->first)
    new->first->pprev = &new->first;
  old->first = NULL;
}

#define hlist_entry(ptr, type, member)    container_of (ptr, type, member)

#define hlist_for_each(pos, head) \
  for (pos = (head)->first; pos; pos = pos->next)

#define hlist_for_each_safe(pos, n, head)                   \
  for (pos = (head)->first; pos && ({ n = pos->next; 1; }); \
       pos = n)

#define hlist_entry_safe(ptr, type, member)                \
  ({ typeof (ptr) ____ptr = (ptr);                         \
     ____ptr ? hlist_entry (____ptr, type, member) : NULL; \
   })

/**
 * hlist_for_each_entry	- iterate over list of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your list.
 * @member:	the name of the hlist_node within the struct.
 */
#define hlist_for_each_entry(pos, head, member)                         \
  for (pos = hlist_entry_safe ((head)->first, typeof (*(pos)), member); \
       pos;                                                             \
       pos = hlist_entry_safe ((pos)->member.next, typeof (*(pos)), member))

/**
 * hlist_for_each_entry_continue - iterate over a hlist continuing after
 * current point
 * @pos:	the type * to use as a loop cursor.
 * @member:	the name of the hlist_node within the struct.
 */
#define hlist_for_each_entry_continue(pos, member)                           \
  for (pos = hlist_entry_safe ((pos)->member.next, typeof (*(pos)), member); \
       pos;                                                                  \
       pos = hlist_entry_safe ((pos)->member.next, typeof (*(pos)), member))

/**
 * hlist_for_each_entry_from - iterate over a hlist continuing from current
 * point
 * @pos:	the type * to use as a loop cursor.
 * @member:	the name of the hlist_node within the struct.
 */
#define hlist_for_each_entry_from(pos, member) \
  for (; pos;                                  \
       pos = hlist_entry_safe ((pos)->member.next, typeof (*(pos)), member))

/**
 * hlist_for_each_entry_safe - iterate over list of given type safe against
 * removal of list entry
 * @pos:	the type * to use as a loop cursor.
 * @n:		another &struct hlist_node to use as temporary storage
 * @head:	the head for your list.
 * @member:	the name of the hlist_node within the struct.
 */
#define hlist_for_each_entry_safe(pos, n, head, member)               \
  for (pos = hlist_entry_safe ((head)->first, typeof (*pos), member); \
       pos && ({ n = pos->member.next; 1; });                         \
       pos = hlist_entry_safe (n, typeof (*pos), member))


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* list.h */
