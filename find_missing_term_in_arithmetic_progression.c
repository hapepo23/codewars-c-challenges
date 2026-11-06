/*
6 kyu
Find the missing term in an Arithmetic Progression
https://www.codewars.com/kata/52de553ebb55d1fca3000371
*/

#include <stddef.h>

int find_missing(const int* nums, size_t n) {
  int diff = (nums[n - 1] - nums[0]) / (int)n;
  for (size_t i = 1; i < n; i++)
    if (nums[i] - nums[i - 1] != diff)
      return nums[i - 1] + diff;
  return nums[0];
}
