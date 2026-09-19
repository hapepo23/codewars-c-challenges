/*
7 kyu
Every possible sum of two digits
https://www.codewars.com/kata/5b4e474305f04bea11000148
*/

#include <stddef.h>

size_t digits(unsigned number, unsigned result[256]) {
  if (number < 10)
    return 0;
  int digits[20];
  int count = 0;
  size_t res = 0;
  while (number > 0) {
    digits[count++] = number % 10;
    number /= 10;
  }
  for (int i = count - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      result[res++] = digits[i] + digits[j];
    }
  }
  return res;
}
