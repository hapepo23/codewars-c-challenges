/*
7 kyu
Combining Ratios
https://www.codewars.com/kata/69e3d400196a47ceacde554f
*/

#include <stdio.h>
#include <string.h>

void merge_ratios(const char* ratio1, const char* ratio2, char* result);

static void do_test(const char* ratio1,
                    const char* ratio2,
                    const char* expected) {
  char submitted[strlen(expected) + 1];
  sprintf(submitted, "??");
  merge_ratios(ratio1, ratio2, submitted);
  printf(
      "ratio1 = \"%s\", ratio2 = \"%s\", actual: \"%s\", expected: \"%s\" -> "
      "%s\n",
      ratio1, ratio2, submitted, expected,
      strcmp(submitted, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("12:4", "3:7", "9:3:7");
  do_test("64:32", "64:14", "64:32:7");
  do_test("6937:3221", "7:108", "48559:22547:347868");
  do_test("74287:28018", "73564:39389", "2732424434:1030558076:551800501");
  return 0;
}
