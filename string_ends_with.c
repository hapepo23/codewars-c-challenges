/*
7 kyu
String ends with?
https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d
*/

#include <stdbool.h>
#include <string.h>

bool solution(const char* string, const char* ending) {
  size_t lstring = strlen(string);
  size_t lending = strlen(ending);
  return lstring >= lending && strcmp(ending, string + lstring - lending) == 0;
}
