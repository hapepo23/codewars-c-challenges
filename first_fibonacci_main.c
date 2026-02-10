/*
7 kyu
First Fibonacci
https://www.codewars.com/kata/6965d769930fb2eff921668f
*/

#include <stdio.h>

typedef struct {
  unsigned first;
  unsigned second;
} pair;

pair solution(unsigned first, unsigned second);

static void do_test(pair problem, pair expected) {
  pair submitted = solution(problem.first, problem.second);
  printf(
      "Given = {%u, %u}, submitted = {%u, %u}, expected  = {%u, %u} -> %s\n",
      problem.first, problem.second, submitted.first, submitted.second,
      expected.first, expected.second,
      submitted.first == expected.first && submitted.second == expected.second
          ? "OK"
          : "FAIL");
}

int main(void) {
  do_test((pair){3, 5}, (pair){0, 1});
  do_test((pair){398, 644}, (pair){2, 6});
  do_test((pair){15, 28}, (pair){2, 13});
  do_test((pair){186, 301}, (pair){3, 7});
  do_test((pair){265, 429}, (pair){1, 12});
  do_test((pair){1186, 1919}, (pair){2, 7});
  return 0;
}
