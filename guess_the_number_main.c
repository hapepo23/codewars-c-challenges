/*
6 kyu
Guess the number!
https://www.codewars.com/kata/5452113c699b538c18000b01
*/

#include <stdio.h>

int get_number(void);

enum Status { CORRECT, TOO_LOW, TOO_HIGH };

static int solution;
static unsigned calls;
static const unsigned MAX_CALLS = 10;

enum Status guess(int number) {
  if (++calls > MAX_CALLS) {
    printf(
        "You cannot call guess() more than %u times! The solutions was %d -> "
        "FAIL\n",
        MAX_CALLS, solution);
  }
  if (number == solution)
    return CORRECT;
  else if (number > solution)
    return TOO_HIGH;
  else
    return TOO_LOW;
}

static void do_test(int number) {
  calls = 0;
  solution = number;
  const int actual = get_number();
  printf("You guessed %d, and the solution was %d -> %s\n", actual, solution,
         actual == solution ? "OK" : "FAIL");
}

int main(void) {
  do_test(1);
  do_test(222);
  do_test(500);
  do_test(666);
  do_test(1000);
  return 0;
}
