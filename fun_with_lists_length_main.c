/*
7 kyu
Fun with lists: length
https://www.codewars.com/kata/581e476d5f59408553000a4b
*/

#include <stdio.h>

typedef struct node_t {
  void* data;
  struct node_t* next;
} Node;

int length(const Node* head);

static void do_test(const Node* head, int expected) {
  int actual = length(head);
  printf("Expected: %d, actual: %d --> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  int dummy = 999;
  do_test(NULL, 0);
  do_test(&(Node){.data = &dummy, .next = NULL}, 1);
  do_test(
      &(Node){.data = &dummy, .next = &(Node){.data = &dummy, .next = NULL}},
      2);
  do_test(&(Node){.data = &dummy,
                  .next = &(
                      Node){.data = &dummy,
                            .next = &(Node){.data = &dummy,
                                            .next = &(Node){.data = &dummy,
                                                            .next = &(
                                                                Node){.data = &dummy, .next = &(Node){.data = &dummy, .next = NULL}}}}}},
          6);
  return 0;
}
