/*
8 kyu
Area of a Square
https://www.codewars.com/kata/5748838ce2fab90b86001b1a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pyramid(int n) {
  char* result = calloc((2 * n + 1) * n + 1, sizeof(char));
  if (n == 1)
    strcpy(result, "/\\\n");
  else {
    int count = sprintf(result, "%*s/\\\n", n - 1, " ");
    for (int i = 2; i <= n - 1; i++)
      count +=
          sprintf(result + count, "%*s/%*s\\\n", n - i, " ", (i - 1) * 2, " ");
    strcat(result, "/");
    for (int i = 1; i <= (n - 1) * 2; i++)
      strcat(result, "_");
    strcat(result, "\\\n");
  }
  return result;
}
