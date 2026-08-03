/*
7 kyu
Love vs friendship
https://www.codewars.com/kata/59706036f6e5d1e22d000016
*/

#include <stdio.h>

int word_score(const char* word);

static void do_test(const char* word, int expected) {
  int actual = word_score(word);
  printf("Word: %s, actual: %d, expected: %d -> %s\n", word, actual, expected,
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("love", 54);
  do_test("friendship", 108);
  do_test("attitude", 100);
  do_test("friends", 75);
  do_test("family", 66);
  do_test("selfness", 99);
  do_test("knowledge", 96);
  return 0;
}
