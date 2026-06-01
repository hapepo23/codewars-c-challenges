/*
6 kyu
WeIrD StRiNg CaSe
https://www.codewars.com/kata/52b757663a95b11b3d00062d
*/

#include <ctype.h>

char* to_weird_case(char* string) {
  char* p = string;
  int index = 0;
  while (*p) {
    if (*p == ' ')
      index = 0;
    else
      *p = (index++) % 2 ? tolower(*p) : toupper(*p);
    ++p;
  }
  return string;
}
