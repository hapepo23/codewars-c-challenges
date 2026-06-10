/*
7 kyu
Quadrant Split Sum
https://www.codewars.com/kata/6a08841ec8545c42e410b34a
*/

#include <limits.h>
#include <stddef.h>

int max_land_value(size_t height, size_t width, const int area[height][width]) {
  size_t h2 = height / 2, w2 = width / 2;
  int sum[4] = {0}, mx = INT_MIN;
  for (size_t row = 0; row < h2; row++)
    for (size_t col = 0; col < w2; col++) {
      sum[0] += area[row][col];
      sum[1] += area[row][width - col - 1];
      sum[2] += area[height - row - 1][col];
      sum[3] += area[height - row - 1][width - col - 1];
    }
  for (size_t i = 0; i < 4; i++)
    if (sum[i] > mx)
      mx = sum[i];
  return mx;
}
