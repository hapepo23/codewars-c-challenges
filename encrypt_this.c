/*
6 kyu
Encrypt this!
https://www.codewars.com/kata/5848565e273af816fb000449
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt_this(const char* str) {
  int len = strlen(str);
  char* result = calloc(len * 3 + 1, sizeof(char));
  char s[len + 1];
  int pos = 0;
  strcpy(s, str);
  for (char* p = strtok(s, " "); p != NULL; p = strtok(NULL, " ")) {
    int l = strlen(p);
    pos += sprintf(result + pos, "%s%d", pos == 0 ? "" : " ", (int)(p[0]));
    for (int i = 1; i < l; i++, pos++) {
      if (i == 1)
        *(result + pos) = p[l - 1];
      else if (i == l - 1)
        *(result + pos) = p[1];
      else
        *(result + pos) = p[i];
    }
  }
  return result;
}
