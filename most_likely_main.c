/*
7 kyu
Most Likely
https://www.codewars.com/kata/56644a421b7c94c622000056
*/

#include <stdbool.h>
#include <stdio.h>

bool most_likely(const char* a, const char* b);

static void tester(const char* a, const char* b, bool expected) {
  bool submitted = most_likely(a, b);
  const char* bs[2] = {"false", "true"};
  printf("a = \"%s\", b = \"%s\", expected: %s, actual: %s -> %s\n", a, b,
         bs[expected], bs[submitted], expected == submitted ? "OK" : "FAIL");
}

int main(void) {
  tester("1:2", "1:3", true);
  tester("1:3", "1:2", false);
  return 0;
}
