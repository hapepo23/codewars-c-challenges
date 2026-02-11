/*
6 kyu
Build Tower
https://www.codewars.com/kata/576757b1df89ecf5bd00073b
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_tower(unsigned n, char tower[n][2 * n - 1]);

static char* stringify_tower(unsigned n, const char tower[n][2 * n - 1]) {
  if (n == 0)
    return calloc(1, 1);
  char *string = malloc(1 + n * (2 * n - 1 + 3)), *ptr = string;
  for (unsigned i = 0; i < n; i++)
    ptr += sprintf(ptr, "\"%.*s\"\n", 2 * n - 1, tower[i]);
  return string;
}

static void do_test(unsigned n, const char expected[n][2 * n - 1]) {
  char(*actual)[n][2 * n - 1] = malloc(sizeof *actual);
  memset(*actual, '@', sizeof *actual);
  build_tower(n, *actual);
  char* act_str = stringify_tower(n, *actual);
  char* exp_str = stringify_tower(n, expected);
  printf("for n = %u, expected:\n%sbut got:\n%s%s\n\n", n, exp_str, act_str,
         strcmp(exp_str, act_str) == 0 ? "OK" : "FAIL");
  free(actual);
  free(exp_str);
  free(act_str);
}

int main(void) {
  do_test(6, (char[6][11]){"     *     ", "    ***    ", "   *****   ",
                           "  *******  ", " ********* ", "***********"});
  do_test(1, (char[1][1]){"*"});
  do_test(2, (char[2][3]){" * ", "***"});
  do_test(3, (char[3][5]){"  *  ", " *** ", "*****"});
  return 0;
}
