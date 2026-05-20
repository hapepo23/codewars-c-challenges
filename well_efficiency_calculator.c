/*
6 kyu
Well efficiency calculator
https://www.codewars.com/kata/5649b9f069dacef88400005e
*/

#include <stdbool.h>
#include <stddef.h>

extern const double FIELD[20][20];

static double fv(int x, int y) {
  double result = 0.0;
  if (x >= 0 && y >= 0 && x < 20 && y < 20)
    result = FIELD[x][y];
  return result;
}

bool is_efficient(size_t x, size_t y, double threshold) {
  return (fv(x - 1, y - 1) + fv(x, y - 1) + fv(x + 1, y - 1) + fv(x - 1, y) +
          fv(x, y) + fv(x + 1, y) + fv(x - 1, y + 1) + fv(x, y + 1) +
          fv(x + 1, y + 1)) >= threshold;
}
