/*
6 kyu
Non-even substrings
https://www.codewars.com/kata/59da47fa27ee00a8b90000b4
*/

#include <stddef.h>

size_t solve(const char* s) {
  const char* p = s;
  size_t result = 0;
  for (size_t i = 1; *p; i++, p++)
    result += i * ((*p - '0') % 2);
  return result;
}
