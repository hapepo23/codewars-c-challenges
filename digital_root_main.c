/*
6 kyu
Sum of Digits / Digital Root
https://www.codewars.com/kata/541c8630095125aba6000c00
*/

#include <stdio.h>

int digital_root(int n);

static void do_test(int n, int expected) {
  int actual = digital_root(n);
  printf("n = %d, expected = %d, actual = %d -> %s\n", n, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(16, 7);
  do_test(195, 6);
  do_test(992, 2);
  do_test(167346, 9);
  do_test(0, 0);
  return 0;
}
