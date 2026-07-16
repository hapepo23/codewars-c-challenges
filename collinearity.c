/*
8 kyu
Collinearity
https://www.codewars.com/kata/65ba420888906c1f86e1e680
*/

#include <math.h>
#include <stdbool.h>

bool collinearity(int x1, int y1, int x2, int y2) {
  if ((x1 == 0 && x2 == 0) || (y1 == 0 && y2 == 0))
    return true;
  if ((x1 == 0 && x2 != 0) || (y1 == 0 && y2 != 0))
    return false;
  return fabs((double)x2 / (double)x1 * (double)y1 - (double)y2) < 1e-10;
}
