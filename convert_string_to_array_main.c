/*
8 kyu
Convert a string to an array
https://www.codewars.com/kata/57e76bc428d6fbc2d500036d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(words, expected) do_test(words, ARR_LEN(expected), expected)

size_t count_words(const char* words);
void words_to_array(const char* words, char* words_array[]);

static char* array_repr(size_t n, const char* const strings[n]) {
  size_t mem_size = n * (sizeof "\"\", " - 1) + sizeof "{}";
  for (size_t i = 0; i < n; i++)
    mem_size += strings[i] ? strlen(strings[i]) : (sizeof "NULL" - 1);
  char *s = calloc(mem_size, 1), *ptr = s;
  *(ptr++) = '{';
  for (size_t i = 0; i < n; i++) {
    ptr += sprintf(ptr, strings[i] ? "\"%s\"%s" : "%s%s",
                   strings[i] ? strings[i] : "NULL", (i == n - 1) ? "" : ", ");
  }
  *(ptr++) = '}';
  *ptr = '\0';
  return s;
}

static void do_test(const char* sentence,
                    size_t exp_len,
                    const char* const expected[exp_len]) {
  size_t act_len = count_words(sentence);
  printf("String = \"%s\"\nThere are %zu words, got %zu -> %s\n", sentence,
         exp_len, act_len, exp_len == act_len ? "OK" : "FAIL");
  char** actual = calloc(act_len, sizeof *actual);
  words_to_array(sentence, actual);
  char* repr_exp = array_repr(exp_len, expected);
  char* repr_act = array_repr(act_len, (const char**)actual);
  printf("Expected: %s\nActual  : %s\n%s\n\n", repr_exp, repr_act,
         strcmp(repr_exp, repr_act) == 0 ? "OK" : "FAIL");
  free(repr_act);
  free(repr_exp);
  for (size_t i = 0; i < act_len; i++)
    free(actual[i]);
  free(actual);
}

int main(void) {
  do_test("", 0, NULL);
  fixed_test("word", ((const char*[]){"word"}));
  fixed_test("Robin Singh", ((const char*[]){"Robin", "Singh"}));
  fixed_test("a b c", ((const char*[]){"a", "b", "c"}));
  fixed_test("I love arrays they are my favorite",
             ((const char*[]){"I", "love", "arrays", "they", "are", "my",
                              "favorite"}));
  return 0;
}
