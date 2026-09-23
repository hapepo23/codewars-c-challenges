/*
6 kyu
The most common letter
https://www.codewars.com/kata/5a434a9dc5e284724f000011
*/

#include <ctype.h>

void replace_most_common(char* string, char letter) {
  int count[26] = {0};
  int fpos[26] = {0};
  char* p = string;
  int pos = 0;
  while (*p) {
    pos++;
    if (islower(*p)) {
      int index = *p - 'a';
      count[index]++;
      if (fpos[index] == 0)
        fpos[index] = pos;
    }
    p++;
  }
  int high = 0;
  for (int i = 0; i < 26; i++)
    if (count[i] > high)
      high = count[i];
  char c = ' ';
  for (int i = 0; i < 26; i++)
    if (count[i] == high && fpos[i] < pos) {
      pos = fpos[i];
      c = 'a' + i;
    }
  p = string;
  while (*p) {
    if (*p == c)
      *p = letter;
    p++;
  }
}
