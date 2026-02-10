/*
6 kyu
Array.diff
https://www.codewars.com/kata/523f5d21c841566fde000009
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* array_diff(const int arr1[],
                size_t n1,
                const int arr2[],
                size_t n2,
                size_t* z);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(size_t n1,
                    const int arr1[n1],
                    size_t n2,
                    const int arr2[n2],
                    size_t nexp,
                    const int expected[nexp]) {
  size_t nact = 42;
  int* actual = array_diff(arr1, n1, arr2, n2, &nact);
  const size_t mem_size = nexp * sizeof *expected;
  printf("arr1     = ");
  print_array(n1, arr1);
  printf("\narr2     = ");
  print_array(n2, arr2);
  printf("\nexpected = ");
  print_array(nexp, expected);
  printf("\nactual   = ");
  print_array(nact, actual);
  printf("\n%s\n\n", (nact == nexp && memcmp(actual, expected, mem_size) == 0)
                         ? "OK"
                         : "FAIL");
  free(actual);
}

int main(void) {
  {
    const int arr1[2] = {1, 2};
    const int arr2[1] = {1};
    const int expected[1] = {2};
    do_test(2, arr1, 1, arr2, 1, expected);
  }
  {
    const int arr1[3] = {1, 2, 2};
    const int arr2[1] = {1};
    const int expected[2] = {2, 2};
    do_test(3, arr1, 1, arr2, 2, expected);
  }
  {
    const int arr1[3] = {1, 2, 2};
    const int arr2[1] = {2};
    const int expected[1] = {1};
    do_test(3, arr1, 1, arr2, 1, expected);
  }
  {
    const int arr1[3] = {1, 2, 2};
    const int* arr2 = NULL;
    const int expected[3] = {1, 2, 2};
    do_test(3, arr1, 0, arr2, 3, expected);
  }
  {
    const int arr1[3] = {1, 2, 3};
    const int arr2[2] = {1, 2};
    const int expected[1] = {3};
    do_test(3, arr1, 2, arr2, 1, expected);
  }
  {
    const int* arr1 = NULL;
    const int arr2[2] = {1, 2};
    const int* expected = NULL;
    do_test(0, arr1, 2, arr2, 0, expected);
  }
  {
    const int arr1[5] = {1, 2, 3, 4, 5};
    const int arr2[3] = {1, 3, 4};
    const int expected[2] = {2, 5};
    do_test(5, arr1, 3, arr2, 2, expected);
  }
  {
    const int arr1[5] = {1, 2, 3, 4, 5};
    const int arr2[5] = {1, 2, 3, 4, 5};
    const int* expected = NULL;
    do_test(5, arr1, 5, arr2, 0, expected);
  }
  return 0;
}
