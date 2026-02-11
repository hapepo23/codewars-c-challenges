/*
6 kyu
Detect Pangram
https://www.codewars.com/kata/545cedaa9943f7fe7b000048
*/

#include <ctype.h>
#include <stdbool.h>

bool is_pangram(const char* str_in) {
  bool s[26] = {false};
  while (*str_in != '\0') {
    if (isupper(*str_in))
      s[*str_in - 'A'] = true;
    else if (islower(*str_in))
      s[*str_in - 'a'] = true;
    str_in++;
  }
  for (int i = 0; i < 26; i++)
    if (!s[i])
      return false;
  return true;
}
