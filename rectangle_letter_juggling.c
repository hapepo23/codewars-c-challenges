/*
6 kyu
Rectangle letter juggling
https://www.codewars.com/kata/60d6f2653cbec40007c92755
*/

#include <stdlib.h>
#include <string.h>

char* encode(const char* plaintext) {
  size_t len = 0;
  for (const char* p = plaintext; *p; p++)
    if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
      len++;
  if (len == 0)
    return calloc(1, 1);
  size_t a = 1;
  while (a * (a + 1) < len)
    a++;
  size_t b = a + 1;
  if (a * a >= len)
    b = a;
  char* text = malloc(a * b + 1);
  char* result = malloc(a * b + b);
  if (!text || !result) {
    free(text);
    free(result);
    return NULL;
  }
  size_t n = 0;
  for (const char* p = plaintext; *p; p++) {
    if (*p >= 'A' && *p <= 'Z')
      text[n++] = *p + ('a' - 'A');
    else if (*p >= 'a' && *p <= 'z')
      text[n++] = *p;
  }
  while (n < a * b)
    text[n++] = ' ';
  size_t pos = 0;
  for (size_t col = 0; col < b; col++) {
    if (col > 0)
      result[pos++] = ' ';
    for (size_t row = 0; row < a; row++)
      result[pos++] = text[row * b + col];
  }
  result[pos] = '\0';
  free(text);
  return result;
}
