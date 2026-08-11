/*
6 kyu
Encrypt this!
https://www.codewars.com/kata/5848565e273af816fb000449
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt_this(const char* str);

static void do_test(const char* str, const char* expected) {
  char* actual = encrypt_this(str);
  printf("Input    = \"%s\"\nExpected = \"%s\"\nActual   = \"%s\"\n-> %s\n\n",
         str, expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("", "");
  do_test("A", "65");
  do_test("Ab", "65b");
  do_test("Abcd", "65dcb");
  do_test("  Abcd   Abcd", "65dcb 65dcb");
  do_test("Abcd Aahhhhhhhhhhhhhhhhz", "65dcb 65zhhhhhhhhhhhhhhhha");
  do_test(" Hello world ", "72olle 119drlo");
  return 0;
}
