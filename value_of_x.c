/*
5 kyu
Value of x
https://www.codewars.com/kata/614ac445f13ead000f91b4d0
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum TokenType { PLUS, MINUS, EQUAL, X, NUM } TokenType;

typedef struct Token {
  TokenType type;
  int value;
} Token;

int solve(const char* equation) {
  int len = strlen(equation);
  char eq[len + 1];
  strcpy(eq, equation);
  Token token[len];
  int token_len = 0;
  for (char* p = strtok(eq, " "); p != NULL; p = strtok(NULL, " ")) {
    if (strlen(p) == 1) {
      switch (*p) {
        case '+':
          token[token_len].type = PLUS;
          break;
        case '-':
          token[token_len].type = MINUS;
          break;
        case '=':
          token[token_len].type = EQUAL;
          break;
        case 'x':
          token[token_len].type = X;
          break;
        default:
          token[token_len].type = NUM;
          break;
      }
    } else {
      token[token_len].type = NUM;
    }
    if (token[token_len].type == NUM)
      token[token_len].value = atoi(p);
    token_len++;
  }
  bool eqfound = false, xleft;
  for (int i = 0; i < token_len; i++) {
    if (token[i].type == EQUAL) {
      eqfound = true;
    } else if (token[i].type == X) {
      xleft = !eqfound;
      if (i > 0 && token[i - 1].type == MINUS)
        xleft = !xleft;
      break;
    }
  }
  eqfound = false;
  int result = 0, val = 0;
  for (int i = 0; i < token_len; i++) {
    if (token[i].type == EQUAL) {
      eqfound = true;
    } else if (token[i].type == NUM) {
      val = token[i].value;
      if (i > 0 && token[i - 1].type == MINUS)
        val = -val;
      if ((xleft && !eqfound) || (!xleft && eqfound))
        val = -val;
      result += val;
    }
  }
  return result;
}
