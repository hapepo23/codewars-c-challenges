/*
6 kyu
Maze Runner
https://www.codewars.com/kata/58663693b359c4a6560001d6
*/

#include <stdio.h>
#include <string.h>

const char* maze_runner(const int maze[], size_t n, const char* directions);

static char* stringify_matrix(char* out, size_t n, const int matrix[n * n]) {
  char* p = out;
  p += sprintf(p, "{\n");
  for (size_t row = 0; row < n; row++) {
    for (size_t col = 0; col < n; col++)
      p += sprintf(p, "%d%s", matrix[n * row + col],
                   (row == n - 1 && col == n - 1) ? "" : ", ");
    p += sprintf(p, "\n");
  }
  p += sprintf(p, "}");
  return out;
}

static void tester(size_t n,
                   const int maze[n * n],
                   const char* directions,
                   const char* expected) {
  const char* const actual = maze_runner(maze, n, directions);
  printf(
      "Maze = %s\nDirections = \"%s\"\nExpected = \"%s\"\nActual = \"%s\"\n-> "
      "%s\n\n",
      stringify_matrix((char[8192]){""}, n, maze), directions, expected, actual,
      strcmp(actual, expected) == 0 ? "OK" : "FAIL");
}

#define N 7

int main(void) {
  const int maze[N * N] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 1, 0, 1,
                           0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0,
                           1, 1, 0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 1, 0, 1};
  {
    const char* directions = "NNNNNEEEEE";
    tester(N, maze, directions, "Finish");
  }
  {
    const char* directions = "NNNNNEESSEENNE";
    tester(N, maze, directions, "Finish");
  }
  {
    const char* directions = "NNNNNEEEEEWW";
    tester(N, maze, directions, "Finish");
  }
  {
    const char* directions = "NEEEE";
    tester(N, maze, directions, "Lost");
  }
  {
    const char* directions = "NNNWW";
    tester(N, maze, directions, "Dead");
  }
  {
    const char* directions = "NNNNNEESSSSSS";
    tester(N, maze, directions, "Dead");
  }
  return 0;
}
