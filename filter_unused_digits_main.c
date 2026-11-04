/*
7 kyu
Filter unused digits
https://www.codewars.com/kata/55de6173a8fbe814ee000061
*/

#include <stdio.h>
#include <string.h>

char* unused_digits(char unused[10 + 1], ...);

#define fixed_test(expected, ...)                                             \
  do_test(                                                                    \
      unused_digits((char[10 + 1]){'@', '@', '@', '@', '@', '@', '@', '@',    \
                                   '@', '@', '@'} __VA_OPT__(, ) __VA_ARGS__, \
                    -1),                                                      \
      expected, #__VA_ARGS__)

static void do_test(const char* actual,
                    const char* expected,
                    const char* args_string) {
  printf("Expected \"%s\", but got \"%s\" for arguments:\n(%s)\n-> %s\n\n",
         expected, actual, args_string,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  fixed_test("123456789", 0);
  fixed_test("09", 12, 34, 56, 78);
  fixed_test("3479", 2015, 8, 26);
  fixed_test("013489", 276, 575);
  fixed_test("0125789", 643);
  fixed_test("01235", 864, 896, 744);
  fixed_test("289", 364, 500, 715, 730);
  fixed_test("25678", 93, 10, 11, 40);
  fixed_test("289", 364, 500, 715, 730);
  fixed_test("25678", 93, 10, 11, 40);
  fixed_test("023456789", 1, 11, 111, 1111);
  fixed_test("", 9, 87, 654, 3210);
  fixed_test("0123456789");
  fixed_test("", 1234567890);
  return 0;
}
