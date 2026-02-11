/*
6 kyu
Find the unique number
https://www.codewars.com/kata/585d7d5adb20cf33cb000235
*/

#include <stddef.h>
#include <stdio.h>

float finduniq(const float nums[], size_t n);

static void print_array(size_t length, const float array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%.6g%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(size_t n, const float nums[n], float expected) {
  float actual = finduniq(nums, n);
  printf("array: ");
  print_array(n, nums);
  printf("\n");
  printf("Expected: %.6g, actual: %.6g -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(6, (float[6]){2, 1, 1, 1, 1, 1}, 2);
  do_test(6, (float[6]){1, 2, 1, 1, 1, 1}, 2);
  do_test(6, (float[6]){1, 1, 2, 1, 1, 1}, 2);
  do_test(6, (float[6]){1, 1, 1, 2, 1, 1}, 2);
  do_test(5, (float[5]){0, 0, 0.55, 0, 0}, 0.55);
  do_test(9,
          (float[9]){999.666, 999.666, 999.666, 999.666, 999.666, 999.666,
                     999.666, 999, 999.666},
          999);
  return 0;
}
