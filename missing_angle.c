/*
6 kyu
Missing Angle
https://www.codewars.com/kata/58417e9ab9c25c774500001f
*/

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double missingAngle(double h, double a, double o) {
  return asin((o == 0.0 ? sqrt(h * h - a * a) : o) /
              (h == 0.0 ? sqrt(a * a + o * o) : h)) *
         180.0 / M_PI;
}
