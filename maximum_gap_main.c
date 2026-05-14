/*
7 kyu
Maximum Gap
https://www.codewars.com/kata/5a7893ef0025e9eb50000013
*/

#include <stddef.h>
#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixedTest(array, expected) doTest(ARR_LEN(array), array, expected)

unsigned maxGap(const int numbers[], unsigned count);

static void printArray(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == (length - 1)) ? "" : ", ");
  printf(" }");
}

static void doTest(size_t count, const int numbers[count], unsigned expected) {
  unsigned actual = maxGap(numbers, count);
  printf("Array = ");
  printArray(count, numbers);
  printf("\nExpected = %u, actual = %u -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixedTest(((int[]){13, 10, 2, 9, 5}), 4);
  fixedTest(((int[]){13, 3, 5}), 8);
  fixedTest(((int[]){24, 299, 131, 14, 26, 25}), 168);
  fixedTest(((int[]){-3, -27, -4, -2}), 23);
  fixedTest(((int[]){-7, -42, -809, -14, -12}), 767);
  fixedTest(((int[]){12, -5, -7, 0, 290}), 278);
  fixedTest(((int[]){-54, 37, 0, 64, -15, 640, 0}), 576);
  return 0;
}
