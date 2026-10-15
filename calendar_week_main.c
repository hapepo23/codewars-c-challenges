/*
6 kyu
Calendar Week
https://www.codewars.com/kata/5c2bedd7eb9aa95abe14d0ed
*/

#include <stdio.h>

unsigned get_calendar_week(const char yyyy_mm_dd[11]);

static void do_test(const char* date, unsigned expected) {
  unsigned actual = get_calendar_week(date);
  printf("Date = \"%s\", expected = %u, actual = %u -> %s\n", date, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("2017-01-01", 52);
  do_test("2018-12-24", 52);
  do_test("2018-12-31", 1);
  do_test("2019-01-01", 1);
  do_test("2016-02-29", 9);
  do_test("2015-12-29", 53);
  do_test("2024-12-31", 1);
  do_test("2025-01-05", 1);
  do_test("2025-01-06", 2);
  do_test("2026-10-15", 42);
  return 0;
}
