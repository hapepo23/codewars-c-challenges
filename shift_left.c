/*
7 kyu
Shift Left
https://www.codewars.com/kata/5bdc191306a8a678f6000187
*/

#include <stddef.h>
#include <string.h>

size_t shift_left(const char* a, const char* b) {
  size_t la = strlen(a);
  size_t lb = strlen(b);
  size_t n = 0;
  while (n < la && n < lb && a[la - n - 1] == b[lb - n - 1])
    n++;
  return la + lb - 2 * n;
}
