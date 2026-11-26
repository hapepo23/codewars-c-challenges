/*
7 kyu
Sorting the Odd way!
https://www.codewars.com/kata/57fb79784e2d0639c9000066
*/

#include <stdio.h>
#include <string.h>

void sort_it_out(size_t length,
                 const double array[length],
                 double sorted[length]);

static void double_stringer(size_t length,
                            const double array[length],
                            char* arr_str) {
  size_t index = 0, pos = sprintf(arr_str, "{");
  while (index < length) {
    pos += sprintf(arr_str + pos, "%.10g%s", array[index],
                   (index == length - 1) ? "" : ", ");
    index++;
  }
  sprintf(arr_str + pos, "}");
}

static void tester(size_t length,
                   const double array[length],
                   const double expected[length]) {
  double submitted[length];
  for (size_t i = 0; i < length; i++)
    submitted[i] = 999;
  sort_it_out(length, array, submitted);
  char arr_str[23 * length + 3];
  char sub_str[23 * length + 3];
  char exp_str[23 * length + 3];
  double_stringer(length, array, arr_str);
  double_stringer(length, submitted, sub_str);
  double_stringer(length, expected, exp_str);
  printf("Array    = %s\nActual   = %s\nExpected = %s\n-> %s\n\n", arr_str,
         sub_str, exp_str, strcmp(sub_str, exp_str) == 0 ? "OK" : "FAIL");
}

int main(void) {
  {
    const double array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const double expected[9] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    tester(9, array, expected);
  }
  {
    const double array[3] = {32, 5, 10};
    const double expected[3] = {5, 32, 10};
    tester(3, array, expected);
  }
  {
    const double array[9] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    const double expected[9] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    tester(9, array, expected);
  }
  {
    const double array[9] = {26, 243, 52, 2, 432414, 1, 11, 46, 32};
    const double expected[9] = {1, 11, 243, 432414, 52, 46, 32, 26, 2};
    tester(9, array, expected);
  }
  {
    const double array[9] = {19, 65, 88, 112, 60, 14, 33, 49, 88};
    const double expected[9] = {19, 33, 49, 65, 112, 88, 88, 60, 14};
    tester(9, array, expected);
  }
  {
    const double* array = NULL;
    const double* expected = NULL;
    tester(0, array, expected);
  }
  {
    const double array[11] = {68, 25, 99, 50, 10, 67, 2, 5, 8, 34, 67};
    const double expected[11] = {5, 25, 67, 67, 99, 68, 50, 34, 10, 8, 2};
    tester(11, array, expected);
  }
  {
    const double array[5] = {3.4, 5.6, 89, 513.1, 9};
    const double expected[5] = {3.4, 5.6, 9, 89, 513.1};
    tester(5, array, expected);
  }
  {
    const double array[9] = {11, 22, 33, 44, 55, 55, 90.4, 4, 78};
    const double expected[9] = {11, 33, 55, 55, 90.4, 78, 44, 22, 4};
    tester(9, array, expected);
  }
  {
    const double array[11] = {13, 2, 24.0, 66, 105, 369, 6, 42, 57, 63, 101};
    const double expected[11] = {13, 57, 63, 101, 105, 369, 66, 42, 24.0, 6, 2};
    tester(11, array, expected);
  }
  {
    const double array[6] = {6.6, 5.5, 1.1, 2.2, 3.3, 4.4};
    const double expected[6] = {1.1, 3.3, 5.5, 6.6, 4.4, 2.2};
    tester(6, array, expected);
  }
  {
    const double array[8] = {2.6, 3.5, 1.7, 4.9, 1.3, 2.4, 3.2, 4.8};
    const double expected[8] = {1.3, 1.7, 3.2, 3.5, 4.9, 4.8, 2.6, 2.4};
    tester(8, array, expected);
  }
  return 0;
}
