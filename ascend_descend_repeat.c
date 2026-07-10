/*
6 kyu
Ascend, Descend, Repeat?
https://www.codewars.com/kata/62ca07aaedc75c88fb95ee2f
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>

char* ascend_descend(size_t length,
                     char string[length + 1],
                     int minimum,
                     int maximum) {
  if (maximum < minimum)
    string[0] = '\0';
  else {
    char buf[length + 12];
    int num = minimum;
    int up = 1;
    size_t len = 0;
    while (len < length) {
      len += sprintf(buf + len, "%d", num);
      if (up && num < maximum)
        num++;
      else if (!up && num > minimum)
        num--;
      if (num == minimum || num == maximum)
        up = !up;
    }
    strncpy(string, buf, length);
    string[length] = '\0';
  }
  return string;
}
