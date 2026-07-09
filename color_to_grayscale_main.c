/*
7 kyu
Color to Grayscale
https://www.codewars.com/kata/649c4012aaad69003f1299c1
*/

#include <stdio.h>
#include <string.h>

void rgb_to_grayscale(const char* color, char* grayscale);

static void do_test(const char* color, const char* expected) {
  char actual[8];
  actual[0] = '\0';
  rgb_to_grayscale(color, actual);
  printf("Color: %s, expected: %s, actual: %s -> %s\n", color, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("#FFFFFF", "#FFFFFF");
  do_test("#0000FF", "#1D1D1D");
  do_test("#00FF00", "#969696");
  do_test("#FF0000", "#4C4C4C");
  do_test("#000000", "#000000");
  return 0;
}
