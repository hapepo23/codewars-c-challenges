/*
5 kyu
■□ Pattern □■ : Zoom
https://www.codewars.com/kata/56e6705b715e72fef0000647
*/

#include <wchar.h>

static void add_line(unsigned count, int colblack, int* pos, wchar_t* pattern) {
  for (unsigned i = *pos; i < (*pos + count); i++)
    pattern[i] = colblack ? L'■' : L'□';
  *pos += count;
}

static void add_alternate(unsigned count,
                          int* col,
                          int* pos,
                          wchar_t* pattern) {
  for (unsigned i = *pos; i < (*pos + count); i++) {
    pattern[i] = *col ? L'■' : L'□';
    *col = !(*col);
  }
  *pos += count;
}

static void add_nl(int isnl, int* pos, wchar_t* pattern) {
  pattern[*pos] = isnl ? L'\n' : L'\0';
  *pos += 1;
}

wchar_t* zoom(unsigned n, wchar_t pattern[n * (n + 1) + 1]) {
  int pos = 0, col, startcol = ((n - 1) % 4 == 0);
  if (n == 1)
    add_line(1, 1, &pos, pattern);
  else {
    add_line(n, startcol, &pos, pattern);
    add_nl(1, &pos, pattern);
    for (unsigned i = 1; i <= n / 2 - 1; i++) {
      col = startcol;
      add_alternate(i, &col, &pos, pattern);
      add_line(n - i * 2, col, &pos, pattern);
      col = !col;
      add_alternate(i, &col, &pos, pattern);
      add_nl(1, &pos, pattern);
    }
    col = startcol;
    add_alternate(n, &col, &pos, pattern);
    add_nl(1, &pos, pattern);
    for (unsigned i = n / 2 - 1; i >= 1; i--) {
      col = startcol;
      add_alternate(i, &col, &pos, pattern);
      add_line(n - i * 2, col, &pos, pattern);
      col = !col;
      add_alternate(i, &col, &pos, pattern);
      add_nl(1, &pos, pattern);
    }
    add_line(n, startcol, &pos, pattern);
  }
  add_nl(0, &pos, pattern);
  return pattern;
}
