/*
5 kyu
Parsing goto statements
https://www.codewars.com/kata/591f3a2e4e5471989000013d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* parse(const char* source);

void do_test(const char* source, const char* expected) {
  char* actual = parse(source);
  printf(
      "** Parsing: **\n%s** Expected: **\n%s\n** Actual: **\n%s\n=> %s <=\n\n",
      source, expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test(
      "5 HERE\n"
      "10 IS\n"
      "goto 40\n"
      "20 JUST rAnDoM TEXT\n"
      "30 AND\n"
      "40 MORE RANDOM text\n",
      "HERE IS MORE RANDOM text");
  do_test(
      "1 I am\n"
      "goto 5\n"
      "2 travelling\n"
      "3 down\n"
      "4 the river\n"
      "5 back\n"
      "10 home\n",
      "I am back home");
  do_test(
      "10 Brave\n"
      "goto 40\n"
      "20 scary\n"
      "40 Romans\n"
      "60 to a man!\n",
      "Brave Romans to a man!");
  do_test(
      "goto 10\n"
      "10 Ten\n",
      "Ten");
  do_test(
      "10 Hello\n"
      "20 world!\n",
      "Hello world!");
  do_test(
      "5 VENI\n"
      "10 VIDI\n"
      "20 VICI\n",
      "VENI VIDI VICI");
  do_test(
      "1 Quo usque\n"
      "2 tandem abutere\n"
      "3 patientia\n"
      "5 nostra\n",
      "Quo usque tandem abutere patientia nostra");
  return 0;
}
