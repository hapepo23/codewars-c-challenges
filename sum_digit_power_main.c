/*
6 kyu
Take a Number And Sum Its Digits Raised To The Consecutive Powers
https://www.codewars.com/kata/5626b561280a42ecc50000d1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

ull* sum_dig_pow(ull a, ull b, ull* results, size_t* length);

void tester(ull a, ull b, size_t exp_len, ull expected[exp_len]) {
  ull results[exp_len];
  for (size_t i = 0; i < exp_len; i++) {
    results[i] = rand() - rand();
  }
  size_t sub_len = 0;
  ull* submitted = sum_dig_pow(a, b, (ull*)results, &sub_len);
  printf("Length actual = %zu, expected = %zu -> %s\n", sub_len, exp_len,
         sub_len == exp_len ? "OK" : "FAIL");
  if (sub_len == exp_len && exp_len > 0) {
    char sub_str[7 * sub_len + 3];
    size_t s = 0, p = sprintf(sub_str, "{");
    while (s < sub_len)
      p += sprintf(sub_str + p, "%llu, ", submitted[s++]);
    sprintf(sub_str + p - 2, "}");
    char exp_str[7 * exp_len + 3];
    size_t e = 0, q = sprintf(exp_str, "{");
    while (e < exp_len)
      q += sprintf(exp_str + q, "%llu, ", expected[e++]);
    sprintf(exp_str + q - 2, "}");
    printf("Submitted = %s\nExpected  = %s\n-> %s\n\n", sub_str, exp_str,
           strcmp(sub_str, exp_str) == 0 ? "OK" : "FAIL");
  } else
    puts("");
}

int main(void) {
  {
    ull a = 1;
    ull b = 10;
    const ull expected[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    tester(a, b, 9, (ull*)expected);
  }
  {
    ull a = 1;
    ull b = 100;
    const ull expected[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 89};
    tester(a, b, 10, (ull*)expected);
  }
  {
    ull a = 10;
    ull b = 100;
    const ull expected[1] = {89};
    tester(a, b, 1, (ull*)expected);
  }
  {
    ull a = 90;
    ull b = 100;
    const ull* expected = NULL;
    tester(a, b, 0, (ull*)expected);
  }
  {
    ull a = 90;
    ull b = 150;
    const ull expected[1] = {135};
    tester(a, b, 1, (ull*)expected);
  }
  {
    ull a = 50;
    ull b = 150;
    const ull expected[2] = {89, 135};
    tester(a, b, 2, (ull*)expected);
  }
  {
    ull a = 10;
    ull b = 150;
    const ull expected[2] = {89, 135};
    tester(a, b, 2, (ull*)expected);
  }
  return 0;
}
