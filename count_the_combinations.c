/*
7 kyu
Count the Combinations
https://www.codewars.com/kata/58e67378fd2d897b8a000110
*/

#include <stddef.h>

size_t num_combo(size_t length, const unsigned array[length], unsigned number) {
  unsigned sum = 0;
  for (size_t i = 0; i < length; i++)
    sum += array[i];
  size_t result = 0;
  for (size_t i = 0; i < length; i++)
    if (sum - array[i] == number)
      result++;
  return result;
}
