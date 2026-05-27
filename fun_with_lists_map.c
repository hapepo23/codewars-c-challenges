/*
6 kyu
Fun with lists: map
https://www.codewars.com/kata/58259d9062cfb45e1a00006b
*/

#include <stddef.h>
#include <stdlib.h>

struct Node {
  struct Node* next;
  int data;
};

typedef int (*map_func)(int);

struct Node* map_list(const struct Node* list, map_func f) {
  struct Node* newlist = NULL;
  struct Node* last = NULL;
  while (list != NULL) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = f(list->data);
    temp->next = NULL;
    if (newlist == NULL)
      newlist = temp;
    else
      last->next = temp;
    last = temp;
    list = list->next;
  }
  return newlist;
}
