/*
6 kyu
Valid Phone Number
https://www.codewars.com/kata/525f47c79f2f25a4db000025
*/

#include <stdbool.h>
#include <stdio.h>

bool valid_phone_number(const char* number);

static void do_test(const char* number, bool expected) {
  bool actual = valid_phone_number(number);
  printf("Number: %s, actual: %s, expected: %s -> %s\n", number,
         actual ? "true" : "false", expected ? "true" : "false",
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("(123) 456-7890", true);
  do_test("(1111)555 2345", false);
  do_test("(098) 123 4567", false);
  do_test("(123)456-7890", false);
  do_test("abc(123)456-7890", false);
  do_test("(123)456-7890abc", false);
  do_test("abc(123)456-7890abc", false);
  do_test("abc(123) 456-7890", false);
  do_test("(123) 456-7890abc", false);
  do_test("abc(123) 456-7890abc", false);
  return 0;
}
