/*
7 kyu
Password entropy
https://www.codewars.com/kata/6a1f03fac18f58f98ad9d21a
*/

#include <ctype.h>
#include <math.h>

double entropy(const char* password) {
  int pool[4] = {0};
  int poolsizes[4] = {26, 26, 10, 32};
  int len = 0;
  while (*password) {
    if (*password > ' ') {
      len++;
      if (islower(*password))
        pool[0] = 1;
      else if (isupper(*password))
        pool[1] = 1;
      else if (isdigit(*password))
        pool[2] = 1;
      else
        pool[3] = 1;
    }
    password++;
  }
  if (len == 0)
    return 0.0;
  int poolsize = 0;
  for (int i = 0; i < 4; i++)
    poolsize += pool[i] * poolsizes[i];
  return (double)len * log2((double)poolsize);
}
