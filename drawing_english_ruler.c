/*
6 kyu
Drawing English Ruler
https://www.codewars.com/kata/696fe8b06b4e2e6ddb50caa8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* result;
static unsigned resultlen;

static void mark(int h, int num) {
  if (strlen(result) > (resultlen - h - 20)) {
    resultlen *= 2;
    result = realloc(result, resultlen * sizeof(char));
  }
  for (int i = 1; i <= h; i++)
    result = strcat(result, "-");
  if (num >= 0) {
    result = strcat(result, " ");
    sprintf(result + strlen(result), "%d", num);
  }
  result = strcat(result, "\n");
}

static void rule(int l, int r, int h) {
  if (h > 0) {
    int m = (l + r) / 2;
    rule(l, m, h - 1);
    mark(h, -1);
    rule(m, r, h - 1);
  }
}

char* draw_ruler(int t, int n) {
  resultlen = 100;
  result = malloc(resultlen * sizeof(char));
  *result = '\0';
  mark(t, 0);
  for (int i = 1; i <= n; i++) {
    rule(0, t * 2, t - 1);
    mark(t, i);
  }
  result[strlen(result) - 1] = '\0';
  return result;
}
