/*
7 kyu
Fun with lists: indexOf
https://www.codewars.com/kata/581c6b075cfa83852700021f
*/

#include <stddef.h>
#include <stdio.h>

struct Node {
  struct Node* next;
  int data;
};

int index_of(const struct Node* list, int search_val);

static void do_test(const struct Node* list, int search_val, int expected) {
  int actual = index_of(list, search_val);
  printf("Expected: %d, actual: %d --> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(NULL, 8, -1);
  do_test(&(struct Node){.data = 8, .next = NULL}, 666, -1);
  do_test(&(struct Node){.data = 8, .next = NULL}, 8, 0);
  do_test(&(struct Node){.data = 8,
                         .next = &(struct Node){.data = 8, .next = NULL}},
          8, 0);
  do_test(&(
              struct Node){.data = 5,
                           .next =
                               &(struct Node){
                                   .data = 0,
                                   .next =
                                       &(struct Node){
                                           .data = -7,
                                           .next = &(struct Node){.data = 652,
                                                                  .next = &(
                                                                      struct Node){.data = 32, .next = &(struct Node){.data = 15, .next = NULL}}}}}},
          652, 3);
  return 0;
}
