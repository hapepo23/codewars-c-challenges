/*
7 kyu
Binary Addition
https://www.codewars.com/kata/551f37452ff852b7bd000139
*/

#include <string.h>

typedef unsigned long long ull;

static void ull_to_binary(ull value, char* buffer) {
  if (value == 0) {
    strcpy(buffer, "0");
    return;
  }
  char temp[65];
  int i = 0;
  while (value > 0) {
    temp[i++] = (value & 1) + '0';
    value >>= 1;
  }
  for (int j = 0; j < i; j++)
    buffer[j] = temp[i - j - 1];
  buffer[i] = '\0';
}

char* binary_add(unsigned a, unsigned b, char* binary) {
  ull_to_binary((ull)a + (ull)b, binary);
  return binary;
}
