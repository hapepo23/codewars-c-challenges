/*
7 kyu
From A to Z
https://www.codewars.com/kata/6512b3775bf8500baea77663
*/

#include <stdio.h>
#include <string.h>

void letters_range(char letters[27], const char range[4]);

static void do_test(const char range[4], const char* expected) {
  char actual[27] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@";
  letters_range(actual, range);
  printf("For range = \"%s\", expected = \"%s\", actual = \"%s\" -> %s\n",
         range, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("a-z", "abcdefghijklmnopqrstuvwxyz");
  do_test("h-o", "hijklmno");
  do_test("Q-Z", "QRSTUVWXYZ");
  do_test("J-J", "J");
  do_test("a-b", "ab");
  do_test("a-a", "a");
  do_test("g-i", "ghi");
  do_test("H-I", "HI");
  do_test("y-z", "yz");
  do_test("e-k", "efghijk");
  do_test("a-q", "abcdefghijklmnopq");
  do_test("F-O", "FGHIJKLMNO");
  return 0;
}
