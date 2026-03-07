#include <stdlib.h>
#include "dll.h"

struct list *new_list() 
{
  struct list *list = malloc(sizeof(struct list));
  if (!list)
    return NULL;
  list->head = list->tail = NULL;

  return list;
}

struct node *new_node() 
{
  struct node *node = malloc(sizeof(struct node));
  if (!node)
    return NULL;
  node->data = node->next = node->prev = NULL;

  return node;
}

void clean(struct list *list)
{
  if (!list || !list->head)
    return;

  struct node *node = list->head;
  struct node *tmp = NULL;
  while (node != NULL) {
    tmp = node->next;
    free(node);
    node = tmp;
  }

  list->head = list->tail = NULL;
}

void destroy(struct list *list)
{
  if (!list)
    return;

  clean(list);
  free(list);
}

void add(struct list *list, void *data)
{
  if (!list)
    return;

  struct node *node = new_node();
  if (!node)
    return;
  node->data = data;

  if (!list->head) {
    list->head = list->tail = node;
    return;
  }

  list->tail->next = node;
  node->prev = list->tail;
  list->tail = node;
}

struct node *search(struct list *list, void *data)
{
  if (!list || !list->head)
    return NULL;

  struct node *cur = list->head;

  while (cur != NULL) {
    if (cur->data == data) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

void del(struct list *list, void *data)
{
  if (!list || !list->head) 
    return;

  struct node *node = search(list, data);
  if (!node) 
    return;

  node->prev
    ? (node->prev->next = node->next)
    : (list->head = node->next);

  node->next
    ? (node->next->prev = node->prev)
    : (list->tail = node->prev);

  free(node);
}
