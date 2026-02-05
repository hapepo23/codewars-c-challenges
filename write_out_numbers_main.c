/*
5 kyu
Write out numbers
https://www.codewars.com/kata/52724507b149fa120600031d
*/

#include <stdio.h>
#include <string.h>

char* number_to_words(unsigned n, char* num_string);

static void do_test(unsigned n, const char* expected) {
  char user_string[128];
  memset(user_string, '@', sizeof user_string);
  char* actual = number_to_words(n, user_string);
  printf("for n = %u\nexpected: \"%s\"\nactual  : \"%s\"\n%s\n\n", n, expected,
         actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(0, "zero");
  do_test(1, "one");
  do_test(10, "ten");
  do_test(19, "nineteen");
  do_test(22, "twenty-two");
  do_test(50, "fifty");
  do_test(793, "seven hundred ninety-three");
  do_test(800, "eight hundred");
  do_test(1000, "one thousand");
  do_test(1003, "one thousand three");
  do_test(3052, "three thousand fifty-two");
  do_test(100000, "one hundred thousand");
  do_test(99997, "ninety-nine thousand nine hundred ninety-seven");
  do_test(500001, "five hundred thousand one");
  do_test(888887,
          "eight hundred eighty-eight thousand eight hundred eighty-seven");
  return 0;
}
