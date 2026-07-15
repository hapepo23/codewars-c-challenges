/*
6 kyu
Fractions To Hexadecimal
https://www.codewars.com/kata/6a3c22c2d5761bf8d86987e2
*/

#include <stdio.h>

void f2hex(const char* fraction, char* hexadecimal) {
  static const char hex[] = "0123456789abcdef";
  unsigned num, den;
  sscanf(fraction, "%u/%u", &num, &den);
  unsigned integer = num / den;
  unsigned rem = num % den;
  int n = sprintf(hexadecimal, "%x", integer);
  if (rem == 0)
    return;
  char* p = hexadecimal + n;
  *p++ = '.';
  for (int i = 0; i < 6 && rem != 0; i++) {
    rem *= 16;
    *p++ = hex[rem / den];
    rem %= den;
  }
  p--;
  while (*p == '0')
    p--;
  *(++p) = '\0';
}
