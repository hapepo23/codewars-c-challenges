/*
7 kyu
Even and Odd!
https://www.codewars.com/kata/594adadee075005308000122
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull* eval(ull n) {
  ull* result = calloc(2, sizeof(ull));
  char nstr[21];
  int l = sprintf(nstr, "%llu", n);
  for (int i = 0; i < l; i++) {
    int digit = nstr[i] - '0';
    result[digit % 2] = result[digit % 2] * 10 + digit;
  }
  return result;
}
