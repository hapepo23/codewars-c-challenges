/*
6 kyu
Tribonacci Sequence
https://www.codewars.com/kata/556deca17c58da83c00002db
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long* tribonacci(const long long signature[3], size_t n);

static void print_array(size_t n, const long long array[n]) {
  printf("{ ");
  for (size_t i = 0; i < n; i++)
    printf("%lld%s", array[i], (i == n - 1) ? "" : ", ");
  printf(" }");
}

static void tester(const long long signature[3],
                   size_t n,
                   const long long expected[n]) {
  const size_t mem_size = n * sizeof *expected;
  long long* actual = tribonacci(signature, n);
  printf("Signature: { %lld, %lld, %lld }; n = %zu\n", signature[0],
         signature[1], signature[2], n);
  printf("Expected:  ");
  print_array(n, expected);
  printf("\nActual:    ");
  print_array(n, actual);
  printf("\n-> %s\n\n",
         memcmp(actual, expected, mem_size) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  {
    const long long signature[3] = {1, 1, 1};
    const size_t n = 10;
    long long expected[10] = {1, 1, 1, 3, 5, 9, 17, 31, 57, 105};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {0, 0, 1};
    const size_t n = 10;
    long long expected[10] = {0, 0, 1, 1, 2, 4, 7, 13, 24, 44};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {0, 1, 1};
    const size_t n = 10;
    long long expected[10] = {0, 1, 1, 2, 4, 7, 13, 24, 44, 81};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {1, 0, 0};
    const size_t n = 10;
    long long expected[10] = {1, 0, 0, 1, 1, 2, 4, 7, 13, 24};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {0, 0, 0};
    const size_t n = 10;
    long long expected[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {0, 0, 0};
    const size_t n = 10;
    long long expected[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {1, 2, 3};
    const size_t n = 10;
    long long expected[10] = {1, 2, 3, 6, 11, 20, 37, 68, 125, 230};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {3, 2, 1};
    const size_t n = 10;
    long long expected[10] = {3, 2, 1, 6, 9, 16, 31, 56, 103, 190};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {42, 55, 70};
    const size_t n = 1;
    long long expected[1] = {42};
    tester(signature, n, expected);
  }
  {
    const long long signature[3] = {300, 200, 100};
    const size_t n = 0;
    long long* expected = NULL;
    tester(signature, n, expected);
  }
  return 0;
}
