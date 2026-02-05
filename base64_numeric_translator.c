/*
5 kyu
Base64 Numeric Translator
https://www.codewars.com/kata/5632e12703e2037fa7000061
*/

#include <stdint.h>
#include <string.h>

typedef uint64_t u64;

static const char* convtable =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

u64 base64_to_base10(const char* base64) {
  u64 result = 0;
  for (unsigned int i = 0; i < strlen(base64); i++) {
    char* n = strchr(convtable, base64[i]);
    result = (n - convtable) + result * 64;
  }
  return result;
}
