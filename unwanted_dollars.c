/*
6 kyu
Unwanted dollars
https://www.codewars.com/kata/587309155cfd6b9fb60000a0
*/

#include <stdlib.h>
#include <string.h>

double money_value(const char* s) {
  unsigned l = strlen(s);
  unsigned pos = 0;
  char str[l + 1];
  for (unsigned i = 0; i < l; i++)
    if (strchr("-.1234567890", s[i]) != NULL)
      str[pos++] = s[i];
  str[pos] = '\0';
  return atof(str);
}
