/*
8 kyu
To square(root) or not to square(root)
https://www.codewars.com/kata/57f6ad55cca6e045d2000627
*/

#include <math.h>
#include <stdlib.h>

int* squareOrSquareRoot(int* array, int length) {
  int* result = malloc(length * sizeof(int));
  for (int i = 0; i < length; i++) {
    int isqrt = (int)sqrt((double)array[i]);
    result[i] = (isqrt * isqrt == array[i]) ? isqrt : (array[i] * array[i]);
  }
  return result;
}
