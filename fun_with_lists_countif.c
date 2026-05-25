/*
6 kyu
Fun with lists: countIf
https://www.codewars.com/kata/5819081d056d4bdd410004f8
*/

#include <stdbool.h>
#include <stddef.h>

struct Node {
  struct Node* next;
  int data;
};

typedef bool (*predicate_func)(int);

int count_if(const struct Node* list, predicate_func predicate) {
  int count = 0;
  while (list != NULL) {
    if (predicate(list->data))
      ++count;
    list = list->next;
  }
  return count;
}
