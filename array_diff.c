/*
6 kyu
Array.diff
https://www.codewars.com/kata/523f5d21c841566fde000009
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool is_element_in_array(const int elem, const int arr[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (elem == arr[i])
      return true;
  }
  return false;
}

int* array_diff(const int arr1[],
                size_t n1,
                const int arr2[],
                size_t n2,
                size_t* z) {
  *z = 0;
  int* result = NULL;
  if (n1 != 0) {
    result = (int*)malloc(sizeof(int) * n1);
    for (size_t i = 0; i < n1; i++) {
      if (!is_element_in_array(arr1[i], arr2, n2)) {
        result[(*z)++] = arr1[i];
      }
    }
    if (*z == 0) {
      free(result);
      result = NULL;
    } else if (*z < n1)
      result = realloc(result, sizeof(int) * (*z));
  }
  return result;
}
