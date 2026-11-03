/*
6 kyu
Number Zoo Patrol
https://www.codewars.com/kata/5276c18121e20900c0000235
*/

#include <stddef.h>

unsigned find_number(const unsigned* arr, size_t len) {
  unsigned missing = 0;
  for (size_t i = 1; i <= len + 1; i++)
    missing ^= (unsigned)i;
  for (size_t i = 0; i < len; i++)
    missing ^= arr[i];
  return missing;
}
