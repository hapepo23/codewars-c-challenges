/*
7 kyu
Smart Log Formatter
https://www.codewars.com/kata/6ab3da4db0d8c965cd93923e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* smart_log_formatter(char* logs);

static void do_test(char* logs, char* expected) {
  char* actual = smart_log_formatter(logs);
  printf("Logs =\n%s\nExpected =\n%s\nActual =\n%s\n-> %s\n\n", logs, expected,
         actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test(
      "ERROR Disk failure\n"
      "ERROR Disk failure\n"
      "INFO User login",
      "ERROR Disk failure (x2)\n"
      "INFO User login");
  do_test(
      "INFO Connected\n"
      "WARNING Low battery\n"
      "INFO Connected",
      "INFO Connected\n"
      "WARNING Low battery\n"
      "INFO Connected");
  do_test("", "");
  return 0;
}
