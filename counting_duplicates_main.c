/*
6 kyu
Counting Duplicates
https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1
*/

#include <stddef.h>
#include <stdio.h>

size_t duplicate_count(const char* text);

static void do_test(const char* text, size_t expected) {
  size_t submitted = duplicate_count(text);
  printf("Text: \"%s\", submitted: %zu, expected: %zu -> %s\n", text, submitted,
         expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("abcde", 0);
  do_test("abcdea", 1);
  do_test("indivisibility", 1);
  do_test("AaBbCc11223344556677889900ZzYyXx", 16);
  return 0;
}
