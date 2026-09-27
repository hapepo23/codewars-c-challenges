/*
6 kyu
Give me a Diamond
https://www.codewars.com/kata/5503013e34137eeeaa001648
*/

#include <stdlib.h>
#include <string.h>

static void repeat_char(char* dest, int num, char c, int* pos) {
  for (int i = 0; i < num; i++) {
    dest[*pos] = c;
    (*pos)++;
  }
}

char* diamond(int n) {
  if (n <= 0 || n % 2 == 0)
    return NULL;
  char* result = calloc((n + 1) * n, sizeof(char));
  int pos = 0;
  for (int i = 1; i < n; i += 2) {
    repeat_char(result, (n - i) / 2, ' ', &pos);
    repeat_char(result, i, '*', &pos);
    repeat_char(result, 1, '\n', &pos);
  }
  repeat_char(result, n, '*', &pos);
  repeat_char(result, 1, '\n', &pos);
  for (int i = n - 2; i > 0; i -= 2) {
    repeat_char(result, (n - i) / 2, ' ', &pos);
    repeat_char(result, i, '*', &pos);
    repeat_char(result, 1, '\n', &pos);
  }
  return result;
}
