#include "doubly_linked_list.h"

doubly_linked_list *doubly_linked_list_new() 
{
  doubly_linked_list *list = malloc(sizeof(struct doubly_linked_list));
  if (!list)
    return NULL;
  list->head = list->tail = NULL;

  return list;
}

doubly_linked_list_node *doubly_linked_list_new_node() 
{
  doubly_linked_list_node *node = malloc(sizeof(struct doubly_linked_list_node));
  if (!node)
    return NULL;
  node->data = node->next = node->prev = NULL;

  return node;
}

void doubly_linked_list_clean(doubly_linked_list *list)
{
  if (!list || !list->head)
    return;

  struct doubly_linked_list_node *node = list->head;
  struct doubly_linked_list_node *tmp = NULL;
  while (node != NULL) {
    tmp = node->next;
    free(node);
    node = tmp;
  }

  list->head = list->tail = NULL;
}

void doubly_linked_list_destroy(doubly_linked_list *list)
{
  if (!list)
    return;

  doubly_linked_list_clean(list);
  free(list);
}

doubly_linked_list_status doubly_linked_list_insert_head(doubly_linked_list *list, void *data)
{
  if (!list)
    return INSERT_FAILURE;

  doubly_linked_list_node *node = doubly_linked_list_new_node();
  if (!node)
    return INSERT_FAILURE;
  node->data = data;

  if (!list->head) {
    list->head = list->tail = node;
    return INSERT_SUCCESS;
  }

  list->tail->next = node;
  node->prev = list->tail;
  list->tail = node;
  return INSERT_SUCCESS;
}

doubly_linked_list_node *doubly_linked_list_search_node(doubly_linked_list *list, void *data)
{
  if (!list || !list->head)
    return NULL;

  doubly_linked_list_node *cur = list->head;

  while (cur != NULL) {
    if (cur->data == data) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

doubly_linked_list_status doubly_linked_list_delete_node(doubly_linked_list *list, void *data)
{
  if (!list || !list->head) 
    return DELETE_FAILURE;

  doubly_linked_list_node *node = doubly_linked_list_search_node(list, data);
  
  if (!node) 
    return DELETE_FAILURE;

  node->prev
    ? (node->prev->next = node->next)
    : (list->head = node->next);

  node->next
    ? (node->next->prev = node->prev)
    : (list->tail = node->prev);

  free(node);

  return DELETE_SUCCESS;
}
