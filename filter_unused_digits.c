/*
7 kyu
Filter unused digits
https://www.codewars.com/kata/55de6173a8fbe814ee000061
*/

#include <stdarg.h>
#include <stdbool.h>

char* unused_digits(char unused[11], ...) {
  bool exists[10] = {false};
  va_list args;
  va_start(args, unused);
  int value = va_arg(args, int);
  while (value != -1) {
    if (value == 0)
      exists[0] = true;
    else {
      while (value > 0) {
        int digit = value % 10;
        exists[digit] = true;
        value /= 10;
      }
    }
    value = va_arg(args, int);
  }
  va_end(args);
  int pos = 0;
  for (int i = 0; i < 10; i++) {
    if (!exists[i])
      unused[pos++] = (char)(i + '0');
  }
  unused[pos] = '\0';
  return unused;
}
