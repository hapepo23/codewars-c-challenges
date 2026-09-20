/*
7 kyu
Two Oldest Ages
https://www.codewars.com/kata/511f11d355fe575d2c000001
*/

#include <stdio.h>

void two_oldest_ages(size_t n, const int ages[n], int result[2]);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void tester(size_t n, const int ages[n], const int expected[2]) {
  int actual[2] = {666, 666};
  two_oldest_ages(n, ages, actual);
  printf("Ages = ");
  print_array(n, ages);
  printf("\n");
  printf("Expected {%d, %d}, but got {%d, %d}\n-> %s\n\n", expected[0],
         expected[1], actual[0], actual[1],
         actual[0] == expected[0] && actual[1] == expected[1] ? "OK" : "FAIL");
}

int main(void) {
  {
    const int ages[6] = {1, 5, 87, 45, 8, 8};
    const int oldest[2] = {45, 87};
    tester(6, ages, oldest);
  }
  {
    const int ages[6] = {6, 5, 83, 5, 3, 18};
    const int oldest[2] = {18, 83};
    tester(6, ages, oldest);
  }
  {
    const int ages[6] = {6, 5, 83, 5, 3, 83};
    const int oldest[2] = {83, 83};
    tester(6, ages, oldest);
  }
  {
    const int ages[2] = {10, 1};
    const int oldest[2] = {1, 10};
    tester(2, ages, oldest);
  }
  {
    const int ages[6] = {-6, -5, -83, -45, -3, -84};
    const int oldest[2] = {-5, -3};
    tester(6, ages, oldest);
  }
  return 0;
}
