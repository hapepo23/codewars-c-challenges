/*
6 kyu
Find the total white and black areas in a strange chessboard
https://www.codewars.com/kata/6262f9f7afc4729d8f5bef48
*/

#include <stddef.h>

typedef struct Pair {
  unsigned white, black;
} pair;

pair white_black_areas(size_t n,
                       const unsigned rows[n],
                       const unsigned cols[n]) {
  pair result;
  unsigned w = 0, b = 0;
  for (size_t i = 0; i < n; i++) {
    if (i % 2)
      w += rows[i];
    else
      b += rows[i];
  }
  result.white = 0;
  result.black = 0;
  for (size_t i = 0; i < n; i++) {
    result.white += cols[i] * (i % 2 ? w : b);
    result.black += cols[i] * (i % 2 ? b : w);
  }
  return result;
}
