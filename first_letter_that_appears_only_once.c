/*
7 kyu
All Star Code Challenge #16
https://www.codewars.com/kata/586566b773bd9cbe2b000013
*/

#include <limits.h>

char no_repeat(const char* string) {
  int count[26];
  int posfirst[26];
  for (int i = 0; i < 26; i++) {
    count[i] = 0;
    posfirst[i] = -1;
  }
  int pos = 0;
  while (*string) {
    int index = (int)(*string - 'a');
    count[index]++;
    if (posfirst[index] == -1)
      posfirst[index] = pos;
    string++;
    pos++;
  }
  int low = INT_MAX;
  char result = '?';
  for (int i = 0; i < 26; i++) {
    if (count[i] == 1) {
      if (posfirst[i] < low) {
        low = posfirst[i];
        result = (char)(i + 'a');
      }
    }
  }
  return result;
}
