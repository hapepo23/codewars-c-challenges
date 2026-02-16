/*
6 kyu
Matrix Transpose
https://www.codewars.com/kata/52fba2a9adcd10b34300094c
*/

#include <stddef.h>

void transpose_matrix(size_t rows,
                      size_t cols,
                      const int matrix[rows][cols],
                      int transpose[cols][rows]) {
  for (size_t r = 0; r < rows; r++)
    for (size_t c = 0; c < cols; c++)
      transpose[c][r] = matrix[r][c];
}
