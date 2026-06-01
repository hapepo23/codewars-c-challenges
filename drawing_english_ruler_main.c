/*
6 kyu
Drawing English Ruler
https://www.codewars.com/kata/696fe8b06b4e2e6ddb50caa8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* draw_ruler(int t, int n);

static void do_test(int t, int n, const char* expected) {
  char* actual = draw_ruler(t, n);
  printf(
      "Major tick length t = %d, Number of inches on the ruler n = %d\n"
      "Expected:\n%s\nActual:\n%s\n-> %s\n\n",
      t, n, expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test(2, 4, "-- 0\n-\n-- 1\n-\n-- 2\n-\n-- 3\n-\n-- 4");
  do_test(3, 3, "--- 0\n-\n--\n-\n--- 1\n-\n--\n-\n--- 2\n-\n--\n-\n--- 3");
  do_test(4, 2,
          "---- 0\n-\n--\n-\n---\n-\n--\n-\n---- "
          "1\n-\n--\n-\n---\n-\n--\n-\n---- 2");
  do_test(5, 1,
          "----- "
          "0\n-\n--\n-\n---\n-\n--\n-\n----\n-\n--\n-\n---\n-\n--\n-\n----- 1");
  return 0;
}
