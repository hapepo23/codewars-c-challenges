/*
7 kyu
Check if a triangle is an equable triangle!
https://www.codewars.com/kata/57d0089e05c186ccb600035e
*/

#include <stdbool.h>
#include <stdio.h>

bool equable_triangle(unsigned a, unsigned b, unsigned c);

static void tester(unsigned a, unsigned b, unsigned c, bool expected) {
  bool submitted = equable_triangle(a, b, c);
  const char* bs[2] = {"false", "true"};
  printf("a = %u, b = %u, c = %u, expected = %s, actual = %s -> %s\n", a, b, c,
         bs[expected], bs[submitted], expected == submitted ? "OK" : "FAIL");
}

int main(void) {
  tester(5, 12, 13, true);
  tester(2, 3, 4, false);
  tester(6, 8, 10, true);
  tester(7, 15, 20, true);
  tester(17, 17, 30, false);
  tester(7, 10, 12, false);
  tester(6, 11, 12, false);
  tester(25, 25, 45, false);
  tester(13, 37, 30, false);
  tester(6, 25, 29, true);
  tester(10, 11, 18, false);
  tester(73, 9, 80, false);
  tester(12, 35, 37, false);
  tester(120, 109, 13, false);
  tester(9, 10, 17, true);
  return 0;
}
