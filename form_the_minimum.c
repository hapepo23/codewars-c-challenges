/*
7 kyu
Form The Minimum
https://www.codewars.com/kata/5ac6932b2f317b96980000ca
*/

#include <stdlib.h>
#include <string.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

int minValue(const int* values, const size_t len) {
  int sorted[len];
  char num[len + 1];
  qsort(memcpy(sorted, values, sizeof(sorted)), len, sizeof(int), compare);
  char* p = num;
  int last = -1;
  for (size_t i = 0; i < len; i++) {
    if (sorted[i] != last)
      *p++ = sorted[i] + '0';
    last = sorted[i];
  }
  *p = '\0';
  return atoi(num);
}
