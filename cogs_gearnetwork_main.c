/*
6 kyu
Cogs Gearnetwork
https://www.codewars.com/kata/6a1170dbe815a63a8eabd1d4
*/

#include <math.h>
#include <stddef.h>
#include <stdio.h>

extern void cogsebi(size_t gears_count,
                    const int gears[gears_count],
                    size_t connections_count,
                    const int connections[connections_count][2],
                    int driver_id,
                    double driver_rpm,
                    double rpms[gears_count]);

static void fill_with_junk(size_t n, double* arr) {
  for (size_t i = 0; i < n; i++)
    arr[i] = 999.99;
}

static void check_results(size_t n,
                          const double* actual,
                          const double* expected) {
  for (size_t i = 0; i < n; i++) {
    printf("Gear %zu, expected %.15g, actual %.15g -> %s\n", i, expected[i],
           actual[i], fabs(expected[i] - actual[i]) < 1e-5 ? "OK" : "FAIL");
  }
  printf("\n");
}

int main(void) {
  {
    int gears[] = {10, 20, 50, 10};
    int connections[][2] = {{0, 1}, {1, 2}, {1, 3}};
    double expected[] = {100.0, -50.0, 20.0, 100.0};
    double actual[4];
    fill_with_junk(4, actual);
    cogsebi(4, gears, 3, connections, 0, 100.0, actual);
    check_results(4, actual, expected);
  }
  {
    int gears[] = {15, 17};
    int connections[][2] = {{0, 1}};
    double expected[] = {100.0, -88.23529411764706};
    double actual[2];
    fill_with_junk(2, actual);
    cogsebi(2, gears, 1, connections, 0, 100.0, actual);
    check_results(2, actual, expected);
  }
  return 0;
}
