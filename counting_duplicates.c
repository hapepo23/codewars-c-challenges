/*
6 kyu
Counting Duplicates
https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1
*/

#include <ctype.h>
#include <stddef.h>

size_t duplicate_count(const char* text) {
  unsigned counts[43] = {0};
  while (*text) {
    int c = *text;
    if (islower(c))
      c -= 32;
    c -= 48;
    if (c >= 0 && c < 43)
      counts[c]++;
    text++;
  }
  size_t result = 0;
  for (size_t c = 0; c < 43; c++)
    if (counts[c] > 1)
      result++;
  return result;
}
