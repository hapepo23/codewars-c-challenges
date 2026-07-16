/*
7 kyu
Triangle area
https://www.codewars.com/kata/59bd84b8a0640e7c49002398
*/

double triangle_area(const char* triangle_string) {
  int c = 0;
  while (*triangle_string)
    if (*triangle_string++ == '\n')
      c++;
  return (c - 2) * (c - 2) / 2.0;
}
