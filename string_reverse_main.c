/*
8 kyu
Reversed Strings
https://www.codewars.com/kata/5168bb5dfe9a00b126000018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strrev(char* string);

static char* strdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

static void do_test(const char* input, const char* expected) {
  char* user_string = strdup(input);
  char* actual = strrev(user_string);
  printf("for string: \"%s\"\n", input);
  if (actual != user_string)
    puts("FAIL - you must return the given string\n");
  else
    printf("expected  : \"%s\"\nactual    : \"%s\"\n%s\n\n", expected, actual,
           strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test("world", "dlrow");
  do_test("Codewars is a great website", "etisbew taerg a si srawedoC");
  do_test("word", "drow");
  do_test("", "");
  do_test("$", "$");
  do_test("kayak", "kayak");
}
