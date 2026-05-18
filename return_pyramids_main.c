/*
8 kyu
Area of a Square
https://www.codewars.com/kata/5748838ce2fab90b86001b1a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pyramid(int n);

int main(void) {
  {
    char* expected = "/\\\n";
    char* submitted = pyramid(1);
    printf("n = %d\nExpected:\n%s\nSubmitted:\n%s\n->%s\n\n", 1, expected,
           submitted, strcmp(expected, submitted) == 0 ? "OK" : "FAIL");
    free(submitted);
    submitted = NULL;
  }
  {
    char* expected = "   /\\\n  /  \\\n /    \\\n/______\\\n";
    char* submitted = pyramid(4);
    printf("n = %d\nExpected:\n%s\nSubmitted:\n%s\n->%s\n\n", 4, expected,
           submitted, strcmp(expected, submitted) == 0 ? "OK" : "FAIL");
    free(submitted);
    submitted = NULL;
  }
  {
    char* expected = "    /\\\n   /  \\\n  /    \\\n /      \\\n/________\\\n";
    char* submitted = pyramid(5);
    printf("n = %d\nExpected:\n%s\nSubmitted:\n%s\n->%s\n\n", 5, expected,
           submitted, strcmp(expected, submitted) == 0 ? "OK" : "FAIL");
    free(submitted);
    submitted = NULL;
  }
  return 0;
}
