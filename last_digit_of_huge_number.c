/*
3 kyu
Last digit of a huge number
https://www.codewars.com/kata/5518a860a73e708c0a000027
*/

#include <stddef.h>

static const int cycles[10][4] = {
    {0, 0, 0, 0}, {1, 1, 1, 1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6, 4, 6},
    {5, 5, 5, 5}, {6, 6, 6, 6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1},
};

static int tower_is_zero(const unsigned long long* a, size_t len);

static int tower_is_one(const unsigned long long* a, size_t len) {
  if (len == 0)
    return 1;
  if (len == 1)
    return a[0] == 1;
  return tower_is_zero(a + 1, len - 1) || a[0] == 1;
}

static int tower_is_zero(const unsigned long long* a, size_t len) {
  if (len == 0)
    return 0;
  if (a[0] != 0)
    return 0;
  return !tower_is_zero(a + 1, len - 1);
}

static int tower_cmp2(const unsigned long long* a, size_t len) {
  if (len == 0)
    return 1;
  if (len == 1)
    return a[0] < 2 ? (int)a[0] : 2;
  if (tower_is_zero(a, len))
    return 0;
  if (tower_is_one(a, len))
    return 1;
  return 2;
}

static unsigned long long tower_mod(const unsigned long long* a,
                                    size_t len,
                                    unsigned long long m) {
  if (len == 0)
    return 1 % m;
  if (len == 1)
    return a[0] % m;
  const unsigned long long* rest = a + 1;
  size_t rlen = len - 1;
  if (tower_is_zero(rest, rlen))
    return 1 % m;
  if (a[0] == 0)
    return 0 % m;
  if (m == 2)
    return a[0] % 2;
  if (m == 4) {
    unsigned long long b = a[0] % 4;
    if (b == 0)
      return 0;
    if (b == 1)
      return 1;
    if (b == 3) {
      unsigned long long e_mod2 = tower_mod(rest, rlen, 2);
      return (e_mod2 == 1) ? 3 : 1;
    }
    int ec = tower_cmp2(rest, rlen);
    return (ec == 1) ? 2 : 0;
  }
  unsigned long long exp_mod4 = tower_mod(rest, rlen, 4);
  int base = (int)(a[0] % 10);
  int ci = (exp_mod4 == 0) ? 3 : (int)(exp_mod4 - 1);
  return cycles[base][ci];
}

int last_digit(const unsigned long long array[], size_t length) {
  if (length == 0)
    return 1;
  return (int)tower_mod(array, length, 10);
}
