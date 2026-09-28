/*
6 kyu
TGI Friday!!
https://www.codewars.com/kata/5a0d6d8c6975982b5b000383
*/

#include <stdio.h>

int count_fridays(int year_start, int year_end);

static void do_test(int year_start, int year_end, int expected) {
  int actual = count_fridays(year_start, year_end);
  printf("For range %d-%d, expected %d, but got %d -> %s\n", year_start,
         year_end, expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(1901, 2000, 171);
  do_test(1901, 2017, 200);
  do_test(1991, 1991, 1);
  do_test(2017, 2017, 2);
  return 0;
}
