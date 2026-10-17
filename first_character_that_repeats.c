/*
6 kyu
First character that repeats
https://www.codewars.com/kata/54f9f4d7c41722304e000bbb
*/

#include <limits.h>
#include <stdbool.h>

char first_duplicate(const char* string) {
  bool seen[UCHAR_MAX + 1] = {false};
  bool duplicate[UCHAR_MAX + 1] = {false};
  for (const char* p = string; *p; ++p) {
    unsigned char c = (unsigned char)*p;
    if (seen[c])
      duplicate[c] = true;
    seen[c] = true;
  }
  for (const char* p = string; *p; ++p)
    if (duplicate[(unsigned char)*p])
      return *p;
  return '\0';
}
