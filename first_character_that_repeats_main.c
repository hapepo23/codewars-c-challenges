/*
6 kyu
First character that repeats
https://www.codewars.com/kata/54f9f4d7c41722304e000bbb
*/

#include <stdio.h>

char first_duplicate(const char* string);

static void do_test(const char* input, char expected) {
  const char actual = first_duplicate(input);
  printf("For string = \"%s\", expected = '%s', actual = '%s' -> %s\n", input,
         expected ? (char[]){expected, '\0'} : "\\0",
         actual ? (char[]){actual, '\0'} : "\\0",
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("translator", 't');
  do_test("tt", 't');
  do_test("t", '\0');
  do_test("", '\0');
  do_test("tweet", 't');
  do_test("Ode to Joy", ' ');
  do_test("ode to joy", 'o');
  do_test("bar", '\0');
  do_test("123123", '1');
  do_test("!@#$!@#$", '!');
  do_test("1a2b3a3c", 'a');
  return 0;
}
