#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
  char *name = "John";
  int age = 22;

  unsigned int arr[5] = {5, 9, 4, 1, 10};
  doubly_linked_list *list = doubly_linked_list_new();
  if (!list)
    return -1;

  doubly_linked_list_node *search_node = NULL;
  doubly_linked_list_node *node = doubly_linked_list_new_node();
  doubly_linked_list_insert_head(list, name);
  search_node = doubly_linked_list_search_node(list, name);
  printf("%s\n", (char *)search_node->data);

  doubly_linked_list_destroy(list);

  return 0;
}
