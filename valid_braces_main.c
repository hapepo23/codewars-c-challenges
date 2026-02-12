/*
6 kyu
Valid Braces
https://www.codewars.com/kata/5277c8a221e209d3f6000b56
*/

#include <stdbool.h>
#include <stdio.h>

bool valid_braces(const char* braces);

static void do_test(const char* braces, const bool expected) {
  const bool actual = valid_braces(braces);
  printf("Input: \"%s\", expected: %s, actual: %s -> %s\n", braces,
         expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("(((", false);
  do_test(")))", false);
  do_test("(){}[]", true);
  do_test("([{}])", true);
  do_test("(}", false);
  do_test("[(])", false);
  do_test("[({})](]", false);
  return 0;
}
