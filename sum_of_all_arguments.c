/*
7 kyu
Sum of all arguments
https://www.codewars.com/kata/540c33513b6532cd58000259
*/

#include <stdarg.h>

int sum(int argc, ...) {
  int sum = 0;
  va_list args;
  va_start(args, argc);
  for (int i = 0; i < argc; i++)
    sum += va_arg(args, int);
  va_end(args);
  return sum;
}
