/*
8 kyu
Do you speak "English"?
https://www.codewars.com/kata/58dbdccee5ee8fa2f9000058
*/

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool sp_eng(const char* sentence) {
  size_t len = strlen(sentence);
  if (len < 7)
    return false;
  char buf[len + 1];
  for (size_t i = 0; i < len; i++) {
    buf[i] = tolower(sentence[i]);
  }
  buf[len] = '\0';
  return strstr(buf, "english") != NULL;
}
