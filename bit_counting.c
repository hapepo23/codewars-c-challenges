/*
6 kyu
Bit Counting
https://www.codewars.com/kata/526571aae218b8ee490006f4
*/

#include <stddef.h>

size_t countBits(unsigned value) {
  size_t count = 0;
  while (value) {
    count += value & 1;
    value >>= 1;
  }
  return count;
}
