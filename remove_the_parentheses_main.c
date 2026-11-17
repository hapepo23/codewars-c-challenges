/*
6 kyu
Remove the parentheses
https://www.codewars.com/kata/5f7c38eb54307c002a2b8cc8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_parentheses(const char* str_in, char* str_out);

static void tester(const char* string, const char* expected) {
  const size_t mem_size = strlen(string) + 1;
  char* submitted = memset(malloc(mem_size), '@', mem_size);
  remove_parentheses(string, submitted);
  printf("String   : \"%s\"\nSubmitted: \"%s\"\nExpected : \"%s\"\n-> %s\n\n",
         string, submitted, expected,
         strcmp(submitted, expected) == 0 ? "OK" : "FAIL");
  free(submitted);
}

int main(void) {
  const struct String_Test_Pair {
    const char *string, *expected;
  } tests[] = {{"example(unwanted thing)example", "exampleexample"},
               {"example(unwanted thing)example", "exampleexample"},
               {"example (unwanted thing) example", "example  example"},
               {"a (bc d)e", "a e"},
               {"a(b(c))", "a"},
               {"hello example (words(more words) here) something",
                "hello example  something"},
               {"(first group) (second group) (third group)", "  "},
               {"no parentheses", "no parentheses"},
               {"empty () parentheses", "empty  parentheses"}};
  for (size_t i = 0; i < sizeof tests / sizeof *tests; i++)
    tester(tests[i].string, tests[i].expected);
  return 0;
}
