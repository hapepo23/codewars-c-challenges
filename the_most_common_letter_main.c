/*
6 kyu
The most common letter
https://www.codewars.com/kata/5a434a9dc5e284724f000011
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_most_common(char* string, char letter);

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

static void do_test(const char* input, char letter, const char* expected) {
  char* actual = xstrdup(input);
  replace_most_common(actual, letter);
  printf(
      "Letter = '%c', input = \"%s\", expected = \"%s\", actual = \"%s\" -> "
      "%s\n",
      letter, input, expected, actual,
      strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("aaa aaa", 't', "ttt ttt");
  do_test("my mom loves me as never did", 't', "ty tot loves te as never did");
  do_test("real talk bro", 'n', "neal talk bno");
  do_test("great job go ahead", 'k', "grekt job go khekd");
  do_test("yyyaaa twwww ttt uuu ccca", 'p', "yyyppp twwww ttt uuu cccp");
  return 0;
}
