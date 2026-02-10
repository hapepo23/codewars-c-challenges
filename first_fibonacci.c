/*
7 kyu
First Fibonacci
https://www.codewars.com/kata/6965d769930fb2eff921668f
*/

typedef struct {
  unsigned first;
  unsigned second;
} pair;

pair solution(unsigned first, unsigned second) {
  while (second <= 2 * first) {
    unsigned s = second - first;
    second = first;
    first = s;
  }
  return (pair){first, second};
}
