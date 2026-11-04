/*
7 kyu
Most Likely
https://www.codewars.com/kata/56644a421b7c94c622000056
*/

#include <stdbool.h>
#include <stdio.h>

bool most_likely(const char* a, const char* b) {
  int a1, a2, b1, b2;
  sscanf(a, "%d:%d", &a1, &a2);
  sscanf(b, "%d:%d", &b1, &b2);
  return (double)a1 / (double)a2 > (double)b1 / (double)b2;
}
