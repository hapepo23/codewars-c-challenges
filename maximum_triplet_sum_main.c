/*
7 kyu
Maximum Triplet Sum
https://www.codewars.com/kata/5aa1bcda373c2eb596000112
*/

#include <stddef.h>
#include <stdio.h>

#define ASIZE(a) (sizeof(a) / sizeof((a)[0]))

int maxTriSum(const int numbers[], int count);

static void printArray(size_t length, const int array[]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void doTest(const int numbers[], int count, int expected) {
  const int actual = maxTriSum(numbers, count);
  printf("Array = ");
  printArray(count, numbers);
  printf("\nExpected = %d, actual = %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    int a[] = {3, 2, 6, 8, 2, 3}, exp = 17;
    doTest(a, ASIZE(a), exp);
  }
  {
    int a[] = {2, 9, 13, 10, 5, 2, 9, 5}, exp = 32;
    doTest(a, ASIZE(a), exp);
  }
  {
    int a[] = {2, 1, 8, 0, 6, 4, 8, 6, 2, 4}, exp = 18;
    doTest(a, ASIZE(a), exp);
  }
  {
    int a[] = {-3, -27, -4, -2, -27, -2}, exp = -9;
    doTest(a, ASIZE(a), exp);
  }
  {
    int a[] = {-14, -12, -7, -42, -809, -14, -12}, exp = -33;
    doTest(a, ASIZE(a), exp);
  }
  {
    int a[] = {-13, -50, 57, 13, 67, -13, 57, 108, 67}, exp = 232;
    doTest(a, ASIZE(a), exp);
  }
  {
    int a[] = {-7, 12, -7, 29, -5, 0, -7, 0, 0, 29}, exp = 41;
    doTest(a, ASIZE(a), exp);
  }
  return 0;
}
