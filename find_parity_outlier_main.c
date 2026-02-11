/*
6 kyu
Find The Parity Outlier
https://www.codewars.com/kata/5526fc09a1bbd946250002dc
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(array, expected) do_test(ARR_LEN(array), array, expected)

int find_outlier(const int values[], size_t count);

static void print_array(size_t length, const int array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}");
}

static void do_test(size_t count, const int array[count], int expected) {
  int actual = find_outlier(array, count);
  printf("For array: ");
  print_array(count, array);
  printf("\n");
  printf("expected %d, actual %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixed_test(((int[]){4, 1, 1}), 4);
  fixed_test(((int[]){1, 4, 1}), 4);
  fixed_test(((int[]){1, 1, 4}), 4);
  fixed_test(((int[]){1, 4, 4}), 1);
  fixed_test(((int[]){4, 1, 4}), 1);
  fixed_test(((int[]){4, 4, 1}), 1);
  fixed_test(((int[]){1, 1, 1, 1, 4}), 4);
  fixed_test(((int[]){4, 1, 1, 1, 1}), 4);
  fixed_test(((int[]){-5, -15, -30, -7, -9}), -30);
  fixed_test(((int[]){0, 0, 0, 7, 0}), 7);
  fixed_test(((int[]){-66, -67, -16}), -67);
  return 0;
}
