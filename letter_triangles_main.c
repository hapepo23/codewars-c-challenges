/*
6 kyu
Letter triangles
https://www.codewars.com/kata/635e70f47dadea004acb5663
*/

#include <stdio.h>

char triangle(const char* row);

static void tester(const char* row, char expected) {
  char submitted = triangle(row);
  printf("Row = \"%s\", submitted: '%c', expected: '%c' -> %s\n", row,
         submitted, expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  tester("codewars", 'l');
  tester("triangle", 'd');
  tester("youhavechosentotranslatethiskata", 'a');
  tester("b", 'b');
  return 0;
}
