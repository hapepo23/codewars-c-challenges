/*
7 kyu
Simple string reversal II
https://www.codewars.com/kata/5a8d1c82373c2e099d0000ac
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_between(char* string, size_t a, size_t b);

static void do_test(const char* string,
                    size_t a,
                    size_t b,
                    const char* expected) {
  char* user_string = strcpy(malloc(strlen(string) + 1), string);
  char* actual = reverse_between(user_string, a, b);
  printf(
      "String   = \"%s\"\n"
      "a        = %zu\n"
      "b        = %zu\n"
      "expected = \"%s\"\n"
      "actual   = \"%s\"\n"
      "-> %s\n\n",
      string, a, b, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test("codewars", 1, 5, "cawedors");
  do_test("codingIsFun", 2, 100, "conuFsIgnid");
  do_test("FunctionalProgramming", 2, 15, "FuargorPlanoitcnmming");
  do_test("abcdefghijklmnopqrstuvwxyz", 0, 20, "utsrqponmlkjihgfedcbavwxyz");
  do_test("abcdefghijklmnopqrstuvwxyz", 5, 20, "abcdeutsrqponmlkjihgfvwxyz");
  return 0;
}
