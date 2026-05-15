/*
7 kyu
Form The Minimum
https://www.codewars.com/kata/5ac6932b2f317b96980000ca
*/

#include <stddef.h>
#include <stdio.h>

int minValue(const int* values, const size_t len);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(const int* values, const size_t len, const int expected) {
  int actual = minValue(values, len);
  printf("Array = ");
  print_array(len, values);
  printf("\nexpected %d, actual %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    const int expected = 13;
    const int arr[] = {1, 3, 1};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 457;
    const int arr[] = {4, 7, 5, 7};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 148;
    const int arr[] = {4, 8, 1, 4};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 579;
    const int arr[] = {5, 7, 9, 5, 7};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 678;
    const int arr[] = {6, 7, 8, 7, 6, 6};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 45679;
    const int arr[] = {5, 6, 9, 9, 7, 6, 4};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 134679;
    const int arr[] = {1, 9, 1, 3, 7, 4, 6, 6, 7};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 356789;
    const int arr[] = {3, 6, 5, 5, 9, 8, 7, 6, 3, 5, 9};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  {
    const int expected = 1;
    const int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const size_t len = sizeof(arr) / sizeof(arr[0]);
    do_test(arr, len, expected);
  }
  return 0;
}
