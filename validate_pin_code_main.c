/*
7 kyu
Validate a PIN code
https://www.codewars.com/kata/55f8a9c06c018a0d6e000132
*/

#include <stdbool.h>
#include <stdio.h>

bool validate_pin(const char* pin);

static void do_test(const char* pin, bool expected) {
  bool actual = validate_pin(pin);
  printf("PIN = %s, actual = %s, expected = %s -> %s\n", pin,
         actual ? "true" : "false", expected ? "true" : "false",
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("1", false);
  do_test("12", false);
  do_test("123", false);
  do_test("12345", false);
  do_test("1234567", false);
  do_test("-1234", false);
  do_test("=12345", false);
  do_test("1.234", false);
  do_test("00000000", false);
  do_test("a234", false);
  do_test(".234", false);
  do_test("1234", true);
  do_test("0000", true);
  do_test("1111", true);
  do_test("123456", true);
  do_test("098765", true);
  do_test("000000", true);
  do_test("090909", true);
  return 0;
}
