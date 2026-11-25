/*
6 kyu
Find the in-between point
https://www.codewars.com/kata/58a672d6426bf38be4000057
*/

#include <stdio.h>

unsigned middle_point(double x1,
                      double y1,
                      double z1,
                      double x2,
                      double y2,
                      double z2,
                      double x3,
                      double y3,
                      double z3);

static void do_test(double x1,
                    double y1,
                    double z1,
                    double x2,
                    double y2,
                    double z2,
                    double x3,
                    double y3,
                    double z3,
                    unsigned expected) {
  unsigned actual = middle_point(x1, y1, z1, x2, y2, z2, x3, y3, z3);
  printf(
      "x1 = %.17g; y1 = %.17g; z1 = %.17g\n"
      "x2 = %.17g; y2 = %.17g; z2 = %.17g\n"
      "x3 = %.17g; y3 = %.17g; z3 = %.17g\n"
      "expected %d, but got %d\n-> %s\n\n",
      x1, y1, z1, x2, y2, z2, x3, y3, z3, expected, actual,
      expected == actual ? "OK" : "FAIL");
}
int main(void) {
  do_test(1, 2, 3, 4, 5, 6, 7, 8, 9, 2);
  do_test(0, 2, 0, 6, -2, 8, 3, 0, 4, 3);
  do_test(1, 0, 4, 5, 0, 6, -7, 0, 0, 1);
  do_test(-1, 0, 2, -2, 4, -1, -3, 8, -4, 2);
  return 0;
}
