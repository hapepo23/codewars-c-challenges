/*
6 kyu
Give me a Diamond
https://www.codewars.com/kata/5503013e34137eeeaa001648
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* diamond(int n);

static void do_test(int n, const char* expected) {
  char* actual = diamond(n);
  printf("For n = %d\n", n);
  if (actual == NULL) {
    if (expected == NULL)
      printf("-> OK\n\n");
    else
      printf("-> FAIL\n\n");
  } else if (expected) {
    printf("expected:\n%s\nactual:\n%s\n", expected, actual);
    if (strcmp(actual, expected) == 0)
      printf("-> OK\n\n");
    else
      printf("-> FAIL\n\n");
  } else
    printf("-> FAIL\n\n");
  if (actual)
    free(actual);
}

int main(void) {
  do_test(1, "*\n");
  do_test(3,
          " *"
          "\n"
          "***"
          "\n"
          " *"
          "\n");
  do_test(5,
          "  *"
          "\n"
          " ***"
          "\n"
          "*****"
          "\n"
          " ***"
          "\n"
          "  *"
          "\n");
  do_test(7,
          "   *"
          "\n"
          "  ***"
          "\n"
          " *****"
          "\n"
          "*******"
          "\n"
          " *****"
          "\n"
          "  ***"
          "\n"
          "   *"
          "\n");
  do_test(2, NULL);
  do_test(-3, NULL);
  do_test(0, NULL);
  return 0;
}
