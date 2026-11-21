/*
6 kyu
Manhattan Distance
https://www.codewars.com/kata/52998bf8caa22d98b800003a
*/

#include <stdlib.h>

int manhattan_distance(const int a[2], const int b[2]) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
