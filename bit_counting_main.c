/*
6 kyu
Bit Counting
https://www.codewars.com/kata/526571aae218b8ee490006f4
*/

#include <limits.h>
#include <stddef.h>
#include <stdio.h>

size_t countBits(unsigned value);

static void do_test(unsigned input, size_t expected) {
  size_t actual = countBits(input);
  printf("For n = %u, expected %ld, actual %ld -> %s\n", input, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(0, 0);
  do_test(4, 1);
  do_test(7, 3);
  do_test(9, 2);
  do_test(10, 2);
  do_test(26, 3);
  do_test(77231418, 14);
  do_test(12525589, 11);
  do_test(3811, 8);
  do_test(392902058, 17);
  do_test(UINT_MAX, 32);
  return 0;
}
