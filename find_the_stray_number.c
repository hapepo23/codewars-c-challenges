/*
7 kyu
Find the stray number
https://www.codewars.com/kata/57f609022f4d534f05000024
*/

#include <stddef.h>

int stray(size_t n, const int arr[n]) {
  int result = 0;
  for (size_t i = 0; i < n; i++)
    result ^= arr[i];
  return result;
}
