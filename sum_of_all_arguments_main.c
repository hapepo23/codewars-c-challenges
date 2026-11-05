/*
7 kyu
Sum of all arguments
https://www.codewars.com/kata/540c33513b6532cd58000259
*/

#include <stdio.h>

int sum(int argc, ...);

#define fixed_test(expected, argc, ...) \
  do_test(sum(argc __VA_OPT__(, ) __VA_ARGS__), expected, #__VA_ARGS__)

static void do_test(int actual, int expected, const char* args_string) {
  printf("Expected = %d, actual = %d for sum(%s) -> %s\n", expected, actual,
         args_string, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  fixed_test(9, 3, /* args */ 1, 3, 5);
  fixed_test(14, 4, /* args */ 0, 3, 9, 2);
  fixed_test(0, 0 /* args */);
  fixed_test(3, 3, /* args */ 1, -2, 4);
  fixed_test(45, 1, /* args */ 45);
  fixed_test(650, 6, /* args */ 100, -200, 50, 500, 600, -400);
  return 0;
}
