/*
7 kyu
From A to Z
https://www.codewars.com/kata/6512b3775bf8500baea77663
*/

void letters_range(char letters[27], const char range[4]) {
  for (char c = range[0]; c <= range[2]; c++)
    *(letters++) = c;
  *letters = '\0';
}
