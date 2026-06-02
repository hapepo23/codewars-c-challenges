/*
6 kyu
The lost beginning
https://www.codewars.com/kata/659af96994b858db10e1675f
*/

#include <stdio.h>
#include <string.h>

int find(const char* s);

static void do_test(const char* s, const int expected) {
  int actual = find(s);
  const char* elipses = strlen(s) <= 20 ? "" : "...";
  printf("For string \"%.20s%s\": expected %d, received %d -> %s\n", s, elipses,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("1", 1);
  do_test("9", 9);
  do_test("10", 10);
  do_test("99100102", 99100102);
  do_test("72637236", 72637236);
  do_test("431243", 431243);
  do_test("577495", 577495);
  do_test("12", 1);
  do_test("123456789101112131415", 1);
  do_test("91011", 9);
  do_test("1112", 11);
  do_test("17181920", 17);
  do_test("99100", 99);
  do_test("99910001001", 999);
  return 0;
}
