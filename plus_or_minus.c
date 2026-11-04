/*
6 kyu
Plus or Minus
https://www.codewars.com/kata/65f8279c265f42003ffbd931
*/

#include <math.h>
#include <stddef.h>

typedef double (*TestFunction)(size_t n, const double values[n]);

void determine_signs(char* expression,
                     const char* variables,
                     TestFunction test) {
  size_t n = 0;
  while (variables[n])
    n++;
  double values[n];
  for (size_t i = 0; i < n; i++)
    values[i] = ldexp(1.0, i);
  double result = test(n, values);
  unsigned int mask = (unsigned int)((result + ((1U << n) - 1)) / 2);
  size_t pos = 0;
  for (size_t i = 0; i < n; i++) {
    if (i > 0 || !(mask & (1U << i)))
      expression[pos++] = (mask & (1U << i)) ? '+' : '-';
    expression[pos++] = variables[i];
  }
  expression[pos] = '\0';
}
