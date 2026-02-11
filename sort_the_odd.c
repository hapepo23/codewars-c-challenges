/*
6 kyu
Sort the odd
https://www.codewars.com/kata/578aa45ee9fd15ff4600090d
*/

#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

void sort_array(size_t n, int arr[n]) {
  int odds[n];
  int j = 0;
  for (size_t i = 0; i < n; i++)
    if (arr[i] % 2 != 0)
      odds[j++] = arr[i];
  qsort(odds, j, sizeof(int), compare);
  j = 0;
  for (size_t i = 0; i < n; i++)
    if (arr[i] % 2 != 0)
      arr[i] = odds[j++];
}
