/*
5 kyu
Grab CSV Columns
https://www.codewars.com/kata/5276c0f3f4bfbd5aae0001ad
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(arr) (sizeof(arr) / sizeof(*arr))
#define do_fixed_test(csv_str, indices_arr, expected) \
  (do_test(csv_str, ARR_LEN(indices_arr), indices_arr, expected))

void csv_columns(const char* csv_str,
                 size_t indices_len,
                 size_t indices[indices_len],
                 char* selected_cols);

static char* print_indices(size_t len, size_t* arr, char* buff) {
  char* buff_p = buff;
  *buff_p++ = '{';
  for (size_t i = 0; i < len; i++)
    buff_p += sprintf(buff_p, "%lu, ", arr[i]);
  strcpy(buff_p - 2, "}");
  return buff;
}

static void do_test(const char* csv_str,
                    size_t indices_len,
                    size_t indices[indices_len],
                    const char* expected) {
  char* actual = malloc(sizeof(char) * (strlen(expected) + 2));
  static char print_buff[32];
  csv_columns(csv_str, indices_len, indices, actual);
  printf(
      "for csv string:\n\"%s\"\nwith indices: %s\nexpected: \"%s\"\nactual  : "
      "\"%s\"\n%s\n\n",
      csv_str, print_indices(indices_len, indices, print_buff), expected,
      actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_fixed_test("1,2\n3,4\n5,6", ((size_t[]){5, 6, 7}), "");
  do_fixed_test("1,2,3\n4,5,6", ((size_t[]){0, 1}), "1,2\n4,5");
  do_fixed_test("a,b,c,d,e\n1,2,3,4,5\nf,g,h,i,j", ((size_t[]){1, 3, 5, 7}),
                "b,d\n2,4\ng,i");
  do_fixed_test("1\n2\n3\n4\n5", ((size_t[]){0, 1}), "1\n2\n3\n4\n5");
  do_fixed_test("1\n2\n3\n4\n5", ((size_t[]){1}), "");
  return 0;
}
