/*
7 kyu
Minimize Sum Of Array
https://www.codewars.com/kata/5a523566b3bfa84c2e00010b
*/

#include <stdlib.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

int minSum(const int array[], unsigned length) {
  int sorted_array[length];
  for (unsigned i = 0; i < length; i++)
    sorted_array[i] = array[i];
  qsort(sorted_array, length, sizeof(int), compare);
  int prod_sum = 0;
  for (unsigned i = 0; i < length / 2; i++)
    prod_sum += sorted_array[i] * sorted_array[length - 1 - i];
  return prod_sum;
}
