/*
7 kyu
Simple string reversal II
https://www.codewars.com/kata/5a8d1c82373c2e099d0000ac
*/

#include <stdlib.h>
#include <string.h>

static void reverse(char* s, int n) {
  int i, j;
  char c;
  for (i = 0, j = n - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

char* reverse_between(char* string, size_t a, size_t b) {
  size_t l = strlen(string);
  b = (b + 1 > l) ? l : b + 1;
  reverse(string + a, b - a);
  return string;
}
