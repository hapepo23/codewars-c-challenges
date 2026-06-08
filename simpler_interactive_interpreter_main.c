/*
2 kyu
Simpler Interactive Interpreter
https://www.codewars.com/kata/53005a7b26d12be55c000243
*/

#include <stdio.h>

typedef int Type;

/* Status codes */
enum StatusCodes {
  OK_CODE = 0,    /* Success */
  EMPTY_CODE = 1, /* Input string consists entirely of whitespaces */
  /* 2, 3, ... */ /* Errors */
};

/* initInterpreter: initialize the interpreter if necessary and return
   a status code (any value other than OK_CODE is treated as an error) */
int initInterpreter(void);

/* closeInterpreter: close the interpreter and free memory if necessary */
void closeInterpreter(void);

/* evaluate: evaluate the string expression and return a status code
   (any value other than OK_CODE and EMPTY_CODE is treated as an error).
   The result of evaluating the expression is placed in a variable
   by the pointer 'result' if the function returns OK_CODE. */
int evaluate(char* input, Type* result);

/* init: initialize a test */
static void init(void) {
  if (initInterpreter() != OK_CODE)
    printf("init -> status FAIL\n");
  return;
}

/* checkEqual: check the result of processing the expression */
static void checkEqual(char* input, Type expected) {
  Type actual;
  int status = evaluate(input, &actual);
  if (status != OK_CODE)
    printf("%s -> %d -> status FAIL\n", input, status);
  else
    printf("%s -> %d -> exp: %d, act: %d -> %s\n", input, status, expected,
           actual, expected == actual ? "OK" : "FAIL");
  return;
}

/* checkError: check an error while processing the expression */
static void checkError(char* input) {
  Type actual;
  int status = evaluate(input, &actual);
  if (status != OK_CODE)
    printf("%s -> %d -> status OK\n", input, status);
  else
    printf("%s -> %d -> status FAIL\n", input, status);
  return;
}

int main(void) {
  init();
  checkEqual("1 + 1", 2);
  checkEqual("2 - 1", 1);
  checkEqual("2 * 3", 6);
  checkEqual("8 / 4", 2);
  checkError("8 / 0");
  checkEqual("7 % 4", 3);
  checkEqual("x = 1", 1);
  checkEqual("x", 1);
  checkError("y");
  checkError("y= ");
  checkError(" ");
  checkError("_i=*5");
  checkEqual("m=3333", 3333);
  checkError("num = (_i - m) / 5");
  closeInterpreter();
  return 0;
}
