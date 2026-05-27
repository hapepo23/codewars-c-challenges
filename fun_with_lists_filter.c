/*
6 kyu
Fun with lists: filter
https://www.codewars.com/kata/582041237df353e01d000084
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct Node {
  struct Node* next;
  int data;
};

typedef bool (*predicate_func)(int);

struct Node* filter_list(const struct Node* list, predicate_func f) {
  struct Node* newlist = NULL;
  struct Node* last = NULL;
  while (list != NULL) {
    if (f(list->data)) {
      struct Node* temp = malloc(sizeof(struct Node));
      temp->data = list->data;
      temp->next = NULL;
      if (newlist == NULL)
        newlist = temp;
      else
        last->next = temp;
      last = temp;
    }
    list = list->next;
  }
  return newlist;
}
