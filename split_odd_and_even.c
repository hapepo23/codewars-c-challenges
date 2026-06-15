/*
6 kyu
T.T.T.17: Split odd and even
https://www.codewars.com/kata/57a2ab1abb994466910003af
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* split_odd_and_even(int value, size_t* pcount) {
  char num[11], buf[11];
  char* p = num + 1;
  char* last = num;
  sprintf(num, "%d", value);
  size_t numlen = strlen(num);
  int* result = calloc(numlen, sizeof(int));
  size_t resultpos = 0;
  while (*p) {
    if ((*p % 2) != (*(p - 1) % 2)) {
      strncpy(buf, last, p - last);
      buf[p - last] = '\0';
      result[resultpos++] = atoi(buf);
      last = p;
    }
    p++;
  }
  result[resultpos] = atoi(last);
  *pcount = resultpos + 1;
  return result;
}
