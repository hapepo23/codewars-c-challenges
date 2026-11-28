/*
7 kyu
Move 10
https://www.codewars.com/kata/57cf50a7eca2603de0000090
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveTen(char* str);

static void doTest(const char* input, const char* expected) {
  extern char* strdup(const char*);
  char* const actual = strdup(input);
  moveTen(actual);
  printf("Input = \"%s\", expected = \"%s\", actual = \"%s\" -> %s\n", input,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  doTest("testcase", "docdmkco");
  doTest("codewars", "mynogkbc");
  doTest("exampletesthere", "ohkwzvodocdrobo");
  return 0;
}
