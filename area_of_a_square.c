/*
8 kyu
Area of a Square
https://www.codewars.com/kata/5748838ce2fab90b86001b1a
*/

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double square_area(double arc) {
  return 4.0 * arc * arc / (M_PI * M_PI);
}
