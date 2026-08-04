/*
7 kyu
Make acronym
https://www.codewars.com/kata/57a60bad72292d3e93000a5a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_acronym(const char* words);

static void do_test(const char* input, const char* expected) {
  char* actual = to_acronym(input);
  printf("For string: \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", input,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("Code Wars", "CW");
  do_test("Water Closet", "WC");
  do_test("Portable Network Graphics", "PNG");
  do_test("PHP: Hypertext Preprocessor", "PHP");
  do_test("hyper text markup language", "HTML");
  return 0;
}
