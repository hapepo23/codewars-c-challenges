/*
3 kyu
Last digit of a huge number
https://www.codewars.com/kata/5518a860a73e708c0a000027
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof *(array))
#define fixed_test(array, expected) dotest(ARRAY_LENGTH(array), array, expected)

int last_digit(const unsigned long long array[], size_t length);

static void print_array(size_t length, const unsigned long long array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%llu%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void dotest(size_t length,
                   const unsigned long long array[length],
                   int expected) {
  const int actual = last_digit(array, length);
  printf("Array = ");
  print_array(length, array);
  printf("\n");
  printf("Expected = %d, actual = %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  dotest(0, NULL, 1);
  fixed_test(((unsigned long long[]){0, 0}), 1);
  fixed_test(((unsigned long long[]){0, 0, 0}), 0);
  fixed_test(((unsigned long long[]){1, 2}), 1);
  fixed_test(((unsigned long long[]){3, 4, 5}), 1);
  fixed_test(((unsigned long long[]){4, 3, 6}), 4);
  fixed_test(((unsigned long long[]){7, 6, 21}), 1);
  fixed_test(((unsigned long long[]){12, 30, 21}), 6);
  fixed_test(((unsigned long long[]){2, 2, 2, 0}), 4);
  fixed_test(((unsigned long long[]){937640, 767456, 981242}), 0);
  fixed_test(((unsigned long long[]){123232, 694022, 140249}), 6);
  fixed_test(((unsigned long long[]){499942, 898102, 846073}), 6);
  return 0;
}
