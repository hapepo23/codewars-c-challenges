/*
6 kyu
Plus or Minus
https://www.codewars.com/kata/65f8279c265f42003ffbd931
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double (*TestFunction)(size_t n, const double values[n]);

void determine_signs(char* expression,
                     const char* variables,
                     TestFunction test);

static bool called;
static const char* expression;

static double test(size_t n, const double values[n]) {
  if (called)
    printf("You can only call test() once per test case\n-> FAIL\n\n");
  called = true;
  size_t n_variables = (strlen(expression) + 1) / 2;
  if (n != n_variables)
    printf(
        "There are %zu variables, but you called test() with %zu values\n-> "
        "FAIL\n\n",
        n_variables, n);
  double result = 0;
  int sign_idx = (expression[0] == '-') ? 0 : -1;
  for (size_t i = 0; i < n; i++, sign_idx += 2) {
    double sign =
        ((i == 0 && expression[0] != '-') || (expression[sign_idx] == '+'))
            ? +1
            : -1;
    result += sign * values[i];
  }
  return result;
}

static void do_test(const char* variables, const char* expected) {
  called = false;
  expression = expected;
  size_t mem_size = 2 * strlen(variables) + 1;
  char* actual = memset(malloc(mem_size), '@', mem_size);
  determine_signs(actual, variables, test);
  printf(
      "Variables = \"%s\"\nexpected  = \"%s\"\nactual    = \"%s\"\n-> %s\n\n",
      variables, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("a", "a");
  do_test("a", "-a");
  do_test("pq", "p+q");
  do_test("pq", "p-q");
  do_test("pq", "-p-q");
  do_test("pq", "-p+q");
  do_test("xyz", "x-y+z");
  do_test("dbcw", "-d-b-c+w");
  do_test("codewars", "c-o-d-e+w-a-r-s");
  do_test("abcdefghijklmnopqrstuvwxyz",
          "a-b+c+d-e+f-g+h-i-j-k-l+m-n+o+p+q-r-s+t-u-v+w+x+y-z");
  return 0;
}
