/*
6 kyu
Locate P using 3 Points and their distances to P
https://www.codewars.com/kata/6326533f8b7445002e856ca3
*/

#include <stdio.h>

typedef struct {
  long long x;
  long long y;
} Point2;

Point2 triangulate(Point2 A,
                   long long dA,
                   Point2 B,
                   long long dB,
                   Point2 C,
                   long long dC);

static void do_test(Point2 A,
                    long long dA,
                    Point2 B,
                    long long dB,
                    Point2 C,
                    long long dC,
                    Point2 expected) {
  Point2 actual = triangulate(A, dA, B, dB, C, dC);
  printf(
      "A = {%lld, %lld}, dA = %lld\n"
      "B = {%lld, %lld}, dB = %lld\n"
      "C = {%lld, %lld}, dC = %lld\n"
      "expected P = {%lld, %lld}\n"
      "actual   P = {%lld, %lld}\n"
      "-> %s\n\n",
      A.x, A.y, dA, B.x, B.y, dB, C.x, C.y, dC, expected.x, expected.y,
      actual.x, actual.y,
      expected.x == actual.x && expected.y == actual.y ? "OK" : "FAIL");
}

int main(void) {
  do_test((Point2){0, 0}, 2, (Point2){0, 1}, 1, (Point2){1, 0}, 1,
          (Point2){1, 1});
  do_test((Point2){0, 1}, 9, (Point2){3, 0}, 25, (Point2){3, 4}, 9,
          (Point2){0, 4});
  do_test((Point2){-1, 0}, 82, (Point2){5, 6}, 34, (Point2){11, 3}, 13,
          (Point2){8, 1});
  do_test((Point2){3, 2}, 40, (Point2){-5, -3}, 37, (Point2){-2, -1}, 18,
          (Point2){1, -4});
  do_test((Point2){-3, 2}, 68, (Point2){0, -1}, 26, (Point2){1, 5}, 41,
          (Point2){5, 0});
  do_test((Point2){-100, -100}, 21226, (Point2){1000, 20}, 998226,
          (Point2){0, 0}, 26, (Point2){1, 5});
  return 0;
}
