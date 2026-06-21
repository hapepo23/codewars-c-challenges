/*
8 kyu
Was the package received before it was sent?
https://www.codewars.com/kata/6707688c0f597511f6649270
*/

#include <stdbool.h>
#include <stdio.h>

bool was_package_received_yesterday(int tz_from,
                                    int tz_to,
                                    int start,
                                    int duration);

static void do_test(int tz_from,
                    int tz_to,
                    int start,
                    int duration,
                    bool expected) {
  bool actual = was_package_received_yesterday(tz_from, tz_to, start, duration);
  printf(
      "TZ-from = %d, TZ-to = %d, start = %d, duration = %d, actual = %s, "
      "expected = %s -> %s\n",
      tz_from, tz_to, start, duration, actual ? "true" : "false",
      expected ? "true" : "false", expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(0, 0, 0, 0, false);
  do_test(1, 1, 0, 1, false);
  do_test(-11, -11, 12, 8, false);
  do_test(1, 5, 6, 3, false);
  do_test(-11, -8, 3, 12, false);
  do_test(7, 1, 5, 0, true);
  do_test(7, -3, 5, 3, true);
  do_test(7, 1, 5, 6, false);
  do_test(7, -3, 5, 8, false);
  return 0;
}
