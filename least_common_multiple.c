/*
5 kyu
Least Common Multiple
https://www.codewars.com/kata/5259acb16021e9d8a60010af
*/

#include <stdarg.h>

typedef unsigned long long ull;

static ull greatest_common_divisor(ull m, ull n) {
  while (m > 0) {
    ull tmp = n % m;
    n = m;
    m = tmp;
  }
  return n;
}

static ull least_common_multiple(ull m, ull n) {
  ull x = m / greatest_common_divisor(m, n);
  return n * x;
}

ull args_LCM(unsigned n, ...) {
  ull lcm;
  if (n == 0)
    return 1;
  va_list args;
  va_start(args, n);
  for (unsigned i = 0; i < n; i++) {
    ull p = va_arg(args, unsigned);
    if (p == 0)
      return 0;
    lcm = i == 0 ? p : least_common_multiple(lcm, p);
  }
  va_end(args);
  return lcm;
}
