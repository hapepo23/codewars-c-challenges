/*
6 kyu
The area between the vertex of the parabola and x-axis
https://www.codewars.com/kata/63ecc21e12797b06519ad94f
*/

#include <math.h>
#include <stdio.h>

double area(double a, double b, double c);

static void dotest(double a, double b, double c, double expected) {
  const double actual = area(a, b, c);
  printf(
      "a = %.10g, b = %.10g, c = %.10g, expected = %.10g,"
      " actual = %.10g -> %s\n",
      a, b, c, expected, actual,
      fabs(expected - actual) < 1e-5 ? "OK" : "FAIL");
}

int main(void) {
  dotest(3, 10, 20, 0);                                 // D<0
  dotest(1, -10, 25, 0);                                // D=0
  dotest(3, -42, 144, 4);                               // D>0
  dotest(1, -10, 21, 10.666667);                        // D>0
  dotest(12.225867, 54.249312, -293.764, 2539.217339);  // D>0
  dotest(256, 2023, -3879, 58243.180912);               // D>0
  dotest(4000, 4000, -4000, 7453.559925);               // D>0
  return 0;
}
