/*
6 kyu
Find the total white and black areas in a strange chessboard
https://www.codewars.com/kata/6262f9f7afc4729d8f5bef48
*/

#include <stdio.h>

typedef struct Pair {
  unsigned white, black;
} pair;

pair white_black_areas(size_t n,
                       const unsigned rows[n],
                       const unsigned cols[n]);

static void tester(size_t n,
                   const unsigned rows[n],
                   const unsigned cols[n],
                   const pair expected) {
  pair submitted = white_black_areas(n, rows, cols);
  char rows_str[7 * n + 1];
  char cols_str[7 * n + 1];
  size_t r = sprintf(rows_str, "{");
  size_t c = sprintf(cols_str, "{");
  size_t i = 0;
  while (i < n) {
    r += sprintf(rows_str + r, "%u, ", rows[i]);
    c += sprintf(cols_str + c, "%u, ", cols[i++]);
  }
  sprintf(rows_str + r - 2, "}");
  sprintf(cols_str + c - 2, "}");
  printf(
      "Rows = %s\nCols = %s\nActual   = {%u, %u}\nExpected = {%u, %u}\n-> "
      "%s\n\n",
      rows_str, cols_str, submitted.white, submitted.black, expected.white,
      expected.black,
      submitted.black != expected.black || submitted.white != expected.white
          ? "FAIL"
          : "OK");
}

int main(void) {
  {
    const unsigned rows[5] = {3, 1, 2, 7, 1};
    const unsigned cols[5] = {1, 8, 4, 5, 2};
    pair expected = {146, 134};
    tester(5, rows, cols, expected);
  }
  {
    const unsigned rows[10] = {3, 1, 2, 7, 1, 11, 12, 3, 8, 1};
    const unsigned cols[10] = {1, 8, 4, 5, 2, 21, 5, 2, 2, 17};
    pair expected = {1583, 1700};
    tester(10, rows, cols, expected);
  }
  {
    const unsigned rows[1] = {3};
    const unsigned cols[1] = {2};
    pair expected = {6, 0};
    tester(1, rows, cols, expected);
  }
  return 0;
}
