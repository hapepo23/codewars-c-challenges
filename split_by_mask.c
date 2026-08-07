/*
7 kyu
Split by Mask
https://www.codewars.com/kata/6a68ed7894f29599a1f7a248
*/

#include <stddef.h>
#include <string.h>

size_t split_by_mask(const char* string,
                     size_t length,
                     const size_t masks[length],
                     char** parts) {
  size_t strl = strlen(string);
  if (strl == 0)
    return 0;
  size_t suml = 0;
  for (size_t i = 0; i < length; i++)
    suml += masks[i];
  if (strl != suml)
    return 0;
  size_t offset = 0;
  for (size_t i = 0; i < length; i++) {
    strncpy(parts[i], string + offset, masks[i]);
    parts[i][masks[i]] = '\0';
    offset += masks[i];
  }
  return length;
}
