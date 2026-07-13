/*
5 kyu
Formula 1 Race
https://www.codewars.com/kata/626d691649cb3c7acd63457b
*/

#include <stdio.h>

int champion_rank(int champion_ID, const char* events);

static void do_test(int champion_ID, const char* events, int expected) {
  int actual = champion_rank(champion_ID, events);
  printf(
      "Champion ID = %d\n"
      "Events      = \"%s\"\n"
      "Expected    = %d\n"
      "Actual      = %d -> %s\n\n",
      champion_ID, events, expected, actual,
      expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(3, "", 3);
  do_test(12, "4 O 3 O", 12);
  do_test(10, "1 I 10 O 2 I", 7);
  do_test(17, "2 O 17 I", -1);
  do_test(
      2,
      "9 O 17 O 9 O 12 O 2 O 12 O 9 O 1 O 5 O 12 O 17 O 20 O 16 O 7 O 2 O 8 O "
      "16 O 14 O 3 O 14 O 11 O 16 O 1 O 13 O 8 O 14 O 5 O 12 O 4 O",
      1);
  return 0;
}
