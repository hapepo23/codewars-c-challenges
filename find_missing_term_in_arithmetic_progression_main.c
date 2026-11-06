/*
6 kyu
Find the missing term in an Arithmetic Progression
https://www.codewars.com/kata/52de553ebb55d1fca3000371
*/

#include <stdio.h>

int find_missing(const int* nums, size_t n);

static void do_test(const int* nums, size_t n, int expected) {
  int actual = find_missing(nums, n);
  printf("Actual = %d, expected: %d -> %s\n", actual, expected,
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test((const int[]){1, 3, 5, 9, 11}, 5, 7);
  do_test((const int[]){-11, -9, -7, -3, -1}, 5, -5);
  do_test((const int[]){1, 1, 1}, 3, 1);
  return 0;
}
