/*
5 kyu
First non-repeating character
https://www.codewars.com/kata/52bc74d4ac05d0945d00054e
*/

#include <stdio.h>
#include <string.h>

void first_non_repeating_codepoint(char output[5], const char* utf8);

static void do_test(const char* input, const char* expected) {
  char actual[5] = "@@@@@";
  first_non_repeating_codepoint(actual, input);
  printf("Input = u8\"%s\", expected = u8\"%s\", actual = u8\"%s\" -> %s\n",
         input, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("stress", "t");
  do_test("sTreSS", "T");
  do_test("moonmen", "e");
  do_test("a", "a");
  do_test("A", "A");
  do_test("aa", "");
  do_test("aA", "");
  do_test("aaA", "");
  do_test("", "");
  do_test("abA", "b");
  do_test("abcCBA", "");
  do_test("abcdCBA", "d");
  do_test(u8"🐐🦊🐐", u8"🦊");
  do_test(u8"🦊🦊", u8"");
  do_test(u8"かか何", u8"何");
  do_test(u8"重!㐷♠㐷©♠∏∏!重©", u8"");
  do_test(u8"∞§ﬁ›ﬂ∞§", u8"ﬁ");
  return 0;
}
