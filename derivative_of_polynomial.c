/*
5 kyu
Calculate the derivative of a polynomial
https://www.codewars.com/kata/56d060d90f9408fb3b000b03
*/

#include <stdio.h>
#include <string.h>

void sprint_derivative(char derivative[4096], const char* polynomial) {
  const char* p = polynomial;
  char* out = derivative;
  int first = 1;
  while (*p) {
    int sign = 1;
    long long coefficient = 0;
    int exponent = 0;
    int has_x = 0;
    if (*p == '+') {
      sign = 1;
      p++;
    } else if (*p == '-') {
      sign = -1;
      p++;
    }
    /* Read the coefficient, if present. */
    while (*p >= '0' && *p <= '9') {
      coefficient = coefficient * 10 + (*p - '0');
      p++;
    }
    if (p == polynomial || *(p - 1) == '+' || *(p - 1) == '-') {
      /* No digits after the sign: coefficient is implicit. */
      coefficient = 1;
    }
    if (*p == 'x') {
      has_x = 1;
      p++;
      if (*p == '^') {
        p++;
        while (*p >= '0' && *p <= '9') {
          exponent = exponent * 10 + (*p - '0');
          p++;
        }
      } else {
        exponent = 1;
      }
    }
    /* Constants and x^0 terms have derivative zero. */
    if (!has_x || exponent == 0)
      continue;
    coefficient *= exponent;
    exponent--;
    if (coefficient == 0)
      continue;
    /* Write the sign, omitting a leading '+'. */
    if (first) {
      if (sign < 0)
        *out++ = '-';
    } else
      *out++ = (sign < 0) ? '-' : '+';
    /* Write the coefficient, omitting 1 before x. */
    if (coefficient != 1 || exponent == 0)
      out += sprintf(out, "%lld", coefficient);
    if (exponent > 0) {
      *out++ = 'x';
      if (exponent > 1)
        out += sprintf(out, "^%d", exponent);
    }
    first = 0;
  }
  if (first)
    strcpy(derivative, "0");
  else
    *out = '\0';
}
