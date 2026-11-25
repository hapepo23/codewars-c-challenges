/*
7 kyu
Check if a triangle is an equable triangle!
https://www.codewars.com/kata/57d0089e05c186ccb600035e
*/

#include <math.h>
#include <stdbool.h>

bool equable_triangle(unsigned a, unsigned b, unsigned c) {
  double perimeter = (double)a + (double)b + (double)c;
  double halfperi = perimeter / 2.0;
  double area = sqrt(halfperi * (halfperi - (double)a) *
                     (halfperi - (double)b) * (halfperi - (double)c));
  return fabs(perimeter - area) < 1e-10;
}
