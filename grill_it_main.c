/*
6 kyu
Grill it!
https://www.codewars.com/kata/595b3f0ad26b2d817400002a
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grille_decypher(char* ciphertext, unsigned code);

static void print_binary(unsigned int n) {
  unsigned int bit = 1u << (sizeof(n) * 8 - 1);
  int started = 0;
  while (bit) {
    if (n & bit)
      started = 1;
    if (started)
      putchar((n & bit) ? '1' : '0');
    bit >>= 1;
  }
  if (!started)
    putchar('0');
  putchar('\n');
}

static void do_test(const char* ciphertext,
                    unsigned code,
                    const char* plaintext) {
  extern char* strdup(const char*);
  char* const actual = strdup(ciphertext);
  grille_decypher(actual, code);
  printf("Code       = %u = ", code);
  print_binary(code);
  printf(
      "Ciphertext = \"%s\"\nPlaintext  = \"%s\"\nActual     = "
      "\"%s\"\n-> %s\n\n",
      ciphertext, plaintext, actual,
      strcmp(plaintext, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("abcdef", 5, "df");
  do_test("", 5, "");
  do_test("abcd", 1, "d");
  do_test("abcd", 0, "");
  do_test("abcd", 0b1111, "abcd");
  do_test("0abd", 2, "b");
  do_test("tcddoadepwweasresd", 77098, "codewars");
  do_test("0123456789012345678901234567890123456789", UINT_MAX,
          "89012345678901234567890123456789");
  do_test("0123456789012345678901234567890123456789", 0, "");
  do_test("0123456789012345678901234567890123456789",
          0b10101010101010101010101010101010u, "8024680246802468");
  do_test("0123456789012345678901234567890123456789",
          0b01010101010101010101010101010101u, "9135791357913579");
  return 0;
}
