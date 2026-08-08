/*
6 kyu
If you can read this...
https://www.codewars.com/kata/586538146b56991861000293
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NATO['A'] == "Alfa", etc
extern const char* const NATO[];

char* to_nato(const char* words) {
  int l = strlen(words);
  char* result = calloc(l * 10 + 1, sizeof(char));
  int pos = 0;
  while (*words) {
    if (isalpha(*words))
      pos += sprintf(result + pos, "%s%s", pos == 0 ? "" : " ",
                     NATO[toupper(*words)]);
    else if (*words != ' ')
      pos += sprintf(result + pos, "%s%c", pos == 0 ? "" : " ", *words);
    words++;
  }
  return result;
}
