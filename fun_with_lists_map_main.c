/*
6 kyu
Fun with lists: map
https://www.codewars.com/kata/58259d9062cfb45e1a00006b
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node* next;
  int data;
};

typedef int (*map_func)(int);

struct Node* map_list(const struct Node* list, map_func f);

static int times_two(int x) {
  return x * 2;
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
                    map_func f,
                    const struct Node* expected) {
  struct Node* actual = map_list(list, f);
  printf("-> %s\n", compareList(expected, actual) ? "OK" : "FAIL");
  freeList(actual);
}

int main(void) {
  do_test(NULL, times_two, NULL);
  do_test(
      &(struct Node){
          .data = 5,
          .next =
              &(struct Node){
                  .data = 0,
                  .next =
                      &(struct Node){
                          .data = -8,
                          .next = &(struct Node){.data = 15, .next = NULL}}}},
      times_two,
      &(struct Node){
          .data = 10,
          .next = &(struct Node){
              .data = 0,
              .next = &(struct Node){
                  .data = -16,
                  .next = &(struct Node){.data = 30, .next = NULL}}}});
  return 0;
}
