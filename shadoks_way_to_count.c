/*
7 kyu
Shadok's way to count
https://www.codewars.com/kata/6b00d45ad1103df1762bded3
*/

#include <limits.h>
#include <math.h>
#include <stdio.h>

void shadok(unsigned number, char* result) {
  static char* dig4words[4] = {"GA", "BU", "ZO", "MEU"};
  unsigned dig4[(int)(log(UINT_MAX) / log(4)) + 1];
  unsigned len = 0;
  do {
    unsigned rem = number % 4;
    dig4[len++] = rem;
    number /= 4;
  } while (number > 0);
  unsigned pos = 0;
  for (int i = len - 1; i >= 0; i--)
    pos += sprintf(result + pos, "%s", dig4words[dig4[i]]);
  *(result + pos) = '\0';
}
