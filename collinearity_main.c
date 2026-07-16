/*
8 kyu
Collinearity
https://www.codewars.com/kata/65ba420888906c1f86e1e680
*/

#include <stdbool.h>
#include <stdio.h>

bool collinearity(int x1, int y1, int x2, int y2);

static void do_test(int x1, int y1, int x2, int y2, bool expected) {
  bool actual = collinearity(x1, y1, x2, y2);
  const char* bs[2] = {"false", "true"};
  printf(
      "x1 = %d, y1 = %d, x2 = %d, y2 = %d\nactual: %s, expected: %s -> %s\n\n",
      x1, y1, x2, y2, bs[actual], bs[expected],
      actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(1, 1, 1, 1, true);
  do_test(1, 2, 2, 4, true);
  do_test(1, 1, 6, 1, false);
  do_test(1, 2, -1, -2, true);
  do_test(1, 2, 1, -2, false);
  do_test(4, 0, 11, 0, true);
  do_test(0, 1, 6, 0, false);
  do_test(4, 4, 0, 4, false);
  do_test(0, 0, 0, 0, true);
  do_test(0, 0, 1, 0, true);
  do_test(0, 7, 0, 0, true);
  return 0;
}
