/*
6 kyu
Knight's Reach
https://www.codewars.com/kata/6afde4830e68b231e3fd1c26
*/

#include <stdio.h>

int many_horse(int x, int y, int n);

static void tester(int x, int y, int n, int expected) {
  int actual = many_horse(x, y, n);
  printf("x = %d, y = %d, n = %d, expected = %d, actual = %d -> %s\n", x, y, n,
         expected, actual, actual == expected ? "OK" : "FAIL");
}

int main(void) {
  tester(1, 1, 0, 1);
  tester(4, 4, 1, 8);
  tester(2, 2, 2, 15);
  tester(1, 1, 6, 32);
  tester(4, 4, 5, 32);
  return 0;
}
