/*
7 kyu
Fun with lists: anyMatch + allMatch
https://www.codewars.com/kata/581e50555f59405743001813
*/

#include <stdbool.h>
#include <stddef.h>

struct Node {
  struct Node* next;
  int data;
};

typedef bool (*predicate_func)(int);

bool any_match(const struct Node* list, predicate_func f) {
  while (list != NULL) {
    if (f(list->data))
      return true;
    list = list->next;
  }
  return false;
}

bool all_match(const struct Node* list, predicate_func f) {
  while (list != NULL) {
    if (!f(list->data))
      return false;
    list = list->next;
  }
  return true;
}
