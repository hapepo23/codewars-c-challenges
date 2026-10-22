/*
6 kyu
+1 Array
https://www.codewars.com/kata/5514e5b77e6b2f38e0000ca9
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

int* up_array(const int arr[], unsigned* count);

static void print_array(size_t length, const int array[length]) {
  if (array == NULL) {
    printf("NULL");
    return;
  }
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}");
}

static void do_test(size_t len_in,
                    const int in[len_in],
                    size_t len_exp,
                    const int expected[len_exp]) {
  unsigned len_act = len_in;
  int* actual = up_array(in, &len_act);
  const bool ok = !(expected == NULL && actual != NULL) &&
                  (len_act == len_exp) && !(len_act != 0 && actual == NULL) &&
                  !memcmp(actual, expected, len_exp * sizeof *expected);
  printf("Input    = ");
  print_array(len_in, in);
  printf("\nExpected = ");
  print_array(len_exp, expected);
  printf("\nActual   = ");
  print_array(len_act, actual);
  printf("\nExpected count = %zu; actual count = %u\n-> %s\n\n", len_exp,
         len_act, ok ? "OK" : "FAIL");
  if (actual != NULL)
    free(actual);
}

int main(void) {
  { do_test(0, NULL, 0, NULL); }
  {
    int arr[] = {1, 2, 33};
    do_test(ARRAY_COUNT(arr), arr, 0, NULL);
  }
  {
    int arr[] = {2, 3, 9}, exp[] = {2, 4, 0};
    do_test(ARRAY_COUNT(arr), arr, ARRAY_COUNT(exp), exp);
  }
  {
    int arr[] = {4, 3, 2, 5}, exp[] = {4, 3, 2, 6};
    do_test(ARRAY_COUNT(arr), arr, ARRAY_COUNT(exp), exp);
  }
  {
    int arr[] = {1, -9};
    do_test(ARRAY_COUNT(arr), arr, 0, NULL);
  }
  {
    int arr[] = {0, 4, 2}, exp[] = {0, 4, 3};
    do_test(ARRAY_COUNT(arr), arr, ARRAY_COUNT(exp), exp);
  }
  {
    int arr[] = {9, 9, 9}, exp[] = {1, 0, 0, 0};
    do_test(ARRAY_COUNT(arr), arr, ARRAY_COUNT(exp), exp);
  }
  {
    int arr[] = {9, 2, 2, 3, 3, 7, 2, 0, 3, 6, 8, 5, 4, 7, 7, 5, 8, 0, 7},
        exp[] = {9, 2, 2, 3, 3, 7, 2, 0, 3, 6, 8, 5, 4, 7, 7, 5, 8, 0, 8};
    do_test(ARRAY_COUNT(arr), arr, ARRAY_COUNT(exp), exp);
  }
  return 0;
}
