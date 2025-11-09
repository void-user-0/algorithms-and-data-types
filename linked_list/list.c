#include "list.h"
#include <stdlib.h>

void linked_list_clean(struct linked_list *list)
{
  if (!list || !list->head)
    return;

  struct linked_list_node *node = list->head;
  struct linked_list_node *tmp = NULL;
  while (node) {
    tmp = node->next;
    free(node);
    node = tmp;
  }
  list->head = list->tail = NULL;
}

void linked_list_destroy(struct linked_list *list)
{
  if (!list) 
    return;

  linked_list_clean(list);
  free(list);
}

struct linked_list_node *new_linked_list_node() 
{
  struct linked_list_node *node = malloc(sizeof(struct linked_list_node));
  if (!node)
    return NULL;
  node->data = node->next = NULL;

  return node;
}

struct linked_list *new_linked_list()
{
  struct linked_list *list = malloc(sizeof(struct linked_list));
  if (!list)
    return NULL;
  list->head = list->tail = NULL;

  return list;
}

void linked_list_insert(struct linked_list *list, void *data)
{
  if (!list)
    return;

  struct linked_list_node *node = new_linked_list_node();
  if (!node)
    return;
  node->data = data;

  if (!list->head) {
    list->head = list->tail = node;
    return;
  }

  list->tail->next = node;
  list->tail = node;
}

struct linked_list_node *linked_list_search(struct linked_list *list, void *data)
{
  if (!list || !list->head)
    return NULL;
  

  struct linked_list_node *node = list->head;
  while (node) {
    if (node->data == data)
      return node;
    node = node->next;
  }
  
  return NULL;
}

void linked_list_delete(struct linked_list *list, void *data)
{
  if (!list || !list->head)
    return;

  struct linked_list_node *node = list->head;
  struct linked_list_node *prev = NULL;

  while (node) {
    if (node->data == data) {
      if (prev) 
        prev->next = node->next;
      else
        list->head = node->next;

      if (node == list->tail)
        list->tail = prev;

      free(node);
      return;
    }
    prev = node;
    node = node->next;
  }
  
}
