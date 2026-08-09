/*
7 kyu
Sum it continuously
https://www.codewars.com/kata/59b44d00bf10a439dd00006f
*/

#include <stddef.h>

void add(size_t length, const int array[length], int output[length]) {
  int sum = 0;
  for (size_t i = 0; i < length; i++)
    output[i] = (sum += array[i]);
}
