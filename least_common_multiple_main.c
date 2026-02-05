/*
5 kyu
Least Common Multiple
https://www.codewars.com/kata/5259acb16021e9d8a60010af
*/

#include <stdio.h>

#define sample_test(expected, argc, ...) \
  do_test(args_LCM(argc, ##__VA_ARGS__), expected, #__VA_ARGS__)

typedef unsigned long long ull;

ull args_LCM(unsigned argc, ...);

static void do_test(ull actual, ull expected, const char* args_string) {
  printf("expected %llu, got %llu for arguments: (%s)\n%s\n\n", expected,
         actual, args_string, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  sample_test(10, 2, 2, 5);
  sample_test(12, 3, 2, 3, 4);
  sample_test(9, 1, 9);
  sample_test(0, 1, 0);
  sample_test(1, 0);
  sample_test(0, 2, 0, 1);
  sample_test(0, 2, 0, 0);
  sample_test(1, 3, 1, 1, 1);
  sample_test(21420, 14, 5, 6, 7, 9, 6, 9, 18, 4, 5, 15, 15, 10, 17, 7);
  sample_test(5290740, 14, 17, 20, 4, 15, 4, 18, 12, 14, 20, 19, 2, 14, 13, 7);
  sample_test(1361360, 14, 11, 13, 4, 5, 17, 4, 10, 13, 16, 13, 13, 14, 20, 14);
  sample_test(840, 8, 20, 1, 6, 10, 3, 7, 8, 4);
  sample_test(2394, 8, 3, 9, 9, 19, 18, 14, 18, 9);
  sample_test(0, 8, 3, 9, 9, 19, 18, 14, 18, 0);
  sample_test(135660, 7, 19, 3, 20, 15, 4, 17, 14);
  return 0;
}
