/*
5 kyu
The Clockwise Spiral
https://www.codewars.com/kata/536a155256eb459b8700077e
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** create_spiral(int n);

static void print_matrix(size_t n, const int* const matrix[n]) {
  printf("{\n");
  for (size_t row = 0; row < n; row++) {
    printf("\t{");
    for (size_t col = 0; col < n; col++)
      printf("%3d%s", matrix[row][col], (col == n - 1) ? "" : ", ");
    printf("}%s\n", (row == row - 1) ? "" : ",");
  }
  printf("}");
}

static void do_test(int n, const int* const expected[n]) {
  int** actual = create_spiral(n);
  if (n <= 0)
    return;
  bool equal = true;
  for (int i = 0; equal && i < n; i++)
    equal = !memcmp(actual[i], expected[i], n * sizeof **expected);
  printf("for n = %d\n", n);
  puts("expected:");
  print_matrix(n, expected);
  puts("\nactual:");
  print_matrix(n, (const int**)actual);
  printf("\n%s\n\n", equal ? "OK" : "FAIL");
  for (int i = 0; i < n; i++)
    free(actual[i]);
  free(actual);
}

int main(void) {
  do_test(1, (const int*[]){(int[]){1}});
  do_test(3,
          (const int*[]){(int[]){1, 2, 3}, (int[]){8, 9, 4}, (int[]){7, 6, 5}});
  do_test(4, (const int*[]){(int[]){1, 2, 3, 4}, (int[]){12, 13, 14, 5},
                            (int[]){11, 16, 15, 6}, (int[]){10, 9, 8, 7}});
  do_test(5,
          (const int*[]){(int[]){1, 2, 3, 4, 5}, (int[]){16, 17, 18, 19, 6},
                         (int[]){15, 24, 25, 20, 7}, (int[]){14, 23, 22, 21, 8},
                         (int[]){13, 12, 11, 10, 9}});
  do_test(2, (const int*[]){(int[]){1, 2}, (int[]){4, 3}});
  do_test(10, (const int*[]){(int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                             (int[]){36, 37, 38, 39, 40, 41, 42, 43, 44, 11},
                             (int[]){35, 64, 65, 66, 67, 68, 69, 70, 45, 12},
                             (int[]){34, 63, 84, 85, 86, 87, 88, 71, 46, 13},
                             (int[]){33, 62, 83, 96, 97, 98, 89, 72, 47, 14},
                             (int[]){32, 61, 82, 95, 100, 99, 90, 73, 48, 15},
                             (int[]){31, 60, 81, 94, 93, 92, 91, 74, 49, 16},
                             (int[]){30, 59, 80, 79, 78, 77, 76, 75, 50, 17},
                             (int[]){29, 58, 57, 56, 55, 54, 53, 52, 51, 18},
                             (int[]){28, 27, 26, 25, 24, 23, 22, 21, 20, 19}});
  return 0;
}
