/*
6 kyu
Derivatives of type x^n
https://www.codewars.com/kata/55e2de13b668981d3300003d
*/

#include <stdio.h>
#include <string.h>

char* differentiate(char* derivative, const char* function);

static void do_test(const char* input, const char* expected) {
  enum { STR_SIZE = 128 };
  char user_string[STR_SIZE];
  memset(user_string, STR_SIZE, '@');
  char* actual = differentiate(user_string, input);
  printf("For function: \"%s\" ... expected: \"%s\", actual: \"%s\" -> %s\n",
         input, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("3x^2", "6x");
  do_test("-5x^3", "-15x^2");
  do_test("6x^-2", "-12x^-3");
  do_test("-x", "-1");
  do_test("42", "0");
  do_test("x^-114", "-114x^-115");
  do_test("x", "1");
  return 0;
}
