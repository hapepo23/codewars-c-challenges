/*
6 kyu
Missing Angle
https://www.codewars.com/kata/58417e9ab9c25c774500001f
*/

#include <math.h>
#include <stdio.h>

double missingAngle(double, double, double);

static void do_test(double h, double a, double o, double expected) {
  double actual = missingAngle(h, a, o);
  printf(
      "h = %.9g; a = %.9g; o = %.9g\n"
      "expected = %.9g; actual = %.9g -> %s\n\n",
      h, a, o, expected, actual,
      fabs(expected - actual) < 1e-3 ? "OK" : "FAIL");
}

int main(void) {
  do_test(0, 400, 300, 36.86989764584402);
  do_test(5, 4, 0, 36.869897645844013);
  do_test(8, 0, 5, 38.682187453489441);
  return 0;
}
