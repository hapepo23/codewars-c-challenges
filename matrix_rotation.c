/*
6 kyu
Matrix Rotation
https://www.codewars.com/kata/593e978a3bb47a8308000b8f
*/

#include <stdlib.h>
#include <string.h>

char** rotate_clockwise(size_t rows_in,
                        const char* const matrix[rows_in],
                        size_t* rows_out) {
  if (rows_in > 0) {
    size_t cols_in = strlen(matrix[0]);
    if (cols_in > 0) {
      *rows_out = cols_in;
      char** result = calloc(cols_in, sizeof(char*));
      for (size_t i = 0; i < cols_in; i++) {
        result[i] = calloc(rows_in + 1, sizeof(char));
        for (size_t j = 0; j < rows_in; j++)
          result[i][j] = matrix[rows_in - 1 - j][i];
      }
      return result;
    }
  }
  *rows_out = 0;
  return NULL;
}

void free_matrix(size_t rows, char* matrix[rows]) {
  for (size_t i = 0; i < rows; i++)
    free(matrix[i]);
  free(matrix);
}
