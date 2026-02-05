/*
5 kyu
Return substring instance count - 2
https://www.codewars.com/kata/52190daefe9c702a460003dd
*/

#include <stdbool.h>
#include <string.h>

int search_substr(const char* full_text,
                  const char* search_text,
                  bool allow_overlap) {
  int count = 0;
  if (full_text && search_text) {
    size_t full_len = strlen(full_text);
    size_t search_len = strlen(search_text);
    if (search_len > 0 && search_len <= full_len) {
      const char* p = full_text;
      while ((p = strstr(p, search_text)) != NULL) {
        count++;
        p += allow_overlap ? 1 : search_len;
      }
    }
  }
  return count;
}
