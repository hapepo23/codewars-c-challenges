/*
7 kyu
Don't give me five!
https://www.codewars.com/kata/5813d19765d81c592200001a
*/

#include <stdbool.h>

static bool has_digit_5(int n) {
  while (n != 0) {
    if (n % 10 == 5 || n % 10 == -5)
      return true;
    n /= 10;
  }
  return false;
}

int dontGiveMeFive(int start, int end) {
  int result = 0;
  for (int i = start; i <= end; i++)
    if (!has_digit_5(i))
      result++;
  return result;
}
