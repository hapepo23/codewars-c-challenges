/*
7 kyu
Sum of two lowest positive integers
https://www.codewars.com/kata/558fc85d8fd1938afb000014
*/

#include <stddef.h>
#include <stdio.h>

long long sum_two_smallest_numbers(size_t n, const int numbers[n]);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(size_t n, const int numbers[n], long long expected) {
  long long actual = sum_two_smallest_numbers(n, numbers);
  printf("array = ");
  print_array(n, numbers);
  printf(", expected %lld, actual %lld --> %s\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    const int numbers[5] = {19, 5, 42, 2, 77};
    do_test(5, numbers, 7);
  }
  {
    const int numbers[5] = {5, 8, 12, 19, 22};
    do_test(5, numbers, 13);
  }
  return 0;
}
