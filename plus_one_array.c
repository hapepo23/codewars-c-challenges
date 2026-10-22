/*
6 kyu
+1 Array
https://www.codewars.com/kata/5514e5b77e6b2f38e0000ca9
*/

#include <stdlib.h>
#include <string.h>

int* up_array(const int arr[], unsigned* count) {
  if (*count <= 0)
    return NULL;
  for (unsigned i = 0; i < *count; i++) {
    if (arr[i] < 0 || arr[i] > 9) {
      *count = 0;
      return NULL;
    }
  }
  int* result = malloc((*count + 1) * sizeof(int));
  int c = 1;
  for (unsigned i = *count; i > 0; i--) {
    result[i] = arr[i - 1] + c;
    if (result[i] > 9) {
      result[i] = 0;
      c = 1;
    } else
      c = 0;
  }
  if (c == 0)
    memmove(result, result + 1, *count * sizeof(int));
  else {
    (*count)++;
    result[0] = c;
  }
  return result;
}
