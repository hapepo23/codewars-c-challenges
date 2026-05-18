/*
6 kyu
Word a10n (abbreviation)
https://www.codewars.com/kata/5375f921003bf62192000746
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* abbreviate(const char* str);

static void do_test(const char* str, const char* expected) {
  char* actual = abbreviate(str);
  printf("String = \"%s\"\nActual = \"%s\"\nExpected = \"%s\"\n-> %s\n\n", str,
         actual, expected, strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("The International accessibility elephant-ride",
          "The I11l a11y e6t-r2e");
  do_test("internationalization", "i18n");
  do_test("accessibility", "a11y");
  do_test("Accessibility", "A11y");
  do_test("elephant-ride", "e6t-r2e");
  return 0;
}
