/*
6 kyu
Determine the date by the day number
https://www.codewars.com/kata/602afedfd4a64d0008eb4e6e
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_day(int day, bool is_leap);

static void do_test(int day, bool is_leap, const char* expected) {
  char* actual = get_day(day, is_leap);
  printf("Day number: %d, leap year: %s, expected: %s, actual: %s -> %s\n", day,
         is_leap ? "true" : "false", expected, actual,
         strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  int d[] = {15, 41, 59, 60, 60, 365, 366};
  bool b[] = {false, false, false, false, true, false, true};
  char* e[] = {"January, 15",  "February, 10", "February, 28", "March, 1",
               "February, 29", "December, 31", "December, 31"};
  for (int i = 0; i < 7; i++)
    do_test(d[i], b[i], e[i]);
  return 0;
}
