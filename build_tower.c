/*
6 kyu
Build Tower
https://www.codewars.com/kata/576757b1df89ecf5bd00073b
*/

void build_tower(unsigned n, char tower[n][2 * n - 1]) {
  for (unsigned i = 0; i < n; i++) {
    unsigned k = 0;
    for (unsigned j = n - 1; j > i; j--)
      tower[i][k++] = ' ';
    for (unsigned j = 0; j < 2 * (i + 1) - 1; j++)
      tower[i][k++] = '*';
    for (unsigned j = n - 1; j > i; j--)
      tower[i][k++] = ' ';
  }
}
