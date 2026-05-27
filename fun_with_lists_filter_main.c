/*
6 kyu
Fun with lists: filter
https://www.codewars.com/kata/582041237df353e01d000084
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node* next;
  int data;
};

typedef bool (*predicate_func)(int);

struct Node* filter_list(const struct Node* list, predicate_func f);

static bool is_odd(int x) {
  return x % 2;
}

static bool is_even(int x) {
  return !(x % 2);
}

static void freeList(struct Node* list) {
  while (list != NULL) {
    struct Node* nx = list->next;
    free(list);
    list = nx;
  }
}

static bool compareList(const struct Node* list1, const struct Node* list2) {
  if (list1 == NULL && list1 == NULL)
    return true;
  while (list1 != NULL) {
    if (list2 != NULL) {
      if (list1->data != list2->data)
        return false;
      list2 = list2->next;
    } else {
      return false;
    }
    list1 = list1->next;
  }
  if (list2 == NULL)
    return true;
  return false;
}

static void do_test(const struct Node* list,
                    predicate_func f,
                    const struct Node* expected) {
  struct Node* actual = filter_list(list, f);
  printf("-> %s\n", compareList(expected, actual) ? "OK" : "FAIL");
  freeList(actual);
}

int main(void) {
  do_test(NULL, is_odd, NULL);
  struct Node* list = &(struct Node){
      .data = 3,
      .next = &(struct Node){.data = 7,
                             .next = &(struct Node){.data = 6,
                                                    .next = &(struct Node){
                                                        .data = 8,
                                                    }}}};
  do_test(list, is_odd,
          &(struct Node){.data = 3,
                         .next = &(struct Node){
                             .data = 7,
                         }});
  do_test(list, is_even,
          &(struct Node){.data = 6,
                         .next = &(struct Node){
                             .data = 8,
                         }});
  return 0;
}
