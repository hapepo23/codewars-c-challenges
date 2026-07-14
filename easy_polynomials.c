/*
6 kyu
Easy Polynomials
https://www.codewars.com/kata/68aeca3ee7a867797c0d4b22
*/

#include <complex.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double complex easy_polynomials(unsigned n) {
  double c = 2.0 * M_PI / ((double)n + 1.0);
  double complex result = cos(c) + sin(c) * I;
  return result;
}
