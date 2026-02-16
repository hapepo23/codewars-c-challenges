/*
6 kyu
Rotate matrix counter - clockwise N - times!
https://www.codewars.com/kata/5919f3bf6589022915000023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define sample_test(input, times, expected) \
  do_test(ARR_LEN(input), input, expected, times)

void rotate_counter_clockwise(size_t n,
                              const int matrix[n][n],
                              unsigned times,
                              int rotated[n][n]);

static void print_matrix(size_t rows,
                         size_t cols,
                         const int matrix[rows][cols]) {
  printf("{\n");
  for (size_t row = 0; row < rows; row++) {
    printf("\t{");
    for (size_t col = 0; col < cols; col++)
      printf("%d%s", matrix[row][col], (col == cols - 1) ? "" : ", ");
    printf("}\n");
  }
  printf("}\n");
}

static void do_test(size_t n,
                    const int input[n][n],
                    const int expected[n][n],
                    unsigned times) {
  int(*actual)[n][n] = malloc(sizeof *actual);
  rotate_counter_clockwise(n, input, times, *actual);
  puts("matrix:");
  print_matrix(n, n, input);
  printf("to be rotated: %u times\n", times);
  puts("expected:");
  print_matrix(n, n, expected);
  puts("got:");
  print_matrix(n, n, *actual);
  printf("%s\n\n", memcmp(expected, *actual, n * n * sizeof(int)) == 0
                       ? "OK"
                       : "INCORRECT");
  free(actual);
}

int main(void) {
  sample_test(((const int[3][3]){
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9},
              }),
              1,
              ((const int[3][3]){
                  {3, 6, 9},
                  {2, 5, 8},
                  {1, 4, 7},
              }));
  sample_test(((const int[3][3]){
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9},
              }),
              2,
              ((const int[3][3]){
                  {9, 8, 7},
                  {6, 5, 4},
                  {3, 2, 1},
              }));
  sample_test(((const int[3][3]){
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9},
              }),
              3,
              ((const int[3][3]){
                  {7, 4, 1},
                  {8, 5, 2},
                  {9, 6, 3},
              }));
  sample_test(((const int[3][3]){
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9},
              }),
              0,
              ((const int[3][3]){
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9},
              }));
  return 0;
}
