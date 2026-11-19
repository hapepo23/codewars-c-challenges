/*
8 kyu
SpeedCode #2 - Array Madness
https://www.codewars.com/kata/56ff6a70e1a63ccdfa0001b1
*/

#include <stdbool.h>
#include <stdio.h>

bool array_madness(size_t n1,
                   const int arr1[n1],
                   size_t n2,
                   const int arr2[n2]);

static void print_array(size_t len, const int array[len]) {
  printf("{ ");
  for (size_t i = 0; i < len; i++)
    printf("%d%s", array[i], (i == len - 1) ? "" : ", ");
  printf(" }");
}

static void tester(size_t n1,
                   const int arr1[n1],
                   size_t n2,
                   const int arr2[n2],
                   bool expected) {
  bool submitted = array_madness(n1, arr1, n2, arr2);
  printf("Array 1 = ");
  print_array(n1, arr1);
  printf("\nArray 2 = ");
  print_array(n2, arr2);
  printf("\n");
  printf("Expected = %s, but got = %s -> %s\n\n", expected ? "true" : "false",
         submitted ? "true" : "false", submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const int arr1[3] = {4, 5, 6};
    const int arr2[3] = {1, 2, 3};
    tester(3, arr1, 3, arr2, true);
  }
  {
    const int arr1[3] = {1, 2, 3};
    const int arr2[3] = {4, 5, 6};
    tester(3, arr1, 3, arr2, false);
  }
  return 0;
}
