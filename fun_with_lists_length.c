/*
7 kyu
Fun with lists: length
https://www.codewars.com/kata/581e476d5f59408553000a4b
*/

#include <stddef.h>

typedef struct node_t {
  void* data;
  struct node_t* next;
} Node;

int length(const Node* head) {
  int result = 0;
  while (head != NULL) {
    head = head->next;
    ++result;
  }
  return result;
}