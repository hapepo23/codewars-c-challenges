/*
7 kyu
Monotone travel
https://www.codewars.com/kata/54466996990c921f90000d61
*/

#include <stdbool.h>
#include <stddef.h>

bool is_monotone(size_t n, const double heights[n]) {
  if (n > 1)
    for (size_t i = 1; i < n; i++)
      if (heights[i] < heights[i - 1])
        return false;
  return true;
}
