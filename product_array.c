/*
7 kyu
Product Array
https://www.codewars.com/kata/5a905c2157c562994900009d
*/

#include <stdlib.h>

long long* productArray(const int numbers[], unsigned count) {
  long long* result = malloc(count * sizeof(long long));
  long long r = numbers[0];
  for (unsigned i = 1; i < count; i++) {
    r *= numbers[i];
  }
  for (unsigned i = 0; i < count; i++) {
    result[i] = r / numbers[i];
  }
  return result;
}
