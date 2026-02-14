/*
6 kyu
Count characters in your string
https://www.codewars.com/kata/52efefcbcdf57161d4000091
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTS_SIZE 128

void count(const char* string, unsigned counts[COUNTS_SIZE]);

static void do_test(const char* string, const unsigned expected[COUNTS_SIZE]) {
  unsigned submitted[COUNTS_SIZE];
  for (size_t index = 0; index < COUNTS_SIZE; index++) {
    submitted[index] = rand() % 10;
  }
  count(string, submitted);
  char sub_str[22 * COUNTS_SIZE + 1];
  char exp_str[22 * COUNTS_SIZE + 1];
  size_t index = 0;
  size_t position = sprintf(sub_str, "{");
  while (index < COUNTS_SIZE) {
    position += sprintf(sub_str + position, "%u, ", submitted[index]);
    index += 1;
  }
  sprintf(sub_str + position - 2, "}");
  index = 0;
  position = sprintf(exp_str, "{");
  while (index < COUNTS_SIZE) {
    position += sprintf(exp_str + position, "%u, ", expected[index]);
    index += 1;
  }
  sprintf(exp_str + position - 2, "}");
  printf("String = \"%s\"\nSubmitted: %s\nExpected:  %s\n%s\n\n", string,
         sub_str, exp_str, strcmp(sub_str, exp_str) == 0 ? "OK" : "FAIL");
}

int main(void) {
  {
    const unsigned expected[COUNTS_SIZE] = {['a'] = 2, ['b'] = 1};
    do_test("aba", expected);
  }
  {
    const unsigned expected[COUNTS_SIZE] = {0};
    do_test("", expected);
  }
  {
    const unsigned expected[COUNTS_SIZE] = {['a'] = 2};
    do_test("aa", expected);
  }
  {
    const unsigned expected[COUNTS_SIZE] = {['a'] = 2, ['b'] = 2};
    do_test("aabb", expected);
  }
  return 0;
}
