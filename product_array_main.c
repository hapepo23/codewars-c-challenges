/*
7 kyu
Product Array
https://www.codewars.com/kata/5a905c2157c562994900009d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixedTest(input, expected) doTest(ARR_LEN(input), input, expected)
#define printArray(length, array, format)                                 \
  do {                                                                    \
    printf("{ ");                                                         \
    for (size_t i = 0; i < (length); i++)                                 \
      printf(format "%s", (array)[i], (i == ((length) - 1)) ? "" : ", "); \
    printf(" }");                                                         \
  } while (0)

long long* productArray(const int numbers[], unsigned count);

static void doTest(size_t count,
                   const int input[count],
                   const long long expected[count]) {
  const size_t mem_size = count * sizeof *expected;
  long long* actual = productArray(input, count);
  printf("Input = ");
  printArray(count, input, "%d");
  printf("\nExpected = ");
  printArray(count, expected, "%lld");
  printf("\nActual = ");
  printArray(count, actual, "%lld");
  printf("\n-> %s\n\n",
         memcmp(actual, expected, mem_size) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  fixedTest(((int[]){12, 20}), ((long long[]){20, 12}));
  fixedTest(((int[]){1, 5, 2}), ((long long[]){10, 2, 5}));
  fixedTest(((int[]){3, 27, 4, 2}), ((long long[]){216, 24, 162, 324}));
  fixedTest(((int[]){13, 10, 5, 2, 9}),
            ((long long[]){900, 1170, 2340, 5850, 1300}));
  fixedTest(((int[]){16, 17, 4, 3, 5, 2}),
            ((long long[]){2040, 1920, 8160, 10880, 6528, 16320}));
  fixedTest(((int[]){10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}),
            ((long long[]){670442572800ll, 609493248000ll, 558702144000ll,
                           515725056000ll, 478887552000ll, 446961715200ll,
                           419026608000ll, 394377984000ll, 372468096000ll,
                           352864512000ll, 335221286400ll}));
  return 0;
}
