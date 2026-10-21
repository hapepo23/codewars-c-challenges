/*
5 kyu
A Brave New Wordle
https://www.codewars.com/kata/62013b174c72240016600e60
*/

#include <stdio.h>
#include <string.h>

void wordle(char hints[6], const char guess[6], const char solution[6]);

static void do_test(const char guess[6],
                    const char solution[6],
                    const char hints[6]) {
  char actual[6];
  memset(actual, '@', sizeof actual);
  wordle(actual, guess, solution);
  printf(
      "Guess    = \"%s\"\nSolution = \"%s\"\nExpected = \"%s\"\nActual   = "
      "\"%s\"\n-> %s\n\n",
      guess, solution, hints, actual,
      strcmp(hints, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("paste", "world", "bbbbb");
  do_test("abcde", "ecdba", "yyyyy");
  do_test("world", "world", "ggggg");
  do_test("blows", "world", "byyyb");
  do_test("bleed", "world", "bybbg");
  do_test("reads", "sales", "byybg");
  do_test("sails", "sales", "ggbyg");
  do_test("aaaaa", "aaabb", "gggbb");
  do_test("aaaaa", "aabbb", "ggbbb");
  do_test("aaaaa", "abbbb", "gbbbb");
  do_test("xbbbb", "babbb", "byggg");
  do_test("xxxxz", "yyyyx", "ybbbb");
  do_test("wooer", "ivory", "bbgby");
  return 0;
}
