/*
8 kyu
Counting sheep...
https://www.codewars.com/kata/54edbc7200b811e956000556
*/

#include <stdbool.h>
#include <stddef.h>

size_t count_sheep(const bool sheep[], size_t count) {
  if (sheep == NULL)
    return 0;
  size_t result = 0;
  for (size_t i = 0; i < count; i++)
    if (sheep[i])
      result++;
  return result;
}
