/*
7 kyu
Fun with lists: lastIndexOf
https://www.codewars.com/kata/581c867a33b9fe732e000076
*/

#include <stdio.h>

struct List {
  struct List* next;
  int data;
};

int last_index_of(const struct List* list, int search_val);

static void do_test(const struct List* list, int search_val, int expected) {
  int actual = last_index_of(list, search_val);
  printf("Expected: %d, actual: %d --> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(NULL, 8, -1);
  do_test(&(struct List){.data = 8, .next = NULL}, 666, -1);
  do_test(&(struct List){.data = 8, .next = NULL}, 8, 0);
  do_test(&(struct List){.data = 8,
                         .next = &(struct List){.data = 8, .next = NULL}},
          8, 1);
  do_test(&(
              struct List){.data = 5,
                           .next =
                               &(struct List){
                                   .data = 652,
                                   .next =
                                       &(struct List){
                                           .data = -7,
                                           .next = &(struct List){.data = 652,
                                                                  .next = &(
                                                                      struct List){.data = 32, .next = &(struct List){.data = 15, .next = NULL}}}}}},
          652, 3);
  return 0;
}
