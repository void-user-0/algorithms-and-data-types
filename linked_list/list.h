#ifndef linked_list_H
#define linked_list_H

struct linked_list_node {
  struct linked_list_node *next;
  void *data;
};

struct linked_list {
  struct linked_list_node *head;
  struct linked_list_node *tail;
};

struct linked_list *new_linked_list();
struct linked_list_node *new_linked_list_node();
void linked_list_destroy(struct linked_list *);
void linked_list_clean(struct linked_list *);

void linked_list_insert(struct linked_list *, void *data);
void linked_list_delete(struct linked_list *, void *data);
struct linked_list_node *linked_list_search(struct linked_list *, void *data);

#endif
