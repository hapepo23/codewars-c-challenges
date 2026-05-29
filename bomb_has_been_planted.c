/*
6 kyu
Bomb has been planted!
https://www.codewars.com/kata/6621b92d6d4e8800178449f5
*/

#include <stdbool.h>
#include <stddef.h>

bool find(const char code,
          size_t m,
          size_t n,
          const char matrix[m][n],
          size_t* prow,
          size_t* pcol) {
  for (size_t i = 0; i < m; i++)
    for (size_t j = 0; j < n; j++)
      if (matrix[i][j] == code) {
        *prow = i;
        *pcol = j;
        return true;
      }
  *prow = 0;
  *pcol = 0;
  return false;
}

size_t distance(size_t rowfrom, size_t colfrom, size_t rowto, size_t colto) {
  size_t rows = rowfrom > rowto ? (rowfrom - rowto) : (rowto - rowfrom);
  size_t cols = colfrom > colto ? (colfrom - colto) : (colto - colfrom);
  return rows < cols ? cols : rows;
}

bool bomb_has_been_planted(size_t m,
                           size_t n,
                           const char matrix[m][n],
                           unsigned time) {
  size_t rowct, colct, rowb, colb, rowk, colk, distcb, distck, distkb;
  bool exk;
  find('C', m, n, matrix, &rowct, &colct);
  find('B', m, n, matrix, &rowb, &colb);
  distcb = distance(rowct, colct, rowb, colb);
  if (time >= distcb + 10)
    return true;
  exk = find('K', m, n, matrix, &rowk, &colk);
  if (exk) {
    distck = distance(rowct, colct, rowk, colk);
    distkb = distance(rowk, colk, rowb, colb);
    if (time >= distck + distkb + 5)
      return true;
  }
  return false;
}
