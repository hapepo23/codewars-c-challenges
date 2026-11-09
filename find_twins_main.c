/*
7 kyu
Find twins
https://www.codewars.com/kata/5834315e06f227a6ac000099
*/

#include <stdbool.h>
#include <stdio.h>

bool elimination(const int* arr, size_t arr_size, int* result);

static void do_test(const int* arr,
                    size_t arr_size,
                    bool expected1,
                    int expected2) {
  int actual2;
  bool actual1 = elimination(arr, arr_size, &actual2);
  printf("Expected = %s, actual = %s\n", expected1 ? "true" : "false",
         actual1 ? "true" : "false");
  if (actual1) {
    printf("Expected = %d, actual = %d\n-> %s\n\n", expected2, actual2,
           expected2 == actual2 ? "OK" : "FAIL");
  } else
    printf("-> %s\n\n", expected1 == actual1 ? "OK" : "FAIL");
}

int main(void) {
  int arr1[] = {2, 5, 34, 1, 22, 1};
  do_test(arr1, sizeof(arr1) / sizeof(int), true, 1);
  int arr2[] = {2, 2, 34, 1, 22};
  do_test(arr2, sizeof(arr2) / sizeof(int), true, 2);
  int arr3[] = {2, 5, 34, 1, 22};
  do_test(arr3, sizeof(arr3) / sizeof(int), false, 0);
  return 0;
}
