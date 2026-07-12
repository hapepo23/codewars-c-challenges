/*
6 kyu
Convert ISBN-10 to ISBN-13
https://www.codewars.com/kata/61ce25e92ca4fb000f689fb0
*/

#include <ctype.h>
#include <string.h>

char* ISBN_converter(char* ISBN_13, const char* ISBN_10) {
  strcpy(ISBN_13, "978-");
  strcpy(ISBN_13 + 4, ISBN_10);
  size_t poscd = strlen(ISBN_13) - 1;
  int mult = 3, sum = 0;
  for (size_t i = 0; i < poscd; i++) {
    if (isdigit(ISBN_13[i])) {
      mult = mult == 1 ? 3 : 1;
      sum += (ISBN_13[i] - '0') * mult;
    }
  }
  ISBN_13[poscd] = '0' + (10 - (sum % 10)) % 10;
  return ISBN_13;
}
