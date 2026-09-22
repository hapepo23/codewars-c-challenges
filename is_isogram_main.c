/*
6 kyu
Is it an isogram?
https://www.codewars.com/kata/586d79182e8d9cfaba0000f1
*/

#include <stdbool.h>
#include <stdio.h>

bool is_isogram(const char* word);

static void do_test(const char* word, bool expected) {
  const char* const bools[2] = {"false", "true"};
  const bool actual = is_isogram(word);
  printf("Word = \"%s\", expected = %s, actual = %s -> %s\n", word,
         bools[expected], bools[actual], expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("eeen", false);
  do_test("a", true);
  do_test("aaa", true);
  do_test("aaab", false);
  do_test("Dermatoglyphics", true);
  do_test("isogram", true);
  do_test("eleven", false);
  do_test("moOse", false);
  do_test("isIsogram", false);
  do_test("", false);
  do_test("-.-", false);
  do_test("--##", false);
  do_test("isogram", true);
  do_test("subdermatoglyphic", true);
  do_test("Alphabet", false);
  do_test("thumbscrew-japingly", true);
  do_test("Hjelmqvist-Gryb-Zock-Pfund-Wax", true);
  do_test("Emily Jung Schwartzkopf", true);
  do_test("aabbccddeeffgg", true);
  return 0;
}
