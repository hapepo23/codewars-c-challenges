/*
7 kyu
Cogs 2
https://www.codewars.com/kata/59e72bdcfc3c4974190000d9
*/

#include <stdlib.h>

double* cog_rpm(const int cogs[], unsigned count, int n) {
  double* result = malloc(2 * sizeof(double));
  result[0] = 1.;
  for (int i = n - 1; i > -1; i--)
    result[0] = -result[0] * (double)cogs[i + 1] / (double)cogs[i];
  result[1] = 1.;
  for (unsigned i = n + 1; i < count; i++)
    result[1] = -result[1] * (double)cogs[i - 1] / (double)cogs[i];
  return result;
}
