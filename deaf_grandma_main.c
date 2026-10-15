/*
6 kyu
Pine's Deaf Grandma
https://www.codewars.com/kata/572b82bf4903c13b1b001079
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(input, expected) \
  do_test(ARR_LEN(input), input, ARR_LEN(expected), expected)

size_t deaf_grandma_conversation(size_t length,
                                 const char* const your_sentences[length],
                                 const char* grandma_sentences[length]);

static void print_array(size_t length, const char* const array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("\"%s\"%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static bool equal_arrays(size_t len_a,
                         const char* const a[len_a],
                         size_t len_b,
                         const char* const b[len_b]) {
  if (len_a != len_b)
    return false;
  for (size_t i = 0; i < len_a; i++)
    if (strcmp(a[i], b[i]))
      return false;
  return true;
}

static void do_test(size_t length_in,
                    const char* const input[length_in],
                    size_t length_exp,
                    const char* const expected[length_exp]) {
  const char** actual = malloc(length_in * sizeof *actual);
  const size_t length_act = deaf_grandma_conversation(length_in, input, actual);
  const bool equal = equal_arrays(length_act, actual, length_exp, expected);
  printf("Input    = ");
  print_array(length_in, input);
  printf("\nexpected = ");
  print_array(length_exp, expected);
  printf("\nactual   = ");
  print_array(length_act, actual);
  printf("\n-> %s\n\n", equal ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  fixed_test(((const char*[]){"hi grandma", "WHAT", "bye", "BYE"}),
             ((const char*[]){"HUH?! SPEAK UP, SONNY!", "NO, NOT SINCE 1938!",
                              "HUH?! SPEAK UP, SONNY!", "OK, BYE!"}));
  fixed_test(((const char*[]){"BYE"}), ((const char*[]){"OK, BYE!"}));
  fixed_test(((const char*[]){"HELLO", "OK, BYE", "BYE"}),
             ((const char*[]){"NO, NOT SINCE 1938!", "NO, NOT SINCE 1938!",
                              "OK, BYE!"}));
  fixed_test(
      ((const char*[]){"Bye", "OK, BYE", "OK, BYE", "BUY", "BYE", "BYE"}),
      ((const char*[]){"HUH?! SPEAK UP, SONNY!", "NO, NOT SINCE 1938!",
                       "NO, NOT SINCE 1938!", "NO, NOT SINCE 1938!",
                       "OK, BYE!"}));
  fixed_test(((const char*[]){"Bye?", "BYE!", "BYE.", "BYE"}),
             ((const char*[]){"HUH?! SPEAK UP, SONNY!", "NO, NOT SINCE 1938!",
                              "NO, NOT SINCE 1938!", "OK, BYE!"}));
  fixed_test(((const char*[]){"BYE8", "1 Ok, Bye!", "BYE"}),
             ((const char*[]){"NO, NOT SINCE 1938!", "HUH?! SPEAK UP, SONNY!",
                              "OK, BYE!"}));
  fixed_test(((const char*[]){"good morning", "NICE TO SEE YOU", "BYE",
                              "oh, I forgot", "nevermind", "see you"}),
             ((const char*[]){"HUH?! SPEAK UP, SONNY!", "NO, NOT SINCE 1938!",
                              "OK, BYE!"}));
  return 0;
}
