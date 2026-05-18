/*
6 kyu
Word a10n (abbreviation)
https://www.codewars.com/kata/5375f921003bf62192000746
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* abbreviate(const char* str) {
  char* result = calloc(strlen(str) + 1, sizeof(char));
  const char* p = str;
  char* q = result;
  while (*p) {
    if (isalpha(*p)) {
      const char* r = p;
      while (isalpha(*r))
        r++;
      if (r - p > 3) {
        *(q++) = *p;
        int cnt = sprintf(q, "%ld", r - p - 2);
        q += cnt;
        *(q++) = *(r - 1);
        p = r;
      } else {
        while (p < r)
          *(q++) = *(p++);
      }
    } else {
      *(q++) = *(p++);
    }
  }
  return result;
}
