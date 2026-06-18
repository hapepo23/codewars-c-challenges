/*
6 kyu
zipWith
https://www.codewars.com/kata/5825792ada030e9601000782
*/

#include <stddef.h>

typedef int (*zipfunc_t)(int, int);

void zip_with(zipfunc_t fn,
              size_t z1,
              const int a1[z1],
              size_t z2,
              const int a2[z2],
              size_t* z3,
              int* a3) {
  *z3 = z1 > z2 ? z2 : z1;
  for (size_t i = 0; i < *z3; i++)
    a3[i] = fn(a1[i], a2[i]);
}
