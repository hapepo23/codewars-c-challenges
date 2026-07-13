/*
5 kyu
■□ Pattern □■ : Zoom
https://www.codewars.com/kata/56e6705b715e72fef0000647
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

wchar_t* zoom(unsigned n, wchar_t pattern[n * (n + 1) + 1]);

static void do_test(unsigned n, const wchar_t* expected) {
  const size_t n_wchars = (n * (n + 1) + 1);
  wchar_t* user_string =
      wmemset(malloc(n_wchars * sizeof *expected), L'@', n_wchars);
  wchar_t* actual = zoom(n, user_string);
  printf(
      "n = %u\nexpected:\n%ls\nactual:\n%ls\n-> %s\n\n", n, expected, actual,
      actual == user_string && wcscmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(user_string);
}

int main(void) {
  setlocale(LC_ALL, "C.UTF-8");
  do_test(1, L"■");
  do_test(3,
          L"□□□"
          L"\n"
          L"□■□"
          L"\n"
          L"□□□");
  do_test(5,
          L"■■■■■"
          L"\n"
          L"■□□□■"
          L"\n"
          L"■□■□■"
          L"\n"
          L"■□□□■"
          L"\n"
          L"■■■■■");
  do_test(7,
          L"□□□□□□□"
          L"\n"
          L"□■■■■■□"
          L"\n"
          L"□■□□□■□"
          L"\n"
          L"□■□■□■□"
          L"\n"
          L"□■□□□■□"
          L"\n"
          L"□■■■■■□"
          L"\n"
          L"□□□□□□□");
  do_test(9,
          L"■■■■■■■■■"
          L"\n"
          L"■□□□□□□□■"
          L"\n"
          L"■□■■■■■□■"
          L"\n"
          L"■□■□□□■□■"
          L"\n"
          L"■□■□■□■□■"
          L"\n"
          L"■□■□□□■□■"
          L"\n"
          L"■□■■■■■□■"
          L"\n"
          L"■□□□□□□□■"
          L"\n"
          L"■■■■■■■■■");
  return 0;
}
