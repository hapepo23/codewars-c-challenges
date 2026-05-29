/*
4 kyu
Explosive Sum
https://www.codewars.com/kata/52ec24228a515e620b0005ef
*/

#include <stdlib.h>

unsigned long long exp_sum(unsigned n) {
  unsigned long long* p = calloc(n + 1, sizeof(unsigned long long));
  if (!p)
    return 0;
  p[0] = 1;
  for (unsigned i = 1; i <= n; i++) {
    for (unsigned j = i; j <= n; j++) {
      p[j] += p[j - i];
    }
  }
  unsigned long long result = p[n];
  free(p);
  return result;
}
