/*
6 kyu
Maze Runner
https://www.codewars.com/kata/58663693b359c4a6560001d6
*/

#include <stddef.h>

typedef struct coord {
  size_t row, col;
} Coord;

const char* maze_runner(
    const int
        maze[] /* flattened n*n grid stored contiguously in row-major order */,
    size_t n,
    const char* directions) {
  static const char* finish = "Finish";
  static const char* dead = "Dead";
  static const char* lost = "Lost";
  Coord start = {.col = 0, .row = 0}, end = {.col = 0, .row = 0};
  for (size_t r = 0; r < n; r++) {
    for (size_t c = 0; c < n; c++) {
      if (maze[r * n + c] == 2) {
        start.col = c;
        start.row = r;
      } else if (maze[r * n + c] == 3) {
        end.col = c;
        end.row = r;
      }
    }
  }
  Coord pos = {.col = start.col, .row = start.row};
  const char* d = directions;
  while (*d != '\0') {
    switch (*d) {
      case 'N':
        if (pos.row == 0)
          return dead;
        pos.row--;
        break;
      case 'S':
        if (pos.row == n - 1)
          return dead;
        pos.row++;
        break;
      case 'W':
        if (pos.col == 0)
          return dead;
        pos.col--;
        break;
      case 'E':
        if (pos.col == n - 1)
          return dead;
        pos.col++;
        break;
    }
    if (maze[pos.row * n + pos.col] == 1)
      return dead;
    if (pos.row == end.row && pos.col == end.col)
      return finish;
    d++;
  }
  return lost;
}
