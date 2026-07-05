/*
7 kyu
Find the calculation type
https://www.codewars.com/kata/5aca48db188ab3558e0030fa
*/

#include <math.h>

char calc_type(double a, double b, double c) {
  if (fabs(a + b - c) < 1e-8)
    return 'A';
  else if (fabs(a - b - c) < 1e-8)
    return 'S';
  else if (fabs(a * b - c) < 1e-8)
    return 'M';
  else if (fabs(a / b - c) < 1e-8)
    return 'D';
  return '?';
}
