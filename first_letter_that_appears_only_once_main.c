/*
7 kyu
All Star Code Challenge #16
https://www.codewars.com/kata/586566b773bd9cbe2b000013
*/

#include <stdio.h>

char no_repeat(const char* string);

static void do_test(const char* string, char expected) {
  char actual = no_repeat(string);
  printf("String = \"%s\", expected '%c', actual '%c' -> %s\n", string,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("e", 'e');
  do_test("aabbccdde", 'e');
  do_test("wxyz", 'w');
  do_test("testing", 'e');
  do_test("codewars", 'c');
  do_test("testing", 'e');
  return 0;
}
