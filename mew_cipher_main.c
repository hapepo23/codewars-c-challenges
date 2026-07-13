/*
7 kyu
Mew Cipher
https://www.codewars.com/kata/671bd5419ea261fbb8d0a0ca
*/

#include <stdio.h>
#include <string.h>

void decipher(size_t length, const char* const code[length], char* mew);

static char* code_stringer(size_t length,
                           const char* code[length],
                           char* code_str) {
  if (!length)
    strcpy(code_str, "(null)");
  else {
    size_t index = 0, pos = sprintf(code_str, "{");
    while (index < length) {
      pos += sprintf(code_str + pos, "\n  \"%s\", ", code[index++]);
    }
    sprintf(code_str + pos - 2, "\n}");
  }
  return code_str;
}

static void do_test(size_t length,
                    const char* code[length],
                    const char* expected) {
  char submitted[length + 1];
  decipher(length, code, submitted);
  size_t width = strlen(code[0]);
  size_t code_str_len = length * (width + 8) + 5 + 1;
  char code_str[code_str_len];
  printf("code[%zu] = %s\n", length, code_stringer(length, code, code_str));
  printf("Submitted: \"%s\"\nExpected:  \"%s\"\n-> %s\n\n", submitted, expected,
         strcmp(submitted, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  {
    const char* code[3] = {"u lk zxuq hfk as fouh", "y l  zpuv  xe at sicd",
                           "welvayfuqbfpeaauaqcrc"};
    const char* expected = "walk your dog at nine";
    do_test(3, code, expected);
  }
  {
    const char* code[1] = {"hello world"};
    const char* expected = "hello world";
    do_test(1, code, expected);
  }
  {
    const char* code[5] = {"", "", "", "", ""};
    const char* expected = "";
    do_test(5, code, expected);
  }
  {
    const char* code[5] = {"a  ", " b ", "  c", "   ", "   "};
    const char* expected = "   ";
    do_test(5, code, expected);
  }
  {
    const char* code[2] = {"foreman pig", "foreman pig"};
    const char* expected = "foreman pig";
    do_test(2, code, expected);
  }
  return 0;
}
