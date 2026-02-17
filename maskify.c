/*
7 kyu
Credit Card Mask
https://www.codewars.com/kata/5412509bd436bd33920011bc
*/

#include <stddef.h>
#include <string.h>

#define LEN_NON_MASKED 4
#define MASK_CHAR '#'

char* maskify(char* masked, const char* string) {
  size_t len = strlen(string);
  strcpy(masked, string);
  if (len > LEN_NON_MASKED) {
    char* p = masked + len - LEN_NON_MASKED - 1;
    while (p >= masked)
      *p-- = MASK_CHAR;
  }
  return masked;
}
