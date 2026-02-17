/*
7 kyu
Credit Card Mask
https://www.codewars.com/kata/5412509bd436bd33920011bc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maskify(char* masked, const char* string);

static void do_test(const char* string, const char* expected) {
  size_t size = strlen(string) + 1;
  char* user_string = memset(malloc(size), '@', size);
  char* actual = maskify(user_string, string);
  printf("For string: \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", string,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test("4556364607935616", "############5616");
  do_test("64607935616", "#######5616");
  do_test("12345", "#2345");
  do_test("1234", "1234");
  do_test("123", "123");
  do_test("12", "12");
  do_test("1", "1");
  do_test("", "");
  do_test("Skippy", "##ippy");
  do_test("Nananananananananananananananana Batman!",
          "####################################man!");
  return 0;
}
