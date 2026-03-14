/*
6 kyu
Reverse a singly-linked list
https://www.codewars.com/kata/57262ca48565846f33001365
*/

#include <stddef.h>
#include <stdio.h>

struct Node {
  int value;
  struct Node* next;
};

struct Node* reverse_list(struct Node* node);

static void do_test(struct Node* input, struct Node* expected) {
  struct Node* p = input;
  printf("Input:");
  while (p != NULL) {
    printf(" %d", p->value);
    p = p->next;
  }
  puts("");
  p = expected;
  printf("Expected:");
  while (p != NULL) {
    printf(" %d", p->value);
    p = p->next;
  }
  puts("");
  input = reverse_list(input);
  p = input;
  printf("Actual:");
  while (p != NULL) {
    printf(" %d", p->value);
    p = p->next;
  }
  puts("");
}

int main(void) {
  struct Node input[3];
  struct Node expected[3];
  input[0].value = 1;
  input[0].next = &input[1];
  input[1].value = 2;
  input[1].next = &input[2];
  input[2].value = 3;
  input[2].next = NULL;
  expected[0].value = 3;
  expected[0].next = &expected[1];
  expected[1].value = 2;
  expected[1].next = &expected[2];
  expected[2].value = 1;
  expected[2].next = NULL;
  do_test(input, expected);
  return 0;
}
