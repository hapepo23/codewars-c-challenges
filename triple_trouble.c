/*
6 kyu
Triple trouble
https://www.codewars.com/kata/55d5434f269c0c3f1b000058
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool triple_trouble(unsigned long long num1, unsigned long long num2) {
  char str1[21], str2[21], s2[3];
  int len1 = sprintf(str1, "%llu", num1);
  sprintf(str2, "%llu", num2);
  s2[2] = '\0';
  for (int i = 0; i < len1 - 2; i++) {
    if (str1[i] == str1[i + 1] && str1[i] == str1[i + 2]) {
      s2[0] = str1[i];
      s2[1] = str1[i];
      if (strstr(str2, s2))
        return true;
    }
  }
  return false;
}
