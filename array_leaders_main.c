/*
7 kyu
Array Leaders
https://www.codewars.com/kata/5a651865fd56cb55760000e0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))
#define RUN_TEST(arr, exp) \
  doTest((arr), ARRAY_COUNT(arr), (exp), ARRAY_COUNT(exp))

int* arrayLeaders(const int numbers[], int inCount, int* outCount);

static void printArray(size_t length, const int array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}");
}

static void doTest(const int input[],
                   int inCount,
                   const int expected[],
                   int expCount) {
  int actCount = 666;
  int* actual = arrayLeaders(input, inCount, &actCount);
  puts("For array:");
  printArray(inCount, input);
  puts("\nExpected:");
  printArray(expCount, expected);
  puts("\nActual:");
  printArray(actCount, actual);
  printf("\n-> %s\n\n",
         actCount == expCount &&
                 memcmp(expected, actual, actCount * sizeof(*expected)) == 0
             ? "OK"
             : "FAIL");
  free(actual);
}

int main(void) {
  {
    int arr[] = {1, 2, 3, 4, 0}, exp[] = {4};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {16, 17, 4, 3, 5, 2}, exp[] = {17, 5, 2};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {-1, -29, -26, -2}, exp[] = {-1};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {-36, -12, -27}, exp[] = {-36, -12};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {5, 2}, exp[] = {5, 2};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {0, -1, -29, 3, 2}, exp[] = {0, -1, 3, 2};
    RUN_TEST(arr, exp);
  }
  return 0;
}
