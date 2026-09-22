/*
8 kyu
Switch it Up!
https://www.codewars.com/kata/5808dcb8f0ed42ae34000031
*/

#include <stdio.h>
#include <string.h>

const char* switchItUp(int digit);

static void test(int digit, const char* expected) {
  const char* actual = switchItUp(digit);
  printf("Digit = %d, expected = \"%s\", actual = \"%s\" -> %s\n", digit,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  test(1, "One");
  test(3, "Three");
  test(5, "Five");
  return 0;
}
