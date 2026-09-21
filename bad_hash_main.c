/*
7 kyu
BAD Hash - String to Int
https://www.codewars.com/kata/596d93bd9b6a5df4de000049
*/

#include <stdio.h>

int hash(const char* str);

static void test(const char* str, int expected) {
  int actual = hash(str);
  printf("String = \"%s\", expected = %d, actual = %d -> %s\n", str, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  test("a", 64);
  test("ca", -820);
  test("Hi", 16);
  test(" Yo - What's Good?! ", 460);
  return 0;
}
