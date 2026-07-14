/*
6 kyu
Easy Polynomials
https://www.codewars.com/kata/68aeca3ee7a867797c0d4b22
*/

#include <complex.h>
#include <stdio.h>

double complex easy_polynomials(unsigned n);

static double complex evaluate_poly(double complex x, unsigned n) {
  double complex sum = 0, term = 1;
  for (unsigned i = 0; i <= n; i++) {
    sum += term;
    term *= x;
  }
  return sum;
}

static void do_test(unsigned n) {
  double complex x = easy_polynomials(n);
  double complex result = evaluate_poly(x, n);
  printf(
      "n = %u\nActual result x = %.17g + %.17g*i\n"
      "Evaluated result = %.17g + %.17g*i\n"
      "-> %s\n\n",
      n, creal(x), cimag(x), creal(result), cimag(result),
      cabs(result) < 1e-5 ? "OK" : "FAIL");
}

int main(void) {
  do_test(1);
  do_test(2);
  do_test(3);
  do_test(4);
  do_test(5);
  do_test(1000000);
  return 0;
}
