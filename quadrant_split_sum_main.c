/*
7 kyu
Quadrant Split Sum
https://www.codewars.com/kata/6a08841ec8545c42e410b34a
*/

#include <stddef.h>
#include <stdio.h>

enum sizes { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT };

int max_land_value(size_t height, size_t width, const int area[height][width]);

static char* mtx_str(size_t height,
                     size_t width,
                     const int matrix[height][width],
                     char* mtx_str) {
  size_t position = sprintf(mtx_str, "{\n");
  for (size_t y = 0; y < height; y++) {
    position += sprintf(mtx_str + position, "  {");
    for (size_t x = 0; x < width; x++) {
      position += sprintf(mtx_str + position, "%d%s", matrix[y][x],
                          x < width - 1 ? ", " : "");
    }
    position += sprintf(mtx_str + position, "}%s\n", y < height - 1 ? "," : "");
  }
  position += sprintf(mtx_str + position, "}");
  return mtx_str;
}

static void tester(size_t height,
                   size_t width,
                   const int area[height][width],
                   int expected) {
  int submitted = max_land_value(height, width, area);
  char arst[((11 + 2) * width + 2) * height + 3];
  printf("Area Matrix: %s\n", mtx_str(height, width, area, arst));
  printf("Submitted: %d, expected: %d -> %s\n\n", submitted, expected,
         submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const int area[TWO][TWO] = {
        {5, 6},
        {1, 3},
    };
    int expected = 6;
    tester(TWO, TWO, area, expected);
  }
  {
    const int area[TWO][TWO] = {
        {0, 0},
        {2, 2},
    };
    int expected = 2;
    tester(TWO, TWO, area, expected);
  }
  {
    const int area[FOUR][FOUR] = {
        {4, 5, 6, 1}, {1, 2, 4, 0}, {9, 0, 3, 2}, {1, 2, 3, 4}};
    int expected = 12;
    tester(FOUR, FOUR, area, expected);
  }
  {
    const int area[SIX][SIX] = {{4, 5, 1, 0, 5, 6}, {1, 6, 1, 7, 0, 0},
                                {0, 0, 0, 0, 0, 0}, {1, 2, 3, 4, 5, 6},
                                {6, 7, 5, 4, 1, 0}, {1, 0, 0, 2, 4, 6}};
    int expected = 32;
    tester(SIX, SIX, area, expected);
  }
  {
    const int area[SIX][SIX] = {{4, -1, 5, 7, 8, -6}, {-2, 6, 8, 1, 2, 9},
                                {2, 7, -3, 6, 1, 0},  {0, 0, 3, 3, -1, -1},
                                {4, 6, 10, 4, 5, 7},  {-2, 5, 7, 9, 1, 2}};
    int expected = 33;
    tester(SIX, SIX, area, expected);
  }
  {
    const int area[TWO][FOUR] = {{1, 2, 3, 4}, {4, 1, 3, 2}};
    int expected = 7;
    tester(TWO, FOUR, area, expected);
  }
  {
    const int area[FOUR][TWO] = {{8, 1}, {1, 7}, {9, 0}, {5, 6}};
    int expected = 14;
    tester(FOUR, TWO, area, expected);
  }
  {
    const int area[FOUR][SIX] = {{1, 5, 6, 8, 1, 0},
                                 {0, -1, 5, 8, -2, 0},
                                 {1, 2, 5, -3, 6, 7},
                                 {0, 0, 2, 7, 0, 3}};
    int expected = 20;
    tester(FOUR, SIX, area, expected);
  }
  {
    const int area[SIX][FOUR] = {{1, 2, 6, 0}, {1, 8, 0, 9}, {5, 6, 8, 1},
                                 {0, 0, 2, 2}, {1, 1, 3, 9}, {9, 9, 5, 6}};
    int expected = 27;
    tester(SIX, FOUR, area, expected);
  }
  {
    const int area[THREE][THREE] = {
        {0, 6, 0},
        {9, 8, 9},
        {0, 2, 0},
    };
    int expected = 0;
    tester(THREE, THREE, area, expected);
  }
  {
    const int area[THREE][THREE] = {
        {6, 5, 2},
        {7, 9, 1},
        {1, 7, 5},
    };
    int expected = 6;
    tester(THREE, THREE, area, expected);
  }
  {
    const int area[FIVE][FIVE] = {
        {1, 3, 5, 8, 0}, {8, 9, 0, 0, 9}, {5, 5, 5, 5, 5},
        {0, 5, 2, 4, 6}, {1, 2, 8, 3, 4},
    };
    int expected = 21;
    tester(FIVE, FIVE, area, expected);
  }
  {
    const int area[FIVE][FIVE] = {
        {-1, -5, -8, -2, -1}, {0, 2, 9, -1, 2},   {5, 9, 9, 4, -9},
        {-3, -1, 9, 2, -7},   {2, -4, -7, -5, 9},
    };
    int expected = -1;
    tester(FIVE, FIVE, area, expected);
  }
  {
    const int area[SEVEN][SEVEN] = {
        {0, 9, 0, 1, 2, 3, 4}, {5, 7, 1, 6, 9, 0, 4}, {0, 5, 7, 1, 1, 1, 1},
        {0, 6, 7, 8, 9, 0, 2}, {8, 7, 3, 4, 5, 1, 2}, {2, 1, 5, 3, 7, 8, 9},
        {5, 6, 8, 1, 2, 9, 0},
    };
    int expected = 45;
    tester(SEVEN, SEVEN, area, expected);
  }
  {
    const int area[SEVEN][SEVEN] = {
        {1, 4, 0, 0, 0, 0, 0},   {-1, 4, 2, 3, 1, 0, 1},
        {3, -2, 4, 1, -2, 5, 1}, {-2, 5, 1, 8, 1, 5, 6},
        {-1, 3, 2, 0, 2, 3, -2}, {0, 5, 1, 2, 0, -2, 4},
        {1, 1, 1, 1, 1, 1, 1},
    };
    int expected = 15;
    tester(SEVEN, SEVEN, area, expected);
  }
  {
    const int area[THREE][FIVE] = {
        {1, 2, 3, 4, 5},
        {5, 1, 2, 4, 3},
        {1, 2, 5, 4, 2},
    };
    int expected = 9;
    tester(THREE, FIVE, area, expected);
  }
  {
    const int area[FIVE][THREE] = {
        {3, 1, 4}, {1, 4, 2}, {0, -2, 5}, {1, 1, 1}, {0, 7, 2}};
    int expected = 6;
    tester(FIVE, THREE, area, expected);
  }
  {
    const int area[FIVE][SEVEN] = {{1, 5, 7, 1, 2, 3, 0},
                                   {0, 2, 3, 4, 1, 5, 6},
                                   {0, 0, 2, 3, 4, 5, 9},
                                   {1, 2, 6, 9, 0, 2, 4},
                                   {5, 6, 7, 9, 0, 1, 2}};
    int expected = 27;
    tester(FIVE, SEVEN, area, expected);
  }
  {
    const int area[SEVEN][FIVE] = {
        {1, 0, 2, 3, 7}, {2, 6, 7, 0, 2}, {4, 5, 6, 8, 9}, {2, 5, 8, 9, 0},
        {1, 2, 6, 8, 9}, {0, 9, 2, 3, 1}, {1, 8, 4, 2, 3}};
    int expected = 29;
    tester(SEVEN, FIVE, area, expected);
  }
  return 0;
}
