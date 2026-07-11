/*
6 kyu
Assemble string
https://www.codewars.com/kata/6210fb7aabf047000f3a3ad6
*/

#include <stdbool.h>
#include <stddef.h>

char* assemble_string(char* assembled,
                      size_t rows,
                      const char* const strings[rows]) {
  if (rows == 0 || strings[0][0] == '\0')
    *assembled = '\0';
  else {
    size_t offset = 0;
    while (strings[0][offset]) {
      bool notfound = true;
      for (size_t i = 0; i < rows && notfound; i++) {
        if (strings[i][offset] != '*') {
          assembled[offset] = strings[i][offset];
          notfound = false;
        }
      }
      if (notfound)
        assembled[offset] = '#';
      offset++;
    }
    assembled[offset] = '\0';
  }
  return assembled;
}
