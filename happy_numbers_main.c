/*
6 kyu
Happy numbers
https://www.codewars.com/kata/5464cbfb1e0c08e9b3000b3e
*/

#include <stdbool.h>
#include <stdio.h>

bool is_happy(unsigned n);

static void tester(unsigned n, bool expected) {
  bool submitted = is_happy(n);
  const char* ft[2] = {"false", "true"};
  printf("n = %u, actual = %s, expected = %s -> %s\n", n, ft[submitted],
         ft[expected], submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  tester(1, true);
  tester(7, true);
  tester(16, false);
  tester(64, false);
  tester(145, false);
  return 0;
}
