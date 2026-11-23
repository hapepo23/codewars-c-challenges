/*
6 kyu
Take a Number And Sum Its Digits Raised To The Consecutive Powers
https://www.codewars.com/kata/5626b561280a42ecc50000d1
*/

#include <stddef.h>
#include <stdio.h>

typedef unsigned long long ull;

ull* sum_dig_pow(ull a, ull b, ull* results, size_t* length) {
  *length = 0;
  char buf[21];
  char* p;
  for (ull i = a; i <= b; i++) {
    ull sum = 0;
    sprintf(buf, "%llu", i);
    p = buf;
    int pos = 1;
    while (*p) {
      ull digit = (ull)(*p - '0');
      ull prod = 1;
      for (int i = 0; i < pos; i++)
        prod *= digit;
      sum += prod;
      p++;
      pos++;
    }
    if (sum == i) {
      results[*length] = i;
      (*length)++;
    }
  }
  return results;
}
