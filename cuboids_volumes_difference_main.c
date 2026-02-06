/*
8 kyu
Difference of Volumes of Cuboids
https://www.codewars.com/kata/58cb43f4256836ed95000f97
*/

#include <stdio.h>

int find_difference(const int a[3], const int b[3]);

static void do_test(const int a[3], const int b[3], const int expected) {
  int submitted = find_difference(a, b);
  printf(
      "Cuboid a = [%d, %d, %d]\nCuboid b = [%d, %d, %d]\n"
      "Expected : %d\nSubmitted: %d\n%s\n\n",
      a[0], a[1], a[2], b[0], b[1], b[2], expected, submitted,
      submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const int one[3] = {3, 2, 5};
    const int two[3] = {1, 4, 4};
    const int expected = 14;
    do_test(one, two, expected);
  }
  {
    const int one[3] = {9, 7, 2};
    const int two[3] = {5, 2, 2};
    const int expected = 106;
    do_test(one, two, expected);
  }
  return 0;
}
