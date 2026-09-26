/*
7 kyu
Age in days
https://www.codewars.com/kata/5803753aab6c2099e600000e
*/

#include <stdio.h>

void age_in_days(char age[64], int year, int month, int day);

static void do_test(int year, int month, int day) {
  char age[64] = "";
  age_in_days(age, year, month, day);
  printf("Date = %d-%d-%d, age = %s\n", year, month, day, age);
}

int main(void) {
  do_test(2014, 3, 27);
  do_test(1970, 1, 1);
  do_test(2020, 3, 3);
  do_test(2026, 9, 26);
  do_test(2026, 9, 25);
  do_test(2026, 9, 1);
  return 0;
}
