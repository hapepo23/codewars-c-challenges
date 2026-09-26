/*
7 kyu
Age in days
https://www.codewars.com/kata/5803753aab6c2099e600000e
*/

#include <stdio.h>
#include <time.h>

int gregorian_calendar_to_jd(int y, int m, int d) {
  y += 8000;
  if (m < 3) {
    y--;
    m += 12;
  }
  return (y * 365) + (y / 4) - (y / 100) + (y / 400) - 1200820 +
         (m * 153 + 3) / 5 - 92 + d - 1;
}

void age_in_days(char age[64], int year, int month, int day) {
  time_t now = time(NULL);
  struct tm* t = localtime(&now);
  int yearnow = t->tm_year + 1900;
  int monthnow = t->tm_mon + 1;
  int daynow = t->tm_mday;
  int diff = gregorian_calendar_to_jd(yearnow, monthnow, daynow) -
             gregorian_calendar_to_jd(year, month, day);
  sprintf(age, "You are %d day%s old", diff, diff == 1 ? "" : "s");
}
