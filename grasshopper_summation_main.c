/*
8 kyu
Grasshopper - Summation
https://www.codewars.com/kata/55d24f55d7dd296eb9000030
*/

#include <stdio.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof *(array))

int summation(int number);

typedef struct Integer_Pair {
  int number;
  int expected;
} pair;

static void do_test(int number, int expected) {
  const int submitted = summation(number);
  printf("Number = %d, submitted: %d, expected: %d -> %s\n", number, submitted,
         expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  const pair tests[] = {{1, 1}, {8, 36}, {100, 5050}};
  for (size_t index = 0; index < ARRAY_LENGTH(tests); index++) {
    const int number = tests[index].number;
    const int expected = tests[index].expected;
    do_test(number, expected);
  }
  return 0;
}
