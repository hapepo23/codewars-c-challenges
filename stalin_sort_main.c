/*
7 kyu
Stalin Sort
https://www.codewars.com/kata/699af631058f5c12b04f4efe
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

void stalin_sort(size_t* length, int array[*length]);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(size_t lenin,
                    const int in[lenin],
                    size_t lenexp,
                    const int exp[lenexp]) {
  size_t mem_in = lenin * sizeof *in, mem_exp = lenexp * sizeof *exp;
  int* actual = NULL;
  if (mem_in) {
    actual = malloc(mem_in);
    memcpy(actual, in, mem_in);
  }
  size_t lenact = lenin;
  stalin_sort(&lenact, actual);
  printf("input    = ");
  print_array(lenin, in);
  printf("\nexpected = ");
  print_array(lenexp, exp);
  printf("\nactual   = ");
  print_array(lenact, actual);
  printf("\n->%s\n\n",
         (lenact != lenexp || memcmp(actual, exp, mem_exp)) ? "FAIL" : "OK");
  if (actual != NULL)
    free(actual);
}

int main(void) {
  {
    const int in[] = {}, exp[] = {};
    do_test(0, in, 0, exp);
  }
  {
    const int in[] = {3, 1, 4, 1, 5, 9, 2}, exp[] = {3, 4, 5, 9};
    do_test(ARR_LEN(in), in, ARR_LEN(exp), exp);
  }
  {
    const int in[] = {1, 2, 3}, exp[] = {1, 2, 3};
    do_test(ARR_LEN(in), in, ARR_LEN(exp), exp);
  }
  {
    const int in[] = {5, 3, 1}, exp[] = {5};
    do_test(ARR_LEN(in), in, ARR_LEN(exp), exp);
  }
  return 0;
}
