/*
6 kyu
Unix Time Stamp
https://www.codewars.com/kata/66c0c135a364f5b9e286c7b5
*/

#include <time.h>

time_t unix_timestamp(const unsigned date[6]) {
  /* date = [Year, Month, Day, Hour, Minute, Second] */
  unsigned y = date[0] - 1970;
  unsigned m = date[1];
  unsigned d = date[2];
  unsigned days = y * 365 + (y + 1) / 4 - (y + 69) / 100 + (y + 369) / 400;
  static const unsigned mdays[] = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
  for (unsigned i = 1; i < m; i++)
    days += mdays[i - 1];
  if (m > 2 && (date[0] % 4 == 0 && (date[0] % 100 != 0 || date[0] % 400 == 0)))
    days++;
  days += d - 1;
  return (time_t)days * 86400 + date[3] * 3600 + date[4] * 60 + date[5];
}
