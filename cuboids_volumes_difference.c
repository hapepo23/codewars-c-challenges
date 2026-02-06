/*
8 kyu
Difference of Volumes of Cuboids
https://www.codewars.com/kata/58cb43f4256836ed95000f97
*/

#include <stdlib.h>

int find_difference(const int a[3], const int b[3]) {
  return abs(a[0] * a[1] * a[2] - b[0] * b[1] * b[2]);
}