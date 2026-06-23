/*
6 kyu
Break camelCase
https://www.codewars.com/kata/5208f99aee097e6552000148
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* camelCase);

static void do_test(const char* input, const char* expected) {
  char* result = solution(input);
  printf("Input: \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", input,
         expected, result, strcmp(expected, result) == 0 ? "OK" : "FAIL");
  free(result);
}

int main(void) {
  do_test("camelCase", "camel Case");
  do_test("thisIsAVeryLongIdentifierName",
          "this Is A Very Long Identifier Name");
  do_test("unshift", "unshift");
  do_test("ABC", "A B C");
  do_test("", "");
  return 0;
}
