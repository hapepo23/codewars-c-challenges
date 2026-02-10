/*
7 kyu
Get the Middle Character
https://www.codewars.com/kata/56747fd5cb988479af000028
*/

#include <string.h>

char* get_middle(char outp[3], const char* inp) {
  unsigned l = strlen(inp);
  unsigned h = l / 2;
  if (l % 2) {
    outp[0] = inp[h];
    outp[1] = '\0';
  } else {
    outp[0] = inp[h - 1];
    outp[1] = inp[h];
    outp[2] = '\0';
  }
  return outp;
}
