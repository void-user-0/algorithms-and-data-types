#ifndef doubly_linked_list_H
#define doubly_linked_list_H

#include <stdlib.h>

typedef struct doubly_linked_list_node {
  struct doubly_linked_list_node  *next;
  struct doubly_linked_list_node  *prev;
  void *data;
} doubly_linked_list_node;

typedef struct doubly_linked_list {
  struct doubly_linked_list_node *head;
  struct doubly_linked_list_node *tail;
} doubly_linked_list;

typedef enum {
  INSERT_SUCCESS =  0,
  INSERT_FAILURE = -1,
  DELETE_SUCCESS =  0,
  DELETE_FAILURE = -1
} doubly_linked_list_status;

doubly_linked_list_node *doubly_linked_list_search_node(doubly_linked_list *, void *);
doubly_linked_list_node *doubly_linked_list_new_node();
doubly_linked_list      *doubly_linked_list_new();

doubly_linked_list_status doubly_linked_list_insert_head(doubly_linked_list *, void *);
doubly_linked_list_status doubly_linked_list_insert_tail(doubly_linked_list *, void *);
doubly_linked_list_status doubly_linked_list_delete_node(doubly_linked_list *, void *);
doubly_linked_list_status doubly_linked_list_is_empty(doubly_linked_list *);

void doubly_linked_list_clean(doubly_linked_list *);
void doubly_linked_list_destroy(doubly_linked_list *);

#endif
