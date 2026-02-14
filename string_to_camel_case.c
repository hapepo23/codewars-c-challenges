/*
6 kyu
CamelCase Method
https://www.codewars.com/kata/587731fda577b3d1b0001196
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* camel_case(const char* s) {
  bool upper_case = true;
  int pos = 0;
  char* result = calloc(strlen(s) + 1, sizeof(char));
  while (*s) {
    if (*s == ' ')
      upper_case = true;
    else {
      result[pos++] = upper_case ? (char)toupper(*s) : *s;
      upper_case = false;
    }
    s++;
  }
  return result;
}
