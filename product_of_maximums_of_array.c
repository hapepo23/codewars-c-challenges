/*
7 kyu
Product Of Maximums Of Array
https://www.codewars.com/kata/5a63948acadebff56f000018
*/

#include <stdlib.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a < *(int*)b) - (*(int*)a > *(int*)b);
}

int maxProduct(const int numbers[], int length, int k) {
  int sorted_array[length];
  for (int i = 0; i < length; i++)
    sorted_array[i] = numbers[i];
  qsort(sorted_array, length, sizeof(int), compare);
  int prod = sorted_array[0];
  for (int i = 1; i < k; i++)
    prod *= sorted_array[i];
  return prod;
}
