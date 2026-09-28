/*
6 kyu
TGI Friday!!
https://www.codewars.com/kata/5a0d6d8c6975982b5b000383
*/

static int day_of_week(int y, int m, int d) {
  /* y > 1752; result 0 = Sunday, 1 = Monday, etc. */
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  if (m < 3) {
    y -= 1;
  }
  return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

static int days_in_month(int y, int m) {
  static int d[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = d[m - 1];
  if (m == 2) {
    if (y % 400 == 0)
      days = 29;
    else if (y % 100 == 0)
      days = 28;
    else if (y % 4 == 0)
      days = 29;
    else
      days = 28;
  }
  return days;
}

int count_fridays(int year_start, int year_end) {
  int result = 0;
  for (int y = year_start; y <= year_end; y++)
    for (int m = 1; m <= 12; m++)
      if (day_of_week(y, m, days_in_month(y, m)) == 5)
        result++;
  return result;
}
