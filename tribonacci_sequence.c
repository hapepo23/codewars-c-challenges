/*
6 kyu
Tribonacci Sequence
https://www.codewars.com/kata/556deca17c58da83c00002db
*/

#include <stdlib.h>

long long* tribonacci(const long long signature[3], size_t n) {
  long long* result = malloc(n * sizeof(long long));
  if (result == NULL && n > 0)
    return NULL;
  for (size_t i = 0; i < n && i < 3; i++)
    result[i] = signature[i];
  for (size_t i = 3; i < n; i++)
    result[i] = result[i - 1] + result[i - 2] + result[i - 3];
  return result;
}
