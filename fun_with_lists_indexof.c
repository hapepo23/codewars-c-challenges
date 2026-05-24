/*
7 kyu
Fun with lists: indexOf
https://www.codewars.com/kata/581c6b075cfa83852700021f
*/

#include <stddef.h>

struct Node {
  struct Node* next;
  int data;
};

int index_of(const struct Node* list, int search_val) {
  int index = 0;
  while (list != NULL) {
    if (list->data == search_val)
      return index;
    list = list->next;
    ++index;
  }
  return -1;
}
