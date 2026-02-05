/*
5 kyu
Return substring instance count - 2
https://www.codewars.com/kata/52190daefe9c702a460003dd
*/

#include <stdbool.h>
#include <stdio.h>

int search_substr(const char* full_text,
                  const char* search_text,
                  bool allow_overlap);

static void do_test(const char* full_text,
                    const char* search_text,
                    bool allow_overlap,
                    int expected) {
  int actual = search_substr(full_text, search_text, allow_overlap);
  printf(
      "full text    : \"%s\"\n"
      "search text  : \"%s\"\n"
      "allow overlap: %s\n"
      "expected     : %d\n"
      "actual       : %d\n"
      "%s\n\n",
      full_text, search_text, allow_overlap ? "true" : "false", expected,
      actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("abcabcabc", "abc", false, 3);
  do_test("abcabcabc", "abc", true, 3);
  do_test("ababa_ababa_ababa", "aba", false, 3);
  do_test("ababa_ababa_ababa", "aba", true, 6);
  return 0;
}
