/*
8 kyu
To square(root) or not to square(root)
https://www.codewars.com/kata/57f6ad55cca6e045d2000627
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* squareOrSquareRoot(int* array, int length);

static void do_test(int* array, int* expected, int length) {
  int* actual = squareOrSquareRoot(array, length);
  printf("-> %s\n",
         memcmp(actual, expected, length * sizeof(int)) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main() {
  int input1[] = {4, 3, 9, 7, 2, 1};
  int expected1[] = {2, 9, 3, 49, 4, 1};
  do_test(input1, expected1, 6);
  int input2[] = {100, 101, 5, 5, 1, 1};
  int expected2[] = {10, 10201, 25, 25, 1, 1};
  do_test(input2, expected2, 6);
  int input3[] = {1, 2, 3, 4, 5, 6};
  int expected3[] = {1, 4, 9, 2, 25, 36};
  do_test(input3, expected3, 6);
  return 0;
}
