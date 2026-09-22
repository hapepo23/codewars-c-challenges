/*
6 kyu
Is it an isogram?
https://www.codewars.com/kata/586d79182e8d9cfaba0000f1
*/

#include <ctype.h>
#include <stdbool.h>

bool is_isogram(const char* word) {
  int counts[26] = {0};
  while (*word) {
    if (isalpha(*word))
      counts[isupper(*word) ? (*word - 'A') : (*word - 'a')]++;
    word++;
  }
  int c = 0;
  for (int i = 0; i < 26; i++) {
    if (counts[i] > 0) {
      if (c == 0)
        c = counts[i];
      else if (c != counts[i])
        return false;
    }
  }
  return c != 0;
}
