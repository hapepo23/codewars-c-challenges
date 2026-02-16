/*
6 kyu
Matrix Transpose
https://www.codewars.com/kata/52fba2a9adcd10b34300094c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(array, expected) \
  do_test(ARR_LEN(array), ARR_LEN(*array), array, expected)

void transpose_matrix(size_t rows,
                      size_t cols,
                      const int matrix[rows][cols],
                      int transpose[cols][rows]);

static void print_matrix(size_t rows,
                         size_t cols,
                         const int matrix[rows][cols]) {
  for (size_t row = 0; row < rows; row++) {
    printf("{");
    for (size_t col = 0; col < cols; col++)
      printf("%d%s", matrix[row][col], (col == cols - 1) ? "" : ", ");
    printf("}\n");
  }
}

static void do_test(size_t rows,
                    size_t cols,
                    int matrix[rows][cols],
                    int expected[cols][rows]) {
  int(*actual)[cols][rows] = malloc(sizeof *actual);
  transpose_matrix(rows, cols, matrix, *actual);
  puts("for matrix:");
  print_matrix(rows, cols, matrix);
  puts("expected:");
  print_matrix(cols, rows, expected);
  puts("but got:");
  print_matrix(cols, rows, *actual);
  printf("-> %s\n\n",
         memcmp(actual, expected, sizeof *actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  fixed_test(((int[1][3]){
                 {1, 2, 3},
             }),
             ((int[3][1]){{1}, {2}, {3}}));
  fixed_test(((int[3][3]){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}),
             ((int[3][3]){{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}));
  fixed_test(((int[1][1]){
                 {1},
             }),
             ((int[1][1]){
                 {1},
             }));
  fixed_test(((int[5][3]){
                 {1, 0, 0},
                 {0, 1, 0},
                 {0, 0, 1},
                 {0, 1, 0},
                 {1, 0, 0},
             }),
             ((int[3][5]){{1, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}}));
  return 0;
}
