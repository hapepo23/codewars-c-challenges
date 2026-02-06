/*
8 kyu
Reversed Strings
https://www.codewars.com/kata/5168bb5dfe9a00b126000018
*/

#include <string.h>

char* strrev(char* string) {
  for (int i = strlen(string) - 1, j = 0; i >= j; i--, j++) {
    char temp = string[j];
    string[j] = string[i];
    string[i] = temp;
  }
  return string;
}
