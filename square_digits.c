/*
7 kyu
Square Every Digit
https://www.codewars.com/kata/546e2562b03326a88e000020
*/

#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

ull square_digits(unsigned n) {
  char sq[10][3] = {"0", "1", "4", "9", "16", "25", "36", "49", "64", "81"};
  char buf[11], rbuf[20] = {'\0'};
  char* p = buf;
  ull result;
  sprintf(buf, "%u", n);
  while (*p) {
    strcat(rbuf, sq[*p - '0']);
    p++;
  }
  sscanf(rbuf, "%llu", &result);
  return result;
}
