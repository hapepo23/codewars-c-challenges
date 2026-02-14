/*
6 kyu
CamelCase Method
https://www.codewars.com/kata/587731fda577b3d1b0001196
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* camel_case(const char* s);

static void do_test(const char* s, const char* expected) {
  char* actual = camel_case(s);
  printf("String: \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", s,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("test case", "TestCase");
  do_test("camel case method", "CamelCaseMethod");
  do_test("say hello ", "SayHello");
  do_test(" camel case word", "CamelCaseWord");
  do_test("", "");
  return 0;
}
