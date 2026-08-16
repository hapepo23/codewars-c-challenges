/*
6 kyu
Delete occurrences of an element if it occurs more than n times
https://www.codewars.com/kata/554ca54ffa7d91b236000023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* delete_nth(size_t szin, const int order[szin], int max_e, size_t* szout);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void tester(size_t len_in,
                   const int in[len_in],
                   int max_e,
                   size_t len_exp,
                   const int exp[len_exp]) {
  const size_t mem_size = len_exp * sizeof *exp;
  size_t len_act = 42;
  int* const act = delete_nth(len_in, in, max_e, &len_act);
  printf("input    = ");
  print_array(len_in, in);
  printf("\nexpected = ");
  print_array(len_exp, exp);
  printf("\nactual   = ");
  print_array(len_act, act);
  printf("\n-> %s\n\n",
         len_act != len_exp || memcmp(act, exp, mem_size) ? "FAIL" : "OK");
  free(act);
}

int main() {
  {
    const int order[4] = {20, 37, 20, 21};
    int max_e = 1;
    int expected[3] = {20, 37, 21};
    tester(4, order, max_e, 3, expected);
  }
  {
    const int order[9] = {1, 1, 3, 3, 7, 2, 2, 2, 2};
    int max_e = 3;
    int expected[8] = {1, 1, 3, 3, 7, 2, 2, 2};
    tester(9, order, max_e, 8, expected);
  }
  {
    const int order[5] = {1, 1, 1, 1, 1};
    int max_e = 5;
    int expected[5] = {1, 1, 1, 1, 1};
    tester(5, order, max_e, 5, expected);
  }
  {
    const int* order = NULL;
    int max_e = 5;
    int* expected = NULL;
    tester(0, order, max_e, 0, expected);
  }
  return 0;
}
