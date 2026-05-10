/*
7 kyu
Product Of Maximums Of Array
https://www.codewars.com/kata/5a63948acadebff56f000018
*/

#include <stdio.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof *(array))
#define fixedTest(array, k, expected) \
  doTest(ARRAY_LENGTH(array), array, k, expected)

int maxProduct(const int numbers[], int length, int k);

static void printArray(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == (length - 1)) ? "" : ", ");
  printf(" }\n");
}

static void doTest(size_t length,
                   const int array[length],
                   size_t k,
                   int expected) {
  int actual = maxProduct(array, length, k);
  printf("Array = ");
  printArray(length, array);
  printf("k: %ld, Expected: %d, actual: %d -> %s\n\n", k, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixedTest(((int[]){4, 3, 5}), 2, 20);
  fixedTest(((int[]){10, 8, 7, 9}), 3, 720);
  fixedTest(((int[]){8, 6, 4, 6}), 3, 288);
  fixedTest(((int[]){10, 2, 3, 8, 1, 10, 4}), 5, 9600);
  fixedTest(((int[]){13, 12, -27, -302, 25, 37, 133, 155, -14}), 5, 247895375);
  fixedTest(((int[]){-4, -27, -15, -6, -1}), 2, 4);
  fixedTest(((int[]){-17, -8, -102, -309}), 2, 136);
  fixedTest(((int[]){10, 3, -27, -1}), 3, -30);
  fixedTest(((int[]){14, 29, -28, 39, -16, -48}), 4, -253344);
  return 0;
}
