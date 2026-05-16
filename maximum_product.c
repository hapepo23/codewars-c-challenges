/*
7 kyu
Maximum Product
https://www.codewars.com/kata/5a4138acf28b82aa43000117
*/

#include <limits.h>
#include <stddef.h>

int adjacentElementsProduct(const int inputArray[], size_t input_size) {
  int mx = INT_MIN;
  for (size_t i = 1; i < input_size; i++) {
    int prd = inputArray[i - 1] * inputArray[i];
    if (prd > mx)
      mx = prd;
  }
  return mx;
}
