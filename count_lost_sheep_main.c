/*
7 kyu
Count all the sheep on farm in the heights of New Zealand
https://www.codewars.com/kata/58e0f0bf92d04ccf0a000010
*/

#include <stdio.h>

int lostSheep(const int* friday, const int* saturday, int total);

static void do_test(const int* friday,
                    const int* saturday,
                    int total,
                    int expected) {
  int actual = lostSheep(friday, saturday, total);
  printf("Expected %d, actual %d -> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    int friday[] = {1, 2, 0}, saturday[] = {3, 4, 0};
    do_test(friday, saturday, 15, 5);
  }
  {
    int friday[] = {3, 1, 2, 0}, saturday[] = {4, 5, 0};
    do_test(friday, saturday, 21, 6);
  }
  {
    int friday[] = {5, 1, 4, 0}, saturday[] = {5, 4, 0};
    do_test(friday, saturday, 29, 10);
  }
  return 0;
}
