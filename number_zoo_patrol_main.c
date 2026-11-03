/*
6 kyu
Number Zoo Patrol
https://www.codewars.com/kata/5276c18121e20900c0000235
*/

#include <stdio.h>

unsigned find_number(const unsigned* arr, size_t len);

static void run_test(unsigned actual, unsigned expected) {
  printf("Actual: %d, expected: %d -> %s\n", actual, expected,
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    unsigned arr[] = {2, 3, 4};
    run_test(find_number(arr, 3), 1);
  }
  {
    unsigned arr[] = {1, 3, 4};
    run_test(find_number(arr, 3), 2);
  }
  {
    unsigned arr[] = {1, 2, 4};
    run_test(find_number(arr, 3), 3);
  }
  {
    unsigned arr[] = {1, 2, 3};
    run_test(find_number(arr, 3), 4);
  }
  return 0;
}
