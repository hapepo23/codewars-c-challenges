/*
6 kyu
Derivatives of type x^n
https://www.codewars.com/kata/55e2de13b668981d3300003d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* differentiate(char* derivative, const char* function) {
  char* px = strchr(function, 'x');
  if (px == NULL) {
    strcpy(derivative, "0");
  } else {
    size_t lfactor = px - function;
    char buf[lfactor + 1];
    strncpy(buf, function, lfactor);
    buf[lfactor] = '\0';
    int ifactor = 1, ex = 1;
    if (strcmp(buf, "-") == 0)
      ifactor = -1;
    else if (*buf)
      ifactor = atoi(buf);
    if (*(px + 1) == '^')
      ex = atoi(px + 2);
    ifactor = ifactor * ex;
    ex--;
    if (ex == 0)
      sprintf(derivative, "%d", ifactor);
    else {
      if (ifactor == 1)
        strcpy(derivative, "x");
      else if (ifactor == -1)
        strcpy(derivative, "-x");
      else
        sprintf(derivative, "%dx", ifactor);
      if (ex != 1)
        sprintf(derivative + strlen(derivative), "^%d", ex);
    }
  }
  return derivative;
}
