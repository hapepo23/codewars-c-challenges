/*
6 kyu
Valid Braces
https://www.codewars.com/kata/5277c8a221e209d3f6000b56
*/

#include <stdbool.h>
#include <string.h>

bool valid_braces(const char* braces) {
  char stack[strlen(braces) + 1];
  int stackpos = 0;
  while (*braces) {
    switch (*braces) {
      case '{':
      case '[':
      case '(':
        stack[stackpos++] = (*braces == '(' ? ')' : *braces + 2);
        break;
      case ')':
      case ']':
      case '}':
        if (stackpos == 0 || stack[stackpos - 1] != *braces)
          return false;
        stackpos--;
        break;
    }
    braces++;
  }
  return stackpos == 0;
}
