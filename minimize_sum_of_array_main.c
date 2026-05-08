/*
7 kyu
Minimize Sum Of Array
https://www.codewars.com/kata/5a523566b3bfa84c2e00010b
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixedTest(array, expected) doTest(ARR_LEN(array), array, expected)

int minSum(const int array[], unsigned length);

static void printArray(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == (length - 1)) ? "" : ", ");
  printf(" }\n");
}

static void doTest(size_t length, const int array[length], int expected) {
  int actual = minSum(array, length);
  printf("Array = ");
  printArray(length, array);
  printf("Expected: %d, actual: %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixedTest(((int[]){5, 4, 2, 3}), 22);
  fixedTest(((int[]){12, 6, 10, 26, 3, 24}), 342);
  fixedTest(((int[]){9, 2, 8, 7, 5, 4, 0, 6}), 74);
  return 0;
}
