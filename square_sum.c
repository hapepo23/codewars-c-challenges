/*
8 kyu
Square(n) Sum
https://www.codewars.com/kata/515e271a311df0350d00000f
*/

#include <stddef.h>

int square_sum(const int values[], size_t count) {
  int result = 0;
  for (size_t i = 0; i < count; i++)
    result += values[i] * values[i];
  return result;
}
