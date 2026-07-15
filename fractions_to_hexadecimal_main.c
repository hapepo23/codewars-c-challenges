/*
6 kyu
Fractions To Hexadecimal
https://www.codewars.com/kata/6a3c22c2d5761bf8d86987e2
*/

#include <stdio.h>
#include <string.h>

void f2hex(const char* fraction, char* hexadecimal);

static void do_test(const char* fraction, const char* expected) {
  char actual[50] = "???";
  f2hex(fraction, actual);
  printf(
      "Fraction  = \"%s\"\n"
      "Actual    = \"%s\"\n"
      "Expected  = \"%s\"\n"
      "-> %s\n\n",
      fraction, actual, expected,
      strcmp(actual, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("0/99", "0");
  do_test("3/3", "1");
  do_test("998/999", "0.ffbe65");
  do_test("1/16777216", "0.000001");
  do_test("249/18", "d.d55555");
  do_test("13/101", "0.20f353");
  do_test("32/2", "10");
  do_test("13723/1706", "8.0b412");
  return 0;
}
