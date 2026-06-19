/*
7 kyu
Chain me
https://www.codewars.com/kata/54fb853b2c8785dd5e000957
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define sample_test(init_val, array, expected) \
  do_test(init_val, ARR_LEN(array), array, expected)

typedef int (*funcptr)(int);

int chain(int init_val, size_t length, const funcptr functions[length]);

static int add10(int x) {
  return x + 10;
}
static int mul30(int x) {
  return x * 30;
}

static void do_test(int init_val,
                    size_t length,
                    const funcptr functions[length],
                    int expected) {
  int actual = chain(init_val, length, functions);
  printf("Expected = %d, actual = %d -> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(666, 0, NULL, 666);
  sample_test(50, ((const funcptr[]){add10}), 60);
  sample_test(50, ((const funcptr[]){mul30}), 1500);
  sample_test(50, ((const funcptr[]){add10, add10}), 70);
  sample_test(50, ((const funcptr[]){add10, mul30}), 1800);
  sample_test(50, ((const funcptr[]){mul30, add10}), 1510);
  return 0;
}
