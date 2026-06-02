/*
6 kyu
Telepathy
https://www.codewars.com/kata/64ad571aa33413003e712168
*/

#include <stdio.h>

unsigned magic_show(const char* ans);

static void do_test(const unsigned expected, const char* ans) {
  unsigned actual = magic_show(ans);
  printf("For answers \"%s\": expected %u, received %u -> %s\n", ans, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(47,
          "| Card 1: Yes | Card 2: Yes | Card 3: Yes | Card 4: Yes | Card 5: "
          "No | Card 6: Yes |");
  do_test(46,
          "| Card 1: No | Card 2: Yes | Card 3: Yes | Card 4: Yes | Card 5: No "
          "| Card 6: Yes |");
  do_test(55,
          "| Card 1: Yes | Card 2: Yes | Card 3: Yes | Card 4: No | Card 5: "
          "Yes | Card 6: Yes |");
  do_test(38,
          "| Card 1: No | Card 2: Yes | Card 3: Yes | Card 4: No | Card 5: No "
          "| Card 6: Yes |");
  return 0;
}
