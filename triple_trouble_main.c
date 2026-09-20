/*
6 kyu
Triple trouble
https://www.codewars.com/kata/55d5434f269c0c3f1b000058
*/

#include <stdbool.h>
#include <stdio.h>

bool triple_trouble(unsigned long long num1, unsigned long long num2);

static void do_test(unsigned long long three,
                    unsigned long long two,
                    bool expected) {
  bool actual = triple_trouble(three, two);
  printf("Input: %llu %llu, expected: %d, actual: %d -> %s\n", three, two,
         expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(123123123, 123123, 0);
  do_test(111, 88, 0);
  do_test(111000, 100, 1);
  do_test(111888, 1188, 1);
  do_test(451999277, 41177722899, 1);
  do_test(1222345, 12345, 0);
  do_test(12345, 12345, 0);
  do_test(666789, 12345667, 1);
  do_test(10560002, 100, 1);
  do_test(1112, 122, 0);
  return 0;
}
