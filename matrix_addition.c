/*
6 kyu
Matrix Addition
https://www.codewars.com/kata/526233aefd4764272800036f
*/

#include <stdlib.h>

int* matrix_addition(size_t n,
                     const int matrix_a[n][n],
                     const int matrix_b[n][n]) {
  int* result = malloc(n * sizeof *matrix_a);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      result[i * n + j] = matrix_a[i][j] + matrix_b[i][j];
  return result;
}
