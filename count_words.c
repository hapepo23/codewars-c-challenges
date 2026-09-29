/*
6 kyu
Count words
https://www.codewars.com/kata/56b3b27cadd4ad275500000c
*/

#include <ctype.h>
#include <string.h>

size_t count_words(const char* string) {
  static char delim[] = " !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
  size_t len = strlen(string) + 1;
  char str[len];
  for (size_t i = 0; i < len; i++)
    str[i] = isupper(string[i]) ? tolower(string[i]) : string[i];
  char* word;
  size_t result = 0;
  word = strtok(str, delim);
  while (word != NULL) {
    if (strcmp(word, "a") != 0 && strcmp(word, "the") != 0 &&
        strcmp(word, "on") != 0 && strcmp(word, "at") != 0 &&
        strcmp(word, "of") != 0 && strcmp(word, "upon") != 0 &&
        strcmp(word, "in") != 0 && strcmp(word, "as") != 0)
      result++;
    word = strtok(NULL, delim);
  }
  return result;
}
