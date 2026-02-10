/*
7 kyu
Is this a triangle?
https://www.codewars.com/kata/56606694ec01347ce800001b
*/

#include <stdbool.h>
#include <stdio.h>

bool is_triangle(int a, int b, int c);

static void do_test(int a, int b, int c, bool expected) {
  bool actual = is_triangle(a, b, c);
  printf("For a = %d, b = %d, c = %d: expected %s, actual %s -> %s\n", a, b, c,
         expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(1, 2, 2, true);
  do_test(3, 3, 3, true);
  do_test(3, 4, 5, true);
  do_test(7, 2, 2, false);
  do_test(10, 100, 1000, false);
  do_test(2, 2, 4, false);
  do_test(1, 3, 7, false);
  do_test(1, 7, 3, false);
  do_test(3, 1, 7, false);
  do_test(3, 7, 1, false);
  do_test(7, 1, 3, false);
  do_test(7, 3, 1, false);
  do_test(3, 3, 0, false);
  do_test(0, 0, 0, false);
  do_test(-3, -4, -5, false);
  return 0;
}
