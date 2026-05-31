/*
7 kyu
Adding Arrays
https://www.codewars.com/kata/59778cb1b061e877c50000cc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(array, expected) \
  do_test(ARR_LEN(array), ARR_LEN(*array), array, expected)

char* array_adder(int rows,
                  int cols,
                  const char matrix[rows][cols],
                  char string[cols * (rows + 1) + 1]);

static void print_matrix(size_t rows,
                         size_t cols,
                         const char matrix[rows][cols]) {
  printf("{\n");
  for (size_t row = 0; row < rows; row++) {
    printf("  {");
    for (size_t col = 0; col < cols; col++) {
      char ch = matrix[row][col];
      printf("%s%s", ch ? (char[]){' ', '\'', ch, '\'', '\0'} : "'\\0'",
             (col == cols - 1) ? "" : ", ");
    }
    printf("}\%s", (row == row - 1) ? "" : ",\n");
  }
  printf("}\n");
}

static void do_test(int rows,
                    int cols,
                    const char matrix[rows][cols],
                    const char* expected) {
  const size_t mem_size = cols * (rows + 1) + 1;
  char* user_string = memset(malloc(mem_size), '@', mem_size);
  char* actual = array_adder(rows, cols, matrix, user_string);
  printf("For matrix %dx%d:\n", rows, cols);
  print_matrix(rows, cols, matrix);
  printf("Expected: \"%s\"\nActual  : \"%s\"\n-> %s\n\n", expected, actual,
         strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  fixed_test(((const char[4][4]){{'J', 'L', 'L', 'M'},
                                 {'u', 'i', 'i', 'a'},
                                 {'s', 'v', 'f', 'n'},
                                 {'t', 'e', 'e', '\0'}}),
             "Just Live Life Man");
  fixed_test(
      ((const char[12][8]){{'T', 'M', 'i', 't', 'p', 'o', 't', 'c'},
                           {'h', 'i', 's', 'h', 'o', 'f', 'h', 'e'},
                           {'e', 't', '\0', 'e', 'w', '\0', 'e', 'l'},
                           {'\0', 'o', '\0', '\0', 'e', '\0', '\0', 'l'},
                           {'\0', 'c', '\0', '\0', 'r', '\0', '\0', '\0'},
                           {'\0', 'h', '\0', '\0', 'h', '\0', '\0', '\0'},
                           {'\0', 'o', '\0', '\0', 'o', '\0', '\0', '\0'},
                           {'\0', 'n', '\0', '\0', 'u', '\0', '\0', '\0'},
                           {'\0', 'd', '\0', '\0', 's', '\0', '\0', '\0'},
                           {'\0', 'r', '\0', '\0', 'e', '\0', '\0', '\0'},
                           {'\0', 'i', '\0', '\0', '\0', '\0', '\0', '\0'},
                           {'\0', 'a', '\0', '\0', '\0', '\0', '\0', '\0'}}),
      "The Mitochondria is the powerhouse of the cell");
  return 0;
}
