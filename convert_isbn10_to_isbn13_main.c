/*
6 kyu
Convert ISBN-10 to ISBN-13
https://www.codewars.com/kata/61ce25e92ca4fb000f689fb0
*/

#include <stdio.h>
#include <string.h>

char* ISBN_converter(char* ISBN_13, const char* ISBN_10);

static void do_test(const char* ISBN_10, const char* ISBN_13) {
  char user_string[64];
  memset(user_string, '@', sizeof user_string);
  char* actual = ISBN_converter(user_string, ISBN_10);
  printf("For ISBN-10: %s, expected ISBN-13: %s, actual: %s -> %s\n", ISBN_10,
         ISBN_13, actual, strcmp(ISBN_13, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("1-85326-158-0", "978-1-85326-158-9");
  do_test("0-14-143951-3", "978-0-14-143951-8");
  do_test("0-02-346450-X", "978-0-02-346450-8");
  do_test("963-14-2164-3", "978-963-14-2164-4");
  do_test("1-7982-0894-6", "978-1-7982-0894-6");
  do_test("84429-2-841-X", "978-84429-2-841-0");
  return 0;
}
