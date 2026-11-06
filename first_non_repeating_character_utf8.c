/*
5 kyu
First non-repeating character
https://www.codewars.com/kata/52bc74d4ac05d0945d00054e
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t codepoint;

static codepoint utf8_decode(const unsigned char** p) {
  const unsigned char* s = *p;
  codepoint cp;
  unsigned char c = *s++;
  if (c < 0x80) {
    cp = c;
  } else if (c < 0xE0) {
    cp = (c & 0x1F);
    cp = (cp << 6) | (*s++ & 0x3F);
  } else if (c < 0xF0) {
    cp = (c & 0x0F);
    cp = (cp << 6) | (*s++ & 0x3F);
    cp = (cp << 6) | (*s++ & 0x3F);
  } else {
    cp = (c & 0x07);
    cp = (cp << 6) | (*s++ & 0x3F);
    cp = (cp << 6) | (*s++ & 0x3F);
    cp = (cp << 6) | (*s++ & 0x3F);
  }
  *p = s;
  return cp;
}

static codepoint ascii_case_folding(codepoint cp) {
  if (cp >= 'A' && cp <= 'Z')
    cp += 'a' - 'A';
  return cp;
}

void first_non_repeating_codepoint(char output[5], const char* utf8) {
  codepoint chars[strlen(utf8) + 1];
  const unsigned char* p = (const unsigned char*)utf8;
  size_t n = 0;
  output[0] = '\0';
  while (*p)
    chars[n++] = utf8_decode(&p);
  p = (const unsigned char*)utf8;
  for (size_t i = 0; i < n; i++) {
    int count = 0;
    for (size_t j = 0; j < n; j++) {
      if (ascii_case_folding(chars[i]) == ascii_case_folding(chars[j]))
        count++;
    }
    if (count == 1) {
      const unsigned char* start = p;
      utf8_decode(&p);
      size_t len = p - start;
      memcpy(output, start, len);
      output[len] = '\0';
      return;
    }
    utf8_decode(&p);
  }
}
