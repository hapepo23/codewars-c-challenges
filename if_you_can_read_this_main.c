/*
6 kyu
If you can read this...
https://www.codewars.com/kata/586538146b56991861000293
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const NATO[100] = {
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "",       "",        "",        "",       "",
    "",        "",         "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",
    "Foxtrot", "Golf",     "Hotel",  "India",   "Juliett", "Kilo",   "Lima",
    "Mike",    "November", "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra",
    "Tango",   "Uniform",  "Victor", "Whiskey", "Xray",    "Yankee", "Zulu",
    "",        "",         "",       "",        "",        "",       "",
    "",        ""};

char* to_nato(const char* words);

static void do_test(const char* words, const char* expected) {
  char* actual = to_nato(words);
  printf("For words: \"%s\"\nExpected : \"%s\"\nActual   : \"%s\"\n-> %s\n\n",
         words, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("If you can read",
          "India Foxtrot Yankee Oscar Uniform Charlie Alfa November Romeo Echo "
          "Alfa Delta");
  do_test("Did not see that coming",
          "Delta India Delta November Oscar Tango Sierra Echo Echo Tango Hotel "
          "Alfa Tango Charlie Oscar Mike India November Golf");
  do_test("go for it!", "Golf Oscar Foxtrot Oscar Romeo India Tango !");
  return 0;
}
