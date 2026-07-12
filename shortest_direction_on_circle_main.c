/*
7 kyu
Shortest direction on circle
https://www.codewars.com/kata/686fd320adc800ab627089c2
*/

#include <stdio.h>

int shortest_direction(long long a, long long b);

static void do_test(long long a, long long b, int expected) {
  int actual = shortest_direction(a, b);
  printf(
      "a = %lld, b = %lld, submitted: %d, expected: %d -> %s\n", a, b, actual,
      expected,
      ((expected == 180 || expected == -180) ? (actual == 180 || actual == -180)
                                             : (actual == expected))
          ? "OK"
          : "FAIL");
}

int main(void) {
  do_test(0, 90, 90);
  do_test(90, 0, -90);
  do_test(180, -450, 90);
  do_test(90, 270, 180);
  do_test(90, 270, -180);
  do_test(600, -600, -120);
  do_test(700, -700, 40);
  do_test(25019997929835 * 360, -25019997929835 * 360, 0);
  do_test(25019997929835 * 360, -25019997929835 * 360 + 1, 1);
  return 0;
}
