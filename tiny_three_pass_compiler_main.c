/*
1 kyu
Tiny Three-Pass Compiler
https://www.codewars.com/kata/5265b0885fda8eac5900093b
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compile(const char* program);

static int stack[1024];
static int sp;

static void push(int n) {
  assert(sp < 1024);
  stack[sp++] = n;
}

static int pop(void) {
  assert(sp > 0);
  return stack[--sp];
}

static int simulate(const char* ins, const int* args) {
  int r0 = 0, r1 = 0, t;
  sp = 0;
  while (ins && *ins) {
    if (!strncmp(ins, "IM", 2))
      r0 = atoi(ins + 3);
    else if (!strncmp(ins, "AR", 2))
      r0 = args[atoi(ins + 3)];
    else if (!strncmp(ins, "SW", 2))
      t = r0, r0 = r1, r1 = t;
    else if (!strncmp(ins, "PU", 2))
      push(r0);
    else if (!strncmp(ins, "PO", 2))
      r0 = pop();
    else if (!strncmp(ins, "AD", 2))
      r0 += r1;
    else if (!strncmp(ins, "SU", 2))
      r0 -= r1;
    else if (!strncmp(ins, "MU", 2))
      r0 *= r1;
    else if (!strncmp(ins, "DI", 2))
      r0 /= r1;
    ins = strchr(ins, '\n');
    if (ins)
      ins++;
  }
  assert(sp == 0);
  return r0;
}

static int test_count;

static void test(const char* program, const int* args, int expected) {
  char* assembly = compile(program);
  int actual = simulate(assembly, args);
  printf("%s | expected: %d | actual: %d -> %s\n", program, expected, actual,
         actual == expected ? "OK" : "FAIL");
  assert(actual == expected);
  free(assembly);
  test_count++;
}

int main(void) {
  int args1[] = {3};
  int args2[] = {7, 5};
  int args3[] = {2, 3, 4};
  int args4[] = {10, 2, 3};
  int args5[] = {100, 5};
  int args6[] = {4, 6};
  int args7[] = {8, 2};
  // Immediate values
  test("[] 42", NULL, 42);
  // Single argument
  test("[ x ] x", args1, 3);
  // Basic arithmetic
  test("[ x y ] x + y", args2, 12);
  test("[ x y ] x - y", args2, 2);
  test("[ x y ] x * y", args2, 35);
  test("[ x y ] x / y", args2, 1);
  // Operator precedence
  test("[ a b c ] a + b * c", args3, 14);
  test("[ a b c ] a * b + c", args3, 10);
  // Parentheses
  test("[ a b ] (a + b) * 2", args2, 24);
  test("[ a b c ] a * (b + c)", args3, 14);
  // Left associativity
  test("[ a b c ] a - b - c", args4, 5);
  test("[ a b c ] a / b / c", args4, 1);
  // Nested expressions
  test("[ a b c ] (a + b) * (a - c)", args3, -10);
  // Constant folding
  test("[ x ] x + 2 * 5", args1, 13);
  test("[ x ] (x + 3) * (2 + 4)", args1, 36);
  test("[] 2 + 3 * 4", NULL, 14);
  // Multiple-character variable names
  test("[ first second ] first + second", args2, 12);
  test("[ first second ] first * second", args6, 24);
  // Argument indexing
  test("[ a b ] b - a", args7, -6);
  // Division with larger values
  test("[ a b ] a / b", args5, 20);
  printf("All %d tests passed.\n", test_count);
  return 0;
}
