/*
8 kyu
Do you speak "English"?
https://www.codewars.com/kata/58dbdccee5ee8fa2f9000058
*/

#include <stdbool.h>
#include <stdio.h>

bool sp_eng(const char* sentence);

static void do_test(const char* sentence, bool expected) {
  bool actual = sp_eng(sentence);
  printf("Sentence: \"%s\", expected: %s, actual: %s -> %s\n", sentence,
         expected ? "true" : "false", actual ? "true" : "false",
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("eenglish", true);
  do_test("english", true);
  do_test("egnlish", false);
  do_test("engliish", false);
  do_test("ENGLISH", true);
  do_test("", false);
  do_test("EGNlihs", false);
  do_test("English", true);
  do_test("eNgliSh", true);
  do_test("1234egn lis;h", false);
  do_test("1234english ;k", true);
  do_test("1234#$%%eNglish ;k9", true);
  do_test("1234englihs**", false);
  return 0;
}
