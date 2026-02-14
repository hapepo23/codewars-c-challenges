/*
6 kyu
Multiplication table
https://www.codewars.com/kata/534d2f5b5371ecf8d2000a08
*/

#include <stdlib.h>

int** multiplication_table(int n) {
  if (n <= 0)
    return NULL;
  int** result = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    result[i] = malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
      result[i][j] = (i + 1) * (j + 1);
  }
  return result;
}
