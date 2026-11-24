/*
7 kyu
You Got Change?
https://www.codewars.com/kata/5966f6343c0702d1dc00004c
*/

#include <stdio.h>

void give_change(unsigned amount, unsigned bills[6]);

static void do_test(unsigned amount, const unsigned expected[6]) {
  unsigned bills[6] = {666, 666, 666, 666, 666, 666};
  give_change(amount, bills);
  printf(
      "For amount = %u:\nexpected = { %u, %u, %u, %u, %u, %u }\n"
      "actual   = { %u, %u, %u, %u, %u, %u }\n-> %s\n\n",
      amount, expected[0], expected[1], expected[2], expected[3], expected[4],
      expected[5], bills[0], bills[1], bills[2], bills[3], bills[4], bills[5],
      expected[0] == bills[0] && expected[1] == bills[1] &&
              expected[2] == bills[2] && expected[3] == bills[3] &&
              expected[4] == bills[4] && expected[5] == bills[5]
          ? "OK"
          : "FAIL");
}

int main(void) {
  do_test(365, ((unsigned[6]){0, 1, 1, 0, 1, 3}));
  do_test(217, ((unsigned[6]){2, 1, 1, 0, 0, 2}));
  do_test(0, ((unsigned[6]){0, 0, 0, 0, 0, 0}));
  return 0;
}
