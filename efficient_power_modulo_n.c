/*
5 kyu
Efficient Power Modulo n
https://www.codewars.com/kata/52fe629e48970ad2bd0007e6
*/

#include <inttypes.h>

typedef uint64_t u64;

u64 modpow(u64 base, u64 exponent, u64 modulo) {
  if (modulo == 1)
    return 0;
  u64 result = 1;
  base %= modulo;
  while (exponent > 0) {
    if (exponent & 1)
      result = (u64)((__uint128_t)result * base % modulo);
    base = (u64)((__uint128_t)base * base % modulo);
    exponent >>= 1;
  }
  return result;
}
