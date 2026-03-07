#ifndef DLL_H
#define DLL_H

#include <stdbool.h>

struct node {
  void *data;
  struct node *next;
  struct node *prev;
};

struct list {
  struct node *head;
  struct node *tail;
};

struct node *new_node();
struct list *new_list();

void clean(struct list *);
void destroy(struct list *);

bool is_empty(struct list *);

struct node *search(struct list *, void *data);
void del(struct list *, void *data);
void add(struct list *, void *data);

#endif
