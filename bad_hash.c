/*
7 kyu
BAD Hash - String to Int
https://www.codewars.com/kata/596d93bd9b6a5df4de000049
*/

int hash(const char* str) {
  int a = 0;
  int b = 0;
  int spaces = 0;
  char prev = '\0';
  while (*str) {
    if (*str == ' ')
      spaces++;
    a += *str;
    if (prev)
      b += (*str - prev);
    prev = *str;
    str++;
  }
  int c = (a | b) & ((~a) << 2);
  int d = c ^ (32 * (spaces + 1));
  return d;
}
