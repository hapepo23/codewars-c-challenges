/*
6 kyu
Find the in-between point
https://www.codewars.com/kata/58a672d6426bf38be4000057
*/

#include <stdbool.h>

static bool test(double xm,
                 double ym,
                 double zm,
                 double x1,
                 double y1,
                 double z1,
                 double x2,
                 double y2,
                 double z2) {
  return ((xm >= x1 && xm <= x2) || (xm >= x2 && xm <= x1)) &&
         ((ym >= y1 && ym <= y2) || (ym >= y2 && ym <= y1)) &&
         ((zm >= z1 && zm <= z2) || (zm >= z2 && zm <= z1));
}

unsigned middle_point(double x1,
                      double y1,
                      double z1,
                      double x2,
                      double y2,
                      double z2,
                      double x3,
                      double y3,
                      double z3) {
  return test(x1, y1, z1, x2, y2, z2, x3, y3, z3)
             ? 1
             : (test(x2, y2, z2, x1, y1, z1, x3, y3, z3) ? 2 : 3);
}
