/*
6 kyu
Find the unique number
https://www.codewars.com/kata/585d7d5adb20cf33cb000235
*/

#include <stddef.h>

float finduniq(const float nums[], size_t n) {
  float same = nums[0];
  if (nums[1] != same && nums[2] != same)
    same = nums[1];
  for (size_t i = 0; i < n; i++)
    if (nums[i] != same)
      return nums[i];
  return nums[0];  // should never be reached
}
