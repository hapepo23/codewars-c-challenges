/*
7 kyu
Find the calculation type
https://www.codewars.com/kata/5aca48db188ab3558e0030fa
*/

#include <stdio.h>

char calc_type(double a, double b, double c);

static void do_test(double a, double b, double c, char expected) {
  char actual = calc_type(a, b, c);
  printf("a = %.10g, b = %.10g, c = %.10g, expected = %c, actual = %c -> %s\n",
         a, b, c, expected, actual, actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(2.0, 3.0, 5.0, 'A');
  do_test(10.0, 5.0, 5.0, 'S');
  do_test(10.0, 4.0, 40.0, 'M');
  do_test(9.0, 5.0, 1.8, 'D');
  return 0;
}
