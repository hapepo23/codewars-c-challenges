/*
6 kyu
Floating powers of two
https://www.codewars.com/kata/68c72f2724c3149560327a3a
*/

#include <math.h>
#include <stdint.h>
#include <string.h>

double double_power_of_two(double v) {
  uint64_t bits;
  memcpy(&bits, &v, sizeof(bits));
  bits &= 0x7fffffffffffffffULL;
  if (bits == 0)
    return NAN;
  uint64_t exp = (bits >> 52) & 0x7ff;
  uint64_t frac = bits & ((1ULL << 52) - 1);
  if (exp == 0x7ff)
    return NAN;
  if (exp != 0) {
    if (frac != 0)
      return NAN;
    return (double)((int)exp - 1023);
  }
  if ((frac & (frac - 1)) != 0)
    return NAN;
  int bit = 0;
  while ((frac & 1) == 0) {
    frac >>= 1;
    ++bit;
  }
  return (double)(-1074 + bit);
}

float float_power_of_two(float v) {
  return double_power_of_two((double)v);
}
