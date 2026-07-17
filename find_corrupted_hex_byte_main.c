/*
7 kyu
Find The Corrupted Hex Byte
https://www.codewars.com/kata/6a54d3e91e9fb16ca31cc912
*/

#include <stdio.h>
#include <sys/types.h>

ssize_t find_corrupted_byte(size_t length, const char* dump[length]);

static char* stringer(size_t length, const char* array[length], char* arr_str) {
  size_t index = 0, pos = sprintf(arr_str, "{");
  while (index < length) {
    pos += sprintf(arr_str + pos, "\"%s\"%s", array[index],
                   (index == length - 1) ? "" : ", ");
    index++;
  }
  sprintf(arr_str + pos, "}");
  return arr_str;
}

static void do_test(size_t length, const char* dump[length], ssize_t expected) {
  ssize_t actual = find_corrupted_byte(length, dump);
  char dumpst[10 * length + 3];
  printf("Dump = %s\nActual: %zd, Expected: %zd -> %s\n\n",
         stringer(length, dump, dumpst), actual, expected,
         actual == expected ? "OK" : "FAIL");
}

int main(void) {
  {
    const char* dump[5] = {"48", "65", "6C", "6C", "6F"};
    ssize_t exp = -1;
    do_test(5, dump, exp);
  }
  {
    const char* dump[5] = {"48", "65", "6G", "6C", "6F"};
    ssize_t exp = 2;
    do_test(5, dump, exp);
  }
  {
    const char* dump[3] = {"48", "6", "6C"};
    ssize_t exp = 1;
    do_test(3, dump, exp);
  }
  {
    const char* dump[3] = {"48", "6c", "6F"};
    ssize_t exp = 1;
    do_test(3, dump, exp);
  }
  {
    const char* dump[3] = {"FF", "00", "123"};
    ssize_t exp = 2;
    do_test(3, dump, exp);
  }
  return 0;
}
