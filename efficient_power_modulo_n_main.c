/*
5 kyu
Efficient Power Modulo n
https://www.codewars.com/kata/52fe629e48970ad2bd0007e6
*/

#include <inttypes.h>
#include <stdio.h>

typedef uint64_t u64;

u64 modpow(u64 base, u64 exponent, u64 modulo);

static void do_test(u64 base, u64 exponent, u64 modulo, u64 expected) {
  u64 actual = modpow(base, exponent, modulo);
  printf("For (%" PRIu64 " ^ %" PRIu64 ") %% %" PRIu64 ", expected: %" PRIu64
         ", actual: %" PRIu64 " -> %s\n",
         base, exponent, modulo, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(2, 3, 5, 3);
  do_test(4, 12, 3, 1);
  do_test(11, 10, 300, 1);
  do_test(11, 100000, 49, 32);
  do_test(5, 100000000, 19, 5);
  do_test(200, 3000, 10, 0);
  do_test(8132, 21302, 5, 4);
  do_test(8132, 21302, 1, 0);
  do_test(9, 193125, 37, 26);
  do_test(13, 81230123, 22, 19);
  do_test(29, 1013293125, 492, 161);
  do_test(31, 902938423012, 1023, 961);
  return 0;
}
