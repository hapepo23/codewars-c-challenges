/*
5 kyu
Sort - one, three, two
https://www.codewars.com/kata/56f4ff45af5b1f8cd100067d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int* sort(const int* array, int length);

static void print_array(const char* text,
                        size_t length,
                        const int array[length]) {
  printf("%s ... { ", text);
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }\n");
}

static void doTest(int length, const int* expected, const int* array) {
  int* actual = sort(array, length);
  print_array("Array   ", length, array);
  print_array("Actual  ", length, actual);
  print_array("Expected", length, expected);
  printf("%s\n\n",
         memcmp(actual, expected, length * sizeof(int)) == 0 ? "OK" : "FAIL");
  if (actual)
    free(actual);
}

int main(void) {
  {
    int expected[] = {8, 8, 9, 9, 10, 10}, array[] = {8, 8, 9, 9, 10, 10};
    doTest(ARRAY_SIZE(array), expected, array);
  }
  {
    int expected[] = {4, 1, 3, 2}, array[] = {1, 2, 3, 4};
    doTest(ARRAY_SIZE(array), expected, array);
  }
  {
    int expected[] = {9, 999, 99}, array[] = {9, 99, 999};
    doTest(ARRAY_SIZE(array), expected, array);
  }
  {
    int expected[] = {8, 18, 11, 15, 5,  4,  14, 9,  19, 1,
                      7, 17, 6,  16, 10, 13, 3,  12, 20, 2},
        array[] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    doTest(ARRAY_SIZE(array), expected, array);
  }
  return 0;
}
