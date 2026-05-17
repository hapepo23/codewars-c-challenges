/*
8 kyu
Area of a Square
https://www.codewars.com/kata/5748838ce2fab90b86001b1a
*/

#include <math.h>
#include <stdio.h>

double square_area(double arc);

static void doTest(double arc, double expected) {
  double actual = square_area(arc);
  printf("For arc = %.17g, expected = %.17g, actual = %.17g -> %s\n", arc,
         expected, actual, fabs(expected - actual) < 1e-9 ? "OK" : "FAIL");
}

int main(void) {
  doTest(2.00, 1.6211389382774046);
  doTest(0.00, 0.00);
  doTest(14.05, 80.00421981582636);
  doTest(1.00, 0.40528473456935116);
  doTest(100.00, 4052.8473456935108);
  return 0;
}
