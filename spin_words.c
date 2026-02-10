/*
6 kyu
Stop gninnipS My sdroW!
https://www.codewars.com/kata/5264d2b162488dc400000001
*/

#include <string.h>

void strrev(char* string) {
  for (int i = strlen(string) - 1, j = 0; i >= j; i--, j++) {
    char temp = string[j];
    string[j] = string[i];
    string[i] = temp;
  }
}

void spin_words(const char* sentence, char* result) {
  int len = strlen(sentence);
  char s[len + 1];
  strcpy(s, sentence);
  strcpy(result, sentence);
  for (char* p = strtok(s, " "); p != NULL; p = strtok(NULL, " ")) {
    int l = strlen(p);
    if (l >= 5) {
      strrev(p);
      memcpy(result + (p - s), p, l);
    }
  }
}
