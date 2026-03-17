/*
7 kyu
Reverse words
https://www.codewars.com/kata/5259b20d6021e9e14c0010d4
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

char* reverseWords(const char* text) {
  char* result = calloc(strlen(text) + 1, sizeof(char));
  const char* ptext = text;
  char* presult = result;
  while (*ptext != '\0') {
    if (*ptext != ' ') {
      char* pstart = presult;
      while (*ptext != ' ' && *ptext != '\0')
        *(presult++) = *(ptext++);
      reverse(pstart, (int)(presult - pstart));
    } else
      *(presult++) = *(ptext++);
  }
  return result;
}
