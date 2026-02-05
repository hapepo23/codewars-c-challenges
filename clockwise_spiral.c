/*
5 kyu
The Clockwise Spiral
https://www.codewars.com/kata/536a155256eb459b8700077e
*/

#include <stdlib.h>

static void do_round(size_t size,
                     size_t round_size,
                     int** matrix,
                     size_t startrow,
                     size_t startcol,
                     int* counter) {
  if (round_size == 1)
    matrix[startrow][startcol] = ++(*counter);
  else {
    for (size_t c = 0; c < round_size - 1; c++)
      matrix[startrow][startcol + c] = ++(*counter);
    for (size_t r = 0; r < round_size - 1; r++)
      matrix[startrow + r][startcol + round_size - 1] = ++(*counter);
    for (size_t c = round_size - 1; c > 0; c--)
      matrix[startrow + round_size - 1][startcol + c] = ++(*counter);
    for (size_t r = round_size - 1; r > 0; r--)
      matrix[startrow + r][startcol] = ++(*counter);
    if (round_size > 2)
      do_round(size, round_size - 2, matrix, startrow + 1, startcol + 1,
               counter);
  }
}

int** create_spiral(int n) {
  if (n <= 0)
    return NULL;
  int** result = (int**)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    result[i] = (int*)calloc(n, sizeof(int));
  }
  int counter = 0;
  do_round(n, n, result, 0, 0, &counter);
  return result;
}
