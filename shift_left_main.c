/*
7 kyu
Shift Left
https://www.codewars.com/kata/5bdc191306a8a678f6000187
*/

#include <stdio.h>

size_t shift_left(const char* a, const char* b);

static void tester(const char* a, const char* b, size_t expected) {
  size_t submitted = shift_left(a, b);
  printf(
      "a        = \"%s\"\nb        = \"%s\"\nExpected = %zu\nActual   = "
      "%zu\n-> %s\n\n",
      a, b, expected, submitted, expected == submitted ? "OK" : "FAIL");
}

int main(void) {
  tester("test", "west", 2);
  tester("test", "yes", 7);
  tester("b", "ab", 1);
  return 0;
}
