/*
5 kyu
Grab CSV Columns
https://www.codewars.com/kata/5276c0f3f4bfbd5aae0001ad
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static char* process_line(char* line,
                          size_t indices_len,
                          size_t indices[indices_len]) {
  char* output = calloc(strlen(line) + 1, sizeof(char));
  char* p = strtok(line, ",");
  int notfirst = 0;
  size_t i = 0;
  while (p != NULL) {
    for (size_t j = 0; j < indices_len; j++) {
      if (i == indices[j]) {
        if (notfirst)
          strcat(output, ",");
        strcat(output, p);
        notfirst = 1;
        break;
      }
    }
    p = strtok(NULL, ",");
    i++;
  }
  return output;
}

void csv_columns(const char* csv_str,
                 size_t indices_len,
                 size_t indices[indices_len],
                 char* selected_cols) {
  *selected_cols = '\0';
  if (strlen(csv_str) == 0 || indices_len == 0)
    return;
  const char* next_nl_or_end;
  const char* start = csv_str;
  int notfirst = 0;
  size_t len = strlen(csv_str);
  next_nl_or_end = strchr(start, '\n');
  if (next_nl_or_end == NULL)
    next_nl_or_end = csv_str + len;
  while (*start) {
    char* line = calloc(next_nl_or_end - start + 1, sizeof(char));
    strncpy(line, start, next_nl_or_end - start);
    char* output = process_line(line, indices_len, indices);
    if (strlen(output) > 0) {
      if (notfirst)
        strcat(selected_cols, "\n");
      strcat(selected_cols, output);
      notfirst = 1;
    }
    free(line);
    free(output);
    if (*next_nl_or_end != '\0') {
      start = next_nl_or_end + 1;
      next_nl_or_end = strchr(start, '\n');
      if (next_nl_or_end == NULL)
        next_nl_or_end = csv_str + len;
    } else
      start = next_nl_or_end;
  }
}
