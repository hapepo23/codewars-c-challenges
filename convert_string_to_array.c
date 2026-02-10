/*
8 kyu
Convert a string to an array
https://www.codewars.com/kata/57e76bc428d6fbc2d500036d
*/

#include <stdlib.h>
#include <string.h>

size_t count_words(const char* words) {
  size_t result = 0;
  if (*words) {
    while (*words) {
      if (*words == ' ')
        result++;
      words++;
    }
    result++;
  }
  return result;
}

void words_to_array(const char* words, char* words_array[]) {
  size_t cnt = count_words(words);
  if (cnt > 0) {
    char* s = calloc(strlen(words) + 1, sizeof(char));
    strcpy(s, words);
    size_t i = 0;
    for (char* p = strtok(s, " "); p != NULL; p = strtok(NULL, " ")) {
      words_array[i] = calloc(strlen(p) + 1, sizeof(char));
      strcpy(words_array[i++], p);
    }
    free(s);
  }
}
