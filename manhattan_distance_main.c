/*
6 kyu
Manhattan Distance
https://www.codewars.com/kata/52998bf8caa22d98b800003a
*/

#include <stdio.h>

int manhattan_distance(const int a[2], const int b[2]);

static void tester(const int a[2], const int b[2], int expected) {
  int submitted = manhattan_distance(a, b);
  printf("a = {%d, %d}, b = {%d, %d}, expected = %d, actual = %d -> %s\n", a[0],
         a[1], b[0], b[1], expected, submitted,
         expected == submitted ? "OK" : "FAIL");
}

int main(void) {
  {
    int a[2] = {1, 1};
    int b[2] = {1, 1};
    tester(a, b, 0);
  }
  {
    int a[2] = {5, 4};
    int b[2] = {3, 2};
    tester(a, b, 4);
  }
  {
    int a[2] = {1, 1};
    int b[2] = {0, 3};
    tester(a, b, 3);
  }
  return 0;
}
