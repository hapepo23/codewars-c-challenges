/*
7 kyu
Find the next perfect square!
https://www.codewars.com/kata/56269eb78ad2e4ced1000013
*/

#include <stdio.h>

long int findNextSquare(long int sq);

static void do_test(long int input, long int expected) {
  long int actual = findNextSquare(input);
  printf("For n = %ld, expected %ld, but got %ld -> %s\n", input, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(121, 144);
  do_test(625, 676);
  do_test(319225, 320356);
  do_test(15241383936l, 15241630849l);
  do_test(155, -1);
  return 0;
}
