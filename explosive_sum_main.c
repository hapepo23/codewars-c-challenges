/*
4 kyu
Explosive Sum
https://www.codewars.com/kata/52ec24228a515e620b0005ef
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long exp_sum(unsigned n);

static void do_test(unsigned n, unsigned long long expected) {
  unsigned long long submitted = exp_sum(n);
  printf("n = %u, submitted = %llu, expected = %llu -> %s\n", n, submitted,
         expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(1, 1);
  do_test(2, 2);
  do_test(3, 3);
  do_test(4, 5);
  do_test(5, 7);
  do_test(10, 42);
  do_test(250, 230793554364681LL);
  do_test(400, 6727090051741041926LL);
  return 0;
}
