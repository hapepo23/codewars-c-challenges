/*
7 kyu
How Many Lonely Letters?
https://www.codewars.com/kata/69cda5b85599f307742ce70a
*/

#include <stdio.h>

unsigned count_lonely_letters(const char* text);

static void do_test(const char* string, unsigned expected) {
  unsigned submitted = count_lonely_letters(string);
  printf("string = \"%s\", submitted = %u, expected = %u -> %s\n", string,
         submitted, expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("ad", 2);
  do_test("abc", 0);
  do_test("Hello, World!", 3);
  do_test("A-dA", 1);
  do_test("zz", 0);
  do_test("", 0);
  do_test("123 !!!", 0);
  do_test("bdfhj", 5);
  do_test("a", 1);
  do_test("z", 1);
  do_test("`a", 1);
  do_test("z{", 1);
  do_test("A@", 1);
  do_test("Z[", 1);
  do_test("Aa", 0);
  do_test("B!d", 2);
  do_test("C-c?e", 1);
  do_test("38iYHn21TeQf", 4);
  do_test("c5AB.!mDG8xK95rmTOj", 5);
}
