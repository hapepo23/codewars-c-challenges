/*
7 kyu
Nth Smallest Element
https://www.codewars.com/kata/5a512f6a80eba857280000fc
*/

#include <stdlib.h>
#include <string.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

int nth_smallest(const int arr[], int count, int n) {
  int sorted[count];
  qsort(memcpy(sorted, arr, sizeof(sorted)), count, sizeof(int), compare);
  return n <= count ? sorted[n - 1] : 0;
}
