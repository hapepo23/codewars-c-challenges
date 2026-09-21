/*
7 kyu
Even and Odd!
https://www.codewars.com/kata/594adadee075005308000122
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull* eval(ull n);

static void test(ull n, const ull expected[2]) {
  ull* actual = eval(n);
  printf("For n = %llu, expected {%llu, %llu}, but got {%llu, %llu} -> %s\n", n,
         expected[0], expected[1], actual[0], actual[1],
         expected[0] == actual[0] && expected[1] == actual[1] ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  test(2134563, (ull[]){246, 1353});
  test(20468, (ull[]){20468, 0});
  test(0, (ull[]){0, 0});
  return 0;
}
