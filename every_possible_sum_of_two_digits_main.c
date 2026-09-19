/*
7 kyu
Every possible sum of two digits
https://www.codewars.com/kata/5b4e474305f04bea11000148
*/

#include <stdio.h>
#include <string.h>

#define BUFF_LEN 256

size_t digits(unsigned number, unsigned result[BUFF_LEN]);

static char* stringer(size_t length,
                      const unsigned array[length],
                      char* arr_str) {
  size_t index = 0, pos = sprintf(arr_str, "{");
  while (index < length) {
    pos += sprintf(arr_str + pos, "%u%s", array[index],
                   (index == length - 1) ? "" : ", ");
    index++;
  }
  sprintf(arr_str + pos, "}");
  return arr_str;
}

static void tester(unsigned number,
                   size_t exp_len,
                   const unsigned expected[exp_len]) {
  unsigned submitted[BUFF_LEN];
  size_t sub_len = digits(number, submitted);
  char sub_str[23 * sub_len + 3];
  stringer(sub_len, submitted, sub_str);
  char exp_str[23 * exp_len + 3];
  stringer(exp_len, expected, exp_str);
  printf("Number = %u\nSubmitted: %s\nExpected:  %s\n-> %s\n\n", number,
         sub_str, exp_str, strcmp(sub_str, exp_str) == 0 ? "OK" : "FAIL");
}

int main(void) {
  {
    const unsigned number = 156;
    const unsigned expected[3] = {6, 7, 11};
    const size_t length = 3;
    tester(number, length, expected);
  }
  {
    const unsigned number = 81596;
    const unsigned expected[10] = {9, 13, 17, 14, 6, 10, 7, 14, 11, 15};
    const size_t length = 10;
    tester(number, length, expected);
  }
  {
    const unsigned number = 3852;
    const unsigned expected[6] = {11, 8, 5, 13, 10, 7};
    const size_t length = 6;
    tester(number, length, expected);
  }
  {
    const unsigned number = 3264128;
    const unsigned expected[21] = {5,  9, 7, 4,  5, 11, 8,  6, 3, 4, 10,
                                   10, 7, 8, 14, 5, 6,  12, 3, 9, 10};
    const size_t length = 21;
    tester(number, length, expected);
  }
  {
    const unsigned number = 999999;
    const unsigned expected[15] = {18, 18, 18, 18, 18, 18, 18, 18,
                                   18, 18, 18, 18, 18, 18, 18};
    const size_t length = 15;
    tester(number, length, expected);
  }
  {
    const unsigned number = 10;
    const unsigned expected[1] = {1};
    const size_t length = 1;
    tester(number, length, expected);
  }
  {
    const unsigned number = 0;
    const unsigned* expected = NULL;
    const size_t length = 0;
    tester(number, length, expected);
  }
  {
    const unsigned number = 6;
    const unsigned* expected = NULL;
    const size_t length = 0;
    tester(number, length, expected);
  }
  return 0;
}
