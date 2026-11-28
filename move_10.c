/*
7 kyu
Move 10
https://www.codewars.com/kata/57cf50a7eca2603de0000090
*/

void moveTen(char* str) {
  while (*str) {
    if (*str > 'p')
      *str -= 26;
    *str++ += 10;
  }
}
