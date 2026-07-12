/*
6 kyu
Determine the date by the day number
https://www.codewars.com/kata/602afedfd4a64d0008eb4e6e
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* get_day(int day, bool is_leap) {
  char* mon[12] = {"January",   "February", "March",    "April",
                   "May",       "June",     "July",     "August",
                   "September", "October",  "November", "December"};
  int len[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
  int l = is_leap ? 1 : 0;
  int m = 0;
  int d = day;
  while (d > len[l][m]) {
    d -= len[l][m];
    m++;
  }
  char* result = calloc(14, sizeof(char));
  sprintf(result, "%s, %d", mon[m], d);
  return result;
}
