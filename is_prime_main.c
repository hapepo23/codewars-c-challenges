/*
6 kyu
Is a number prime?
https://www.codewars.com/kata/5262119038c0985a5b00029f
*/

#include <stdbool.h>
#include <stdio.h>

bool is_prime(int num);

static void do_test(int num, bool expected) {
  bool actual = is_prime(num);
  printf("Input was: %d, expected: is%sprime, actual: is%sprime -> %s\n", num,
         expected ? " " : " not ", actual ? " " : " not ",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(0, false);
  do_test(1, false);
  do_test(2, true);
  do_test(73, true);
  do_test(75, false);
  do_test(-1, false);
  do_test(3, true);
  do_test(5, true);
  do_test(7, true);
  do_test(41, true);
  do_test(5099, true);
  do_test(4, false);
  do_test(6, false);
  do_test(8, false);
  do_test(9, false);
  do_test(45, false);
  do_test(-5, false);
  do_test(-8, false);
  do_test(-41, false);
  do_test(247464361, false);
  do_test(1634300119, true);
  return 0;
}
