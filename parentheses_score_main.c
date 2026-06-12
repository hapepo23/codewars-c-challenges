/*
6 kyu
Evaluate the Group of Parentheses
https://www.codewars.com/kata/64b6722493f1050058dc3f98
*/

#include <stdio.h>

int parentheses_score(const char* parentheses);

static void do_test(const char* input, int expected) {
  int actual = parentheses_score(input);
  printf("For parentheses = \"%s\", expected %d, actual %d -> %s\n", input,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("()", 1);
  do_test("(((())))", 8);
  do_test("(()(()))", 6);
  do_test("(()())()", 5);
  do_test("()()(())", 4);
  do_test("()(())", 3);
  do_test("(()()(()(()()()()))(()()()())())", 58);
  do_test("(()()(()(()())()))", 28);
  do_test("((((()()(()(()()()(()()(()()(()))))))(()))()(()()())))", 1580);
  do_test("(()()())", 6);
  return 0;
}
