/*
6 kyu
Detect Pangram
https://www.codewars.com/kata/545cedaa9943f7fe7b000048
*/

#include <stdbool.h>
#include <stdio.h>

bool is_pangram(const char* str_in);

static void do_test(const char* str_in, bool expected) {
  bool actual = is_pangram(str_in);
  printf("String: \"%s\", expected: %s, actual = %s -> %s\n", str_in,
         expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("The quick, brown fox jumps over the lazy dog!", true);
  do_test("The quick, brown fox jumped over the lazy dog!", false);
  do_test("abc DEF ghi-JKL,mno:PQR.stu.VWX#z..", false);
  do_test("abc DEF ghi-JKL,mno:PQR.stu.VWXyz..", true);
  return 0;
}
