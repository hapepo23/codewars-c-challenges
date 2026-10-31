/*
7 kyu
Sum of integers in string
https://www.codewars.com/kata/598f76a44f613e0e0b000026
*/

#include <stdio.h>

unsigned sum_string_integers(const char* string);

static void do_test(const char* string, unsigned expected) {
  unsigned actual = sum_string_integers(string);
  printf("String = \"%s\", expected = %u, actual = %u -> %s\n", string,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("abc0777def", 777);
  do_test("0x10", 10);
  do_test("0xFF", 0);
  do_test("1e8", 9);
  do_test("", 0);
  do_test("12.4", 16);
  do_test("15-15", 30);
  do_test("150x15- 30-0050", 245);
  do_test("h3ll0w0rld", 3);
  do_test("2 + 3 = ", 5);
  do_test(
      "Our company made approximately 1 million in gross revenue last quarter.",
      1);
  do_test("The Great Depression lasted from 1929 to 1939.", 3868);
  do_test("Dogs are our best friends.", 0);
  do_test("C4t5 are 4m4z1ng.", 18);
  do_test("The30quick20brown10f0x1203jumps914ov3r1349the102l4zy dog", 3635);
  return 0;
}
