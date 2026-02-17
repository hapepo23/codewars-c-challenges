/*
7 kyu
String ends with?
https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool solution(const char* string, const char* ending);

static void do_test(const char* string, const char* ending, bool expected) {
  bool actual = solution(string, ending);
  printf("String = \"%s\", ending = \"%s\", expected = %s, actual = %s -> %s\n",
         string, ending, expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("abc", "bc", true);
  do_test("abc", "d", false);
  do_test("abc", "", true);
}
