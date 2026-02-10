/*
7 kyu
Get the Middle Character
https://www.codewars.com/kata/56747fd5cb988479af000028
*/

#include <stdio.h>
#include <string.h>

char* get_middle(char outp[3], const char* inp);

static void do_test(const char* inp, const char* expected) {
  char outp[3] = {'x', 'x', 'x'};
  char* actual = get_middle(outp, inp);
  printf("Input = \"%s\", expected: \"%s\", actual: \"%s\" -> %s\n", inp,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("test", "es");
  do_test("testing", "t");
  do_test("middle", "dd");
  do_test("A", "A");
  do_test("C lang", "la");
  return 0;
}
