/*
8 kyu
Convert a Boolean to a String
https://www.codewars.com/kata/551b4501ac0447318f0009cd
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char* boolean_to_string(bool b);

static void do_test(bool b, const char* expected) {
  const char* actual = boolean_to_string(b);
  printf("Expected: \"%s\", actual: \"%s\" -> %s\n", expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(true, "true");
  do_test(false, "false");
  return 0;
}
