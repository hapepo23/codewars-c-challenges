/*
7 kyu
Sum of two lowest positive integers
https://www.codewars.com/kata/558fc85d8fd1938afb000014
*/

#include <limits.h>
#include <stddef.h>

long long sum_two_smallest_numbers(size_t n, const int numbers[n]) {
  long long sum;
  int smallest = INT_MAX;
  size_t smallest_index = -1;
  for (size_t i = 0; i < n; i++) {
    if (numbers[i] < smallest) {
      smallest = numbers[i];
      smallest_index = i;
    }
  }
  sum = smallest;
  smallest = INT_MAX;
  for (size_t i = 0; i < n; i++) {
    if (i != smallest_index && numbers[i] < smallest) {
      smallest = numbers[i];
    }
  }
  sum += smallest;
  return sum;
}
