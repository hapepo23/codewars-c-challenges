/*
7 kyu
Computing the entropy of a message
https://www.codewars.com/kata/6925ba5fcee28ebed6e18e7d
*/

#include <math.h>
#include <stdio.h>

double message_entropy(const char* message);

static void do_test(const char* input, double expected) {
  const double actual = message_entropy(input);
  printf("String = \"%s\", expected = %.8g, actual = %.8g -> %s\n", input,
         expected, actual, fabs(expected - actual) < 1e-6 ? "OK" : "FAIL");
}

int main(void) {
  do_test("hello world", 2.646439344);
  do_test("", 0.0);
  do_test("AAABAAC", 1.148834854);
  do_test("yyyyyy", 0);
  do_test("aA 123412?", 2.725480556);
  return 0;
}
