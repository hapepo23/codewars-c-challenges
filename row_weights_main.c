/*
7 kyu
Row Weights
https://www.codewars.com/kata/5abd66a5ccfd1130b30000a9
*/

#include <stdio.h>

#define RUN_TEST(arr, exp) doTest((arr), sizeof(arr) / sizeof((arr)[0]), (exp));

void rowWeights(const int weights[], int count, int teams[]);

static void doTest(const int weights[], int count, int expected[]) {
  int teams[2] = {0};
  rowWeights(weights, count, teams);
  printf(
      "Team 1: expected %d, but received %d, Team 2: expected %d, but received "
      "%d --> %s\n",
      expected[0], teams[0], expected[1], teams[1],
      expected[0] == teams[0] && expected[1] == teams[1] ? "OK" : "FAIL");
}

int main(void) {
  {
    int arr[] = {80}, exp[] = {80, 0};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {100, 50}, exp[] = {100, 50};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {50, 60, 70, 80}, exp[] = {120, 140};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {13, 27, 49}, exp[] = {62, 27};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {70, 58, 75, 34, 91}, exp[] = {236, 92};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {29, 83, 67, 53, 19, 28, 96}, exp[] = {211, 164};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {100, 50}, exp[] = {100, 50};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {100, 51, 50, 100}, exp[] = {150, 151};
    RUN_TEST(arr, exp);
  }
  {
    int arr[] = {39, 84, 74, 18, 59, 72, 35, 61}, exp[] = {207, 235};
    RUN_TEST(arr, exp);
  }
  return 0;
}
