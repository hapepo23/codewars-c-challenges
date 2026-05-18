/*
7 kyu
Return pyramids
https://www.codewars.com/kata/5a1c28f9c9fc0ef2e900013b
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pyramid(int n) {
  int bytes = 1;
  for (int i = 1; i <= n; i++)
    bytes += (n + i + 1);
  char* result = calloc(bytes, sizeof(char));
  int count = 0;
  for (int i = 0; i < n - 1; i++)
    count += sprintf(result + count, "%*s/%*s\\\n", n - i - 1, "", i * 2, "");
  result[count++] = '/';
  for (int i = 1; i <= (n - 1) * 2; i++)
    result[count++] = '_';
  strcpy(result + count, "\\\n");
  return result;
}
