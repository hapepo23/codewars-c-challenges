/*
5 kyu
Calculate the derivative of a polynomial
https://www.codewars.com/kata/56d060d90f9408fb3b000b03
*/

#include <stdio.h>
#include <string.h>

void sprint_derivative(char derivative[4096], const char* polynomial);

static void do_test(const char* input, const char* expected) {
  char actual[4096];
  memset(actual, '@', sizeof actual);
  sprint_derivative(actual, input);

  printf("Input    = \"%s\"\nExpected = \"%s\"\nActual   = \"%s\"\n-> %s\n\n",
         input, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("-100", "0");
  do_test("4x+1", "4");
  do_test("x^5-x", "5x^4-1");
  do_test("-x^2+3x+4", "-2x+3");
  do_test("x+2", "1");
  return 0;
}
