/*
7 kyu
Smart Log Formatter
https://www.codewars.com/kata/6ab3da4db0d8c965cd93923e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char** split(const char* s, const char splitchar, size_t* count) {
  size_t i, n = 1;
  char** fields;
  const char* p = s;
  while (*p) {
    if (*p++ == splitchar)
      n++;
  }
  fields = malloc(n * sizeof(*fields));
  if (!fields)
    return NULL;
  const char* start = s;
  i = 0;
  for (p = s;; p++) {
    if (*p == splitchar || *p == '\0') {
      size_t len = p - start;
      fields[i] = malloc(len + 1);
      memcpy(fields[i], start, len);
      fields[i][len] = '\0';
      i++;
      if (*p == '\0')
        break;
      start = p + 1;
    }
  }
  *count = n;
  return fields;
}

static void concat(char* dest, int* pos, char* src, int count, char* ending) {
  *pos += sprintf(dest + (*pos), "%s", src);
  if (count > 1)
    *pos += sprintf(dest + (*pos), " (x%d)", count);
  *pos += sprintf(dest + (*pos), "%s", ending);
}

char* smart_log_formatter(char* logs) {
  size_t len = strlen(logs);
  char* result;
  if (len > 0) {
    size_t linecount = 0;
    char** lines = split(logs, '\n', &linecount);
    result = calloc(len + 1 + linecount * 15, sizeof(char));
    int last = -1;
    int count = 0;
    int pos = 0;
    for (size_t i = 0; i < linecount; i++) {
      if (last == -1 || (last >= 0 && strcmp(lines[i], lines[last]) != 0)) {
        if (last != -1)
          concat(result, &pos, lines[last], count, "\n");
        last = i;
        count = 1;
      } else {
        count++;
      }
    }
    concat(result, &pos, lines[last], count, "");
    for (size_t i = 0; i < linecount; i++)
      free(lines[i]);
    free(lines);
  } else {
    result = calloc(1, sizeof(char));
  }
  return result;
}
