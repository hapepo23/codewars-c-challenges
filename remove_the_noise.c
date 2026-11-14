/*
7 kyu
Remove the noise from the string
https://www.codewars.com/kata/5681cf0be812b41721000034
*/

#include <stdbool.h>
#include <string.h>

void remove_noise(char* input) {
  static const char* noise[] = {"%", "$", "&", "/",  "#", "·",
                                "@", "|", "º", "\\", "ª"};
  char* src = input;
  char* dst = input;
  while (*src) {
    int nskip = true;
    for (size_t i = 0; i < sizeof(noise) / sizeof(noise[0]); i++) {
      size_t len = strlen(noise[i]);
      if (strncmp(src, noise[i], len) == 0) {
        src += len;
        nskip = false;
        break;
      }
    }
    if (nskip)
      *dst++ = *src++;
  }
  *dst = '\0';
}
