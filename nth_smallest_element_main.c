/*
7 kyu
Nth Smallest Element
https://www.codewars.com/kata/5a512f6a80eba857280000fc
*/

#include <stddef.h>
#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int nth_smallest(const int* arr, int count, int n);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(size_t count, const int arr[count], int n, int expected) {
  int actual = nth_smallest(arr, count, n);
  printf("Array = ");
  print_array(count, arr);
  printf("\nn = %d, expected %d, actual %d -> %s\n\n", n, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    int a[] = {3, 1, 2}, n = 2, exp = 2;
    do_test(ARRAY_SIZE(a), a, n, exp);
  }
  {
    int a[] = {15, 20, 7, 10, 4, 3}, n = 3, exp = 7;
    do_test(ARRAY_SIZE(a), a, n, exp);
  }
  {
    int a[] = {-5, -1, -6, -18}, n = 4, exp = -1;
    do_test(ARRAY_SIZE(a), a, n, exp);
  }
  {
    int a[] = {-102, -16, -1, -2, -367, -9}, n = 5, exp = -2;
    do_test(ARRAY_SIZE(a), a, n, exp);
  }
  {
    int a[] = {2, 169, 13, -5, 0, -1}, n = 4, exp = 2;
    do_test(ARRAY_SIZE(a), a, n, exp);
  }
  {
    int a[] = {177, 225, 243, -169, -12, -5, 2, 92}, n = 5, exp = 92;
    do_test(ARRAY_SIZE(a), a, n, exp);
  }
  return 0;
}
