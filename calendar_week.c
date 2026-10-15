/*
6 kyu
Calendar Week
https://www.codewars.com/kata/5c2bedd7eb9aa95abe14d0ed
*/

#include <stdio.h>

unsigned get_calendar_week(const char yyyy_mm_dd[11]) {
  int y, m, d;
  sscanf(yyyy_mm_dd, "%4d-%2d-%2d", &y, &m, &d);
  static const int days[] = {0,   31,  59,  90,  120, 151,
                             181, 212, 243, 273, 304, 334};
  int doy = days[m - 1] + d;
  if (m > 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
    doy++;
  /* Monday = 1, ..., Sunday = 7 */
  int jan1 = (y + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400) % 7;
  jan1 = jan1 ? jan1 : 7;
  int weekday = (jan1 + doy - 1) % 7;
  weekday = weekday ? weekday : 7;
  int week = (doy - weekday + 10) / 7;
  if (week < 1) {
    /* Last ISO week of the previous year */
    int prev = y - 1;
    int prevjan1 =
        (prev + (prev - 1) / 4 - (prev - 1) / 100 + (prev - 1) / 400) % 7;
    return prevjan1 == 4 ||
                   (prevjan1 == 3 &&
                    (prev % 4 == 0 && (prev % 100 != 0 || prev % 400 == 0)))
               ? 53
               : 52;
  }
  if (week == 53) {
    /* Check whether this year actually has week 53 */
    return jan1 == 4 ||
                   (jan1 == 3 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
               ? 53
               : 1;
  }
  return (unsigned)week;
}
