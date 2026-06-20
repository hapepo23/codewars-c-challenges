/*
7 kyu
Retrieve The N-th String Term
https://www.codewars.com/kata/66ca80460f2a3f128a865cc5
*/

#include <stddef.h>

const char* extract_string(const char* input, int n) {
  if (n < 0)
    return NULL;
  if (n == 0)
    return input;
  int count = 0;
  while (1) {
    if (*input == '\0') {
      if (*(input + 1) == '\0')
        return NULL;
      count++;
      if (count == n)
        return input + 1;
    }
    input++;
  }
  return NULL;
}
