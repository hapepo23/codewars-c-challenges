/*
6 kyu
Transform To Prime
https://www.codewars.com/kata/5a946d9fba1bb5135100007c
*/

#include <stdbool.h>

static bool is_prime(int num) {
  if (num <= 1)
    return false;
  if (num == 2 || num == 3)
    return true;
  if (num % 2 == 0 || num % 3 == 0)
    return false;
  for (int i = 5; i * i <= num; i = i + 6)
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  return true;
}

int minimumNumber(const int numbers[], unsigned count) {
  int sum = 0, add = 0;
  for (unsigned i = 0; i < count; i++)
    sum += numbers[i];
  while (!is_prime(sum + add))
    add++;
  return add;
}
