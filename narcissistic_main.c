/*
6 kyu
Does my number look big in this?
https://www.codewars.com/kata/5287e858c6b5a9678200083c
*/

#include <stdbool.h>
#include <stdio.h>

bool narcissistic(int num);

static void do_test(int num, bool expected) {
  bool actual = narcissistic(num);
  printf("n = %d, expected = %s, actual = %s -> %s\n", num,
         expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(7, true);
  do_test(371, true);
  do_test(122, false);
  do_test(4887, false);
  do_test(2147483647, false);
  return 0;
}
