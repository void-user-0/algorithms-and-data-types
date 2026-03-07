#include "linked_list.h"
#include <stdio.h>

typedef unsigned int u16; // 0 - 65535

u16 linked_list_len(struct linked_list *list)
{
  if (!list->head)
    return 0;

  unsigned int len = 0;
  struct linked_list_node *node = list->head;
  if (!node)
    return 0;

  while (node != NULL) {
    len++;
    node = node->next;
  }

  return len;
}

int main()
{
  int n = 24;
  char *name = "John";
  struct linked_list *list = linked_list_new();
  if (!list) {
    printf("err new list");
    return 1;
  }
  linked_list_insert_tail(list, &n);
  linked_list_insert_tail(list, name);

  struct linked_list_node *node = linked_list_search_node(list, name);
  if (!node) {
    printf("not found node!\n");
    return 1;
  }
  printf("%s\n", (char *)node->data);
  node = linked_list_search_node(list, &n);
  if (!node)
    printf("not found node!");

  printf("%d\n", *(int *)node->data);

  linked_list_delete_node(list, name);

  u16 len = linked_list_len(list);

  printf("list len: %u\n", len);

  unsigned int age = 26;
  int nums[] = {5, 10, 15, 20};

  linked_list_insert_head(list, &age);
  node = linked_list_search_node(list, &age);
  printf("%u\n", *(unsigned int *)node->data);

  linked_list_delete_node(list, &age);
  
  linked_list_insert_head(list, nums);
  node = linked_list_search_node(list, nums);
  printf("%d\n", ((int *)node->data)[2]);

  printf("list len: %u\n", linked_list_len(list));

  linked_list_destroy(list);
  return 0;
}
