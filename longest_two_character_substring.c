/*
6 kyu
Longest 2-character substring
https://www.codewars.com/kata/55bc0c54147a98798f00003e
*/

#include <stdlib.h>
#include <string.h>

char* substring(const char* string) {
  int count[256] = {0};
  size_t left = 0;
  size_t best_start = 0;
  size_t best_len = 0;
  size_t unique = 0;
  for (size_t right = 0; string[right]; right++) {
    unsigned char c = (unsigned char)string[right];
    if (count[c]++ == 0)
      unique++;
    /* Shrink window until it contains at most 2 characters. */
    while (unique > 2) {
      unsigned char d = (unsigned char)string[left++];
      if (--count[d] == 0)
        unique--;
    }
    size_t len = right - left + 1;
    /* >, not >=, preserves the first occurrence. */
    if (len > best_len) {
      best_start = left;
      best_len = len;
    }
  }
  char* result = malloc(best_len + 1);
  if (!result)
    return NULL;
  memcpy(result, string + best_start, best_len);
  result[best_len] = '\0';
  return result;
}
