#ifndef linked_list_H
#define linked_list_H

#include <stdlib.h>

struct linked_list_node {
  struct linked_list_node *next;
  void *data;
};

struct linked_list {
  struct linked_list_node *head;
  struct linked_list_node *tail;
};

struct linked_list *linked_list_new();
struct linked_list_node *inked_list_new_node();
struct linked_list_node *linked_list_search_node(struct linked_list *, void *data);
void linked_list_check_and_insert_fist_element(struct linked_list *, struct linked_list_node *);
void linked_list_insert_head(struct linked_list *, void *data);
void linked_list_insert_tail(struct linked_list *, void *data);
void linked_list_delete_node(struct linked_list *, void *data);
void linked_list_destroy(struct linked_list *);
void linked_list_clean(struct linked_list *);

#endif
