/*
6 kyu
Pine's Deaf Grandma
https://www.codewars.com/kata/572b82bf4903c13b1b001079
*/

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

size_t deaf_grandma_conversation(size_t length,
                                 const char* const your_sentences[length],
                                 const char* grandma_sentences[length]) {
  static char* quiet_answer = "HUH?! SPEAK UP, SONNY!";
  static char* loud_answer = "NO, NOT SINCE 1938!";
  static char* bye_answer = "OK, BYE!";
  for (size_t i = 0; i < length; i++) {
    if (strcmp(your_sentences[i], "BYE") == 0) {
      grandma_sentences[i] = bye_answer;
      return i + 1;
    }
    const char* p = your_sentences[i];
    bool isloud = true;
    while (*p) {
      if (islower(*p)) {
        isloud = false;
        break;
      }
      p++;
    }
    if (isloud)
      grandma_sentences[i] = loud_answer;
    else
      grandma_sentences[i] = quiet_answer;
  }
  return length;
}
