/*
7 kyu
Triangle area
https://www.codewars.com/kata/59bd84b8a0640e7c49002398
*/

#include <math.h>
#include <stdio.h>

double triangle_area(const char* triangle_string);

static void do_test(double expected, const char* triangle) {
  static const double EPSILON = 1e-9;
  double actual = triangle_area(triangle);
  printf("Expected: %.17g, actual: %.17g, for triangle:\n%s-> %s\n\n", expected,
         actual, triangle, fabs(expected - actual) < EPSILON ? "OK" : "FAIL");
}

int main(void) {
  do_test(0.5,
          ""
          "\n"
          "."
          "\n"
          ". ."
          "\n");
  do_test(2.0,
          ""
          "\n"
          "."
          "\n"
          ". ."
          "\n"
          ". . ."
          "\n");
  do_test(4.5,
          ""
          "\n"
          "."
          "\n"
          ". ."
          "\n"
          ". . ."
          "\n"
          ". . . ."
          "\n");
  do_test(8,
          ""
          "\n"
          "."
          "\n"
          ". ."
          "\n"
          ". . ."
          "\n"
          ". . . ."
          "\n"
          ". . . . ."
          "\n");
  do_test(12.5,
          ""
          "\n"
          "."
          "\n"
          ". ."
          "\n"
          ". . ."
          "\n"
          ". . . ."
          "\n"
          ". . . . ."
          "\n"
          ". . . . . ."
          "\n");
  return 0;
}
