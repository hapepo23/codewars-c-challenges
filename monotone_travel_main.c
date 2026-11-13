/*
7 kyu
Monotone travel
https://www.codewars.com/kata/54466996990c921f90000d61
*/

#include <stdbool.h>
#include <stdio.h>

bool is_monotone(size_t n, const double heights[n]);

static void print_array(size_t len, const double array[len]) {
  printf("{ ");
  for (size_t i = 0; i < len; i++)
    printf("%.17g%s", array[i], (i == len - 1) ? "" : ", ");
  printf(" }");
}

static void tester(size_t n, const double heights[n], bool exp) {
  const bool act = is_monotone(n, heights);
  printf("Heights = ");
  print_array(n, heights);
  printf("\n");
  printf("Expected = %s, actual = %s -> %s\n\n", exp ? "true" : "false",
         act ? "true" : "false", exp == act ? "OK" : "FAIL");
}

int main(void) {
  {
    const double heights[7] = {5, 5, 5, 5, 5, 5, 5};
    tester(7, heights, true);
  }
  {
    const double heights[5] = {5, 4, 3, 2, 1};
    tester(5, heights, false);
  }
  {
    const double heights[2] = {1, 11};
    tester(2, heights, true);
  }
  {
    const double heights[7] = {5, 10, 0, 1, -40, 42, -1};
    tester(7, heights, false);
  }
  {
    const double heights[1] = {1};
    tester(1, heights, true);
  }
  {
    const void* heights = NULL;
    tester(0, heights, true);
  }
  return 0;
}
