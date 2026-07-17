/*
7 kyu
Find The Corrupted Hex Byte
https://www.codewars.com/kata/6a54d3e91e9fb16ca31cc912
*/

#include <stdbool.h>
#include <sys/types.h>

bool is_valid_hex_byte(const char* s) {
  for (int i = 0; i < 2; i++)
    if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F')))
      return false;
  return s[2] == '\0';
}

ssize_t find_corrupted_byte(size_t length, const char* dump[length]) {
  for (size_t i = 0; i < length; i++)
    if (!is_valid_hex_byte(dump[i]))
      return i;
  return -1;
}
