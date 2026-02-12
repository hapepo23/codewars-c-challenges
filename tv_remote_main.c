/*
7 kyu
TV Remote
https://www.codewars.com/kata/5a5032f4fd56cb958e00007a
*/

#include <stdio.h>

int tv_remote(const char* word);

static void do_test(const char* word, int expected) {
  int actual = tv_remote(word);
  printf("Word: \"%s\", expected: %d, actual: %d -> %s\n", word, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("codewars", 36);
  do_test("does", 16);
  do_test("your", 23);
  do_test("solution", 33);
  do_test("work", 20);
  do_test("for", 12);
  do_test("these", 27);
  do_test("words", 25);
  do_test("/x_7ot1189azyq1", 76);
  do_test("abcde123654jihgfklmno7890@.tsrqpuvwxyz_/", 79);
  do_test("aaaabbbb", 9);
  return 0;
}
