/*
7 kyu
Square Every Digit
https://www.codewars.com/kata/546e2562b03326a88e000020
*/

#include <limits.h>
#include <stdio.h>

typedef unsigned long long ull;

ull square_digits(unsigned n);

static void do_test(unsigned n, ull expected) {
  ull actual = square_digits(n);
  printf("For n = %u, expected %llu, actual %llu -> %s\n", n, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(3212u, 9414ull);
  do_test(2112u, 4114ull);
  do_test(0u, 0ull);
  do_test(999u, 818181ull);
  do_test(10001u, 10001ull);
  do_test(3210987654u, 9410816449362516ull);
  do_test(3999999999u, 9818181818181818181ull);
  do_test(UINT_MAX, 164811681364948125ull);
  return 0;
}
