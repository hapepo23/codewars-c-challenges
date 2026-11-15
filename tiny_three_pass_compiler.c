/*
1 kyu
Tiny Three-Pass Compiler
https://www.codewars.com/kata/5265b0885fda8eac5900093b
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define div divide

typedef struct AST {
  enum op { imm, arg, plus, min, mul, div } op;
  struct AST *a, *b;
  int n;
} AST;

// --------------------------------------------------
// AST constructors
// --------------------------------------------------

AST* Arg(int n) {
  AST* p = malloc(sizeof(AST));
  *p = (AST){arg, NULL, NULL, n};
  return p;
}

AST* Imm(int n) {
  AST* p = malloc(sizeof(AST));
  *p = (AST){imm, NULL, NULL, n};
  return p;
}

AST* Bin(enum op op, AST* a, AST* b) {
  AST* p = malloc(sizeof(AST));
  *p = (AST){op, a, b, 0};
  return p;
}

// --------------------------------------------------
// Tokenizer
// --------------------------------------------------

static char* copy_token(const char* s, size_t len) {
  char* p = malloc(len + 1);
  memcpy(p, s, len);
  p[len] = '\0';
  return p;
}

char** tokenize(const char* program) {
  size_t capacity = 16;
  size_t count = 0;
  char** tokens = malloc(capacity * sizeof(char*));
  while (*program) {
    if (isspace((unsigned char)*program)) {
      program++;
      continue;
    }
    const char* start = program;
    if (isalpha((unsigned char)*program)) {
      while (isalpha((unsigned char)*program))
        program++;
    } else if (isdigit((unsigned char)*program)) {
      while (isdigit((unsigned char)*program))
        program++;
    } else {
      program++;
    }
    if (count + 2 > capacity) {
      capacity *= 2;
      tokens = realloc(tokens, capacity * sizeof(char*));
    }
    tokens[count++] = copy_token(start, program - start);
  }
  tokens[count] = NULL;
  return tokens;
}

// --------------------------------------------------
// Parser (recursive descent)
// --------------------------------------------------

static char** tokens;
static int pos;

static int is_token(const char* s) {
  return tokens[pos] && strcmp(tokens[pos], s) == 0;
}

static int argument_index(const char* name) {
  for (int i = 0; tokens[i] && strcmp(tokens[i], "]") != 0; i++) {
    if (strcmp(tokens[i], name) == 0)
      return i - 1;
  }
  return -1;
}

// factor ::= number | variable | '(' expression ')'

static AST* parse_expression(void);

static AST* parse_factor(void) {
  if (is_token("(")) {
    pos++;
    AST* p = parse_expression();
    pos++;  // ')'
    return p;
  }
  if (isdigit((unsigned char)tokens[pos][0])) {
    int n = atoi(tokens[pos++]);
    return Imm(n);
  }
  int n = argument_index(tokens[pos]);
  pos++;
  return Arg(n);
}

// term ::= factor | term '*' factor | term '/' factor

static AST* parse_term(void) {
  AST* p = parse_factor();
  while (is_token("*") || is_token("/")) {
    enum op operation = is_token("*") ? mul : div;
    pos++;
    p = Bin(operation, p, parse_factor());
  }
  return p;
}

// expression ::= term | expression '+' term | expression '-' term

static AST* parse_expression(void) {
  AST* p = parse_term();
  while (is_token("+") || is_token("-")) {
    enum op operation = is_token("+") ? plus : min;
    pos++;
    p = Bin(operation, p, parse_term());
  }
  return p;
}

// --------------------------------------------------
// PASS 1
// --------------------------------------------------

AST* pass1(const char* program) {
  tokens = tokenize(program);
  pos = 0;
  pos++;  // '['
  // Skip argument list.
  while (!is_token("]"))
    pos++;
  pos++;  // ']'
  AST* result = parse_expression();
  // Free tokenizer memory.
  for (int i = 0; tokens[i]; i++)
    free(tokens[i]);
  free(tokens);
  tokens = NULL;
  return result;
}

// --------------------------------------------------
// PASS 2
// --------------------------------------------------

AST* pass2(AST* ast) {
  if (!ast || ast->op == imm || ast->op == arg)
    return ast;
  ast->a = pass2(ast->a);
  ast->b = pass2(ast->b);
  // Nothing to fold if either operand is not constant.
  if (ast->a->op != imm || ast->b->op != imm)
    return ast;
  int a = ast->a->n;
  int b = ast->b->n;
  int result;
  switch (ast->op) {
    case plus:
      result = a + b;
      break;
    case min:
      result = a - b;
      break;
    case mul:
      result = a * b;
      break;
    case div:
      if (b == 0)
        return ast;
      result = a / b;
      break;
    default:
      return ast;
  }
  return Imm(result);
}

// --------------------------------------------------
// PASS 3
// --------------------------------------------------

// Dynamic assembly string.

static char* code;
static size_t code_len;
static size_t code_capacity;

static void emit(const char* instruction, int n) {
  char buffer[64];
  if (n >= 0)
    snprintf(buffer, sizeof(buffer), "%s %d", instruction, n);
  else
    snprintf(buffer, sizeof(buffer), "%s", instruction);
  size_t len = strlen(buffer);
  if (code_len + len + 2 > code_capacity) {
    code_capacity = (code_capacity + len + 64) * 2;
    code = realloc(code, code_capacity);
  }
  if (code_len)
    code[code_len++] = '\n';
  memcpy(code + code_len, buffer, len);
  code_len += len;
  code[code_len] = '\0';
}

static void generate(AST* ast) {
  if (ast->op == imm) {
    emit("IM", ast->n);
    return;
  }
  if (ast->op == arg) {
    emit("AR", ast->n);
    return;
  }
  // Evaluate left operand and save it.
  generate(ast->a);
  emit("PU", -1);
  // Evaluate right operand.
  generate(ast->b);
  // Restore left operand into R0 and move
  // right operand into R1.
  emit("SW", -1);
  emit("PO", -1);
  // Perform the operation.
  switch (ast->op) {
    case plus:
      emit("AD", -1);
      break;
    case min:
      emit("SU", -1);
      break;
    case mul:
      emit("MU", -1);
      break;
    case div:
      emit("DI", -1);
      break;
    default:
      break;
  }
}

char* pass3(AST* ast) {
  code_capacity = 128;
  code_len = 0;
  code = malloc(code_capacity);
  code[0] = '\0';
  generate(ast);
  return code;
}

// --------------------------------------------------
// COMPILER
// --------------------------------------------------

char* compile(const char* program) {
  return pass3(pass2(pass1(program)));
}
