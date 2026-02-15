/*
5 kyu
Value of x
https://www.codewars.com/kata/614ac445f13ead000f91b4d0
*/

#include <stdio.h>

int solve(const char* equation);

static void do_test(const char* equation, int expected) {
  int actual = solve(equation);
  printf("Equation: \"%s\", expected x = %d, actual x = %d -> %s\n", equation,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("x + 1 = 9 - 2", 6);
  do_test("x - 2 + 3 = 2", 1);
  do_test("x = + 2 - 5 + 9", 6);
  do_test("- 10 = x", -10);
  do_test("- x = - 1", 1);
  do_test("x - 0 + 0 = 0", 0);
  return 0;
}
