/*
6 kyu
Write Number in Expanded Form
https://www.codewars.com/kata/5842df8ccbd22792a4000245
*/

#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

char* expandedForm(char string[512], ull n) {
  int notfirst = 0;
  char buf[21];
  char* zeros = "00000000000000000000";
  sprintf(buf, "%llu", n);
  *string = '\0';
  int len = strlen(buf) - 1;
  char* p = buf;
  while (*p) {
    if (*p != '0') {
      if (notfirst)
        strcat(string, " + ");
      strncat(string, p, 1);
      strncat(string, zeros, len);
      notfirst = 1;
    }
    len--;
    p++;
  }
  return string;
}
