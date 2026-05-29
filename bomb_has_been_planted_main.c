/*
6 kyu
Bomb has been planted!
https://www.codewars.com/kata/6621b92d6d4e8800178449f5
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool bomb_has_been_planted(size_t m,
                           size_t n,
                           const char matrix[n][n],
                           unsigned time);

static void make_mtx_str(size_t m,
                         size_t n,
                         const char matrix[m][n],
                         char* mtx_str) {
  size_t position = sprintf(mtx_str, "{\n");
  for (size_t y = 0; y < m; y++) {
    position += sprintf(mtx_str + position, "  {");
    for (size_t x = 0; x < n; x++) {
      position += sprintf(mtx_str + position, "%c%s", matrix[y][x],
                          x < n - 1 ? ", " : "");
    }
    position += sprintf(mtx_str + position, "}%s\n", y < m - 1 ? "," : "");
  }
  position += sprintf(mtx_str + position, "}");
}

static void do_test(size_t m,
                    size_t n,
                    const char matrix[m][n],
                    unsigned time,
                    bool expected) {
  bool submitted = bomb_has_been_planted(m, n, matrix, time);
  const char* bs[2] = {"false", "true"};
  char mtx_str[(22 * n + 2) * m + 5 + 4000];
  make_mtx_str(m, n, matrix, mtx_str);
  printf("Matrix:\n%s\nSubmitted: %s\nExpected:  %s\n-> %s\n\n", mtx_str,
         bs[submitted], bs[expected], submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const char matrix[8][7] = {{'C', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0', '0', 'B'}};
    unsigned time = 7;
    do_test(8, 7, matrix, time, false);
  }
  {
    const char matrix[1][5] = {{'C', 'B', '0', '0', '0'}};
    unsigned time = 9;
    do_test(1, 5, matrix, time, false);
  }
  {
    const char matrix[5][5] = {{'C', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'},
                               {'0', '0', '0', 'B', '0'},
                               {'0', '0', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
    unsigned time = 13;
    do_test(5, 5, matrix, time, true);
  }
  {
    const char matrix[3][4] = {
        {'0', '0', '0', 'C'}, {'0', '0', '0', '0'}, {'B', '0', '0', '0'}};
    unsigned time = 13;
    do_test(3, 4, matrix, time, true);
  }
  {
    const char matrix[9][6] = {
        {'0', '0', '0', '0', '0', '0'}, {'C', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', 'B'}, {'0', '0', '0', '0', '0', '0'},
        {'0', '0', 'K', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'}};
    unsigned time = 13;
    do_test(9, 6, matrix, time, true);
  }
  {
    const char matrix[4][4] = {{'0', 'K', '0', 'C'},
                               {'0', '0', '0', '0'},
                               {'0', '0', '0', '0'},
                               {'B', '0', '0', '0'}};
    unsigned time = 12;
    do_test(4, 4, matrix, time, true);
  }
  return 0;
}
