/*
6 kyu
Letter triangles
https://www.codewars.com/kata/635e70f47dadea004acb5663
*/

#include <string.h>

char triangle(const char* row) {
  int len = strlen(row);
  char buf[len + 1];
  strcpy(buf, row);
  while (len > 1) {
    for (int i = 0; i < len - 1; i++) {
      int temp = (int)buf[i] + (int)buf[i + 1] - 96;
      buf[i] = (char)(temp > 122 ? (char)(temp - 26) : temp);
    }
    buf[len--] = '\0';
  }
  return buf[0];
}
