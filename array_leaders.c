/*
7 kyu
Array Leaders
https://www.codewars.com/kata/5a651865fd56cb55760000e0
*/

#include <stdlib.h>

static void reverse_array(int arr[], int n) {
  int l = 0, r = n - 1;
  while (l < r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    ++l;
    --r;
  }
}

int* arrayLeaders(const int numbers[], int inCount, int* outCount) {
  int* result = (int*)malloc(inCount * sizeof(int));
  *outCount = 0;
  int sumright = 0;
  for (int i = inCount - 1; i >= 0; i--) {
    if (numbers[i] > sumright) {
      result[*outCount] = numbers[i];
      ++(*outCount);
    }
    sumright += numbers[i];
  }
  reverse_array(result, *outCount);
  return result;
}
