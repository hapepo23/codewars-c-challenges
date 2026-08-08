/*
7 kyu
Find the stray number
https://www.codewars.com/kata/57f609022f4d534f05000024
*/

#include <stdio.h>

int stray(size_t n, const int arr[n]);

static void do_test(size_t n, const int arr[n], int expected) {
  int actual = stray(n, arr);
  printf("Actual: %d, expected: %d -> %s\n", actual, expected,
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    int example[3] = {1, 0, 0};
    do_test(3, example, 1);
  }
  {
    int example[5] = {1, 1, 2, 1, 1};
    do_test(5, example, 2);
  }
  {
    int example[7] = {2, 2, 2, 2, 2, 2, 3};
    do_test(7, example, 3);
  }
  return 0;
}
