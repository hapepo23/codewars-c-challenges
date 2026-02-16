/*
6 kyu
Matrix Addition
https://www.codewars.com/kata/526233aefd4764272800036f
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(a, b, c) do_test(ARR_LEN(a), a, b, c)

int* matrix_addition(size_t n,
                     const int matrix_a[n][n],
                     const int matrix_b[n][n]);

static void print_array(size_t n, const int array[n]) {
  printf("{");
  for (size_t i = 0; i < n; i++)
    printf("%d%s", array[i], (i == n - 1) ? "" : ", ");
  printf("}");
}

static void print_matrix(size_t n, const int matrix[n][n]) {
  printf("{\n");
  for (size_t i = 0; i < n; i++) {
    printf("\t");
    print_array(n, matrix[i]);
    printf(",\n");
  }
  printf("}");
}

static void do_test(size_t n,
                    const int a[n][n],
                    const int b[n][n],
                    const int c[n][n]) {
  int* actual = matrix_addition(n, a, b);
  const size_t mem_size = n * sizeof *a;
  printf("a =\n");
  print_matrix(n, a);
  printf("\nb =\n");
  print_matrix(n, b);
  printf("\nexpected =\n");
  print_matrix(n, c);
  printf("\nactual =\n");
  print_matrix(n, (const int(*)[n])actual);  // <-- cast vector to int[n][n]
  printf("\n--> %s\n\n", memcmp(actual, c, mem_size) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  fixed_test(((int[2][2]){{1, 2}, {1, 2}}), ((int[2][2]){{2, 3}, {2, 3}}),
             ((int[2][2]){{3, 5}, {3, 5}}));
  fixed_test(((int[1][1]){{1}}), ((int[1][1]){{2}}), ((int[1][1]){{3}}));
  fixed_test(((int[3][3]){{1, 2, 3}, {3, 2, 1}, {1, 1, 1}}),
             ((int[3][3]){{2, 2, 1}, {3, 2, 3}, {1, 1, 3}}),
             ((int[3][3]){{3, 4, 4}, {6, 4, 4}, {2, 2, 4}}));
  fixed_test(((int[3][3]){{0, 0, 3}, {1, 3, 2}, {4, 6, 9}}),
             ((int[3][3]){{1, 2, 0}, {3, 2, 4}, {3, 2, 0}}),
             ((int[3][3]){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
  return 0;
}
