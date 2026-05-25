/*
6 kyu
Fun with lists: countIf
https://www.codewars.com/kata/5819081d056d4bdd410004f8
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct Node {
  struct Node* next;
  int data;
};

typedef bool (*predicate_func)(int);

int count_if(const struct Node* list, predicate_func predicate);

static bool is_odd(int x) {
  return x % 2;
}

static bool is_even(int x) {
  return !(x % 2);
}

static void do_test(const struct Node* list, predicate_func f, int expected) {
  int actual = count_if(list, f);
  printf("Expected: %d, actual: %d --> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(NULL, is_odd, 0);
  struct Node* list = &(struct Node){
      .data = 3,
      .next = &(struct Node){.data = 7,
                             .next = &(struct Node){.data = 6,
                                                    .next = &(struct Node){
                                                        .data = 8,
                                                    }}}};
  do_test(list, is_odd, 2);
  do_test(list, is_even, 2);
  return 0;
}
