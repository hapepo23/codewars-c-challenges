/*
7 kyu
Frequency sequence
https://www.codewars.com/kata/585a033e3a36cdc50a00011c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* char_frequencies(const char* string, char separator) {
  int freq[128] = {0};
  int len = strlen(string);
  for (int i = 0; i < len; i++)
    freq[(int)string[i]]++;
  int l = 0;
  char buf[12];
  for (int i = 0; i < len; i++) {
    if (i > 0)
      l++;
    l += sprintf(buf, "%d", freq[(int)string[i]]);
  }
  char* result = calloc(l + 1, sizeof(char));
  int pos = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0) {
      result[pos] = separator;
      pos++;
    }
    pos += sprintf(result + pos, "%d", freq[(int)string[i]]);
  }
  return result;
}
