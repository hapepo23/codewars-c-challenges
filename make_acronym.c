/*
7 kyu
Make acronym
https://www.codewars.com/kata/57a60bad72292d3e93000a5a
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* to_acronym(const char* words) {
  size_t l = strlen(words);
  char* result = calloc(l + 1, sizeof(char));
  if (*words) {
    size_t pos = 0;
    result[pos++] = toupper(*(words++));
    while (*words) {
      if (*(words - 1) == ' ')
        result[pos++] = toupper(*words);
      words++;
    }
  }
  return result;
}
