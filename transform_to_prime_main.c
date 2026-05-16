/*
6 kyu
Transform To Prime
https://www.codewars.com/kata/5a946d9fba1bb5135100007c
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixedTest(array, expected) doTest(ARR_LEN(array), array, expected)

int minimumNumber(const int numbers[], unsigned count);

static void printArray(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == (length - 1)) ? "" : ", ");
  printf(" }");
}

static void doTest(size_t count, const int numbers[count], int expected) {
  int actual = minimumNumber(numbers, count);
  printf("Array = ");
  printArray(count, numbers);
  printf("\nExpected = %d, actual = %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixedTest(((int[]){3, 1, 2}), 1);
  fixedTest(((int[]){5, 2}), 0);
  fixedTest(((int[]){1, 1, 1}), 0);
  fixedTest(((int[]){2, 12, 8, 4, 6}), 5);
  fixedTest(((int[]){50, 39, 49, 6, 17, 28}), 2);
  return 0;
}
