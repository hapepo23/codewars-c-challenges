/*
6 kyu
Break camelCase
https://www.codewars.com/kata/5208f99aee097e6552000148
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* camelCase) {
  char* result = calloc(strlen(camelCase) * 2 + 1, sizeof(char));
  char* p = result;
  while (*camelCase) {
    *(p++) = *(camelCase++);
    if (isupper(*camelCase))
      *(p++) = ' ';
  }
  return result;
}
