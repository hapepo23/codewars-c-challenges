/*
7 kyu
Find the median
https://www.codewars.com/kata/5864eb8039c5ab9cd400005c
*/

#include <stdlib.h>
#include <string.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a < *(int*)b) - (*(int*)a > *(int*)b);
}

double median(size_t length, int array[length]) {
  int sorted[length];
  qsort(memcpy(sorted, array, sizeof(sorted)), length, sizeof(int), compare);
  return (sorted[length / 2] + sorted[length / 2 - (!(length % 2))]) / 2.;
}
