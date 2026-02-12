/*
6 kyu
Write Number in Expanded Form
https://www.codewars.com/kata/5842df8ccbd22792a4000245
*/

#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

char* expandedForm(char string[512], ull n);

static void doTest(unsigned long long n, const char* expected) {
  char user_string[512];
  memset(user_string, '@', sizeof user_string);
  char* actual = expandedForm(user_string, n);
  printf("For n = %llu ...\nexpected: \"%s\"\nactual  : \"%s\"\n%s\n\n", n,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  doTest(12, "10 + 2");
  doTest(42, "40 + 2");
  doTest(70304, "70000 + 300 + 4");
  doTest(
      11111111111111111111ull,
      "10000000000000000000 + 1000000000000000000 + 100000000000000000 + "
      "10000000000000000 + 1000000000000000 + 100000000000000 + 10000000000000 "
      "+ 1000000000000 + 100000000000 + 10000000000 + 1000000000 + 100000000 + "
      "10000000 + 1000000 + 100000 + 10000 + 1000 + 100 + 10 + 1");
  return 0;
}
