/*
5 kyu
Conway's Look and Say - Generalized
https://www.codewars.com/kata/530045e3c7c0f4d3420001af
*/

#include <stdio.h>

typedef unsigned long long ullong;

ullong look_say(ullong n);

static void do_test(ullong input, ullong expected) {
  ullong actual = look_say(input);
  printf("For n = %llu, expected %llu, but got %llu -> %s\n", input, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(1ULL, 11ULL);
  do_test(11ULL, 21ULL);
  do_test(21ULL, 1211ULL);
  do_test(1211ULL, 111221ULL);
  do_test(0ULL, 10ULL);
  do_test(2014ULL, 12101114ULL);
  do_test(9000ULL, 1930ULL);
  do_test(22322ULL, 221322ULL);
  do_test(222222222222ULL, 122ULL);
  return 0;
}
