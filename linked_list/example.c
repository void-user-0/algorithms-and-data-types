#include "list.h"
#include <stdio.h>

void list_len(struct linked_list *list)
{
  if (!list->head)
    return;

  int len = 0;
  struct linked_list_node *node = list->head;
  if (!node)
    return;

  while (node != NULL) {
    len++;
    node = node->next;
  }

  printf("%d\n", len);
}

int main()
{
  int n = 5;
  char *name = "John";
  struct linked_list *list = new_linked_list();
  if (!list) {
    printf("err new list");
    return 1;
  }
  linked_list_insert(list, &n);
  linked_list_insert(list, name);

  struct linked_list_node *node = linked_list_search(list, name);
  if (!node) {
    printf("not found\n");
    return 1;
  }
  printf("%s\n", (char *)node->data);

  linked_list_delete(list, name);

  list_len(list);

  linked_list_destroy(list);
  return 0;
}
