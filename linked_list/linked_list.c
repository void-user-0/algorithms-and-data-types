#include "linked_list.h"

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

struct linked_list_node *linked_list_new_node() 
{
  struct linked_list_node *node = malloc(sizeof(struct linked_list_node));
  if (!node)
    return NULL;
  node->data = node->next = NULL;

  return node;
}

struct linked_list *linked_list_new()
{
  struct linked_list *list = malloc(sizeof(struct linked_list));
  if (!list)
    return NULL;
  list->head = list->tail = NULL;

  return list;
}

void linked_list_check_and_insert_first_element(struct linked_list *list, struct linked_list_node *node)
{
  if (!list->head) {
    list->head = list->tail = node;
    return;
  }
}

void linked_list_insert_tail(struct linked_list *list, void *data)
{
  if (!list)
    return;

  struct linked_list_node *node = linked_list_new_node();
  if (!node)
    return;
  node->data = data;

  linked_list_check_and_insert_first_element(list, node);

  list->tail->next = node;
  list->tail = node;
}

void linked_list_insert_head(struct linked_list *list, void *data) 
{
  if (!list)
    return;

  struct linked_list_node *node = linked_list_new_node();
  node->data = data;

  linked_list_check_and_insert_first_element(list, node);

  node->next = list->head;
  list->head = node;
}

struct linked_list_node *linked_list_search_node(struct linked_list *list, void *data)
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

void linked_list_delete_node(struct linked_list *list, void *data)
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
