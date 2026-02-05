/*
5 kyu
Sort - one, three, two
https://www.codewars.com/kata/56f4ff45af5b1f8cd100067d
*/

#include <stdlib.h>
#include <string.h>

static const char* ones[] = {"zero",    "one",       "two",      "three",
                             "four",    "five",      "six",      "seven",
                             "eight",   "nine",      "ten",      "eleven",
                             "twelve",  "thirteen",  "fourteen", "fifteen",
                             "sixteen", "seventeen", "eighteen", "nineteen"};

static const char* tens[] = {"",      "",      "twenty",  "thirty", "forty",
                             "fifty", "sixty", "seventy", "eighty", "ninety"};

static void number_below_1000(int n, char* out) {
  out[0] = '\0';
  if (n >= 100) {
    strcat(out, ones[n / 100]);
    strcat(out, " hundred");
    n %= 100;
    if (n > 0)
      strcat(out, " ");
  }
  if (n >= 20) {
    strcat(out, tens[n / 10]);
    if (n % 10 != 0) {
      strcat(out, "-");
      strcat(out, ones[n % 10]);
    }
  } else if (n > 0) {
    strcat(out, ones[n]);
  }
}

static char* number_to_words(unsigned n, char* num_string) {
  num_string[0] = '\0';
  if (n == 0) {
    strcpy(num_string, "zero");
    return num_string;
  }
  if (n >= 1000) {
    number_below_1000(n / 1000, num_string);
    strcat(num_string, " thousand");
    n %= 1000;
    if (n > 0)
      strcat(num_string, " ");
  }
  if (n > 0) {
    char temp[128];
    number_below_1000(n, temp);
    strcat(num_string, temp);
  }
  return num_string;
}

static int compare_by_words(const void* a, const void* b) {
  static char sx[256], sy[256];
  int x = *(const int*)a;
  int y = *(const int*)b;
  const char* wx = number_to_words(x, sx);
  const char* wy = number_to_words(y, sy);
  return strcmp(wx, wy);
}

int* sort(const int* array, int length) {
  if (length <= 0)
    return NULL;
  int* result = malloc(length * sizeof(int));
  if (!result)
    return NULL;
  memcpy(result, array, length * sizeof(int));
  qsort(result, length, sizeof(int), compare_by_words);
  return result;
}
