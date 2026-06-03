/*
6 kyu
The area between the vertex of the parabola and x-axis
https://www.codewars.com/kata/63ecc21e12797b06519ad94f
*/

#include <math.h>

double area(double a, double b, double c) {
  double d = b * b - 4. * a * c;
  if (d <= 0.)
    return 0.;
  double x1 = (-b + sqrt(d)) / (2. * a);
  double x2 = (-b - sqrt(d)) / (2. * a);
  double area = (a * x1 * x1 * x1 / 3. + b * x1 * x1 / 2. + c * x1) -
                (a * x2 * x2 * x2 / 3. + b * x2 * x2 / 2. + c * x2);
  return area < 0. ? -area : area;
}
