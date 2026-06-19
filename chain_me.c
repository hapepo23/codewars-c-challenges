/*
7 kyu
Chain me
https://www.codewars.com/kata/54fb853b2c8785dd5e000957
*/

#include <stddef.h>

typedef int (*funcptr)(int);

int chain(int init_val, size_t length, const funcptr functions[length]) {
  int result = init_val;
  for (size_t i = 0; i < length; i++)
    result = functions[i](result);
  return result;
}
