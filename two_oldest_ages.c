/*
7 kyu
Two Oldest Ages
https://www.codewars.com/kata/511f11d355fe575d2c000001
*/

#include <limits.h>
#include <stddef.h>

void two_oldest_ages(size_t n, const int ages[n], int result[2]) {
  result[0] = INT_MIN;
  result[1] = INT_MIN;
  for (size_t i = 0; i < n; i++) {
    if (ages[i] >= result[1]) {
      result[0] = result[1];
      result[1] = ages[i];
    } else if (ages[i] > result[0]) {
      result[0] = ages[i];
    }
  }
}
