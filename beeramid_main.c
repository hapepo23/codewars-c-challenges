/*
5 kyu
Beeramid
https://www.codewars.com/kata/51e04f6b544cf3f6550000c1
*/

#include <stdio.h>

int beeramid(double bonus, double price);

static void do_test(double bonus, double price, int expected) {
  int actual = beeramid(bonus, price);
  printf("Bonus = %.2f, price = %.2f, expected: %d, actual: %d --> %s\n", bonus,
         price, expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(1500., 2., 12);
  do_test(5000., 3., 16);
  return 0;
}
