/*
8 kyu
Counting sheep...
https://www.codewars.com/kata/54edbc7200b811e956000556
*/

#include <stdbool.h>
#include <stdio.h>

size_t count_sheep(const bool sheep[], size_t count);

static void do_test(const bool sheep[], size_t count, int expected) {
  int actual = count_sheep(sheep, count);
  printf("Actual: %d, expected: %d -> %s\n", actual, expected,
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(((bool[]){true, true,  true, false, true,  true,  true,  true,
                    true, false, true, false, true,  false, false, true,
                    true, true,  true, true,  false, false, true,  true}),
          24, 17);
  do_test(((bool[]){
              true,
          }),
          1, 1);
  do_test(((bool[]){
              false,
          }),
          1, 0);
  do_test(((bool[]){
              true,
              true,
              true,
              false,
          }),
          4, 3);
  do_test(NULL, 0, 0);
  return 0;
}
