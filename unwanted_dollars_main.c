/*
6 kyu
Unwanted dollars
https://www.codewars.com/kata/587309155cfd6b9fb60000a0
*/

#include <math.h>
#include <stdio.h>

double money_value(const char* s);

static void do_test(const char* input, double expected) {
  double error_tolerance = 1e-9;
  double actual = money_value(input);
  printf(
      "Input    = \"%s\"\n"
      "Expected = %.17g\n"
      "Actual   = %.17g (error is %.17g)\n"
      "-> %s\n\n",
      input, expected, actual, fabs(actual - expected),
      fabs(actual - expected) < error_tolerance ? "OK" : "FAIL");
}

int main(void) {
  do_test("12.34", 12.34);
  do_test(" $5.67", 5.67);
  do_test("-0.89", -0.89);
  do_test("-$ 0.1", -0.10);
  do_test("$-2.3456", -2.3456);
  do_test("007", 7.00);
  do_test(" $ 89", 89.0);
  do_test("   .11", 0.11);
  do_test("$.2", 0.20);
  do_test("-.34", -0.34);
  do_test("$$$", 0.0);
  return 0;
}
