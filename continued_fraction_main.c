/*
6 kyu
Continued Fraction
https://www.codewars.com/kata/660e5631b673a8004b71d208
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIXTEEN 16

void continued_fraction(unsigned numer,
                        unsigned denom,
                        unsigned* results,
                        size_t* length);

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

static void tester(unsigned numer,
                   unsigned denom,
                   size_t exp_len,
                   const unsigned expected[exp_len]) {
  unsigned submitted[exp_len + SIXTEEN];
  memset(submitted, 0u, (exp_len + SIXTEEN) * sizeof(unsigned));
  size_t sub_len = rand() % SIXTEEN + 1;
  continued_fraction(numer, denom, submitted, &sub_len);
  char sub_str[22 * exp_len + 1];
  char exp_str[22 * exp_len + 1];
  char message[200] = {0};
  char phrase[115] = {0};
  bool judgement = true;
  if (sub_len != exp_len) {
    sprintf(phrase, "Length was set to wrong value: %zu should be %zu.",
            sub_len, exp_len);
    judgement = false;
  } else if (exp_len == 0) {
    for (size_t index = 0; index < SIXTEEN; index++) {
      if (submitted[index] != 0) {
        sprintf(phrase,
                "When zero values are passed in,\nno assignments to *results "
                "should occur.\n  -->  mutation detected at index %zu",
                index);
        judgement = false;
        sub_len = index + 1;
        break;
      }
    }
  } else {
    for (size_t index = 0; index < exp_len; index++) {
      if (submitted[index] != expected[index]) {
        sprintf(phrase, "Results array contains incorrect values");
        judgement = false;
        break;
      }
    }
  }
  make_arr_str(sub_len, submitted, sub_str);
  make_arr_str(exp_len, expected, exp_str);
  sprintf(message,
          "%s\nnumer = %u\ndenom = %u\n"
          "Submitted: %s\nExpected:  %s",
          phrase, numer, denom, sub_str, exp_str);
  printf("-> %s%s\n\n", judgement ? "OK" : "FAIL\n", message);
}

int main(void) {
  {
    const unsigned expected[5] = {2, 6, 3, 1, 5};
    tester(311, 144, 5, expected);
  }
  {
    const unsigned expected[5] = {2, 3, 17, 1, 5};
    tester(761, 327, 5, expected);
  }
  {
    const unsigned expected[3] = {191, 4, 2};
    tester(1721, 9, 3, expected);
  }
  {
    const unsigned expected[1] = {121};
    tester(1089, 9, 1, expected);
  }
  {
    const unsigned expected[1] = {847};
    tester(11011, 13, 1, expected);
  }
  {
    const unsigned expected[1] = {69};
    tester(1173, 17, 1, expected);
  }
  {
    const unsigned* expected = NULL;
    tester(0, 15, 0, expected);
  }
  return 0;
}
