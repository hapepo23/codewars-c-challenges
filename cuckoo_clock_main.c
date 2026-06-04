/*
6 kyu
Cuckoo Clock
https://www.codewars.com/kata/656e4602ee72af0017e37e82
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cuckoo_clock(const char* initial_time, int n, char* output_time);

static void do_test(char* initial_time, int n, char* expected) {
  char* actual = malloc(6);
  cuckoo_clock(initial_time, n, actual);
  printf("Initial time: %s, n: %d, expected: %s, actual: %s -> %s\n",
         initial_time, n, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("07:22", 1, "07:30");
  do_test("12:22", 2, "12:45");
  do_test("01:30", 2, "01:45");
  do_test("04:01", 10, "05:30");
  do_test("03:38", 19, "06:00");
  do_test("10:00", 1, "10:00");
  do_test("10:00", 10, "10:00");
  do_test("10:00", 11, "10:15");
  do_test("10:00", 13, "10:45");
  do_test("10:00", 20, "11:00");
  do_test("12:30", 1, "12:30");
  do_test("12:30", 2, "12:45");
  do_test("12:30", 3, "01:00");
  do_test("12:30", 4, "01:15");
  do_test("09:53", 50, "02:30");
  do_test("08:17", 113, "08:00");
  do_test("08:17", 114, "08:15");
  do_test("08:17", 115, "08:30");
  do_test("08:17", 150, "11:00");
  do_test("08:17", 200, "05:45");
  return 0;
}
