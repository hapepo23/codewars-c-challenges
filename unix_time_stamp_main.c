/*
6 kyu
Unix Time Stamp
https://www.codewars.com/kata/66c0c135a364f5b9e286c7b5
*/

#include <stdio.h>
#include <time.h>

time_t unix_timestamp(const unsigned date[6]);

static void do_test(const unsigned date[6], time_t expected) {
  const time_t actual = unix_timestamp(date);
  printf(
      "Date = { %u, %u, %u, %u, %u, %u }, expected = %lld, actual = %lld -> "
      "%s\n",
      date[0], date[1], date[2], date[3], date[4], date[5], (long long)expected,
      (long long)actual,
      (long long)expected == (long long)actual ? "OK" : "FAIL");
}

int main(void) {
  do_test((unsigned[6]){1970, 1, 1, 0, 0, 0}, 0);
  do_test((unsigned[6]){2001, 9, 9, 1, 46, 40}, 1000000000);
  do_test((unsigned[6]){9999, 12, 31, 23, 59, 59}, 253402300799);
  do_test((unsigned[6]){2900, 3, 1, 0, 0, 0}, 29353104000);
  do_test((unsigned[6]){9100, 1, 1, 0, 0, 0}, 225001065600);
  do_test((unsigned[6]){6400, 3, 1, 0, 0, 0}, 139802457600);
  do_test((unsigned[6]){8000, 1, 1, 0, 0, 0}, 190288396800);
  do_test((unsigned[6]){2345, 6, 7, 8, 9, 10}, 11847456550);
  do_test((unsigned[6]){5555, 5, 5, 5, 5, 5}, 113142373505);
  return 0;
}
