/*
2 kyu
Simpler Interactive Interpreter
https://www.codewars.com/kata/53005a7b26d12be55c000243
*/

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 256
#define MAX_IDENTIFIER_LENGTH 64
#define DEBUG false

typedef int Type;

/* Status codes */
enum StatusCodes {
  OK_CODE = 0,    /* Success */
  EMPTY_CODE = 1, /* Input string consists entirely of whitespaces */
  ERR_CODE = 2    /* Errors */
};

typedef struct {
  char name[MAX_IDENTIFIER_LENGTH];
  double value;
} Variable;

static Variable vars[MAX_VARIABLES];
static size_t varCount = 0;

static const char* str;
static size_t pos;
static size_t strsize;
static int errcode;

static Variable* findVariable(const char* name);
static double getVariable(const char* name);
static void setVariable(const char* name, double value);
static bool isIdentifierStart(char c);
static bool isIdentifierChar(char c);
static bool parseIdentifier(char* out, size_t outSize);
static void skipSpaces(void);
static double parseFactor(void);
static double parseTerm(void);
static double parseExpression(void);
static double parseAssignment(void);
static double calculate(const char* expression);

/* initInterpreter: initialize the interpreter if necessary and return
   a status code (any value other than OK_CODE is treated as an error) */
int initInterpreter(void) {
  varCount = 0;
  return OK_CODE;
}

/* closeInterpreter: close the interpreter and free memory if necessary */
void closeInterpreter(void) {
  varCount = 0;
  return;
}

/* evaluate: evaluate the string expression, and return a status code
   (any value other than OK_CODE and EMPTY_CODE is treated as an error).
   The result of evaluating the expression is placed in a variable
   by the pointer 'result' if the function returns OK_CODE. */
int evaluate(char* input, Type* result) {
  errcode = OK_CODE;
  *result = calculate(input);
  if (DEBUG)
    printf("%s -> err= %d, result = %d\n", input, errcode, *result);
  return errcode;
}

static Variable* findVariable(const char* name) {
  for (size_t i = 0; i < varCount; i++) {
    if (strcmp(vars[i].name, name) == 0)
      return &vars[i];
  }
  return NULL;
}

static double getVariable(const char* name) {
  Variable* v = findVariable(name);
  if (!v) {
    errcode = ERR_CODE;
    return 0.0;
  }
  return v->value;
}

static void setVariable(const char* name, double value) {
  Variable* v = findVariable(name);
  if (v) {
    v->value = value;
    return;
  }
  if (varCount >= MAX_VARIABLES) {
    errcode = ERR_CODE;
  }
  strcpy(vars[varCount].name, name);
  vars[varCount].value = value;
  varCount++;
}

static bool isIdentifierStart(char c) {
  return isalpha((unsigned char)c) || c == '_';
}

static bool isIdentifierChar(char c) {
  return isalnum((unsigned char)c) || c == '_';
}

static bool parseIdentifier(char* out, size_t outSize) {
  skipSpaces();
  if (pos >= strsize || !isIdentifierStart(str[pos]))
    return false;
  size_t start = pos++;
  while (pos < strsize && isIdentifierChar(str[pos]))
    pos++;
  size_t len = pos - start;
  if (len >= outSize)
    len = outSize - 1;
  memcpy(out, str + start, len);
  out[len] = '\0';
  return true;
}

static void skipSpaces(void) {
  while (pos < strsize && isspace((unsigned char)str[pos])) {
    pos++;
  }
}

static double parseFactor(void) {
  skipSpaces();
  /* unary minus */
  if (pos < strsize && str[pos] == '-') {
    pos++;
    return -parseFactor();
  }
  /* parenthesized expression */
  if (pos < strsize && str[pos] == '(') {
    pos++;
    double value = parseAssignment();
    skipSpaces();
    if (pos >= strsize || str[pos] != ')')
      errcode = ERR_CODE;
    pos++;
    return value;
  }
  /* variable */
  {
    char name[MAX_IDENTIFIER_LENGTH];
    size_t savedPos = pos;
    if (parseIdentifier(name, sizeof(name)))
      return getVariable(name);
    pos = savedPos;
  }
  /* number */
  {
    char* pend;
    double value = strtod(str + pos, &pend);
    if (pend == str + pos)
      errcode = ERR_CODE;
    pos = (size_t)(pend - str);
    return value;
  }
}

static double parseTerm(void) {
  double value = parseFactor();
  while (true) {
    skipSpaces();
    if (pos >= strsize)
      break;
    char op = str[pos];
    if (op != '*' && op != '/' && op != '%')
      break;
    pos++;
    double rhs = parseFactor();
    switch (op) {
      case '*':
        value *= rhs;
        break;
      case '/':
        if (rhs == 0.0)
          errcode = ERR_CODE;
        else
          value /= rhs;
        break;
      case '%':
        if (rhs == 0.0)
          errcode = ERR_CODE;
        else
          value = fmod(value, rhs);
        break;
    }
  }
  return value;
}

static double parseExpression(void) {
  double value = parseTerm();
  while (true) {
    skipSpaces();
    if (pos >= strsize)
      break;
    char op = str[pos];
    if (op != '+' && op != '-')
      break;
    pos++;
    double rhs = parseTerm();
    if (op == '+')
      value += rhs;
    else
      value -= rhs;
  }
  return value;
}

static double parseAssignment(void) {
  skipSpaces();
  if (pos >= strsize) {
    errcode = EMPTY_CODE;
    return 0.0;
  }
  size_t savedPos = pos;
  char name[MAX_IDENTIFIER_LENGTH];
  if (parseIdentifier(name, sizeof(name))) {
    skipSpaces();
    if (pos < strsize && str[pos] == '=') {
      pos++;
      skipSpaces();
      if (pos >= strsize) {
        errcode = ERR_CODE;
        return 0.0;
      }
      double value = parseAssignment();
      if (errcode == 0)
        setVariable(name, value);
      return value;
    }
  }
  pos = savedPos;
  return parseExpression();
}

static double calculate(const char* expression) {
  str = expression;
  strsize = strlen(expression);
  pos = 0;
  double result = parseAssignment();
  skipSpaces();
  if (pos != strsize)
    errcode = ERR_CODE;
  return result;
}