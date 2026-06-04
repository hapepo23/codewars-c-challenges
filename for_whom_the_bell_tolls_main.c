/*
6 kyu
For whom the Bell tolls
https://www.codewars.com/kata/62665d43e67fbaf7b37212d2
*/

#include <stdio.h>
#include <string.h>

void bell(unsigned n, unsigned* array);

void do_test(unsigned n, unsigned* expected) {
  unsigned submitted[n];
  char sub_str[4 * n + 3], exp_str[4 * n + 3];
  bell(n, submitted);
  for (unsigned i = 0; i < n; i++) {
    unsigned s = 0, p = sprintf(sub_str, "{");
    while (s < n)
      p += sprintf(sub_str + p, "%u, ", submitted[s++]);
    sprintf(sub_str + p - 2, "}");
    unsigned e = 0, q = sprintf(exp_str, "{");
    while (e < n)
      q += sprintf(exp_str + q, "%u, ", expected[e++]);
    sprintf(exp_str + q - 2, "}");
  }
  printf("n = %u\nSubmitted: %s\nExpected:  %s\n-> %s\n\n", n, sub_str, exp_str,
         strcmp(sub_str, exp_str) == 0 ? "OK" : "FAIL");
}

int main(void) {
  {
    unsigned expected[1] = {1};
    do_test(1, expected);
  }
  {
    unsigned expected[2] = {2, 2};
    do_test(2, expected);
  }
  {
    unsigned expected[3] = {3, 4, 3};
    do_test(3, expected);
  }
  {
    unsigned expected[4] = {4, 6, 6, 4};
    do_test(4, expected);
  }
  {
    unsigned expected[5] = {5, 8, 9, 8, 5};
    do_test(5, expected);
  }
  {
    unsigned expected[6] = {6, 10, 12, 12, 10, 6};
    do_test(6, expected);
  }
  {
    unsigned expected[7] = {7, 12, 15, 16, 15, 12, 7};
    do_test(7, expected);
  }
  {
    unsigned expected[8] = {8, 14, 18, 20, 20, 18, 14, 8};
    do_test(8, expected);
  }
  {
    unsigned expected[9] = {9, 16, 21, 24, 25, 24, 21, 16, 9};
    do_test(9, expected);
  }
  {
    unsigned expected[10] = {10, 18, 24, 28, 30, 30, 28, 24, 18, 10};
    do_test(10, expected);
  }
  {
    unsigned expected[11] = {11, 20, 27, 32, 35, 36, 35, 32, 27, 20, 11};
    do_test(11, expected);
  }
  {
    unsigned expected[12] = {12, 22, 30, 36, 40, 42, 42, 40, 36, 30, 22, 12};
    do_test(12, expected);
  }
  return 0;
}
