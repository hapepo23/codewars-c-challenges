/*
7 kyu
Mew Cipher
https://www.codewars.com/kata/671bd5419ea261fbb8d0a0ca
*/

#include <ctype.h>
#include <stddef.h>
#include <string.h>

void decipher(size_t length, const char* const code[length], char* mew) {
  size_t lenstr = strlen(code[0]);
  for (size_t i = 0; i < lenstr; i++) {
    double avg = 0.0;
    for (size_t j = 0; j < length; j++) {
      if (islower(code[j][i]))
        avg += (double)(code[j][i] - 'a' + 1);
    }
    avg /= (double)length;
    int iavg = (int)avg - 1;
    mew[i] = iavg == -1 ? ' ' : 'a' + iavg;
  }
  mew[lenstr] = '\0';
}
