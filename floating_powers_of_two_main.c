/*
6 kyu
Floating powers of two
https://www.codewars.com/kata/68c72f2724c3149560327a3a
*/

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

float float_power_of_two(float);
double double_power_of_two(double);

static void test_float(float v, float w) {
  float g = float_power_of_two(v);
  printf("float_power_of_two(%.9g), expected: %.9g, actual: %.9g -> %s\n", v, w,
         g, w == g || (isnan(w) && isnan(g)) ? "OK" : "FAIL");
}

static void test_double(double v, double w) {
  double g = double_power_of_two(v);
  printf("double_power_of_two(%.9g), expected: %.9g, actual: %.9g -> %s\n", v,
         w, g, w == g || (isnan(w) && isnan(g)) ? "OK" : "FAIL");
}

int main(void) {
  test_float(1.0F, 0);
  test_float(-1.0F, 0);
  test_float(2.0F, 1);
  test_float(-2.0F, 1);
  test_float(0.5F, -1);
  test_float(-0.5F, -1);
  test_float(4.0F, 2);
  test_float(-4.0F, 2);
  test_float(0.25F, -2);
  test_float(-0.25F, -2);
  test_float(1024.0F, 10);
  test_float(-1024.0F, 10);
  test_float(1.0F / 1024.0F, -10);
  test_float(-1.0F / 1024.0F, -10);
  test_float(0x1P-149F, -149);
  test_float(-0x1P-149F, -149);
  test_float(0x1P+127F, 127);
  test_float(-0x1P+127F, 127);
  test_float(0.0F, NAN);
  test_float(-0.0F, NAN);
  test_float(3.0F, NAN);
  test_float(-3.0F, NAN);
  test_float(0.75F, NAN);
  test_float(-0.75F, NAN);
  test_float(INFINITY, NAN);
  test_float(-INFINITY, NAN);
  test_float(NAN, NAN);
  test_float(FLT_MAX, NAN);
  test_float(-FLT_MAX, NAN);
  test_double(1.0, 0);
  test_double(-1.0, 0);
  test_double(2.0, 1);
  test_double(-2.0, 1);
  test_double(0.5, -1);
  test_double(-0.5, -1);
  test_double(4.0, 2);
  test_double(-4.0, 2);
  test_double(0.25, -2);
  test_double(-0.25, -2);
  test_double(1024.0, 10);
  test_double(-1024.0, 10);
  test_double(1.0 / 1024.0, -10);
  test_double(-1.0 / 1024.0, -10);
  test_double(0x1P-1074, -1074);
  test_double(-0x1P-1074, -1074);
  test_double(0x1P+1023, 1023);
  test_double(-0x1P+1023, 1023);
  test_double(0.0, NAN);
  test_double(-0.0, NAN);
  test_double(3.0, NAN);
  test_double(-3.0, NAN);
  test_double(0.75, NAN);
  test_double(-0.75, NAN);
  test_double(INFINITY, NAN);
  test_double(-INFINITY, NAN);
  test_double(NAN, NAN);
  test_double(DBL_MAX, NAN);
  test_double(-DBL_MAX, NAN);
  return 0;
}
