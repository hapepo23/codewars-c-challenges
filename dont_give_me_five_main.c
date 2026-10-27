/*
7 kyu
Don't give me five!
https://www.codewars.com/kata/5813d19765d81c592200001a
*/

#include <stdio.h>

int dontGiveMeFive(int start, int end);

static void dotest(int start, int end, int expected) {
  int actual = dontGiveMeFive(start, end);
  printf("Range = %d...%d, expected = %d, actual = %d -> %s\n", start, end,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  dotest(1, 9, 8);
  dotest(4, 17, 12);
  dotest(-17, -4, 12);
  return 0;
}
