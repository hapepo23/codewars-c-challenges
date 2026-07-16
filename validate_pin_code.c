/*
7 kyu
Validate a PIN code
https://www.codewars.com/kata/55f8a9c06c018a0d6e000132
*/

#include <ctype.h>
#include <stdbool.h>

bool validate_pin(const char* pin) {
  const char* p = pin;
  while (*p)
    if (!isdigit(*(p++)))
      return false;
  return (p - pin) == 4 || (p - pin) == 6;
}
