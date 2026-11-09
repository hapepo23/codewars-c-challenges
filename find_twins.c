/*
7 kyu
Find twins
https://www.codewars.com/kata/5834315e06f227a6ac000099
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static int compare(const void* a, const void* b) {
  return (*(const int*)a > *(const int*)b) - (*(const int*)a < *(const int*)b);
}

bool elimination(const int* arr, size_t arr_size, int* result) {
  if (arr_size < 2)
    return false;
  int copy[arr_size];
  for (size_t i = 0; i < arr_size; i++)
    copy[i] = arr[i];
  qsort(copy, arr_size, sizeof(int), compare);
  for (size_t i = 1; i < arr_size; i++) {
    if (copy[i] == copy[i - 1]) {
      *result = copy[i];
      return true;
    }
  }
  return false;
}
