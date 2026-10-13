/*
6 kyu
Sum of a Sequence [Hard-Core Version]
https://www.codewars.com/kata/587a88a208236efe8500008b
*/

#include <stdio.h>

typedef long long int lli;

lli sequence_sum(lli begin_number, lli end_number, lli step);

static void dotest(lli begin, lli end, lli step, lli expected) {
  lli actual = sequence_sum(begin, end, step);
  printf(
      "Begin = %lld; end = %lld; step = %lld; "
      "expected = %lld; actual = %lld -> %s\n",
      begin, end, step, expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  dotest(2, 2, 2, 2);
  dotest(2, 6, 2, 12);
  dotest(1, 5, 1, 15);
  dotest(1, 5, 3, 5);
  dotest(1, 5, -3, 0);
  dotest(-1, -5, 1, 0);
  dotest(2, 2, -9, 2);
  dotest(2, 6, 2, 12);
  dotest(1, 5, 1, 15);
  dotest(1, 5, 3, 5);
  dotest(-1, -5, -3, -5);
  dotest(16, 15, 3, 0);
  dotest(9383, 71418, 2, 1253127200);
  return 0;
}
