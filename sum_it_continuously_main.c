/*
7 kyu
Sum it continuously
https://www.codewars.com/kata/59b44d00bf10a439dd00006f
*/

#include <stdio.h>
#include <string.h>

void add(size_t length, const int array[length], int output[length]);

static void make_arr_str(size_t length,
                         const int array[length],
                         char* arr_str) {
  if (!length)
    strcpy(arr_str, "(null)");
  else {
    size_t index = 0, pos = sprintf(arr_str, "{");
    while (index < length) {
      pos += sprintf(arr_str + pos, "%d, ", array[index++]);
    }
    sprintf(arr_str + pos - 2, "}");
  }
}

static void tester(size_t length,
                   const int array[length],
                   const int expected[length]) {
  int submitted[length];
  for (size_t index = 0; index < length; index++) {
    submitted[index] = 99;
  }
  add(length, array, submitted);
  int judgement = 1;
  for (size_t index = 0; index < length; index++) {
    if (submitted[index] != expected[index]) {
      judgement = 0;
      break;
    }
  }
  char arr_str[22 * length + 1];
  char sub_str[22 * length + 1];
  char exp_str[22 * length + 1];
  make_arr_str(length, array, arr_str);
  make_arr_str(length, submitted, sub_str);
  make_arr_str(length, expected, exp_str);
  printf("Array    = %s\nActual   = %s\nExpected = %s\n-> %s\n\n", arr_str,
         sub_str, exp_str, judgement ? "OK" : "FAIL");
}

int main(void) {
  {
    const int array[1] = {0};
    const int expected[1] = {0};
    tester(1, array, expected);
  }
  {
    const int array[1] = {-33};
    const int expected[1] = {-33};
    tester(1, array, expected);
  }
  {
    const int array[4] = {32, -9, 2, 0};
    const int expected[4] = {32, 23, 25, 25};
    tester(4, array, expected);
  }
  {
    const int array[5] = {1, 2, 3, 4, 5};
    const int expected[5] = {1, 3, 6, 10, 15};
    tester(5, array, expected);
  }
  {
    const int array[5] = {2, 4, 6, 8, 10};
    const int expected[5] = {2, 6, 12, 20, 30};
    tester(5, array, expected);
  }
  {
    const int array[5] = {1, 8, 27, 64, 125};
    const int expected[5] = {1, 9, 36, 100, 225};
    tester(5, array, expected);
  }
  {
    const int array[6] = {9, 18, 27, 36, 45, 54};
    const int expected[6] = {9, 27, 54, 90, 135, 189};
    tester(6, array, expected);
  }
  {
    const int array[7] = {6, 12, 18, 24, 30, 36, 42};
    const int expected[7] = {6, 18, 36, 60, 90, 126, 168};
    tester(7, array, expected);
  }
  {
    const int array[8] = {8, 16, 24, 32, 40, 48, 56, 64};
    const int expected[8] = {8, 24, 48, 80, 120, 168, 224, 288};
    tester(8, array, expected);
  }
  return 0;
}
