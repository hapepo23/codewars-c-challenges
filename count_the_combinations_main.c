/*
7 kyu
Count the Combinations
https://www.codewars.com/kata/58e67378fd2d897b8a000110
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t num_combo(size_t length, const unsigned array[length], unsigned number);

static void make_arr_str(size_t length,
                         const unsigned array[length],
                         char* arr_str) {
  if (!length)
    strcpy(arr_str, "(null)");
  else {
    size_t index = 0, pos = sprintf(arr_str, "{");
    while (index < length) {
      pos += sprintf(arr_str + pos, "%u, ", array[index++]);
    }
    sprintf(arr_str + pos - 2, "}");
  }
}

static void do_test(size_t length,
                    const unsigned array[length],
                    unsigned number,
                    size_t expected) {
  size_t submitted = num_combo(length, array, number);
  char arr_str[22 * length + 1];
  make_arr_str(length, array, arr_str);
  printf(
      "Array    = %s\nNumber   = %u\nActual   = %zu\nExpected = %zu\n-> %s\n\n",
      arr_str, number, submitted, expected,
      submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const unsigned array[5] = {2, 0, 0, 0, 1};
    do_test(5, array, 1, 1);
  }
  {
    const unsigned array[5] = {2, 0, 0, 0, 1};
    do_test(5, array, 3, 3);
  }
  {
    const unsigned array[5] = {0, 0, 0, 0, 0};
    do_test(5, array, 0, 5);
  }
  {
    const unsigned array[5] = {0, 0, 0, 0, 1};
    do_test(5, array, 1, 4);
  }
  {
    const unsigned array[5] = {0, 0, 0, 0, 1};
    do_test(5, array, 2, 0);
  }
  return 0;
}
