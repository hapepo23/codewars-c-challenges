/*
7 kyu
Fun with lists: lastIndexOf
https://www.codewars.com/kata/581c867a33b9fe732e000076
*/

#include <stddef.h>

struct List {
  struct List* next;
  int data;
};

int last_index_of(const struct List* list, int search_val) {
  int result = -1;
  int index = 0;
  while (list != NULL) {
    if (list->data == search_val)
      result = index;
    list = list->next;
    ++index;
  }
  return result;
}
