/*
8 kyu
Square(n) Sum
https://www.codewars.com/kata/515e271a311df0350d00000f
*/

#include <stdio.h>

int square_sum(const int values[], size_t count);

static void do_test(const int values[], size_t count, int expected) {
  int actual = square_sum(values, count);
  printf("Expected: %d, actual: %d -> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    const int values[] = {-1};
    do_test(values, 0, 0);
  }
  {
    const int values[] = {1, 2};
    do_test(values, 2, 5);
  }
  {
    const int values[] = {0, 3, 4, 5};
    do_test(values, 4, 50);
  }
  return 0;
}
