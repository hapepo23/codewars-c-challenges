/*
5 kyu
Parsing goto statements
https://www.codewars.com/kata/591f3a2e4e5471989000013d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULT_LENGTH 2000

typedef enum Type { TEXT, GOTO } Type;

typedef struct Pgm {
  Type type;
  int lineno;
  char* text;
} Pgm;

static size_t find_goto_line(Pgm* pgm, size_t pgm_len, int lineno) {
  for (size_t i = 0; i < pgm_len; i++)
    if (pgm[i].type == TEXT)
      if (pgm[i].lineno == lineno)
        return i;
  return 0;
}

char* parse(const char* source) {
  size_t pgm_len = 0;
  const char* p = source;
  while (*p) {
    if (*p == '\n')
      pgm_len++;
    p++;
  }
  Pgm program[pgm_len];
  size_t i = 0;
  const char* pstart = source;
  p = source;
  while (*p) {
    if (*p == '\n') {
      if (*pstart >= '0' && *pstart <= '9') {
        const char* q = pstart;
        while (*q != ' ')
          q++;
        program[i].type = TEXT;
        program[i].lineno = atoi(pstart);
        program[i].text = calloc(p - q, sizeof(char));
        strncpy(program[i].text, q + 1, p - q - 1);
      } else if (strncmp(pstart, "goto ", 5) == 0) {
        program[i].type = GOTO;
        program[i].lineno = atoi(pstart + 5);
        program[i].text = NULL;
      }
      pstart = p + 1;
      i++;
    }
    p++;
  }
  if (i != pgm_len) {
    puts("Pgm Length Error");
    exit(1);
  }
  char* result = calloc(MAX_RESULT_LENGTH, sizeof(char));
  i = 0;
  while (1) {
    if (program[i].type == GOTO) {
      i = find_goto_line(program, pgm_len, program[i].lineno);
      if (i == 0) {
        puts("Goto Destination Error");
        exit(2);
      }
    } else {
      strcat(result, program[i].text);
      strcat(result, " ");
      i++;
    }
    if (i == pgm_len)
      break;
  }
  for (i = 0; i < pgm_len; i++) {
    if (program[i].text != NULL) {
      free(program[i].text);
    }
  }
  if (result[strlen(result) - 1] == ' ')
    result[strlen(result) - 1] = '\0';
  return result;
}
