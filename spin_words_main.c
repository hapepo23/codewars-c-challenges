/*
6 kyu
Stop gninnipS My sdroW!
https://www.codewars.com/kata/5264d2b162488dc400000001
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spin_words(const char* sentence, char* result);

static void do_test(const char* sentence, const char* expected) {
  const size_t mem_size = strlen(sentence) + 1;
  char* submitted = memset(malloc(mem_size), '@', mem_size);
  spin_words(sentence, submitted);
  printf("Sentence:  \"%s\"\nSubmitted: \"%s\"\nExpected:  \"%s\"\n%s\n\n",
         sentence, submitted, expected,
         strcmp(submitted, expected) == 0 ? "OK" : "FAIL");
  free(submitted);
}

int main(void) {
  do_test("Welcome", "emocleW");
  do_test("spam", "spam");
  do_test("This is a test", "This is a test");
  do_test("This is another test", "This is rehtona test");
  return 0;
}
