/*
7 kyu
Retrieve The N-th String Term
https://www.codewars.com/kata/66ca80460f2a3f128a865cc5
*/

#include <stddef.h>
#include <stdio.h>

#define test_basic(input, n, offset) tester(input, n, &input[offset])

const char* extract_string(const char* input, int n);

static void tester(const char* input, const int n, const char* expected) {
  const char* result = extract_string(input, n);
  if (expected == NULL) {
    printf("Expected NULL -> %s\n", result == NULL ? "OK" : "FAIL");
  } else {
    const ptrdiff_t expected_offset = expected - input;
    const ptrdiff_t result_offset = result - input;
    printf("Expected '%s', but got '%s' -> %s\n", expected, result,
           expected_offset == result_offset ? "OK" : "FAIL");
  }
}

int main(void) {
  test_basic("hello\0world\0\0", 0, 0);     // "hello"
  test_basic("well\0done\0\0", 1, 5);       // "done"
  test_basic("you\0are\0close\0\0", 2, 8);  // "close"
  test_basic("the\0brown\0fox\0jumps\0over\0the\0lazy\0dog\0\0", 7,
             34);                                  // "dog"
  test_basic("not\0the\0last\0string\0\0", 2, 8);  // "last"
  tester("edge\0case\0\0", -1, NULL);
  tester("another\0edge\0case\0\0", 3, NULL);
  return 0;
}
