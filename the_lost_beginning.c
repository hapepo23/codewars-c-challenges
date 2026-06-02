/*
6 kyu
The lost beginning
https://www.codewars.com/kata/659af96994b858db10e1675f
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buf[12];

static bool check(const char* s, const int len, int* ppos, const int num) {
  int numlen = sprintf(buf, "%d", num);
  if (*ppos + numlen > len) {
    *ppos += numlen;
    return false;
  }
  bool result = memcmp(s + (*ppos), buf, numlen) == 0;
  (*ppos) += numlen;
  return result;
}

int find(const char* s) {
  int lens = strlen(s);
  int result;
  for (int len = 1; len <= 10; len++) {
    strncpy(buf, s, len);
    buf[len] = '\0';
    result = atoi(buf);
    int num = result + 1;
    int pos = len;
    if (pos == lens)
      return result;
    while (pos <= lens) {
      if (!check(s, lens, &pos, num))
        break;
      if (pos == lens)
        return result;
      num++;
    }
  }
  return result;  // should not happen
}