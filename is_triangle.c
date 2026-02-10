/*
7 kyu
Is this a triangle?
https://www.codewars.com/kata/56606694ec01347ce800001b
*/

#include <stdbool.h>

bool is_triangle(int a, int b, int c) {
  int mx = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
  return mx < (a + b + c - mx);
}
