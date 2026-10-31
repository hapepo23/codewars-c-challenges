/*
7 kyu
Sum of integers in string
https://www.codewars.com/kata/598f76a44f613e0e0b000026
*/

#include <stdlib.h>
#include <string.h>

unsigned sum_string_integers(const char* string) {
  static char delim[] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  int len = strlen(string) + 1;
  char str[len];
  for (int i = 0; i < len; i++)
    str[i] = string[i];
  char* word;
  int result = 0;
  word = strtok(str, delim);
  while (word != NULL) {
    result += atoi(word);
    word = strtok(NULL, delim);
  }
  return (unsigned)result;
}
