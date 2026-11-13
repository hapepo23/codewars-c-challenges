/*
6 kyu
Happy numbers
https://www.codewars.com/kata/5464cbfb1e0c08e9b3000b3e
*/

#include <stdbool.h>

static unsigned sum_of_squares_of_digits(unsigned n) {
  if (n <= 1)
    return n;
  unsigned digit;
  unsigned result = 0;
  do {
    digit = n % 10;
    result += digit * digit;
    n /= 10;
  } while (n > 0);
  return result;
}

bool is_happy(unsigned n) {
  do {
    n = sum_of_squares_of_digits(n);
    if (n == 1)
      return true;
  } while (n != 4);
  return false;
}
