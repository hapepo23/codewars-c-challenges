/*
6 kyu
WeIrD StRiNg CaSe
https://www.codewars.com/kata/52b757663a95b11b3d00062d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_weird_case(char* string);

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

static void do_test(const char* input, const char* expected) {
  char* user_string = xstrdup(input);
  char* actual = to_weird_case(user_string);
  printf("For string \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", input,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test("String", "StRiNg");
  do_test("Weird string case", "WeIrD StRiNg CaSe");
  do_test("", "");
  do_test("a aa aaa aaaa", "A Aa AaA AaAa");
  do_test("A AA AAA AAAA", "A Aa AaA AaAa");
  do_test("A Aa AaA AaAa", "A Aa AaA AaAa");
  do_test("a aA aAa aAaA", "A Aa AaA AaAa");
  return 0;
}
