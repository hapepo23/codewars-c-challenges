/*
6 kyu
Ascend, Descend, Repeat?
https://www.codewars.com/kata/62ca07aaedc75c88fb95ee2f
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ascend_descend(size_t length,
                     char string[length + 1],
                     int minimum,
                     int maximum);

static void do_test(size_t length,
                    int minimum,
                    int maximum,
                    const char expected[length + 1]) {
  char* user_string = malloc(length + 1);
  memset(user_string, '@', length + 1);
  char* actual = ascend_descend(length, user_string, minimum, maximum);
  printf(
      "Length = %zu, minimum = %d, maximum = %d\n"
      "expected: \"%s\"\n"
      "actual  : \"%s\"\n"
      "-> %s\n\n",
      length, minimum, maximum, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test(5, 1, 3, "12321");
  do_test(14, 0, 2, "01210121012101");
  do_test(11, 5, 9, "56789876567");
  do_test(15, 9, 15, "910111213141514");
  do_test(6, 10, 14, "101112");
  do_test(10, 1, 1, "1111111111");
  do_test(1, -5, -4, "-");
  do_test(1, -1, 0, "-");
  do_test(25, -9, -3, "-9-8-7-6-5-4-3-4-5-6-7-8-");
  do_test(0, 1, 2, "");
  do_test(14, -4, -5, "");
  do_test(5, 10, 12, "10111");
  do_test(6, 10, 12, "101112");
  do_test(7, 10, 12, "1011121");
  do_test(8, 10, 12, "10111211");
  do_test(9, 10, 12, "101112111");
  do_test(10, 10, 12, "1011121110");
  do_test(11, 10, 12, "10111211101");
  return 0;
}
