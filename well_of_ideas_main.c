/*
8 kyu
Well of Ideas - Easy Version
https://www.codewars.com/kata/57f222ce69e09c3630000212
*/

#include <stdio.h>
#include <string.h>

const char* well(size_t n, const char* const ideas[n]);

static void print_array(size_t len, const char* const array[len]) {
  printf("{ ");
  for (size_t i = 0; i < len; i++)
    printf("\"%s\"%s", array[i], (i == len - 1) ? "" : ", ");
  printf(" }");
}

static void tester(size_t n, const char* const ideas[n], const char* expected) {
  const char* submitted = well(n, ideas);
  printf("Ideas = ");
  print_array(n, ideas);
  printf("\n");
  printf("Expected = \"%s\", actual = \"%s\" -> %s\n\n", expected, submitted,
         strcmp(expected, submitted) == 0 ? "OK" : "FAIL");
}

int main(void) {
  {
    const char* ideas[3] = {"bad", "bad", "bad"};
    tester(3, ideas, "Fail!");
  }
  {
    const char* ideas[5] = {"good", "bad", "bad", "bad", "bad"};
    tester(5, ideas, "Publish!");
  }
  {
    const char* ideas[9] = {"good", "bad", "bad", "bad", "bad",
                            "good", "bad", "bad", "good"};
    tester(9, ideas, "I smell a series!");
  }
  {
    const char** ideas = NULL;
    tester(0, ideas, "Fail!");
  }
  return 0;
}
