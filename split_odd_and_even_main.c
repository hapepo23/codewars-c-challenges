/*
6 kyu
T.T.T.17: Split odd and even
https://www.codewars.com/kata/57a2ab1abb994466910003af
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* split_odd_and_even(int value, size_t* pcount);

static void stringify(int* elems, size_t count, char* out) {
  char* end = out;
  end += sprintf(end, "%s", "{ ");
  for (size_t nelem = 0; nelem < count; ++nelem) {
    end += sprintf(end, "%d, ", elems[nelem]);
  }
  end[-2] = ' ';
  end[-1] = '}';
}

static void assert_answer(int value,
                          size_t expectedCount,
                          int expectedAnswer[expectedCount]) {
  size_t actualCount = -1;
  int* actualAnswer = split_odd_and_even(value, &actualCount);
  char strExpectedAnswer[40], strActualAnswer[40];
  stringify(expectedAnswer, expectedCount, strExpectedAnswer);
  stringify(actualAnswer, expectedCount, strActualAnswer);
  printf("Value = %d\n", value);
  printf("Count expected = %zu, actual = %zu -> %s\n", expectedCount,
         actualCount, expectedCount == actualCount ? "OK" : "FAIL");
  printf("Array expected = %s, actual = %s -> %s\n", strExpectedAnswer,
         strActualAnswer,
         strcmp(strExpectedAnswer, strActualAnswer) == 0 ? "OK" : "FAIL");
  puts("");
  free(actualAnswer);
}

int main(void) {
  {
    int value = 123;
    int expected[] = {1, 2, 3};
    assert_answer(value, 3, expected);
  }
  {
    int value = 223;
    int expected[] = {22, 3};
    assert_answer(value, 2, expected);
  }
  {
    int value = 111;
    int expected[] = {111};
    assert_answer(value, 1, expected);
  }
  {
    int value = 13579;
    int expected[] = {13579};
    assert_answer(value, 1, expected);
  }
  {
    int value = 2468642;
    int expected[] = {2468642};
    assert_answer(value, 1, expected);
  }
  {
    int value = 135246;
    int expected[] = {135, 246};
    assert_answer(value, 2, expected);
  }
  {
    int value = 123456;
    int expected[] = {1, 2, 3, 4, 5, 6};
    assert_answer(value, 6, expected);
  }
  {
    int value = 8123456;
    int expected[] = {8, 1, 2, 3, 4, 5, 6};
    assert_answer(value, 7, expected);
  }
  {
    int value = 82123456;
    int expected[] = {82, 1, 2, 3, 4, 5, 6};
    assert_answer(value, 7, expected);
  }
  {
    int value = 88123456;
    int expected[] = {88, 1, 2, 3, 4, 5, 6};
    assert_answer(value, 7, expected);
  }
  return 0;
}
