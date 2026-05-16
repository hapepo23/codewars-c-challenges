/*
7 kyu
Maximum Product
https://www.codewars.com/kata/5a4138acf28b82aa43000117
*/

#include <stdio.h>

int adjacentElementsProduct(const int inputArray[], size_t input_size);

static void printArray(const size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == (length - 1)) ? "" : ", ");
  printf(" }");
}

static void doTest(const int inputArray[],
                   const size_t input_size,
                   const int expected) {
  int actual = adjacentElementsProduct(inputArray, input_size);
  printf("Array = ");
  printArray(input_size, inputArray);
  printf("\nExpected %d, actual %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  doTest((int[]){5, 8}, 2, 40);
  doTest((int[]){1, 2, 3}, 3, 6);
  doTest((int[]){1, 5, 10, 9}, 4, 90);
  doTest((int[]){4, 12, 3, 1, 5}, 5, 48);
  doTest((int[]){5, 1, 2, 3, 1, 4}, 6, 6);
  doTest((int[]){3, 6, -2, -5, 7, 3}, 6, 21);
  doTest((int[]){9, 5, 10, 2, 24, -1, -48}, 7, 50);
  doTest((int[]){5, 6, -4, 2, 3, 2, -23}, 7, 30);
  doTest((int[]){-23, 4, -5, 99, -27, 329, -2, 7, -921}, 9, -14);
  doTest((int[]){5, 1, 2, 3, 1, 4}, 6, 6);
  doTest((int[]){1, 0, 1, 0, 1000}, 5, 0);
  doTest((int[]){1, 2, 3, 0}, 4, 6);
  return 0;
}
