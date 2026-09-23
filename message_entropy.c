/*
7 kyu
Computing the entropy of a message
https://www.codewars.com/kata/6925ba5fcee28ebed6e18e7d
*/

#include <math.h>

double message_entropy(const char* message) {
  int count[128] = {0};
  int tot = 0;
  while (*message) {
    if (*message > ' ') {
      count[(int)*message]++;
      tot++;
    }
    message++;
  }
  double result = 0.0;
  for (int i = ' ' + 1; i < 128; i++) {
    if (count[i]) {
      double p = (double)count[i] / (double)tot;
      result += p * log2(p);
    }
  }
  return -result;
}
