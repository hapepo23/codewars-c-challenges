/*
6 kyu
Assemble string
https://www.codewars.com/kata/6210fb7aabf047000f3a3ad6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(strings, expected) \
  do_test(ARR_LEN(strings), strings, expected)

char* assemble_string(char* assembled,
                      size_t rows,
                      const char* const strings[rows]);

static void print_strings(size_t rows, const char* const strings[rows]) {
  printf("{\n");
  for (size_t row = 0; row < rows; row++)
    printf("  \"%s\"%s\n", strings[row], (row == rows - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(size_t rows,
                    const char* const strings[rows],
                    const char* expected) {
  const size_t mem_size = strlen(expected) + 1;
  char* user_string = memset(malloc(mem_size), '@', mem_size);
  char* actual = assemble_string(user_string, rows, strings);
  puts("For strings:");
  print_strings(rows, strings);
  printf(
      "expected: \"%s\"\nactual  : \"%s\"\n-> %s\n\n", expected, actual,
      strcmp(actual, expected) == 0 && actual == user_string ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  do_test(0, NULL, "");
  fixed_test(
      ((const char*[]){"H*llo, W*rld!", "Hel*o, *or*d!", "*ello* World*"}),
      "Hello, World!");
  fixed_test(((const char*[]){".** . .' .'' ! ! .", ". . . .' **' ! * .",
                              "* . .*.* .'' * ! .", ". . .*.' .**** ! .",
                              "**. * .* .*' ! ! ."}),
             ". . . .' .'' ! ! .");
  fixed_test(
      ((const char*[]){". . . .", ". . . .", ". . . .", ". . . .", ". . . ."}),
      ". . . .");
  fixed_test(((const char*[]){"12***6789", "**3456789", "12345**8*",
                              "***456**9", "1*3*5*7*9", "*2*456789"}),
             "123456789");
  fixed_test(((const char*[]){"******", "******", "******", "******"}),
             "######");
  fixed_test(((const char*[]){"*#*#*#*#*#*#*#*", "*#*#*#*#*#*#*#*",
                              "*#*#*#*#*#*#*#*", "*#*#*#*#*#*#*#*"}),
             "###############");
  fixed_test(((const char*[]){"", ""}), "");
  return 0;
}
