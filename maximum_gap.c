/*
7 kyu
Maximum Gap
https://www.codewars.com/kata/5a7893ef0025e9eb50000013
*/

#include <stdlib.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

unsigned maxGap(const int numbers[], unsigned count) {
  unsigned i, gap = 0, result = 0;
  int sorted_numbers[count];
  for (i = 0; i < count; i++)
    sorted_numbers[i] = numbers[i];
  qsort(sorted_numbers, count, sizeof(int), compare);
  for (i = 1; i < count; i++) {
    gap = sorted_numbers[i] - sorted_numbers[i - 1];
    if (gap > result)
      result = gap;
  }
  return result;
}
