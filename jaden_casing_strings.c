/*
7 kyu
Jaden Casing Strings
https://www.codewars.com/kata/5390bac347d09b7da40006f6
*/

#include <ctype.h>

char* to_jaden_case(char* jaden_case, const char* string) {
  char* p = jaden_case;
  if (*string)
    *(p++) = toupper(*(string++));
  else {
    *jaden_case = '\0';
    return jaden_case;
  }
  while (*string) {
    if (*(string - 1) == ' ')
      *(p++) = toupper(*(string++));
    else
      *(p++) = *(string++);
  }
  *p = '\0';
  return jaden_case;
}
