/*
8 kyu
SpeedCode #2 - Array Madness
https://www.codewars.com/kata/56ff6a70e1a63ccdfa0001b1
*/

#include <stdbool.h>
#include <stddef.h>

bool array_madness(size_t n1,
                   const int arr1[n1],
                   size_t n2,
                   const int arr2[n2]) {
  int arr1_sq_sum = 0, arr2_cb_sum = 0;
  for (size_t i = 0; i < n1; i++)
    arr1_sq_sum += arr1[i] * arr1[i];
  for (size_t i = 0; i < n2; i++)
    arr2_cb_sum += arr2[i] * arr2[i] * arr2[i];
  return arr1_sq_sum > arr2_cb_sum;
}
