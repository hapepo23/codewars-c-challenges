/*
6 kyu
How many pages in a book?
https://www.codewars.com/kata/622de76d28bf330057cd6af8
*/

#include <stdio.h>

unsigned amount_of_pages(unsigned summary);

static void do_test(unsigned summary, unsigned expected) {
  unsigned actual = amount_of_pages(summary);
  printf("Summary = %u, actual: %u, expected: %u -> %s\n", summary, actual,
         expected, actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(5, 5);
  do_test(25, 17);
  do_test(1095, 401);
  do_test(185, 97);
  do_test(660, 256);
  return 0;
}
