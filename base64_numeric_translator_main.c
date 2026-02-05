/*
5 kyu
Base64 Numeric Translator
https://www.codewars.com/kata/5632e12703e2037fa7000061
*/

#include <inttypes.h>
#include <stdio.h>

typedef uint64_t u64;

u64 base64_to_base10(const char* base64);

static void do_test(const char* base64, u64 base10) {
  u64 actual = base64_to_base10(base64);
  printf("for base64: \"%s\"\nexpected: %" PRIu64 "\nactual  : %" PRIu64
         "\n%s\n\n",
         base64, base10, actual, base10 == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("A", 0);
  do_test("/", 63);
  do_test("BA", 64);
  do_test("//", 4095);
  do_test("WIN", 90637);
  do_test("b64", 114360);
  do_test("B64", 7864);
  do_test("/+/", 262079);
  do_test("HelloWorld", 134710352538679645);
  do_test("P//////////", UINT64_MAX);
  return 0;
}
