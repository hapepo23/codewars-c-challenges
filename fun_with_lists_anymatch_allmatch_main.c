/*
7 kyu
Fun with lists: anyMatch + allMatch
https://www.codewars.com/kata/581e50555f59405743001813
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

enum type { ANY, ALL };

struct Node {
  struct Node* next;
  int data;
};

typedef bool (*predicate_func)(int);

bool any_match(const struct Node* list, predicate_func f);
bool all_match(const struct Node* list, predicate_func f);

static bool is_odd(int x) {
  return x % 2;
}

static bool is_even(int x) {
  return !(x % 2);
}

static void do_test(const struct Node* list,
                    predicate_func f,
                    enum type type,
                    bool expected) {
  bool actual;
  if (type == ANY)
    actual = any_match(list, f);
  else
    actual = all_match(list, f);
  printf("Type: %s, Expected: %s, actual: %s --> %s\n",
         type == ANY ? "ANY" : "ALL", expected ? "TRUE" : "FALSE",
         actual ? "TRUE" : "FALSE", expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(NULL, is_odd, ANY, false);
  do_test(NULL, is_odd, ALL, true);
  struct Node* list1 =
      &(struct Node){.data = 3, .next = &(struct Node){.data = 7}};
  do_test(list1, is_odd, ANY, true);
  do_test(list1, is_odd, ALL, true);
  do_test(list1, is_even, ANY, false);
  do_test(list1, is_even, ALL, false);
  struct Node* list2 =
      &(struct Node){.data = 3, .next = &(struct Node){.data = 4}};
  do_test(list2, is_odd, ANY, true);
  do_test(list2, is_odd, ALL, false);
  do_test(list2, is_even, ANY, true);
  do_test(list2, is_even, ALL, false);
  return 0;
}
