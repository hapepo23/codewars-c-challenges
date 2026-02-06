/*
6 kyu
Non-even substrings
https://www.codewars.com/kata/59da47fa27ee00a8b90000b4
*/

#include <stdio.h>

size_t solve(const char* s);

static void do_test(const char* s, size_t expected) {
  size_t submitted = solve(s);
  printf("String   : \"%s\"\nSubmitted: %zu\nExpected : %zu\n%s\n\n", s,
         submitted, expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("1347", 7);
  do_test("1357", 10);
  do_test("13471", 12);
  do_test("134721", 13);
  do_test("1347231", 20);
  do_test("13472315", 28);
  return 0;
}
