/*
6 kyu
Rotate matrix counter - clockwise N - times!
https://www.codewars.com/kata/5919f3bf6589022915000023
*/

#include <stddef.h>

static void copy(size_t n, const int from[n][n], int to[n][n]) {
  for (size_t r = 0; r < n; r++) {
    for (size_t c = 0; c < n; c++) {
      to[r][c] = from[r][c];
    }
  }
}

void rotate_counter_clockwise(size_t n,
                              const int matrix[n][n],
                              unsigned times,
                              int rotated[n][n]) {
  int temp[n][n];
  unsigned rots = times % 4;
  if (rots == 0) {
    copy(n, matrix, rotated);
  } else {
    copy(n, matrix, temp);
    for (unsigned i = 0; i < rots; i++) {
      for (size_t r = 0; r < n; r++) {
        for (size_t c = 0; c < n; c++) {
          rotated[n - 1 - c][r] = temp[r][c];
        }
      }
      if (i < rots - 1)
        copy(n, rotated, temp);
    }
  }
}
