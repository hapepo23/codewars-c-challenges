/*
7 kyu
How Many Lonely Letters?
https://www.codewars.com/kata/69cda5b85599f307742ce70a
*/

#include <ctype.h>

unsigned count_lonely_letters(const char* text) {
  unsigned cnt[28] = {0};
  while (*text) {
    if (isalpha(*text))
      cnt[tolower(*text) - 96]++;
    text++;
  }
  unsigned result = 0;
  for (int i = 1; i <= 26; i++)
    if (cnt[i] == 1 && cnt[i - 1] == 0 && cnt[i + 1] == 0)
      result++;
  return result;
}
