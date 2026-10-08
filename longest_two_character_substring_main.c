/*
6 kyu
Longest 2-character substring
https://www.codewars.com/kata/55bc0c54147a98798f00003e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substring(const char* string);

static void do_test(const char* string, const char* expected) {
  char* const actual = substring(string);
  printf("For string: \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", string,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("", "");
  do_test("a", "a");
  do_test("aa", "aa");
  do_test("aaa", "aaa");
  do_test("ab", "ab");
  do_test("aba", "aba");
  do_test("abc", "ab");
  do_test("abcba", "bcb");
  do_test("bbacc", "bba");
  do_test("ccddeeff", "ccdd");
  do_test("112233", "1122");
  do_test("aabb112222ccccdef", "2222cccc");
  do_test("aabacacacacacacac", "acacacacacacac");
  do_test("11111", "11111");
  return 0;
}
