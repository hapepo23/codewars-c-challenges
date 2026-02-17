/*
7 kyu
Binary Addition
https://www.codewars.com/kata/551f37452ff852b7bd000139
*/

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

char* binary_add(unsigned a, unsigned b, char* binary);

static void do_test(unsigned a, unsigned b, const char* expected) {
  char user_string[128];
  memset(user_string, '@', sizeof user_string);
  char* actual = binary_add(a, b, user_string);
  printf("For %u + %u, expected: \"%s\", actual: \"%s\" -> %s\n", a, b,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(1, 2, "11");
  do_test(51, 12, "111111");
  do_test(100, 0, "1100100");
  do_test(0, 0, "0");
  do_test(UINT_MAX, UINT_MAX, "111111111111111111111111111111110");
  return 0;
}
