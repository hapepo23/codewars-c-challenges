/*
7 kyu
Reverse words
https://www.codewars.com/kata/5259b20d6021e9e14c0010d4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(const char* text);

static void do_test(const char* text, const char* expected) {
  char* actual = reverseWords(text);
  printf("Text = \"%s\", expected = \"%s\", actual = \"%s\" -> %s\n", text,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("The quick brown fox jumps over the lazy dog.",
          "ehT kciuq nworb xof spmuj revo eht yzal .god");
  do_test("apple", "elppa");
  do_test("a b c d", "a b c d");
  do_test("  double  spaced  words  ", "  elbuod  decaps  sdrow  ");
  do_test("  ", "  ");
  do_test("  du", "  ud");
  do_test("du  ", "ud  ");
  do_test("", "");
  return 0;
}
