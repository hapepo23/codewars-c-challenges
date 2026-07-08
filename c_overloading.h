/*
6 kyu
C overloading
https://www.codewars.com/kata/625eb7850e2c2f000eca370c
*/

#include <stdio.h>
#include <string.h>

static int add_ii(int a, int b) {
  return a + b;
}

static char* add_ic(int a, char* b) {
  char buf[64];
  sprintf(buf, "%d%s", a, b);
  strcpy(b, buf);
  return b;
}

static char* add_ci(char* a, int b) {
  char buf[64];
  sprintf(buf, "%s%d", a, b);
  strcpy(a, buf);
  return a;
}

static char* add_cc(char* a, const char* b) {
  char buf[64];
  sprintf(buf, "%s%s", a, b);
  strcpy(a, buf);
  return a;
}

#define add(a, b)                                                             \
  _Generic((a),                                                               \
      int: _Generic((b), int: add_ii, char*: add_ic),                         \
      char*: _Generic((b), int: add_ci, const char*: add_cc, char*: add_cc))( \
      a, b)
