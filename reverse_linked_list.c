/*
6 kyu
Reverse a singly-linked list
https://www.codewars.com/kata/57262ca48565846f33001365
*/

#include <stddef.h>

struct Node {
  int value;
  struct Node* next;
};

struct Node* reverse_list(struct Node* node) {
  struct Node* p = node;
  struct Node* prev = NULL;
  struct Node* next;
  while (p != NULL) {
    next = p->next;
    p->next = prev;
    prev = p;
    p = next;
  }
  return prev;
}
