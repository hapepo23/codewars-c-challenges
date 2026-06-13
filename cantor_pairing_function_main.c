/*
6 kyu
Cantor's pairing function
https://www.codewars.com/kata/543b9113def6343e43000875
*/

#include <stdio.h>
#include <string.h>

void cantor_pairing_function(char* output, unsigned n);

static void do_test(unsigned n, const char* expected) {
  char actual[64];
  memset(actual, '@', sizeof(actual));
  cantor_pairing_function(actual, n);
  printf("n = %u, expected = \"%s\", actual = \"%s\" -> %s\n", n, expected,
         actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(1, "1/1");
  do_test(2, "1/2");
  do_test(3, "2/1");
  do_test(4, "3/1");
  do_test(5, "2/2");
  do_test(6, "1/3");
  do_test(7, "1/4");
  do_test(16, "1/6");
  do_test(21, "6/1");
  do_test(22, "7/1");
  do_test(28, "1/7");
  do_test(268435455, "22590/581");
  return 0;
}
