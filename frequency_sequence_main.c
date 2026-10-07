/*
7 kyu
Frequency sequence
https://www.codewars.com/kata/585a033e3a36cdc50a00011c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* char_frequencies(const char* string, char separator);

static void do_test(const char* input, char separator, const char* expected) {
  char* const actual = char_frequencies(input, separator);
  printf(
      "For separator '%c' and string: \"%s\",\n"
      "expected: \"%s\", actual: \"%s\"\n-> %s\n\n",
      separator, input, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("", '-', "");
  do_test("hello world", '-', "1-1-3-3-2-1-1-2-1-3-1");
  do_test("19999999", ':', "1:7:7:7:7:7:7:7");
  do_test("^^^**$", 'x', "3x3x3x2x2x1");
  return 0;
}
