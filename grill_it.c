/*
6 kyu
Grill it!
https://www.codewars.com/kata/595b3f0ad26b2d817400002a
*/

void grille_decypher(char* ciphertext, unsigned code) {
  unsigned len = 0;
  unsigned i;
  char* dst = ciphertext;
  while (ciphertext[len] != '\0')
    len++;
  for (i = 0; i < len; i++) {
    unsigned pos = len - 1 - i;
    if (pos < sizeof(code) * 8 && (code & (1u << pos)))
      *dst++ = ciphertext[i];
  }
  *dst = '\0';
}
