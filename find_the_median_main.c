/*
7 kyu
Find the median
https://www.codewars.com/kata/5864eb8039c5ab9cd400005c
*/

#include <math.h>
#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(array, expected) do_test(ARR_LEN(array), array, expected)

double median(size_t length, int array[length]);

static void print_array(size_t length, const int array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(size_t length, int array[length], double expected) {
  static const double epsilon = 1e-9;
  double actual = median(length, array);
  printf("array = ");
  print_array(length, array);
  printf("expected = %.10g, actual = %.10g -> %s\n\n", expected, actual,
         fabs(actual - expected) <= epsilon ? "OK" : "FAIL");
}

int main(void) {
  fixed_test(((int[]){3, 2, 1}), 2.0);
  fixed_test(((int[]){1}), 1.0);
  fixed_test(((int[]){1234, 345, 78}), 345.0);
  fixed_test(((int[]){33, 99, 100, 30, 29, 50}), 41.5);
  fixed_test(((int[]){3, 50}), 26.5);
  return 0;
}
