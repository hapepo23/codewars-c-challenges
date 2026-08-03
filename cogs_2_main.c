/*
7 kyu
Cogs 2
https://www.codewars.com/kata/59e72bdcfc3c4974190000d9
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*(arr)))

double* cog_rpm(const int cogs[], unsigned count, int n);

static char* array_to_str(char* out, unsigned count, const int array[count]) {
  char* ptr = out;
  ptr += sprintf(ptr, "{ ");
  for (size_t i = 0; i < count; i++)
    ptr += sprintf(ptr, "%d%s", array[i], (i == count - 1) ? "" : ", ");
  ptr += sprintf(ptr, " }");
  return out;
}

static void do_test(unsigned count,
                    const int cogs[count],
                    int n,
                    const double expected[2]) {
  char* array_str = array_to_str((char[4096]){""}, count, cogs);
  double* actual = cog_rpm(cogs, count, n);
  printf("Cogs = %s\nn = %d\n", array_str, n);
  printf("Expected = { %.17g, %.17g }\nActual = { %.17g, %.17g }\n",
         expected[0], expected[1], actual[0], actual[1]);
  if (fabs(actual[0] - expected[0]) < 1e-3 &&
      fabs(actual[1] - expected[1]) < 1e-3)
    puts("-> OK\n");
  else
    puts("-> FAIL\n");
  free(actual);
}

int main(void) {
  {
    int cogs[] = {100, 50, 25}, n = 1;
    double expected[2] = {-1.0 / 2.0, -2.0};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  {
    int cogs[] = {100, 100, 50, 25}, n = 2;
    double expected[2] = {1.0 / 2.0, -2.0};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  {
    int cogs[] = {100}, n = 0;
    double expected[2] = {1.0, 1.0};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  {
    int cogs[] = {100, 100, 100, 100}, n = 0;
    double expected[2] = {1, -1};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  {
    int cogs[] = {100, 100, 100, 100}, n = 1;
    double expected[2] = {-1, 1};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  {
    int cogs[] = {100, 100, 100, 100}, n = 2;
    double expected[2] = {1, -1};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  {
    int cogs[] = {100, 100, 100, 100}, n = 3;
    double expected[2] = {-1, 1};
    do_test(ARRAY_SIZE(cogs), cogs, n, expected);
  }
  return 0;
}
